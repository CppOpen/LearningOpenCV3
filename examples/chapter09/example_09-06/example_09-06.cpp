//Example 9-6. An example program ch4_qt.cpp, which takes a single argument
//indicating a video file; that video file will be replayed inside of a Qt object that we will
//define, called QMoviePlayer
//

#include "stdafx.h"

#include "QMoviePlayer.h"

int main(int argc, char* argv[]) {
	std::cout << "\n\nExample 9-6. An example program ch4_qt.cpp, which takes a single argument"
		<< "\nindicating a video file; that video file will be replayed inside of a Qt object"
		<< "\nthat we will define, called QMoviePlayer"
		<< "\nCall:\n" << argv[0] << " <path/movie>"
		<< "\nExample:\n" << argv[0] << " ../tree.avi\n" << endl;
	if (argc != 2)
		return -1;

	QApplication app(argc, argv);
	QMoviePlayer mp;
	mp.open(argv[1]);
	mp.show();
	return app.exec();
}
