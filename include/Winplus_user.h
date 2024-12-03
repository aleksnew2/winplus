#include "Winplus_defines.h"
#include "Winplus_types.h"
#include <complex.h>
#include <windows.h>

extern "C" {
typedef struct {
  u16 Width;
  u16 Height;
} WinSizePlus;

typedef struct {
  i16 PosX;
  i16 PosY;
} WinPosPlus;

typedef struct {
  const wc16 *Title;
  const wc16 *ClassName;
  i32 Id;
} WinMessageBoxPlus;

typedef struct {
  WinSizePlus Size;
  WinPosPlus Position;
  const wc16 *Title;
  i32 Id;
} WindowPlus;

typedef enum {
  WMB_ERROR = MB_ICONERROR + MB_OK,
  WMB_WARNING = MB_ICONWARNING + MB_OK,
  WMB_INFO = MB_ICONINFORMATION + MB_OK
} WMB_Type;

WINPLUS_API WinMessageBoxPlus WMB_Init(wc16 *Title, wc16 *ClassName);
WINPLUS_API void WMB_Close(WinMessageBoxPlus wmb);
WINPLUS_API void WMB_Kill(WinMessageBoxPlus wmb);
WINPLUS_API i32 WMB_GenerateID(WinMessageBoxPlus wmb);
WINPLUS_API void WMB_SetType(WinMessageBoxPlus wmb, WMB_Type type);

WINPLUS_API WindowPlus WP_Init(i16 x, i16 y, u16 width, u16 height,
                               const wc16 *Title);
WINPLUS_API void WP_Close(WindowPlus wp);
WINPLUS_API void WP_Kill(WindowPlus wp);
WINPLUS_API i32 WP_GenerateID(WindowPlus wp);
WINPLUS_API u16 WP_GetWidth(const WindowPlus wp);
WINPLUS_API u16 WP_GetHeight(const WindowPlus wp);
WINPLUS_API i16 WP_GetPosX(const WindowPlus wp);
WINPLUS_API i16 WP_GetPosY(const WindowPlus wp);
}