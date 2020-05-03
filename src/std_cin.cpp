#include "std_cin.hpp"
#include <iostream>
#include <vector>

void std_cin::truncate_tail_lf() {
  std::vector<std::string> strs;
  std::string line;
  while (getline(std::cin, line)) {
    strs.push_back(line);
  }
  unsigned int last = strs.size();
  for (unsigned int i = 0; i < last; i++) {
    if (i != last-1) {
      std::cout << strs[i] << std::endl;
    } else {
      std::cout << strs[i];
    }
  }
}
