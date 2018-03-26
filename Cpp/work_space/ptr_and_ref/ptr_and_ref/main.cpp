//
//  main.cpp
//  ptr_and_ref
//
//  Created by qiuyang.zhu on 2018/3/26.
//  Copyright © 2018年 qiuyang.zhu. All rights reserved.
//

#include <iostream>

#define LOG(x) std::cout << x << std::endl

class Player {
 public:
  int x, y;
  int speed;

  void Move(int xa, int ya) {
    x += xa * speed;
    y += ya * speed;
  }
};

int main(int argc, const char* argv[]) {
  int a = 5;
  int& ref = a;
  ref = 2;

  Player player;
  player.x = 2;
  LOG(player.x);

  LOG(a);
  return 0;
}
