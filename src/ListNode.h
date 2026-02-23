#ifndef LISTNODE_H_
#define LISTNODE_H_

#include <string>

struct ListNode {
  ListNode *prev = nullptr;
  ListNode *next = nullptr;
  ListNode *rand = nullptr;

  std::string data;
};

#endif // LISTNODE_H_
