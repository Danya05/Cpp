#include <iostream>
#include <cstring>

class String {
 public:
  String() = default;

  String(const char* arg): string_(new char[strlen(arg) + 1]) {
    size = strlen(arg);
    string_ = new char[size + 1];
    for (size_t i = 0; i < size; ++i) {
      string_[i] = *(arg + i);
    }
  }

  String(const String& str): string_(new char[str.cap + 1]), size(str.size), cap(str.cap) {
    memcpy(string_, str.string_, size + 1);
  }

  String(size_t n, char c): string_(new char[n + 1]), size(n), cap(n) {
    memset(string_, c, size);
    string_[n] = '\0';
  }

  ~String() {
    delete[] string_;
  }

  size_t length(const String& st) {
    return st.size;
  }
 private:
  size_t size = 0;
  size_t cap = 0;
  char* string_ = nullptr;
  friend bool operator==(const String& st1, const String& st2);
  friend bool operator>=(const String& st1, const String& st2);
  friend bool operator<=(const String& st1, const String& st2);
  friend bool operator>(const String& st1, const String& st2);
  friend bool operator<(const String& st1, const String& st2);
};

String operator+=(const String& st1, const String& st2);

bool operator==(const String& st1, const String& st2) {
  if (st1.size != st2.size) {
    return false;
  }
  for (size_t i = 0; i < st1.size; ++i) {
    if (st1.string_[i] != st2.string_[i]) {
      return false;
    }
  }
  return true;
}

bool operator>=(const String& st1, const String& st2) {
  if (st1 == st2) {
    return true;
  }
  return st1 > st2;
}

bool operator>(const String& st1, const String& st2) {
  if (st1.size > st2.size) {
    return true;
  }
  if (st1.size < st2.size) {
    return false;
  }
  for (size_t i = 0; i < st1.size; ++i) {
    if (st1.string_[i] > st2.string_[i]) {
      return true;
    }
    if (st1.string_[i] < st2.string_[i]) {
      return false;
    }
  }
  return true;
}

bool operator<=(const String& st1, const String& st2) {
  if (st1 == st2) {
    return true;
  }
  return st1 < st2;
}

bool operator<(const String& st1, const String& st2) {
  if (st1.size > st2.size) {
    return false;
  }
  if (st1.size < st2.size) {
    return true;
  }
  for (size_t i = 0; i < st1.size; ++i) {
    if (st1.string_[i] > st2.string_[i]) {
      return false;
    }
    if (st1.string_[i] < st2.string_[i]) {
      return true;
    }
  }
  return false;
}

bool operator!=(const String& st1, const String& st2) {
  return !(st1 == st2);
}



int main() {
  char arg[6]{ "abcde" };
  String st(arg);
  String a(5, 'a');
  String st1;
  st1 = a;
  a = a;
}
