#include "ListCreator/ListCreator.h"
#include "ListNode.h"
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

    std::cout << "\n\n";
    ListCreator creator(data);
    ListNode *head = creator.getHead();

    ListNode *cur = head;
    int i = 0;
    while (cur) {
      std::cout << "[" << i << "] "
                << "data: \"" << cur->data << "\""
                << "; prev: "
                << (cur->prev ? "\"" + cur->prev->data + "\"" : "nullptr")
                << "; next: "
                << (cur->next ? "\"" + cur->next->data + "\"" : "nullptr")
                << "; rand: "
                << (cur->rand ? "\"" + cur->rand->data + "\"" : "nullptr")
                << "\n";
      cur = cur->next;
      ++i;
    }

  } catch (const ParserException &e) {
    std::cerr << "Parse error: " << e.what() << "\n";
    return 1;
  }

  std::cout << '\n';
  return 0;
}
