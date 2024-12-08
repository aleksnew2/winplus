#include "Winplus_defines.hpp"

namespace winplus::error {
/**
 * Terminates the current process with an error code.
 *
 * This function is used internally for error handling and should not be called
 * directly. Useful for halting execution when an unrecoverable error occurs.
 * Outputs error before stopping program process. 
 */
WINPLUS_API void StopProcess(u16 error);

/**
  Outputs error with code.


 */
WINPLUS_API void Log();
} // namespace winplus::error