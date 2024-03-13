#include <iostream>
#include "str.h"

int main(){
  str* alma = new str;
  *alma = "alma";
  std::cout << *alma << " at " << alma << std::endl;
  delete alma;

  str hello, world;
  hello += "hello";
  std::cout << hello << std::endl;

  world = " world";
  std::cout << hello + world << std::endl;
}
