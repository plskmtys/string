#include <cstring>
#include <iostream>
#include "str.h"

str::str(const char* t){
  len = std::strlen(t);
  text = new char[len+1];
  std::strcpy(text, t);
}

str::~str(){
  if(text != NULL) delete[] text;
}

str::str(const str& s){
  len = s.len;
  text = new char[len+1];
  std::strcpy(text, s.text);
}

str& str::operator=(const str& rhs){
  if(this == &rhs) return *this;
  if(text != NULL) delete[] text;
  len = rhs.len;
  text = new char[len+1];
  std::strcpy(text, rhs.text);
  return *this;
}

str& str::operator=(const char* rhs){
  if(text != NULL) delete[] text;
  len = std::strlen(rhs);
  text = new char[len+1];
  std::strcpy(text, rhs);
  return *this;
}

std::ostream& operator<<(std::ostream& os, const str& s){
  if(s.text != NULL) os << s.text;
  return os;
}

str& str::append(const char* s){
  len = len + std::strlen(s);
  char* newtext = new char[len+1];
  std::strcpy(newtext, text);
  std::strcat(newtext, s);
  newtext[len] = '\0';
  delete[] text;
  text = newtext;
  return *this;
}

str& str::append(const str& s){
  this->append(s.text);
  return *this;
}

str& str::append(const char c){
  char* newtext = new char[len+2];
  std::strcpy(newtext, text);
  newtext[len] = c;
  newtext[len+1] = '\0';
  delete[] text;
  text = newtext;
  return *this;
}

str& str::operator+(const str& s){
  this->append(s);
  return *this;
}

str& str::operator+(const char c){
  this->append(c);
  return *this;
}

str& str::operator+(const char* s){
  this->append(s);
  return *this;
}

str& str::operator+=(const char* s){
  *this = *this + s;
  return *this;
}

str& str::operator+=(const str& s){
  *this = *this + s;
  return *this;
}

str& str::operator+=(const char c){
  *this = *this + c;
  return *this;
}
/*
std::istream& operator>>(std::istream& is, const str& s){
  //read
  return is;
}
*/
