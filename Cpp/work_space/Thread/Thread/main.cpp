//
//  main.cpp
//  Thread
//
//  Created by qiuyang.zhu on 2018/3/29.
//  Copyright © 2018年 qiuyang.zhu. All rights reserved.
//

#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork() {
  using namespace std::literals::chrono_literals;
  static int i = 0;

  std::cout << "Thread id = " << std::this_thread::get_id() << std::endl;

  while (!s_Finished) {
    i++;
    std::cout << i << " Working...\n";
    std::this_thread::sleep_for(1s);
  }
}

int main(int argc, const char* argv[]) {
  std::thread worker(DoWork);

  std::cin.get();
  s_Finished = true;

  worker.join();

  // insert code here...
  std::cout << "Thread id = " << std::this_thread::get_id() << std::endl;
  std::cout << "Hello, World!\n";
  return 0;
}
