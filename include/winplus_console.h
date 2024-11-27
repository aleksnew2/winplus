#ifndef WINPLUS_CONSOLE_H
#define WINPLUS_CONSOLE_H
#ifdef WINPLUS_EXPORTS
#define WINPLUS_API __declspec(dllexport)
#else
#define WINPLUS_API __declspec(dllimport)
#endif

enum win_console_type
{
  wc_error,
  wc_info,
  wc_warning
};

WINPLUS_API void
win_console_log(win_console_type wct, const wchar_t* message);

#endif