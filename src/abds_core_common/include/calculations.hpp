#ifndef ABDS_CORE__CALCULATIONS_HPP_
#define ABDS_CORE__CALCULATIONS_HPP_
#include <type_traits>
#include <cmath>
#include <stdexcept>

namespace abds_core
{
template<typename T>
const bool isInLimit(const T & target, const T & value, const T & limit)
{
  static_assert(
    std::is_floating_point<T>::value,
    "Float comparisons only support floating point types.");

  const auto delta = std::abs(target - value);
  const auto larger = std::max(std::abs(target), std::abs(value));
  const auto maxRelDelta = (larger * limit);
  return delta <= maxRelDelta;
}

template<typename T1, typename T2>
inline auto cross_2d(const T1 & pt, const T2 & q)
{
  return (pt.x * q.y) - (pt.y * q.x);
}

template<typename T1, typename T2>
inline auto dot_2d(const T1 & pt, const T2 & q)
{
  return (pt.x * q.x) + (pt.y * q.y);
}
template<typename T>
inline auto norm_2d(const T & pt)
{
  return sqrtf(static_cast<float_t>(dot_2d(pt, pt)));
}
template<typename T>
T times_2d(const T & p, const float_t a)
{
  T r;
  r.x = static_cast<float_t>(p.x) * a;
  r.y = static_cast<float_t>(p.y) * a;
  return r;
}
template<typename T>
T plus_2d(const T & p, const T & q)
{
  T r;
  r.x = p.x + q.x;
  r.y = p.y + q.y;
  return r;
}
template<typename T>
T minus_2d(const T & p, const T & q)
{
  T r;
  r.x = p.x - q.x;
  r.y = p.y - q.y;
  return r;
}
template<typename T>
inline T intersection_2d(const T & pt, const T & u, const T & q, const T & v)
{
  const float_t num = cross_2d(minus_2d(pt, q), u);
  float_t den = cross_2d(v, u);
  constexpr auto FEPS = std::numeric_limits<float_t>::epsilon();
  if (fabsf(den) < FEPS) {
    if (fabsf(num) < FEPS) {
      // collinear case, anything is ok
      den = 1.0F;
    } else {
      // parallel case, no valid output
      throw std::runtime_error(
              "intersection_2d: no unique solution (either collinear or parallel)");
    }
  }
  return plus_2d(q, times_2d(v, num / den));
}

static constexpr uint32_t  SECONDS_TO_NANOSECONDS = 1000000000;
} // namespace abds_core
#endif // CORE__CALCULATIONS_HPP_