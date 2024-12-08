#include "Winplus_defines.hpp"
#include "Winplus_types.hpp"
#include <print>
#include <string>
#include <vector>

namespace winplus::compiler {
namespace lexer {
/**
 * A lexical token.
 *
 * A token is the result of breaking a stream of source code into individual
 * units of meaning. Each token represents a single element in the source code
 * stream, such as a keyword, identifier, or operator.
 */
class WINPLUS_API Lexer {
public:
  /**
   * Enumeration of token types for lexical analysis.
   *
   * This enumeration is used to categorize each token into a specific type.
   * The type of a token determines how it is processed in the parser.
   */
  enum class TokenType {
    ENUMERATION,    // For 'enumeration' keyword
    TYPE,           // For 'type:' field
    TITLE,          // For 'title:' field
    ID,             // For 'id:' field
    STRING_LITERAL, // For string values
    INT_LITERAL,    // For integer values
    COLON,          // For ':'
    SEMICOLON,      // For ';' end of object marker
    ERROR,          // For error handling
    END_OF_FILE     // End of input marker
  };

  /**
   * Represents a lexical token.
   *
   * A Token holds the type, lexeme, and line number information for a lexical
   * element in the source code. The 'type' indicates the category of the token,
   * such as a keyword or identifier. The 'lexeme' is the exact substring from
   * the source code that matches the token. The 'line' specifies the line
   * number in the source code where the token is located.
   */
  struct Token {
    TokenType type;
    std::string lexeme;
    int line;

    Token(TokenType t, std::string l, int ln)
        : type(t), lexeme(std::move(l)), line(ln) {}
  };

  explicit Lexer(const std::string &source)
      : source_(source), current_(0), start_(0), line_(1) {}

  /**
   * Scans the source code from the current position and returns the next token.
   *
   * This function advances the current position in the source code and returns
   * the next Token in the stream. The type of the returned token is determined
   * by the next sequence of characters in the source code. The lexeme of the
   * returned token is the exact substring from the source code that matches the
   * token. The line number of the returned token is the line number in the
   * source code where the token is located.
   */
  Token nextToken();

  /**
   * Returns true if there are more tokens to be scanned in the source code
   * stream.
   *
   * This function checks if the current position is within the bounds of the
   * source code string, indicating that there are more tokens to be scanned.
   * Returns true if there are more tokens, false otherwise.
   */
  bool hasMoreTokens() const { return current_ < source_.length(); }

  /**
   * Advances the current position in the source code by one character.
   *
   * This function increments the `current_` index, effectively consuming the
   * current character and moving to the next one in the source code stream.
   * Returns the current character before advancing.
   */
  char advance();

  /**
   * Peeks at the next character in the source code stream without consuming it.
   *
   * Returns the character at the current position in the source code stream
   * without advancing the `current_` index. If the end of input has been
   * reached, returns the null character (`\0`).
   */
  char peek() const;

  /**
   * Peeks at the character after the current one in the source code stream
   * without consuming it.
   *
   * Returns the character immediately following the current position in the
   * source code stream without advancing the `current_` index. If the end of
   * input has been reached, returns the null character (`\0`).
   */
  char peekNext() const;

  /**
   * Matches the current character in the source code stream against the given
   * character.
   *
   * Compares the current character in the source code stream against the given
   * character. If the two characters are equal, the `current_` index is
   * incremented and the function returns `true`. Otherwise, the function simply
   * returns `false` without advancing the `current_` index.
   */
  bool match(char expected);

  /**
   * Skips over whitespace characters in the source code.
   *
   * Advances the current position past any whitespace characters, including
   * spaces, tabs, and line breaks. This function ensures that the lexer
   * continues parsing at the next non-whitespace character.
   */
  void skipWhitespace();

  /**
   * Constructs a lexical token from a given type.
   *
   */
  Token makeToken(TokenType type);

  /**
   * Extracts and returns a string literal token from the source code.
   *
   * This function processes a string literal, capturing all characters between
   * the opening and closing quotes. If the string is unterminated, it returns
   * an error token. The function also handles line breaks within strings
   * by incrementing the line counter.
   */
  Token string();

  /**
   * Extracts and returns an integer literal token from the source code.
   *
   * This function processes an integer literal, capturing all contiguous digits
   * in the source code. The function also handles radix specifiers, such as
   * hexadecimal and octal literals.
   */
  Token number();

  /**
   * Extracts and returns an identifier token from the source code.
   *
   * This function processes an identifier, capturing all alphanumeric
   * characters and underscores in the source code. The function also handles
   * keywords by returning the corresponding token type.
   */
  Token identifier();

  /**
   * Determines if a character is a digit.
   *
   * This function takes a character as input and returns true if the character
   * is a digit (0-9) and false otherwise.
   */
  bool isDigit(char c) const;

  /**
   * Determines if a character is an alphabetic character.
   *
   * This function takes a character as input and returns true if the character
   * is an uppercase or lowercase letter (A-Z, a-z) and false otherwise.
   */
  bool isAlpha(char c) const;

  /**
   * Determines if a character is an alphanumeric character.
   *
   * This function takes a character as input and returns true if the character
   * is an uppercase or lowercase letter (A-Z, a-z) or a digit (0-9) and false
   * otherwise.
   */
  bool isAlphaNumeric(char c) const;

  /**
   * Creates and returns an error token with the given message.
   *
   * This function is used to report errors to the user. The function takes a
   * string message as input and returns a token with the type TokenType::ERROR
   * and the given message. The token is used to report errors to the user.
   */
  Token errorToken(const std::string &message);

  /**
   * Tokenizes the entire source code into a vector of tokens.
   *
   * This function processes the entire source code and returns a vector containing
   * all tokens found in the source. It continues scanning until it reaches the
   * end of the file or encounters an error token. If an error token is encountered,
   * it will be included as the last token in the returned vector.
   *
   * @return A vector of Token objects representing all tokens in the source code.
   */
  std::vector<Token> tokenize();

private:
  std::string source_;
  size_t current_;
  size_t start_;
  int line_;
};

} // namespace lexer
} // namespace winplus::compiler