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

using namespace winplus;

WINPLUS_API void user::WinSizePlus::SetWidth(u16 newData) { this->Width = newData; }
WINPLUS_API void user::WinSizePlus::SetHeight(u16 newData) { this->Height = newData; }

WINPLUS_API u16 user::WinSizePlus::GetWidth() const { return this->Width; }
WINPLUS_API u16 user::WinSizePlus::GetHeight() const { return this->Height; }

WINPLUS_API void user::WinPosPlus::SetPosX(i16 newData) { this->PosX = newData; }
WINPLUS_API void user::WinPosPlus::SetPosY(i16 newData) { this->PosY = newData; }

WINPLUS_API i16 user::WinPosPlus::GetPosX() const { return this->PosX; }
WINPLUS_API i16 user::WinPosPlus::GetPosY() const { return this->PosY; }

WINPLUS_API user::WinMessageBoxPlus user::WMB_Init(string Title,
                                                string ClassName) {
  return WinMessageBoxPlus{Title, ClassName, rand::GenerateID()};
}

WINPLUS_API user::WindowPlus user::WP_Init(i16 x, i16 y, u16 width, u16 height,
                                        const string Title) {
  WindowPlus wp_instance = {};
  wp_instance.SetPosX(x);
  wp_instance.SetPosY(y);
  wp_instance.SetWidth(width);
  wp_instance.SetHeight(height);
  wp_instance.Title = Title;
  wp_instance.Id = rand::GenerateID();
  return wp_instance;
}

WINPLUS_API u32 rand::GenerateID() {
  u32 length = 9;

  u32 lower_bound = std::pow(10, length - 1);
  u32 upper_bound = std::pow(10, length) - 1;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(lower_bound, upper_bound);
  return dis(gen);
}

WINPLUS_API void user::WinMessageBoxPlus::Close() {
  HWND hwnd = FindWindowA(this->Title.c_str(), this->ClassName.c_str());
  if (hwnd != NULL) {
    PostMessage(hwnd, WM_COMMAND, IDOK, 0);
  }
}

WINPLUS_API void user::WinMessageBoxPlus::Open() {
  MessageBoxA(NULL, this->Title.c_str(), this->ClassName.c_str(), this->Type);
}

WINPLUS_API void user::WinMessageBoxPlus::SetType(WMB_Type type) {
  this->Type = type;
}

WINPLUS_API void user::WindowPlus::Open() {
  auto WindowProc = [](HWND hwnd, UINT uMsg, WPARAM wParam,
                       LPARAM lParam) -> LRESULT {
    switch (uMsg) {
    case WM_CLOSE:
      DestroyWindow(hwnd);
      break;
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    default:
      return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
  };

  HINSTANCE hInstance = (HINSTANCE)GetModuleHandle(NULL);
  const wchar_t *CLASS_NAME = L"MyWindowClass";

  WNDCLASSW wc = {};
  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = CLASS_NAME;
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

  if (!RegisterClassW(&wc)) {
    // std::wcout << L"Failed to register window class! Error code: " << error
    //            << std::endl;
    return;
  }

  std::wstring wTitle(this->Title.begin(), this->Title.end());

  HWND hwnd =
      CreateWindowExW(0, CLASS_NAME, wTitle.c_str(), WS_OVERLAPPEDWINDOW,
                      this->GetPosX(), this->GetPosY(), this->GetWidth(),
                      this->GetHeight(), NULL, NULL, hInstance, NULL);

  if (!hwnd) {
    // std::wcout << L"Failed to create window!" << std::endl;
    return;
  }

  ShowWindow(hwnd, SW_SHOWNORMAL);
  UpdateWindow(hwnd);

  MSG msg = {};
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
}
