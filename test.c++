#include "include/Winplus.hpp"

int main() {
  auto msg = WMB_Init("HI!", "@");
  msg.SetType(WMB_ERROR);
  msg.Open();
}