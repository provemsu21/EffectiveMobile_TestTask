#include <fstream>
#include <stdexcept>

class ParserException : public std::runtime_error {
public:
  explicit ParserException(const std::string &msg) : std::runtime_error(msg) {}
};

class Parser { // TODO IParser
private:
  const std::string filename_;
  std::ifstream is_;
  std::vector<std::pair<std::string, int>> data_;
  void openFile();
  bool isOpen();

public:
  Parser(const std::string &filename);
  bool parseFile();
  const std::vector<std::pair<std::string, int>> &getData() const {
    return data_;
  }
};
