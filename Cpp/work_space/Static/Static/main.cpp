//
//  main.cpp
//  Static
//
//  Created by qiuyang.zhu on 2018/3/28.
//  Copyright © 2018年 qiuyang.zhu. All rights reserved.
//

#include <iostream>

extern int s_Variable;

struct Entity {
  static int x, y;

  void Print() { std::cout << x << ", " << y << std::endl; }
};
int main(int argc, const char* argv[]) {
  Entity e;
  e.x = 2;
  e.y = 3;

  Entity e1;
  Entity::x = 5;
  Entity::y = 8;

  e.Print();
  e1.Print();

  // insert code here...
  std::cout << s_Variable << std::endl;
  return 0;
}
