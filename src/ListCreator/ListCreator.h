#ifndef LISTMANAGER_LISTCREATOR_H_
#define LISTMANAGER_LISTCREATOR_H_

#include <string>
#include <utility>
#include <vector>

using Data = std::vector<std::pair<std::string, int>>;

class ListNode;

class ListCreator {
private:
  ListNode *head_;
  const Data &data_;

  void initDataTokens();
  void initIndexTokens();

public:
  explicit ListCreator(const Data &data);
  ListNode *getHead() const { return head_; }
};

#endif // LISTMANAGER_LISTCREATOR_H_
