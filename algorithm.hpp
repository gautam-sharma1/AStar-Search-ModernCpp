#ifndef algorithm_hpp
#define algorithm_hpp
#include <tuple>
#include <cmath>
#include <vector>
#include <functional>
#include <map>
#include <queue>
#include <algorithm>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include <opencv2/videoio.hpp>

#include <opencv2/objdetect.hpp>

#include <opencv2/imgproc.hpp>
using namespace cv;

// struct Point
// {
//     int x_coord{0};
//     int y_coord{0};
// };


//Main data structure of the problem
using PointI = std::tuple<int, int>;

//A dictionary that stores the path to a given node.If {2,2} is selected for expansion that it stores the path till {2,2}.
std::map<PointI, std::vector<std::vector<int>>> optimal_path;

// representation of a point in 2D space. Any point can be represented as {x,y} and the cost to reach that point from the previous point.
struct my_point
{
    PointI p;
    int cost;
};

/*
Heuristic funtion. Should be modified according to the problem.
*/
double Heuristic(PointI a, PointI b)
{
    return 30*std::sqrt((std::get<0>(a) - std::get<0>(b)) ^ 2 + (std::get<1>(a) - std::get<1>(b)) ^ 2);
};


inline static PointI goal = std::make_tuple(10, 10); // Goal position. Static so can be modified from main


/*
Order in which Astar compare two nodes. 
*/
struct Order
{
    bool operator()(my_point const &a, my_point const &b) const
    {
        return (a.cost + Heuristic(a.p, goal) < b.cost + Heuristic(b.p, goal));
    }
};


/*
Main class
*/
class Astar
{

public:
    Astar(int x, int y) : _starting_pos{std::make_tuple(x, y)} //Constructor
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

    void Movement(PointI &p)
    {
        _cost += 1;
        if (IsLegal(p))
        {
            std::vector<std::vector<int>> poi{optimal_path[p]};
            for (auto &x : _moves)
            {
                for (auto &y : _moves)
                {
                    if (abs(x) != abs(y))
                    {
                        PointI p_new = std::make_tuple(std::get<0>(p) + x, std::get<1>(p) + y);                       


                        poi.push_back({std::get<0>(p), std::get<1>(p)});
                        optimal_path[p_new] = poi;

                        if (IsLegal(p_new) && std::find(_history.begin(), _history.end(), p_new) == _history.end())
                        {
                            my_point temp;
                            temp.p = p_new;
                            temp.cost += _cost;

                            PQueue.push(temp);
                            _history.push_back(p_new);
                        }
                    }
                }
            }
        }
    }

    bool IsLegal(PointI point)
    {
        return std::get<0>(point) >= 0 && std::get<0>(point) <= 10 && std::get<1>(point) >= 0 && std::get<1>(point) <= 10;
    }

    void SetObstacle(){};
    void GetObstacle(){};

    void Implementation()
    {
        Mat Picture(320, 240, CV_8UC3, cv::Scalar(0, 0, 0));
         // Check for failure
        if (Picture.empty())
        {
            std::cout << "Could not instantiate the image" << std::endl;
            std::cin.get(); //wait for any key press
        }
        resize(Picture, Picture, Size(500, 500));

        circle(Picture, Point(300, 300), 20, Scalar(255, 255, 0), 2, 8, 0);
        Movement(_starting_pos);
        my_point temp = PQueue.top();
        while (temp.p != goal)
        {
            temp = PQueue.top();
            auto x = std::get<0>(temp.p)*30;
            auto y = std::get<1>(temp.p)*30;
            circle(Picture, Point(x, y), 20, Scalar(0, 255, 0), 2, 8, 0);
            imshow("A* Search", Picture);
            waitKey(50);


            PQueue.pop();
            Movement(temp.p);
            std::cout << std::get<0>(temp.p) << " " << std::get<1>(temp.p) << std::endl;

            std::vector<std::vector<int>> path = optimal_path[temp.p];
            std::vector<std::vector<int> >::iterator itr = std::unique(path.begin(), path.end());
            path.resize(std::distance(path.begin(), itr));
            if(x==300 && y==300){
            for (auto itr = path.begin(); itr != path.end(); ++itr)
            {
                circle(Picture, Point((*itr).at(0)*30, (*itr).at(1)*30), 20, Scalar(0, 0, 255), 2, 8, 0);
                waitKey(100);
                imshow("A* Search", Picture);
            }
          
            } 
            for (auto itr = path.begin(); itr != path.end(); ++itr)
            {

                std::cout<<"{"<<(*itr).at(0)<<","<<(*itr).at(1)<<"} ";
            }
            std::cout<<std::endl;
        }
        destroyWindow("Path planner Reinforcement-Learning");
    };
    //inline static PointI goal = std::make_tuple(10, 10); //Default goal of the Astar problem

private:
    PointI _starting_pos = std::make_tuple(0, 0); //Starting position can be changed from the constructor
    std::vector<int> _moves = {-1, 0, 1}; // Possible moves in x and y direction
    std::priority_queue<my_point, std::vector<my_point>, Order> PQueue; // Priority Queue that helps expandind nodes based on their least combined cost
    int _cost = 0; 
    std::vector<PointI> _history; 
};

#endif /* algorithm_hpp */


