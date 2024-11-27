/**
 * The header provides functionality to create, manipulate, and display message
 * boxes using the Windows API.
 *
 * Still under development.
 */
#include <windows.h>
#ifndef WINPLUS_WMB_H
#define WINPLUS_WMB_H
#ifdef WINPLUS_EXPORTS
#define WINPLUS_API __declspec(dllexport)
#else
#define WINPLUS_API __declspec(dllimport)
#endif

enum wmb_type
{
  wmb_error = MB_ICONERROR + MB_OK,
  wmb_warning = MB_ICONWARNING + MB_OK,
  wmb_info = MB_ICONINFORMATION + MB_OK
};

extern "C" struct win_messagebox
{
  wmb_type type;
  const wchar_t* title;
  const wchar_t* className;
  bool is_open;
};

extern "C" WINPLUS_API win_messagebox
wmb_create(wmb_type type, const wchar_t* title, const wchar_t* className);

extern "C" WINPLUS_API void
wmb_change_title(win_messagebox& wmb, const wchar_t* nw);

extern "C" WINPLUS_API void
wmb_change_classname(win_messagebox& wmb, const wchar_t* nw);

extern "C" WINPLUS_API void
wmb_close(win_messagebox& wmb);

extern "C" WINPLUS_API void
wmb_restart(win_messagebox& wmb);

extern "C" WINPLUS_API int
wmb_show(win_messagebox& wmb);

extern "C" WINPLUS_API bool
wmb_is_open(win_messagebox& wmb);

#endif // WINPLUS_WMB_H