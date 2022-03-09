#include "quad_storage.hpp"

namespace abds_core
{
template<typename T>
void Quad<T>::clear()
{
    if (data != NULL)
    {
        delete data;
        data = NULL;
    }
    if (topLeftTree != NULL)
    {
        topLeftTree->clear();
        delete topLeftTree;
        topLeftTree = NULL;
    }
    if (topRightTree != NULL)
    {
        topRightTree->clear();
        delete topRightTree;
        topRightTree = NULL;
    }
    if (botLeftTree != NULL)
    {
        botLeftTree->clear();
        delete botLeftTree;
        botLeftTree = NULL;
    }
    if (botRightTree != NULL)
    {
        botRightTree->clear();
        delete botRightTree;
        botRightTree = NULL;
    }
}

template<typename T>
void Quad<T>::iterate(std::function<void(T)> function)
{
    if(data != NULL){function(*data);}
    if(topLeftTree != NULL){topLeftTree->iterate(function);}
    if(topRightTree != NULL){topRightTree->iterate(function);}
    if(botLeftTree != NULL){botLeftTree->iterate(function);}
    if(botRightTree != NULL){botRightTree->iterate(function);}
}

template<typename T>
void Quad<T>::insert(T *_data)
{
    if (_data == NULL)
    {
        return;
    }
    // Current quad cannot contain it
    if (!isInBoundary(_data->pos))
    {
        return;
    }
    // We are at a quad of min size
    // We cannot subdivide this quad further
    float w = fabs(topLeft.x - botRight.x);
    float l = fabs(topLeft.y - botRight.y);

    if (w <= min_width ||
        l <= min_width)
    {
        data = _data;
        return;
    }
  
    if ((topLeft.x + botRight.x) / 2 >= _data->pos.x)
    {
        // Indicates topLeftTree
        if ((topLeft.y + botRight.y) / 2 <= _data->pos.y)
        {
            if (topLeftTree == NULL)
                topLeftTree = new Quad(
                    PointXY(topLeft.x, topLeft.y),
                    PointXY((topLeft.x + botRight.x) / 2,
                        (topLeft.y + botRight.y) / 2),
                    min_width);
            topLeftTree->insert(_data);
        }
  
        // Indicates botLeftTree
        else
        {
            if (botLeftTree == NULL)
                botLeftTree = new Quad(
                    PointXY(topLeft.x,
                        (topLeft.y + botRight.y) / 2),
                    PointXY((topLeft.x + botRight.x) / 2,
                        botRight.y),
                    min_width);
            botLeftTree->insert(_data);
        }
    }
    else
    {
        // Indicates topRightTree
        if ((topLeft.y + botRight.y) / 2 <= _data->pos.y)
        {
            if (topRightTree == NULL)
                topRightTree = new Quad(
                    PointXY((topLeft.x + botRight.x) / 2,
                        topLeft.y),
                    PointXY(botRight.x,
                        (topLeft.y + botRight.y) / 2),
                    min_width);
            topRightTree->insert(_data);
        }
  
        // Indicates botRightTree
        else
        {
            if (botRightTree == NULL)
                botRightTree = new Quad(
                    PointXY((topLeft.x + botRight.x) / 2,
                        (topLeft.y + botRight.y) / 2),
                    PointXY(botRight.x, botRight.y),
                    min_width);
            botRightTree->insert(_data);
        }
    }
}

template<typename T>
T* Quad<T>::find(PointXY p)
{
    // Current quad cannot contain it
    if (!isInBoundary(p))
        return NULL;
  
    if (data != NULL)
        return data;
  
    if ((topLeft.x + botRight.x) / 2 >= p.x)
    {
        // Indicates topLeftTree
        if ((topLeft.y + botRight.y) / 2 <= p.y)
        {
            if (topLeftTree == NULL)
                return NULL;
            return topLeftTree->find(p);
        }
  
        // Indicates botLeftTree
        else
        {
            if (botLeftTree == NULL)
                return NULL;
            return botLeftTree->find(p);
        }
    }
    else
    {
        // Indicates topRightTree
        if ((topLeft.y + botRight.y) / 2 <= p.y)
        {
            if (topRightTree == NULL)
                return NULL;
            return topRightTree->find(p);
        }
  
        // Indicates botRightTree
        else
        {
            if (botRightTree == NULL)
                return NULL;
            return botRightTree->find(p);
        }
    }
}

template<typename T>
bool Quad<T>::isInBoundary(PointXY p)
{
    return (p.x >= topLeft.x &&
        p.x <= botRight.x &&
        p.y <= topLeft.y &&
        p.y >= botRight.y);
}

template<typename T>
std::vector<T*> Quad<T>::find_neighbours(PointXY p)
{
    std::vector<T*> neighbours;
    neighbours.reserve(8);
    neighbours.push_back(find(PointXY{p.x-min_width, p.y+min_width}));
    neighbours.push_back(find(PointXY{p.x, p.y+min_width}));
    neighbours.push_back(find(PointXY{p.x+min_width, p.y+min_width}));
    neighbours.push_back(find(PointXY{p.x-min_width, p.y}));
    neighbours.push_back(find(PointXY{p.x+min_width, p.y}));
    neighbours.push_back(find(PointXY{p.x-min_width, p.y-min_width}));
    neighbours.push_back(find(PointXY{p.x, p.y-min_width}));
    neighbours.push_back(find(PointXY{p.x+min_width, p.y-min_width}));
    return neighbours;
}
} // namespace abds_core
