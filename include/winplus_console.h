#ifndef WINPLUS_CONSOLE_H
#define WINPLUS_CONSOLE_H
#ifdef WINPLUS_EXPORTS
#define WINPLUS_API __declspec(dllexport)
#else
#define WINPLUS_API __declspec(dllimport)
#endif

enum WIN_CONSOLE_TYPE
{
  WC_ERROR,
  WC_INFO,
  WC_WARNING
};

void WIN_CONSOLE_LOG(WIN_CONSOLE_TYPE wct, const wchar_t* message);

#endif