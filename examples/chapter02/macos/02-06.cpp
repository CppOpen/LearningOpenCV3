#include <opencv2/opencv.hpp>

int main (int argc, const char* argv[]) {
    
    cv::Mat src = cv::imread(argv[1]);
    if (src.empty())
        return -1;
    
    cv::Mat pyrd;
    cv::pyrDown(src, pyrd);
    
    cv::imshow("Example2-6 src", src);
    cv::imshow("Example2-6 pyrd", pyrd);
    
    cv::waitKey();
    
    return 0;
}
