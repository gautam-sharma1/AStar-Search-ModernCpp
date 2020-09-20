#include <iostream>
#include "Astar.hpp"
#include "draw.hpp"


int main()
{   
    std::cout << "hello" << std::endl;
    Astar A(0,3);
    A.SetGoal(9,9);
    A.Implementation();
    //auto [goal_x , goal_y] = A.goal;
    //std::cout<<goal_x;
    return 0;
}