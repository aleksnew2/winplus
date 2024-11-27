#include <cstdint>

#ifndef WINPLUS_TIME_H
#define WINPLUS_TIME_H
#ifdef WINPLUS_EXPORTS
#define WINPLUS_API __declspec(dllexport)
#else
#define WINPLUS_API __declspec(dllimport)
#endif

enum TIME_TYPE
{
  TT_MICROSECONDS,
  TT_MILLISECONDS,
  TT_SECOND,
  TT_MINUTE,
  TT_HOUR
};

typedef void(EVENT)();

extern "C" WINPLUS_API void
WAIT(TIME_TYPE tt, uint16_t time) noexcept;

extern "C" WINPLUS_API void
WAIT_Q(TIME_TYPE tt, uint16_t time, EVENT e) noexcept;

#endif