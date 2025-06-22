#include <cstddef>
#include <fstream>
#include <iomanip>
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

/*
 * Checks if the given pattern exists within the content.
 * @param content The text to search in.
 * @param pattern The substring to search for.
 * @return True if the pattern is found in the content, false otherwise.
 */
bool contains(const string &content, const string &pattern) {
  size_t pos = content.find(pattern);
  return pos != string::npos;
}

/*
 * Displays usage instructions to the user, indicating
 * the expected command-line input format.
 */
void displayUsage() {
  const int WIDTH = 15;
  const int patternLength =
      9; // size of "<pattern>". Help line-up the print out
  string findw = "findw ";
  cout << "USAGE:\n";
  cout << std::setw(WIDTH - (patternLength - findw.size())) << findw
       << "<pattern> <path> \n";
}

/**
 * Displays an error message indicating that required
 * command-line arguments are missing, and shows
 * the expected arguments.
 */
void insufficientArgsError() {
  const int WIDTH = 15;
  string pattern = "<pattern>";
  string path = "<path>";
  cerr << "error: The following required arguments were not provided:\n";
  cerr << std::setw(WIDTH) << pattern << "\n";
  cerr << std::setw(WIDTH - (pattern.size() - path.size())) << path << "\n";
}

int main(int argc, char *argv[]) {
  // Validate that exactly 2 arguments are provided (excluding program name)
  if (argc < 3) {
    insufficientArgsError();
    displayUsage();
    return 1;
  } else if (argc > 3) {
    cerr << "error: Too many arguments.\n";
    displayUsage();
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
    if (contains(line, cli.pattern)) {
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
