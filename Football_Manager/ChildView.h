
// ChildView.h : interface of the CChildView class
//
#include<vector>
#include "Player.h"
#include "Tactic.h"

#pragma once

// CChildView window

class CChildView : public CWnd
{
// Construction
	
	
public:
	CChildView();

	std::vector<Tactic>tacticList;
	Tactic currentTactic;
// Attributes

public:

	COLORREF col = RGB(0,0,0);
	LOGFONT lf;
	int tactic = 1;
	int out = 20;
	POINT mouseP;
	BOOL init=false;
	CRect rct, rect;
	BOOL gk = false;
	int pIndex = -1;
// Operations
public:
	void calcPlayers();
	void InitPlayers442();
	void addToMenu(CString name, int id);
	void SaveTactic();
	bool GetFont(LOGFONT& lf, COLORREF& col);
	void RemoveMenu(CString name);
	void deleteTactic(Tactic tak);
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
	afx_msg BOOL OnEraseBkgnd(CDC * pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT flags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	afx_msg void OnTactic442();
	afx_msg void OnOptionsSavetactic();
	afx_msg void SettingsFont();
	afx_msg void OnOptionsDeletetactic();
	DECLARE_MESSAGE_MAP()
public:
	
	


	
};


