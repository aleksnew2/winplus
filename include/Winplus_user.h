#include "Winplus_defines.h"
#include "Winplus_types.h"
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
}