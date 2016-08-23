
// ChildView.h : interface of the CChildView class
//


#pragma once
#include "Player.h"

// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:
	int tactic = 1;
	Player players[11];
	POINT mouseP;
	BOOL mouseButtonPress;


// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	BOOL PreTranslateMessage(MSG * pMsg);
	
	void OnSize(UINT nType, int cx, int cy);
	void InitPlayers442();

	void InitPlayers352();

	void InitPlayers451();

	void InitPlayers433();

	void InitPlayers343();

	void InitPlayers4231();

	void InitPlayers3331();

	void InitPlayers532();

	void InitPlayers541();

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTactic442();
	afx_msg void OnTactic451();
	afx_msg void OnTactic433();
	afx_msg void OnTactic4231();
	afx_msg void OnTactic3331();
	afx_msg void OnTactic343();
	afx_msg void OnTactic352();
	afx_msg void OnTactic532();
	afx_msg void OnTactic541();
};

