#include "include/winplus.h"

int
main()
{
  auto s = WMB_CREATE(WMB_TYPE::WMB_ERROR, L"HI!", L"HELLO");
  WMB_SHOW(s);
  return 0;
}