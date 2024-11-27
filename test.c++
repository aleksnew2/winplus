#include "include/winplus.h"
#include <iostream>

void
print()
{
  std::cout << "HI!" << std::endl;
}

int
main()
{
  WAIT_Q(TT_SECOND, 5, print);
}