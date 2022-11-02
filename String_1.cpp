#include <iostream>
#include <cstring>

class String {
 public:
  String(const char* arg) {
    size_t size = strlen(arg);
    string_ = new char[size + 1];
    for (size_t i = 0; i < size; ++i) {
      string_[i] = *(arg + i);
    }
    for (size_t j = 0; j < size; ++j) {
      std::cout << string_[j];
    }
  }
  String(int size, char c) {
    string_ = new char[size + 1];
    for (int i = 0; i < size; ++i) {
      string_[i] = c;
    }
  }
  char* string_;
};

int main() {
  char arg[6]{ "abcde" };
  String st(arg);
  String (5, 'a');
}
