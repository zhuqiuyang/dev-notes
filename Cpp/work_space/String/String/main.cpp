//
//  main.cpp
//  String
//
//  Created by qiuyang.zhu on 2018/3/27.
//  Copyright © 2018年 qiuyang.zhu. All rights reserved.
//

#include <iostream>
#include <string>

int main(int argc, const char* argv[]) {
  std::string names = "Ace";
    names+= " Hello ";
  std::cout << names << names.size() << std::endl;

  //   const char* name = "Ace";
  //   char name2[4] = {'A', 'c', 'e', 0};
  //   name = "asdf";
  //   std::cout << "Hello, World!\n" << name << std::endl;
  //   std::cout << "Hello, World!\n" << name2 << std::endl;
  return 0;
}
