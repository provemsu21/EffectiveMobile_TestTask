#ifndef SERIALIZER_SERIALIZER_H_
#define SERIALIZER_SERIALIZER_H_

#include "../ListNode.h"
#include <fstream>
#include <stdexcept>
#include <unordered_map>

namespace Serializer {
inline void serialize(ListNode *head, const std::string &filename) {
  std::ofstream os(filename, std::ios::binary);
  if (!os.is_open())
    throw std::runtime_error("Cannot open file: " + filename);

  std::unordered_map<ListNode *, int> indexMap;
  ListNode *cur = head;
  int idx = 0;
  while (cur) {
    indexMap[cur] = idx++;
    cur = cur->next;
  }

  int32_t count = static_cast<int32_t>(indexMap.size());
  os.write(reinterpret_cast<const char *>(&count), sizeof(count));

  cur = head;
  while (cur) {
    int32_t dataLen = static_cast<int32_t>(cur->data.size());
    os.write(reinterpret_cast<const char *>(&dataLen), sizeof(dataLen));

    os.write(cur->data.data(), dataLen);

    int32_t randIndex = (cur->rand == nullptr) ? -1 : indexMap[cur->rand];
    os.write(reinterpret_cast<const char *>(&randIndex), sizeof(randIndex));

    cur = cur->next;
  }
}
} // namespace Serializer

#endif // SERIALIZER_SERIALIZER_H_
