//Example 9-4. QT Backend test

#include "stdafx.h"
#include "..\..\_opencv.h"
void help(char** argv) {
	std::cout << "\n"
		<< "QT Backend test\n"
		<< argv[0] << " <path/filename>\n"
		<< "For example:\n"
		<< argv[0] << " ../fruits.jpg\n"
		<< std::endl;
}

int mybar0;
int mybar1;

int main(int argc, char** argv) {

	if (argc != 2) {
		help(argv);
		return 0;
	}
	
	const char* file_name = argv[1];
	cv::Mat img = cv::imread(file_name, -1);;
	if (img.empty()) return -1;

	cv::namedWindow("Image", cv::WINDOW_GUI_EXPANDED);

	cv::displayOverlay("Image", file_name, 0);
	cv::createTrackbar("Trackbar0", "Image", &mybar0, 255);
	cv::createTrackbar("Trackbar1", "Image", &mybar1, 255);
	cv::createButton("", NULL, NULL, cv::QT_PUSH_BUTTON);
	cv::createButton("", NULL, NULL, cv::QT_PUSH_BUTTON);
	cv::createButton("", NULL, NULL, cv::QT_PUSH_BUTTON);
	cv::createButton("", NULL, NULL, cv::QT_PUSH_BUTTON | cv::QT_NEW_BUTTONBAR);

	cv::createTrackbar("Trackbar2", "", &mybar1, 255);
	cv::createButton("Button3", NULL, NULL, cv::QT_RADIOBOX, 1);
	cv::createButton("Button4", NULL, NULL, cv::QT_RADIOBOX, 0);
	cv::createButton("Button5", NULL, NULL, cv::QT_CHECKBOX, 0);

	cv::imshow("Image", img);
	cv::waitKey(0);
    return 0;
}

