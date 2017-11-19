#include "stdafx.h"

#include "QMoviePlayer.h"

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	QMoviePlayer mp;
	mp.open(argv[1]);
	mp.show();
	return app.exec();
}
