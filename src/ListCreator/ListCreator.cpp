#include "ListCreator.h"
#include "../ListNode.h"
#include "../validator/validator.h"
#include <stdexcept>

ListCreator::ListCreator(const Data &data) : head_(nullptr), data_(data) {
  initDataTokens();
  initIndexTokens();
}

void ListCreator::initDataTokens() {
  if (data_.empty()) {
    head_ = nullptr;
    return;
  }
  head_ = new ListNode();
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
  size_t n = data_.size();

  ListNode *head = head_;

  std::vector<ListNode *> nodes;
  nodes.reserve(n);

  while (head) {
    nodes.push_back(head);
    head = head->next;
  }

  for (size_t i = 0; i < n; ++i) {
    int index = data_[i].second;
    if (!Validator::checkRandIndex(index, n))
      throw std::out_of_range("Rand index " + std::to_string(index) +
                              " out of range for node " + std::to_string(i) +
                              " (list size = " + std::to_string(n) + ")");

    nodes[i]->rand = (index == -1) ? nullptr : nodes[index];
  }
}

ListCreator::~ListCreator() {
  ListNode *cur = head_;
  while (cur) {
    ListNode *next = cur->next;
    delete cur;
    cur = next;
  }
}
