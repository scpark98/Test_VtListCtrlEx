
// test_vtlistctrlexDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test_vtlistctrlex.h"
#include "test_vtlistctrlexDlg.h"
#include "afxdialogex.h"

#include "../../Common/MemoryDC.h"
#include "../../Common/RandomText.h"

#include <security.h>
#include <secext.h>


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
	DDX_Control(pDX, IDC_LIST_SHELL0, m_list_shell0);
	DDX_Control(pDX, IDC_LIST_SHELL1, m_list_shell1);
	DDX_Control(pDX, IDC_PATH0, m_path0);
	DDX_Control(pDX, IDC_PATH1, m_path1);
	DDX_Control(pDX, IDC_TREE0, m_tree0);
	DDX_Control(pDX, IDC_TREE1, m_tree1);
	DDX_Control(pDX, IDC_COMBO_COLOR_THEME, m_combo_color_theme);
	DDX_Control(pDX, IDC_TREE, m_tree);
}

BEGIN_MESSAGE_MAP(Ctest_vtlistctrlexDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &Ctest_vtlistctrlexDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Ctest_vtlistctrlexDlg::OnBnClickedCancel)
	ON_WM_ERASEBKGND()
	ON_WM_WINDOWPOSCHANGED()
	ON_NOTIFY(LVN_ENDLABELEDIT, IDC_LIST_SHELL0, &Ctest_vtlistctrlexDlg::OnLvnEndlabeleditListShell0)
	ON_NOTIFY(LVN_KEYDOWN, IDC_LIST_SHELL0, &Ctest_vtlistctrlexDlg::OnLvnKeydownListShell0)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_SHELL0, &Ctest_vtlistctrlexDlg::OnNMRClickListShell0)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_SHELL0, &Ctest_vtlistctrlexDlg::OnNMDblclkListShell0)
	ON_REGISTERED_MESSAGE(Message_CPathCtrl, &Ctest_vtlistctrlexDlg::on_message_pathctrl)
	ON_REGISTERED_MESSAGE(Message_CVtListCtrlEx, &Ctest_vtlistctrlexDlg::on_message_vtlistctrlex)
	ON_REGISTERED_MESSAGE(Message_CSCTreeCtrl, &Ctest_vtlistctrlexDlg::on_message_CSCTreeCtrl)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_SHELL1, &Ctest_vtlistctrlexDlg::OnNMDblclkListShell1)
	ON_CBN_SELCHANGE(IDC_COMBO_COLOR_THEME, &Ctest_vtlistctrlexDlg::OnCbnSelchangeComboColorTheme)
	ON_WM_QUERYENDSESSION()
	ON_WM_ENDSESSION()
	ON_WM_TIMER()
	ON_NOTIFY(TVN_BEGINLABELEDIT, IDC_TREE0, &Ctest_vtlistctrlexDlg::OnTvnBeginlabelEditTree0)
	ON_NOTIFY(TVN_ENDLABELEDIT, IDC_TREE0, &Ctest_vtlistctrlexDlg::OnTvnEndlabelEditTree0)
	ON_NOTIFY(TVN_BEGINLABELEDIT, IDC_TREE1, &Ctest_vtlistctrlexDlg::OnTvnBeginlabelEditTree1)
	ON_NOTIFY(TVN_ENDLABELEDIT, IDC_TREE1, &Ctest_vtlistctrlexDlg::OnTvnEndlabelEditTree1)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE0, &Ctest_vtlistctrlexDlg::OnTvnSelchangedTree0)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &Ctest_vtlistctrlexDlg::OnTvnSelchangedTree1)
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

	m_resize.Add(IDC_LIST, 0, 0, 0, 100);

	m_resize.Add(IDC_PATH0, 0, 0, 50, 0);
	m_resize.Add(IDC_TREE0, 0, 0, 10, 100);
	m_resize.Add(IDC_LIST_SHELL0, 10, 0, 40, 100);

	m_resize.Add(IDC_PATH1, 50, 0, 50, 0);
	m_resize.Add(IDC_TREE1, 50, 0, 10, 100);
	m_resize.Add(IDC_LIST_SHELL1, 60, 0, 40, 100);

	m_combo_color_theme.AddString(_T("color_theme_default"));
	m_combo_color_theme.AddString(_T("color_theme_light_blue"));
	m_combo_color_theme.AddString(_T("color_theme_navy_blue"));
	m_combo_color_theme.AddString(_T("color_theme_dark_blue"));
	m_combo_color_theme.AddString(_T("color_theme_dark_gray"));
	m_combo_color_theme.AddString(_T("color_theme_dark"));

	m_combo_color_theme.SetCurSel(0);

	m_tooltip.Create(this);// , TTS_ALWAYSTIP | TTS_NOPREFIX | TTS_NOANIMATE);

	EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, 0);

	logWrite(_T("1"));

	//shellimagelist를 초기화 한 후 트리, 리스트에서 공통으로 사용한다.
	m_ShellImageList.Initialize();

	logWrite(_T("2"));


	logWrite(_T("3"));

	logWrite(_T("4"));

	bool use_custom_draw = theApp.GetProfileInt(_T("setting"), _T("use custom draw"), true);
	m_tree.use_custom_draw(use_custom_draw);
	m_tree.load_from_string(_T("\
1\n\
	11\n\
	12\n\
		121\n\
			1211\n\
				12111\n\
	13\n\
2\n\
	21\n\
		211\n\
		212한글\n\
		213English\n\
		214にほんご\n\
		214漢字\n\
	22\n\
	23\n\
		231\n\
			2311\n\
			2312\n\
				23121\n\
				23122\n\
3\n\
	31\n\
	32\n\
	33\n\
		331\n\
4\n\
	41\
	"));

	m_tree0.use_custom_draw(use_custom_draw);
	m_tree0.set_as_shell_treectrl(&m_ShellImageList, true);
	m_tree1.set_as_shell_treectrl(&m_ShellImageList, true);
	m_tree0.use_drag_and_drop(true);
	m_tree1.use_drag_and_drop(true);

	logWrite(_T("5"));

	m_tree0.add_drag_images(IDB_DRAG_ONE_FILE, IDB_DRAG_MULTI_FILES);
	m_tree1.add_drag_images(IDB_DRAG_ONE_FILE, IDB_DRAG_MULTI_FILES);

	logWrite(_T("6"));

	m_tree0.select_folder(_T("C:\\"));
	m_tree1.select_folder(_T("c:\\"));

	logWrite(_T("7"));

	m_list_shell0.set_as_shell_listctrl();
	m_list_shell0.set_shell_imagelist(&m_ShellImageList);
	m_list_shell0.use_drag_and_drop(true);
	m_list_shell0.load_column_width(&theApp, _T("shell list0"));
	m_list_shell0.set_path(_T("C:\\"));
	m_list_shell0.add_drag_images(IDB_DRAG_ONE_FILE, IDB_DRAG_MULTI_FILES);

	logWrite(_T("8"));

	m_list_shell1.set_as_shell_listctrl();
	m_list_shell1.set_shell_imagelist(&m_ShellImageList);
	m_list_shell1.use_drag_and_drop(true);
	m_list_shell1.load_column_width(&theApp, _T("shell list1"));
	m_list_shell1.set_path(_T("c:\\"));
	m_list_shell1.add_drag_images(IDB_DRAG_ONE_FILE, IDB_DRAG_MULTI_FILES);

	logWrite(_T("9"));
	m_path0.set_shell_imagelist(&m_ShellImageList);
	m_path0.set_path(_T("C:\\"));

	m_path1.set_shell_imagelist(&m_ShellImageList);
	m_path1.set_path(_T("c:\\"));

	logWrite(_T("10"));
	//for test
	//m_path.add_remote_drive_volume(_T("로컬 디스크 (C:)"));

	//m_path.back_color(lightblue);
	//m_list_shell.set_path(_T("d:\\"));

	//CRect r(500, 20, 1500, 1000);
	//m_plist_shell = new CVtListCtrlEx();
	//m_plist_shell->Create(WS_CHILD | WS_BORDER | WS_VISIBLE, r, this, 7723);
	////DWORD dwStyle = m_plist_shell->GetStyle() & LVS_TYPEMASK;
	////m_plist_shell->ModifyStyle(LVS_TYPEMASK, dwStyle | LVS_REPORT | LVS_OWNERDRAWFIXED | LVS_OWNERDATA);
	//m_plist_shell->set_shell_list();
	//m_plist_shell->set_path(_T("C:\\"));


	//일반 ListCtrl의 초기설정
	init_list(&m_list);

	RestoreWindowPosition(&theApp, this);

	m_tree0.iterate_tree_with_no_recursion();

	logWrite(_T("11"));
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Ctest_vtlistctrlexDlg::init_list(CVtListCtrlEx* plist)
{
	plist->set_headings(_T("No,50;Name,150;Slogan,200;Score,100;Memo,200"));
	//m_list.set_color_theme(CVtListCtrlEx::color_theme_dark_gray);
	//m_list.set_line_height(theApp.GetProfileInt(_T("list name"), _T("line height"), 80));

	plist->set_font_size(theApp.GetProfileInt(_T("list"), _T("font size"), 9));
	plist->set_font_name(theApp.GetProfileString(_T("list"), _T("font name"), _T("맑은 고딕")));

	plist->load_column_width(&theApp, _T("list name"));
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

	//SetTimer(timer_add_data, 100, NULL);
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
		CPaintDC dc1(this);
		CRect rc;

		GetClientRect(rc);
		CMemoryDC dc(&dc1, &rc, false);

		//dc.FillSolidRect(rc, RGB(64, 64, 64));// ::GetSysColor(COLOR_3DFACE));
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
	//m_tree0.iterate_tree_with_no_recursion();
	m_tree0.iterate_tree();
	//m_list.set_line_height(40);
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
	m_list_shell0.save_column_width(&theApp, _T("shell list0"));

	CDialogEx::OnCancel();
}



BOOL Ctest_vtlistctrlexDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	return false;
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


void Ctest_vtlistctrlexDlg::OnLvnEndlabeleditListShell0(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMLVDISPINFO* pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int item = m_list_shell0.get_recent_edit_item();
	int subItem = m_list_shell0.get_recent_edit_subitem();
	CString	text = m_list_shell0.get_text(item, subItem);
	CString oldtext = m_list_shell0.get_old_text();
	CString oldfile;
	CString newfile;

	//변경된 내용이 없으면 리턴.
	if (text == oldtext)
		return;

	//파일명 외에는 변경할 수 없게 세팅되어 있으므로 굳이 체크하지 않아도 된다.
	//if (subItem != CVtListCtrlEx::col_filename)
	//	return;

	if (m_list_shell0.is_shell_listctrl())
	{ 
		oldfile.Format(_T("%ws\\%s"), m_list_shell0.get_path(), m_list_shell0.get_old_text());
		newfile.Format(_T("%ws\\%s"), m_list_shell0.get_path(), text);

		//local이면 직접 파일명을 rename하고
		if (m_list_shell0.is_shell_listctrl_local())
		{
			if (!MoveFile(oldfile, newfile))
			{
				get_last_error_string(true);
				m_list_shell0.set_text(item, subItem, oldtext);
				return;
			}
		}
		//remote라면 그 명령을 remote에 전달한다.
		else
		{

		}
	}


	*pResult = 0;
}

BOOL Ctest_vtlistctrlexDlg::PreTranslateMessage(MSG* pMsg)
{
	//이 코드를 넣어줘야 disabled에서도 툴팁이 동작하는데
	//이 코드를 컨트롤 클래스에 넣어줘도 소용없다.
	//이 코드는 main에 있어야 한다.
	//disabled가 아닌 경우는 잘 표시된다.
	if (m_tooltip.m_hWnd)
	{
		//msg를 따로 선언해서 사용하지 않고 *pMsg를 그대로 이용하면 이상한 현상이 발생한다.
		MSG msg = *pMsg;
		msg.hwnd = (HWND)m_tooltip.SendMessage(TTM_WINDOWFROMPOINT, 0, (LPARAM) & (msg.pt));

		CPoint pt = msg.pt;

		if (msg.message >= WM_MOUSEFIRST && msg.message <= WM_MOUSELAST)
			::ScreenToClient(msg.hwnd, &pt);

		msg.lParam = MAKELONG(pt.x, pt.y);

		// relay mouse event before deleting old tool 
		m_tooltip.SendMessage(TTM_RELAYEVENT, 0, (LPARAM)&msg);
	}

	switch (pMsg->message)
	{
		case WM_POWERBROADCAST :
			if (pMsg->wParam == PBT_APMSUSPEND)
			{
				AfxMessageBox(_T("WM_POWERBROADCAST -> PBT_APMSUSPEND"));
				return FALSE;
			}
			break;
		case WM_QUERYENDSESSION:
				AfxMessageBox(_T("Computer is shutting down"));
			if (pMsg->lParam == 0)
			{
				return FALSE;
			}
			else if ((pMsg->lParam & ENDSESSION_LOGOFF) == ENDSESSION_LOGOFF)
			{
				AfxMessageBox(_T("User is logging off"));
				return FALSE;
			}
			break;
		case WM_ENDSESSION :
			{
				AfxMessageBox(_T("WM_ENDSESSION"));
			}
	}

	/*
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
			//m_list.add_item(i2S(m_list.GetItemCount()));
			return true;
		}
	}
	*/

	return CDialogEx::PreTranslateMessage(pMsg);
}



void Ctest_vtlistctrlexDlg::OnLvnKeydownListShell0(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLVKEYDOWN pLVKeyDown = reinterpret_cast<LPNMLVKEYDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (pLVKeyDown->wVKey == VK_DELETE)
	{
		CString str;
		CString file;
		std::deque<int> dqSelected;

		m_list_shell0.get_selected_items(&dqSelected);

		if (dqSelected.size() == 1)
			str.Format(_T("선택된 항목을 삭제할까요?"));
		else
			str.Format(_T("선택된 %d개의 항목을 삭제할까요?"), dqSelected.size());

		if (AfxMessageBox(str, MB_ICONQUESTION | MB_YESNO) == IDNO)
			return;

		//file.Format(_T("%s\\%s"), m_list_shell.get_path(), )
		//local이라면 파일 삭제, 리스트 삭제하면 되고
		if (m_list_shell0.is_shell_listctrl_local())
		{
			m_list_shell0.delete_selected_items();
		}
		//remote라면 삭제 명령을 전달한다.
		else
		{

		}
	}

	*pResult = 0;
}


void Ctest_vtlistctrlexDlg::OnNMRClickListShell0(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void Ctest_vtlistctrlexDlg::OnNMDblclkListShell0(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int index = m_list_shell0.get_selected_index();
	
	if (index < 0 || index >= m_list_shell0.size())
		return;

	if (m_list_shell0.is_shell_listctrl())
	{
		if (m_list_shell0.is_shell_listctrl_local())
		{
			CString new_path;
			int csidl = m_ShellImageList.get_csidl_by_shell_known_string(m_list_shell0.get_path());
			if (csidl == CSIDL_DRIVES)
			{
				new_path = convert_special_folder_to_real_path(m_list_shell0.get_text(index, CVtListCtrlEx::col_filename),
																m_ShellImageList.get_csidl_map());
				m_list_shell0.set_path(new_path);
				m_path0.set_path(new_path);
				m_tree0.select_folder(new_path);
			}
			else
			{
				new_path = m_list_shell0.get_path() + _T("\\") + m_list_shell0.get_text(index, CVtListCtrlEx::col_filename);
				if (PathIsDirectory(new_path))
				{
					m_list_shell0.set_path(new_path);
					m_path0.set_path(new_path);
					m_tree0.select_folder(new_path);
				}
			}
		}
	}

	*pResult = 0;
}


void Ctest_vtlistctrlexDlg::OnNMDblclkListShell1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int index = m_list_shell1.get_selected_index();

	if (index < 0 || index >= m_list_shell1.size())
		return;

	if (m_list_shell1.is_shell_listctrl())
	{
		if (m_list_shell1.is_shell_listctrl_local())
		{
			CString new_path;
			int csidl = m_ShellImageList.get_csidl_by_shell_known_string(m_list_shell1.get_path());
			if (csidl == CSIDL_DRIVES)
			{
				new_path = convert_special_folder_to_real_path(m_list_shell1.get_text(index, CVtListCtrlEx::col_filename),
																m_ShellImageList.get_csidl_map());
				m_list_shell1.set_path(new_path);
				m_path1.set_path(new_path);
				m_tree1.select_folder(new_path);
			}
			else
			{
				new_path = m_list_shell1.get_path() + _T("\\") + m_list_shell1.get_text(index, CVtListCtrlEx::col_filename);
				if (PathIsDirectory(new_path))
				{
					m_list_shell1.set_path(new_path);
					m_path1.set_path(new_path);
					m_tree1.select_folder(new_path);
				}
			}
		}
	}

	*pResult = 0;
}

LRESULT	Ctest_vtlistctrlexDlg::on_message_pathctrl(WPARAM wParam, LPARAM lParam)
{
	CPathCtrlMessage* pMsg = (CPathCtrlMessage*)wParam;

	if (pMsg->pThis == &m_path0)
	{
		TRACE(_T("on_message_pathctrl from m_path0\n"));
		if (pMsg->message == CPathCtrl::message_pathctrl_path_changed)
		{
			m_list_shell0.set_path(pMsg->cur_path);// m_path0.get_full_path());
			m_tree0.select_folder(pMsg->cur_path);
		}
	}
	else if (pMsg->pThis == &m_path1)
	{
		TRACE(_T("on_message_pathctrl from m_path1\n"));
		if (pMsg->message == CPathCtrl::message_pathctrl_path_changed)
		{
			m_list_shell1.set_path(pMsg->cur_path);// m_path1.get_full_path());
			m_tree1.select_folder(pMsg->cur_path);
		}
	}

	return 0;
}

LRESULT	Ctest_vtlistctrlexDlg::on_message_vtlistctrlex(WPARAM wParam, LPARAM lParam)
{
	CVtListCtrlExMessage* msg = (CVtListCtrlExMessage*)wParam;

	if (msg->message == CVtListCtrlEx::message_drag_and_drop)
	{
		//다른 앱에서 드롭된 경우는 대상 컨트롤들에 남아있는 drophilited 항목들의 상태를 지워줘야 한다.
		//원래는 마지막 drophilited했던 컨트롤을 기억시켰다가 해당 컨트롤만 해줘야 한다.
		if (msg->pTarget == NULL)
		{
			m_list_shell0.set_items_state(0, LVIS_DROPHILITED);
			m_list_shell1.set_items_state(0, LVIS_DROPHILITED);
			m_tree0.SelectDropTarget(NULL);
			m_tree1.SelectDropTarget(NULL);
			return 0;
		}

		CString droppedItem;
		CVtListCtrlEx* pDragListCtrl = (CVtListCtrlEx*)msg->pThis;

		if (msg->pTarget->IsKindOf(RUNTIME_CLASS(CListCtrl)))
		{
			CVtListCtrlEx* pDropListCtrl = (CVtListCtrlEx*)msg->pTarget;

			int droppedIndex = pDragListCtrl->get_drop_index();

			if (droppedIndex >= 0)
				droppedItem = pDropListCtrl->get_text(droppedIndex, CVtListCtrlEx::col_filename);

			std::deque<int> dq;
			pDragListCtrl->get_selected_items(&dq);

			for (int i = 0; i < dq.size(); i++)
				TRACE(_T("dropped src %d = %s\n"), i, pDragListCtrl->get_text(dq[i], CVtListCtrlEx::col_filename));

			TRACE(_T("dropped on = %s\n"), droppedItem);



			//필요한 모든 처리가 끝나면 drophilited 표시를 없애준다.
			if (droppedIndex >= 0)
				pDropListCtrl->SetItemState(droppedIndex, 0, LVIS_DROPHILITED);
		}
		else if (msg->pTarget->IsKindOf(RUNTIME_CLASS(CTreeCtrl)))
		{
			CTreeCtrl* pDropTreeCtrl = (CTreeCtrl*)msg->pTarget;
			HTREEITEM hItem = pDropTreeCtrl->GetDropHilightItem();

			if (hItem)
			{
				droppedItem = pDropTreeCtrl->GetItemText(hItem);
				TRACE(_T("dropped on = %s\n"), droppedItem);



				//필요한 모든 처리가 끝나면 drophilited 표시를 없애준다.
				//pDropTreeCtrl->SetItemState(hItem, 0, TVIS_DROPHILITED);	<= 이걸로는 해제 안된다.
				pDropTreeCtrl->SelectDropTarget(NULL);
			}
		}
	}

	return 0;
}

LRESULT	Ctest_vtlistctrlexDlg::on_message_CSCTreeCtrl(WPARAM wParam, LPARAM lParam)
{
	CSCTreeCtrlMessage* msg = (CSCTreeCtrlMessage*)wParam;

	//drag_and_drop일 경우는 msg에 src, dst에 대한 모든 정보가 포함되어 있으므로
	//m_tree0 or m_tree1 어느 컨트롤이냐에 따라 처리할 필요는 없다.
	if (msg->message == CSCTreeCtrl::message_drag_and_drop)
	{
		CString droppedItem;
		CSCTreeCtrl* pDragTreeCtrl = (CSCTreeCtrl*)msg->pThis;

		if (msg->pTarget->IsKindOf(RUNTIME_CLASS(CListCtrl)))
		{
			CListCtrl* pDropListCtrl = (CListCtrl*)msg->pTarget;

			if (pDragTreeCtrl->m_nDropIndex >= 0)
				droppedItem = pDropListCtrl->GetItemText(pDragTreeCtrl->m_nDropIndex, 0);

			TRACE(_T("drag item = %s\n"), pDragTreeCtrl->GetItemText(pDragTreeCtrl->m_DragItem));
			TRACE(_T("dropped on = %s\n"), (droppedItem.IsEmpty() ? _T("dropped on ListCtrl") : droppedItem));

			//필요한 모든 처리가 끝나면 drophilited 표시를 없애준다.
			if (pDragTreeCtrl->m_nDropIndex >= 0)
				pDropListCtrl->SetItemState(pDragTreeCtrl->m_nDropIndex, 0, LVIS_DROPHILITED);
		}
		else if (msg->pTarget->IsKindOf(RUNTIME_CLASS(CTreeCtrl)))
		{
			CSCTreeCtrl* pDropTreeCtrl = (CSCTreeCtrl*)msg->pTarget;

			TRACE(_T("drag item = %s\n"), pDragTreeCtrl->GetItemText(pDragTreeCtrl->m_DragItem));
			TRACE(_T("dropped on = %s\n"), pDropTreeCtrl->GetItemText(pDragTreeCtrl->m_DropItem));

			//필요한 모든 처리가 끝나면 drophilited 표시를 없애준다.
			//pDropTreeCtrl->SetItemState(hItem, 0, TVIS_DROPHILITED);	<= 이걸로는 해제 안된다.
			pDropTreeCtrl->SelectDropTarget(NULL);
		}

		return 0;
	}
	else if (msg->message == CSCTreeCtrl::message_selchanged)
	{
		CString path = *(CString*)lParam;

		//AfxMessageBox(path);
		
		if (msg->pThis == &m_tree0)
		{
			m_list_shell0.set_path(path);
			m_path0.set_path(path);
		}
		else if (msg->pThis == &m_tree1)
		{
			m_list_shell1.set_path(path);
			m_path1.set_path(path);
		}

		//AfxMessageBox(_T("set_path end"));
	}

	return 0;
}

void Ctest_vtlistctrlexDlg::OnCbnSelchangeComboColorTheme()
{
	int index = m_combo_color_theme.GetCurSel();

	if (index < 0 || index >= m_combo_color_theme.GetCount())
		return;

	m_list.set_color_theme(index);

	m_tree0.set_color_theme(index);
	m_list_shell0.set_color_theme(index);

	m_tree1.set_color_theme(index);
	m_list_shell1.set_color_theme(index);
}


BOOL Ctest_vtlistctrlexDlg::OnQueryEndSession()
{
	if (!CDialogEx::OnQueryEndSession())
		return FALSE;

	// TODO:  여기에 특수화된 쿼리 종료 세션 코드를 추가합니다.
	ShutdownBlockReasonCreate(m_hWnd, CStringW("프로그램을 안전종료중입니다..."));

	AfxMessageBox(_T("OnQueryEndSession"));

	ShutdownBlockReasonDestroy(m_hWnd);

	return TRUE;
}


void Ctest_vtlistctrlexDlg::OnEndSession(BOOL bEnding)
{
	CDialogEx::OnEndSession(bEnding);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	AfxMessageBox(_T("OnEndSession"));
}


void Ctest_vtlistctrlexDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == timer_add_data)
	{
		int index = m_list.add_item(i2S(m_list.size()));
		m_list.set_text(index, list_name, RandomText::GetName());
		//m_list.set_text_color(index, 0, RGB(index, index, index));//random19937(RGB(0,0,0), RGB(255,255,255)));
		m_list.set_text(index, list_slogan, RandomText::GetSlogan());
		//m_list.set_text_color(index, index, RGB(indexi, 0, 0));//random19937(RGB(0,0,0), RGB(255,255,255)));
		m_list.set_text(index, list_score, i2S(random19937(0, 100)));
		//m_list.set_text_color(index, 2, RGB(0, 0, 255-index));//random19937(RGB(0,0,0), RGB(255,255,255)));
		m_list.set_text(index, list_memo, RandomText::GetName());
	}

	CDialogEx::OnTimer(nIDEvent);
}


void Ctest_vtlistctrlexDlg::OnTvnBeginlabelEditTree0(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTVDISPINFO pTVDispInfo = reinterpret_cast<LPNMTVDISPINFO>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	TRACE(_T("%s\n"), __function__);
	*pResult = 0;
}


void Ctest_vtlistctrlexDlg::OnTvnEndlabelEditTree0(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTVDISPINFO pTVDispInfo = reinterpret_cast<LPNMTVDISPINFO>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	TRACE(_T("%s\n"), __function__);
	*pResult = 0;
}


void Ctest_vtlistctrlexDlg::OnTvnBeginlabelEditTree1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTVDISPINFO pTVDispInfo = reinterpret_cast<LPNMTVDISPINFO>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	TRACE(_T("%s\n"), __function__);
	*pResult = 0;
}


void Ctest_vtlistctrlexDlg::OnTvnEndlabelEditTree1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTVDISPINFO pTVDispInfo = reinterpret_cast<LPNMTVDISPINFO>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	TRACE(_T("%s\n"), __function__);
	*pResult = 0;
}


void Ctest_vtlistctrlexDlg::OnTvnSelchangedTree0(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString path = m_tree0.get_fullpath(m_tree0.GetSelectedItem());

	m_list_shell0.set_path(path);
	m_path0.set_path(path);

	*pResult = 0;
}


void Ctest_vtlistctrlexDlg::OnTvnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}
