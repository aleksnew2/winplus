#include "include/Winplus.hpp"
#include <print>

int main() {
  const auto code = winplus::rand::GenerateErrorCode();
  std::println("{}", code);
}