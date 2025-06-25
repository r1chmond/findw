#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <iostream>
#include <string>

using std::string;

struct CommandLine {
  string pattern;
  string path;

  CommandLine(const string &patternIn, const string &pathIn);
};

#endif
