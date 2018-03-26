//
//  main.cpp
//  Class
//
//  Created by qiuyang.zhu on 2018/3/26.
//  Copyright © 2018年 qiuyang.zhu. All rights reserved.
//

#include <iostream>

class Log {
 public:
  const int LogLevelError = 0;
  const int LogLevelWarning = 1;
  const int LogLevelInfo = 2;

 private:
  int m_LogLevel;

 public:
  void SetLevel(int level) { m_LogLevel = level; }

  void Error(const char* message) {
    if (m_LogLevel >= LogLevelError)
      std::cout << "[Erroring]: " << message << std::endl;
  }
  void Warn(const char* message) {
    if (m_LogLevel >= LogLevelWarning)
      std::cout << "[Warning]: " << message << std::endl;
  }
  void Info(const char* message) {
    if (m_LogLevel >= LogLevelInfo)
      std::cout << "[Infoing]: " << message << std::endl;
  }
};

int main(int argc, const char* argv[]) {
  Log log;
  log.SetLevel(log.LogLevelError);
  log.Error("Hello");
  log.Warn("Hello");
  log.Info("Hello");

  return 0;
}
