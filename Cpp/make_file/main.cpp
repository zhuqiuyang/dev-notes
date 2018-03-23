#include <iostream>
#include "functions.h"

int main() {
  print_hello();
  std::cout << std::endl;
  std::cout << "Fact of 5 is " << factorial(5) << std::endl;
  return 0;
}