#pragma once

#include <cmath>
#include <type_traits>

namespace g3d {
template <typename T>
struct Vector3 {
  T x{};
  T y{};
  T z{};

  /// Unary +
  constexpr Vector3 operator+() const { return *this; }

  /// Unary -
  constexpr Vector3 operator-() const { return {-x, -y, -z}; }

  /// Sum of vectors
  constexpr Vector3 operator+(const Vector3& v2) const {
    return {x + v2.x, y + v2.y, z + v2.z};
  }

  /// Subtraction of vectors
  constexpr Vector3 operator-(const Vector3& v2) const {
    return {x - v2.x, y - v2.y, z - v2.z};
  }

  /// Sum with a scalar
  constexpr Vector3 operator+(const T& s) const {
    return {x + s, y + s, z + s};
  }

  /// Subtracting a scalar
  constexpr Vector3 operator-(const T& s) const {
    return {x - s, y - s, z - s};
  }

  /// Scaling (multiplication)
  constexpr Vector3 operator*(const T& s) const {
    return {x * s, y * s, z * s};
  }

  friend inline constexpr Vector3 operator*(const T& s, const Vector3& v1) {
    return v1 * s;
  }

  /// Scaling (division)
  constexpr Vector3 operator/(const T& s) const {
    return {x / s, y / s, z / s};
  }
};

/// Deduction guide for CTAD
template <typename T1, typename T2, typename T3>
Vector3(const T1&, const T2&, const T3&)
    -> Vector3<std::common_type_t<T1, T2, T3>>;

/// Dot Product
template <typename T>
inline constexpr T dot(const Vector3<T>& v1, const Vector3<T>& v2) {
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

/// Cross Product
template <typename T>
inline constexpr Vector3<T> cross(const Vector3<T>& v1, const Vector3<T>& v2) {
  return {v1.y * v2.z - v1.z * v2.y,
          v1.z * v2.x - v1.x * v2.z,
          v1.x * v2.y - v1.y * v2.x};
}

/// Length squared
template <typename T>
inline constexpr T length_squared(const Vector3<T>& v) {
  //return v.x * v.x + v.y * v.y + v.z * v.z;
  return dot(v, v);
}

// Vector Length (norm)
template <typename T>
inline constexpr T length(const Vector3<T>& v) {
  return std::sqrt(length_squared(v));
}

// Normalize a vector
template <typename T>
inline constexpr auto normalize(const Vector3<T>& v) {
  auto l = length(v);
  return (l == 0) ? v : (v / l);
}

// Distance from two Vectors, as if they were points
template <typename T>
inline constexpr auto distance(const Vector3<T>& v1, const Vector3<T>& v2) {
  return length(v1 - v2);
}

}  // namespace g3d
