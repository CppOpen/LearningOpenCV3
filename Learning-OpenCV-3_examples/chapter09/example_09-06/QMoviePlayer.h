//Example 9-7. The QMoviePlayer object header file QMoviePlayer.h
//
#pragma once

#include <string>
#include <iostream>

#include "..\..\_opencv.h"

#include <QApplication>
#include <QLabel>
#include <QMediaPlayer>
#include <QVideoWidget>
#ifdef _DEBUG
#pragma comment(lib, "Qt5Widgetsd.lib")
#pragma comment(lib, "Qt5MultimediaWidgetsd.lib")
#pragma comment(lib, "Qt5Multimediad.lib")
#pragma comment(lib, "Qt5Cored.lib")
#pragma comment(lib, "Qt5Guid.lib")
#else
#pragma comment(lib, "Qt5Widgets.lib")
#pragma comment(lib, "Qt5MultimediaWidgets.lib")
#pragma comment(lib, "Qt5Multimedia.lib")
#pragma comment(lib, "Qt5Core.lib")
#pragma comment(lib, "Qt5Gui.lib")
#endif

using namespace std;
class QMoviePlayer : public QWidget {
	Q_OBJECT;
public:
	QMoviePlayer(QWidget *parent = NULL);
	virtual ~QMoviePlayer() { ; }
	bool open(string file);

private:
	cv::VideoCapture m_cap;
	QImage  m_qt_img;
	cv::Mat m_cv_img;
	QTimer* m_timer;
	void paintEvent(QPaintEvent* q);
	void _copyImage(void);

public slots:
	void nextFrame();
};
