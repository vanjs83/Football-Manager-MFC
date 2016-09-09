
// ChildView.cpp : implementation of the CChildView class

#include "stdafx.h"
#include "Football_Manager.h"
#include "ChildView.h"
#include "askDialog.h"
#include <afxwin.h>
#include <string>
#include "MainFrm.h"
#include <tchar.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define ID_MENUSHOW   2000

// CChildView

CChildView::CChildView()
{
	CClientDC hdc(0);
	ZeroMemory(&lf, sizeof lf);
	_tcscpy_s(lf.lfFaceName, _T("Arial"));
	lf.lfHeight = -12 * GetDeviceCaps(hdc, LOGPIXELSY) / 72;


}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
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

	if ((GetKeyState(VK_LBUTTON) & 0x100) != 0) {
		if (pIndex != -1)
		{
			CClientDC hdc(this);

			HFONT hfnt = CreateFontIndirect(&lf);
			HGDIOBJ holdfont = SelectObject(hdc, hfnt);
			CSize fsize = hdc.GetTextExtent(currentTactic.player[pIndex].position);
			//
			double x = rct.Width() * currentTactic.player[pIndex].rx;
			double y = rct.Height() * currentTactic.player[pIndex].ry;
			//
			RECT rect = { x - (fsize.cx), y - (fsize.cy),(x)+(fsize.cx * 2), (y)+(fsize.cy * 2) };
			//hdc.Rectangle(&rect);;
			InvalidateRect(&rect, true);



			//
			x = point.x;
			y = point.y;
			//
			currentTactic.player[pIndex].rx = x / rct.Width();
			currentTactic.player[pIndex].ry = y / rct.Height();
			//

			x = rct.Width() * currentTactic.player[pIndex].rx;
			y = rct.Height() * currentTactic.player[pIndex].ry;
			//
			if (x < out) //ne daj igracima izvan terena
			{
				x = out;
				if (y < out)
					y = out;
				else if (y + fsize.cy > rct.Height() - out)
					y = rct.Height() - out - fsize.cy;
			}
			else if (x > rct.Width() - out - fsize.cx)
			{
				x = rct.Width() - out - fsize.cx;
				if (y < out)
					y = out;
				else if (y + fsize.cy > rct.Height() - out)
					y = rct.Height() - out - fsize.cy;
			}
			else if (y < out)
				y = out;

			else if (y + fsize.cy > rct.Height() - out)
				y = rct.Height() - out - fsize.cy;

			else if (x >= rct.Width() / 7 && x <= rct.Width() / 7 * 2)
			{
				currentTactic.player[pIndex].position = _T("CB");
				if (y <= rct.Height() / 5)
					currentTactic.player[pIndex].position = _T("DL");
				if (y >= rct.Height() / 5 * 4)
					currentTactic.player[pIndex].position = _T("DR");
			}

			else if (x >= rct.Width() / 7 * 2 && x <= rct.Width() / 7 * 4) {

				currentTactic.player[pIndex].position = _T("MC");
				if (y <= rct.Height() / 5)
					currentTactic.player[pIndex].position = _T("ML");
				if (y >= rct.Height() / 5 * 4)
					currentTactic.player[pIndex].position = _T("MR");
			}

			else if (x >= rct.Width() / 7 * 3 && x <= rct.Width() / 7 * 5) {
				currentTactic.player[pIndex].position = _T("AMC");
				if (y <= rct.Height() / 5 * 2)
					currentTactic.player[pIndex].position = _T("AML");
				if (y >= rct.Height() / 5 * 3)
					currentTactic.player[pIndex].position = _T("AMR");
			}

			else if (x >= rct.Width() / 7 * 5) {
				currentTactic.player[pIndex].position = _T("FC");
				if (y <= rct.Height() / 5)
					currentTactic.player[pIndex].position = _T("LFC");
				if (y >= rct.Height() / 5 * 4)
					currentTactic.player[pIndex].position = _T("RFC");

			}
			//
			if (x <= rct.Width() / 7) {//Postavi golmana
				if (!gk) {
					currentTactic.player[pIndex].position = _T("GK");
					gk = true;
				}
			}
			//
			currentTactic.player[pIndex].rx = x / rct.Width();
			currentTactic.player[pIndex].ry = y / rct.Height();
			//
			RECT rect2 = { x - (fsize.cx), y - (fsize.cy),(x)+(fsize.cx * 2), (y)+(fsize.cy * 2) };
			//hdc.Rectangle(&rect);;
			InvalidateRect(&rect2, true);
			DeleteObject(SelectObject(hdc, holdfont));
			//	ReleaseDC(&hdc);
		}
	}



	
}




void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// see large comment in previous function
	GetClientRect(&rct);
	CClientDC hdc(this);

	HFONT hfnt = CreateFontIndirect(&lf);
	HGDIOBJ holdfont = SelectObject(hdc, hfnt);

	//
	for (int i = 0; i < 11; i++) {
		double x, y;
		CSize fsize = hdc.GetTextExtent(currentTactic.player[i].position);
		//calc relative
		x = rct.Width() * currentTactic.player[i].rx;
		y = rct.Height() * currentTactic.player[i].ry;
		//

		if (point.x + out >= x && point.x <= x + out)
			if (point.y + out >= y && point.y <= y + out)
			{

				x = point.x;
				y = point.y;
				currentTactic.player[i].rx = x / rct.Width();
				currentTactic.player[i].ry = y / rct.Height();
				//
				if (x < out) //ne daj igracima izvan terena
				{
					x = out;
					if (y < out)
						y = out;
					else if (y + fsize.cy > rct.Height() - out)
						y = rct.Height() - out - fsize.cy;
				}
				else if (x > rct.Width() - out - fsize.cx)
				{
					x = rct.Width() - out - fsize.cx;
					if (y < out)
						y = out;
					else if (y + fsize.cy > rct.Height() - out)
						y = rct.Height() - out - fsize.cy;
				}
				else if (y < out)
					y = out;

				else if (y + fsize.cy > rct.Height() - out)
					y = rct.Height() - out - fsize.cy;
				//
				currentTactic.player[i].rx = x / rct.Width();
				currentTactic.player[i].ry = y / rct.Height();
				pIndex = i;
				init = true;
				break;
			}
	}
	DeleteObject(SelectObject(hdc, holdfont));
	ReleaseDC(&hdc);	
}





void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// see large comment in previous function
	
	Invalidate();
	UpdateWindow();
	pIndex = -1;

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
	double x, y;
	GetClientRect(&rect);
	if (rect.Width() == 0)return;
	if (rect.Width() == 0)return;
	currentTactic.name = _T("4:4:2");
	currentTactic.player[0].position = _T("GK");
	currentTactic.player[1].position = _T("DR");
	currentTactic.player[2].position = _T("DL");
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
	x = out;//gk
	y = rect.Height() / 2 - out;
	currentTactic.player[0].rx = x / rect.Width();
	currentTactic.player[0].ry = y / rect.Height();
	x = rect.Width() / 4;//DR
	y = rect.Height() / 5 * 4;
	currentTactic.player[1].rx = x / rect.Width();
	currentTactic.player[1].ry = y / rect.Height();
	x = rect.Width() / 4;//DL
	y = rect.Height() / 5;
	currentTactic.player[2].rx = x / rect.Width();
	currentTactic.player[2].ry = y / rect.Height();
	x = rect.Width() / 4;//CB
	y = rect.Height() / 5 * 2;
	currentTactic.player[3].rx = x / rect.Width();
	currentTactic.player[3].ry = y / rect.Height();

	x = rect.Width() / 4;//CB
	y = rect.Height() / 5 * 3;
	currentTactic.player[4].rx = x / rect.Width();
	currentTactic.player[4].ry = y / rect.Height();
	//crtanje veze
	x = rect.Width() / 4 * 2;//MR
	y = rect.Height() / 5 * 4;
	currentTactic.player[5].rx = x / rect.Width();
	currentTactic.player[5].ry = y / rect.Height();
	x = rect.Width() / 4 * 2;//ML
	y = rect.Height() / 5;
	currentTactic.player[6].rx = x / rect.Width();
	currentTactic.player[6].ry = y / rect.Height();
	x = rect.Width() / 4 * 2;//MC
	y = rect.Height() / 5 * 2;
	currentTactic.player[7].rx = x / rect.Width();
	currentTactic.player[7].ry = y / rect.Height();
	x = rect.Width() / 4 * 2;//MC
	y = rect.Height() / 5 * 3;
	currentTactic.player[8].rx = x / rect.Width();
	currentTactic.player[8].ry = y / rect.Height();
	//crtanje napada
	x = rect.Width() / 4 * 3;//FC
	y = rect.Height() / 5 * 2;
	currentTactic.player[9].rx = x / rect.Width();
	currentTactic.player[9].ry = y / rect.Height();
	x = rect.Width() / 4 * 3;//FC
	y = rect.Height() / 5 * 3;
	currentTactic.player[10].rx = x / rect.Width();
	currentTactic.player[10].ry = y / rect.Height();
}
  
void CChildView::OnPaint()
{  
	
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here

	GetClientRect(&rct);
	//Brush
	CBrush *oldBrush;
	CBrush brushGreen(RGB(0, 128, 0));//brush	
    oldBrush= dc.SelectObject(&brushGreen); //select brush tool
    dc.Rectangle(0, 0, rct.right, rct.bottom);//draw rectangle
	dc.SelectObject(oldBrush);
	DeleteObject(brushGreen);//delete brush tool
	

	CPen pen(PS_SOLID, 3, RGB(255, 255, 255)); // lokalna varijabla u OnPaint
	CPen* oldPen = dc.SelectObject(&pen); // selekcija vraća prethodni
	
    //crtanje okvira
dc.MoveTo(out, out); //krajnja točka
dc.LineTo(out, rct.bottom - out);//početna točka

dc.MoveTo(out, out);
dc.LineTo(rct.right - out, out);

dc.MoveTo(rct.right - out, out);
dc.LineTo(rct.right - out, rct.bottom - out);

dc.MoveTo(out, rct.bottom - out);
dc.LineTo(rct.right - out, rct.bottom - out);


dc.MoveTo((rct.right - out + out) / 2, out);
dc.LineTo((rct.right - out + out) / 2, rct.bottom - out);

	//crtanje lijevog prostora gola
dc.MoveTo(out, rct.bottom / 10 * 4);
dc.LineTo(out + rct.right / 30, rct.bottom / 10 * 4);
dc.LineTo(out + rct.right / 30, rct.bottom / 10 * 6);
dc.LineTo(out, rct.bottom / 10 * 6);

	//crtanje desnog prostora za gol
dc.MoveTo(rct.right - out, rct.bottom / 10 * 4);
dc.LineTo(rct.right / 30 * 29, rct.bottom / 10 * 4);
dc.LineTo(rct.right / 30 * 29, rct.bottom / 10 * 6);
dc.LineTo(rct.right - out, rct.bottom / 10 * 6);

	//crtanje lijevog šesnajsterca
dc.MoveTo(out, rct.bottom / 10 * 2);
dc.LineTo(out + rct.right / 8, rct.bottom / 10 * 2);
dc.LineTo(out + rct.right / 8, rct.bottom / 10 * 8);
dc.LineTo(out, rct.bottom / 10 * 8);

	//crtanje desnog šesnajsterca
dc.MoveTo(rct.right - out, rct.bottom / 10 * 2);
dc.LineTo(rct.right / 8 * 7 - out, rct.bottom / 10 * 2);
dc.LineTo(rct.right / 8 * 7 - out, rct.bottom / 10 * 8);
dc.LineTo(rct.right - out, rct.bottom / 10 * 8);

	//lijeva tocka za penal
dc.MoveTo(rct.right / 30 * 3, rct.bottom / 2);
dc.LineTo(rct.right / 30 * 3, rct.bottom / 2);

	//desna tocka za penal
dc.MoveTo(rct.right / 30 * 28 - out, rct.bottom / 2);
dc.LineTo(rct.right / 30 * 28 - out, rct.bottom / 2);

	//lijevi gol
dc.MoveTo(out, rct.bottom / 18 * 8);
dc.LineTo(out / 2, rct.bottom / 18 * 8);
dc.LineTo(out / 2, rct.bottom / 18 * 10);
dc.LineTo(out, rct.bottom / 18 * 10);

	//desni gol
dc.MoveTo(rct.Width() - out, rct.bottom / 18 * 8);
dc.LineTo(rct.Width() - out / 2, rct.bottom / 18 * 8);
dc.LineTo(rct.Width() - out / 2, rct.bottom / 18 * 10);
dc.LineTo(rct.Width() - out, rct.bottom / 18 * 10);


//Lijevi polukrug
double x1, y1, x2, y2, x3, y3, x4, y4;
x3 = out + rct.right / 8 + 1;
y3 = rct.bottom / 12 * 5;
x1 = out + rct.right / 11;
y1 = y3;
x4 = out + rct.right / 8 + 1;
y4 = rct.bottom / 12 * 7;
x2 = out + rct.right / 7;
y2 = y4;
dc.SetArcDirection(AD_CLOCKWISE);
dc.Arc(x1, y1, x2, y2, x3, y3, x4, y4);
//
//Desni polukrug
x3 = rct.right / 8 * 7 - out;
y3 = rct.bottom / 12 * 5;
x1 = (rct.right / 11 * 10 - out);
y1 = y3;
x4 = rct.right / 8 * 7 - out;
y4 = rct.bottom / 12 * 7;
x2 = rct.right / 7 * 6 - out;
y2 = y4;
dc.SetArcDirection(AD_COUNTERCLOCKWISE);
dc.Arc(x1, y1, x2, y2, x3, y3, x4, y4);


//crtanje kruga
x1 = rct.right / 8 * 3 ;
y1 = rct.bottom / 4 ;
x2 = rct.right / 8 * 5;
y2 = rct.bottom / 4 * 3;
x3 = rct.right / 2 ;
y3 = rct.bottom / 2 / 2;
x4 = rct.right / 2;
y4 = y3 = rct.bottom / 2 / 2;
dc.Arc(x1, y1, x2, y2, x3, y3, x4, y4);



   dc.SelectObject(oldPen); //select delete object
	DeleteObject(pen);    // delete object
	// TODO: Add your message handler code here

	// Do not call CWnd::OnPaint() for painting messages
	BOOL b = false;
	     gk = false;
	//crtanje igraca na terenu!!
	    
		 HFONT hfnt = CreateFontIndirect(&lf);
		 HGDIOBJ holdfont = dc.SelectObject(hfnt);
	for (int i = 0; i < 11; i++) {
	
		double x = rct.Width() * currentTactic.player[i].rx;
		double y = rct.Height() * currentTactic.player[i].ry;
		dc.SetTextColor(col);
		dc.SetTextAlign(TA_LEFT);
		dc.SetBkMode(TRANSPARENT);
		if (currentTactic.player[i].position == _T("GK")) gk = true;
		dc.TextOut(x, y, currentTactic.player[i].position);

 				}
    	dc.SelectObject(holdfont);
	    DeleteObject(holdfont); //delete object def_font
	
	// Do not call CWnd::OnPaint() for painting messages
		}

	void CChildView::OnTactic442()
	{
		// TODO: Add your command handler code here
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
			NULL, 0, szPath)))
		{
			PathAppend(szPath, TEXT("igraci.bin"));
			if (ffile.Open(szPath, CFile::modeCreate | CFile::modeWrite | CFile::typeText))
			{
				for (int i = 0; i < tacticList.size(); i++)
				{
					Tactic tak = tacticList[i];
					CString str;
					str.Format(L"%s\n", tak.name);
					ffile.WriteString(str);
					for (int i = 0; i < 11; i++) {

						str.Format(L"%s\n", tak.player[i].position);
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
		tacticList.clear();
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
					for (int i = 0; i < 11; i++) 
					{
					
						ffile.ReadString(tc.player[i].position);//pozicija igraca

						ffile.ReadString(str);
						tc.player[i].rx = _wtof(str);

						ffile.ReadString(str);
						tc.player[i].ry = _wtof(str);
					}

					addToMenu(tc.name, tacticList.size());
					tacticList.push_back(tc);

				}
				ffile.Close();
			}
		}
	}
	
	bool CChildView::GetFont(LOGFONT& lf, COLORREF& col) {

		CHOOSEFONT cf;
		ZeroMemory(&cf, sizeof cf);
		cf.lStructSize = sizeof cf;
		cf.Flags = CF_INITTOLOGFONTSTRUCT | CF_SCREENFONTS | CF_EFFECTS;
		cf.lpLogFont = &lf;
		cf.rgbColors = col;
		if (ChooseFont(&cf)) {
			col = cf.rgbColors;
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
			     addToMenu(tak.name, tacticList.size());
			       tacticList.push_back(tak);
			         SaveTactic();
		}
	}


	void CChildView::OnMenuClick(UINT nID)
	{
		int id = ID_MENUSHOW;
		for (int i = 0; i < tacticList.size(); i++)
		{
			Tactic tak = tacticList[i];
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
		if (GetFont(lf,  col))
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
		for (int i = 0; i < tacticList.size(); i++)
		{
			Tactic tak0 = tacticList[i];
			if (tak0.name == tak.name)
			{
				tacticList.erase(tacticList.begin() + i, tacticList.begin() + i + 1);
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
			if (currentTactic.name == _T("4:4:2"))
			{
				MessageBox(_T("You can't delete default tactic"), _T("Fault"), MB_OK | MB_ICONWARNING);
				return;
			}
		        deleteTactic(currentTactic);


	}
