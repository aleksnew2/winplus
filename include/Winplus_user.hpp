#include "Winplus_defines.hpp"
#include "Winplus_types.hpp"
#include <complex.h>
#include <minwindef.h>
#include <windows.h>

#ifndef WINPLUS_USER_H
#define WINPLUS_USER_H

namespace winplus {

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

  virtual ~WinSizePlus() = default;
  /** Sets window width. */
  virtual WINPLUS_API void SetWidth(u16 newData);
  /** Sets window height. */
  virtual WINPLUS_API void SetHeight(u16 newData);
  /** Returns window width. */
  virtual WINPLUS_API u16 GetWidth() const;
  /** Returns window height. */
  virtual WINPLUS_API u16 GetHeight() const;
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

  virtual ~WinPosPlus() = default;
  /** Sets window X position. */
  virtual WINPLUS_API void SetPosX(i16 newData);
  /** Sets window Y position. */
  virtual WINPLUS_API void SetPosY(i16 newData);
  /** Returns window X position. */
  virtual WINPLUS_API i16 GetPosX() const;
  /** Returns window Y position. */
  virtual WINPLUS_API i16 GetPosY() const;
};

/**
 * Structure containing message box properties.
 *
 * Holds information about the message box title, class name, and identifier.
 * Useful for creating and managing message boxes with specific properties.
 */
class WINPLUS_API WinMessageBoxPlus {
public:
  string Title;     /**< Window title. */
  const string ClassName; /**< Window class name. */
  u32 Id;                 /**< Unique identifier for the message box */
  WMB_Type Type;          /**< Message box type. */

  /**
   * Closes a message box.
   *
   * Closes the specified message box, freeing associated resources.
   * Useful for managing message box lifecycle.
   */
  WINPLUS_API void Close();

  /**
   * Opens a message box.
   *
   * Displays the specified message box to the user,
   * allowing interaction with the message box content.
   */
  WINPLUS_API void Open();

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
class WINPLUS_API WindowPlus : public WinSizePlus, public WinPosPlus {
public:
  string Title;     /**< Window title.  */
  const string ClassName; /**< Window class name. */
  u32 Id;                 /**< Unique identifier for the window */

  /**
   * Closes a window.
   *
   * Closes the specified window, freeing associated resources.
   * Useful for managing window lifecycle.
   */
  WINPLUS_API void Close();

  /**
   * Opens a window.
   *
   * Displays the specified window on the screen, allowing user interaction
   * with the window content.
   */
  WINPLUS_API void Open();

  /**
   * Sets window width.
   *
   * Sets the width of the window to the specified value.
   */
  WINPLUS_API void SetWidth(u16 newData) override { Width = newData; }

  /**
   * Sets window height.
   *
   * Sets the height of the window to the specified value.
   */
  WINPLUS_API void SetHeight(u16 newData) override { Height = newData; }

  /**
   * Returns window width.
   *
   * Returns the current width of the window.
   */
  WINPLUS_API u16 GetWidth() const override { return Width; }

  /**
   * Returns window height.
   *
   * Returns the current height of the window.
   */
  WINPLUS_API u16 GetHeight() const override { return Height; }

  /**
   * Sets window X position.
   *
   * Sets the X-coordinate of the window position to the specified value.
   */
  WINPLUS_API void SetPosX(i16 newData) override { PosX = newData; }

  /**
   * Sets window Y position.
   *
   * Sets the Y-coordinate of the window position to the specified value.
   */
  WINPLUS_API void SetPosY(i16 newData) override { PosY = newData; }

  /**
   * Returns window X position.
   *
   * Returns the current X-coordinate of the window position.
   */
  WINPLUS_API i16 GetPosX() const override { return PosX; }

  /**
   * Returns window Y position.
   *
   * Returns the current Y-coordinate of the window position.
   */
  WINPLUS_API i16 GetPosY() const override { return PosY; }
};

// class WINPLUS_API WinComponentPlus{

// };

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
WINPLUS_API u32 GenerateID();

}

#endif