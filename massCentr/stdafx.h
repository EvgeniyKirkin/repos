#ifndef __MSHTOOFREADER_STDAFX_H__
#define __MSHTOOFREADER_STDAFX_H__


#include "os_def.h"

#include <cstdio>
#include <cstdlib>

#include <iostream>   //for std
#include <iomanip>    //for setw()  выравнивание метки
#include <fstream>    //for files   для работы с файлами потока стрим
#include <string.h>
#include <string>
#include <cmath>
#include <vector>

#if defined(_AIX)
#include <strings.h>
#endif

#if !defined(WIN32) || defined(__CYGWIN__) 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>
#else
#include <tchar.h>
#include <conio.h>    //for _getch()  для задержки экрана
#include <ctime>
#include <windows.h>  //for Sleep() & system("PAUSE")
#endif

using std::cout;
using std::endl;
using std::fixed;
using std::setw;
using std::sprintf;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::ios_base;
using std::vector;

#include "./classes/const.h"
#include "./classes/point.h"
#include "./classes/face.h"
#include "./classes/line.h"
#include "ArgumentsController.h"
#include "classes.h"
#include "function.h"


#endif
