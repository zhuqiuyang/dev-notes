//
//  main.cpp
//  HelloWorld
//
//  Created by qiuyang.zhu on 2017/12/6.
//  Copyright © 2017年 qiuyang.zhu. All rights reserved.
//

#include <iostream>
#include "Log.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int a = 8;
    a++;

    const char* string = "Hello";

    for (int i = 0;i< 5;i++) {
        const char c = string[i];
        std::cout << c << std::endl;
    }
    Log("Hello World");
    std::cin.get();
    return 0;
}

