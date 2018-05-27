#include <opencv2/opencv.hpp>

int main (int argc, const char* argv[]) {
    
    cv::VideoCapture cap;
    cap.open(argv[2]);
    if (!cap.isOpened())
        return -1;
    
    int fps = cap.get(cv::CAP_PROP_FPS);
    cv::Size size {
        (int)cap.get(cv::CAP_PROP_FRAME_WIDTH),
        (int)cap.get(cv::CAP_PROP_FRAME_HEIGHT)
    };
    
    cv::VideoWriter writer;
    writer.open(argv[3],
                CV_FOURCC('M','J','P','G'),
                fps,
                size);
    
    for (cv::Mat frame, logpolar;;) {
        cap >> frame;
        if (frame.empty())
            break;
        
        cv::logPolar(frame,
                     logpolar,
                     cv::Point2f {
                         (float)(frame.cols/2),
                         (float)(frame.rows/2)
                     },
                     40,
                     cv::WARP_FILL_OUTLIERS);
        
        writer << logpolar;
        cv::imshow("Example2-11 logpolar", logpolar);
        
        if (cv::waitKey(1000/fps) == 27)
            break;
    }
    
    writer.release();
    
    return 0;
}
