/**
 * The header provides time-related functions.
 * 
 * Still under development.
 */
#include <cstdint>

#ifndef WINPLUS_TIME_H
#define WINPLUS_TIME_H
#ifdef WINPLUS_EXPORTS
#define WINPLUS_API __declspec(dllexport)
#else
#define WINPLUS_API __declspec(dllimport)
#endif

enum time_type
{
  tt_microseconds,
  tt_milliseconds,
  tt_second,
  tt_minute,
  tt_hour
};

typedef void(win_event)();

extern "C" WINPLUS_API void
wait(time_type tt, uint16_t time) noexcept;

extern "C" WINPLUS_API void
wait_q(time_type tt, uint16_t time, win_event e) noexcept;

#endif