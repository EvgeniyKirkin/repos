#ifndef __CLASSES_CONST_H__
#define __CLASSES_CONST_H__

#include "os_def.h"


#define PI 3.14159265358979323846
#define EPS2  1e-2
#define EPS3  1e-3
#define EPS5  1e-5
#define EPS7  1e-7
#define EPS10 1e-10
#define EPS14 1e-14
#define EPS15 1e-15
#define EPS20 1e-20
#define STR_MAX_SIZE 255
#define _STR_LEN_MAX_ 255

#define PressureAtm 101325.
#define Pr 0.71

#define str_meshpath "./_Mesh/"
#define str_servicepath "./_Service/"

#define str_geocfgfl "Geo.cfg"



template <class T> int sgn(T a)
{
	if (a > 0) return 1;
	if (a < 0) return -1;
	return 0;
}

struct facet              // 50  байт   //структура для считывания из бинарника
{
	float normal[3];      // 12  байт  (нормаль)
	float vertex[3][3];   // 36  байт  (вершины)
	unsigned short attr;  //  2 байта 
};

#endif

