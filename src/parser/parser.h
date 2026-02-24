#ifndef PARSER_PARSER_H_
#define PARSER_PARSER_H_

#include "../types.h"
#include <fstream>
#include <stdexcept>
#include <string>

class ParserException : public std::runtime_error {
public:
  explicit ParserException(const std::string &msg) : std::runtime_error(msg) {}
};

class Parser {
private:
  const std::string filename_;
  std::ifstream is_;
  Data data_;

  void openFile();
  bool isOpen() const;

public:
  explicit Parser(const std::string &filename);
  void parseFile();
  const Data &getData() const { return data_; }
};

#endif // PARSER_PARSER_H_
