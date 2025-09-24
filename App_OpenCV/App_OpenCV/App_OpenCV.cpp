
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/core/utils/logger.hpp>
#include <iostream>


using namespace std;
using namespace cv;

int main()
{
    utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_WARNING);

    string image_path = "Assets/Input_Pictures/Temp_Entity.png";

    Mat image = imread(image_path, IMREAD_COLOR);
    
    cvtColor(image, image, COLOR_RGB2GRAY);

    resize(image, image, { 500,500 });

    imshow("ImageNew", image);

    waitKey(0);

    return 0;
}