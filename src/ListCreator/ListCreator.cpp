#include "ListCreator.h"
#include "../ListNode.h"
#include "../validator/validator.h"
#include <stdexcept>

ListCreator::ListCreator(const Data &data) : head_(nullptr) {
  initDataTokens(data);
  try {
    initIndexTokens(data);
  } catch (...) {
    freeList();
    throw;
  }
}

void ListCreator::initDataTokens(const Data &data) {
  size_t n = data.size();
  if (n == 0) {
    head_ = nullptr;
    return;
  }

  nodes_.reserve(n);

  head_ = new ListNode();
  ListNode *head = head_;
  ListNode *prev = nullptr;

  for (size_t i = 0; i < n; ++i) {
    head->prev = prev;
    if (i != n - 1) {
      head->next = new ListNode();
    } else {
      head->next = nullptr;
    }
    head->data = data[i].first;
    nodes_.push_back(head);
    prev = head;
    head = head->next;
  }
}

void ListCreator::initIndexTokens(const Data &data) {
  size_t n = data.size();

  for (size_t i = 0; i < n; ++i) {
    int index = data[i].second;
    if (!Validator::checkRandIndex(index, n))
      throw std::out_of_range("Rand index " + std::to_string(index) +
                              " out of range for node " + std::to_string(i) +
                              " (list size = " + std::to_string(n) + ")");

    nodes_[i]->rand = (index == -1) ? nullptr : nodes_[index];
  }
}

void ListCreator::freeList() noexcept {
  ListNode *cur = head_;
  while (cur) {
    ListNode *next = cur->next;
    delete cur;
    cur = next;
  }
  head_ = nullptr;
}

ListCreator::~ListCreator() { freeList(); }
