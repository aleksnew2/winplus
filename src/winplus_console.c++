#include "../include/winplus.h"
#include <cassert>
#include <stdio.h>

const char*
wct_to_string(win_console_type wct)
{
  switch (wct) {
    case wc_error:
      return "wc_error";
    case wc_warning:
      return "wc_warning";
    case wc_info:
      return "wc_info";
    default:
      return "unknown_enum_type";
  }
}

void
win_console_log(win_console_type wct, const wchar_t* message)
{
  wprintf(L"[%s] %ls\n", wct_to_string(wct), message);
  fflush(stdout);
}
