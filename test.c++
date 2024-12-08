#include "include/Winplus.hpp"
#include <print>

int main() { 
  auto window = winplus::user::WP_Init(50, 60, 500, 500, "Window"); 
  std::println("{}", window.Id);
  window.Open();
}