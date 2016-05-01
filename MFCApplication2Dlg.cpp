
// MFCApplication2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL OnInitDialog();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 对话框



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2Dlg::OnBnClickedButton2)
//	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnClickedButton1)
//ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnClickedButton1)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 消息处理程序


BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



/*
void CMFCApplication2Dlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, 0, 0, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("All Filese(*.own)|*.own||"), AfxGetMainWnd());
	CString file_path, file_text;
	if (IDOK == dlg.DoModal())
	{
		//	file_path = _T("myNote.own");
		file_path = dlg.GetPathName();
		if (file_path.Right(4) != ".own")
		{
			file_path += ".own";
		}
		CFile file;
		if (!file.Open(file_path, CFile::modeCreate | CFile::modeWrite))
		{
			MessageBox(_T("Note file create failed"));
			return;
		}
		m_Edit.GetWindowTextW(file_text);
		CArchive ar(&file, CArchive::store);
		ar << file_text;
		MessageBox(_T("Note saved successfully"));
		ar.Close();
		file.Close();
	}
}
*/

void CMFCApplication2Dlg::OnBnClickedButton2()//button
{
	// TODO:  在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, 0, 0, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("All Filese(*.own)|*.own||"), AfxGetMainWnd());
	CFile file;
	CString file_path, file_text, file_line;
	if (IDOK == dlg.DoModal())
	{
		file_path = dlg.GetPathName();
		MessageBox(file_path);
		if (!file.Open(file_path, CFile::modeRead))
		{
			MessageBox(_T("Note file open failed"));
			return ;
		}
		SetWindowText(file_path);
		CArchive ar(&file, CArchive::load);
		ar >> file_text;
		ar.Close();
		file.Close();
		m_Edit.SetWindowText(file_text);
	}
}



void CMFCApplication2Dlg::OnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, 0, 0, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("All Filese(*.own)|*.own||"), AfxGetMainWnd());
	CString file_path, file_text;
	if (IDOK == dlg.DoModal())
	{
		//	file_path = _T("myNote.own");
		file_path = dlg.GetPathName();
		if (file_path.Right(4) != ".own")
		{
			file_path += ".own";
		}
		CFile file;
		if (!file.Open(file_path, CFile::modeCreate | CFile::modeWrite))
		{
			MessageBox(_T("Note file create failed"));
			return;
		}
		m_Edit.GetWindowTextW(file_text);
		CArchive ar(&file, CArchive::store);
		ar << file_text;
		MessageBox(_T("Note saved successfully"));
		ar.Close();
		file.Close();
	}
}
