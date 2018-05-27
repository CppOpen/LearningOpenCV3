#include <opencv2/opencv.hpp>

int main (int argc, const char* argv[]) {
    
    cv::Mat src = cv::imread(argv[1]);
    if (src.empty())
        return -1;
    
    cv::Mat blur;
    
    cv::GaussianBlur(src, blur, {5, 5}, 3, 3);
    cv::GaussianBlur(blur, blur, {5, 5}, 3, 3);
    
    cv::imshow("Example2-5 src", src);
    cv::imshow("Example2-5 blur", blur);
    
    cv::waitKey(0);
    
    return 0;
}
