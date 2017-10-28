#ifndef __POINT_CUDA_H__
#define __POINT_CUDA_H__

#include "const.h"

//класс точек
//подходит и для радиус-векторов
class CPoint
{
public:

	//стандартный конструктор
	__host__ __device__ CPoint (void) {};

	//конструктор копирования
	//приравнивает к другой точке
	__host__ __device__ CPoint (const CPoint &pnt)
	{
		x = pnt.x;
		y = pnt.y; 
		z = pnt.z;
	};

	//конструктор перемещения
	//приравнивает к другой временной точке
//	CPoint (const CPoint &&pnt)
//	{
//		x = pnt.x;
//		y = pnt.y; 
//		z = pnt.z;
//	};

	//конструктор
	//все координаты заданы в явном виде
	__host__ __device__ CPoint (double xv, double yv, double zv):  x(xv), y(yv), z(zv) {};
	
	//конструктор 
	//все координаты равны
	__host__ __device__ CPoint (double f):  x(f), y(f), z(f) {};

	//стандартный деструктор
	__host__ __device__ ~CPoint (void) {};


	//оператор присвоения
	//медленное приравнивание другой точке
	__host__ __device__ inline void operator= (const CPoint &pnt)
	{
		x = pnt.x;
		y = pnt.y;
		z = pnt.z;
	};

	//перемещающий оператор присвоения
	//быстрое приравнивание и удаление временной точки
//	inline void operator= (const CPoint &&pnt)
//	{
//		x = pnt.x;
//		y = pnt.y;
//		z = pnt.z;
//	};

	//оператор присвоения
	//все три координаты приравниваются одному числу
	__host__ __device__ inline void operator= (const double f)
	{
		x = f;
		y = f;
		z = f;
	};

    //оператор плюс-равно
	//сложение точки с данной
	// a = a + b
	__host__ __device__ inline void operator+= (const CPoint &pnt)
	{
		x += pnt.x;
		y += pnt.y;
		z += pnt.z;
	};

    //перемещающий оператор плюс-равно
	//сложение точки с данной
	// a = a + b
//	inline void operator+= (const CPoint &&pnt)
//	{
//		x += pnt.x;
//		y += pnt.y;
//		z += pnt.z;
//	};

    //оператор минус-равно
	//вычитание из точки данную
	// a = a - b
	__host__ __device__ inline void operator-= (const CPoint &pnt)
	{
		x -= pnt.x;
		y -= pnt.y;
		z -= pnt.z;
	};

    //перемещающий оператор минус-равно
	//вычитание из точки данную
	//a = a - b
//	inline void operator-= (const CPoint &&pnt)
//	{
//		x -= pnt.x;
//		y -= pnt.y;
//		z -= pnt.z;
//	};

	//оператор делить-равно на число
	//деление координат на число целого типа
	__host__ __device__ inline void operator/= (const int f)
	{
		x /= f;
		y /= f;
		z /= f;
	};

	//оператор делить-равно на число
	//деление координат на число вещественного типа
	__host__ __device__ inline void operator/= (const float f)
	{
		x /= f;
		y /= f;
		z /= f;
	};

	//оператор делить-равно на число
	//деление координат на число целого типа
	__host__ __device__ inline void operator*= (const int f)
	{
		x *= f;
		y *= f;
		z *= f;
	};

	//оператор делить-равно на число
	//деление координат на число вещественного типа
	__host__ __device__ inline void operator*= (const double f)
	{
		x *= f;
		y *= f;
		z *= f;
	};




	//отображение точки на экране
	//выводятся просто координаты точки
	__host__ __device__ inline void ShowIt ()
	{
		cout << setw(15) << x << " " << setw(15) << y << " " << setw(15) << z << endl;
	};

	//присвоение существующей точке новыx координат
	//идентично a = b
	__host__ __device__ inline void set (CPoint pnt)
	{
		x = pnt.x;
		y = pnt.y;
		z = pnt.z;
	};

	//присвоение существующей точке новыx координат
	//заданных в явном виде
	__host__ __device__ inline void set (double xv, double yv, double zv)
	{
		x = xv;
		y = yv;
		z = zv;
	};

	//присвоение существующей точке новыx координат
	//заданных в явном виде
	__host__ __device__ inline void set (double f)
	{
		x = f;
		y = f;
		z = f;
	};

	//длина радиус-вектора
	//с текущими координатами
	__host__ __device__ inline double length ()   {  return sqrt(x*x + y*y + z*z);  };

	//нормирование радиус-вектора
	//с текущими координатами
	__host__ __device__ inline void ToSingle ()
	{
		double len = length();		//Если вектор нулевой, то возвращаемой нулевой.
		(len > 0.? x /= len: 0.);
		(len > 0.? y /= len: 0.);
		(len > 0.? z /= len: 0.);
	};
	

public:
	double x; //координата X
	double y; //координата Y
	double z; //координата Z
};



//оператор унарный минус
//параметр pnt, результат  -pnt
__host__ __device__ inline CPoint operator- (const CPoint &pnt)  {  return CPoint(-pnt.x, -pnt.y, -pnt.z);  }

//оператор сложения двух точек
//параметры p1 и p2,  результат - точка p1+p2
__host__ __device__ inline CPoint operator+ (const CPoint &p1, const CPoint &p2)  {  return CPoint (p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);  }

//оператор вычитания из точки точку
//параметры p1 и p2,  результат - точка p1-p2
__host__ __device__ inline CPoint operator- (const CPoint &p1, const CPoint &p2)  {  return CPoint (p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);  }

//оператор умножения на число целого типа
//параметры pnt и f, результат  pnt*f
__host__ __device__ inline CPoint operator* (const CPoint &pnt, const int f)  {  return CPoint (pnt.x*f, pnt.y*f, pnt.z*f);  }

//оператор умножения на число вещественного типа
//параметры pnt и f, результат  pnt*f
__host__ __device__ inline CPoint operator* (const CPoint &pnt, const double f)  {  return CPoint (pnt.x*f, pnt.y*f, pnt.z*f);  }

//оператор деления на число целого типа
//параметры pnt и f, результат  pnt*f
__host__ __device__ inline CPoint operator/ (const CPoint &pnt, const int f)  {  return CPoint (pnt.x/f, pnt.y/f, pnt.z/f);  }

//оператор днлнния на число вещественного типа
//параметры pnt и f, результат  pnt*f
__host__ __device__ inline CPoint operator/ (const CPoint &pnt, const double f)  {  return CPoint (pnt.x/f, pnt.y/f, pnt.z/f);  }

//оператор сравнения двух точек на равенство
//параметры p1 и p2,  результат  true  или  false
//сравнение ведется до порядка точности EPS
__host__ __device__ inline bool operator== (const CPoint &p1, const CPoint &p2)
{
/*	if (p1.x != p2.x)  return false;
	if (p1.y != p2.y)  return false;
	if (p1.z != p2.z)  return false;*/
	if (fabs(p1.x - p2.x) >= EPS10) return false;
	if (fabs(p1.y - p2.y) >= EPS10) return false;
	if (fabs(p1.z - p2.z) >= EPS10) return false;
	return true;
}

//оператор сравнения двух точек на неравенство
//параметры p1 и p2,  результат  true  или  false
//сравнение ведется до порядка точности EPS
__host__ __device__ inline bool operator!= (const CPoint &p1, const CPoint &p2)
{
	if (fabs(p1.x - p2.x) >= EPS10) return true;
	if (fabs(p1.y - p2.y) >= EPS10) return true;
	if (fabs(p1.z - p2.z) >= EPS10) return true;
	return false;
}

//функция нахождения расстояния между двумя точками
//параметры p1 и p2, результат - число типа double
__host__ __device__ inline double length (const CPoint &p1, const CPoint &p2)
{
	return (p1-p2).length ();
}

//функция нахождения скалярного произведения
//входяцие аргументы - точки (радиус-вектора) p1 и p2
//результат  число  (p1, p2)
__host__ __device__ inline float scalar_product (const CPoint &p1, const CPoint &p2)
{
	return (p1.x*p2.x + p1.y*p2.y + p1.z*p2.z);
}

//функция нахождения векторного произведения
//входяцие аргументы - точки (радиус-вектора) p1 и p2
//результат  вектор  <p1, p2>
__host__ __device__ inline CPoint vector_product (const CPoint &p1, const CPoint &p2)
{
	return CPoint(p1.y*p2.z - p2.y*p1.z, - p1.x*p2.z + p2.x*p1.z, p1.x*p2.y - p2.x*p1.y);
}

//функция нахождения смешанного произведения
//входяцие аргументы - точки (радиус-вектора) p1, p2 и p3
//результат  число  (p1, <p2, p3>)
__host__ __device__ inline double scalar_triple_product (const CPoint &p1, const CPoint &p2, const CPoint &p3)
{
	CPoint pp(vector_product(p2, p3));
	return scalar_product (p1, pp);
}


#endif
