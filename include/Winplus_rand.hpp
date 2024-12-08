#include "Winplus_defines.hpp"
#include "Winplus_types.hpp"

namespace winplus::rand {
/**
 * Generates a unique identifier.
 *
 * Computes and returns a unique identifier.
 * Useful for tracking and managing.
 */
WINPLUS_API u32 GenerateID();

/**
 * Generates an error code.
 *
 * Computes and returns a unique error code.
 * Useful for generating platform-independent error codes.
 */
WINPLUS_API u32 GenerateErrorCode();
} // namespace winplus::rand