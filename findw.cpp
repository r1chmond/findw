#include <fstream>
#include <iostream>
#include <string>

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

  std::string pattern = argv[1];
  std::string path = argv[2];
  std::ifstream infile{path};
  if (!infile) {
    std::cerr << "Error opening file!\n" << "EXIT 1\n";
    std::exit(EXIT_FAILURE);
  }
  std::string line{};
  while (std::getline(infile, line)) {
    std::cout << line;
  }
  std::cout << "\n";
  infile.close();
  std::cout << "================================ \n";
  std::cout << "File has successfully been read!";
  std::cout << "\n";

  return 0;
}
