
// ChildView.h : interface of the CChildView class
//


#pragma once
#include<fstream>
#include "Player.h"
#include "Tactic.h"
// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();
	CList<Tactic, Tactic>tacticList;
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
	void InitPlayers442();
// Implementation
public:
	virtual ~CChildView();
	// Generated message map functions
protected:
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT flags, CPoint point);
	afx_msg void OnTactic442();
	afx_msg void OnOptionsSavetactic();
	DECLARE_MESSAGE_MAP()
public:
	
	void SaveTactic();
	void addToMenu(CString name, int id);
	int FindMenuItem(CMenu * Menu, LPCTSTR MenuString);
	void ReadTaktike();

	void OnMenuClick(UINT nID);
};

