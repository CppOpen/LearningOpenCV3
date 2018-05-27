#pragma once
#  pragma warning(disable:4996)
#  pragma warning(disable:4244)

#ifdef _MSC_VER
	#include <Windows.h>
#endif

#include <opencv2/opencv.hpp>

#define _CV_VERSION_STR  CVAUX_STR(CV_VERSION_MAJOR)  CVAUX_STR(CV_VERSION_MINOR)  CVAUX_STR(CV_VERSION_REVISION)

#ifdef _MSC_VER
	#define DLL_EXT  ".lib"
	#define HEAD_DLL ""
#else
	#define HEAD_DLL "."
	#define DLL_EXT  ".dylib"
#endif

#ifdef _DEBUG
#define _CV_VERSION  HEAD_DLL _CV_VERSION_STR "d" DLL_EXT
#else
#define _CV_VERSION  _CV_VERSION_STR  DLL_EXT
#endif


#ifdef HAVE_OPENCV_ARUCO
#pragma comment(lib, "opencv_aruco" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_BGSEGM
#pragma comment(lib, "opencv_bgsegm" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_BIOINSPIRED
#pragma comment(lib, "opencv_bioinspired" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_CALIB3D
#pragma comment(lib, "opencv_calib3d" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_CCALIB
#pragma comment(lib, "opencv_ccalib" _CV_VERSION )
#endif

#ifdef HAVE_OPENCV_CORE
#pragma comment(lib, "opencv_core" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_CVV
//#pragma comment(lib, "opencv_cvv" _CV_VERSION )
// msvc cpp  encode problem
#endif

#ifdef HAVE_OPENCV_DATASETS
#pragma comment(lib, "opencv_datasets" _CV_VERSION )
#endif

#ifdef HAVE_OPENCV_DNN
#pragma comment(lib, "opencv_dnn" _CV_VERSION )
#endif

#ifdef HAVE_OPENCV_DPM
#pragma comment(lib, "opencv_dpm" _CV_VERSION )
#endif

#ifdef HAVE_OPENCV_FACE
#pragma comment(lib, "opencv_face" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_FEATURES2D
#pragma comment(lib, "opencv_features2d" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_FLANN
#pragma comment(lib, "opencv_flann" _CV_VERSION)
#endif

#ifdef HAVE_OPENCV_FUZZY
#pragma comment(lib, "opencv_fuzzy" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_HIGHGUI
#pragma comment(lib, "opencv_highgui" _CV_VERSION )
#endif

#ifdef HAVE_OPENCV_IMG_HASH
#pragma comment(lib, "opencv_img_hash" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_IMGCODECS
#pragma comment(lib, "opencv_imgcodecs" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_IMGPROC
#pragma comment(lib, "opencv_imgproc" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_LINE_DESCRIPTOR
#pragma comment(lib, "opencv_line_descriptor" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_ML
#pragma comment(lib, "opencv_ml" _CV_VERSION )
#endif

#ifdef HAVE_OPENCV_OBJDETECT
#pragma comment(lib, "opencv_objdetect" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_OPTFLOW
#pragma comment(lib, "opencv_optflow" _CV_VERSION )
#endif

#ifdef HAVE_OPENCV_PHASE_UNWRAPPING
#pragma comment(lib, "opencv_phase_unwrapping" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_PHOTO
#pragma comment(lib, "opencv_photo" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_PLOT
#pragma comment(lib, "opencv_plot" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_REG
#pragma comment(lib, "opencv_reg" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_RGBD
#pragma comment(lib, "opencv_rgbd" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_SALIENCY
#pragma comment(lib, "opencv_saliency" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_SHAPE
#pragma comment(lib, "opencv_shape" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_STEREO
#pragma comment(lib, "opencv_stereo" _CV_VERSION )
#endif

#ifdef HAVE_OPENCV_STITCHING
#pragma comment(lib, "opencv_stitching" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_STRUCTURED_LIGHT
#pragma comment(lib, "opencv_structured_light" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_SUPERRES
#pragma comment(lib, "opencv_superres" _CV_VERSION )
#endif

#ifdef HAVE_OPENCV_SURFACE_MATCHING
#pragma comment(lib, "opencv_surface_matching" _CV_VERSION)
#endif

#ifdef HAVE_OPENCV_TEXT
#pragma comment(lib, "opencv_text" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_TRACKING
#pragma comment(lib, "opencv_tracking" _CV_VERSION )
#endif

#ifdef HAVE_OPENCV_VIDEO
#pragma comment(lib, "opencv_video" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_VIDEOIO
#pragma comment(lib, "opencv_videoio" _CV_VERSION )
#endif

#ifdef HAVE_OPENCV_VIDEOSTAB
#pragma comment(lib, "opencv_videostab" _CV_VERSION )
#endif

#ifdef HAVE_OPENCV_XFEATURES2D
#include <opencv2/xfeatures2d.hpp>
#pragma comment(lib, "opencv_xfeatures2d" _CV_VERSION )
#endif

#ifdef HAVE_OPENCV_XIMGPROC
#pragma comment(lib, "opencv_ximgproc" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_XOBJDETECT
#pragma comment(lib, "opencv_xobjdetect" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_XPHOTO
#pragma comment(lib, "opencv_xphoto" _CV_VERSION  )
#endif

#ifdef HAVE_OPENCV_VIZ
#pragma comment(lib, "opencv_viz" _CV_VERSION  )
#endif

#ifdef OPENCV_ENABLE_NONFREE
#include <opencv2/xfeatures2d/nonfree.hpp>
#endif

#pragma comment(lib,"Opengl32.lib")
#pragma comment(lib,"Glu32.lib")
#include <opencv2/core/opengl.hpp>
