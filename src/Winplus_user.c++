#include "../include/Winplus.hpp"
#include <cassert>
#include <cmath>
#include <cstddef>
#include <libloaderapi.h>
#include <minwindef.h>
#include <random>
#include <string>
#include <windows.h>
#include <winnt.h>

WINPLUS_API void WinSizePlus::SetWidth(u16 newData) { this->Width = newData; }
WINPLUS_API void WinSizePlus::SetHeight(u16 newData) { this->Height = newData; }

WINPLUS_API u16 WinSizePlus::GetWidth() const { return this->Width; }
WINPLUS_API u16 WinSizePlus::GetHeight() const { return this->Height; }

WINPLUS_API void WinPosPlus::SetPosX(i16 newData) { this->PosX = newData; }
WINPLUS_API void WinPosPlus::SetPosY(i16 newData) { this->PosY = newData; }

WINPLUS_API i16 WinPosPlus::GetPosX() const { return this->PosX; }
WINPLUS_API i16 WinPosPlus::GetPosY() const { return this->PosY; }

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

WINPLUS_API void WindowPlus::Open() {
  auto windowProc = [](HWND hwnd, UINT uMsg, WPARAM wParam,
                       LPARAM lParam) -> LRESULT CALLBACK {
    switch (uMsg) {
    case WM_CLOSE:
      DestroyWindow(hwnd);
      break;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
  };

  HINSTANCE hInstance = (HINSTANCE)GetModuleHandle(NULL);
  wstring wClassName =
      std::wstring(this->ClassName.begin(), this->ClassName.end());
  const wchar_t *CLASS_NAME = wClassName.c_str();

  WNDCLASS wc = {};
  wc.lpfnWndProc = windowProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = reinterpret_cast<LPCSTR>(CLASS_NAME);

  RegisterClass(&wc);

  HWND hwnd = CreateWindowExA(0, reinterpret_cast<LPCSTR>(CLASS_NAME),
                              reinterpret_cast<LPCSTR>(Title.c_str()),
                              WS_OVERLAPPEDWINDOW, this->GetPosX(),
                              this->GetPosY(), this->GetWidth(),
                              this->GetHeight(), NULL, NULL, hInstance, NULL);
}
