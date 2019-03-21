#include <iostream>
#include <functional>

#include "asio.hpp"

#include "grid.hpp"

class printer
{
public:
  printer(asio::io_context& io)
      : strand_(io),
        t1_(io, asio::chrono::seconds(1)),
        t2_(io, asio::chrono::seconds(1)),
        count_(0)
  {
    t1_.async_wait([this](const asio::error_code&){this->print1();});
    t2_.async_wait([this](const asio::error_code&){this->print2();});
  }

  ~printer()
  {
    std::cout << "Final Count is" << count_ << std::endl;
  }

  void print1()
  {
    if(count_ < 10)
    {
      std::cout << "Timer 1:" << count_ << std::endl;
      ++count_;
      t1_.expires_at(t1_.expiry() + asio::chrono::seconds(1));

      t1_.async_wait([this](const asio::error_code&){this->print1();});
    }
  }

  void print2()
  {
    if(count_ < 10)
    {
      std::cout << "Timer 2:" << count_ << std::endl;
      ++count_;
      t2_.expires_at(t2_.expiry() + asio::chrono::seconds(1));

      t2_.async_wait([this](const asio::error_code&){this->print2();});
    }
  }

private:
  asio::io_context::strand strand_;
  asio::steady_timer t1_;
  asio::steady_timer t2_;
  int count_;
};


int main() {
 asio::io_context io;
 printer p(io);
 asio::thread t([&io](){io.run();});
 io.run();
 t.join();

 return 0;
}
