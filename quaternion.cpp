#include "quaternion.h"
#include <cmath>
#include <iomanip>

quaternion quaternion::operator-() const {
  return quaternion{-a, -b, -c, -d};
}

quaternion quaternion::operator~() const {
  return quaternion{a, -b, -c, -d};
}

double quaternion::abs() const {
  return sqrt(a * a + b * b + c * c + d * d);
}

quaternion quaternion::norm() const {
  return *this / abs();
}

quaternion quaternion::inverse() const {
  return ~(*this) * (1 / (abs() * abs()));
}

bool quaternion::operator==(const quaternion& rhs) const noexcept {
  return (a == rhs.a && b == rhs.b && c == rhs.c && d == rhs.d);
}

bool quaternion::operator!=(const quaternion& rhs) const noexcept {
  return !operator==(rhs);
}

quaternion& quaternion::operator+=(const quaternion& rhs) noexcept {
  a += rhs.a;
  b += rhs.b;
  c += rhs.c;
  d += rhs.d;
  return *this;
}

quaternion& quaternion::operator+=(const double scalar) noexcept {
  return operator+=(quaternion(scalar));
}

quaternion& quaternion::operator-=(const quaternion& rhs) noexcept {
  a -= rhs.a;
  b -= rhs.b;
  c -= rhs.c;
  d -= rhs.d;
  return *this;
}

quaternion& quaternion::operator-=(const double scalar) noexcept {
  return operator-=(quaternion(scalar));
}

quaternion& quaternion::operator*=(const quaternion& rhs) noexcept {
  return *this = quaternion{a * rhs.a - b * rhs.b - c * rhs.c - d * rhs.d,
                            a * rhs.b + rhs.a * b + c * rhs.d - rhs.c * d,
                            a * rhs.c + rhs.a * c + d * rhs.b - rhs.d * b,
                            a * rhs.d + rhs.a * d + b * rhs.c - rhs.b * c};
}

quaternion& quaternion::operator*=(const double scalar) noexcept {
  return operator*=(quaternion(scalar));
}

quaternion& quaternion::operator/=(const quaternion& rhs) noexcept {
  return operator*=(rhs.inverse());
}

quaternion& quaternion::operator/=(const double scalar) noexcept {
  return operator/=(quaternion(scalar));
}

std::ostream& quaternion::writeTo(std::ostream& ostream) const {
  ostream << std::fixed << std::setprecision(3);
  return ostream << a << (b >= 0 ? " + " : " - ") << std::abs(b) << "i"
                 << (c >= 0 ? " + " : " - ") << std::abs(c) << "j"
                 << (d >= 0 ? " + " : " - ") << std::abs(d) << "k";
}

std::istream& quaternion::readFrom(std::istream& istream) {
  return istream >> a >> b >> c >> d;
}

std::ostream& operator<<(std::ostream& ostream, const quaternion& rhs) {
  return rhs.writeTo(ostream);
}

std::istream& operator>>(std::istream& istream, quaternion& rhs) {
  return rhs.readFrom(istream);
}

quaternion operator+(const quaternion& lhs, const quaternion& rhs) {
  quaternion out(lhs);
  out += rhs;
  return out;
}

quaternion operator+(const quaternion& lhs, const double scalar) {
  quaternion out(lhs);
  quaternion tmp(scalar);
  return out += tmp;
}

quaternion operator+(const double scalar, const quaternion& rhs) {
  quaternion out(scalar);
  quaternion tmp(rhs);
  return out += tmp;
}

quaternion operator-(const quaternion& lhs, const quaternion& rhs) {
  quaternion out(lhs);
  out -= rhs;
  return out;
}

quaternion operator-(const quaternion& lhs, const double scalar) {
  quaternion out(lhs);
  quaternion tmp(scalar);
  return out -= tmp;
}

quaternion operator-(const double scalar, const quaternion& rhs) {
  quaternion out(scalar);
  quaternion tmp(rhs);
  return out -= tmp;
}

quaternion operator*(const quaternion& lhs, const quaternion& rhs) {
  quaternion out(lhs);
  out *= rhs;
  return out;
}

quaternion operator*(const quaternion& lhs, const double scalar) {
  quaternion out(lhs);
  quaternion tmp(scalar);
  return out *= tmp;
}

quaternion operator*(const double scalar, const quaternion& rhs) {
  quaternion out(scalar);
  quaternion tmp(rhs);
  return out *= tmp;
}

quaternion operator/(const quaternion& lhs, const quaternion& rhs) {
  quaternion out(lhs);
  out /= rhs;
  return out;
}

quaternion operator/(const quaternion& lhs, const double scalar) {
  quaternion out(lhs);
  quaternion tmp(scalar);
  return out /= tmp;
}

quaternion operator/(const double scalar, const quaternion& rhs) {
  quaternion out(scalar);
  quaternion tmp(rhs);
  return out /= tmp;
}
