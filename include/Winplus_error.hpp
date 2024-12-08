#include "Winplus_defines.hpp"
#include "Winplus_types.hpp"

#ifndef WINPLUS_ERROR_H
#define WINPLUS_ERROR_H

namespace winplus::error {
/**
 * Terminates the current process with an error code.
 *
 * This function is used internally for error handling and should not be called
 * directly. Useful for halting execution when an unrecoverable error occurs.
 * Outputs error before stopping program process.
 */
WINPLUS_API void StopProcess(winplus::error_code error);

/**
 * Logs an error code.
 *
 * Outputs the error code to the console or logging mechanism.
 * Useful for debugging and logging errors that do not require process
 * termination. Does not halt execution of the program.
 */
WINPLUS_API void Log(winplus::error_code error);
} // namespace winplus::error

#endif