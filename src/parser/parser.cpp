#include "parser.h"
#include "../validator/validator.h"
#include <ios>
#include <string>

Parser::Parser(const std::string &filename) : filename_(filename) {}

void Parser::openFile() { is_.open(filename_, std::ios::in); }

bool Parser::isOpen() { return is_.is_open(); }

void Parser::parseFile() {
  openFile();
  if (!isOpen())
    throw ParserException("Cannot open file: " + filename_);

  std::string line;
  int line_num = 0;
  while (std::getline(is_, line)) {
    ++line_num;
    if (line.empty())
      continue;

    size_t sep = line.rfind(';');
    if (sep == std::string::npos)
      throw ParserException("Invalid format at line " +
                            std::to_string(line_num) + ": no ';' separator");

    std::string data_token = line.substr(0, sep);
    std::string index_token = line.substr(sep + 1);

    try {
      int index = std::stoi(index_token);
      if (!Validator::checkDataLength(data_token))
        throw ParserException("Data too long at line " +
                              std::to_string(line_num));
      if (!Validator::checkNodesSize(data_.size()))
        throw ParserException("Too many nodes, max is " +
                              std::to_string(Validator::MAX_NODES_));

      data_.push_back({std::move(data_token), index});
    } catch (const ParserException &) {
      throw;
    } catch (...) {
      throw ParserException("Invalid rand index at line " +
                            std::to_string(line_num));
    }
  }

  is_.close();
  if (data_.empty())
    throw ParserException("File is empty or has no valid data");
}
