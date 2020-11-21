/*
* A-star algorithm
* See COPYRIGHT file at the top of the source tree.
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the LSST License Statement and
* the GNU General Public License along with this program. If not,
* see <http://www.lsstcorp.org/LegalNotices/>.
*
* @file algorithm.hppfunction
* @author Gautam Sharma
* Contact: gautamsharma2813@gmail.com
*/

#include <iostream>
#include "../include/Astar.hpp"
#include "../include/draw.hpp"
/*
Aim of this project is to abstract away all the complicated stuff to give the user a simple yet efficient interface to implement A* search algorithm.
*/
int main()
{

    Astar A(0, 3);      // sets starting point of the agent
    A.SetGoal(9, 9);    // sets goal coordinate
    A.Implementation(); // begins the search procedure
    return 0;
}