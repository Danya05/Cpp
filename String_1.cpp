/*
* MIPT - STRING  2022*
*/

#include <iostream>
#include <cstring>

class String {
 public:
  String(): size_(0), cap(0), string_(new char[1]) {
    string_[0] = '\0';
  }

  String(size_t size, size_t cap): size_(size), cap(cap), string_(new char[cap + 1]) {}

  String(const char* arg): string_(new char[strlen(arg) + 1]) {
    size_ = strlen(arg);
    std::copy(arg, arg + size_ + 1, string_);
    cap = size_;
  }

  String(const String& str): size_(str.size_), cap(str.cap), string_(new char[str.cap + 1]) {
    memcpy(string_, str.string_, size_ + 1);
  }

  String(size_t n, char c): size_(n), cap(n), string_(new char[cap + 1]) {
    memset(string_, c, size_);
    string_[n] = '\0';
  }

  void UpdateCapRealloc() {
    if (size_ == 0){
      char* new_st = new char[2];
      delete[] string_;
      new_st[1] = '\0';
      string_ = new_st;
      //delete[] new_st;
      cap = 1;
      return;
    } else {
      char *new_st = new char[2 * cap + 1];
      strcpy(new_st, string_);
      cap *= 2;
      delete[] string_;
      string_ = new_st;
      //delete[] new_st;
    }
  }

  size_t find(const String& st) const{
    int flag = 1;
    for (size_t i = 0; i <= size_ - st.size_; ++i) {
      flag = 1;
      if (st.string_[0] == string_[i]) {
        for (size_t j = 1; j < st.size_; ++j) {
          if (st.string_[j] != string_[i + j]) {
            flag = 0;
            break;
          }
        }
        if (flag == 1) {
          return i;
        }
      }
    }
    return size_;
  }

  size_t rfind(const String& st) const{
    int flag = 1;
    int idx = size_;
    for (size_t i = 0; i <= size_ - st.size_; ++i) {
      flag = 1;
      if (st.string_[0] == string_[i]) {
        for (size_t j = 1; j < st.size_; ++j) {
          if (st.string_[j] != string_[i + j]) {
            flag = 0;
            break;
          }
        }
        if (flag == 1) {
          idx = i;
        }
      }
    }
    return idx;
  }

  char* data() {
    return &string_[0];
  }

  char* data() const{
    return &string_[0];
  }

  ~String() {
    delete[] string_;
  }

  char& front() {
    return string_[0];
  }

  const char& front() const {
    return string_[0];
  }

  char& back() {
    return string_[size_ - 1];
  }

  const char& back() const {
    return string_[size_ - 1];
  }

  void push_back(char c) {
    if (size_ == cap) {
      UpdateCapRealloc();
    }
    string_[size_] = c;
    string_[size_ + 1] = '\0';
    ++size_;
  }

  void pop_back() {
    string_[size_ - 1] = '\0';
    --size_;
  }

  bool empty() {
    return size_ == 0;
  }

  void clear() {
    string_[0] = '\0';
    size_ = 0;
  }

  String substr(size_t start, size_t count) {
    String st(count + 1, 2 * count);
    for (size_t i = 0; i < count; ++i) {
      st.string_[i] = string_[start + i];
    }
    st.string_[size_] = '\0';
    return st;
  }

  String substr(size_t start, size_t count) const {
    String st(count, 2 * count);
    std::copy(string_ + start, string_ + start + count + 1, st.string_);
    st.string_[st.size_] = '\0';
    return st;
  }

  size_t length() {
    return size_;
  }

  size_t length() const {
    return size_;
  }

  char& operator[](int val) {
    return string_[val];
  }

  const char& operator[](int val) const {
    return string_[val];
  }

  size_t size() {
    return size_;
  }

  size_t capacity() {
    return cap;
  }

  void shrink_to_fit() {
    char* st = new char[size_ + 1];
    memcpy(st, string_, size_ + 1);
    delete[] string_;
    string_ = st;
    cap = size_;
  }

  String& operator+=(char st2) {
    this -> push_back(st2);
    return *this;
  }

  String& operator+=(const String& st1) {
    char* st = new char[st1.size_ + size_ + 1];
    strcpy(st, string_);
    strcat(st, st1.string_);
    size_ += st1.size_;
    cap = size_;
    delete[] string_;
    string_ = st;
    return *this;
  }

  String& operator=(String s){
    std::swap(size_, s.size_);
    std::swap(cap, s.cap);
    std::swap(string_, s.string_);
    return *this;
  }

 private:
  size_t size_ = 0;
  size_t cap = 0;
  char* string_ = nullptr;
  friend String operator+(const String& st1, const String& st2);
  friend String operator+(char st1, const String& st2);
  friend String operator+(String st1, char st2);
  friend bool operator==(const String& st1, const String& st2);
  friend bool operator>=(const String& st1, const String& st2);
  friend bool operator<=(const String& st1, const String& st2);
  friend bool operator>(const String& st1, const String& st2);
  friend bool operator<(const String& st1, const String& st2);
  friend std::ostream& operator<<(std::ostream& os, const String& st);
  friend std::istream& operator>>(std::istream& in, String& st);
};

bool operator==(const String& st1, const String& st2) {
  if (st1.size_ != st2.size_) {
    return false;
  }
  for (size_t i = 0; i < st1.size_; ++i) {
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
  if (st1.size_ > st2.size_) {
    return true;
  }
  if (st1.size_ < st2.size_) {
    return false;
  }
  for (size_t i = 0; i < st1.size_; ++i) {
    if (st1.string_[i] > st2.string_[i]) {
      return true;
    }
    if (st1.string_[i] < st2.string_[i]) {
      return false;
    }
  }
  return false;
}


String operator+(const String& st1, const String& st2) {
  String st = String(st2.string_);
  st.size_ = st1.size_ + st2.size_;
  st.cap = st1.cap + st2.cap;
  strcpy(st.string_, st1.string_);
  strcat(st.string_, st2.string_);
  st.string_[st.size_] = '\0';
  return st;
}

String operator+(String st1, char st2) {
  String st = String(1, st2);
  st.size_ = st1.size_ + 1;
  st.string_ = new char[st1.size_ + 2];
  memcpy(st.string_, st1.string_, st1.size_);
  st.string_[st1.size_] = st2;
  st.string_[st1.size_ + 1] = '\0';
  return st;
}

String operator+(char st1, const String& st2) {
  String st3(1, st1);
  return (st3 += st2);
}

bool operator<=(const String& st1, const String& st2) {
  if (st1 == st2) {
    return true;
  }
  return st1 < st2;
}

bool operator<(const String& st1, const String& st2) {
  if (st1.size_ > st2.size_) {
    return false;
  }
  if (st1.size_ < st2.size_) {
    return true;
  }
  for (size_t i = 0; i < st1.size_; ++i) {
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

std::ostream& operator<<(std::ostream& os, const String& st) {
  return os << st.string_;
}

std::istream& operator>>(std::istream& in, String& st) {
  char array[1000000];
  in >> array;
  st.size_ = strlen(array);
  st.string_ = new char[st.size_ + 1];
  strcpy(st.string_, array);
  return in;
}
