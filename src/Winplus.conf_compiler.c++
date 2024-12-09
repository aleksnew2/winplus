#include "../include/Winplus.conf_compiler.hpp"
#include <cctype>

namespace winplus::compiler {
namespace lexer {

char Lexer::advance() { return source_[current_++]; }

char Lexer::peek() const {
  if (current_ >= source_.length())
    return '\0';
  return source_[current_];
}

char Lexer::peekNext() const {
  if (current_ + 1 >= source_.length())
    return '\0';
  return source_[current_ + 1];
}

bool Lexer::match(char expected) {
  if (current_ >= source_.length())
    return false;
  if (source_[current_] != expected)
    return false;
  current_++;
  return true;
}

void Lexer::skipWhitespace() {
  for (;;) {
    char c = peek();
    switch (c) {
    case ' ':
    case '\r':
    case '\t':
      advance();
      break;
    case '\n':
      line_++;
      advance();
      break;
    default:
      return;
    }
  }
}

Lexer::Token Lexer::makeToken(TokenType type) {
  std::string lexeme = source_.substr(start_, current_ - start_);
  return Token(type, lexeme, line_);
}

Lexer::Token Lexer::string() {
  while (peek() != '\'' && !source_.empty()) {
    if (peek() == '\n')
      line_++;
    advance();
  }

  if (current_ >= source_.length()) {
    return errorToken("Unterminated string.");
  }

  advance();

  std::string value = source_.substr(start_ + 1, current_ - start_ - 2);
  return Token(TokenType::STRING_LITERAL, value, line_);
}

Lexer::Token Lexer::number() {
  while (isDigit(peek()))
    advance();

  std::string num = source_.substr(start_, current_ - start_);
  return Token(TokenType::INT_LITERAL, num, line_);
}

Lexer::Token Lexer::identifier() {
  while (isAlphaNumeric(peek()))
    advance();

  std::string text = source_.substr(start_, current_ - start_);

  if (text == "enumeration")
    return Token(TokenType::ENUMERATION, text, line_);
  if (text == "type")
    return Token(TokenType::TYPE, text, line_);
  if (text == "title")
    return Token(TokenType::TITLE, text, line_);
  if (text == "id")
    return Token(TokenType::ID, text, line_);

  return errorToken("Unexpected identifier: " + text);
}

bool Lexer::isDigit(char c) const { return c >= '0' && c <= '9'; }

bool Lexer::isAlpha(char c) const {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool Lexer::isAlphaNumeric(char c) const { return isAlpha(c) || isDigit(c); }

Lexer::Token Lexer::errorToken(const std::string &message) {
  return Token(TokenType::ERROR, message, line_);
}

Lexer::Token Lexer::nextToken() {
  skipWhitespace();

  start_ = current_;

  if (current_ >= source_.length()) {
    return Token(TokenType::END_OF_FILE, "", line_);
  }

  char c = advance();

  if (isDigit(c))
    return number();
  if (isAlpha(c))
    return identifier();

  switch (c) {
  case '\'':
    return string();
  case ':':
    return makeToken(TokenType::COLON);
  case ';':
    return makeToken(TokenType::SEMICOLON);
  }

  return errorToken(std::string("Unexpected character: ") + c);
}

std::vector<lexer::Lexer::Token> Lexer::tokenize() {
  std::vector<Token> tokens;

  while (hasMoreTokens()) {
    Token token = nextToken();
    tokens.push_back(token);

    if (token.type == TokenType::ERROR ||
        token.type == TokenType::END_OF_FILE) {
      break;
    }
  }

  return tokens;
}

} // namespace lexer

namespace parser {

lexer::Lexer::Token Parser::peek() const {
  if (isAtEnd()) return tokens_[tokens_.size() - 1];
  return tokens_[current_];
}

lexer::Lexer::Token Parser::advance() {
  if (!isAtEnd()) current_++;
  return tokens_[current_ - 1];
}

bool Parser::check(lexer::Lexer::TokenType type) const {
  if (isAtEnd()) return false;
  return peek().type == type;
}

lexer::Lexer::Token Parser::consume(lexer::Lexer::TokenType type, const std::string& message) {
  if (check(type)) return advance();
  throw std::runtime_error(message);
}

bool Parser::isAtEnd() const {
  return current_ >= tokens_.size() || 
         tokens_[current_].type == lexer::Lexer::TokenType::END_OF_FILE;
}

EnumEntry Parser::parseEnumeration() {
  EnumEntry entry;
  
  // Parse: enumeration [number]:
  consume(lexer::Lexer::TokenType::ENUMERATION, "Expected 'enumeration'");
  auto enumIdToken = consume(lexer::Lexer::TokenType::INT_LITERAL, "Expected enumeration ID");
  entry.enumId = std::stoi(enumIdToken.lexeme);
  consume(lexer::Lexer::TokenType::COLON, "Expected ':' after enumeration ID");

  // Parse: type: '[value]'
  consume(lexer::Lexer::TokenType::TYPE, "Expected 'type'");
  consume(lexer::Lexer::TokenType::COLON, "Expected ':' after 'type'");
  auto typeToken = consume(lexer::Lexer::TokenType::STRING_LITERAL, "Expected type value");
  entry.type = typeToken.lexeme;

  // Validate type value
  if (entry.type != "error" && entry.type != "app_id") {
    throw std::runtime_error("Invalid type value: '" + entry.type + "'. Expected 'error' or 'app_id'");
  }

  // Parse: title: '[value]'
  consume(lexer::Lexer::TokenType::TITLE, "Expected 'title'");
  consume(lexer::Lexer::TokenType::COLON, "Expected ':' after 'title'");
  auto titleToken = consume(lexer::Lexer::TokenType::STRING_LITERAL, "Expected title value");
  entry.title = titleToken.lexeme;

  // Parse: id: [number];
  consume(lexer::Lexer::TokenType::ID, "Expected 'id'");
  consume(lexer::Lexer::TokenType::COLON, "Expected ':' after 'id'");
  auto idToken = consume(lexer::Lexer::TokenType::INT_LITERAL, "Expected ID value");
  entry.id = std::stoi(idToken.lexeme);
  consume(lexer::Lexer::TokenType::SEMICOLON, "Expected ';' after enumeration");

  return entry;
}

std::vector<EnumEntry> Parser::parse() {
  std::vector<EnumEntry> entries;
  
  while (!isAtEnd()) {
    try {
      entries.push_back(parseEnumeration());
    } catch (const std::runtime_error& e) {
      // Skip to the next enumeration or end of file
      while (!isAtEnd() && !check(lexer::Lexer::TokenType::ENUMERATION)) {
        advance();
      }
    }
  }
  
  return entries;
}

} // namespace parser
} // namespace winplus::compiler
