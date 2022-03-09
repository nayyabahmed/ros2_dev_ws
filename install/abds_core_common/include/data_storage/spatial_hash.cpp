#include "spatial_hash.hpp"
namespace abds_core
{
template<typename T>
void SpatialHash<T>::clear()
{
    m_hash.clear();
}
bool next_bin(const std::pair<Index,Index> & range, Index & idx)
{
    bool ret = true;
    ++idx.x;
    if (idx.x > range.second.x) {
        idx.x = range.first.x;
        ++idx.y;
        if (idx.y > range.second.y) {
            idx.y = range.first.y;
            ++idx.z;
            if (idx.z > range.second.z) {
                ret = false;
            }
        }
    }
    return ret;
}
template<typename T>
void SpatialHash<T>::iterate(const std::pair<Index,Index> & range, std::function<void(std::pair<It,It>)> function)
{    
    Index idx = range.first;
    do {
        auto points = m_hash.equal_range(idx);
        function(points);
    } while (next_bin(range, idx));
}

template<typename T>
void SpatialHash<T>::iterate(std::function<void(std::pair<It,It>)> function)
{    
    It it = m_hash.begin();
    while (it != m_hash.end())
    {
        Index key = it->first;
        auto points = m_hash.equal_range(key);
        function(points);
        it = points.second;
    }    
}

template<typename T>
size_t SpatialHash<T>::insert(T _data, PointXYZ p)
{
    if(m_hash.size() >= m_config.get_capacity())
    {              
        throw std::runtime_error("SpatialHash: Hash capacity(" + std::to_string(m_config.get_capacity()) + ") overrun! Consider using smaller Hashes.");
    }
    auto index = get_Index(p);
    auto found = m_hash.equal_range(index);
    auto dist = std::distance(found.first, found.second);
    
    m_hash.insert(std::make_pair(index, _data));
    return dist + 1;
}

template<typename T>
std::pair<Index,Index> SpatialHash<T>::near(Index ref, float_t radius)
{
    const int32_t iradius = static_cast<int32_t>(std::ceil(radius / m_config.get_cell_size()));
    const int32_t xmin = std::max(ref.x - iradius, m_config.get_minX_idx());
    const int32_t ymin = std::max(ref.y - iradius, m_config.get_minY_idx());
    const int32_t zmin = std::max(ref.z - iradius, m_config.get_minZ_idx());
    const int32_t xmax = std::min(ref.x + iradius, m_config.get_maxX_idx());
    const int32_t ymax = std::min(ref.y + iradius, m_config.get_maxY_idx());
    const int32_t zmax = std::min(ref.z + iradius, m_config.get_maxZ_idx());
    // return bottom-left portion of cube and top-right portion of cube
    return {{xmin, ymin, zmin}, {xmax, ymax, zmax}};
}

template<typename T>
std::vector<typename SpatialHash<T>::It> SpatialHash<T>::find_neighbours(const PointXYZ p, std::function<float_t(const PointXYZ&)>  calculate_threshold)
{
    m_neighbours.clear();
    auto idx = get_Index(p);
    float_t radius = calculate_threshold(p);
    float_t radius2 = radius * radius;    
    auto bins = near(idx,radius);
    Index jdx = bins.first;
    do
    {
        // TODO: check if neighbour can actually have points in it?
        const auto range = m_hash.equal_range(jdx);
        for (auto it = range.first; it != range.second; ++it) 
        {            
          const auto pt = static_cast<PointXYZ>(it->second);
          // check that threshold is satisfied both ways
          float_t inv_radius = calculate_threshold(pt);
          float_t inv_radius2 = inv_radius * inv_radius;   
          const float_t dist2 = m_config.distance_squared(p, pt);
          if (dist2 <= radius2 && dist2 <= inv_radius2) {
            m_neighbours.push_back(it);
          }
        }

    } while (next_bin(bins, jdx));    
    return m_neighbours;
}

template<typename T>
void SpatialHash<T>::erase(Index idx)
{
    m_hash.erase(idx);
}

template<typename T>
void SpatialHash<T>::erase(It it)
{
    if (end() == m_hash.find(it->first)) {
      throw std::domain_error{"SpatialHash: Attempting to erase invalid iterator"};
    }
    m_hash.erase(it);
}
template<typename T>
std::pair<Index,Index> SpatialHash<T>::get_all()
{
    return {
        {
          m_config.get_minX_idx(),
          m_config.get_minY_idx(),
          m_config.get_minZ_idx()
        },
        {
          m_config.get_maxX_idx(),
          m_config.get_maxY_idx(),
          m_config.get_maxZ_idx()
        }};
}

} // namespace abds_core