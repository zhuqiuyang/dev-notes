//
//  main.cpp
//  Array
//
//  Created by qiuyang.zhu on 2018/3/28.
//  Copyright © 2018年 qiuyang.zhu. All rights reserved.
//

#include <iostream>
#include <array>

class Entity {
  int examples[5];
  int* examples1 = new int[5];

  Entity() {
    for (int i = 0; i < 5; i++) {
      examples[i] = 2;
    }
  }
};

int main(int argc, const char* argv[]) {
  int examples[5];
  int* ptr = examples;
  for (int i = 0; i < 5; i++) examples[i] = 2;
  examples[2] = 5;
  *(ptr + 2) = 6;

  int* another = new int[5];
  for (int i = 0; i < 5; i++) another[i] = 2;

  std::array<int, 5> arr;
  
  // insert code here...
  std::cout << examples[2] << std::endl;
  std::cout << examples << "\n" << sizeof(examples) << std::endl;
  std::cout << arr.size() << std::endl;
  return 0;
}
