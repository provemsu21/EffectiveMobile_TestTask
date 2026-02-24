#ifndef LISTMANAGER_LISTCREATOR_H_
#define LISTMANAGER_LISTCREATOR_H_

#include "../types.h"
#include <vector>

struct ListNode;

class ListCreator {
private:
  ListNode *head_;
  Data data_;

  void initDataTokens();
  void initIndexTokens();

public:
  explicit ListCreator(const Data &data);
  ListCreator(const ListCreator &) = delete;
  ListCreator &operator=(const ListCreator &) = delete;
  ~ListCreator();

  ListNode *getHead() const { return head_; }
};

#endif // LISTMANAGER_LISTCREATOR_H_
