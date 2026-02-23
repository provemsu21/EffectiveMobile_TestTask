#include "parser/parser.h"
#include <iostream>

int main() {
  std::cout << '\n';
  try {
    Parser parser("inlet.in");
    parser.parseFile();

    const auto &data = parser.getData();
    std::cout << "Parsed " << data.size() << " nodes:\n\n";
    for (size_t i = 0; i < data.size(); ++i) {
      std::cout << "[" << i << "] "
                << "data: \"" << data[i].first << "\""
                << "; rand: " << data[i].second << "\n";
    }
  } catch (const ParserException &e) {
    std::cerr << "Parse error: " << e.what() << "\n";
    return 1;
  }
  std::cout << '\n';
  return 0;
}
