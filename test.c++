#include "include/Winplus.hpp"
#include <print>

int main() {
  winplus::error::Log(6, "hELLO!");
  winplus::error::StopProcess(5, "Hi!");
}