#include "QMoviePlayer.h"
#include <QTimer>
#include <QPainter>

QMoviePlayer::QMoviePlayer(QWidget *parent)
	: QWidget(parent)
{
}

bool QMoviePlayer::open(string file) {
	if (!m_cap.open(file)) return false;
	// If we opened the file, set up everything now:
	//
	m_cap.read(m_cv_img);
	m_qt_img = QImage(
		QSize(m_cv_img.cols, m_cv_img.rows),
		QImage::Format_RGB888
	);
	
	this->setFixedHeight(m_qt_img.height());
	this->setFixedWidth(m_qt_img.width());

	_copyImage();
	m_timer = new QTimer(this);
	connect(
		m_timer,
		SIGNAL(timeout()),
		this,
		SLOT(nextFrame())
	);
	m_timer->start(1000. / m_cap.get(cv::CAP_PROP_FPS));
	return true;
}

void QMoviePlayer::_copyImage(void) {
	// Copy the image data into the Qt QImage
	//
	cv::Mat cv_header_to_qt_image(
		cv::Size(
			m_qt_img.width(),
			m_qt_img.height()
		),
		CV_8UC3,
		m_qt_img.bits()
	);
	if (m_cv_img.empty()) return;
	cv::cvtColor(m_cv_img, cv_header_to_qt_image, cv::COLOR_BGR2RGB);
}

void QMoviePlayer::nextFrame() {
	// Nothing to do if capture object is not open
	//
	if (!m_cap.isOpened()) return;
	m_cap.read(m_cv_img);
	_copyImage();
	this->update();
}

void QMoviePlayer::paintEvent(QPaintEvent* e) {
	QPainter painter(this);
	painter.drawImage(QPoint(0, 0), m_qt_img);
}