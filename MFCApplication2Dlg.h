
// MFCApplication2Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include <fstream>
#include<string>
using std::string;
using std::ifstream;
// CMFCApplication2Dlg �Ի���
class CMFCApplication2Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Edit;
//	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
//	afx_msg void OnClickedButton1();
//	afx_msg void OnClickedButton1();
	afx_msg void OnClickedButton1();
};