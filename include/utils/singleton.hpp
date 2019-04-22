#pragma once

#include <cassert>
#include <cstdlib>
#include <memory>
#include <type_traits>
#include <utility>

// policies
template <class T>
struct PolicyMutable { using ref_t = T&; };

template <class T>
struct PolicyConst { using ref_t = const T&; };

template <class T>
struct StaticStorage;

template <class T>
struct DynamicStorage;

template <class T>
struct ResettableDynamicStorage;

// Dynamic storage means heap allocation and enables inheritance polymorphism

template <class T>
struct SingletonConstructorToken {
private:
  SingletonConstructorToken() = default;

  // only storage policies can make a token
  // allowed storage policies are :
  friend struct StaticStorage<T>;
  friend struct DynamicStorage<T>;
  friend struct ResettableDynamicStorage<T>;
};

template <class T, template <class> class StoragePolicy, template <class> class MutabilityPolicy>
class Singleton : public StoragePolicy<T> {
  using type_t = T;
  using storage_t = StoragePolicy<type_t>;
  using ref_t = typename MutabilityPolicy<type_t>::ref_t;

protected:
  // Inherited typedefs for the client class to use
  using base_singleton_t = Singleton;
  using ctor_token_t = SingletonConstructorToken<T>;

  // A ctor token is required to construct a singleton class
  Singleton(ctor_token_t) {}
  Singleton(const Singleton&) = delete;
  Singleton(Singleton&&) = delete;
  Singleton& operator=(const Singleton&) = delete;
  Singleton& operator=(Singleton&&) = delete;

public:
  static ref_t instance() {
    return const_cast<ref_t>(storage_t::instance());
  }
};

template <class T>
struct StaticStorage {
  static const T& instance() {
    static T static_instance{SingletonConstructorToken<T>()};
    return static_instance;
  }
};

template <class T>
struct DynamicStorage {
  static const T& instance() {
    assert(s_ptr != nullptr);
    return *s_ptr;
  }

  template <class U = T, class... Args>
  static void initialize_instance(Args&&... args) {
    assert(s_ptr == nullptr);
    s_ptr = std::make_unique<U>(SingletonConstructorToken<T>(), std::forward<Args>(args)...);
  }

  static bool is_instance_initialized() {
    return s_ptr != nullptr;
  }

private:
  static void delete_instance() {
    s_ptr = nullptr;
  }

  static std::unique_ptr<T> s_ptr;

  friend struct ResettableDynamicStorage<T>;
};

template <class T>
std::unique_ptr<T> DynamicStorage<T>::s_ptr = nullptr;

template <class T>
struct ResettableDynamicStorage : public DynamicStorage<T> {
private:
  using super_t = DynamicStorage<T>;

public:
  using super_t::initialize_instance;
  using super_t::delete_instance;

  template <class U = T, class... Args>
  static void reset_instance(Args&&... args) {
    delete_instance();
    initialize_instance(std::forward<Args>(args)...);
  }
};

// typedefs

template <class T>
using ConstStaticSingleton = Singleton<T, StaticStorage, PolicyConst>;

template <class T>
using ConstDynamicSingleton = Singleton<T, DynamicStorage, PolicyConst>;

template <class T>
using ConstResettableDynamicSingleton = Singleton<T, ResettableDynamicStorage, PolicyConst>;

template <class T>
using MutableStaticSingleton = Singleton<T, StaticStorage, PolicyMutable>;

template <class T>
using MutableDynamicSingleton = Singleton<T, DynamicStorage, PolicyMutable>;

template <class T>
using MutableResettableDynamicSingleton = Singleton<T, ResettableDynamicStorage, PolicyMutable>;

// macros

#define SINGLETON_CTOR_TOKEN singleton_token_with_magic_number_3458234_
#define SINGLETON_CTOR_DECL(Class, ...) Class(ctor_token_t SINGLETON_CTOR_TOKEN, __VA_ARGS__)
#define SINGLETON_CTOR_INIT(...) super_singleton_t{SINGLETON_CTOR_TOKEN, __VA_ARGS__}

// use these ones to remove warning when not using variadic arguments
#define SINGLETON_DEFAULT_CTOR_DECL(Class) Class(ctor_token_t SINGLETON_CTOR_TOKEN)
#define SINGLETON_DEFAULT_CTOR_INIT() super_singleton_t{SINGLETON_CTOR_TOKEN}

// use this when you want a completely default and empty ctor
#define SINGLETON_DEFAULT_CTOR(Class) SINGLETON_DEFAULT_CTOR_DECL(Class) : SINGLETON_DEFAULT_CTOR_INIT() {}

#define SINGLETON_CLASS(Class, BaseSingletonClass) \
private:                                           \
  using singleton_t = Class;                       \
  using super_singleton_t = BaseSingletonClass;


// broken singleton_class assertion:
//  static_assert(std::is_base_of<super_singleton_t, singleton_t>::value, #Class " should inherit from " #BaseSingletonClass);
