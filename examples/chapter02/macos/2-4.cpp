#include <opencv2/opencv.hpp>

cv::VideoCapture cap;
bool isStop = true;
bool isSync = false;

int main (int argc, const char* argv[]) {
    
    cap.open(argv[2]);
    if (!cap.isOpened())
        return -1;
    
    int slider_position = 0;
    
    auto sync_window = [](int pos, void*)->void {
        cap.set(cv::CAP_PROP_POS_FRAMES, pos);
        if (isStop)
            isSync = false;
    };
    
    cv::namedWindow("Example2-4");
    cv::createTrackbar("Position",
                       "Example2-4",
                       &slider_position,
                       cap.get(cv::CAP_PROP_FRAME_COUNT),
                       sync_window);
    
    for (cv::Mat frame;;) {
        if ((!isStop) || (isStop && !isSync)) {
            if (isStop)
                isSync = true;
            
            cap >> frame;
            if (frame.empty())
                break;
            
            cv::setTrackbarPos("Position", "Example2-4",
                               cap.get(cv::CAP_PROP_POS_FRAMES));
            
            cv::imshow("Example2-4", frame);
        }
        int key = cv::waitKey(1000/30);
        if (key == 27)
            break;
        else if (key == 's')
            isStop = true;
        else if (key == 'r')
            isStop = false;
    }
    
    return 0;
}
