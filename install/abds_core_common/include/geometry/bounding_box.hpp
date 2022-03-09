#ifndef ABDS_CORE__BOUNDING_BOX
#define ABDS_CORE__BOUNDING_BOX
#include "types.hpp"
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>
#include <vector>
#include <iostream>
#include <abds_core_common/msg/bounding_boxes.hpp>
namespace abds_core
{
// Templated alias for stripping reference qualifiers
template<typename T>
using base_type = typename std::remove_cv<typename std::remove_reference<T>::type>::type;
using Point32 =
  geometry_msgs::msg::Point32_<std::allocator<void>>;
using abds_core_common::msg::BoundingBox;
using abds_core_common::msg::BoundingBoxes;

struct Covariance2d
{
  float_t xx;
  float_t yy;
  float_t xy;
  std::size_t num_points;
};  // struct Covariance2d
template<typename IT>
Covariance2d covariance_2d(const IT begin, const IT end)
{
  Covariance2d ret{0.0F, 0.0F, 0.0F, 0U};
  float_t ux = 0.0F;
  float_t uy = 0.0F;
  float_t num_points = 0.0F;
  for (auto it = begin; it != end; ++it) {
    ++ret.num_points;
    num_points = static_cast<float_t>(ret.num_points);
    const auto & pt = *it;
    // update mean x
    const float_t dx = pt.x - ux;
    ux = ux + (dx / num_points);
    // update cov
    const float_t dy = pt.y - uy;
    ret.xy += (pt.x - ux) * (dy);
    // update mean y
    uy = uy + (dy / num_points);
    // update M2
    ret.xx += dx * (pt.x - ux);
    ret.yy += dy * (pt.y - uy);
  }
  // finalize sample (co-)variance
  if (ret.num_points > 1U) {
    num_points = num_points - 1.0F;
  }
  ret.xx /= num_points;
  ret.yy /= num_points;
  ret.xy /= num_points;

  return ret;
}
template<typename IT, typename PointT>
void compute_corners(
  decltype(BoundingBox::corners) & corners,
  const std::array<IT,4U> & supports,
  const std::array<PointT,4U> & directions)
{
  for (uint8_t idx = 0U; idx < corners.size(); ++idx) {
    const uint8_t jdx = (idx != 3U) ? (idx + 1U) : 0U;
    const auto pt =
      intersection_2d(*supports[idx], directions[idx], *supports[jdx], directions[jdx]);
    corners[idx].x = pt.x;
    corners[idx].y = pt.y;
  }
}
template<typename IT>
void compute_height(const IT begin, const IT end, BoundingBox & box)
{
  float_t max_z = -std::numeric_limits<float_t>::max();
  float_t min_z = std::numeric_limits<float_t>::max();
  for (auto it = begin; it != end; ++it) {
    const float_t z = it->z;
    if (z <= min_z) {
      min_z = z;
    }
    if (z >= max_z) {
      max_z = z;
    }
  }
  box.centroid.z = (max_z + min_z) * 0.5F;
  for (auto & corner : box.corners) {
    corner.z = box.centroid.z;
  }
  box.size.z = (max_z - min_z);
};

template<typename PointT>
std::pair<float_t, float_t> eigen_2d(
  const Covariance2d & cov, PointT & eigvec1, PointT & eigvec2)
{
  const float_t tr_2 = (cov.xx + cov.yy) * 0.5F;
  const float_t det = (cov.xx * cov.yy) - (cov.xy * cov.xy);
  // Add a small fudge to alleviate floating point errors
  float_t disc = ((tr_2 * tr_2) - det) + std::numeric_limits<float_t>::epsilon();
  if (disc < 0.0F) {
    throw std::runtime_error(
            "pca_2d: negative discriminant! Should never happen for well formed "
            "covariance matrix");
  }
  disc = std::sqrt(disc);
  // compute eigenvalues
  const auto ret = std::make_pair(tr_2 + disc, tr_2 - disc);
  if (fabsf(cov.xy * cov.xy) > std::numeric_limits<float_t>::epsilon()) {
    eigvec1.x = cov.xy;
    eigvec1.y = ret.first - cov.xx;
    eigvec2.x = cov.xy;
    eigvec2.y = ret.second - cov.xx;
  } else {
    if (cov.xx > cov.yy) {
      eigvec1.x = 1.0F;
      eigvec1.y = 0.0F;
      eigvec2.x = 0.0F;
      eigvec2.y = 1.0F;
    } else {
      eigvec1.x = 0.0F;
      eigvec1.y = 1.0F;
      eigvec2.x = 1.0F;
      eigvec2.y = 0.0F;
    }
  }
  return ret;
}

template<typename IT, typename PointT>
bool compute_supports(
  const IT begin,
  const IT end,
  const PointT & eig1,
  const PointT & eig2,
  std::array<IT,4U> & support)
{
  const bool ret = cross_2d(eig1, eig2) >= 0.0F;
  std::array<float_t, 4U> metrics{{
    -std::numeric_limits<float_t>::max(),
    -std::numeric_limits<float_t>::max(),
    std::numeric_limits<float_t>::max(),
    std::numeric_limits<float_t>::max()
  }};
  for (auto it = begin; it != end; ++it) {
    const PointT & pt = *it;
    float_t val = dot_2d(ret ? eig1 : eig2, pt);
    if (val > metrics[0U]) {
      metrics[0U] = val;
      support[0U] = it;
    }
    if (val < metrics[2U]) {
      metrics[2U] = val;
      support[2U] = it;
    }
    val = dot_2d(ret ? eig2 : eig1, pt);
    if (val > metrics[1U]) {
      metrics[1U] = val;
      support[1U] = it;
    }
    if (val < metrics[3U]) {
      metrics[3U] = val;
      support[3U] = it;
    }
  }
  return ret;
}
void finalise_box(const decltype(BoundingBox::corners) & corners, BoundingBox & box)
{
  (void)std::copy(&corners[0U], &corners[corners.size()], &box.corners[0U]);
  // orientation: this is robust to lines
  const float_t yaw_rad_2 =
    atan2f(box.corners[2U].y - box.corners[1U].y, box.corners[2U].x - box.corners[1U].x) * 0.5F;
  box.orientation.x = 0;
  box.orientation.y = 0;
  box.orientation.z = sinf(yaw_rad_2);
  box.orientation.w = cosf(yaw_rad_2);
  box.centroid = times_2d(plus_2d(corners[0U], corners[2U]), 0.5F);
}

template<typename IT, typename PointT>
void size_2d(
  const std::array<IT,4U> & corners,
  PointT & ret)
{
  ret.x = std::max(
    norm_2d(
      minus_2d(
        corners[1U],
        corners[0U])), std::numeric_limits<float_t>::epsilon());
  ret.y = std::max(
    norm_2d(
      minus_2d(
        corners[2U],
        corners[1U])), std::numeric_limits<float_t>::epsilon());
}

template<typename IT, typename PointT>
BoundingBox compute_bounding_box(
  const PointT & ax1,
  const PointT & ax2,
  const std::array<IT,4U> & supports)
{
  decltype(BoundingBox::corners) corners;
  const std::array<PointT,4U> directions{{ax1, ax2, times_2d(ax1, -1.0), times_2d(ax2,-1.0)}};
  compute_corners(corners, supports, directions);

  // build box
  BoundingBox bbox;
  finalise_box(corners, bbox);
  size_2d(corners, bbox.size);
  return bbox;
}

template<typename IT>
BoundingBox eigenbox_2d(const IT begin, const IT end)
{
  // compute covariance
  const Covariance2d cov = covariance_2d(begin, end);

  // compute eigenvectors
  using PointT = base_type<decltype(*begin)>;
  PointT eig1;
  PointT eig2;
  const auto eigv = eigen_2d(cov, eig1, eig2);

  // find extreme points
  std::array<IT,4U> supports;
  const bool is_ccw = compute_supports(begin, end, eig1, eig2, supports);
  // build box
  if (is_ccw) {
    std::swap(eig1, eig2);
  }
  BoundingBox bbox = compute_bounding_box(eig1, eig2, supports);

  return bbox;
}
template<typename PointT>
std::vector<BoundingBox> compute_bounding_boxes(
  std::vector<std::vector<PointT>> & clusters,
  bool should_get_height)
{
  std::vector<BoundingBox> boxes;
  for (auto cluster : clusters) {
    try {
      boxes.push_back(eigenbox_2d(cluster.begin(),cluster.end()));
      if (should_get_height) {
        compute_height(
          cluster.begin(),cluster.end(), boxes.back());
      }
    } catch (const std::exception & e) {
      std::cerr << e.what() << std::endl;
    }
  }
  return boxes;
}
} // namespace abds_core
#endif // ABDS_CORE__BOUNDING_BOX