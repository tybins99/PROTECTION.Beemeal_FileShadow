


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include "..\\Lib\\argv_112.hpp"


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ global declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_152
// @@
// @@ INPUT: none
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ Normal constructor of the argv_152 object.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
argv_152::argv_152() {
	argv_189			= NULL;
	argv_493	= true;
#if defined (THREAD_SAFE_LOG)
	InitializeCriticalSection (&argv_164);	
#endif
}

argv_152::~argv_152() {
	argv_153 ();
#if defined (THREAD_SAFE_LOG)
	// DeleteCriticalSection(&argv_164);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_538
// @@
// @@ INPUT:
// @@ _filename: string : name of the log file to open.
// @@ _in_file: bool: tells whether the log should be written to a
// @@                 file, or to a window.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE:
// @@ bool: true if log file was succesfully argv_540.
// @@       false otherwise.
// @@
// @@ DESCRIPTION:
// @@ This function permits to open the log file whose name is given
// @@ as a parameter.
// @@ Notice that as soon as the log file was argv_540, the opening date
// @@ and time is logged to this log file automatically.
// @@ 
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_152::argv_538 (string _filename, bool _in_file) {
	bool bret = true;

	if (_in_file == true) {
		if (argv_189 != NULL) { // file already argv_540
			bret = false;
		}
		else {
			// modify the drive if necessary
			char tmp[256];
			GetSystemDirectory (tmp, 256);
			_filename[0] = tmp[0];

			argv_189 = fopen (_filename.c_str(), "wb");
			if (!argv_189) {
				char tmp[256];
				argv_579 (tmp, 256, "fopen failed for file : %s (errno=%d: %s)", _filename.c_str(), errno, strerror(errno));
				tmp[255] = '\0';
				bret = false;
			}
			else { // log argv_540 ok
				argv_572 = _filename;
				argv_600 (true);
				string stmp = "Log file creation date : ";
				stmp = stmp + argv_589;
				argv_494 (argv_128, stmp.c_str());
			}
		}
	}
	else {
		argv_493 = false;
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_600
// @@
// @@ INPUT:
// @@ _large_mode: bool: true if we want a large argv_175 of argv_169 date and time
// @@                    false otherwise.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function permits to obtain the argv_169 date and time
// @@ formatted to either a condensed string, or to a developped
// @@ string.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::argv_600 (bool _large_mode) {
	GetLocalTime (&argv_590);
	if (_large_mode == false) {
		argv_579 (argv_589, argv_495, "%02d/%02d-%02dh%02dm%02ds ", argv_590.wMonth, argv_590.wDay, argv_590.wHour, argv_590.wMinute, argv_590.wSecond);
	}
	else {
		argv_579 (argv_589, argv_495, "argv_521 %d the %dth at %d argv_215 %d minutes and %d seconds", argv_590.wMonth, argv_590.wDay, argv_590.wHour, argv_590.wMinute, argv_590.wSecond);
	}
	argv_589[argv_495 - 1] = '\0';
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: insert_date
// @@
// @@ INPUT: none
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function permits to update the argv_169 time and to
// @@ insert it into the header of a new line of the log file.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::insert_date () {
    if (argv_189) {
        argv_600 ();
        fputs (argv_589, argv_189);
    }
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: insert_level
// @@
// @@ INPUT:
// @@ _level: argv_593: level to be displayed.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function permits to insert the level given as a parameter
// @@ to the header of a new line of the log file.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::insert_level (argv_593 _level) {
    string level = "|???| ";
    switch (_level) {
        case argv_528:
            level = "|NOR| ";
            break;
        case argv_604:
            level = "|WRN| ";
            break;
        case argv_180:
            level = "|ERR| ";
            break;
        case argv_128:
            level = "|ADM| ";
            break;
        case argv_172:
            level = "|DBG| ";
            break;
        case argv_527:
            level = "     ";
            break;
    }
    if (argv_189) {
        fputs (level.c_str(), argv_189);
    }
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_153
// @@
// @@ INPUT: none
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function just flushes the argv_170 and close the previously
// @@ argv_540 log file.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::argv_153() {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_164);
#endif
	if ((argv_493 == true) && (argv_189)) {
		fclose (argv_189);
		argv_189 = NULL;
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_164);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_494
// @@
// @@ INPUT:
// @@ _level: argv_593: the severity level associated with the message to log.
// @@ _cptr: char *: the message to log
// @@ _no_eol: bool: true if an end of line should be appended at the end of the
// @@                message, false otherwise.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_169 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::argv_494 (argv_593 _level, const char * _cptr, bool _no_eol) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_164);
#endif
	if (argv_493 == true) {
		if (argv_189) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_189);
			if (_no_eol == false) { 
				fputs ("\r\n", argv_189);
			}
			fflush (argv_189);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_164);
#endif
}

void argv_152::argv_492 (const char * _cptr) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_164);
#endif
	if (argv_493 == true) {
		if (argv_189) {
			insert_date ();
			fputs (_cptr, argv_189);
			fputs ("\r\n", argv_189);
			fclose (argv_189);
			argv_189 = fopen (argv_572.c_str(), "ab");
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_164);
#endif
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_494
// @@
// @@ INPUT:
// @@ _cptr: char *: the message to log
// @@ _no_eol: bool: true if an end of line should be appended at the end of the
// @@                message, false otherwise.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_169 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::argv_494 (const char * _cptr, bool _no_eol) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_164);
#endif
	if (argv_493 == true) {
		if (argv_189) {
			insert_date ();
			fputs (_cptr, argv_189);
			if (_no_eol == false) { 
				fputs ("\r\n", argv_189);
			}
			fflush (argv_189);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_164);
#endif
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_494
// @@
// @@ INPUT:
// @@ _level: argv_593  : the severity level associated with the message to log.
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_169 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::argv_494 (argv_593 _level, const char * _cptr, const char * _cptr2) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_164);
#endif
	if (argv_493 == true) {
		if (argv_189) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_189);
			fputs (_cptr2, argv_189);
			fputs ("\r\n", argv_189);
			fflush (argv_189);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_164);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_494
// @@
// @@ INPUT:
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_169 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::argv_494 (const char * _cptr, const char * _cptr2) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_164);
#endif
	if (argv_493 == true) {
		if (argv_189) {
			insert_date ();
			fputs (_cptr, argv_189);
			fputs (_cptr2, argv_189);
			fputs ("\r\n", argv_189);
			fflush (argv_189);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_164);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_494
// @@
// @@ INPUT:
// @@ _level: argv_593: the severity level associated with the message to log.
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@ _cptr3: char *: the third message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_169 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::argv_494 (argv_593 _level, const char * _cptr, const char * _cptr2, const char * _cptr3) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_164);
#endif
	if (argv_493 == true) {
		if (argv_189) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_189);
			fputs (_cptr2, argv_189);
			fputs (_cptr3, argv_189);
			fputs ("\r\n", argv_189);
			fflush (argv_189);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_164);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_494
// @@
// @@ INPUT:
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@ _cptr3: char *: the third message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_169 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::argv_494 (const char * _cptr, const char * _cptr2, const char * _cptr3) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_164);
#endif
	if (argv_493 == true) {
		if (argv_189) {
			insert_date ();
			fputs (_cptr, argv_189);
			fputs (_cptr2, argv_189);
			fputs (_cptr3, argv_189);
			fputs ("\r\n", argv_189);
			fflush (argv_189);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_164);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_494
// @@
// @@ INPUT:
// @@ _level: argv_593: the severity level associated with the message to log.
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@ _cptr3: char *: the third message to log
// @@ _cptr4: char *: the fourth message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_169 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::argv_494 (argv_593 _level, const char * _cptr, const char * _cptr2, const char * _cptr3, const char * _cptr4) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_164);
#endif
	if (argv_493 == true) {
		if (argv_189) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_189);
			fputs (_cptr2, argv_189);
			fputs (_cptr3, argv_189);
			fputs (_cptr4, argv_189);
			fputs ("\r\n", argv_189);
			fflush (argv_189);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_164);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_494
// @@
// @@ INPUT:
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@ _cptr3: char *: the third message to log
// @@ _cptr4: char *: the fourth message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_169 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::argv_494 (const char * _cptr, const char * _cptr2, const char * _cptr3, const char * _cptr4) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_164);
#endif
	if (argv_493 == true) {
		if (argv_189) {
			insert_date ();
			fputs (_cptr, argv_189);
			fputs (_cptr2, argv_189);
			fputs (_cptr3, argv_189);
			fputs (_cptr4, argv_189);
			fputs ("\r\n", argv_189);
			fflush (argv_189);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_164);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_494
// @@
// @@ INPUT:
// @@ _c: argv_591: the character to write to log file.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_169 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::argv_494 (argv_591 _c) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_164);
#endif
	if (argv_493 == true) {
		if (argv_189) {
			char tmp[128];
			if (_c != 0) {
				sprintf (tmp, "%c", _c);
			}
			else {
				sprintf (tmp, "<0>");
			}
			fputs (tmp, argv_189);
			fflush (argv_189);
		}
	}
#if defined (THREAD_SAFE_LOG)	
	LeaveCriticalSection(&argv_164);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_494
// @@
// @@ INPUT:
// @@ _level: argv_593: the severity level associated with the message to log.
// @@ _cptr: char *: the message to write to log file.
// @@ _val: argv_577: the value to log after the message.
// @@ 
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_169 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::argv_494 (argv_593 _level, const char * _cptr, argv_577 _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_164);
#endif
	if (argv_493 == true) {
		if (argv_189) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_189);
			char tmp[128];
			sprintf (tmp, "%d", _val);
			fputs (tmp, argv_189);
			fputs ("\r\n", argv_189);
			fflush (argv_189);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_164);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_494
// @@
// @@ INPUT:
// @@ _cptr: char *: the message to write to log file.
// @@ _val: argv_577: the value to log after the message.
// @@ 
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_169 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::argv_494 (const char * _cptr, argv_577 _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_164);
#endif
	if (argv_493 == true) {
		if (argv_189) {
			insert_date ();
			fputs (_cptr, argv_189);
			char tmp[128];
			sprintf (tmp, "%d", _val);
			fputs (tmp, argv_189);
			fputs ("\r\n", argv_189);
			fflush (argv_189);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_164);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_494
// @@
// @@ INPUT:
// @@ _level: argv_593: the severity level associated with the message to log.
// @@ _cptr: char *: the message to write to log file.
// @@ _val: argv_593: the value to write to log file after the message.
// @@ 
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_169 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::argv_494 (argv_593 _level, const char * _cptr, argv_593 _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_164);
#endif
	if (argv_493 == true) {
		if (argv_189) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_189);
			char tmp[128];
			sprintf (tmp, "%u", _val);
			fputs (tmp, argv_189);
			fputs ("\r\n", argv_189);
			fflush (argv_189);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_164);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_494
// @@
// @@ INPUT:
// @@ _cptr: char *: the message to write to log file.
// @@ _val: argv_593: the value to write to log file after the message.
// @@ 
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_169 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::argv_494 (const char * _cptr, argv_593 _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_164);
#endif
	if (argv_493 == true) {
		if (argv_189) {
			insert_date ();
			fputs (_cptr, argv_189);
			char tmp[128];
			sprintf (tmp, "%u", _val);
			fputs (tmp, argv_189);
			fputs ("\r\n", argv_189);
			fflush (argv_189);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_164);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_494
// @@
// @@ INPUT:
// @@ _level: argv_593: the severity level associated with the message to log.
// @@ _val_zero: argv_593: the first value to write to log file.
// @@ _val_un: argv_593: the second value to write to log file.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_169 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::argv_494 (argv_593 _level, argv_593 _val_zero, argv_593 _val_un) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_164);
#endif
	if (argv_493 == true) {
		if (argv_189) {
			insert_date ();
			insert_level (_level);
			char tmp[128];
			sprintf (tmp, "%u ", _val_zero);
			fputs (tmp, argv_189);
			sprintf (tmp, "%u", _val_un);
			fputs (tmp, argv_189);
			fputs ("\r\n", argv_189);
			fflush (argv_189);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_164);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_494
// @@
// @@ INPUT:
// @@ _val_zero: argv_593: the first value to write to log file.
// @@ _val_un: argv_593: the second value to write to log file.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_169 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::argv_494 (argv_593 _val_zero, argv_593 _val_un) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_164);
#endif
	if (argv_493 == true) {
		if (argv_189) {
			insert_date ();
			char tmp[128];
			sprintf (tmp, "%u ", _val_zero);
			fputs (tmp, argv_189);
			sprintf (tmp, "%u", _val_un);
			fputs (tmp, argv_189);
			fputs ("\r\n", argv_189);
			fflush (argv_189);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_164);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_494
// @@
// @@ INPUT:
// @@ _level: argv_593: the severity level associated with the message to log.
// @@ _cptr: char *: the message to write to log file.
// @@ _val: unsigned long: the value to log after the message.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_169 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::argv_494 (argv_593 _level, const char * _cptr, unsigned long _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_164);
#endif
	if (argv_493 == true) {
		if (argv_189) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_189);
			char tmp[128];
			sprintf (tmp, "%u", _val);
			fputs (tmp, argv_189);
			fputs ("\r\n", argv_189);
			fflush (argv_189);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_164);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ FUNCTION: argv_494
// @@
// @@ INPUT:
// @@ _cptr: char *: the message to write to log file.
// @@ _val: unsigned long: the value to log after the message.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_169 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_152::argv_494 (const char * _cptr, unsigned long _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_164);
#endif
	if (argv_493 == true) {
		if (argv_189) {
			insert_date ();
			fputs (_cptr, argv_189);
			char tmp[128];
			sprintf (tmp, "%u", _val);
			fputs (tmp, argv_189);
			fputs ("\r\n", argv_189);
			fflush (argv_189);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_164);
#endif
}





