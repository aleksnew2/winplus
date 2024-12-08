#include "include/Winplus.conf_compiler.h"
#include <fstream>
#include <iostream>
#include <print>

std::string_view tokenTypeToString(winplus::compiler::lexer::Lexer::TokenType type) {
  switch (type) {
    case winplus::compiler::lexer::Lexer::TokenType::ENUMERATION: return "ENUMERATION";
    case winplus::compiler::lexer::Lexer::TokenType::TYPE: return "TYPE";
    case winplus::compiler::lexer::Lexer::TokenType::TITLE: return "TITLE";
    case winplus::compiler::lexer::Lexer::TokenType::ID: return "ID";
    case winplus::compiler::lexer::Lexer::TokenType::STRING_LITERAL: return "STRING";
    case winplus::compiler::lexer::Lexer::TokenType::INT_LITERAL: return "INTEGER";
    case winplus::compiler::lexer::Lexer::TokenType::COLON: return "COLON";
    case winplus::compiler::lexer::Lexer::TokenType::SEMICOLON: return "SEMICOLON";
    case winplus::compiler::lexer::Lexer::TokenType::ERROR: return "ERROR";
    case winplus::compiler::lexer::Lexer::TokenType::END_OF_FILE: return "EOF";
  }
  return "UNKNOWN";
}

int main() {
  std::string filename = "file.txt";
  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Failed to open the file: " << filename << std::endl;
    return 1;
  }

  std::string content;
  std::string line;
  while (std::getline(file, line)) {
    content += line + "\n";
  }

  file.close();

  winplus::compiler::lexer::Lexer lexer(content);
  auto tokens = lexer.tokenize();

  for (const auto& token : tokens) {
    std::print("Token: {}, Lexeme: '{}', Line: {}\n", 
               tokenTypeToString(token.type), 
               token.lexeme, 
               token.line);
  }
}