
// MFCApplication2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCApplication2Dlg �Ի���



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


// CMFCApplication2Dlg ��Ϣ�������


BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



/*
void CMFCApplication2Dlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
