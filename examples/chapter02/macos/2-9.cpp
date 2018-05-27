#include <opencv2/opencv.hpp>

int main (int argc, const char* argv[]) {
    
    cv::Mat src = cv::imread(argv[1]);
    if (src.empty())
        return -1;
    
    cv::Mat gray, pyrd, canny;
    
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
    cv::pyrDown(gray, pyrd);
    cv::pyrDown(pyrd, pyrd);
    cv::Canny(pyrd, canny, 10, 100, 3, true);
    
    int x = 16, y = 32;
    cv::Vec3b intensity = src.at<cv::Vec3b>(y,x);
    uchar blue = intensity[0];
    uchar green = intensity[1];
    uchar red = intensity[2];
    
    std::cout << "(b,g,r) = "
    << (uint)blue << ", "
    << (uint)green << ", "
    << (uint)red << "\n";
    
    std::cout << "(gray) = "
    << (uint)gray.at<uchar>(y,x) << "\n";
    
    x/=4; y/=4;
    std::cout << "(pyrd gray) = "
    << (uint)pyrd.at<uchar>(y,x) << "\n";
    
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j)
            canny.at<uchar>(y+j, x+i) = 128;
    
    cv::imshow("Example2-9 gray", gray);
    cv::imshow("Example2-9 pyrd, canny, pixel", canny);
    
    cv::waitKey(0);
    
    return 0;
}
