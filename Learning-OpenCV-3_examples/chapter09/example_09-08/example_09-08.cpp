// Example 9-8. An example header file for our custom View class
//

#include "stdafx.h"
#include "..\..\_opencv.h"

#include <atlbase.h>
#include <atlapp.h>
#include <atlframe.h>
#include <atldlgs.h>
#include <atlmisc.h>

#include "resource.h"


class COpenCVTestView : public CWindowImpl<COpenCVTestView> {
public:
	enum { IDD = IDD_FORMVIEW1};

	DECLARE_WND_CLASS(NULL)
	bool OpenFile(std::string file);
	void _copyImage();
	BOOL PreTranslateMessage(MSG* pMsg)
	{
		return CWindow::IsDialogMessage(pMsg);
	}

	BEGIN_MSG_MAP(COpenCVTestView)
		MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBkgnd)
		MESSAGE_HANDLER(WM_PAINT, OnPaint)
		MESSAGE_HANDLER(WM_TIMER, OnTimer)
	END_MSG_MAP()
	// Handler prototypes (uncomment arguments if needed):
	//  LRESULT MessageHandler(
	//    UINT    /*uMsg*/,
	//    WPARAM  /*wParam*/,
	//    LPARAM  /*lParam*/,
	//    BOOL&   /*bHandled*/
	//  );
	//  LRESULT CommandHandler(
	//    WORD    /*wNotifyCode*/,
	//    WORD    /*wID*/,
	//    HWND    /*hWndCtl*/,
	//    BOOL&   /*bHandled*/
	//  );
	//  LRESULT NotifyHandler(
	//    int     /*idCtrl*/,
	//    LPNMHDR /*pnmh*/,
	//    BOOL&   /*bHandled*/
	//  );
	LRESULT OnPaint(
		UINT    /*uMsg*/,
		WPARAM  /*wParam*/,
		LPARAM  /*lParam*/,
		BOOL&   /*bHandled*/
	);
	LRESULT OnTimer(
		UINT    /*uMsg*/,
		WPARAM  /*wParam*/,
		LPARAM  /*lParam*/,
		BOOL&   /*bHandled*/
	);
	LRESULT OnEraseBkgnd(
		UINT    /*uMsg*/,
		WPARAM  /*wParam*/,
		LPARAM  /*lParam*/,
		BOOL&   /*bHandled*/
	);
private:
	cv::VideoCapture m_cap;
	cv::Mat          m_cv_img;
	RGBTRIPLE*       m_bitmapBits;
};

class CMainFrame : public CFrameWindowImpl<CMainFrame>,
	public CUpdateUI<CMainFrame>,
	public CMessageFilter,
	public CIdleHandler
{
public:
	DECLARE_FRAME_WND_CLASS(NULL, IDD_FORMVIEW)

	BEGIN_UPDATE_UI_MAP(CMainFrame)
	END_UPDATE_UI_MAP()

	BEGIN_MSG_MAP(CMainFrame)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		CHAIN_MSG_MAP(CUpdateUI<CMainFrame>)
		CHAIN_MSG_MAP(CFrameWindowImpl<CMainFrame>)
		COMMAND_ID_HANDLER(ID_FILE_OPENEX, OnFileOpen)
	END_MSG_MAP()

	virtual BOOL PreTranslateMessage(MSG* pMsg)
	{
		if (CFrameWindowImpl<CMainFrame>::PreTranslateMessage(pMsg))
			return TRUE;

		return m_view.PreTranslateMessage(pMsg);
	}

	virtual BOOL OnIdle()
	{
		UIUpdateToolBar();
		return FALSE;
	}

	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		RECT m;
		this->GetClientRect(&m);
		m_view.Create(this->m_hWnd, m);

		HMENU hMenu = LoadMenu(_AtlBaseModule.GetResourceInstance(), MAKEINTRESOURCE(IDR_MENU1));
		SetMenu(hMenu);
		return 0;
	}

	LRESULT OnFileOpen(WORD /*wNotifyCode*/, 	WORD /*wID*/,HWND /*hWndCtl*/,	BOOL& /*bHandled*/);

protected:
	COpenCVTestView m_view;
};

LRESULT CMainFrame::OnFileOpen(
	WORD /*wNotifyCode*/,
	WORD /*wID*/,
	HWND /*hWndCtl*/,
	BOOL& /*bHandled*/
) {
	WTL::CFileDialog dlg(TRUE);
	if (IDOK == dlg.DoModal(m_hWnd)) {
		m_view.OpenFile(dlg.m_szFileName);
	}
	return 0;
}

bool COpenCVTestView::OpenFile(std::string file) {
	if (!m_cap.open(file)) return false;
	// If we opened the file, set up everything now:
	//
	m_cap.read(m_cv_img);
	// could create a DIBSection here, but let's just allocate memory for raw bits
	//
	if (m_cv_img.empty()) return false;

	RECT rect = { 0,0,m_cv_img.cols,m_cv_img.rows };
	this->MoveWindow(&rect, 1);
	m_bitmapBits = new RGBTRIPLE[m_cv_img.cols * m_cv_img.rows];
	_copyImage();
	SetTimer(0, (int)( 1000.0f / m_cap.get(cv::CAP_PROP_FPS) ));
	return true;
}

void COpenCVTestView::_copyImage() {
	// Copy the image data into the bitmap
	//
	cv::Mat cv_header_to_qt_image(
		cv::Size(
			m_cv_img.cols,
			m_cv_img.rows
		),
		CV_8UC3,
		m_bitmapBits
	);
	if (m_cv_img.empty()) return;

	m_cv_img.copyTo(cv_header_to_qt_image);
}

LRESULT COpenCVTestView::OnPaint(
	UINT /* uMsg */,
	WPARAM /* wParam  */,
	LPARAM /* lParam  */,
	BOOL& /* bHandled */
) {
	CPaintDC dc =  m_hWnd;
	WTL::CRect rect;
	GetClientRect(&rect);
	
	if (m_cap.isOpened()) {
		BITMAPINFO bmi = { 0 };
		bmi.bmiHeader.biSize = sizeof(bmi.bmiHeader);
		bmi.bmiHeader.biCompression = BI_RGB;
		bmi.bmiHeader.biWidth = m_cv_img.cols;
		// note that bitmaps default to bottom-up, use negative height to
		// represent top-down
		//
		bmi.bmiHeader.biHeight = m_cv_img.rows * -1;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biBitCount = 24;
		dc.StretchDIBits(
			0,0,
			rect.Width(),
			rect.Height(),

			0,0,
			bmi.bmiHeader.biWidth,
			abs(bmi.bmiHeader.biHeight),

			m_bitmapBits,
			&bmi,
			DIB_RGB_COLORS,
			SRCCOPY);
	}
	else {
		dc.FillRect(rect, COLOR_WINDOW);
	}
	return 0;
}

LRESULT COpenCVTestView::OnTimer(
	UINT /* uMsg	*/,
	WPARAM /* wParam  */,
	LPARAM /* lParam  */,
	BOOL& /* bHandled */
) {
	// Nothing to do if capture object is not open
	//
	if (!m_cap.isOpened()) return 0;
	m_cap.read(m_cv_img);
	_copyImage();
	Invalidate();
	return 0;
}

LRESULT COpenCVTestView::OnEraseBkgnd(
	UINT /* uMsg 	*/,
	WPARAM /* wParam  */,
	LPARAM /* lParam   */,
	BOOL& /* bHandled */
) {
	// since we completely paint our window in the OnPaint handler, use
	// an empty background handler
	return 0;
}

CAppModule _Module;

int Run(LPTSTR /*lpstrCmdLine*/ = NULL, int nCmdShow = SW_SHOWDEFAULT)
{
	CMessageLoop theLoop;
	_Module.AddMessageLoop(&theLoop);

	CMainFrame wndMain;

	if (wndMain.CreateEx() == NULL)
	{
		ATLTRACE(_T("Main window creation failed!\n"));
		return 0;
	}

	wndMain.ShowWindow(nCmdShow);
	int nRet = theLoop.Run();

	_Module.RemoveMessageLoop();
	return nRet;
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpstrCmdLine, int nCmdShow)
{
	HRESULT hRes = ::CoInitialize(NULL);
	// If you are running on NT 4.0 or higher you can use the following call instead to 
	// make the EXE free threaded. This means that calls come in on a random RPC thread.
	//	HRESULT hRes = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
	ATLASSERT(SUCCEEDED(hRes));

	// this resolves ATL window thunking problem when Microsoft Layer for Unicode (MSLU) is used
	::DefWindowProc(NULL, 0, 0, 0L);

	AtlInitCommonControls(ICC_COOL_CLASSES | ICC_BAR_CLASSES);	// add flags to support other controls

	hRes = _Module.Init(NULL, hInstance);
	ATLASSERT(SUCCEEDED(hRes));

	int nRet = Run(lpstrCmdLine, nCmdShow);

	_Module.Term();
	::CoUninitialize();

	return nRet;
}

