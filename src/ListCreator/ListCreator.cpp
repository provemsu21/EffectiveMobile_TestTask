#include "ListCreator.h"
#include "../ListNode.h"

ListCreator::ListCreator(const Data &data)
    : head_(new ListNode()), data_(data) {
  initDataTokens();
  initIndexTokens();
}

void ListCreator::initDataTokens() {
  ListNode *head = head_;
  ListNode *prev = nullptr;
  for (size_t i = 0; i < data_.size(); ++i) {
    head->prev = prev;
    if (i != data_.size() - 1) {
      head->next = new ListNode();
    } else {
      head->next = nullptr;
    }
    head->data = data_[i].first;
    prev = head;
    head = head->next;
  }
}

void ListCreator::initIndexTokens() {
  ListNode *head = head_;

  std::vector<ListNode *> nodes;
  nodes.reserve(data_.size());

  while (head) {
    nodes.push_back(head);
    head = head->next;
  }

  for (size_t i = 0; i < data_.size(); ++i) {
    int index = data_[i].second;
    nodes[i]->rand =
        (index <= -1 || index >= static_cast<int>(data_.size()) ? nullptr
                                                                : nodes[index]);
  }
}
