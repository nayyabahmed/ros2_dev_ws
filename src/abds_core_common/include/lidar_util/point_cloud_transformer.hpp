#ifndef ABDS_CORE__POINT_CLOUD_TRANSFORMER
#define ABDS_CORE__POINT_CLOUD_TRANSFORMER

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>
#include <mutex>

namespace abds_core
{
namespace lidar_util
{
class PointCloudTransformer
{
public:
    void setTransform(const Eigen::Affine3f & tf)
    {
        std::lock_guard<std::mutex> guard(transform_mutex);
        m_transform = tf;
    }
    template<typename PointT>
    void transform(const PointT & in, PointT & out) const
    {
        // we don't want transform to change while we apply it.
        std::lock_guard<std::mutex> guard(transform_mutex);
        Eigen::Vector3f out_vec = m_transform * Eigen::Vector3f{in.x, in.y, in.z};
        out.x = out_vec[0];
        out.y = out_vec[1];
        out.z = out_vec[2];
    }
private:
    mutable std::mutex transform_mutex;
    Eigen::Affine3f m_transform;
};
}
} // namespace abds_core
#endif // ABDS_CORE__POINT_CLOUD_TRANSFORMER