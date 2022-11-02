#include <iostream>

#include <cmath>

class C {
 public:
  C() : re(0), im(0) {}
  C(double re, double im): re(re), im(im) {}
  C(double re): re(re), im(0) {}
  C(const C& c) {
    re = c.re;
    im = c.im;
  }
  double re;
  double im;
  double abs(const C& c){
    return sqrt(c.im * c.im + c.re * c.re);
  }
 private:
  friend C operator+(const C& a, const C& b);
  friend C operator-(const C& a, const C& b);
  friend C operator*(const C& a, const C& b);
  friend C operator/(const C& a, const C& b);
  friend bool operator==(const C& a, const C& b);
  friend bool operator!=(const C& a, const C& b);
  friend std::ostream& operator<<(std::ostream& os, const C& a);
};

C operator+(const C& a, const C& b) {
  return C{a.re + b.re, a.im + b.im};
}

C operator-(const C& a, const C& b) {
  return C{a.re - b.re, a.im - b.im};
}

C operator*(const C& a, const C& b) {
  return C{a.re * b.re - a.im * b.im, a.re * b.im - b.re * a.im};
}

C operator/(const C& a, const C& b) {
  return C{(a.re * b.re + a.im * b.im) / (b.re * b.re + b.im * b.im),
                 (a.im * b.re - a.re * b.im) / (b.re * b.re + b.im * b.im)};
}

bool operator==(const C& a, const C& b) {
  return a.re == b.re and a.im == b.im;
}

bool operator!=(const C& a, const C& b) {
  return !(a == b);
}

std::ostream& operator<<(std::ostream& os, const C& a) {
  return os << a.re << ' ' << a.im;
}

int main() {
  C c{1, 2};
  std::cout << C::abs(const &c) << std::endl;
}
