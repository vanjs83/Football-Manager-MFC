
// ChildView.cpp : implementation of the CChildView class
#include<iostream>
#include<fstream>
#include<cstdio>
#include "stdafx.h"
#include "Football_Manager.h"
#include "ChildView.h"
#include "askDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#define ID_MENUSHOW   2000
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_COMMAND(ID_TACTIC_4, &CChildView::OnTactic442)
	ON_COMMAND(ID_OPTIONS_SAVETACTIC, &CChildView::OnOptionsSavetactic)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);
	ReadTaktike();
	return TRUE;
}
void CChildView::OnMouseMove(UINT flags, CPoint point)
{
	// see large comment in previous function
	mouseButtonPress = false;
	if ((GetKeyState(VK_LBUTTON) & 0x100) != 0) {
		mouseP.x = point.x;
		mouseP.y = point.y;
		mouseButtonPress = true;
		Invalidate();
		UpdateWindow();
	}

}

void CChildView::OnSize(UINT nType, int cx, int cy)
{
		
		if (!init)
			InitPlayers442();

}

void CChildView::InitPlayers442() {
	//int out = 20;
	//CRect rct;
	GetClientRect(&rect);
	players[0].position = _T("GK");
	players[1].position = _T("DL");
	players[2].position = _T("DR");
	players[3].position = _T("CB");
	players[4].position = _T("CB");
	players[5].position = _T("MR");
	players[6].position = _T("ML");
	players[7].position = _T("MC");
	players[8].position = _T("MC");
	players[9].position = _T("FC");
	players[10].position = _T("FC");
	//
	//crtanje obrane
	players[0].x = out;//gk
	players[0].y = rect.Height() / 2 - out;
	players[1].x = rect.Width() / 4;//DR
	players[1].y = rect.Height() / 5 * 4;
	players[2].x = rect.Width() / 4;//DL
	players[2].y = rect.Height() / 5;
	players[3].x = rect.Width() / 4;//CB
	players[3].y = rect.Height() / 5 * 2;
	players[4].x = rect.Width() / 4;//CB
	players[4].y = rect.Height() / 5 * 3;
	//crtanje veze
	players[5].x = rect.Width() / 4 * 2;//MR
	players[5].y = rect.Height() / 5 * 4;
	players[6].x = rect.Width() / 4 * 2;//ML
	players[6].y = rect.Height() / 5;
	players[7].x = rect.Width() / 4 * 2;//MC
	players[7].y = rect.Height() / 5 * 2;
	players[8].x = rect.Width() / 4 * 2;//MC
	players[8].y = rect.Height() / 5 * 3;
	//crtanje napada
	players[9].x = rect.Width() / 4 * 3;//FC
	players[9].y = rect.Height() / 5 * 2;
	players[10].x = rect.Width() / 4 * 3;//FC
	players[10].y = rect.Height() / 5 * 3;
	// relative rx, ry
	for (int i = 0; i < 11; i++) {
		players[i].rx = players[i].x / rect.Width();
		players[i].ry = players[i].y / rect.Height();
	}

}


void CChildView::OnPaint()
{  
	
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	//int out = 20;
	//CRect rct;
	GetClientRect(&rct);
	CDC* dcc = this->GetDC();//get window
	CBrush brushGreen(RGB(0, 128, 0));//brush
	dcc->SelectObject(brushGreen); //select brush tool
	dcc->Rectangle(0, 0, rct.right, rct.bottom);//draw rectangle

	CPen* newPen = new CPen(PS_SOLID | PS_GEOMETRIC, 3, RGB(255, 255, 255));
	CPen* pOldPen = dcc->SelectObject(newPen);//select pen
											  
    //crtanje okvira
	dcc->MoveTo(out, out); //krajnja točka
	dcc->LineTo(out, rct.bottom - out);//početna točka

	dcc->MoveTo(out, out);
	dcc->LineTo(rct.right - out, out);

	dcc->MoveTo(rct.right - out, out);
	dcc->LineTo(rct.right - out, rct.bottom - out);

	dcc->MoveTo(out, rct.bottom - out);
	dcc->LineTo(rct.right - out, rct.bottom - out);

	//crtanje kruga
	dcc->Ellipse(rct.right / 3 + out, rct.bottom / 4, rct.right / 3 * 2 - out, rct.bottom / 4 * 3);

	dcc->MoveTo((rct.right - out + out) / 2, out);
	dcc->LineTo((rct.right - out + out) / 2, rct.bottom - out);

	//crtanje lijevog gola
	dcc->MoveTo(out, rct.bottom / 10 * 4);
	dcc->LineTo(out + rct.right / 30, rct.bottom / 10 * 4);
	dcc->LineTo(out + rct.right / 30, rct.bottom / 10 * 6);
	dcc->LineTo(out, rct.bottom / 10 * 6);

	//crtanje desnog gola
	dcc->MoveTo(rct.right - out, rct.bottom / 10 * 4);
	dcc->LineTo(rct.right / 30 * 29, rct.bottom / 10 * 4);
	dcc->LineTo(rct.right / 30 * 29, rct.bottom / 10 * 6);
	dcc->LineTo(rct.right - out, rct.bottom / 10 * 6);
	//crtanje lijevog šesnajsterca
	dcc->MoveTo(out, rct.bottom / 10 * 2);
	dcc->LineTo(out + rct.right / 8, rct.bottom / 10 * 2);
	dcc->LineTo(out + rct.right / 8, rct.bottom / 10 * 8);
	dcc->LineTo(out, rct.bottom / 10 * 8);
	//crtanje desnog šesnajsterca
	dcc->MoveTo(rct.right - out, rct.bottom / 10 * 2);
	dcc->LineTo(rct.right / 8 * 7 - out, rct.bottom / 10 * 2);
	dcc->LineTo(rct.right / 8 * 7 - out, rct.bottom / 10 * 8);
	dcc->LineTo(rct.right - out, rct.bottom / 10 * 8);
	//lijeva tocka za penal
	dcc->MoveTo(rct.right / 30 * 3, rct.bottom / 2);
	dcc->LineTo(rct.right / 30 * 3, rct.bottom / 2);
	//desna tocka za penal
	dcc->MoveTo(rct.right / 30 * 28 - out, rct.bottom / 2);
	dcc->LineTo(rct.right / 30 * 28 - out, rct.bottom / 2);
	// TODO: Add your message handler code here

	// Do not call CWnd::OnPaint() for painting messages
	BOOL b = false;

	//crtanje igraca na terenu!!
	for (int i = 0; i < 11; i++) {
		//calc relative
		players[i].x = rct.Width() * players[i].rx;
		players[i].y = rct.Height() * players[i].ry;
		//
		if (mouseButtonPress)
			if (mouseP.x + out >= players[i].x && mouseP.x <= players[i].x + out)
				if (mouseP.y + out >= players[i].y && mouseP.y <= players[i].y + out)
				{
					if (!b)
					{
						players[i].x = mouseP.x;
						players[i].y = mouseP.y;
						players[i].rx = players[i].x / rct.Width();
						players[i].ry = players[i].y / rct.Height();
						//
						init = true;
						b = true;
					}
				}

		if (players[i].x <= rct.Width() / 7)
		{
			players[i].position = _T("GK");
		}
		else if (players[i].x >= rct.Width() / 7 && players[i].x <= rct.Width() / 7 * 2) {

			players[i].position = _T("CB");
			if (players[i].y <= rct.Height() / 5)
				players[i].position = _T("DL");
			if (players[i].y >= rct.Height() / 5 * 4)
				players[i].position = _T("DR");
		}
		else if (players[i].x >= rct.Width() / 7 * 2 && players[i].x <= rct.Width() / 7 * 4) {

			players[i].position = _T("MC");
			if (players[i].y <= rct.Height() / 5)
				players[i].position = _T("ML");
			if (players[i].y >= rct.Height() / 5 * 4)
				players[i].position = _T("MR");
		}
		else if (players[i].x >= rct.Width() / 7 * 4 && players[i].x <= rct.Width() / 7 * 5) {
			players[i].position = _T("AMC");
			if (players[i].y <= rct.Height() / 5 * 2)
				players[i].position = _T("AML");
			if (players[i].y >= rct.Height() / 5 * 3)
				players[i].position = _T("AMR");
		}

		//else if (players[i].x >= rct.Width() / 7 * 6) {
		else{
			players[i].position = _T("FC");
			if (players[i].y <= rct.Height() / 5 )
				players[i].position = _T("LFC");
			if (players[i].y >= rct.Height() / 5 * 4)
				players[i].position = _T("RFC");

		}
	
		dcc->SetTextAlign(TA_CENTER);
		dcc->SetBkMode(TMT_TRANSPARENT);
		dcc->TextOutW(players[i].x, players[i].y , players[i].position);
		// Do not call CWnd::OnPaint() for painting messages
	}
	
}


	void CChildView::OnTactic442()
	{
		// TODO: Add your command handler code here
		MessageBox(_T("4:4:2"),_T("Tactic"));
		tactic =1;
		InitPlayers442();
		Invalidate();
		UpdateWindow();
	}

	

	void CChildView::SaveTactic()
	{
		//Pisi
		
		CStdioFile ffile;
		TCHAR szPath[MAX_PATH];
		if (SUCCEEDED(SHGetFolderPath(NULL,
			CSIDL_PERSONAL | CSIDL_FLAG_CREATE,
			NULL, 0,  szPath)))
		{
			PathAppend(szPath, TEXT("file.bin"));
			if (ffile.Open(szPath, CFile::modeCreate | CFile::modeWrite | CFile::typeText))
			{
				POSITION takListPos = tacticList.GetHeadPosition();
				while (takListPos != NULL)
				{
					Tactic tak = tacticList.GetNext(takListPos);
					CString str;
					str.Format(L"%s\n", tak.name);
					ffile.WriteString(str);
					for (int i = 0; i < 11; i++) {

						str.Format(L"%s\n", tak.player[i].position);
						ffile.WriteString(str);
						str.Format(L"%g\n", tak.player[i].x);
						ffile.WriteString(str);
						str.Format(L"%g\n", tak.player[i].y);
						ffile.WriteString(str);
						str.Format(L"%g\n", tak.player[i].rx);
						ffile.WriteString(str);
						str.Format(L"%g\n", tak.player[i].ry);
						ffile.WriteString(str);
					}
				}
				ffile.Close();
			}
		}
	}



	void CChildView::addToMenu(CString name, int id)
	{

		// Get the menu from the application window.
		CMenu* mmenu = AfxGetMainWnd()->GetMenu();
		int pos = FindMenuItem(mmenu, _T("Tactic"));
		CMenu* submenu = mmenu->GetSubMenu(pos);
		UINT mid = submenu->GetMenuItemID(pos);
		if (pos == -1)
			return;
		submenu->AppendMenu(MF_ENABLED | MF_STRING, ID_MENUSHOW + id, name);
	}



	int CChildView::FindMenuItem(CMenu* Menu, LPCTSTR MenuString)
	{
		ASSERT(Menu);
		ASSERT(::IsMenu(Menu->GetSafeHmenu()));

		int count = Menu->GetMenuItemCount();
		for (int i = 0; i < count; i++)
		{
			CString str;
			if (Menu->GetMenuString(i, str, MF_BYPOSITION) && str.Compare(MenuString) == 0)
				return i;
		}
		return -1;
	}



	void CChildView::ReadTaktike()
	{
	
		//citaj
		tacticList.RemoveAll();
		CStdioFile ffile;
		TCHAR szPath[MAX_PATH];
		if (SUCCEEDED(SHGetFolderPath(NULL,
			CSIDL_PERSONAL | CSIDL_FLAG_CREATE,
			NULL,
			0,
			szPath)))
		{
			PathAppend(szPath, TEXT("file.bin"));
			if (ffile.Open(szPath, CFile::modeRead | CFile::typeText))
			{
				Tactic tc;
				CString str;
				while (ffile.ReadString(tc.name))
				{
					for (int i = 0; i < 11; i++) {
						ffile.ReadString(tc.player[i].position);
						ffile.ReadString(str);

						tc.player[i].x = _wtof(str);
						ffile.ReadString(str);

						tc.player[i].y = _wtof(str);
						ffile.ReadString(str);

						tc.player[i].rx = _wtof(str);
						ffile.ReadString(str);

						tc.player[i].ry = _wtof(str);
						ffile.ReadString(str);
					}
					addToMenu(tc.name, tacticList.GetCount());
					tacticList.AddTail(tc);
	
				}
				ffile.Close();
			}
		}
	}



	void CChildView::OnOptionsSavetactic()
	{
		// TODO: Add your command handler code here
		askDialog dialog;
		if (dialog.DoModal() == IDOK)
		{
			Tactic tak;
			tak.name=dialog.EditValue;
			for (int i = 0; i < 11; i++) {
				// relative rx, ry
				players[i].rx = players[i].x / rct.Width();
				players[i].ry = players[i].y / rct.Height();
				tak.player[i] = players[i];
			}
			addToMenu(tak.name, tacticList.GetCount());
			tacticList.AddTail(tak);
			SaveTactic();
		}
	}

	void CChildView::OnMenuClick(UINT nID)
	{
		int id = ID_MENUSHOW;
		POSITION takListPos = tacticList.GetHeadPosition();
		while (takListPos != NULL)
		{
			Tactic tak = tacticList.GetNext(takListPos);
			if (nID == id)
			{
				for (int i = 0; i < 11; i++) {
					players[i] = tak.player[i];
				}
				Invalidate();
				UpdateWindow();
				return;
			}
			id++;
		}
	}