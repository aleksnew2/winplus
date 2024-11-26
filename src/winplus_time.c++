#include "../include/winplus.h"
#include <chrono>
#include <thread>

void
WAIT(TIME_TYPE tt, uint16_t time) noexcept
{
  using namespace std::chrono;
  using namespace std::this_thread;

  switch (tt) {
    case TT_MICROSECONDS:
      sleep_for(microseconds(time));
      break;
    case TT_MILLISECONDS:
      sleep_for(milliseconds(time));
      break;
    case TT_SECOND:
      sleep_for(seconds(time));
      break;
    case TT_MINUTE:
      sleep_for(minutes(time));
      break;
    case TT_HOUR:
      sleep_for(hours(time));
      break;
  }
}