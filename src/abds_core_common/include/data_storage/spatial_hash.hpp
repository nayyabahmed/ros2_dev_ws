#ifndef ABDS_CORE__SPATIAL_HASH
#define ABDS_CORE__SPATIAL_HASH

#include "types.hpp"
#include <unordered_map>
#include <functional>
#include <vector>
#include <bits/stdc++.h>
namespace abds_core
{
using abds_core::PointXYZ;

template<typename T>
class SpatialHash
{
public:
    using It = typename std::unordered_multimap<Index, T, IndexHash>::const_iterator;
    class Config
    {
    public:
        Config(
        const float min_x,
        const float max_x,
        const float min_y,
        const float max_y,
        const float min_z,
        const float max_z,
        const float cell_size,
        const float cell_height,
        const size_t capacity)
        : m_min_x(min_x),
        m_min_y(min_y),
        m_min_z(min_z),
        m_max_x(max_x),
        m_max_y(max_y),
        m_max_z(max_z),
        m_cell_size(cell_size),
        m_cell_height(cell_height),
        m_capacity(capacity)
        {
            if (cell_size <= 0.0F) 
            {
                throw std::domain_error("Error constructing SpatialHash: must have positive side length");
            }
            Index min_index = get_Index({min_x,min_y,min_z});
            Index max_index = get_Index({max_x,max_y,max_z});
            m_min_x_idx = min_index.x;
            m_min_y_idx = min_index.y;
            m_min_z_idx = min_index.z;
            m_max_x_idx = max_index.x;
            m_max_y_idx = max_index.y;
            m_max_z_idx = max_index.z;
        }
        size_t get_capacity() const
        {
            return m_capacity;
        }
        int32_t get_minX_idx() const
        {
            return m_min_x_idx;
        }
        int32_t get_minY_idx() const
        {
            return m_min_y_idx;
        }
        int32_t get_minZ_idx() const
        {
            return m_min_z_idx;
        }
        int32_t get_maxX_idx() const
        {
            return m_max_x_idx;
        }
        int32_t get_maxY_idx() const
        {
            return m_max_y_idx;
        }
        int32_t get_maxZ_idx() const
        {
            return m_max_z_idx;
        }
        float_t get_cell_size() const
        {
            return m_cell_size;
        }
        float_t get_cell_height() const
        {
            return m_cell_height;
        }

        Index get_Index(const PointXYZ p)
        {
            Index result;
            result.x = std::floor(p.x/m_cell_size);
            result.y = std::floor(p.y/m_cell_size);

            if(m_cell_height > 0)
            {
                result.z = std::floor(p.z/m_cell_height);
            }
            else 
            {
                result.z = 0;
            }    
            return result;
        }
        float_t distance_squared(PointXYZ p, PointXYZ p2)
        {
            const float_t dx = p.x - p2.x;
            const float_t dy = p.y - p2.y;
            const float_t dz = p.z - p2.z;
            return (dx * dx) + (dy * dy) + (dz * dz);
        }
    private:
        const float m_min_x;
        const float m_min_y;
        const float m_min_z;
        const float m_max_x;
        const float m_max_y;
        const float m_max_z;
        float m_min_x_idx;
        float m_min_y_idx;
        float m_min_z_idx;
        float m_max_x_idx;
        float m_max_y_idx;
        float m_max_z_idx;
        const float m_cell_size;
        const float m_cell_height;
        const size_t m_capacity;
    }; // class Config
    /// \brief insert data point into structure
    /// \param[in] _data the data point.
    /// \param[in] p the data position.
    size_t insert(T _data, PointXYZ p);
    /// \brief finds data at given position
    /// \param[in] point the position of the datapoint
    T* find(PointXYZ point);
    void clear();
    /// \brief execute function on elements in range
    /// \param[in] function function to iterate
    void iterate(const std::pair<Index,Index> & range, std::function<void(std::pair<It,It>)> function);
    void iterate(std::function<void(std::pair<It,It>)> function);
    /// \brief find adjacent cells'
    /// \param p point in original cell
    std::vector<It> find_neighbours(const PointXYZ p, std::function<float_t(const PointXYZ&)> calculate_threshold);
    std::pair<Index,Index> get_all();
    void erase(Index idx);
    void erase(It it);
    void erase(PointXYZ pt) { erase(get_Index(pt)); }
    
    Index get_Index(const PointXYZ p)
    {
        return m_config.get_Index(p);
    }
    size_t size() const
    {
        return m_hash.size();
    }
    size_t capacity() const
    {
        return m_config.get_capacity();
    }
    bool empty() const
    {
        return m_hash.empty();
    }
    It begin() const
    {
        return m_hash.begin();
    }
    It end() const
    {
        return m_hash.end();
    }
    It cbegin() const
    {
        return begin();
    }
    It cend() const
    {
        return end();
    }

    SpatialHash(Config config)
    : m_config(config),
    m_hash()
    {
        m_hash.reserve(config.get_capacity());
    }
private:
    std::pair<Index,Index> near(Index ref, float_t radius);
    std::unordered_multimap<Index, T, IndexHash> m_hash;
    Config m_config;
    std::vector<It> m_neighbours;
};
} // namespace abds_core
#endif // ABDS_CORE__SPATIAL_HASH