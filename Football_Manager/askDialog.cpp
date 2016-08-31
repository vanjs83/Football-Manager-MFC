// askDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Football_Manager.h"
#include "askDialog.h"
#include "afxdialogex.h"
#include "askDialog.h"

// askDialog dialog

IMPLEMENT_DYNAMIC(askDialog, CDialogEx)

askDialog::askDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

askDialog::~askDialog()
{
}

void askDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, askEdit);
}


BEGIN_MESSAGE_MAP(askDialog, CDialogEx)
	


	ON_BN_CLICKED(IDOK, &askDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// askDialog message handlers


void askDialog::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	GetDlgItemText(IDC_EDIT1,EditValue);
	if (EditValue == _T("")) {
		MessageBox(_T("Write tactic"), _T("Fault"), MB_OK);
		return;
	}

	CDialogEx::OnOK();
}
