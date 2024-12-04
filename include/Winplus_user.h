#include "Winplus_defines.h"
#include "Winplus_types.h"
#include <complex.h>
#include <windows.h>

extern "C" {
/**
 * Structure representing window dimensions.
 *
 * This structure holds the width and height of a window in pixels.
 * Useful for defining window size and performing size-related calculations.
 */
typedef struct {
  u16 Width;  /**< Width of the window in pixels */
  u16 Height; /**< Height of the window in pixels */
} WinSizePlus;

/**
 * Structure representing window position coordinates.
 *
 * This structure contains the X and Y coordinates for the window's position.
 * Useful for window placement and movement operations.
 */
typedef struct {
  i16 PosX; /**< X-coordinate of the window position */
  i16 PosY; /**< Y-coordinate of the window position */
} WinPosPlus;

/**
 * Structure containing message box properties.
 *
 * Holds information about the message box title, class name, and identifier.
 * Useful for creating and managing message boxes with specific properties.
 */
typedef struct {
  const wc16 *Title;    /**< Window title in wide characters */
  const wc16 *ClassName; /**< Window class name in wide characters */
  i32 Id;              /**< Unique identifier for the message box */
} WinMessageBoxPlus;

/**
 * Structure containing window properties.
 *
 * Combines window size, position, title, and identifier into a single structure.
 * Useful for comprehensive window management and manipulation.
 */
typedef struct {
  WinSizePlus Size;    /**< Window size information */
  WinPosPlus Position; /**< Window position information */
  const wc16 *Title;   /**< Window title in wide characters */
  i32 Id;             /**< Unique identifier for the window */
} WindowPlus;

/**
 * Enumeration of message box types with predefined styles.
 *
 * Defines various types of message boxes with their associated styles.
 * Useful for standardizing message box appearances across applications.
 */
typedef enum {
  WMB_ERROR = MB_ICONERROR + MB_OK,   /**< Error message box with OK button */
  WMB_WARNING = MB_ICONWARNING + MB_OK, /**< Warning message box with OK button */
  WMB_INFO = MB_ICONINFORMATION + MB_OK /**< Information message box with OK button */
} WMB_Type;

/**
 * Initializes a new message box.
 *
 * Creates and returns a new message box with the specified title and class name.
 * Useful for displaying messages to users in a standardized format.
 */
WINPLUS_API WinMessageBoxPlus WMB_Init(wc16 *Title, wc16 *ClassName);

/**
 * Closes a message box.
 *
 * Closes the specified message box, freeing associated resources.
 * Useful for managing message box lifecycle.
 */
WINPLUS_API void WMB_Close(WinMessageBoxPlus wmb);

/**
 * Forcefully terminates a message box.
 *
 * Immediately closes the specified message box, regardless of its state.
 * Useful for emergency shutdown of message boxes.
 */
WINPLUS_API void WMB_Kill(WinMessageBoxPlus wmb);

/**
 * Generates a unique identifier for a message box.
 *
 * Computes and returns a unique identifier for the specified message box.
 * Useful for tracking and managing multiple message boxes.
 */
WINPLUS_API i32 WMB_GenerateID(WinMessageBoxPlus wmb);

/**
 * Sets the type and style of a message box.
 *
 * Configures the specified message box with the given type and style.
 * Useful for customizing message box appearance and behavior.
 */
WINPLUS_API void WMB_SetType(WinMessageBoxPlus wmb, WMB_Type type);

/**
 * Initializes a new window.
 *
 * Creates and returns a new window with the specified position, size, and title.
 * Useful for creating application windows with specific properties.
 */
WINPLUS_API WindowPlus WP_Init(i16 x, i16 y, u16 width, u16 height,
                               const wc16 *Title);

/**
 * Closes a window.
 *
 * Closes the specified window, freeing associated resources.
 * Useful for managing window lifecycle.
 */
WINPLUS_API void WP_Close(WindowPlus wp);

/**
 * Forcefully terminates a window.
 *
 * Immediately closes the specified window, regardless of its state.
 * Useful for emergency shutdown of windows.
 */
WINPLUS_API void WP_Kill(WindowPlus wp);

/**
 * Generates a unique identifier for a window.
 *
 * Computes and returns a unique identifier for the specified window.
 * Useful for tracking and managing multiple windows.
 */
WINPLUS_API i32 WP_GenerateID(WindowPlus wp);

/**
 * Gets the width of a window.
 *
 * Retrieves and returns the width of the specified window in pixels.
 * Useful for layout and rendering calculations.
 */
WINPLUS_API u16 WP_GetWidth(const WindowPlus wp);

/**
 * Gets the height of a window.
 *
 * Retrieves and returns the height of the specified window in pixels.
 * Useful for layout and rendering calculations.
 */
WINPLUS_API u16 WP_GetHeight(const WindowPlus wp);

/**
 * Gets the X-coordinate of a window's position.
 *
 * Retrieves and returns the X-coordinate of the specified window's position.
 * Useful for positioning and alignment operations.
 */
WINPLUS_API i16 WP_GetPosX(const WindowPlus wp);

/**
 * Gets the Y-coordinate of a window's position.
 *
 * Retrieves and returns the Y-coordinate of the specified window's position.
 * Useful for positioning and alignment operations.
 */
WINPLUS_API i16 WP_GetPosY(const WindowPlus wp);
}