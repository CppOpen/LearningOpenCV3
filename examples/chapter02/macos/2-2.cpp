#include <opencv2/opencv.hpp>

int main (int argc, const char* argv[]) {
    
    cv::VideoCapture cap;
    cap.open(argv[2]);
    if (!cap.isOpened())
        return -1;
    
    for (cv::Mat frame;;) {
        cap >> frame;
        if (frame.empty())
            break;
        
        cv::imshow("Example2-3", frame);
        if (cv::waitKey(1000/30) >= 0)
            break;
    }
    
    return 0;
}
