#include <iostream>
//#include "memtrace.h"

class str{
private:
  char* text;
  size_t len;

public:
  str(): text(NULL), len(0){}

  str(const char* t);

  ~str();

  str(const str& s);

  str& operator=(const str& rhs);

  str& operator=(const char* rhs);

  friend std::ostream& operator<<(std::ostream& os, const str& s);

  str& append(const str& s);

  str& append(const char c);

  str& append(const char* s);

  str& operator+(const str& s);

  str& operator+(const char c);

  str& operator+(const char* s);

  str& operator+=(const char* s);

  str& operator+=(const str& s);

  str& operator+=(const char c);
  //friend std::istream& operator>>(std::istream& is, const str& s); 
};
