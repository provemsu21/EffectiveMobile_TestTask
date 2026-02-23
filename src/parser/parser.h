#include <fstream>
#include <stdexcept>

using Data = std::vector<std::pair<std::string, int>>;

class ParserException : public std::runtime_error {
public:
  explicit ParserException(const std::string &msg) : std::runtime_error(msg) {}
};

class Parser { // TODO IParser
private:
  const std::string filename_;
  std::ifstream is_;
  Data data_;
  void openFile();
  bool isOpen();

public:
  Parser(const std::string &filename);
  bool parseFile();
  const Data &getData() const { return data_; }
};
