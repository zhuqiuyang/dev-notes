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

int Entity::x;
int Entity::y;

// Local Static
void Function() {
  static int i = 0;
  i++;
  std::cout << i << std::endl;
}

class Singleton {
 private:
  static Singleton* s_Instance;

 public:
  static Singleton& Get() { return *s_Instance; }
};

Singleton* Singleton::s_Instance = nullptr;

// or:

class Singleton_New {
 public:
  static Singleton& Get() {
    static Singleton instance;
    return instance;
  }
};

//Singleton* Singleton::s_Instance = nullptr;

// end Local static

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

  Function();
  Function();
  Function();
  Function();
  Function();
  return 0;
}
