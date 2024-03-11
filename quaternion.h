#pragma once

#include <iostream>

/**
 * \brief Класс, представляющий [кватернион](https://ru.wikipedia.org/wiki/%D0%9A%D0%B2%D0%B0%D1%82%D0%B5%D1%80%D0%BD%D0%B8%D0%BE%D0%BD)
 * в евклидовом пространстве.
 *
 * Используется внутреннее представление \f$a + b i + c j + d k\f$,
 * где \f$a,~b,~c,~d\f$ - вещественные коэффициенты; \f$i,~j,~k\f$ - мнимые единицы.
 */
class quaternion {
 public:
  explicit quaternion(double a = 0, double b = 0, double c = 0, double d = 0)
      : a(a), b(b), c(c), d(d) {}

  quaternion(const quaternion&) = default;

  quaternion(quaternion&&) = default;

  ~quaternion() = default;

  quaternion& operator=(const quaternion&) = default;

  //! \f$-q\f$: поэлементное отрицание.
  quaternion operator-() const;

  //! \f$\overline{q}\f$: взятие сопряжённого кватерниона.
  quaternion operator~() const;

  //! Модуль \f$|q| = \sqrt{a^2 + b^2 + c^2 + d^2}\f$
  double abs() const;

  //! Норма \f$q' = \frac{q}{|q|}; |q'| = 1\f$
  quaternion norm() const;

  //! Обратный кватернион \f$q^{-1} = \frac{\overline{q}}{|q|^2}\f$
  quaternion inverse() const;

  //! Поэлементная проверка на равенство.
  bool operator==(const quaternion& rhs) const noexcept;

  //! Поэлементная проверка на неравенство.
  bool operator!=(const quaternion& rhs) const noexcept;

  //! Поэлементная сумма.
  quaternion& operator+=(const quaternion& rhs) noexcept;

  //! Поэлементная сумма с \f$q = (\text{scalar}, 0, 0, 0)\f$
  quaternion& operator+=(double scalar) noexcept;

  //! Поэлементная разность.
  quaternion& operator-=(const quaternion& rhs) noexcept;

  //! Поэлементная разность с \f$q = (\text{scalar}, 0, 0, 0)\f$
  quaternion& operator-=(double scalar) noexcept;

  //! Произведение кватернионов.
  quaternion& operator*=(const quaternion& rhs) noexcept;

  //! Умножение на скаляр \f$q = (\text{scalar}, 0, 0, 0)\f$.
  quaternion& operator*=(double scalar) noexcept;

  //! Деление кватернионов (умножение на \f$\text{rhs}^{-1}\f$).
  quaternion& operator/=(const quaternion& rhs) noexcept;

  //! Деление на скаляр \f$q = (\text{scalar}, 0, 0, 0)\f$
  quaternion& operator/=(double scalar) noexcept;

  /** \brief Запись в поток вывода в формате \f$a + b i + c j + d k\f$.
   *
   * Вещественные коэффициенты \f$a, b, c, d\f$ округляются до 3 знаков.
   */
  std::ostream& writeTo(std::ostream& ostream) const;

  //! Чтение из потока ввода в формате `a b c d`
  std::istream& readFrom(std::istream& istream);

 private:
  double a{0};
  double b{0};
  double c{0};
  double d{0};
};

std::ostream& operator<<(std::ostream& ostream, const quaternion& rhs);

std::istream& operator>>(std::istream& istream, quaternion& rhs);

quaternion operator+(const quaternion& lhs, const quaternion& rhs);

quaternion operator+(const quaternion& lhs, double scalar);

quaternion operator+(double scalar, const quaternion& rhs);

quaternion operator-(const quaternion& lhs, const quaternion& rhs);

quaternion operator-(const quaternion& lhs, double scalar);

quaternion operator-(double scalar, const quaternion& rhs);

quaternion operator*(const quaternion& lhs, const quaternion& rhs);

quaternion operator*(const quaternion& lhs, double scalar);

quaternion operator*(double scalar, const quaternion& rhs);

quaternion operator/(const quaternion& lhs, const quaternion& rhs);

quaternion operator/(const quaternion& lhs, double scalar);

quaternion operator/(double scalar, const quaternion& rhs);
