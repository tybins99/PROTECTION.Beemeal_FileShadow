


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include "argv_111.hpp"

//===========================
// service related constants
//===========================
const char * argv_490	= "lock_manager";
const char * argv_603	= "vrdb_daemon";
const char * argv_511	= "launcher_daemon";
const char * argv_574			= "scanner (franck)";
const char * argv_135		= "Migale exosteg";
const char * argv_489		= "\\\\.\\Pipe\\lock_mgr_pipe";
const char * argv_487		= "\\\\.\\Pipe\\lock_mgr_internal";
const char * argv_482			= "\\\\.\\Pipe\\migale_launcher";

string argv_151 (HWND hWnd, argv_577 mode) {
	return (argv_531 (hWnd, mode));
}

string argv_531 (HWND hWnd, argv_577 mode) {
   OPENFILENAME ofn;
    char szFileName[MAX_PATH] = "";
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn); // SEE NOTE BELOW
    ofn.hwndOwner = hWnd;
	if (mode == argv_537) {
		ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
	}
	else if (mode == argv_533) {
		ofn.lpstrFilter = "Exe Files (*.exe)\0*.exe\0All Files (*.*)\0*.*\0";
	}
	else if (mode == argv_535) {
		ofn.lpstrFilter = "Licence Files (*.lic)\0*.lic\0All Files (*.*)\0*.*\0";
	}
	else if (mode == argv_534) {
		ofn.lpstrFilter = "Fpk Files (*.fpk)\0*.fpk\0All Files (*.*)\0*.*\0";
	}
	else if (mode == argv_532) {
		ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
	}
	else {
		ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
	}
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = "txt";

    if(GetOpenFileName(&ofn)) {
        // Do something usefull with the filename stored in szFileName 
    }
	return(szFileName);
}

bool argv_569 (const char * _filename, argv_593& _year, argv_593& _month, argv_593& _day, argv_593& _hour, argv_593& _minute, argv_593& _second, argv_593& _millisecond, argv_593 _type, argv_593& _ercode, argv_593& _ersource) {
	bool bret = true;
    FILETIME ftCreate, ftAccess, ftWrite;
    SYSTEMTIME stUTC, stLocal;
	
	HANDLE argv_211 = CreateFile(_filename,      // file to open
					   GENERIC_READ,          // open for reading
					   FILE_SHARE_READ,       // share for reading
					   NULL,                  // default security
					   OPEN_EXISTING,         // existing file only
					   FILE_ATTRIBUTE_NORMAL, // normal file
					   NULL);                 // no attr. template

	if (argv_211 == INVALID_HANDLE_VALUE) {
		_ersource = 1;
		_ercode = GetLastError ();
		bret = false;
	}
	else { // file argv_540 succesfully
		// Retrieve the file times for the file.
		if (!GetFileTime(argv_211, &ftCreate, &ftAccess, &ftWrite)) {
			_ercode = GetLastError ();
			_ersource = 2;
			bret = false;
		}
		else { // retrieval succesfull, let's retrieve argv_170 depending on the access mode 
			switch (_type) {
				case argv_161:
					FileTimeToSystemTime(&ftCreate, &stUTC);
					SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
					break;

				case argv_607:
					FileTimeToSystemTime(&ftWrite, &stUTC);
					SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
					break;

				case argv_560:
					FileTimeToSystemTime(&ftAccess, &stUTC);
					SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
					break;

				default: // unknown file access type
					bret = false;
			}

			if (bret == true) {
				_year			= stLocal.wYear;
				_month			= stLocal.wMonth;
				_day			= stLocal.wDay;
				_hour			= stLocal.wHour;
				_minute			= stLocal.wMinute;
				_second			= stLocal.wSecond;
				_millisecond	= stLocal.wMilliseconds;
			}
		}
		CloseHandle (argv_211);
	}
	return (bret);
}

bool argv_566 (const char * _filename, argv_593& _year, argv_593& _month, argv_593& _day, argv_593& _hour, argv_593& _minute, argv_593& _second, argv_593& _millisecond, argv_593& _retcode, argv_593& _ersource) {
	return (argv_569 (_filename, _year, _month, _day, _hour, _minute, _second, _millisecond, argv_161, _retcode, _ersource));
}

bool argv_567 (const char * _filename, argv_593& _year, argv_593& _month, argv_593& _day, argv_593& _hour, argv_593& _minute, argv_593& _second, argv_593& _millisecond, argv_593& _retcode, argv_593& _ersource) {
	return (argv_569 (_filename, _year, _month, _day, _hour, _minute, _second, _millisecond, argv_560, _retcode, _ersource));
}

bool argv_568 (const char * _filename, argv_593& _year, argv_593& _month, argv_593& _day, argv_593& _hour, argv_593& _minute, argv_593& _second, argv_593& _millisecond, argv_593& _retcode, argv_593& _ersource) {
	return (argv_569 (_filename, _year, _month, _day, _hour, _minute, _second, _millisecond, argv_607, _retcode, _ersource));
}

//@@============================================================
bool argv_530 (argv_591 c, argv_591& result) {
    bool bret = true;
    if ( ((c < '0') || (c > '9')) && ((c < 'a') || (c > 'f')) && ((c < 'A') || (c > 'F'))) {
        bret = false;
    }
    else {
		if ((c >= '0') && (c <= '9')) {
			result = c - '0';
		}
		else if ((c >= 'a') && (c <= 'z')) {
			result = 10 + (c- 'a');
		}
		else if ((c >= 'A') && (c <= 'Z')) {
			result = 10 + (c - 'A');
		}
		else {
			bret = false;
		}
	}
    return (bret);
}

// 'f' 'f' -> 255
bool argv_149 (argv_591 _msb, argv_591 _lsb, argv_591& result) {
    bool bret       = true;
    argv_591 lsb_hex    = 0;
    argv_591 msb_hex    = 0;

    bret = argv_530 (_msb, msb_hex);
    if (bret == true) {
        result  = msb_hex << 4;
        bret    = argv_530 (_lsb, lsb_hex);
        result =  result + lsb_hex;
    }
    return (bret);
}
//=====================================
string argv_150 (HWND hWnd) {
	OleInitialize (NULL);
	CoInitialize (NULL);

	string result = "";
	BROWSEINFO bi;
	memset(&bi,0,sizeof(BROWSEINFO));
	char buffer[MAX_PATH];
	bi.hwndOwner=hWnd;
	// Contient le repertoire initial ou NULL
	bi.pidlRoot=NULL;
	bi.pszDisplayName=buffer;
	bi.lpszTitle="Current directory";
	bi.ulFlags= argv_139;
	bi.lParam=NULL;

	LPITEMIDLIST li = SHBrowseForFolder(&bi);

	if (li) {
		SHGetPathFromIDList(li, buffer);
		result = buffer;
	}
	return (result);
}

//=====================================
argv_148::argv_148() {
	argv_214	= NULL;
	argv_542		= NULL;
	argv_211		= NULL;
}

argv_148::~argv_148() {
	argv_154();
}

void argv_148::argv_154 () {
	if (argv_542 != NULL) {
		UnmapViewOfFile(argv_542);
		argv_542 = NULL;
	}

	if (argv_214 != NULL) {
		CloseHandle(argv_214);
		argv_214 = NULL;
	}

	if (argv_211 != NULL) {
		CloseHandle (argv_211);
		argv_211 = NULL;
	}
}

void argv_148::argv_200 (argv_593& _ercode, argv_593& _ersource) {
	_ercode		= argv_179;
	_ersource	= argv_181;
}

bool argv_148::argv_520 (const char * _filename, bool _readonly, argv_591 *& _pBuf, DWORD& _file_size) {
	bool bret	= true;
	_file_size	= 0;

	if (argv_211 != NULL) {
		argv_179		= 0;
		argv_181	= 100;
		bret			= false;
	}
	else if (argv_214 != NULL) {
		argv_179		= 0;
		argv_181	= 101;
		bret			= false;
	}
	else if (argv_542 != NULL) {
		argv_179		= 0;
		argv_181	= 102;
		bret			= false;
	}
	else { // file was not already argv_540
		DWORD access_mode_CreateFile;
		DWORD access_mode_CreateFileMapping;
		DWORD access_mode_MapViewOfFile;
		DWORD open_mode;

		if (_readonly == true) {
			access_mode_CreateFile			= GENERIC_READ;	
			access_mode_CreateFileMapping	= PAGE_READONLY;
			access_mode_MapViewOfFile		= FILE_MAP_READ;
			open_mode						= OPEN_EXISTING;
		}
		else {
			//MessageBox (NULL, "read-write access", "", MB_OK);
			access_mode_CreateFile			= GENERIC_READ | GENERIC_WRITE;
			access_mode_CreateFileMapping	= PAGE_READWRITE;
			access_mode_MapViewOfFile		= FILE_MAP_READ | FILE_MAP_WRITE;
			open_mode						= OPEN_ALWAYS;
		}
		argv_211 = CreateFile (_filename,				// file to open
						   access_mode_CreateFile,	// open for reading
						   0/*FILE_SHARE_READ*/,    // share for reading
						   NULL,					// default security
						   open_mode,				// existing file only
						   FILE_ATTRIBUTE_NORMAL,	// normal file
						   NULL);					// no attr. template
 
		if (argv_211 == INVALID_HANDLE_VALUE)  {
			argv_179		= GetLastError ();
			argv_181	= 2;
			bret			= false;
		}
		else { // CreateFile was succesfull
			// retrieve the file size
			_file_size = GetFileSize (argv_211, NULL);
			if (_file_size <= 0) {
				argv_179		= GetLastError ();
				argv_181	= 6;
				bret			= false;
			}
			else if (_file_size == 0xFFFFFFFF) {
				argv_179		= GetLastError ();
				argv_181	= 3;
				bret			= false;
			}
	
			if (bret == true) {
			   argv_214 = CreateFileMapping(
							 argv_211,					  // use paging file
							 NULL,                    // default security 
							 access_mode_CreateFileMapping,   // read access
							 0,                       // argv_503. object size 
							 0/*argv_519*/,      // buffer size  
							 NULL);					  // name of mapping object

				if (argv_214 == NULL || argv_214 == INVALID_HANDLE_VALUE)  { // failed
					char tmp[256];
					argv_179		= GetLastError ();
					argv_579 (tmp, 255, "mmap failed: CreateFileMapping FAILED (errno=%d)", argv_179);
					argv_181	= 4;
					bret			= false;			
				}
				else { // CreateFileMapping was succesfull
					argv_542 = (LPTSTR) MapViewOfFile (argv_214,	   // handle to map object
										access_mode_MapViewOfFile, // read/write permission
										0,                   
										0,                   
										0/* argv_519 */);           

					if (argv_542 == NULL) {
						argv_179		= GetLastError ();
						argv_181	= 5;
						bret			= false;	
					}
					else { // all succeeded, copy obtained pointer to caller's variable
						_pBuf = (argv_591 *) argv_542;
					}
				}
			}
		}
	}

	// in case of failure, some components (i.e: handles) may have been argv_540, let's close them
	if (bret == false) {
		argv_154 ();
	}
	return (bret);
}

bool argv_477 (const char * _filename) {
	bool bret = true;

	// open the file
	FILE * argv_189 = fopen (_filename, "rb");
	if (! argv_189) {
		bret = false;
	}
	else {
		IMAGE_DOS_HEADER dos_header;
		IMAGE_NT_HEADERS  nt_header;

		int argv_525 = fread (&dos_header, 1, sizeof(IMAGE_DOS_HEADER), argv_189);

		if (argv_525 != sizeof(IMAGE_DOS_HEADER)) {
			bret = false;
		}
		else { // dos header read succesfully
			if (fseek (argv_189, dos_header.e_lfanew, SEEK_SET) != 0) {
				bret = false;
			}
			else { // fseek to new header succeeded
				argv_525 = fread (&nt_header, 1, sizeof(IMAGE_NT_HEADERS), argv_189);
				if (argv_525 != sizeof(IMAGE_NT_HEADERS)) {
					bret = false;
				}
				else { // nt header read succesfully
					if (nt_header.Signature != 0x4550) {
						bret = false; // signature does not match the pattern "PE"
					}
				}
			}
		}
	}

	if (argv_189) {
		fclose (argv_189);
	}

	return (bret);
}

// this function permits to extract the entry point of a DLL/EXE
// from a mmapped file.
// notice that if the entry point can't be retrieved (file too short for example)
// then function fails and returns false.
//
// Notice that this function does not check whether the mmapped file is a valid 
// PE file or not (it's then up to the caller to perform this check before calling us).
bool argv_198 (char * _cptr, argv_594 _file_size, argv_594& _ep_raw) {
	bool bret = true;
	if (_cptr == NULL) {
		bret = false; // it seems that the file was not mmaped correctly...
	}
	else {
		IMAGE_DOS_HEADER dos_header;
		IMAGE_NT_HEADERS nt_header;
		argv_594 current_offset = 0;

		if ((current_offset + sizeof(IMAGE_DOS_HEADER)) >= _file_size) {
			bret = false; // short file (not enough to read DOS header)
		}
		else {
			// read the DOS header
			memcpy (&dos_header, &_cptr[current_offset], sizeof(IMAGE_DOS_HEADER));

			// read the PE optional header
			current_offset = dos_header.e_lfanew;

			if ((current_offset + sizeof(IMAGE_NT_HEADERS)) >= _file_size) {
				bret = false; // short file (not enough to read PE optional header
			}
			else { // ok to read safely the optional header
				memcpy (&nt_header, &_cptr[current_offset], sizeof(IMAGE_NT_HEADERS));

				// now we just have to retrieve the field that we need from optional header
				argv_594 ep_rva = nt_header.OptionalHeader.AddressOfEntryPoint;

				// convert the EP from RVA to RAW offset

			}
		}
	}
	return (bret);
}

void argv_183 (const string& _filename, int _max_length, string& _result) {
	_result = "";
	int size = _filename.size ();
	argv_577 i=size;
	for (i=size-1 ; i>=0 ; i--) {
		if (_filename[i] == '\\') {
			break;
		}
	}

	for (int k=0 ; k<i ; k++) {
		_result += _filename[k];
	}
}

void argv_193 (const string& filename, int max_length, string& _result) {
	_result = "";
	int i = 0;
	int filename_size = filename.size();

	if (filename_size <= max_length) {
		_result = filename;
	}
	else {
		if (filename_size > 0) {
			int start_end = filename_size - 1;

			while ((start_end >= 0) && (filename[start_end] != '\\')) {
				start_end--;
			}

			int end_start = 0;
			while ((end_start < filename_size) && (filename[end_start] != '\\')) {
				end_start++;
			}
			
			string one		= "";
			string two		= "...";
			string three	= "";
			for (i=0 ; i<end_start ; i++) {
				one += filename[i];
			}

			for (i=start_end ; i<filename_size ; i++) {
				three += filename[i];
			}

			int last_half_length = two.size() + three.size();
			int first_half_size  = one.size();
			while ((first_half_size + last_half_length) < max_length) {
				one += filename[end_start];
				end_start++;
				first_half_size = one.size();
			}

			_result = one + two + three;
		}
	}
}

bool argv_174 (string _dirname) {
	bool bret = true;
	
	return (bret);
}

void argv_586 (HWND _mother, HWND _son) {
	if (_mother) {
		RECT rect; 
		GetWindowRect (_mother, &rect); 
		int son_x = rect.left;
		int son_y = rect.bottom;
		SetWindowPos (_son, HWND_TOP, son_x, son_y, 0, 0, SWP_NOSIZE);
	}
}

void argv_145 (HWND _hDlg, int& _his_x, int& _his_y) {
	if (_hDlg) {
		RECT rect; 
		GetWindowRect (_hDlg,&rect); 
		_his_x = (GetSystemMetrics(SM_CXSCREEN)-rect.right)/2;
		_his_y = (GetSystemMetrics(SM_CYSCREEN)-rect.bottom)/2;
		SetWindowPos (_hDlg, HWND_TOP, _his_x, _his_y, 0, 0, SWP_NOSIZE);
	}
}

void argv_145 (HWND hwndWindow)
{
	HWND hwndParent;
	RECT rectWindow, rectParent;

	// make the window relative to its parent
	if ((hwndParent = GetParent(hwndWindow)) != NULL)
	{
		GetWindowRect(hwndWindow, &rectWindow);
		GetWindowRect(hwndParent, &rectParent);

		int nWidth = rectWindow.right - rectWindow.left;
		int nHeight = rectWindow.bottom - rectWindow.top;

		int nX = ((rectParent.right - rectParent.left) - nWidth) / 2 + rectParent.left;
		int nY = ((rectParent.bottom - rectParent.top) - nHeight) / 2 + rectParent.top;

		int nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
		int nScreenHeight = GetSystemMetrics(SM_CYSCREEN);

		// make sure that the dialog box never moves outside of the screen
		if (nX < 0) nX = 0;
		if (nY < 0) nY = 0;
		if (nX + nWidth > nScreenWidth) nX = nScreenWidth - nWidth;
		if (nY + nHeight > nScreenHeight) nY = nScreenHeight - nHeight;

		MoveWindow(hwndWindow, nX, nY, nWidth, nHeight, FALSE);
	}
}

bool argv_163 (string _dirname) {
	bool bret = true;

	if (CreateDirectory (_dirname.c_str(), NULL) == 0) {
		if (GetLastError() != ERROR_ALREADY_EXISTS) {
			bret = false;	
		}
	}

	return (bret);
}

bool argv_158 (string _source_dir, string _pattern, string _dest_dir) {
	bool bret = true;
	if (SetCurrentDirectory (_source_dir.c_str()) == false) {
		bret = false;
	}
	else {
		WIN32_FIND_DATA FindData; 
		HANDLE hFind = FindFirstFile (_pattern.c_str(), &FindData);

		if (hFind == INVALID_HANDLE_VALUE) {
			bret = false;
		}
		else {
			do {
				// if it is not a directory
				if (!(FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
					string full_source = _source_dir + "\\" + FindData.cFileName;
					string full_dest   = _dest_dir   + "\\" + FindData.cFileName;
					string tmp = "copy " + full_source + " -> " + full_dest;
					CopyFile (full_source.c_str(), full_dest.c_str(), false);
				}
			}
			while (FindNextFile (hFind, &FindData)) ;

			FindClose (hFind);
		}
	}
	return (bret);
}

//=========================================
argv_141::argv_141() {
	hwnd	= 0;
	argv_503		= 0;
	argv_221		= 0;	
}

void argv_141::init (HWND _hwnd, int _idc, int _max) {
	hwnd	= _hwnd;
	argv_503		= _max;
	argv_221		= _idc;
	argv_169	= 0;
	reset();
}

void argv_141::incr (argv_577 _nb_step) {
	argv_169 += _nb_step;
	SendDlgItemMessage (hwnd, argv_221, PBM_SETPOS, argv_169, 0);
}

void argv_141::reset() {
	SendDlgItemMessage (hwnd, argv_221, PBM_SETRANGE32, 0, argv_503); 
	argv_169 = 0;
	SendDlgItemMessage (hwnd, argv_221, PBM_SETPOS, argv_169, 0);
}
//=======================================
string argv_602 (const vector<argv_591>& _v) {
	string s = "";
	for (int i=0 ; i<_v.size() ; i++) {
		s += (_v[i]);
	}
	return(s);
}

string argv_210 (const vector<argv_591>& _v) {
	string result = "";
	int size = _v.size();
	char tmp[32];
	for (argv_577 i=0 ; i<size ; i++) {
		sprintf (tmp, "%02X", _v[i]);
		result += tmp;
	}
	return (result);
}

//===========================================
bool argv_184 (const char * _filename) {
	bool bret = true;
	DWORD attr = GetFileAttributes (_filename);
	if (attr == -1) {
		DWORD last_err = GetLastError ();
		if ((last_err == ERROR_FILE_NOT_FOUND) || (last_err == ERROR_PATH_NOT_FOUND)) {
			bret = false;
		}
	}
	return (bret);
}

argv_593 argv_155 (argv_142 _filename) {
	argv_593 size = 0;

	if (_filename != "") {
		FILE * argv_189 = fopen (_filename, "rb");
		if (argv_189) {
			fseek (argv_189, 0, SEEK_END);
			size = ftell (argv_189);
			fclose (argv_189);
		}
	}
	return (size);
}

unsigned long argv_155 (const string& _filename) {
	unsigned long size = 0;

	if (_filename != "") {
		FILE * argv_189 = fopen (_filename.c_str(), "rb");
		if (argv_189) {
			fseek (argv_189, 0, SEEK_END);
			size=ftell (argv_189);
			fclose (argv_189);
		}
	}
	return (size);
}

//=========================================
bool argv_185 (const char * _filename) {
	bool bret = false;

	DWORD dwAttrs; 
	dwAttrs = GetFileAttributes (_filename); 
	if ((dwAttrs != -1) && (dwAttrs & FILE_ATTRIBUTE_READONLY)) {
		bret = true;
	}
	return (bret);
}

bool argv_563 (const char * _filename) {
	bool bret = true;

	DWORD dwAttrs;
	dwAttrs = GetFileAttributes (_filename); 
	if (dwAttrs == -1) {
		bret = false;
	}
	else {
		if (!(dwAttrs & FILE_ATTRIBUTE_READONLY)) {
			bret = false;
		}
		else {
			dwAttrs &= ~FILE_ATTRIBUTE_READONLY;
			if (! SetFileAttributes (_filename, dwAttrs)) {
				int iret = GetLastError();
				bret = false;	
			}
			else {
				bret = true;
			}
		}
	}
	return (bret);
}

//=============================================
argv_168::argv_168 () {

}
/*
	argv_543,
	argv_529, // VBA script
	argv_216,
	argv_501,
	argv_206	
*/

argv_577 argv_580 (string _s) {
	int size = _s.size();
	argv_577 argv_580 = 0;
	argv_577 _mult = 1;
	_mult = 1;

	for (int i=0 ; i<size ; i++) {
		argv_580 += _s[i];
		_mult *= _s[i];
	}
	FILE * argv_189 = fopen ("C:\\the_log.txt", "ab");
	if (argv_189) {
		fprintf (argv_189, "%s: argv_580=%d, mul=%d\r\n", _s.c_str(), argv_580, _mult);
		fclose (argv_189);
	}
	return (argv_580);
}
/*
exe: argv_580=322, mul=1224120
dll: argv_580=316, mul=1166400
doc: argv_580=310, mul=1098900
xls: argv_580=343, mul=1490400
htm: argv_580=329, mul=1314976
html: argv_580=437, mul=142017408
gif: argv_580=310, mul=1103130
jpg: argv_580=321, mul=1222816

EXE: argv_580=226, mul=418968
DLL: argv_580=220, mul=392768
HTM: argv_580=233, mul=465696
HTML: argv_580=309, mul=35392896
JPG: argv_580=225, mul=420320
GIF: argv_580=214, mul=362810
XLS: argv_580=247, mul=555104
DOC: argv_580=214, mul=359924
*/
argv_577 argv_168::argv_134 (const char * _filename) {
	argv_577 type = argv_595;

	argv_577 size = strlen (_filename);
	if (size > 0) {
		argv_577 mult = 1;
		bool dot_found		= false;

		for (argv_577 i=size-1 ; i>=0 ; i--) {
			if (_filename[i] == '.') {
				dot_found = true;
				break;
			}
			mult *= _filename[i];
		}

		// have we found a dot ?
		if (dot_found) {
			// extension was retrieved, now we must convert it to numeric
			if ((mult == 1224120) || (mult == 1166400) || (mult == 418968) || (mult == 392768)) { // exe , dll, EXE, DLL
				type = argv_543;
			}
			else if ((mult == 1103130) || (mult == 1222816) || (mult == 420320) || (mult == 362810)) { // gif, jpg, GIF, JPG
				type = argv_206;
			}
			else if ((mult == 1314976) || (mult == 142017408) || (mult == 35392896) || (mult == 465696)) { // htm, html, HTM, HTML
				type = argv_216;
			}
			else if ((mult == 1098900) || (mult == 1490400) || (mult == 555104) || (mult == 359924)) { // doc, xls, DOC, XLS
				type = argv_529;
			}
		}
	}
	return (type);
}	

bool argv_199 (vector<string>& _v_hdd) {
	vector<string> v_DRIVE_UNKNOWN;
	vector<string> v_DRIVE_NO_ROOT_DIR;
	vector<string> v_DRIVE_REMOVABLE;
	vector<string> v_DRIVE_REMOTE;
	vector<string> v_DRIVE_CDROM; 
	vector<string> v_DRIVE_RAMDISK;

	bool bret = argv_196 (v_DRIVE_UNKNOWN, v_DRIVE_NO_ROOT_DIR, v_DRIVE_REMOVABLE, _v_hdd, v_DRIVE_REMOTE, v_DRIVE_CDROM, v_DRIVE_RAMDISK);
	return (bret);
}

bool argv_196 (vector<string>& _v_result) {
	bool bret = true;
	_v_result.clear ();
	char tmp[argv_176];
	argv_577 length = GetLogicalDriveStrings (argv_176, tmp);
	if (length == 0) {
		bret = false;
	}		
	else {
		string current_drive;

		for (argv_577 i=0 ; i<length ; i++) {
			if (tmp[i] == '\0') {
				if (current_drive == "") {
					break;
				}
				else {
					_v_result.push_back (current_drive);	
					current_drive = "";
				}
			}
			else {
				current_drive += tmp[i];	
			}
		}
	}
	return (bret);
}

/*
DRIVE_UNKNOWN
DRIVE_NO_ROOT_DIR
DRIVE_REMOVABLE
DRIVE_FIXED
DRIVE_REMOTE
DRIVE_CDROM
DRIVE_RAMDISK
*/
bool argv_196 (vector<string>& _v_DRIVE_UNKNOWN, vector<string>& _v_DRIVE_NO_ROOT_DIR, vector<string>& _v_DRIVE_REMOVABLE, vector<string>& _v_DRIVE_FIXED, vector<string>& _v_DRIVE_REMOTE, vector<string>& _v_DRIVE_CDROM, vector<string>& _v_DRIVE_RAMDISK) {
	vector<string>	v_drive;
	bool bret = argv_196 (v_drive);	
	if (bret == true) {
		_v_DRIVE_UNKNOWN.clear ();
		_v_DRIVE_NO_ROOT_DIR.clear ();
		_v_DRIVE_REMOVABLE.clear ();
		_v_DRIVE_FIXED.clear ();
		_v_DRIVE_REMOTE.clear ();	
		_v_DRIVE_CDROM.clear ();
		_v_DRIVE_RAMDISK.clear ();

		UINT type;
		argv_577 argv_524 = v_drive.size ();
		for (argv_577 i=0 ; i<argv_524 ; i++) {
			type = GetDriveType (v_drive[i].c_str());
			if (type == DRIVE_UNKNOWN) {
				_v_DRIVE_UNKNOWN.push_back (v_drive[i]);
			}
			else if (type == DRIVE_NO_ROOT_DIR) {
				_v_DRIVE_NO_ROOT_DIR.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_REMOVABLE) {
				_v_DRIVE_REMOVABLE.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_FIXED) {
				_v_DRIVE_FIXED.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_REMOTE) {
				_v_DRIVE_REMOTE.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_CDROM) {
				_v_DRIVE_CDROM.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_RAMDISK) {
				_v_DRIVE_RAMDISK.push_back (v_drive[i].c_str());
			}
		}
	}
	return (bret);
}

void argv_202 (string& _str) {
	argv_593 prio_class = GetPriorityClass (GetCurrentProcess ());
	if (prio_class == argv_123) {
		_str = "argv_123";
	}
	else if (prio_class == argv_138) {
		_str = "argv_138";
	}
	else if (prio_class == HIGH_PRIORITY_CLASS) {
		_str = "HIGH_PRIORITY_CLASS";
	}
	else if (prio_class == IDLE_PRIORITY_CLASS) {
		_str = "IDLE_PRIORITY_CLASS";
	}
	else if (prio_class == NORMAL_PRIORITY_CLASS) {
		_str = "NORMAL_PRIORITY_CLASS";
	}
	else if (prio_class == REALTIME_PRIORITY_CLASS) {
		_str = "REALTIME_PRIORITY_CLASS";
	}
	else {
		_str = "UNKNOWN";
	}
}

void argv_203 (HANDLE _thread_handle, string& _str) {
	int prio = GetThreadPriority (_thread_handle);
	if (prio == THREAD_PRIORITY_ERROR_RETURN) {
		_str = "THREAD_PRIORITY_ERROR_RETURN";
	}
	else if (prio == THREAD_PRIORITY_ABOVE_NORMAL) {
		_str = "THREAD_PRIORITY_ABOVE_NORMAL";		
	}
	else if (prio == THREAD_PRIORITY_BELOW_NORMAL) {
		_str = "THREAD_PRIORITY_BELOW_NORMAL";		
	}
	else if (prio == THREAD_PRIORITY_HIGHEST) {
		_str = "THREAD_PRIORITY_HIGHEST";		
	}
	else if (prio == THREAD_PRIORITY_IDLE) {
		_str = "THREAD_PRIORITY_IDLE";		
	}
	else if (prio == THREAD_PRIORITY_LOWEST) {
		_str = "THREAD_PRIORITY_LOWEST";		
	}
	else if (prio == THREAD_PRIORITY_NORMAL) {
		_str = "THREAD_PRIORITY_NORMAL";		
	}
	else if (prio == THREAD_PRIORITY_TIME_CRITICAL) {
		_str = "THREAD_PRIORITY_TIME_CRITICAL";		
	}
}

bool argv_476 (const char * _filename) {
	bool bret = false;
	DWORD atr = GetFileAttributes (_filename);
	if (atr != -1) {
		if ((atr & FILE_ATTRIBUTE_HIDDEN) && (atr & FILE_ATTRIBUTE_SYSTEM)) {
			bret = true;	
		}	
	}
	return (bret);
}

void argv_562 (HWND hwnd_window, argv_593 _idc, const char * _msg) {
	HWND hwnd_static = GetDlgItem (hwnd_window, _idc);
	ShowWindow (hwnd_static, SW_HIDE);
	ShowWindow (hwnd_static, SW_SHOWDEFAULT);
	SendDlgItemMessage (hwnd_window, _idc, WM_SETTEXT, 0, (LPARAM) "");
	UpdateWindow (hwnd_static);
	SendDlgItemMessage (hwnd_window, _idc, WM_SETTEXT, 0, (LPARAM) _msg);
}

// =================
argv_140::argv_140 () {
	init_done = false;
}

void argv_140::init (HWND _hwnd, HINSTANCE _hinstance) {
	reset ();
	hwnd_window = _hwnd;
	hInstance	= _hinstance;
	init_done	= true;
}

void argv_140::argv_127 (argv_593 _winid) {
	if (init_done) {
		argv_601.push_back (_winid);
		argv_524++;
	}
}

void argv_140::incr () {
	if (init_done) {
		argv_583++;
		if (argv_583 >= argv_524) {
			argv_583 = 0;
		}
		InvalidateRect (hwnd_window, NULL, FALSE); // force WM_PAINT to be sent
		UpdateWindow (hwnd_window);
	}
}

void argv_140::reset () {
	argv_524		= 0;
	argv_601.clear ();
	hwnd_window	= NULL;
	hInstance	= NULL;
	init_done	= false;
	argv_583		= 0;
}

void argv_140::argv_175 () {
	if (init_done) {
		argv_208 = LoadImage (hInstance, MAKEINTRESOURCE(argv_601[argv_583]),IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION);
		argv_209 = BeginPaint (hwnd_window, &argv_559);
		DrawState (argv_209,NULL,NULL, (long) argv_208, NULL,0,0,0,0,DST_BITMAP);
		EndPaint (hwnd_window, &argv_559);
		DeleteObject (argv_208);
	}
}

argv_593 argv_201 () {
	argv_593 version = 0;
	OSVERSIONINFOEX osvi;
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	GetVersionEx ((OSVERSIONINFO *) &osvi);
	switch (osvi.dwPlatformId) {
		case VER_PLATFORM_WIN32_NT:
			version = osvi.dwMajorVersion;
			break;
	}

	return (version);
}

bool argv_479 () {
	return (argv_201() == 5);
}

bool argv_478 () {
	return (argv_201() == 6);
}

argv_593 argv_182 (const char * _line, vector<string>& _v_arg) {
	argv_593 nb_arg = 0;
	argv_593 length = strlen (_line);
	string current_arg;
	bool in_brackets = false;

	for (argv_593 i=0 ; i<length ; i++) {
		if (_line[i] == '\"') {
			if (in_brackets == false) {
				in_brackets = true;	
			}
			else {
				_v_arg.push_back (current_arg);
				current_arg = "";
				in_brackets = false;
			}
		}
		else if (in_brackets == true) {
			current_arg += _line[i];
		}
		else if ((_line[i] != ' ') && (_line[i] != '\t')) {
			current_arg += _line[i];
		}
		else {
			if (current_arg.size() > 0) {
				_v_arg.push_back (current_arg);
				current_arg = "";
			}
		}
	}

	// don't forget the last parameter
	if (current_arg.size() > 0) {
		_v_arg.push_back (current_arg);
	}
	return (_v_arg.size());
}

void argv_194 (const char * _prefix, const char * _suffix1, const char * _suffix2, string& _filename1, string& _filename2) {
	_filename1 = _filename2 = "";
	SYSTEMTIME argv_590;
	GetLocalTime (&argv_590);
	srand ((unsigned) argv_590.wMilliseconds);
	argv_577 liste[3];
	liste[0] = rand () % 512;
	liste[1] = rand () % 512;
	liste[2] = rand () % 512;
	char tmp[1024];
	argv_579 (tmp, 1024, "%s_%d_%d_%d_%d_%d%d%d%d.%s", _prefix, argv_590.wHour,argv_590.wMinute,argv_590.wSecond,argv_590.wMilliseconds, _suffix1, liste[0], liste[1], liste[2], _suffix1);
	tmp[1023] = '\0';
	_filename1 = tmp;

	argv_579 (tmp, 1024, "%s_%d_%d_%d_%d_%d%d%d%d.%s", _prefix, argv_590.wHour,argv_590.wMinute,argv_590.wSecond,argv_590.wMilliseconds, _suffix1, liste[0], liste[1], liste[2], _suffix2);
	tmp[1023] = '\0';
	_filename2 = tmp;
}

bool argv_188 (argv_142 _folder_name) {
	bool bret = false;
	DWORD attr = GetFileAttributes (_folder_name);
	if (attr != argv_475) {
		if (attr & FILE_ATTRIBUTE_DIRECTORY) {
			bret = true;
		}
	}
	return (bret);
}

bool argv_162 (argv_142 _folder_name) {
	bool bret = true;
	if (CreateDirectory (_folder_name, NULL) == 0) {
		bret = false;
	}
	return (bret);
}

void argv_581 (const std::string& i_StringToSplit, char i_Delimiter, std::vector<std::string>& io_VectorToken) {
	io_VectorToken.clear();
	std::istringstream iss(i_StringToSplit);
	std::string Token;
	while (std::getline(iss, Token, i_Delimiter)) {
		io_VectorToken.push_back(Token);
	}
}

std::string argv_564 (const std::string& io_Filename) {
	std::string Result;
	wchar_t Delim = L'.';
	std::vector<std::string> VectorToken;
	argv_581 (io_Filename, Delim, VectorToken);

	size_t NbElem = VectorToken.size();
	if (NbElem > 1) {
		for (size_t i = 0 ; i < NbElem - 1 ; i++) {
			if (0 == i) {
				Result += VectorToken[i];
			}
			else {
				Result = Result + "." + VectorToken[i];
			}
		}
	}
	return (Result);
}