#include <iostream>

// Log signature
void Log (const char* message);

int Multiply(int a, int b) {
  Log("Multiply");
  return a * b;
}

int main () {
  std::cout << Multiply(5, 8) << std::endl;
  std::cin.get();
}