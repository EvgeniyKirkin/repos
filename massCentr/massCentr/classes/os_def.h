#ifndef __OS_DEF_H__
#define __OS_DEF_H__



 
//#define WIN32
//#define __CYGWIN__
//#define __GNUC__
//#define _AIX

//#define SOCKOFF


#if !defined(WIN32) || defined(__CYGWIN__)
#define ird_mkdir(name) mkdir(name, 0777)
#else
#define ird_mkdir(name) CreateDirectory(name, NULL);
#endif //defined(__GNUC__) && defined(__CYGWIN__)

#if !defined(WIN32) || defined(__CYGWIN__)
#define sprintf_s sprintf
#define sscanf_s sscanf
#define Sleep usleep
#define TRUE 1
#define FALSE 0
#define _finite std::isfinite
#define _getch getchar
#define getch getchar
#endif




#endif
