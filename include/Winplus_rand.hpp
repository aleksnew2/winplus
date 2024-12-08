#include "Winplus_defines.hpp"
#include "Winplus_types.hpp"

#ifndef WINPLUS_RAND_H
#define WINPLUS_RAND_H

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
WINPLUS_API u16 GenerateErrorCode();
} // namespace winplus::rand
#endif
