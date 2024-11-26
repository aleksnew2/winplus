#include <cstdint>

#ifndef WINPLUS_CONSOLE_H
#define WINPLUS_CONSOLE_H
#ifdef WINPLUS_EXPORTS
#define WINPLUS_API __declspec(dllexport)
#else
#define WINPLUS_API __declspec(dllimport)
#endif

enum TIME_TYPE
{
  SECOND,
  MINUTE,
  HOUR
};

typedef void(EVENT)();

extern "C" WINPLUS_API void
WAIT(TIME_TYPE tt, uint16_t time);

extern "C" WINPLUS_API void
WAIT_Q(TIME_TYPE tt, uint16_t time, EVENT e);

#endif