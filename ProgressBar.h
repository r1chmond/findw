#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

#include <iostream>
#include <iterator>
#include <string>

using std::cout;
using std::string;

template <typename Iterator>

class ProgressBar {
private:
  Iterator begin;
  Iterator end;
  size_t progressCount;

public:
  ProgressBar(Iterator begin, Iterator end)
      : begin(begin), end(end), progressCount(0) {}

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

  void showProgress() { cout << repeat('*', progressCount) << "\n"; }

  ProgressBar &operator++() {
    if (begin != end) {
      ++progressCount;
      ++begin;
    }
    return *this;
  }
};

#endif
