#ifndef VALIDATOR_VALIDATOR_H_
#define VALIDATOR_VALIDATOR_H_

#include <string>

namespace Validator {

static constexpr int MAX_NODES_ = 1'000'000;
static constexpr int MAX_DATA_LENGTH_ = 1'000;

inline bool checkNodesSize(int count) { return count <= MAX_NODES_; }
inline bool checkDataLength(const std::string &data) {
  return data.size() <= MAX_DATA_LENGTH_;
}
inline bool isValidRandIndex(int index) { return index == -1 || index >= 0; }
inline bool checkRandIndex(int index, size_t nodeCount) {
  if (index == -1)
    return true;
  if (index < 0)
    return false;
  return static_cast<size_t>(index) < nodeCount;
}
}; // namespace Validator

#endif // VALIDATOR_VALIDATOR_H_
