#include <iostream>
#include <cstring>

class String {
 public:
  String() = default;

  String(const char* arg): string_(new char[strlen(arg) + 1]) {
    size_ = strlen(arg);
    string_ = new char[size_ + 1];
    for (size_t i = 0; i < size_; ++i) {
      string_[i] = *(arg + i);
    }
    string_[size_] = '\0';
    cap = 2 * size_;
  }

  String(const String& str): size_(str.size_), cap(str.cap), string_(new char[str.cap + 1]) {
    memcpy(string_, str.string_, size_ + 1);
  }

  String(size_t n, char c): size_(n), cap(n), string_(new char[n + 1]) {
    memset(string_, c, size_);
    string_[n] = '\0';
  }

  size_t find(const String& st) {
    char* result = new char[st.size_ + 1];
    for (size_t i = 0; i < size_ - st.size_; ++i) {
      memcpy(result, string_ + i, st.size_);
      result[size_] = '\0';
      if (String(result) == st) {
        return i;
      }
    }
    return size_;
  }

  size_t find(const String& st) const{
    char* result = new char[st.size_ + 1];
    for (size_t i = 0; i < size_ - st.size_; ++i) {
      memcpy(result, string_ + i, st.size_);
      result[size_] = '\0';
      if (String(result) == st) {
        return i;
      }
    }
    return size_;
  }

  size_t rfind(const String& st) {
    char* result = new char[st.size_ + 1];
    for (size_t i = size_ - st.size_; i > 0; --i) {
      memcpy(result, string_ + i, st.size_);
      result[size_] = '\0';
      if (String(result) == st) {
        return i;
      }
    }
    return size_;
  }

  size_t rfind(const String& st) const{
    char* result = new char[st.size_ + 1];
    for (size_t i = size_ - st.size_; i > 0; --i) {
      memcpy(result, string_ + i, st.size_);
      result[size_] = '\0';
      if (String(result) == st) {
        return i;
      }
    }
    return size_;
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
    string_[size_] = c;
    ++size_;
  }

  void pop_back() {
    string_[size_] = '\0';
    --size_;
  }

  bool empty() {
    return size_ == 0;
  }

  void clear() {
    if (!empty()) {
      size_ = 0;
      delete[] string_;
      string_ = new char[1];
    }
  }

  String substr(size_t start, size_t count) {
    String st;
    st.size_ = count + 1;
    st.string_ = new char[st.size_];
    for (size_t i = 0; i < count; ++i) {
      st.string_[i] = string_[start + i];
    }
    st.string_[count - 1] = '\0';
    st.cap = st.size_;
    return st;
  }

  String substr(size_t start, size_t count) const {
    String st;
    st.size_ = count + 1;
    st.string_ = new char[st.size_];
    for (size_t i = 0; i < count; ++i) {
      st.string_[i] = string_[start + i];
    }
    st.string_[count - 1] = '\0';
    st.cap = st.size_;
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
    clear();
  }

  String& operator+=(char st2);
  String& operator+=(const String& st1);

 private:
  size_t size_ = 0;
  size_t cap = 0;
  char* string_ = nullptr;
  friend String operator+(const String& st1, const String& st2);
  friend String operator+(char st1, const String& st2);
  friend String operator+(const String& st1, char st2);
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


//НЕ О(1)
String& String::operator+=(const String& st1) {
  *this = *this + st1;
  return *this;
}

String& String::operator+=(char st2) {
  this -> push_back(st2);
  return *this;
}

String operator+(const String& st1, const String& st2) {
  String st3;
  st3.size_ = st1.size_ + st2.size_;
  st3.string_ = new char[st3.size_];
  st3.cap = st1.cap + st2.cap;
  strcpy(st3.string_, st1.string_);
  strcat(st3.string_, st2.string_);
  return st3;
}

String operator+(char st1, const String& st2) {
  String st3;
  st3.size_ = 1 + st2.size_;
  st3.string_ = new char[st3.size_ + 1];
  st3[0] = st1;
  strcpy(st3.string_, st2.string_);
  return st3;
}

String operator+(const String& st1, char st2) {
  String st3;
  st3.size_ = 1 + st1.size_;
  st3.string_ = new char[st3.size_ + 1];
  st3[0] = st2;
  strcpy(st3.string_, st1.string_);
  return st3;
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
  char array[1000];
  in >> array;
  st.size_ = strlen(array);
  st.string_ = new char[st.size_ + 1];
  strcpy(st.string_, array);
  return in;
}
