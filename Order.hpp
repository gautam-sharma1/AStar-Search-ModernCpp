#ifndef Order_hpp
#define Order_hpp
#include "algorithm.hpp"
 
 
 struct Order
{
    bool operator()(point const& a, point const& b) const
    {
        return (a.cost + Heuristic(a.p,Astar::goal)  < b.cost + Heuristic(b.p,Astar::goal) );
    }
};   


#endif /* Order_hpp */