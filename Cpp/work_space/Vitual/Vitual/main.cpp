//
//  main.cpp
//  Vitual
//
//  Created by qiuyang.zhu on 2018/3/27.
//  Copyright © 2018年 qiuyang.zhu. All rights reserved.
//

#include <iostream>

class Printable {
 public:
  virtual std::string GetClassName() = 0;
};

class Entity : public Printable {
 public:
  virtual std::string GetName() { return "Entity"; }
  std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity {
 private:
  std::string m_Name;

 public:
  Player(const std::string& name) : m_Name(name) {}

  std::string GetName() override { return m_Name; }
  std::string GetClassName() override { return "Player"; }
};

void Print(Printable* obj) { std::cout << obj->GetClassName() << std::endl; }

int main(int argc, const char* argv[]) {
  //    Entity* e = new Entity();
  //    std::cout << e->GetName() << std::endl;

  Player* p = new Player("Cherno");
  std::cout << p->GetName() << std::endl;

  Print(p);

  std::cin.get();
}
