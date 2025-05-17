#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "argc: " << argc << "\n";
  std::cout << "argv: [";
  for (int i = 0; i < argc; ++i) {
    std::cout << argv[i] << ", ";
  }
  std::cout << "]\n";
  return 0;
}
