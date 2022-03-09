#ifndef ABDS_CORE__TYPES_HPP_
#define ABDS_CORE__TYPES_HPP_

#include <limits>
#include <vector>
#include "calculations.hpp"

namespace abds_core
{
struct Index
{
    int32_t x;
    int32_t y;
    int32_t z;
    bool operator==(const Index& other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }
}; // struct Index

class IndexHash
{    
public:
    size_t operator()(const Index& i) const
    {
        return (std::hash<int32_t>()(i.x)) ^
               (std::hash<int32_t>()(i.y)) ^
               (std::hash<int32_t>()(i.z));
    }
}; // class IndexHash

struct PointXY
{
    float x;
    float y;
    PointXY(float _x, float _y)
    {
        x = _x;
        y = _y;
    }
    PointXY()
    {
        x = 0;
        y = 0;
    }
};

struct PointXYZ
{
  float x{0.0F};
  float y{0.0F};
  float z{0.0F};
};

struct PointXYZI
{
  float x{0.0F};
  float y{0.0F};
  float z{0.0F};
  float intensity{0.0F};
  operator PointXYZ() const {return PointXYZ{x,y,z};}
  bool operator==(
  const PointXYZI & p2) const noexcept
  {
    return
      isInLimit(
      x, p2.x, std::numeric_limits<float>::epsilon()) &&

      isInLimit(
      y, p2.y, std::numeric_limits<float>::epsilon()) &&

      isInLimit(
      z, p2.z, std::numeric_limits<float>::epsilon()) &&

      isInLimit(
      intensity, p2.intensity, std::numeric_limits<float>::epsilon());
  }
};

struct PointXYZIR
{
  PointXYZIR() = default;
  PointXYZIR(PointXYZ pt)
  : x(pt.x),
    y(pt.y),
    z(pt.z),
    r(std::sqrt((pt.x * pt.x) + (pt.y * pt.y)))
  {}
  PointXYZIR(PointXYZI pt)
  : x(pt.x),
    y(pt.y),
    z(pt.z),
    intensity(pt.intensity),
    r(std::sqrt((pt.x * pt.x) + (pt.y * pt.y)))
  {}
  float x{0.0F};
  float y{0.0F};
  float z{0.0F};
  float r{0.0F};
  float intensity{0.0F};
  operator PointXYZ() const {return PointXYZ{x,y,z};}
  operator PointXYZI() const {return PointXYZI{x,y,z,intensity};}
  const bool operator==(
  const PointXYZIR & p2) noexcept
  {
    return
      isInLimit(
      x, p2.x, std::numeric_limits<float>::epsilon()) &&

      isInLimit(
      y, p2.y, std::numeric_limits<float>::epsilon()) &&

      isInLimit(
      z, p2.z, std::numeric_limits<float>::epsilon()) &&

      isInLimit(
      r, p2.r, std::numeric_limits<float>::epsilon()) &&

      isInLimit(
      intensity, p2.intensity, std::numeric_limits<float>::epsilon());
  }
};

struct PointXYZIF
{
  float x{0.0F};
  float y{0.0F};
  float z{0.0F};
  float intensity{0.0F};
  short id{0};
  operator PointXYZ() const {return PointXYZ{x,y,z};}
  const bool operator==(
    const PointXYZIF & p2) noexcept
  {
    const auto epsilon = std::numeric_limits<float>::epsilon();
    return isInLimit(x, p2.x, epsilon) &&
            isInLimit(y, p2.y, epsilon) &&
            isInLimit(z, p2.z, epsilon) &&
            isInLimit(intensity, p2.intensity, epsilon) &&
            (id == p2.id);
  }
  static constexpr uint16_t END_OF_SCAN_ID = 65535u;
};

using PointBlock = std::vector<PointXYZI>;
using PointPtrBlock = std::vector<const PointXYZI *>;
/// \brief Stores basic configuration information, does some simple validity checking
static constexpr uint16_t POINT_BLOCK_CAPACITY = 12288U;

}  // namespace abds_core
#endif // CORE__TYPES_HPP_