#include "stdafx.h"
#include "resource.h"
#include "argv_107.h"
#include "..\\Lib\\argv_112.hpp"

using namespace std;

argv_152 logger;

bool				argv_496				= false;
bool				argv_212	= false;
HWND				argv_573;
string				argv_205			= "";
LRESULT CALLBACK	argv_122(HWND, UINT, WPARAM, LPARAM);
string				argv_190					= "48elfrad73";

// Global Variables:
#define		argv_508 100
HINSTANCE	argv_213;								// argv_169 instance
TCHAR		argv_587[argv_508];			// The title bar text
TCHAR		argv_588[argv_508];		// The title bar text

ATOM				argv_522(HINSTANCE hInstance);
BOOL				argv_473(HINSTANCE, int);
LRESULT CALLBACK	argv_606(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	argv_122(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	MSG msg;
	HACCEL hAccelTable;
	LoadString(hInstance, argv_471, argv_587, argv_508);
	LoadString(hInstance, argv_448, argv_588, argv_508);
	argv_522(hInstance);

	if (!argv_473 (hInstance, nCmdShow))  {
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)argv_448);
	while (GetMessage(&msg, NULL, 0, 0))  {
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))  {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return msg.wParam;
}

ATOM argv_522(HINSTANCE hInstance) {
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX); 
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)argv_606;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)argv_465);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)argv_448;
	wcex.lpszClassName	= argv_588;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)argv_463);
	return RegisterClassEx(&wcex);
}

bool argv_184 (const string& _filename) {
	bool bret = true;

	FILE * argv_189 = fopen (_filename.c_str(), "rb");
	if (!argv_189) {
		bret = false;
	}
	else {
		fclose(argv_189);
	}	

	return(bret);
}

BOOL argv_473(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	argv_213 = hInstance; // Store instance handle in our global variable

	hWnd = CreateWindow(argv_588, argv_587, WS_VISIBLE | WS_OVERLAPPEDWINDOW,
	  CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
	  return FALSE;
	}

	ShowWindow(hWnd, SW_SHOWMINIMIZED);
	UpdateWindow(hWnd);
	argv_573 = hWnd;

	DialogBox(argv_213, (LPCTSTR)argv_449, hWnd, (DLGPROC)argv_122);
	DestroyWindow(hWnd);
	return TRUE;
}

HDC argv_204;

LRESULT CALLBACK argv_606(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT argv_559;
	HDC argv_209;
	
	TCHAR szHello[argv_508];
	LoadString(argv_213, argv_472, szHello, argv_508);

	switch (message) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case argv_467:
				   DialogBox(argv_213, (LPCTSTR)argv_449, hWnd, (DLGPROC)argv_122);
				   break;
				case argv_468:
				   DestroyWindow(hWnd);
				   break;

				case argv_469:
					argv_531(hWnd,argv_532);
					break;

				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_PAINT:
			argv_209 = BeginPaint(hWnd, &argv_559);
			argv_204 = argv_209;
			// TODO: Add any drawing code here...
			RECT rt;
			GetClientRect(hWnd, &rt);
			DrawText(argv_209, szHello, strlen(szHello), &rt, DT_CENTER);
			EndPaint(hWnd, &argv_559);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

unsigned int argv_156 () {
	unsigned int argv_580 = 0;

	for (int i=0 ; i<argv_190.size() ; i++) {
		argv_580 += argv_190[i];
	}
	return (argv_580);
}

void argv_178 (char * _cptr, int _size) {
	unsigned int argv_580 = argv_156();

	for (int i=0 ; i<_size ; i++) {
		_cptr[i] = (_cptr[i] + argv_580) ^ 0x74;
	}
}

void argv_173 (char * _cptr, int _size) {
	unsigned int argv_580 = argv_156();

	for (int i=0 ; i<_size ; i++) {
		_cptr[i] = (_cptr[i] ^ 0x74) - argv_580;
	}
}

// 00 20 12 74 = exe (V1)
// 00 21 13 75 = exe (V2)
//
// 00 17 04 73 = zip (V1) 
// 00 18 05 74 = zip (V2)
argv_577 argv_186 (const char * _filename) {
	argv_577 id = argv_555;
	FILE * argv_189 = fopen (_filename, "rb");
	if (! argv_189) {
		id = argv_551;
	}
	else {
		unsigned char argv_589[4];
		int val;
		bool short_file = false;

		for (int i=0 ; i<4 ; i++) {
			val = fgetc (argv_189);
			if (val == EOF) {
				short_file = true;
				break;
			}
			else {
				argv_589[i] = (unsigned char) val;
			}
		}

		if (short_file == false) {
			if ((argv_589[0]==0x00) && (argv_589[1]==0x21) && (argv_589[2]==0x13) && (argv_589[3]==0x75)) {
				id = argv_553;		
			}
			else if ((argv_589[0]==0x00) && (argv_589[1]==0x20) && (argv_589[2]==0x12) && (argv_589[3]==0x74)) {
				id = argv_552;
			}
			else if ((argv_589[0]==0x00) && (argv_589[1]==0x18) && (argv_589[2]==0x05) && (argv_589[3]==0x74)) {
				id = argv_558;
			}
			else if ((argv_589[0]==0x00) && (argv_589[1]==0x17) && (argv_589[2]==0x04) && (argv_589[3]==0x73)) {
				id = argv_557;
			}
			else if ((argv_589[0]==0x4D) && (argv_589[1]==0x5A)) {
				id = argv_554;
			}
			else if((argv_589[0]==0x50) && (argv_589[1]==0x4B) && (argv_589[2]==0x03) && (argv_589[3]==0x04)) {
				id = argv_556;
			}
		}
		fclose (argv_189);
	}
	return (id);
}

bool argv_550 (const char * _filename) {
	bool bret = true;
	argv_148 mapper;
	DWORD file_size = 0;
	argv_591 * cptr = NULL;

	if (mapper.argv_520 (_filename, false, cptr, file_size) == false) {
		logger.argv_494 ("mmap failed for file : ", _filename);
		bret = false;
	}
	else {
		argv_591 current_key = 0x74;
		for (argv_593 i = 0 ; i<file_size ; i++) {
			cptr[i] = cptr[i] ^ current_key;
			current_key += 0x9;
		}
		mapper.argv_154 ();
	}
	return (bret);
}

// this function is called in both protect/unprotect cases.
bool argv_541 (const char * _filename, argv_593 _file_type, argv_591 _a, argv_591 _b, argv_591 _c, argv_591 _d) {
	bool bret = true;
	argv_148 mapper;
	DWORD file_size = 0;
	argv_591 * cptr = NULL;

	if (mapper.argv_520 (_filename, false, cptr, file_size) == false) {
		logger.argv_494 ("mmap failed for file : ", _filename);
		bret = false;
	}
	else {
		logger.argv_494 ("file size : ", file_size);
		argv_591 current_key = 0x74;
		cptr[0] = _a;
		cptr[1] = _b;
		cptr[2] = _c;
		cptr[3] = _d;

		if ((_file_type != argv_552) && (_file_type != argv_557)) {
			for (argv_593 i=4 ; i<file_size ; i++) {
				cptr[i] = cptr[i] ^ current_key;
				current_key++;
			}
			mapper.argv_154 ();
		}
	}
	return (bret);
}

bool argv_480 (const std::string& i_CurrentFilename) {
	bool bret = false;
	const char * Cptr = strstr (i_CurrentFilename.c_str(), argv_481.c_str());
	if (nullptr != Cptr) {
		bret = true;
	}
	return (bret);
}

bool argv_565 (const std::string& i_CurrentFilename) {
	bool bret = true;
	std::string NewFilename = i_CurrentFilename;
	if (argv_480 (i_CurrentFilename)) {
		NewFilename = argv_564 (i_CurrentFilename);
	}
	else {
		NewFilename += argv_481;
	}
	char BufTmp[4096];
	if (0 == MoveFile (i_CurrentFilename.c_str(), NewFilename.c_str())) {
		sprintf (BufTmp, "+++ argv_565 failed\nSourceFile=%s\nDestFile=%s\n", i_CurrentFilename.c_str(), NewFilename.c_str());
		MessageBox(argv_573, BufTmp, i_CurrentFilename.c_str(), MB_OK | MB_ICONERROR);
		bret = false;
	}
	else {
		//sprintf (BufTmp, "argv_565 Success\nSourceFile=%s\nDestFile=%s\n", i_CurrentFilename.c_str(), NewFilename.c_str());
		//MessageBox(argv_573, BufTmp, i_CurrentFilename.c_str(), MB_OK);
	}
	return (bret);
}

bool argv_548 (HWND _hwnd, const char * _filename, bool _silent_mode) {
	string filename;
	bool bret = true;
	
	if (_filename == NULL) {
		filename = argv_531 (_hwnd, argv_532);
	}
	else {
		filename = _filename;
	}
	if (filename != "") {
		SendDlgItemMessage(_hwnd, argv_284, WM_SETTEXT, 0, (LPARAM) filename.c_str());

		if (argv_184 (filename.c_str()) == false) {
			MessageBox(argv_573, "No such file !", "",MB_OK | MB_ICONERROR);
			bret = false;
		}
		else {
			argv_577 id = argv_186 (filename.c_str());
			if (id == argv_552) {
				if (_silent_mode == false) {
					MessageBox(argv_573, "This EXE file is already protected ! (by version 1.0)", "",MB_OK | MB_ICONWARNING);
				}
				bret = false;
			}
			else if (id == argv_553) {
				if (_silent_mode == false) {
					MessageBox(argv_573, "This EXE file is already protected ! (by version 2.0)", "",MB_OK | MB_ICONWARNING);
				}
				bret = false;
			}
			else if (id == argv_557) {
				if (_silent_mode == false) {
					MessageBox(argv_573, "This ZIP file is already protected ! (by version 1.0)", "",MB_OK | MB_ICONWARNING);
				}
				bret = false;
			}
			else if (id == argv_558) {
				if (_silent_mode == false) {
					MessageBox(argv_573, "This ZIP file is already protected ! (by version 2.0)", "",MB_OK | MB_ICONWARNING);
				}
				bret = false;
			}
			else if (id == argv_554) {
				bool bret = argv_541 (filename.c_str(), id, 0x00, 0x21, 0x13, 0x75);
				if (bret == false) {
					MessageBox(argv_573, "this EXE file could not be protected !", filename.c_str(), MB_OK | MB_ICONERROR);
					bret = false;
				}
				else if (_silent_mode == false) {
					MessageBox(argv_573, "EXE file protected succesfully", "",MB_OK);							
				}
			}
			else if (id == argv_556) {
				bool bret = argv_541 (filename.c_str(), id, 0x00, 0x18, 0x05, 0x74);
				if (bret == false) {
					MessageBox(argv_573, "this ZIP file could not be protected !", filename.c_str(), MB_OK | MB_ICONERROR);
					bret = false;
				}
				else if (_silent_mode == false) {
					MessageBox(argv_573, "ZIP file protected succesfully", filename.c_str(), MB_OK);	
				}
			}
			else if (id == argv_555) {
				MessageBox(argv_573, "unknown file type !", filename.c_str(), MB_OK | MB_ICONERROR);
				bret = false;
			}
			else {
				MessageBox(argv_573, "file type could not be determined !", filename.c_str(), MB_OK | MB_ICONERROR);
				bret = false;
			}
		}
	}
	if (true == bret) {
		bret = argv_565 (filename);
	}
	return (bret);
}

bool argv_549 (HWND _hwnd) {
	string dirname = argv_150 (_hwnd);
	if (dirname != "") {
		argv_577 nb_file		= 0;
		argv_577 nb_success		= 0;
		argv_577 nb_failed		= 0;
		SendDlgItemMessage (_hwnd, argv_284, WM_SETTEXT, 0, (LPARAM) dirname.c_str());

		if (SetCurrentDirectory (dirname.c_str()) == 0) {
			MessageBox(argv_573, "can't cd to directory !", dirname.c_str(), MB_OK | MB_ICONERROR);	
			return false;
		}
		WIN32_FIND_DATA FindData; 
		char tmp[512];

		HANDLE hFind = FindFirstFile ("*.exe", &FindData);
		if (hFind != INVALID_HANDLE_VALUE) {
			bool bret				= true;
			string	full_filename	= "";
			do {
				// if it is not a directory
				if (!(FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
					full_filename = dirname + "\\" + FindData.cFileName;
					nb_file++;
					bret = argv_548 (_hwnd, full_filename.c_str(), true);
					if (bret == true) {
						nb_success++;
					}
					else {
						nb_failed++;
					}
					argv_579 (tmp, 512, "%d processed (%d success, %d failed)", nb_file, nb_success, nb_failed);
					tmp[511] = '\0';
					SendDlgItemMessage (_hwnd, argv_371, WM_SETTEXT, 0, (LPARAM) tmp);
				}
			}
			while (FindNextFile (hFind, &FindData)) ;
			FindClose (hFind);
		}

		hFind = FindFirstFile ("*.zip", &FindData);
		if (hFind != INVALID_HANDLE_VALUE) {
			bool bret				= true;
			string	full_filename	= "";
			do {
				// if it is not a directory
				if (!(FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
					full_filename = dirname + "\\" + FindData.cFileName;
					nb_file++;
					bret = argv_548 (_hwnd, full_filename.c_str(), true);
					if (bret == true) {
						nb_success++;
					}
					else {
						nb_failed++;
					}
					argv_579 (tmp, 512, "%d processed (%d success, %d failed)", nb_file, nb_success, nb_failed);
					tmp[511] = '\0';
					SendDlgItemMessage (_hwnd, argv_371, WM_SETTEXT, 0, (LPARAM) tmp);
				}
			}
			while (FindNextFile (hFind, &FindData)) ;
			FindClose (hFind);
		}
	
	}
	return(true);
}


bool argv_598 (HWND _hwnd, const char * _filename, bool _silent_mode) {
	bool bret = true;
	string filename;
	
	if (_filename == NULL) {
		filename = argv_531 (_hwnd, argv_532);
	}
	else {
		filename = _filename;
	}

	if (filename != "") {
		SendDlgItemMessage (_hwnd, argv_284, WM_SETTEXT, 0, (LPARAM) filename.c_str());

		if (argv_184 (filename.c_str()) == false) {
			MessageBox(argv_573, "No such file !", filename.c_str(), MB_OK | MB_ICONERROR);
			bret = false;
		}
		else {
			argv_577 id = argv_186 (filename.c_str());
			if ((id == argv_552) || (id == argv_553)) {
				bool bret = argv_541 (filename.c_str(), id, 0x4D, 0x5A, 0x00, 0x00);
				if (bret == false) {
					MessageBox(argv_573, "this EXE file could not be unprotected !", filename.c_str(), MB_OK | MB_ICONERROR);
					bret = false;
				}
				else if (_silent_mode == false) {
					MessageBox(argv_573, "EXE file unprotected succesfully", filename.c_str(), MB_OK);	
				}
			}
			else if ((id == argv_558) || (id == argv_557)) {
				bool bret = argv_541 (filename.c_str(), id, 0x50, 0x4B, 0x03, 0x04);
				if (bret == false) {
					MessageBox(argv_573, "this ZIP file could not be unprotected !", filename.c_str(), MB_OK | MB_ICONERROR);
					bret = false;
				}
				else if (_silent_mode == false) {
					MessageBox(argv_573, "ZIP file unprotected succesfully", filename.c_str(), MB_OK);	
				}
			}
			else if (id == argv_554) {
				if (_silent_mode == false) {
					MessageBox(argv_573, "This EXE file is not protected !", "",MB_OK | MB_ICONWARNING);
				}
				bret = false;
			}
			else if (id == argv_556) {
				if (_silent_mode == false) {
					MessageBox(argv_573, "This ZIP file is not protected !", "",MB_OK | MB_ICONWARNING);
				}
				bret = false;
			}
			else if (id == argv_555) {
				if (_silent_mode == false) {
					MessageBox(argv_573, "unknown file type !", filename.c_str(), MB_OK | MB_ICONERROR);
				}
				bret = false;
			}
			else {
				MessageBox(argv_573, "file type could not be determined !", filename.c_str(), MB_OK | MB_ICONERROR);
				bret = false;
			}
		}
	}
	if (true == bret) {
		bret = argv_565 (filename);
	}
	return (bret);
}

void argv_599 (HWND _hwnd) {
	string dirname = argv_150 (_hwnd);
	if (dirname != "") {
		argv_577 nb_file		= 0;
		argv_577 nb_success		= 0;
		argv_577 nb_failed		= 0;

		SendDlgItemMessage (_hwnd, argv_284, WM_SETTEXT, 0, (LPARAM) dirname.c_str());

		if (SetCurrentDirectory (dirname.c_str()) == 0) {
			MessageBox(argv_573, "can't cd to directory !", dirname.c_str(), MB_OK | MB_ICONERROR);	
			return;
		}
		WIN32_FIND_DATA FindData; 
		char tmp[512];

		HANDLE hFind = FindFirstFile ("*.exe", &FindData);
		if (hFind != INVALID_HANDLE_VALUE) {
			bool bret				= true;
			string	full_filename	= "";
			do {
				// if it is not a directory
				if (!(FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
					full_filename = dirname + "\\" + FindData.cFileName;
					nb_file++;
					bret = argv_598 (_hwnd, full_filename.c_str(), true);
					if (bret == true) {
						nb_success++;
					}
					else {
						nb_failed++;
					}
					argv_579 (tmp, 512, "%d processed (%d success, %d failed)", nb_file, nb_success, nb_failed);
					tmp[511] = '\0';
					SendDlgItemMessage (_hwnd, argv_371, WM_SETTEXT, 0, (LPARAM) tmp);
				}
			}
			while (FindNextFile (hFind, &FindData)) ;
			FindClose (hFind);
		}

		hFind = FindFirstFile ("*.zip", &FindData);
		if (hFind != INVALID_HANDLE_VALUE) {
			bool bret				= true;
			string	full_filename	= "";
			do {
				// if it is not a directory
				if (!(FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
					full_filename = dirname + "\\" + FindData.cFileName;
					nb_file++;
					bret = argv_598 (_hwnd, full_filename.c_str(), true);
					if (bret == true) {
						nb_success++;
					}
					else {
						nb_failed++;
					}
					argv_579 (tmp, 512, "%d processed (%d success, %d failed)", nb_file, nb_success, nb_failed);
					tmp[511] = '\0';
					SendDlgItemMessage (_hwnd, argv_371, WM_SETTEXT, 0, (LPARAM) tmp);
				}	
			}
			while (FindNextFile (hFind, &FindData)) ;
			FindClose (hFind);
		}
	}
}

LRESULT CALLBACK argv_122(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)
	{
		case WM_INITDIALOG:
			argv_573 = hDlg;
			argv_145 (hDlg);
			SendDlgItemMessage (hDlg, argv_284, WM_SETTEXT, 0, (LPARAM) "");
			SendDlgItemMessage (hDlg, argv_371, WM_SETTEXT, 0, (LPARAM) "Ready");
			logger.argv_538 ("C:\\log.txt");
			return TRUE;

		case WM_COMMAND:
			switch(LOWORD(wParam)) {
				case IDOK:
				case IDCANCEL:
					ShowWindow (hDlg, SW_SHOW);
					EndDialog(hDlg, LOWORD(wParam));
					return TRUE;
				break;

				case argv_364:
					argv_548 (hDlg, NULL, false);
					break;

				//case argv_365:
				//	argv_549 (hDlg);
				//	break;

				case argv_389:
					argv_598 (hDlg, NULL, false);
					break;

				//case argv_390:
				//	argv_599 (hDlg);
				//	break;
			}
	}
	return FALSE;
}