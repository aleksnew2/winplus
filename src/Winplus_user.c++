#include "../include/Winplus.hpp"
#include <cmath>
#include <cstddef>
#include <random>
#include <windows.h>

WINPLUS_API WinMessageBoxPlus WMB_Init(string Title, string ClassName) {
  return WinMessageBoxPlus{Title, ClassName, GenerateID()};
}

// WINPLUS_API WindowPlus WP_Init(i16 x, i16 y, u16 width, u16 height,
//                                const string Title) {
//   WinPosPlus position = {x, y};
//   WinSizePlus size = {width, height};
//   return WindowPlus{size, position, Title, GenerateID()};
// }

WINPLUS_API u32 GenerateID() {
  u32 length = 9;

  u32 lower_bound = std::pow(10, length - 1);
  u32 upper_bound = std::pow(10, length) - 1;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(lower_bound, upper_bound);
  return dis(gen);
}

WINPLUS_API void WinMessageBoxPlus::Close() {
  HWND hwnd = FindWindowA(this->Title.c_str(), this->ClassName.c_str());
  if (hwnd != NULL) {
    PostMessage(hwnd, WM_COMMAND, IDOK, 0);
  }
}

WINPLUS_API void WinMessageBoxPlus::Open() {
  MessageBoxA(NULL, this->Title.c_str(), this->ClassName.c_str(), this->Type);
}

WINPLUS_API void WinMessageBoxPlus::SetType(WMB_Type type) {
  this->Type = type;
}
