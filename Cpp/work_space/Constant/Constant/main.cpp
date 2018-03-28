//
//  main.cpp
//  Constant
//
//  Created by qiuyang.zhu on 2018/3/28.
//  Copyright © 2018年 qiuyang.zhu. All rights reserved.
//

#include <iostream>

int main(int argc, const char* argv[]) {
  const int MAX_AGE = 90;

  int* a = new int;
  *a = 2;
  a = (int*)&MAX_AGE;
  // insert code here...
  std::cout << *a << std::endl;
  return 0;
}
