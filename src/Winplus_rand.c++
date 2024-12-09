#include "../include/Winplus.hpp"
#include <random>

using namespace winplus;

WINPLUS_API u32 rand::GenerateID() {
  u32 length = 9;

  u32 lower_bound = std::pow(10, length - 1);
  u32 upper_bound = std::pow(10, length) - 1;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(lower_bound, upper_bound);
  return dis(gen);
}

WINPLUS_API u16 rand::GenerateErrorCode() {
  u16 length = 5;

  u16 lower_bound = std::pow(4, length - 1);
  u16 upper_bound = std::pow(4, length) - 1;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(lower_bound, upper_bound);
  return dis(gen);
}