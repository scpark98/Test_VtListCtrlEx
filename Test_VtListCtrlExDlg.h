
// test_vtlistctrlexDlg.h : header file
//

#pragma once
#include "afxcmn.h"

#include <deque>

//#include "list_data.h"

#include "../../Common/Functions.h"
#include "../../Common/MemoryDC.h"
#include "../../Common/ResizeCtrl.h"
#include "../../Common/CListCtrl/CVtListCtrlEx/VtListCtrlEx.h"

// Ctest_vtlistctrlexDlg dialog
class Ctest_vtlistctrlexDlg : public CDialogEx
{
// Construction
public:
	Ctest_vtlistctrlexDlg(CWnd* pParent = NULL);	// standard constructor

													//This is the database we using
	//std::deque<CListData> m_list_db;
	CResizeCtrl		m_resize;

	void			init_list(CVtListCtrlEx* plist);

	enum list_column
	{
		list_no = 0,
		list_name,
		list_slogan,
		list_score,
		list_memo,
	};

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_VTLISTCTRLEX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CVtListCtrlEx m_list;
	CVtListCtrlEx m_list_shell;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg void OnLvnEndlabeleditList(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
