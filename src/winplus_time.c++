#include "../include/winplus.h"
#include <chrono>
#include <thread>

void
wait(time_type tt, uint16_t time) noexcept
{
  switch (tt) {
    case tt_microseconds:
      std::this_thread::sleep_for(std::chrono::microseconds(time));
      break;
    case tt_milliseconds:
      std::this_thread::sleep_for(std::chrono::milliseconds(time));
      break;
    case tt_second:
      std::this_thread::sleep_for(std::chrono::seconds(time));
      break;
    case tt_minute:
      std::this_thread::sleep_for(std::chrono::minutes(time));
      break;
    case tt_hour:
      std::this_thread::sleep_for(std::chrono::hours(time));
      break;
  }
}

void
wait_q(time_type tt, uint16_t time, win_event e) noexcept
{
  wait(tt, time);
  e();
}
