#include "mylib.h"

void say(string message) { cout << message << endl; }
void say(vector<string> vec) {
  for (int c = 0; c < vec.size(); c++) {
    cout << vec[c] << endl;
  }
}