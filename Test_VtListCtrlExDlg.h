
// test_vtlistctrlexDlg.h : header file
//

#pragma once
//#include "afxcmn.h"

#include <deque>

//#include "list_data.h"

#include "../../Common/Functions.h"
#include "../../Common/MemoryDC.h"
#include "../../Common/ResizeCtrl.h"
#include "../../Common/CTreeCtrl/SCTreeCtrl/SCTreeCtrl.h"
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

	void			init_list();

	enum list_column
	{
		col_no = 0,
		col_name,
		col_slogan,
		col_score,
		col_memo,
	};

	LRESULT			on_message_CVtListCtrlEx(WPARAM wParam, LPARAM lParam);
	LRESULT			on_message_CPathCtrl(WPARAM wParam, LPARAM lParam);
	LRESULT			on_message_CSCTreeCtrl(WPARAM wParam, LPARAM lParam);

	//Shell의 imagelist 및 shell과 관계된 멤버 제공
	CShellImageList		m_shell_imagelist;

protected:
	CToolTipCtrl	m_tooltip;

	enum TIMER_ID
	{
		timer_add_test_data = 0,
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
	CPathCtrl m_path0;
	CPathCtrl m_path1;
	CVtListCtrlEx m_list;
	CSCTreeCtrl m_tree;
	CSCTreeCtrl m_tree0;
	CSCTreeCtrl m_tree1;
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
	CComboBox m_combo_color_theme;
	afx_msg void OnCbnSelchangeComboColorTheme();
	afx_msg BOOL OnQueryEndSession();
	afx_msg void OnEndSession(BOOL bEnding);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnTvnBeginlabelEditTree0(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTvnEndlabelEditTree0(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTvnBeginlabelEditTree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTvnEndlabelEditTree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTvnSelchangedTree0(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTvnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLvnItemchangedList(NMHDR* pNMHDR, LRESULT* pResult);
};
