#ifndef PARSER_PARSER_H_
#define PARSER_PARSER_H_

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
  explicit Parser(const std::string &filename);
  void parseFile();
  const Data &getData() const { return data_; }
};

#endif // PARSER_PARSER_H_
