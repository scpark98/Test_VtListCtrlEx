
// test_vtlistctrlex.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Ctest_vtlistctrlexApp:
// See test_vtlistctrlex.cpp for the implementation of this class
//

class Ctest_vtlistctrlexApp : public CWinApp
{
public:
	Ctest_vtlistctrlexApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Ctest_vtlistctrlexApp theApp;