
// test_vtlistctrlexDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test_vtlistctrlex.h"
#include "test_vtlistctrlexDlg.h"
#include "afxdialogex.h"

#include "../../Common/MemoryDC.h"
#include "../../Common/RandomText.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ctest_vtlistctrlexDlg dialog



Ctest_vtlistctrlexDlg::Ctest_vtlistctrlexDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_VTLISTCTRLEX_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest_vtlistctrlexDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Control(pDX, IDC_LIST_SHELL, m_list_shell);
}

BEGIN_MESSAGE_MAP(Ctest_vtlistctrlexDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &Ctest_vtlistctrlexDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Ctest_vtlistctrlexDlg::OnBnClickedCancel)
	ON_WM_ERASEBKGND()
	ON_WM_WINDOWPOSCHANGED()
	ON_NOTIFY(LVN_ENDLABELEDIT, IDC_LIST, &Ctest_vtlistctrlexDlg::OnLvnEndlabeleditList)
END_MESSAGE_MAP()


// Ctest_vtlistctrlexDlg message handlers

BOOL Ctest_vtlistctrlexDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_resize.Create(this);
	m_resize.Add(IDC_LIST, 0, 0, 50, 100);
	m_resize.Add(IDC_LIST_SHELL, 50, 0, 50, 100);

	EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, 0);

	m_list_shell.set_shell_list();
	m_list_shell.load_column_width(&theApp, _T("shell list"));
	//m_list_shell.set_path(_T("C:\\Users\\scpark\\Desktop"));
	m_list_shell.set_path(_T("d:\\"));

	init_list(&m_list);

	RestoreWindowPosition(&theApp, this);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Ctest_vtlistctrlexDlg::init_list(CVtListCtrlEx* plist)
{
	plist->set_headings(_T("No,50;Name,150;Slogan,200;Score,100;Memo,200"));
	//m_list.set_color_theme(CVtListCtrlEx::color_theme_dark_gray);
	//m_list.set_line_height(theApp.GetProfileInt(_T("list name"), _T("line height"), 80));
	plist->load_column_width(&theApp, _T("list name"));
	plist->set_font_size(theApp.GetProfileInt(_T("file list"), _T("font size"), 9));
	plist->set_font_name(theApp.GetProfileString(_T("file list"), _T("font name"), _T("맑은 고딕")));
	plist->set_header_height(24);

	//
	plist->set_use_own_imagelist(false);
	plist->set_line_height(20);

	//plist->set_column_text_align(0, HDF_CENTER);
	//plist->set_column_text_align(0, HDF_CENTER);
	//plist->set_column_text_align(1, HDF_CENTER);
	//plist->set_column_text_align(2, HDF_CENTER);
	/*
	plist->set_header_text_align(0, HDF_CENTER);
	plist->set_header_text_align(1, HDF_CENTER);
	plist->set_header_text_align(2, HDF_CENTER);
	plist->set_header_text_align(3, HDF_LEFT);
	*/
	//m_list.set_column_data_type(list_score, CVtListCtrlEx::column_data_type_percentage_grid);
	plist->set_column_data_type(list_score, CVtListCtrlEx::column_data_type_progress);
	plist->allow_edit();

	srand(time(NULL));

	int index;

	for (int i = 0; i < 100; i++)
	{
		int index = m_list.add_item(i2S(i));
		plist->set_text(index, list_name, RandomText::GetName());
		//m_list.set_text_color(index, 0, RGB(index, index, index));//random19937(RGB(0,0,0), RGB(255,255,255)));
		plist->set_text(index, list_slogan, RandomText::GetSlogan());
		//m_list.set_text_color(index, index, RGB(indexi, 0, 0));//random19937(RGB(0,0,0), RGB(255,255,255)));
		plist->set_text(index, list_score, i2S(random19937(0, 100)));
		//m_list.set_text_color(index, 2, RGB(0, 0, 255-index));//random19937(RGB(0,0,0), RGB(255,255,255)));
		plist->set_text(index, list_memo, RandomText::GetName());
	}

	plist->set_item_color(10, 1, red, blue);
	plist->set_item_color(3, 0, deeppink, dodgerblue);
}

void Ctest_vtlistctrlexDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Ctest_vtlistctrlexDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		return;
		CPaintDC dc1(this);
		CRect rc;

		GetClientRect(rc);
		CMemoryDC dc(&dc1, &rc, true);

		dc.FillSolidRect(rc, ::GetSysColor(COLOR_3DFACE));
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Ctest_vtlistctrlexDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest_vtlistctrlexDlg::OnBnClickedOk()
{
	m_list.set_line_height(40);
	//m_list.set_header_height(20);

	//m_list.random();
	//m_list.ensure_visible(50, CVtListCtrlEx::visible_last, 3);
	/*
	std::deque<int> result;
	m_list.find_string(_T("angela Clark"), -1, NULL, &result);
	for (int i = 0; i < result.size(); i++)
	{
		m_list.set_text_color(result[i], 0, PINK);
	}

	//m_list.sort_by_text_color(0, true);
	
	int n = m_list.find_string(_T("angela Clark"), 0, true);
	AfxMessageBox(i2S(n));
	*/
}


void Ctest_vtlistctrlexDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	m_list.save_column_width(&theApp, _T("list name"));
	m_list_shell.save_column_width(&theApp, _T("shell list"));

	CDialogEx::OnCancel();
}



BOOL Ctest_vtlistctrlexDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	//return false;
	return CDialogEx::OnEraseBkgnd(pDC);
}


void Ctest_vtlistctrlexDlg::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: Add your message handler code here
	SaveWindowPosition(&theApp, this);

	//int items = m_list.GetCountPerPage();
	//SetWindowText(i2S(items));
}


void Ctest_vtlistctrlexDlg::OnLvnEndlabeleditList(NMHDR *pNMHDR, LRESULT *pResult)
{
	NMLVDISPINFO *pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);
	// TODO: Add your control notification handler code here
	//m_list.set_item_text(pDispInfo->item.iItem, pDispInfo->item.iSubItem, pDispInfo->item.pszText);
	//std::deque<int> *dqlist = m_list.get_selected_list_for_edit();
	//for (int i = 0; i < dqlist->size(); i++)
	//	TRACE(_T("selected[%d] = %d\n"), i, dqlist->at(i));

	int item = m_list.get_recent_edit_item();
	int subItem = m_list.get_recent_edit_subitem();
	CString	text = m_list.get_text(item, subItem);
	CString oldfile;
	CString newfile;

	if (text != m_list.get_old_text())
	{
		oldfile.Format(_T("%ws\\%s"), m_list.get_text(item, subItem), m_list.get_old_text());
		newfile.Format(_T("%ws\\%s"), m_list.get_text(item, subItem), text);
	}

	*pResult = 0;
}


BOOL Ctest_vtlistctrlexDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_DELETE :
			if (AfxMessageBox(_T("선택된 항목을 삭제할까요?"), MB_ICONQUESTION | MB_YESNO) == IDNO)
				return true;
			m_list.delete_selected_items();
			break;
		case VK_ADD :
			m_list.add_item(i2S(m_list.GetItemCount()));
			return true;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
