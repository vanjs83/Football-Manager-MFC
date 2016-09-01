
// ChildView.cpp : implementation of the CChildView class

#include "stdafx.h"
#include "Football_Manager.h"
#include "ChildView.h"
#include "askDialog.h"
#include <afxwin.h>
#include <string>
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define ID_MENUSHOW   2000

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
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_TACTIC_4, &CChildView::OnTactic442)
	ON_COMMAND(ID_OPTIONS_SAVETACTIC, &CChildView::OnOptionsSavetactic)
	ON_COMMAND(ID_SETTINGS_FONT, &CChildView::SettingsFont)
	ON_COMMAND(ID_OPTIONS_DELETETACTIC32798, &CChildView::OnOptionsDeletetactic)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	return false;
}

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
	//CRect rect;
	GetClientRect(&rect);
	currentTactic.name = _T("4:4:2");
	currentTactic.player[0].position = _T("GK");
	currentTactic.player[1].position = _T("DL");
	currentTactic.player[2].position = _T("DR");
	currentTactic.player[3].position = _T("CB");
	currentTactic.player[4].position = _T("CB");
	currentTactic.player[5].position = _T("MR");
	currentTactic.player[6].position = _T("ML");
	currentTactic.player[7].position = _T("MC");
	currentTactic.player[8].position = _T("MC");
	currentTactic.player[9].position = _T("FC");
	currentTactic.player[10].position = _T("FC");
	//
	//crtanje obrane
	currentTactic.player[0].x = out;//gk
	currentTactic.player[0].y = rect.Height() / 2 - out;
	currentTactic.player[1].x = rect.Width() / 4;//DR
	currentTactic.player[1].y = rect.Height() / 5 * 4;
	currentTactic.player[2].x = rect.Width() / 4;//DL
	currentTactic.player[2].y = rect.Height() / 5;
	currentTactic.player[3].x = rect.Width() / 4;//CB
	currentTactic.player[3].y = rect.Height() / 5 * 2;
	currentTactic.player[4].x = rect.Width() / 4;//CB
	currentTactic.player[4].y = rect.Height() / 5 * 3;
	//crtanje veze
	currentTactic.player[5].x = rect.Width() / 4 * 2;//MR
	currentTactic.player[5].y = rect.Height() / 5 * 4;
	currentTactic.player[6].x = rect.Width() / 4 * 2;//ML
	currentTactic.player[6].y = rect.Height() / 5;
	currentTactic.player[7].x = rect.Width() / 4 * 2;//MC
	currentTactic.player[7].y = rect.Height() / 5 * 2;
	currentTactic.player[8].x = rect.Width() / 4 * 2;//MC
	currentTactic.player[8].y = rect.Height() / 5 * 3;
	//crtanje napada
	currentTactic.player[9].x = rect.Width() / 4 * 3;//FC
	currentTactic.player[9].y = rect.Height() / 5 * 2;
	currentTactic.player[10].x = rect.Width() / 4 * 3;//FC
	currentTactic.player[10].y = rect.Height() / 5 * 3;

	// relative rx, ry
	for (int i = 0; i < 11; i++) {
		currentTactic.player[i].rx = currentTactic.player[i].x / rect.Width();
		currentTactic.player[i].ry = currentTactic.player[i].y / rect.Height();
	}

}

  
void CChildView::OnPaint()
{  
	
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	
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

	//crtanje lijevog prostora gola
	dcc->MoveTo(out, rct.bottom / 10 * 4);
	dcc->LineTo(out + rct.right / 30, rct.bottom / 10 * 4);
	dcc->LineTo(out + rct.right / 30, rct.bottom / 10 * 6);
	dcc->LineTo(out, rct.bottom / 10 * 6);

	//crtanje desnog prostora za gol
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

	//lijevi gol
	dcc->MoveTo(out, rct.bottom / 18 * 8);
	dcc->LineTo(out / 2, rct.bottom / 18 * 8);
	dcc->LineTo(out / 2, rct.bottom / 18 * 10);
	dcc->LineTo(out, rct.bottom / 18 * 10);

	//desni gol
	dcc->MoveTo(rct.Width() - out, rct.bottom / 18 * 8);
	dcc->LineTo(rct.Width() - out / 2, rct.bottom / 18 * 8);
	dcc->LineTo(rct.Width() - out / 2, rct.bottom / 18 * 10);
	dcc->LineTo(rct.Width() - out, rct.bottom / 18 * 10);

	
	// TODO: Add your message handler code here

	// Do not call CWnd::OnPaint() for painting messages
	BOOL b = false;
	     gk = false;
	//crtanje igraca na terenu!!
	
	for (int i = 0; i < 11; i++) {

		//calc relative
		currentTactic.player[i].x = rct.Width() * currentTactic.player[i].rx;
		currentTactic.player[i].y = rct.Height() * currentTactic.player[i].ry;
		//
		if (mouseButtonPress)
			if (mouseP.x + out >= currentTactic.player[i].x && mouseP.x <= currentTactic.player[i].x + out)
				if (mouseP.y + out >= currentTactic.player[i].y && mouseP.y <= currentTactic.player[i].y + out)
				{
					if (!b)
					{
						currentTactic.player[i].x = mouseP.x;
						currentTactic.player[i].y = mouseP.y;
						currentTactic.player[i].rx = currentTactic.player[i].x / rct.Width();
						currentTactic.player[i].ry = currentTactic.player[i].y / rct.Height();
						//
						init = true;
						b = true;
					}
				}

		if (currentTactic.player[i].x < out) //ne daj igracima izvan terena
			currentTactic.player[i].x = out;

		else if (currentTactic.player[i].x > rct.Width() - out)
			currentTactic.player[i].x = rct.Width() - 2* out;

		else if (currentTactic.player[i].y < out)
			currentTactic.player[i].y = out;

		else if (currentTactic.player[i].y > rct.Height() - out)
			currentTactic.player[i].y = rct.Height() - 2 * out;
		
		
		
		        //CB
			 if (currentTactic.player[i].x >= rct.Width() / 7 && currentTactic.player[i].x <= rct.Width() / 7 * 2 ) {

				currentTactic.player[i].position = _T("CB");
				if (currentTactic.player[i].y <= rct.Height() / 5 )
					currentTactic.player[i].position = _T("DL");
				if (currentTactic.player[i].y >= rct.Height() / 5 * 4 )
					currentTactic.player[i].position = _T("DR");
			}
			 //MC
			else if (currentTactic.player[i].x >= rct.Width() / 7 * 2 && currentTactic.player[i].x <= rct.Width() / 7 * 4) {

				currentTactic.player[i].position = _T("MC");
				if (currentTactic.player[i].y <= rct.Height() / 5)
					currentTactic.player[i].position = _T("ML");
				if (currentTactic.player[i].y >= rct.Height() / 5 * 4)
					currentTactic.player[i].position = _T("MR");
			}
			//AMF
			else if (currentTactic.player[i].x >= rct.Width() / 7 * 4 && currentTactic.player[i].x <= rct.Width() / 7 * 5) {
				currentTactic.player[i].position = _T("AMC");
				if (currentTactic.player[i].y <= rct.Height() / 5 * 2)
					currentTactic.player[i].position = _T("AML");
				if (currentTactic.player[i].y >= rct.Height() / 5 * 3)
					currentTactic.player[i].position = _T("AMR");
			}
			//FC
			else if (currentTactic.player[i].x >= rct.Width() / 7 * 5) {
		 
				currentTactic.player[i].position = _T("FC");
				if (currentTactic.player[i].y <= rct.Height() / 5)
					currentTactic.player[i].position = _T("LFC");
				if (currentTactic.player[i].y >= rct.Height() / 5 * 4)
					currentTactic.player[i].position = _T("RFC");

			}
			//GK
			if (currentTactic.player[i].x <= rct.Width() / 7)
			{
				if (!gk)
				{
					currentTactic.player[i].position = _T("GK");
					gk = true;
				}
			}

			if (!fontL)fontL = dcc->GetCurrentFont();
			CFont* def_font = dcc->SelectObject(fontL);
			
			dcc->SetTextColor(col);
			dcc->SetTextAlign(TA_LEFT);
			dcc->SetBkMode(TMT_TRANSPARENT);
			dcc->TextOutW(currentTactic.player[i].x, currentTactic.player[i].y, currentTactic.player[i].position);
			dcc->SelectObject(def_font);
			// Do not call CWnd::OnPaint() for painting messages
		}

	DeleteObject(brushGreen);
	DeleteObject(newPen);
	DeleteObject(fontL);
	}


	void CChildView::OnTactic442()
	{
		// TODO: Add your command handler code here
	//	MessageBox(_T("4:4:2"),_T("Tactic"));
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
			PathAppend(szPath, TEXT("igraci.bin"));
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

	// FindMenuItem() will find a menu item string from the specified
	// popup menu and returns its position (0-based) in the specified 
	// popup menu. It returns -1 if no such menu item string is found.
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
			PathAppend(szPath, TEXT("igraci.bin"));
			if (ffile.Open(szPath, CFile::modeRead | CFile::typeText))
			{
				Tactic tc;
				CString str;
				while (ffile.ReadString(tc.name))//citam ime taktike
				{
					for (int i = 0; i < 11; i++) {
					
						ffile.ReadString(tc.player[i].position);//pozicija igraca

						ffile.ReadString(str);
						tc.player[i].x = _wtof(str);

						ffile.ReadString(str);
						tc.player[i].y = _wtof(str);

						ffile.ReadString(str);
						tc.player[i].rx = _wtof(str);

						ffile.ReadString(str);
						tc.player[i].ry = _wtof(str);


					}

					addToMenu(tc.name, tacticList.GetCount());
					tacticList.AddTail(tc);

				}
				ffile.Close();
			}
		}
	}
	
	bool CChildView::GetFont() {
	
		CFontDialog dlg;
		if (dlg.DoModal() == IDOK)
		{
			fontL->DeleteObject();
			fontL->CreateFontIndirect(dlg.m_cf.lpLogFont);
			col = dlg.GetColor();
			return true;
		}
		return false;
	}





	void CChildView::OnOptionsSavetactic()
	{
	    
		// TODO: Add your command handler code here
		askDialog dialog;
		if (dialog.DoModal() == IDOK)
		{

				if (!gk) {
					MessageBox(_T("Set GK!!"), _T("Fault!!"), MB_OK);
					return;
				}

			Tactic tak=currentTactic;
			tak.name=dialog.EditValue;
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
				currentTactic = tak;
				Invalidate();
				UpdateWindow();
				return;
				}
			id++;
		}
	}

	void CChildView::SettingsFont()
	{
		// TODO: Add your command handler code here
		if (GetFont())
		{
			InvalidateRect(NULL, true);
			UpdateWindow();
		}
	}


	void CChildView::RemoveMenu(CString name)
	{

		// Get the menu from the application window.
		CMenu* mmenu = AfxGetMainWnd()->GetMenu();
		int pos = FindMenuItem(mmenu, _T("Tactic"));
		CMenu* submenu = mmenu->GetSubMenu(pos);
		int pos2 = FindMenuItem(submenu, name);
		if (pos2 == -1)return;
		submenu->RemoveMenu(pos2, MF_BYPOSITION);
	}

	void CChildView::deleteTactic(Tactic tak)
	{
		// TODO: Add your command handler code here
		for (int i = 0; i < tacticList.GetCount(); i++)
		{
			POSITION takListPos = tacticList.FindIndex(i);
			Tactic tak0 = tacticList.GetAt(takListPos);
			if (tak0.name == tak.name)
			{
				tacticList.RemoveAt(takListPos);
				RemoveMenu(tak.name);
				SaveTactic();
				break;
			}
		}
	}

	void CChildView::OnOptionsDeletetactic()
	{
		// TODO: Add your command handler code here
		if (MessageBox(_T("Do you whish to delete current tactic?"), _T("Question"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		        deleteTactic(currentTactic);


	}
