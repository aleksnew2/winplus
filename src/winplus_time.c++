#include "../include/winplus.h"
#include <chrono>
#include <thread>

void
WAIT(TIME_TYPE tt, uint16_t time) noexcept
{
  switch (tt) {
    case TT_MICROSECONDS:
      std::this_thread::sleep_for(std::chrono::microseconds(time));
      break;
    case TT_MILLISECONDS:
      std::this_thread::sleep_for(std::chrono::milliseconds(time));
      break;
    case TT_SECOND:
      std::this_thread::sleep_for(std::chrono::seconds(time));
      break;
    case TT_MINUTE:
      std::this_thread::sleep_for(std::chrono::minutes(time));
      break;
    case TT_HOUR:
      std::this_thread::sleep_for(std::chrono::hours(time));
      break;
  }
}