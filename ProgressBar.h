#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

#include <chrono>
#include <iostream>
#include <iterator>
#include <string>
#include <thread>

using std::cout;
using std::string;

#define CLEAR "\x1B[2K\r"

template <typename Iterator>

class ProgressBar {
private:
  Iterator begin;
  Iterator end;
  size_t progressCount;
  char loadStyle;                        // character to indicate progress
  std::pair<char, char> blockCharacters; // open and close charaters eg: []
  size_t vectorSize;
  double increment;
  const size_t BAR_SIZE = 10;
  const size_t MAX_PERCENTAGE = 100;

  /*
   * Repeats a character n times
   * @param c charater to repeat
   * @param n number of times to repeat the character
   * @return string for the same charater of size n
   */
  string repeat(char c, int n) {
    string res(n, c);
    return res;
  }

  size_t currentProgress(size_t prevProgressCount) {
    size_t result = progressCount * increment;
    if (result > MAX_PERCENTAGE || prevProgressCount == BAR_SIZE) {
      return MAX_PERCENTAGE;
    }
    return result;
  }

  void delay() { std::this_thread::sleep_for(std::chrono::milliseconds(50)); }

  void barContent() {
    size_t fillCount = (progressCount * BAR_SIZE) / vectorSize;
    cout << CLEAR << currentProgress(fillCount) << "% " << blockCharacters.first
         << repeat(loadStyle, fillCount) << repeat('_', BAR_SIZE - fillCount)
         << blockCharacters.second << std::flush;
  }

public:
  ProgressBar(Iterator begin, Iterator end)
      : begin(begin), end(end), progressCount(0), loadStyle('*'),
        blockCharacters({'[', ']'}), vectorSize(std::distance(begin, end)) {
    increment = double(MAX_PERCENTAGE) / vectorSize;
  }

  ProgressBar(Iterator begin, Iterator end, char loadStyleIn,
              char lBlockCharacter, char rBlockCharacter)
      : begin(begin), end(end), progressCount(0), loadStyle(loadStyleIn),
        blockCharacters({lBlockCharacter, rBlockCharacter}),
        vectorSize(std::distance(begin, end)) {
    increment = double(MAX_PERCENTAGE) / vectorSize;
  }

  void setLoadStyle(char c) { loadStyle = c; }

  void setBlockCharacters(char l, char r) { blockCharacters = {l, r}; }

  void showProgress() {
    delay();
    ++*this; // move iter to point to the next element
    barContent();
  }

  void finishMsg(const string &msg) {
    cout << "\n";
    cout << msg << "\n";
  }

  ProgressBar &operator++() {
    if (begin != end) {
      ++progressCount;
      ++begin;
    }
    return *this;
  }
};

#endif
