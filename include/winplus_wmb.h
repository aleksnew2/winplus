#include <windows.h>

#ifndef WINPLUS_WMB_H
#define WINPLUS_WMB_H
#ifdef WINPLUS_EXPORTS
#define WINPLUS_API __declspec(dllexport)
#else
#define WINPLUS_API __declspec(dllimport)
#endif

enum WMB_TYPE
{
  WMB_ERROR = MB_ICONERROR + MB_OK,
  WMB_WARNING = MB_ICONWARNING + MB_OK,
  WMB_INFO = MB_ICONINFORMATION + MB_OK
};

extern "C" struct WIN_MESSAGEBOX
{
  WMB_TYPE type;
  const wchar_t* title;
  const wchar_t* className;
  bool is_open;
};

extern "C" WINPLUS_API WIN_MESSAGEBOX
WMB_CREATE(WMB_TYPE type, const wchar_t* title, const wchar_t* className);

extern "C" WINPLUS_API WIN_MESSAGEBOX
WMB_IS(int s, int d);

extern "C" WINPLUS_API void
WMB_CHANGE_TITLE(WIN_MESSAGEBOX& wmb, const wchar_t* nw);

extern "C" WINPLUS_API void
WMB_CHANGE_CLASSNAME(WIN_MESSAGEBOX& wmb, const wchar_t* nw);

extern "C" WINPLUS_API void
WMB_CLOSE(WIN_MESSAGEBOX& wmb);

extern "C" WINPLUS_API void
WMB_RESTART(WIN_MESSAGEBOX& wmb);

extern "C" WINPLUS_API int
WMB_SHOW(WIN_MESSAGEBOX& wmb);

extern "C" WINPLUS_API bool
WMB_IS_OPEN(WIN_MESSAGEBOX& wmb);

#endif // WINPLUS_WMB_H