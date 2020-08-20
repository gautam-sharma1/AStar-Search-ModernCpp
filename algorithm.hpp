#ifndef algorithm_hpp
#define algorithm_hpp
#include <tuple>
#include <cmath>
#include <vector>
#include <functional>
#include <queue>
#include <algorithm>

struct Point
{
    int x_coord{0};
    int y_coord{0};
};



using PointI = std::tuple<int, int>;

struct point{
    PointI p;
    int cost;
};



double Heuristic(PointI a, PointI b)
    {
        return std::sqrt((std::get<0>(a) - std::get<0>(b)) ^ 2 + (std::get<1>(a) - std::get<1>(b)) ^ 2);
    };



inline static PointI goal = std::make_tuple(5, 10); //Goal position

 struct Order
{
    bool operator()(point const& a, point const& b) const
    {
        return (a.cost + Heuristic(a.p,goal)  < b.cost + Heuristic(b.p,goal) );
    }
};   


class Astar
{

public:
    Astar(int x, int y) : _starting_pos{std::make_tuple(x, y)}
    {
        std::cout << "Starting position set to "
                  << "{" << std::get<0>(_starting_pos) << ", " << std::get<1>(_starting_pos) << "} " << std::endl;
    }

    /*
    Heuristic can be changed based on the problem.
    Current heuristic is (x1-x2)^2 + (y1-y2)^2
    */
    // double Heursitic(PointI a, PointI b)
    // {
    //     return std::sqrt((std::get<0>(a) - std::get<0>(b)) ^ 2 + (std::get<1>(a) - std::get<1>(b)) ^ 2);
    // };

    void Movement(PointI &p){
        _cost += 1;
        if(IsLegal(p)){
        for(auto &x:_moves){
            for(auto &y : _moves){
            PointI p_new = std::make_tuple(std::get<0>(p)+x, std::get<1>(p)+y);
            if(IsLegal(p_new) && std::find(_history.begin(), _history.end(), p_new) == _history.end()){
                point temp;
                temp.p = p_new;
                temp.cost += _cost;
                PQueue.push(temp);
                _history.push_back(p_new);
            }
        }
        }
        }

    }

    bool IsLegal(PointI point){
        return std::get<0>(point)>=0 && std::get<0>(point)<=10 && std::get<1>(point)>=0 && std::get<1>(point)<=10 ;
    }

    void SetObstacle(){};
    void GetObstacle(){};
    void Implementation(){
        
        Movement(_starting_pos);
        point temp = PQueue.top();
        while(temp.p != goal){
        temp = PQueue.top();
        PQueue.pop();
        Movement(temp.p);
        std::cout<< std::get<0> (temp.p) <<  " " << std::get<1> (temp.p) << std::endl;
        }
    };
    //inline static PointI goal = std::make_tuple(10, 10); //Default goal of the Astar problem


private:
    PointI _starting_pos = std::make_tuple(0, 0);
    std::vector<int> _moves = {-1,0,1};
    std::priority_queue< point, std::vector<point> , Order > PQueue ;
    int _cost = 0;
    std::vector<PointI> _history;


};




#endif /* algorithm_hpp */