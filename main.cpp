#include <iostream>
#include "algorithm.hpp"


int main()
{   
    std::cout << "hello" << std::endl;
    Astar A(2,2);
    A.Implementation();
    //auto [goal_x , goal_y] = A.goal;
    //std::cout<<goal_x;
    return 0;
}