#include <opencv2/opencv.hpp>

int main (int argc, const char* argv[]) {
    
    cv::Mat img = cv::imread(argv[1]);
    if (img.empty())
        return -1;
    
    cv::Mat gray, pyrd, canny;
    
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::pyrDown(gray, pyrd);
    cv::pyrDown(pyrd, pyrd);
    cv::Canny(pyrd, canny, 10, 100, 3, true);
    
    cv::imshow("Example2-8 gray", gray);
    cv::imshow("Example2-8 gray, pyrd*2, canny", canny);
    
    cv::waitKey(0);
    
    return 0;
}
