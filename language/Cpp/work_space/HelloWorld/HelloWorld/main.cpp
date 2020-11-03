//
//  main.cpp
//  HelloWorld
//
//  Created by qiuyang.zhu on 2017/12/6.
//  Copyright © 2017年 qiuyang.zhu. All rights reserved.
//

 #include <iostream>
// #include "Log.h"

class Entity
{
public:
    virtual std::string GetName() {return "Entity";}
};

class Player : public Entity
{
private:
    std::string m_Name;
public:
    Player(const std::string& name)
    : m_Name(name) {}
    
    std::string GetName() { return m_Name; }
};

void PrintName(Entity* e) {
    std::cout << e->GetName() << std::endl;
}

int main(int argc, const char * argv[]) {
    Entity* e = new Entity();
    PrintName(e);
    
    Player* p = new Player("Cherno");
    PrintName(p);
    
    
//    std::cin.get();
}

