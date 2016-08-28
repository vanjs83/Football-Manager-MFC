
// ChildView.h : interface of the CChildView class
//
#include<fstream>
#include "Player.h"
#include "Tactic.h"

#pragma once

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
	int out = 20;
	Player players[11];
	POINT mouseP;
	BOOL mouseButtonPress;
	BOOL init=false;
	CRect rct, rect;
// Operations
public:
	void InitPlayers442();
	void addToMenu(CString name, int id);
	void SaveTactic();
// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void ReadTaktike();
// Implementation
public:
	virtual ~CChildView();
	int FindMenuItem(CMenu * Menu, LPCTSTR MenuString);
	void OnMenuClick(UINT nID);
	// Generated message map functions
protected:
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT flags, CPoint point);
	afx_msg void OnTactic442();
	afx_msg void OnOptionsSavetactic();
	DECLARE_MESSAGE_MAP()
public:
	
	

};

