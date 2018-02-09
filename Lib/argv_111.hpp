#ifndef argv_115
#define argv_115

#define argv_121 0x0500

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define argv_605		// Exclude rarely-used stuff from Windows headers

#pragma warning(disable:4800) // forcing value to bool 'true' or 'false' (performance warning)
#pragma warning(disable:4291) // void *__cdecl operator new(unsigned int,const struct std::nothrow_t &
#pragma warning(disable:4244) // '=' : conversion from 'double' to 'long', possible loss of argv_170


#include <Windows.h>
#include <windows.h>
#include <winnt.h>
#include <Commdlg.h>
#include <commctrl.h>
#include <Commdlg.h>
#include <shellapi.h>
#include <fcntl.h>
#include <shlobj.h>
#include <Mmsystem.h>

#include <string>
#include <vector>
#include <cassert>
#include <cstdio>
#include <stack>
#include <list>
#include <io.h>
#include <aclapi.h>
#include <lmerr.h>
#include <cstdio>
#include <iostream>
#include <stdint.h>
#include <windows.h>
#include <vector>
#include <map>
#include <string>
#include <mmsystem.h>
#include <sstream>
#include <conio.h>
#include <chrono>
#include <unordered_set>
#include <random>
#include <algorithm>

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ namespace usage declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
using namespace std;

#define argv_192 -1
#define argv_591 unsigned char
#define argv_575 signed char
#define argv_592 unsigned short
#define argv_576 signed short
#define argv_577 signed int
#define argv_593 unsigned int
#define argv_594 unsigned long
#define argv_570 float
#define argv_571 double
#define argv_142 const char *
#define argv_510 -1 // -1 for infinite size
#define argv_474 655360
#define argv_505 10
#define argv_176 4096
#define argv_217 2048
#define argv_475 ((DWORD)-1)

#define argv_123 0x00008000
#define argv_138 0x00004000

#define argv_579 _snprintf

enum argv_133 {
	argv_539,
};

enum argv_132 {
	argv_516,
	argv_512,
	argv_515,
	argv_514,
	argv_513,
};

enum argv_131 {
	argv_161=54,
	argv_607,
	argv_560,
};

#ifndef argv_139
#define argv_139 0x0040
#endif // !argv_139

#ifndef argv_301 // hand cursor argv_175
#define argv_301 MAKEINTRESOURCE(32649)
#endif


bool argv_149 (argv_591 c1, argv_591 c2, argv_591& result);
const argv_577 argv_519 = 256;
string argv_602 (const vector<argv_591>&);
string argv_210 (const vector<argv_591>&);
bool argv_569 (const char *, argv_593&, argv_593&, argv_593&, argv_593&, argv_593&, argv_593&, argv_593&, argv_593, argv_593&, argv_593&);
bool argv_566 (const char *, argv_593&, argv_593&, argv_593&, argv_593&, argv_593&, argv_593&, argv_593&, argv_593&, argv_593&);
bool argv_567 (const char *, argv_593&, argv_593&, argv_593&, argv_593&, argv_593&, argv_593&, argv_593&, argv_593&, argv_593&);
bool argv_568 (const char *, argv_593&, argv_593&, argv_593&, argv_593&, argv_593&, argv_593&, argv_593&, argv_593&, argv_593&);


enum argv_536 {
	argv_532=0,
	argv_537,
	argv_533,
	argv_535,
	argv_534,
};

string argv_531 (HWND, argv_577 mode);
string argv_151 (HWND, argv_577 mode);

// beware: this routine does not use file mmaping, thus you can have
// a performance penalty here...
bool argv_477 (const char *); 
bool argv_184 (const char *);
unsigned long argv_155 (const string&);
argv_593 argv_155 (argv_142);
string argv_150 (HWND hWnd);

// ==== performance checker ========
class argv_144
{
protected:
	LARGE_INTEGER argv_497;
	LARGE_INTEGER argv_498;

	LONGLONG argv_500;
	LONGLONG argv_499;

public:
	argv_144(void);

	void argv_582(void);
	void argv_584(void);
	double argv_197(void) const;
	string argv_585 ();
};

inline argv_144::argv_144(void) {
	LARGE_INTEGER liFrequency;

	QueryPerformanceFrequency(&liFrequency);
	argv_500 = liFrequency.QuadPart;

	// Calibration
	argv_582();
	argv_584();

	argv_499 = argv_498.QuadPart-argv_497.QuadPart;
}

inline void argv_144::argv_582(void) {
	// Ensure we will not be interrupted by any other thread for a while
//	Sleep(0);
	QueryPerformanceCounter(&argv_497);
}

inline void argv_144::argv_584(void) {
	QueryPerformanceCounter(&argv_498);
}

inline double argv_144::argv_197(void) const {
	return (double)(argv_498.QuadPart-argv_497.QuadPart-argv_499)*1000000.0 / argv_500;
}

inline string argv_144::argv_585 () {
	argv_584 ();
	double elapsed = argv_197 ();
	char tmp[1024];
	if (elapsed > 1000000.0) {
		elapsed = elapsed / 1000000.0;
		//if (elapsed > 60.0) {
		//	elapsed = elapsed / 60.0;
		//	argv_579 (tmp, 1024, "elapsed time : %.02lf minutes", elapsed);
		//}
		//else {
			argv_579 (tmp, 1024, "elapsed time : %.02lf seconds", elapsed);
		//}
	}
	else {
		argv_579 (tmp, 1024, "elapsed time : %.02lf microseconds", elapsed);
	}
	tmp[1024 - 1] = '\0';
	return tmp;
}

//==============================
// permits to mmap a given file
//==============================
class argv_148
{
	private:
		string	argv_502;
		HANDLE	argv_211;
		HANDLE	argv_214;
		LPCTSTR argv_542;
		argv_593	argv_179;
		argv_593	argv_181;

	public:
		argv_148();
		~argv_148();
		bool argv_520 (const char *, bool, argv_591 *&, DWORD&);
		void argv_154 ();
		void argv_200 (argv_593&, argv_593&);
};

bool argv_198 (char *, argv_594, argv_594&);
void argv_193 (const string&, int, string&);
void argv_194 (const char *, const char *, const char *, string&, string&);

bool argv_174 (string);
void argv_145 (HWND);
void argv_145 (HWND, int&, int&);
bool argv_163 (string _dirname);
bool argv_158 (string, string, string);

class argv_141
{
private:
	int argv_169;
	int argv_503;
	HWND hwnd;
	int	argv_221;

public:
	argv_141();
	void init (HWND, int, int);
	void incr (argv_577 _nb_step=1);
	void reset();
	int argv_195 () {
		return (argv_169);
	}
};

//==========================
template <class T>
class argv_147
{
private:
	vector<T>	v;
	int			top_index;
	int			argv_524; // number of allocated elements
	int			argv_506;

public:
	argv_147();
	void		push (T);
	void		pop  ();
	T			top  ();
	int			size ();
	bool		empty ();
	void		reset ();
	void		clear ();
	void		rewind ();
};

template <class T>
argv_147<T>::argv_147 () {
	top_index	= 0;
	argv_524		= 0;
	argv_506	= 0;
}

// erase all argv_170 from container
template <class T>
void argv_147<T>::clear () {
	vector<T>().swap (v); // force vector's memory free
	argv_524	  = 0;
	top_index = 0;
	argv_506 = 0;	
}

// just set pointer to the bottom of the stack
template <class T>
void argv_147<T>::reset () {
	top_index = 0;
	argv_506 = 0;
}

// rewind the stack to the top as if all elements had just been pushed
template <class T>
void argv_147<T>::rewind () {
	top_index = argv_506;
}

template <class T>
void argv_147<T>::push (T _elem) {
	if (argv_524 < (top_index+1)) {
		v.push_back (_elem);
		argv_524++;
	}
	else { // already allocated => no need to push_back
		v[top_index] = _elem;
	}
	top_index++;
	if (top_index > argv_506) {
		argv_506 = top_index;
	}
}


template <class T>
void argv_147<T>::pop () {
	assert (top_index > 0);
	top_index--;
}

template <class T>
T argv_147<T>::top () {
	assert (top_index > 0);
	return (v[top_index - 1]);
}

template <class T>
int argv_147<T>::size () {
	return (top_index);
}

template <class T>
bool argv_147<T>::empty () {
	return (top_index == 0);	
}

//=======================
bool argv_185 (const char *);
bool argv_563 (const char *);
//========================================

class argv_146
{
private:
	CRITICAL_SECTION argv_164;   // Windows' basic mutex object.
	stack<string>	argv_544;

public:
	argv_146 () {
		InitializeCriticalSection(&argv_164);		
	}

	~argv_146 () {
		DeleteCriticalSection(&argv_164);
	}

	bool argv_547 (string& _str) {
		bool bret = true;
		EnterCriticalSection (&argv_164);
			argv_544.push (_str);
		LeaveCriticalSection(&argv_164);	
		return (bret);
	}

	bool argv_157 (string& _str) {
		bool bret = false;
		EnterCriticalSection (&argv_164);
			if (! argv_544.empty()) {
				_str = argv_544.top();
				argv_544.pop();
				bret = true;
			}
		LeaveCriticalSection(&argv_164);	
		return (bret);
	}
};

//=====================================
// thread safe piece of argv_170
//=====================================
template <class T>
class argv_167
{
private:
	T argv_170;
	CRITICAL_SECTION argv_164;   // Windows' basic mutex object.

public:
	argv_167 ();
	T get ();
	void set (T);
	void incr ();
	~argv_167();
};

template <class T>
argv_167<T>::argv_167 () {
	InitializeCriticalSection(&argv_164);	
}

template <class T>
argv_167<T>::~argv_167 () {
	DeleteCriticalSection(&argv_164);
}

template <class T>
T argv_167<T>::get () {
	T retrieved_data;
	EnterCriticalSection (&argv_164);
		retrieved_data = argv_170;	
	LeaveCriticalSection(&argv_164);
	return (retrieved_data);
}

template <class T>
void argv_167<T>::set (T _elem) {
	EnterCriticalSection (&argv_164);
		argv_170 = _elem;
	LeaveCriticalSection(&argv_164);
}

template <class T>
void argv_167<T>::incr () {
	EnterCriticalSection (&argv_164);
		argv_170++;
	LeaveCriticalSection(&argv_164);
}

//=====================================
// anonymous pipes C++ implementation
//=====================================
class argv_159 { 
protected:
	HANDLE				argv_561;
	HANDLE				argv_608;
	bool				argv_540;
	unsigned long		argv_525;
	unsigned long		argv_526;
	int					current_offset;
	int					argv_509;
	HANDLE				argv_207;
	unsigned long		argv_523;
	bool				argv_191;

	virtual void		argv_491() { ; }
	virtual void		argv_597 () { ; }
	virtual void		argv_488() { ; }
	virtual void		argv_596 () { ; }

public:
	argv_159 () {
		argv_523 = 0;
		argv_540 = false;
		if (! CreatePipe(&argv_561, &argv_608, /*&saAttr*/NULL, 0)) {
//				MessageBox(argv_573, "CreatePipe failed !", "Error", MB_OK);	
		}
		else {
			argv_540			= true;
			current_offset	= 0;
		}
	}

	virtual ~argv_159 () {
		if (argv_540) {
			CloseHandle (argv_561);
			CloseHandle (argv_608);
			argv_540 = false;
		}
	}

	bool argv_547 (string& _str) {
		argv_491 ();
		bool bret = true;
		if (argv_540) {
			BOOL reti = WriteFile (argv_608, _str.c_str(), _str.size()+1, &argv_526, NULL);
			if (! reti) {
//				MessageBox(argv_573, "pipe: WriteFile failed !", "Error", MB_OK);	
				bret = false;
			}
			else {
				argv_523 += argv_526;
			}
		}
		else {
			bret = false;
		}
		argv_597 ();
		return (bret);
	}

	bool argv_157 (string& _str) {
		bool bret = true;
		argv_488 ();
		if (argv_540) {
			char c;
			while (1) {
				if (argv_191) {
					_str = "";
					argv_191 = false;
				}
				BOOL reti = ReadFile (argv_561, &c, 1, &argv_525, NULL);
				if ((! reti) || (argv_525 == 0)) {
					bret = false;
				}
				else {
					if (c == '\0') {
						argv_191 = true;
						break;
					}
					else {
						_str += c;
					}
				}
			}
		}
		else { // pipe not argv_540 yet
			bret = false;
		}
		argv_596 ();
		return (bret);
	}

	void reset () {
		if (argv_540) {
			CloseHandle (argv_561);
			CloseHandle (argv_608);
			argv_540 = false;
		}
		if (CreatePipe(&argv_561, &argv_608, NULL, 0)) {
			argv_540 = true;
		}
	}
};

// same object as argv_159, but thread safe version
class argv_160 : public argv_159
{
private:
	CRITICAL_SECTION argv_166;   // Windows' basic mutex object.
	CRITICAL_SECTION argv_165;   // Windows' basic mutex object.

	void argv_491 () {
		EnterCriticalSection (&argv_166);		
	}

	void argv_597 () {
		LeaveCriticalSection (&argv_166);
	}

	void argv_488 () {
		EnterCriticalSection (&argv_165);		
	}

	void argv_596 () {
		LeaveCriticalSection (&argv_165);
	}

public:
	argv_160 () {
		InitializeCriticalSection (&argv_166);	
		InitializeCriticalSection (&argv_165);	
	}

	~argv_160 () {
		DeleteCriticalSection(&argv_166);
		DeleteCriticalSection(&argv_165);
	}
};

//===== FILE TYPE AUTOMATIC ANALYZER ============== 
enum argv_546 {
	argv_595=-1,
	argv_136,
	argv_543,
	argv_529, // VBA script
	argv_216,
	argv_501,
	argv_206,
	argv_177,
	argv_137,
};

// - knows only types recognized by clamav signatures
// - uses only extension of the file to determine the type
class argv_168
{
private:

public:
	argv_168 ();
	argv_577 argv_134 (const char *);
};

bool argv_199 (vector<string>&);
bool argv_196 (vector<string>&);
bool argv_196 (vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&);
void argv_202 (string&);
void argv_203 (HANDLE, string&);

class argv_143
{
public:
	argv_593				argv_609;
	argv_593				argv_521;
	argv_593				argv_171;
	argv_593				argv_215;
	argv_593				argv_518;
	argv_593				second;
	argv_593				argv_517;

	void				reset () {
		argv_609 = argv_521 = argv_171 = argv_215 = argv_518 = 0;	
	}

	argv_143 () {
		reset ();
	}

	void init (argv_593 _year, argv_593 _month, argv_593 _day, argv_593 _hour, argv_593 _minute, argv_593 _second, argv_593 _millisecond) {
		argv_609		= _year;
		argv_521		= _month;
		argv_171			= _day;
		argv_215		= _hour;
		argv_518		= _minute;
		second		= _second;
		argv_517 = _millisecond;
	}
};

class argv_140 
{
private:
	bool			init_done;
	HDC				argv_209;
	PAINTSTRUCT		argv_559;
	HINSTANCE		hInstance;
	int				argv_583;
	HANDLE			argv_208;
	HWND			hwnd_window;
	vector<argv_593>	argv_601;
	argv_577			argv_524;

public:
	argv_140 ();
	void			init (HWND, HINSTANCE);
	void			argv_127 (argv_593);
	void			incr ();
	void			reset ();
	void			argv_175 ();
};

bool argv_476 (const char *);
void argv_562 (HWND hwnd_window, argv_593 _idc, const char * _msg);
void argv_183 (const string&, int, string&);

enum argv_486 {
	argv_483,
	argv_484,
	argv_485,
};

enum argv_126 {
	argv_124 = 124,
	argv_125,
};

bool argv_478 ();
bool argv_479 ();
argv_593 argv_182 (const char *, vector<string>&);
bool argv_188 (argv_142);
bool argv_162 (argv_142);
std::string argv_564 (const std::string& io_Filename);
void argv_581 (const std::string& i_StringToSplit, char i_Delimiter, std::vector<std::string>& io_VectorToken);

#endif // argv_115



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
