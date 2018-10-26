//
//  main.cpp
//  NameSpace
//
//  Created by qiuyang.zhu on 2018/3/23.
//  Copyright © 2018年 qiuyang.zhu. All rights reserved.
//

#include <iostream>
#include <string>

namespace apple {
void print(const std::string& text) { std::cout << text << std::endl; }
}  // namespace apple

namespace orange {
void print(const char* text) {
  std::string temp = text;
  std::reverse(temp.begin(), temp.end());
  std::cout << temp << std::endl;
}
}  // namespace orange

using namespace apple;
using namespace orange;

int main(int argc, const char* argv[]) {
  // insert code here...
  std::cout << "Hello, World!\n";

  print("Hello");
  return 0;
}
