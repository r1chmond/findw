#include <iostream>

int main(int argc, char *argv[]) {
  // guard to enforce parsing 2 arguments
  if (argc < 3) {
    std::cerr << "error: insufficient arguments." << std::endl;
    return 1;
  } else if (argc > 3) {
    std::cerr << "error: Too many arguments." << std::endl;
    return 1;
  }

  std::cout << "argc: " << argc << "\n";
  std::cout << "argv: [";
  for (int i = 0; i < argc; ++i) {
    std::cout << argv[i] << ", ";
  }
  std::cout << "]\n";
  return 0;
}
