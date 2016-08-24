#pragma once
#include "afxwin.h"


// askDialog dialog

class askDialog : public CDialogEx
{
	DECLARE_DYNAMIC(askDialog)

public:
	askDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~askDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit askEdit;
};
