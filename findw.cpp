#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::ifstream;
using std::string;
using std::vector;

struct CommandLine {
  string pattern;
  string path;

  CommandLine(const string &patternIn, const string &pathIn)
      : pattern(patternIn), path(pathIn) {}
};

int main(int argc, char *argv[]) {
  // guard to enforce parsing 2 arguments
  if (argc < 3) {
    cerr << "error: insufficient arguments.\n";
    return 1;
  } else if (argc > 3) {
    cerr << "error: Too many arguments.\n";
    return 1;
  }

  cout << "argc: " << argc << "\n";
  cout << "argv: [";
  for (int i = 0; i < argc; ++i) {
    cout << argv[i] << ", ";
  }
  cout << "]\n";

  CommandLine cli{argv[1], argv[2]};

  vector<string> fileContent{};
  ifstream infile{cli.path};
  if (!infile) {
    cerr << "Error opening file!\n" << "EXIT 1\n";
    std::exit(EXIT_FAILURE);
  }
  std::string line{};
  while (std::getline(infile, line)) {
    fileContent.push_back(line);
  }
  cout << "\n";
  infile.close();
  cout << "================================ \n";
  cout << "File has successfully been read!";
  cout << "\n";

  string found{};
  for (const auto &line : fileContent) {
    size_t pos = line.find(cli.pattern);
    if (pos != string::npos) {
      found += line + "\n";
    }
  }
  if (found.empty()) {
    cout << "\"" + cli.pattern + "\"" + " not found!\n";
  } else {
    cout << "\n";
    cout << "Found!\n";
    cout << found << "\n";
  }

  return 0;
}
