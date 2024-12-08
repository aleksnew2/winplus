#include "../include/Winplus.hpp"
#include <cstdlib>
#include <print>

WINPLUS_API void winplus::error::Log(winplus::error_code code,
                                     const string message) {
  std::println("[error, {}] {}", code, message);
}

WINPLUS_API void winplus::error::StopProcess(winplus::error_code code,
                                             const string message) {
  winplus::error::Log(code, message);
  std::println("Aborting...");
  abort();
}
