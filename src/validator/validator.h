#include <string>
#include <vector>

namespace Validator {

static constexpr int MAX_NODES_ = 1e6;
static constexpr int MAX_DATA_LENGTH_ = 1e3;

inline bool checkNodesSize(int count) {
  return count >= MAX_NODES_ ? false : true;
}
inline bool checkDataLength(const std::string &data) {
  return data.size() >= MAX_DATA_LENGTH_ ? false : true;
}
}; // namespace Validator
