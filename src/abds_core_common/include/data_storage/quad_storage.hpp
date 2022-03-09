#ifndef ABDS_CORE__QUAD_STORAGE
#define ABDS_CORE__QUAD_STORAGE

#include "types.hpp"
#include <functional>

namespace abds_core
{
template<typename DataT>
class Quad
{
public:
    /// \brief insert data point into structure
    /// \param[in] _data the data point. must have pos field
    void insert(DataT *_data);
    /// \brief finds datapoint at given position
    /// \param[in] point the position of the datapoint
    DataT* find(PointXY point);
    /// \brief check if position falls within quad
    /// \param[in] p the position to check
    bool isInBoundary(PointXY p);
    void clear();
    /// \brief execute function on all stored items
    /// \param[in] function function to iterate
    void iterate(std::function<void(DataT)> function);
    /// \brief find adjacent 8 Quads' data \n
    ///  0 1 2 \n 
    ///  3   4 \n 
    ///  5 6 7
    /// \param p point in original quad
    std::vector<DataT*> find_neighbours(PointXY p);
    Quad()
    {
        topLeft = PointXY(0, 0);
        botRight = PointXY(0, 0);
        data = NULL;
        topLeftTree  = NULL;
        topRightTree = NULL;
        botLeftTree  = NULL;
        botRightTree = NULL;
        min_width = 1;
    }
    Quad(PointXY topL, PointXY botR, float _min_width)
    {
        data = NULL;
        topLeftTree  = NULL;
        topRightTree = NULL;
        botLeftTree  = NULL;
        botRightTree = NULL;
        topLeft = topL;
        botRight = botR;
        min_width = _min_width;
    }
protected:
    PointXY topLeft;
    PointXY botRight;

    float min_width;

    DataT *data;
    Quad *topLeftTree;
    Quad *topRightTree;
    Quad *botLeftTree;
    Quad *botRightTree;
}; // class Quad
} // namespace abds_core

#endif // ABDS_CORE__QUAD_STORAGE