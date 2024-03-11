#include <cassert>
#include <cmath>
#include <sstream>

#include "quaternion.h"

const double EPS = 1e-4;

int main() {
  assert((-quaternion{1, 2, 3, 4} == quaternion{-1, -2, -3, -4}));
  assert((~quaternion{1, 2, 3, 4} == quaternion{1, -2, -3, -4}));
  assert((quaternion{1, 2, 3, 4}.abs() == sqrt(1 + 4 + 9 + 16)));
  assert((quaternion{1, 4, 4, -4}.norm() ==
          quaternion{1. / 7, 4. / 7, 4. / 7, -4. / 7}));

  assert((quaternion{1, 2, 3, 4} + quaternion{5, 6, 7, 8} ==
          quaternion{6, 8, 10, 12}));
  assert((quaternion{5, 6, 7, 8} - quaternion{4, 3, 2, 1} ==
          quaternion{1, 3, 5, 7}));

  assert((quaternion{2} * quaternion{0, 1, 2, 3} == quaternion{0, 2, 4, 6}));
  assert((quaternion{2} * quaternion{3} == quaternion{6}));
  assert((quaternion{0, 1, 2, 3} * quaternion{0, 4, 5, 6} ==
          quaternion{-(1 * 4 + 2 * 5 + 3 * 6), 2 * 6 - 3 * 5, 3 * 4 - 1 * 6,
                     1 * 5 - 2 * 4}));
  assert((quaternion{1, 2, 3, 4} * 2 == quaternion{2, 4, 6, 8}));

  assert((~(quaternion{1, 2, 3, 4} * quaternion{5, 6, 7, 8}) ==
          ~quaternion{5, 6, 7, 8} * ~quaternion{1, 2, 3, 4}));

  assert(((quaternion{1, 2, 3, 4} / quaternion{5, 6, 7, 8} *
               quaternion{5, 6, 7, 8} -
           quaternion{1, 2, 3, 4})
              .abs() < EPS));
  assert((quaternion{2, 4, 6, 8} / 2 == quaternion{1, 2, 3, 4}));

  std::istringstream test_input("-1.0 2.0 -3.0 4.0");
  quaternion test_q;
  test_input >> test_q;
  assert((test_q == quaternion{-1, 2, -3, 4}));

  std::ostringstream test_out;
  test_out << quaternion{5, -6, 7, -8};
  assert((test_out.str() == "5.000 - 6.000i + 7.000j - 8.000k"));

  std::cout << "Тесты пройдены\n";

  return 0;
}
