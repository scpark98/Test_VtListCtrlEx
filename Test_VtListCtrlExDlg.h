
// test_vtlistctrlexDlg.h : header file
//

#pragma once
//#include "afxcmn.h"

#include <deque>

//#include "list_data.h"

#include "../../Common/Functions.h"
#include "../../Common/MemoryDC.h"
#include "../../Common/ResizeCtrl.h"
#include "../../Common/CTreeCtrl/TreeCtrlEx.h"
#include "../../Common/CListCtrl/CVtListCtrlEx/VtListCtrlEx.h"
#include "../../Common/CStatic/PathCtrl/PathCtrl.h"
#include "../../Common/system/ShellImageList/ShellImageList.h"

// Ctest_vtlistctrlexDlg dialog
class Ctest_vtlistctrlexDlg : public CDialogEx
{
// Construction
public:
	Ctest_vtlistctrlexDlg(CWnd* pParent = NULL);	// standard constructor
	CResizeCtrl		m_resize;

	CVtListCtrlEx*	m_plist_shell = NULL;

	void			init_list(CVtListCtrlEx* plist);

	enum list_column
	{
		list_no = 0,
		list_name,
		list_slogan,
		list_score,
		list_memo,
	};

	LRESULT			on_message_vtlistctrlex(WPARAM wParam, LPARAM lParam);
	LRESULT			on_message_pathctrl(WPARAM wParam, LPARAM lParam);
	LRESULT			on_message_treectrlex(WPARAM wParam, LPARAM lParam);

	//Shell의 imagelist 및 shell과 관계된 멤버 제공
	CShellImageList		m_ShellImageList;

protected:
	CToolTipCtrl	m_tooltip;

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
	CPathCtrl m_path0;
	CPathCtrl m_path1;
	CVtListCtrlEx m_list;
	CTreeCtrlEx m_tree0;
	CTreeCtrlEx m_tree1;
	CVtListCtrlEx m_list_shell0;
	CVtListCtrlEx m_list_shell1;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnLvnEndlabeleditListShell0(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLvnKeydownListShell0(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMRClickListShell0(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMDblclkListShell0(NMHDR* pNMHDR, LRESULT* pResult);
	//afx_msg void OnLvnBegindragListShell0(NMHDR* pNMHDR, LRESULT* pResult);
	//afx_msg void OnLvnBegindragListShell1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMDblclkListShell1(NMHDR* pNMHDR, LRESULT* pResult);
};
