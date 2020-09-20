#ifndef draw_hpp
#define draw_hpp

#include <opencv2/core.hpp>
//#include "Astar.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <tuple>
#include <memory>

using namespace cv;

using PointI = std::tuple<int, int>;
class Draw
{
public:
    explicit Draw(Mat Picture, const PointI &goal)
    {
        _Picture = Picture;

        // Check for failure
        if (Picture.empty())
        {
            std::cout << "Could not instantiate the image" << std::endl;
            std::cin.get(); //wait for any key press
        }
        resize(_Picture, _Picture, Size(600, 600));
        temp_goal = goal;
        circle(_Picture, Point(std::get<0>(temp_goal) * _scale_factor, std::get<0>(temp_goal) * _scale_factor), 5, Scalar(255, 255, 0), 2, 8, 0); // plots goal position
        //line(_Picture, Point(10 * 30, 0 * 30), Point pt2, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
    }

    static void Simulation(PointI point)
    { //using _sf = _scale_factor;
        auto x = std::get<0>(point) * _scale_factor;
        auto y = std::get<1>(point) * _scale_factor;
        circle(_Picture, Point(x, y), 5, Scalar(0, 255, 0), 2, 8, 0);
        //line(_Picture, Point(10 * 30, 0 * 30), Point pt2, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
        imshow("A* Search", _Picture);
        waitKey(50);
    }

    void Draw_Path(PointI point, const std::vector<std::vector<int>> &path)
    {
        auto x = std::get<0>(point) * _scale_factor;
        auto y = std::get<1>(point) * _scale_factor;
        //using _sf = _scale_factor;
        if (x / _scale_factor == std::get<0>(temp_goal) && y / _scale_factor == std::get<1>(temp_goal))
        {
            for (auto itr = path.begin(); itr != path.end(); ++itr)
            {
                circle(_Picture, Point((*itr).at(0) * _scale_factor, (*itr).at(1) * _scale_factor), 5, Scalar(0, 0, 255), 2, 8, 0);
                waitKey(100);
                imshow("A* Search", _Picture);
            }
        }
    }

private:
    inline static Mat _Picture;
    const static int _scale_factor{30};
     PointI temp_goal;
};
// static void Draw (Mat &Picture, PointI point){

// };
#endif /* draw_hpp */