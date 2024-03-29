
// Registration_Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Registration.h"
#include "Registration_Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CRegistration_Dlg dialog




CRegistration_Dlg::CRegistration_Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegistration_Dlg::IDD, pParent)
	, m_strName(_T(""))
	, m_strDate(_T(""))
	, m_nCertificateID(0)
	, m_strCourse(_T(""))
	, m_nID(0)
	, m_bAnjoman(FALSE)
	, m_bResearch(FALSE)
	, m_bQuran(FALSE)
	, m_bBasij(FALSE)
	, m_nGender(0)
	, gender(0)
	, temp_var(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRegistration_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_cmbCourse);
	DDX_Text(pDX, IDC_EDT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDT_BIRTH, m_strDate);
	DDX_Text(pDX, IDC_EDT_ID, m_nCertificateID);
	DDX_CBString(pDX, IDC_COMBO1, m_strCourse);
	DDX_Text(pDX, IDC_EDT_BIRTH2, m_nID);
	DDX_Check(pDX, IDC_CHECK1, m_bAnjoman);
	DDX_Check(pDX, IDC_CHECK2, m_bResearch);
	DDX_Check(pDX, IDC_CHECK3, m_bQuran);
	DDX_Check(pDX, IDC_CHECK4, m_bBasij);
	DDX_Radio(pDX, IDC_RADIO1, gender);	
}

BEGIN_MESSAGE_MAP(CRegistration_Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CRegistration_Dlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDT_BIRTH2, &CRegistration_Dlg::OnEnChangeEdtBirth2)
END_MESSAGE_MAP()


// CRegistration_Dlg message handlers

BOOL CRegistration_Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CString Courses[] = {_T("الکترونیک"), _T("کنترل"), _T("مخابرات"), _T("قدرت"), _T("رباتیک")};
	for (int i = 0; i < 5; i++)
		m_cmbCourse.AddString(Courses[i]);
	
	m_cmbCourse.SetCurSel(2);

	//GetDlgItem(IDOK)->EnableWindow(0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRegistration_Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRegistration_Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRegistration_Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CRegistration_Dlg::OnBnClickedOk()
{
	UpdateData();

	CString data;
	data = _T("\nنام و نام خانوادگی: ") + m_strName;
	data += _T("\nتاریخ تولد: ") + m_strDate;
	data.AppendFormat(_T("\nشماره شناسنامه: %d"), m_nCertificateID);
	CString str_gender[] = {_T("مرد"), _T("زن")};
	data += _T("\nجنسیت: ") + str_gender[gender];
	data.AppendFormat(_T("\nشماره دانشجویی: %d"), m_nID);
	data += _T("\nرشته تحصیلی: ") + m_strCourse;

	CString strCoop = _T("");
	if(m_bAnjoman)
		strCoop += _T("انجمن علمی، ");
	if(m_bResearch)
		strCoop += _T("پژوهشکده، ");
	if(m_bQuran)
		strCoop += _T("شورای صنفی، ");
	if(m_bBasij)
		strCoop += _T("انجمن اسلامی");

	data += _T("\nهمکاری با: ") + strCoop + _T("\n\r");

	MessageBox(data, _T("اطلاعات وارد شده: "), MB_RTLREADING|MB_RIGHT);
#if 0
	FILE* fp = fopen("student.txt", "at,ccs=UNICODE");//ccs: coded character set
	if(!fp){
		MessageBox(_T("File can not be openned."), _T("Error"));
		return;
	}
	fwprintf(fp, _T("%s"), data.GetBuffer());
	//fwrite(data, 2, data.GetLength(), fp);//Unicode version of fprintf
	fclose(fp);
#else
	CStdioFile file;
	file.Open(L"student.txt", CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate
							| CFile::typeText	| CFile::typeUnicode);

	//CFile::modeCreate Creates a new file if no file exists.; If the file already exists, CFileException is raised.
	//CFile::modeNoTruncate Creates a new file if no file exists; otherwise, if the file already exists, it is attached to the CFile object.
	//CFile::modeWrite Requests write access only.
	//file.SeekToEnd(); Sets the value of the file pointer to the logical end of the file.

	file.SeekToEnd();
	file.WriteString(data); // \r\n to move the cursor to the next line

	file.Close();
#endif
	MessageBox(_T("اطلاعات در فايل student.txt ذخيره شد."), _T("توجه"), MB_RTLREADING|MB_RIGHT|MB_ICONINFORMATION);
}


void CRegistration_Dlg::OnEnChangeEdtBirth2()
{
	//UpdateData(1);

	//GetDlgItem(IDOK)->EnableWindow(m_nID >= 1e7);
}
