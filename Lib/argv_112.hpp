#ifndef argv_116
#define argv_116



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

#include "..\\Lib\\argv_111.hpp"



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ namespace usage declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
using namespace std;



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ constants declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
enum argv_545 {
    argv_528,
    argv_604,
    argv_180,
    argv_128,
    argv_172,
    argv_527,
};



const int argv_495 = 256;


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_152
// @@
// @@ DESCRIPTION:
// @@ This object permits to open a log file,
// @@ save argv_170 into it, and close it.
// @@ It can be thread safe depending on the compilation
// @@ flags you choose.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class argv_152
{
	private:
		string  argv_572;
		FILE *	argv_189;
		bool	argv_493;
#if defined (THREAD_SAFE_LOG)
		CRITICAL_SECTION argv_164;
#endif
		char argv_589[argv_495];
		SYSTEMTIME argv_590;
		void argv_600 (bool _large_mode=false);
		void insert_date ();
		void insert_level (argv_593);

	public:
		argv_152();
		virtual ~argv_152();
		bool argv_538 (string, bool _in_file=true);
		void argv_153 ();
		void argv_494 (argv_593, const char *, bool _no_eol=false);
		void argv_494 (argv_593, const char *, argv_577);
		void argv_494 (argv_593, const char *, argv_593);
		void argv_494 (argv_591);
		void argv_494 (argv_593, argv_593, argv_593);
		void argv_494 (argv_593, const char *, const char *);
		void argv_494 (argv_593, const char *, const char *, const char *);
		void argv_494 (argv_593, const char *, const char *, const char *, const char *);
		void argv_494 (argv_593, const char *, unsigned long);

		void argv_494 (argv_593, argv_593);
		void argv_494 (const char *, bool _no_eol=false);
		void argv_494 (const char *, argv_577);
		void argv_494 (const char *, argv_593);
		void argv_494 (const char *, const char *);
		void argv_494 (const char *, const char *, const char *);
		void argv_494 (const char *, const char *, const char *, const char *);
		void argv_494 (const char *, unsigned long);
		void argv_492 (const char *);
};


#endif // argv_116



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
