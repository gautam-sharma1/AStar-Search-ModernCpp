#include <iostream>
#include "Astar.hpp"
#include "draw.hpp"

/*
Aim of this project is to abstract away all the complicated stuff to give the user a simple yet efficient interface to implement A* search algorithm.
*/
int main()
{   
    std::cout << "Hello" << std::endl;
    Astar A(0,3); // sets starting point of the agent
    A.SetGoal(9,9); // sets goal coordinate
    A.Implementation(); // begins the search procedure
    
    /*
    That's it :)
    */
    
    return 0;
}
