#include <opencv2/opencv.hpp>

template <typename T>
class MyMat : public cv::Mat {
public:
    MyMat(cv::InputArray img):cv::Mat(img.getMat()) {};
    
    auto begin() { return cv::Mat::begin<T>(); };
    auto end() { return cv::Mat::end<T>(); };
};


int main (int argc, const char* argv[]) {
    auto start = cv::getTickCount();
    auto test = cv::Matx33d(3, 0, 0,
                            0, 3, 0,
                            0, 0, 3);
    cv::NAryMatIterator
    auto ma = cv::Mat {cv::Size{2,2}, CV_8UC2, cv::Scalar{2.1}};
    cv::Complexf
    CV_MAKETYPE(hello, hi);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << (uint)ma.at<uchar>(i,j) << " ";
        }
        std::cout << std::endl;
    }
    
    auto test2 = cv::Matx13d(1, 2, 3);
    
    auto test3 = test2 * test;
    auto test4 = test.get_minor<2,2>(1,1);
    
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << test4(i,j) << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << test3(i, j) << " ";
        }
        std::cout << std::endl;
    }
    
    cv::Mat src = cv::imread(argv[1]);
    if (src.empty())
        return -1;
//    for (auto read : MyMat<uchar>{src}) {
//        std::cout << (uint)read << std::endl;
//    }
    
    cv::namedWindow("Example2-1");
    
    cv::imshow("Example2-1", src);
    std::cout << (cv::getTickCount() - start)/cv::getTickFrequency() << std::endl;
    cv::waitKey(0);
    
    cv::destroyWindow("Example2-1");
    
    return 0;
}
