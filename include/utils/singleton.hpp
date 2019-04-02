#pragma once

template <class T>
class SingletonBase {
protected:
  struct SingletonExclusiveConstructor {};

  SingletonBase(SingletonExclusiveConstructor);
  SingletonBase(const SingletonBase&) = delete;
  SingletonBase(SingletonBase&&) = delete;
  SingletonBase& operator=(const SingletonBase&) = delete;
  SingletonBase& operator=(SingletonBase&&) = delete;
};

template <class T>
class Singleton : SingletonBase<T> {
public:
  static const T& instance() {
    static T static_instance(SingletonBase<T>::SingletonExclusiveConstructor());
    return static_instance;
  };
};

template <class T>
class MutableSingleton : SingletonBase<T> {
public:
  static T& instance() {
    static T static_instance(SingletonBase<T>::SingletonExclusiveConstructor());
    return static_instance;
  };
};
