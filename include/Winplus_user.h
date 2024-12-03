#include "Winplus_defines.h"
#include "Winplus_types.h"

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
}