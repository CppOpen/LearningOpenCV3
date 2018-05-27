#include <opencv2/opencv.hpp>

int main (int argc, const char* argv[]) {
    
    cv::Mat src = cv::imread(argv[1]);
    if (src.empty())
        return -1;
    
    cv::Mat gray, canny;
    
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
    cv::Canny(gray, canny, 10, 100, 3, true);
    
    cv::imshow("Example2-7 gray", gray);
    cv::imshow("Example2-7 canny", canny);
    
    cv::waitKey(0);
    
    return 0;
}
