#include "../include/winplus.h"
#include <bits/this_thread_sleep.h>
#include <cassert>

win_messagebox
wmb_create(wmb_type type, const wchar_t* title, const wchar_t* className)
{
  auto wmb = win_messagebox{};
  wmb.type = type;
  wmb.title = title;
  wmb.className = className;
  wmb.is_open = false;
  return wmb;
}

void
wmb_change_title(win_messagebox& wmb, const wchar_t* nw)
{
  wmb.title = nw;
}

void
wmb_change_classname(win_messagebox& wmb, const wchar_t* nw)
{
  wmb.className = nw;
}

void
wmb_close(win_messagebox& wmb)
{
  assert(wmb.is_open == true);
  auto hwnd = FindWindowW(wmb.className, wmb.title);
  if (hwnd != NULL) {
    SendMessage(hwnd, WM_CLOSE, 0, 0);
  }
}

void
wmb_restart(win_messagebox& wmb)
{
  wmb_close(wmb);
  std::this_thread::sleep_for(std::chrono::seconds{ 2 });
  wmb_show(wmb);
}

int
wmb_show(win_messagebox& wmb)
{
  return MessageBoxW(NULL, wmb.title, wmb.className, wmb.type);
}

bool
wmb_is_open(win_messagebox& wmb)
{
  return wmb.is_open;
}