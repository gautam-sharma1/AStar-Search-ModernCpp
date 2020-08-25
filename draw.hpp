#ifndef draw_hpp
#define draw_hpp

#include <opencv2/core.hpp>
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
    explicit Draw(Mat Picture)
    {
        _Picture = Picture;
        // Check for failure
        if (Picture.empty())
        {
            std::cout << "Could not instantiate the image" << std::endl;
            std::cin.get(); //wait for any key press
        }
        resize(_Picture, _Picture, Size(600, 600));

        circle(_Picture, Point(10 * 30, 0 * 30), 20, Scalar(255, 255, 0), 2, 8, 0);
    }

    static void Simulation(PointI point)
    {
        auto x = std::get<0>(point) * 30;
        auto y = std::get<1>(point) * 30;
        circle(_Picture, Point(x, y), 20, Scalar(0, 255, 0), 2, 8, 0);
        imshow("A* Search", _Picture);
        waitKey(50);
    }

    static void Check_Goal(PointI point, std::vector<std::vector<int>> path)
    {
    }

    static void Goal_Check() private : inline static Mat _Picture;
};
// static void Draw (Mat &Picture, PointI point){

// };
#endif /* draw_hpp */