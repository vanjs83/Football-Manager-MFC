
// Football_Manager.h : main header file for the Football_Manager application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CFootball_ManagerApp:
// See Football_Manager.cpp for the implementation of this class
//

class CFootball_ManagerApp : public CWinApp
{
public:
	CFootball_ManagerApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFootball_ManagerApp theApp;
