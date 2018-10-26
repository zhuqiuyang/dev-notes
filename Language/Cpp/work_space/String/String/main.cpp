//
//  main.cpp
//  String
//
//  Created by qiuyang.zhu on 2018/3/27.
//  Copyright © 2018年 qiuyang.zhu. All rights reserved.
//

#include <iostream>
#include <string>

// c lib
#include <stdlib.h>

int main(int argc, const char* argv[]) {
  const char name[8] = "Che\0rno";
  std::cout << strlen(name) << std::endl;

  char* name1 = "Ace";
  name1[2] = 'c';

  std::cout << *name1 << std::endl;

  const wchar_t* nama2 = L"Ace";
  // 2 byte
  const char16_t* name3 = u"Ace";
  // 4 byte
  const char32_t* name3 = U"Ace";

  // std
  using namespace std::string_literals;

  std::string name0 = std::string("Ace") + "Hello";
  // c14
  std::string name01 = "Ace"s + "Hello";

  const char* example = R"(Line1
  Line2
  ...)";
  const char* ex =
      "Line1\n"
      "Line2\n"
      "Line3";

  std::string names = "Ace";
  names += " Hello ";
  std::cout << names << names.size() << std::endl;

  //   const char* name = "Ace";
  //   char name2[4] = {'A', 'c', 'e', 0};
  //   name = "asdf";
  //   std::cout << "Hello, World!\n" << name << std::endl;
  //   std::cout << "Hello, World!\n" << name2 << std::endl;
  return 0;
}
