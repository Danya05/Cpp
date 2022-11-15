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

  String(const String& str): size(str.size), cap(str.cap), string_(new char[str.cap + 1]) {
    memcpy(string_, str.string_, size + 1);
  }

  String(size_t n, char c): size(n), cap(n), string_(new char[n + 1]) {
    memset(string_, c, size);
    string_[n] = '\0';
  }

  ~String() {
    delete[] string_;
  }

  char* front() {
    return &string_[0];
  }

  char* back() {
    return &string_[size - 1];
  }

  bool empty() {
    return size == 0;
  }

  void clear() {
    if (!empty()) {
      size = 0;
      delete[] string_;
      string_ = new char[1];
    }
  }

  String substr(size_t start, size_t count) {
    String st;
    st.size = count + 1;
    st.string_ = new char[st.size];
    for (size_t i = 0; i < count; ++i) {
      st.string_[i] = string_[start + i];
    }
    st.string_[count - 1] = '\0';
    return st;
  }

  static size_t length(const String& st) {
    return st.size;
  }

  char operator[](int val) {
    return string_[val];
  }

  /*void push_back(char c) {

  }

  char* back(String string) {
    return string[0];
  }*/

 private:
  size_t size = 0;
  size_t cap = 0;
  char* string_ = nullptr;
  //friend bool operator[](String& st);
  friend String operator+(String& st1, String& st2);
  friend String operator+=(String& st1, String& st2);
  friend bool operator==(const String& st1, const String& st2);
  friend bool operator>=(const String& st1, const String& st2);
  friend bool operator<=(const String& st1, const String& st2);
  friend bool operator>(const String& st1, const String& st2);
  friend bool operator<(const String& st1, const String& st2);
};

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
  return false;
}


//НЕ О(1)
String operator+=(String& st1, String& st2) {
  st1.size = st1.size + st2.size;
  st1.string_ = new char[st1.size + 1];
  strcpy(st1.string_, st1.string_);
  strcat(st1.string_, st2.string_);
  return st1;
}

String operator+(String& st1, String& st2) {
  String st3;
  st3.size = st1.size + st2.size;
  st3.string_ = new char[st3.size + 1];
  strcpy(st3.string_, st1.string_);
  strcat(st3.string_, st2.string_);
  return st3;
}

/*char& operator[](String& st, int i) {
  if (length(st) > i) {
    return 0;
  }
  return st.string_[i];
}*/

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
  char arg[6] = { "abcde" };
  String st(arg);
  String a(5, 'a');
  st.clear();
  std::cout << st.empty();
}
