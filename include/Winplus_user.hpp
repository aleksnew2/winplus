#include "Winplus_defines.h"
#include "Winplus_types.h"
#include <complex.h>
#include <windows.h>

/**
 * Enumeration of message box types with predefined styles.
 *
 * Defines various types of message boxes with their associated styles.
 * Useful for standardizing message box appearances across applications.
 */
enum WMB_Type {
  WMB_ERROR = MB_ICONERROR + MB_OK, /**< Error message box with OK button */
  WMB_WARNING =
      MB_ICONWARNING + MB_OK, /**< Warning message box with OK button */
  WMB_INFO =
      MB_ICONINFORMATION + MB_OK /**< Information message box with OK button */
};

/**
 * Structure representing window dimensions.
 *
 * This structure holds the width and height of a window in pixels.
 * Useful for defining window size and performing size-related calculations.
 */
struct WinSizePlus {
  u16 Width;  /**< Width of the window in pixels */
  u16 Height; /**< Height of the window in pixels */
};

/**
 * Structure representing window position coordinates.
 *
 * This structure contains the X and Y coordinates for the window's position.
 * Useful for window placement and movement operations.
 */
struct WinPosPlus {
  i16 PosX; /**< X-coordinate of the window position */
  i16 PosY; /**< Y-coordinate of the window position */
};

/**
 * Structure containing message box properties.
 *
 * Holds information about the message box title, class name, and identifier.
 * Useful for creating and managing message boxes with specific properties.
 */
class WINPLUS_API WinMessageBoxPlus {
public:
  const string Title;     /**< Window title. */
  const string ClassName; /**< Window class name. */
  i32 Id;                 /**< Unique identifier for the message box */

  /**
   * Closes a message box.
   *
   * Closes the specified message box, freeing associated resources.
   * Useful for managing message box lifecycle.
   */
  WINPLUS_API void Close();

  /**
   * Forcefully terminates a message box.
   *
   * Immediately closes the specified message box, regardless of its state.
   * Useful for emergency shutdown of message boxes.
   */
  WINPLUS_API void Kill();

  /**
   * Sets the type and style of a message box.
   *
   * Configures the specified message box with the given type and style.
   * Useful for customizing message box appearance and behavior.
   */
  WINPLUS_API void SetType(WMB_Type type);
};

/**
 * Structure containing window properties.
 *
 * Combines window size, position, title, and identifier into a single
 * structure. Useful for comprehensive window management and manipulation.
 */
class WINPLUS_API WindowPlus {
public:
  WinSizePlus Size;    /**< Window size information */
  WinPosPlus Position; /**< Window position information */
  const string Title;  /**< Window title.  */
  i32 Id;              /**< Unique identifier for the window */

  /**
   * Closes a window.
   *
   * Closes the specified window, freeing associated resources.
   * Useful for managing window lifecycle.
   */
  WINPLUS_API void Close();

  /**
   * Forcefully terminates a window.
   *
   * Immediately closes the specified window, regardless of its state.
   * Useful for emergency shutdown of windows.
   */
  WINPLUS_API void Kill();

  /**
   * Gets the width of a window.
   *
   * Retrieves and returns the width of the specified window in pixels.
   * Useful for layout and rendering calculations.
   */
  WINPLUS_API u16 GetWidth() const;

  /**
   * Gets the height of a window.
   *
   * Retrieves and returns the height of the specified window in pixels.
   * Useful for layout and rendering calculations.
   */
  WINPLUS_API u16 GetHeight() const;

  /**
   * Gets the X-coordinate of a window's position.
   *
   * Retrieves and returns the X-coordinate of the specified window's position.
   * Useful for positioning and alignment operations.
   */
  WINPLUS_API i16 GetPosX() const;

  /**
   * Gets the Y-coordinate of a window's position.
   *
   * Retrieves and returns the Y-coordinate of the specified window's position.
   * Useful for positioning and alignment operations.
   */
  WINPLUS_API i16 GetPosY() const;
};

/**
 * Initializes a new message box.
 *
 * Creates and returns a new message box with the specified title and class
 * name. Useful for displaying messages to users in a standardized format.
 */
WINPLUS_API WinMessageBoxPlus WMB_Init(string Title, string ClassName);

/**
 * Initializes a new window.
 *
 * Creates and returns a new window with the specified position, size, and
 * title. Useful for creating application windows with specific properties.
 */
WINPLUS_API WindowPlus WP_Init(i16 x, i16 y, u16 width, u16 height,
                               const string Title);

/**
 * Generates a unique identifier.
 *
 * Computes and returns a unique identifier.
 * Useful for tracking and managing.
 */
WINPLUS_API i32 GenerateID();