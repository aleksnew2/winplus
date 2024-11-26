#include "../include/winplus.h"
#include <bits/this_thread_sleep.h>
#include <cassert>

WIN_MESSAGEBOX
WMB_CREATE(WMB_TYPE type, const wchar_t* title, const wchar_t* className)
{
  auto wmb = WIN_MESSAGEBOX{};
  wmb.type = type;
  wmb.title = title;
  wmb.className = className;
  wmb.is_open = false;
  return wmb;
}

void
WMB_CHANGE_TITLE(WIN_MESSAGEBOX& wmb, const wchar_t* nw)
{
  wmb.title = nw;
}

void
WMB_CHANGE_CLASSNAME(WIN_MESSAGEBOX& wmb, const wchar_t* nw)
{
  wmb.className = nw;
}

void
WMB_CLOSE(WIN_MESSAGEBOX& wmb)
{
  assert(wmb.is_open == true);
  auto hwnd = FindWindowW(wmb.className, wmb.title);
  if (hwnd != NULL) {
    SendMessage(hwnd, WM_CLOSE, 0, 0);
  }
}

void
WMB_RESTART(WIN_MESSAGEBOX& wmb)
{
  WMB_CLOSE(wmb);
  std::this_thread::sleep_for(std::chrono::seconds{ 2 });
  WMB_SHOW(wmb);
}

int
WMB_SHOW(WIN_MESSAGEBOX& wmb)
{
  return MessageBoxW(NULL, wmb.title, wmb.className, wmb.type);
}

bool
WMB_IS_OPEN(WIN_MESSAGEBOX& wmb)
{
  return wmb.is_open;
}