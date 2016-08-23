
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Football_Manager.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_COMMAND(ID_TACTIC_4, &CChildView::OnTactic442)
	ON_COMMAND(ID_TACTIC_5, &CChildView::OnTactic451)
	ON_COMMAND(ID_TACTIC_6, &CChildView::OnTactic433)
	ON_COMMAND(ID_TACTIC_7, &CChildView::OnTactic4231)
	ON_COMMAND(ID_TACTIC_3, &CChildView::OnTactic3331)
	ON_COMMAND(ID_TACTIC_8, &CChildView::OnTactic343)
	ON_COMMAND(ID_TACTIC_9, &CChildView::OnTactic352)
	ON_COMMAND(ID_TACTIC_10, &CChildView::OnTactic532)
	ON_COMMAND(ID_TACTIC_11, &CChildView::OnTactic541)
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

	return TRUE;
}

BOOL CChildView::PreTranslateMessage(MSG* pMsg)//prima mouse move
{
	if (pMsg->message == WM_MOUSEMOVE)
	{
		GetCursorPos(&mouseP);
		RECT r;
		GetWindowRect(&r);
		ScreenToClient(&mouseP);
		mouseButtonPress = false;
		if ((GetKeyState(VK_LBUTTON) & 0x100) != 0) {
			CString val;
			val.Format(L"%d, %d", mouseP.x - r.left, mouseP.y - r.top);
			//static1.SetWindowTextW(val);
			mouseButtonPress = true;
			OnPaint();
		}
	}
	return CChildView::PreTranslateMessage(pMsg);
}

void CChildView::OnSize(UINT nType, int cx, int cy)
{
	switch (tactic)
	{
	case 1:
	{
		InitPlayers442();
		break;
	}
	case 2:
	{
		InitPlayers451();
		break;

	}
	case 3:
	{
		InitPlayers433();
		break;
	}
	case 4:
	{
		InitPlayers4231();
		break;
	}
	case 5:
	{
		InitPlayers3331();
		break;
	}
	case 6:
	{
		InitPlayers343();
		break;
	}
	case 7:
	{
		InitPlayers352();
		break;
	}
	case 8:
	{
		InitPlayers532();
	}
	case 9:
	{

		InitPlayers541();
		break;
	}
	default:
		break;
	}




}
void CChildView::InitPlayers442() {
	int out = 20;
	CRect rect;
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


}


void CChildView::InitPlayers352()
{
	int out = 20;
	CRect rect;
	GetClientRect(&rect);
	players[0].position = _T("GK");
	players[1].position = _T("CB");
	players[2].position = _T("CB");
	players[3].position = _T("CB");
	players[4].position = _T("MC");
	players[5].position = _T("MC");
	players[6].position = _T("ML");
	players[7].position = _T("MC");
	players[8].position = _T("MR");
	players[9].position = _T("FC");
	players[10].position = _T("FC");

	players[0].x = out;//gk
	players[0].y = rect.Height() / 2 - out;
	//crtanje obrane
	players[1].x = rect.Width() / 4;//CB
	players[1].y = rect.Height() / 4 * 3;

	players[2].x = rect.Width() / 4;//CB
	players[2].y = rect.Height() / 4;

	players[3].x = rect.Width() / 4;//CB
	players[3].y = rect.Height() / 4 * 2;
	//crtanje veze
	players[4].x = rect.Width() / 4 * 2;//MR
	players[4].y = rect.Height() / 6 * 2;

	players[5].x = rect.Width() / 4 * 2;//MR
	players[5].y = rect.Height() / 6 * 3;

	players[6].x = rect.Width() / 4 * 2;//ML
	players[6].y = rect.Height() / 6;

	players[7].x = rect.Width() / 4 * 2;//MC
	players[7].y = rect.Height() / 6 * 4;

	players[8].x = rect.Width() / 4 * 2;//MR
	players[8].y = rect.Height() / 6 * 5;
	//crtanje napada
	players[9].x = rect.Width() / 4 * 3;//FC
	players[9].y = rect.Height() / 5 * 2;

	players[10].x = rect.Width() / 4 * 3;//FC
	players[10].y = rect.Height() / 5 * 3;



}
void CChildView::InitPlayers451() {

	int out = 20;
	CRect rect;
	GetClientRect(&rect);
	players[0].position = _T("GK");
	players[1].position = _T("DR");
	players[2].position = _T("DL");
	players[3].position = _T("CB");
	players[4].position = _T("CB");
	players[5].position = _T("MR");
	players[6].position = _T("ML");
	players[7].position = _T("MC");
	players[8].position = _T("MC");
	players[9].position = _T("MC");
	players[10].position = _T("FC");

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
	players[5].y = rect.Height() / 6 * 5;
	players[6].x = rect.Width() / 4 * 2;//ML
	players[6].y = rect.Height() / 6;
	players[7].x = rect.Width() / 4 * 2;//MC
	players[7].y = rect.Height() / 6 * 2;
	players[8].x = rect.Width() / 4 * 2;//MC
	players[8].y = rect.Height() / 6 * 3;
	players[9].x = rect.Width() / 4 * 2;//MC
	players[9].y = rect.Height() / 6 * 4;
	//crtanje napada

	players[10].x = rect.Width() / 4 * 3;//FC
	players[10].y = rect.Height() / 4 * 2;

}

void CChildView::InitPlayers433() {
	int out = 20;
	CRect rect;
	GetClientRect(&rect);
	players[0].position = _T("GK");
	players[1].position = _T("DR");
	players[2].position = _T("DL");
	players[3].position = _T("CB");
	players[4].position = _T("CB");
	players[5].position = _T("MC");
	players[6].position = _T("MC");
	players[7].position = _T("MC");
	players[8].position = _T("RFC");
	players[9].position = _T("LFC");
	players[10].position = _T("FC");

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
	players[5].x = rect.Width() / 4 * 2;//MC
	players[5].y = rect.Height() / 4 * 3;

	players[6].x = rect.Width() / 4 * 2;//MC
	players[6].y = rect.Height() / 4;

	players[7].x = rect.Width() / 4 * 2;//MC
	players[7].y = rect.Height() / 4 * 2;
	//crtanje napada
	players[8].x = rect.Width() / 4 * 3;//FC
	players[8].y = rect.Height() / 4 * 3;

	players[9].x = rect.Width() / 4 * 3;//FC
	players[9].y = rect.Height() / 4;

	players[10].x = rect.Width() / 4 * 3;//FC
	players[10].y = rect.Height() / 4 * 2;
}

void CChildView::InitPlayers343() {

	int out = 20;
	CRect rect;
	GetClientRect(&rect);
	players[0].position = _T("GK");
	players[1].position = _T("CB");
	players[2].position = _T("CB");
	players[3].position = _T("CB");
	players[4].position = _T("MC");
	players[5].position = _T("MR");
	players[6].position = _T("ML");
	players[7].position = _T("MC");
	players[8].position = _T("LFC");
	players[9].position = _T("RC");
	players[10].position = _T("FC");

	players[0].x = out;//gk
	players[0].y = rect.Height() / 2 - out;
	//crtanje obrane
	players[1].x = rect.Width() / 4;//CB
	players[1].y = rect.Height() / 4 * 3;

	players[2].x = rect.Width() / 4;//CB
	players[2].y = rect.Height() / 4;

	players[3].x = rect.Width() / 4;//CB
	players[3].y = rect.Height() / 4 * 2;
	//crtanje veze
	players[4].x = rect.Width() / 4 * 2;//MR
	players[4].y = rect.Height() / 5 * 3;


	players[5].x = rect.Width() / 4 * 2;//MR
	players[5].y = rect.Height() / 5 * 4;

	players[6].x = rect.Width() / 4 * 2;//ML
	players[6].y = rect.Height() / 5;

	players[7].x = rect.Width() / 4 * 2;//MC
	players[7].y = rect.Height() / 5 * 2;

	//crtanje napada
	players[8].x = rect.Width() / 4 * 3;//RFC
	players[8].y = rect.Height() / 4 * 3;

	players[9].x = rect.Width() / 4 * 3;//LFC
	players[9].y = rect.Height() / 4;

	players[10].x = rect.Width() / 4 * 3;//FC
	players[10].y = rect.Height() / 4 * 2;
}




void CChildView::InitPlayers4231() {
	int out = 20;
	CRect rect;
	GetClientRect(&rect);
	players[0].position = _T("GK");
	players[1].position = _T("DR");
	players[2].position = _T("DL");
	players[3].position = _T("CB");
	players[4].position = _T("CB");
	players[5].position = _T("MC");
	players[6].position = _T("MC");
	players[7].position = _T("AML");
	players[8].position = _T("AMC");
	players[9].position = _T("AMR");
	players[10].position = _T("FC");

	//crtanje obrane
	players[0].x = out;//gk
	players[0].y = rect.Height() / 2 - out;

	players[1].x = rect.Width() / 5;//DR
	players[1].y = rect.Height() / 5 * 4;
	players[2].x = rect.Width() / 5;//DL
	players[2].y = rect.Height() / 5;
	players[3].x = rect.Width() / 5;//CB
	players[3].y = rect.Height() / 5 * 2;
	players[4].x = rect.Width() / 5;//CB
	players[4].y = rect.Height() / 5 * 3;
	//crtanje veze
	players[5].x = rect.Width() / 5 * 2;//MC
	players[5].y = rect.Height() / 6 * 2;

	players[6].x = rect.Width() / 5 * 2;//MC
	players[6].y = rect.Height() / 5 * 3;

	players[7].x = rect.Width() / 5 * 3;//AML
	players[7].y = rect.Height() / 4;

	players[8].x = rect.Width() / 5 * 3;//AMC
	players[8].y = rect.Height() / 4 * 2;

	players[9].x = rect.Width() / 5 * 3;//AMR
	players[9].y = rect.Height() / 4 * 3;

	//crtanje napada
	players[10].x = rect.Width() / 5 * 4;//FC
	players[10].y = rect.Height() / 4 * 2;


}
void CChildView::InitPlayers3331() {
	//crtanje obrane

	int out = 20;
	CRect rect;
	GetClientRect(&rect);
	players[0].position = _T("GK");
	players[1].position = _T("CB");
	players[2].position = _T("CB");
	players[3].position = _T("CB");
	players[4].position = _T("MC");
	players[5].position = _T("MC");
	players[6].position = _T("MC");
	players[7].position = _T("AML");
	players[8].position = _T("AMC");
	players[9].position = _T("AMR");
	players[10].position = _T("FC");

	players[0].x = out;//gk
	players[0].y = rect.Height() / 2 - out;
	//crtanje obrane
	players[1].x = rect.Width() / 5;//CB
	players[1].y = rect.Height() / 4 * 3;

	players[2].x = rect.Width() / 5;//CB
	players[2].y = rect.Height() / 4;

	players[3].x = rect.Width() / 5;//CB
	players[3].y = rect.Height() / 4 * 2;
	//crtanje veze
	players[4].x = rect.Width() / 5 * 2;//MC
	players[4].y = rect.Height() / 4 * 2;


	players[5].x = rect.Width() / 5 * 2;//MC
	players[5].y = rect.Height() / 4 * 3;

	players[6].x = rect.Width() / 5 * 2;//MC
	players[6].y = rect.Height() / 4;
	//crtanje atack midfilder
	players[7].x = rect.Width() / 5 * 3;//AML
	players[7].y = rect.Height() / 4;

	players[8].x = rect.Width() / 5 * 3;//AMC
	players[8].y = rect.Height() / 4 * 2;

	players[9].x = rect.Width() / 5 * 3;//AMR
	players[9].y = rect.Height() / 4 * 3;

	players[10].x = rect.Width() / 5 * 4;//FC
	players[10].y = rect.Height() / 4 * 2;


}

void CChildView::InitPlayers532() {

	int out = 20;
	CRect rect;
	GetClientRect(&rect);
	players[0].position = _T("GK");
	players[1].position = _T("DR");
	players[2].position = _T("DL");
	players[3].position = _T("CB");
	players[4].position = _T("CB");
	players[5].position = _T("CB");
	players[6].position = _T("MC");
	players[7].position = _T("MC");
	players[8].position = _T("MC");
	players[9].position = _T("FC");
	players[10].position = _T("FC");

	players[0].x = out;//gk
	players[0].y = rect.Height() / 2 - out;
	//crtanje obrane
	players[1].x = rect.Width() / 4;//DR
	players[1].y = rect.Height() / 6 * 5;

	players[2].x = rect.Width() / 4;//DL
	players[2].y = rect.Height() / 6;

	players[3].x = rect.Width() / 4;//CB
	players[3].y = rect.Height() / 6 * 2;

	players[4].x = rect.Width() / 4;//CB
	players[4].y = rect.Height() / 6 * 3;

	players[5].x = rect.Width() / 4;//CB
	players[5].y = rect.Height() / 6 * 4;
	//crtanje veze 
	players[6].x = rect.Width() / 4 * 2;//MC
	players[6].y = rect.Height() / 4 * 3;

	players[7].x = rect.Width() / 4 * 2;//MC
	players[7].y = rect.Height() / 4;

	players[8].x = rect.Width() / 4 * 2;//MC
	players[8].y = rect.Height() / 4 * 2;
	//crtanje napada
	players[9].x = rect.Width() / 4 * 3;//FC
	players[9].y = rect.Height() / 5 * 2;

	players[10].x = rect.Width() / 4 * 3;//FC
	players[10].y = rect.Height() / 5 * 3;

}
void CChildView::InitPlayers541() {

	int out = 20;
	CRect rect;
	GetClientRect(&rect);
	players[0].position = _T("GK");
	players[1].position = _T("DR");
	players[2].position = _T("DL");
	players[3].position = _T("CB");
	players[4].position = _T("CB");
	players[5].position = _T("CB");
	players[6].position = _T("MR");
	players[7].position = _T("ML");
	players[8].position = _T("MC");
	players[9].position = _T("MC");
	players[10].position = _T("FC");

	players[0].x = out;//gk
	players[0].y = rect.Height() / 2 - out;
	//crtanje obrane
	players[1].x = rect.Width() / 4;//DR
	players[1].y = rect.Height() / 6 * 5;

	players[2].x = rect.Width() / 4;//DL
	players[2].y = rect.Height() / 6;

	players[3].x = rect.Width() / 4;//CB
	players[3].y = rect.Height() / 6 * 2;

	players[4].x = rect.Width() / 4;//CB
	players[4].y = rect.Height() / 6 * 3;

	players[5].x = rect.Width() / 4;//CB
	players[5].y = rect.Height() / 6 * 4;
	//crtanje veze 
	players[6].x = rect.Width() / 4 * 2;//MR
	players[6].y = rect.Height() / 5 * 4;

	players[7].x = rect.Width() / 4 * 2;//ML
	players[7].y = rect.Height() / 5;

	players[8].x = rect.Width() / 4 * 2;//MC
	players[8].y = rect.Height() / 5 * 2;

	players[9].x = rect.Width() / 4 * 2;//MC
	players[9].y = rect.Height() / 5 * 3;
	//crtanje napada
	players[10].x = rect.Width() / 4 * 3;//FC
	players[10].y = rect.Height() / 4 * 2;

}




void CChildView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// TODO: Add your message handler code here
	int out = 20;
	int goal = 50;
	CRect rct;
	GetClientRect(&rct);
	RECT r;
	GetClientRect(&r);
	CDC* dcc = this->GetDC();//get window
	CBrush brushGreen(RGB(0, 128, 0));//brush
	dcc->SelectObject(brushGreen); //select brush tool
	dcc->Rectangle(0, 0, r.right, r.bottom);//draw rectangle

	CPen* newPen = new CPen(PS_SOLID | PS_GEOMETRIC, 3, RGB(255, 255, 255));
	CPen* pOldPen = dcc->SelectObject(newPen);//select pen
											  //dcc->TextOutW(10, 10, _T("text"));
											  //crtanje okvira
	dcc->MoveTo(out, out); //krajnja točka
	dcc->LineTo(out, r.bottom - out);//početna točka

	dcc->MoveTo(out, out);
	dcc->LineTo(r.right - out, out);

	dcc->MoveTo(r.right - out, out);
	dcc->LineTo(r.right - out, r.bottom - out);

	dcc->MoveTo(out, r.bottom - out);
	dcc->LineTo(r.right - out, r.bottom - out);

	//crtanje kruga
	//int diff = (rct.bottom / 2) / 2;
	//left               //top             //right                        //bottom
	//dcc->Ellipse((rct.right / 2) - diff, diff + out, (rct.right / 2) + diff, (rct.bottom / 2) + diff - out);

	dcc->Ellipse(rct.right / 3 + out, rct.bottom / 4, rct.right / 3 * 2 - out, rct.bottom / 4 * 3);

	dcc->MoveTo((r.right - out + out) / 2, out);
	dcc->LineTo((r.right - out + out) / 2, r.bottom - out);

	//crtanje lijevog gola
	dcc->MoveTo(out, rct.bottom / 10 * 4);
	dcc->LineTo(out + rct.right / 30, rct.bottom / 10 * 4);
	dcc->LineTo(out + rct.right / 30, rct.bottom / 10 * 6);
	dcc->LineTo(out, rct.bottom / 10 * 6);

	//crtanje desnog gola
	dcc->MoveTo(r.right - out, rct.bottom / 10 * 4);
	dcc->LineTo(r.right / 30 * 29, rct.bottom / 10 * 4);
	dcc->LineTo(r.right / 30 * 29, rct.bottom / 10 * 6);
	dcc->LineTo(r.right - out, rct.bottom / 10 * 6);
	//crtanje lijevog šesnajsterca
	dcc->MoveTo(out, rct.bottom / 10 * 2);
	dcc->LineTo(out + rct.right / 8, rct.bottom / 10 * 2);
	dcc->LineTo(out + rct.right / 8, rct.bottom / 10 * 8);
	dcc->LineTo(out, rct.bottom / 10 * 8);
	//crtanje desnog šesnajsterca
	dcc->MoveTo(r.right - out, rct.bottom / 10 * 2);
	dcc->LineTo(r.right / 8 * 7 - out, rct.bottom / 10 * 2);
	dcc->LineTo(r.right / 8 * 7 - out, rct.bottom / 10 * 8);
	dcc->LineTo(r.right - out, rct.bottom / 10 * 8);
	//lijeva tocka za penal
	dcc->MoveTo(rct.right / 30 * 3, rct.bottom / 2);
	dcc->LineTo(rct.right / 30 * 3, rct.bottom / 2);
	//desna tocka za penal
	dcc->MoveTo(rct.right / 30 * 28 - out, rct.bottom / 2);
	dcc->LineTo(rct.right / 30 * 28 - out, rct.bottom / 2);
	// TODO: Add your message handler code here

	// Do not call CWnd::OnPaint() for painting messages
	BOOL b = false;

	for (int i = 0; i < 11; i++) {
		if (mouseButtonPress)
			if (mouseP.x + out >= players[i].x && mouseP.x <= players[i].x + out)
				if (mouseP.y + out >= players[i].y && mouseP.y <= players[i].y + out)
				{
					if (!b)
					{
						players[i].x = mouseP.x;
						players[i].y = mouseP.y;
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
		else if (players[i].x >= rct.Width() / 7 * 2 && players[i].x >= rct.Width() / 7 * 3 && players[i].x <= rct.Width() / 7 * 4) {

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

		else if (players[i].x >= rct.Width() / 7 * 6) {
			players[i].position = _T("FC");
			if (players[i].y <= rct.Height() / 5 * 2)
				players[i].position = _T("LFC");
			if (players[i].y >= rct.Height() / 5 * 3)
				players[i].position = _T("RFC");

		}

		dcc->TextOutW(players[i].x, players[i].y, players[i].position);




		// Do not call CWnd::OnPaint() for painting messages
	}
}


	void CChildView::OnTactic442()
	{
		// TODO: Add your command handler code here
		MessageBox(_T("4:4:2"),_T("Tactic"));
		tactic =1;
		InitPlayers442();
		OnPaint();
	}


	void CChildView::OnTactic451()
	{
		// TODO: Add your command handler code here
		MessageBox(_T("4:5:1"), _T("Tactic"));
		tactic =2;
		InitPlayers451();
		OnPaint();
	}


	void CChildView::OnTactic433()
	{
		// TODO: Add your command handler code here
		MessageBox(_T("4:5:1"), _T("Tactic"));
		tactic =3;
		InitPlayers433();
		OnPaint();
	}


	void CChildView::OnTactic4231()
	{
		// TODO: Add your command handler code here
		MessageBox(_T("4:2:3:1"), _T("Tactic"));
		tactic =4;
		InitPlayers433();
		OnPaint();
	}


	void CChildView::OnTactic3331()
	{
		// TODO: Add your command handler code here
		MessageBox(_T("3:3:3:1"), _T("Tactic"));
		tactic =5;
		InitPlayers3331();
		OnPaint();
	}


	void CChildView::OnTactic343()
	{
		// TODO: Add your command handler code here
		MessageBox(_T("3:4:3"), _T("Tactic"));
		tactic =6;
		InitPlayers343();
		OnPaint();
	}


	void CChildView::OnTactic352()
	{
		// TODO: Add your command handler code here
		MessageBox(_T("3:5:2"), _T("Tactic"));
		tactic = 7;
		InitPlayers352();
		OnPaint();
	}


	void CChildView::OnTactic532()
	{
		// TODO: Add your command handler code here
		MessageBox(_T("3:5:2"), _T("Tactic"));
		tactic =8;
		InitPlayers352();
		OnPaint();
	}


	void CChildView::OnTactic541()
	{
		// TODO: Add your command handler code here
		MessageBox(_T("5:4:1"), _T("Tactic"));
		tactic =9;
		InitPlayers541();
		OnPaint();
	}
