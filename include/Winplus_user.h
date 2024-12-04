#include "Winplus_defines.h"
#include "Winplus_types.h"
#include <complex.h>
#include <windows.h>

extern "C" {

/**
 * Structure representing window dimensions
 */
typedef struct {
  /** Width of the window in pixels */
  u16 Width;
  /** Height of the window in pixels */
  u16 Height;
} WinSizePlus;

/**
 * Structure representing window position coordinates
 */
typedef struct {
  /** X-coordinate of the window position */
  i16 PosX;
  /** Y-coordinate of the window position */
  i16 PosY;
} WinPosPlus;

/**
 * Structure containing message box properties
 */
typedef struct {
  /** Window title in wide characters */
  const wc16 *Title;
  /** Window class name in wide characters */
  const wc16 *ClassName;
  /** Unique identifier for the message box */
  i32 Id;
} WinMessageBoxPlus;

/**
 * Structure containing window properties
 */
typedef struct {
  /** Window size information */
  WinSizePlus Size;
  /** Window position information */
  WinPosPlus Position;
  /** Window title in wide characters */
  const wc16 *Title;
  /** Unique identifier for the window */
  i32 Id;
} WindowPlus;

/**
 * Enumeration of message box types with predefined styles
 */
typedef enum {
  /** Error message box with OK button */
  WMB_ERROR = MB_ICONERROR + MB_OK,
  /** Warning message box with OK button */
  WMB_WARNING = MB_ICONWARNING + MB_OK,
  /** Information message box with OK button */
  WMB_INFO = MB_ICONINFORMATION + MB_OK
} WMB_Type;

/**
 * Initializes a new message box
 * Title - Window title in wide characters
 * ClassName - Window class name in wide characters
 * Returns initialized WinMessageBoxPlus structure
 */
WINPLUS_API WinMessageBoxPlus WMB_Init(wc16 *Title, wc16 *ClassName);

/**
 * Closes a message box
 * wmb - Message box to close
 */
WINPLUS_API void WMB_Close(WinMessageBoxPlus wmb);

/**
 * Forcefully terminates a message box
 * wmb - Message box to terminate
 */
WINPLUS_API void WMB_Kill(WinMessageBoxPlus wmb);

/**
 * Generates a unique identifier for a message box
 * wmb - Message box to generate ID for
 * Returns generated identifier
 */
WINPLUS_API i32 WMB_GenerateID(WinMessageBoxPlus wmb);

/**
 * Sets the type and style of a message box
 * wmb - Message box to modify
 * type - Type to set (WMB_ERROR, WMB_WARNING, or WMB_INFO)
 */
WINPLUS_API void WMB_SetType(WinMessageBoxPlus wmb, WMB_Type type);

/**
 * Initializes a new window
 * x - X-coordinate for window position
 * y - Y-coordinate for window position
 * width - Window width in pixels
 * height - Window height in pixels
 * Title - Window title in wide characters
 * Returns initialized WindowPlus structure
 */
WINPLUS_API WindowPlus WP_Init(i16 x, i16 y, u16 width, u16 height,
                               const wc16 *Title);

/**
 * Closes a window
 * wp - Window to close
 */
WINPLUS_API void WP_Close(WindowPlus wp);

/**
 * Forcefully terminates a window
 * wp - Window to terminate
 */
WINPLUS_API void WP_Kill(WindowPlus wp);

/**
 * Generates a unique identifier for a window
 * wp - Window to generate ID for
 * Returns generated identifier
 */
WINPLUS_API i32 WP_GenerateID(WindowPlus wp);

/**
 * Gets the width of a window
 * wp - Window to query
 * Returns window width in pixels
 */
WINPLUS_API u16 WP_GetWidth(const WindowPlus wp);

/**
 * Gets the height of a window
 * wp - Window to query
 * Returns window height in pixels
 */
WINPLUS_API u16 WP_GetHeight(const WindowPlus wp);

/**
 * Gets the X-coordinate of a window's position
 * wp - Window to query
 * Returns window X-coordinate
 */
WINPLUS_API i16 WP_GetPosX(const WindowPlus wp);

/**
 * Gets the Y-coordinate of a window's position
 * wp - Window to query
 * Returns window Y-coordinate
 */
WINPLUS_API i16 WP_GetPosY(const WindowPlus wp);

}