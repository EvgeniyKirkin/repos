#ifndef __LINE_CUDA_H__
#define __LINE_CUDA_H__

//#define double float

#include "const.h"

class CLine
{
public:

	//стандартный конструктор
	__host__ __device__ CLine (void) {};

	//конструктор копирования
	//приравнивает к другой точке
	__host__ __device__ CLine (const CLine &line)
	{
		a = line.a;
		b = line.b; 
	};

	////конструктор перемещения
	////приравнивает к другой временной точке
	//__host__ __device__ CLine (const CLine &&line)
	//{
	//	a = line.a;
	//	b = line.b; 
	//};

	//конструктор
	//все координаты заданы в явном виде
	__host__ __device__ CLine (int av, int bv):  a(av), b(bv) {};
	
	//конструктор 
	//все координаты равны
	__host__ __device__ CLine (int f):  a(f), b(f) {};

	//стандартный деструктор
	__host__ __device__ ~CLine (void) {};


	//оператор присвоения
	//медленное приравнивание другой точке
	__host__ __device__ inline void operator= (const CLine &line)
	{
		a = line.a;
		b = line.b;
	};

	////перемещающий оператор присвоения
	////быстрое приравнивание и удаление временной точки
	//__host__ __device__ inline void operator= (const CLine &&line)
	//{
	//	a = line.a;
	//	b = line.b;
	//};

	//оператор присвоения
	//все три координаты приравниваются одному числу
	__host__ __device__ inline void operator= (const int f)
	{
		a = f;
		b = f;
	};

    //оператор плюс-равно
	//сложение точки с данной
	// a = a + b
	/*inline void operator+= (const CLine &line)
	{
		a += line.a;
		b += line.b;
		z += line.z;
	};*/

    //перемещающий оператор плюс-равно
	//сложение точки с данной
	// a = a + b
	/*inline void operator+= (const CLine &&line)
	{
		a += line.a;
		b += line.b;
		z += line.z;
	};*/

    //оператор минус-равно
	//вычитание из точки данную
	// a = a - b
	/*inline void operator-= (const CLine &line)
	{
		a -= line.a;
		b -= line.b;
		z -= line.z;
	};*/

    //перемещающий оператор минус-равно
	//вычитание из точки данную
	//a = a - b
	/*inline void operator-= (const CLine &&line)
	{
		a -= line.a;
		b -= line.b;
		z -= line.z;
	};*/

	//оператор делить-равно на число
	//деление координат на число целого типа
	/*inline void operator/= (const int f)
	{
		a /= f;
		b /= f;
		z /= f;
	};*/

	//оператор делить-равно на число
	//деление координат на число вещественного типа
	/*inline void operator/= (const double f)
	{
		a /= f;
		b /= f;
		z /= f;
	};*/

	//оператор делить-равно на число
	//деление координат на число целого типа
	/*inline void operator*= (const int f)
	{
		a *= f;
		b *= f;
		z *= f;
	};*/

	//оператор делить-равно на число
	//деление координат на число вещественного типа
	/*inline void operator*= (const double f)
	{
		a *= f;
		b *= f;
		z *= f;
	};*/




	//отображение точки на экране
	//выводятся просто координаты точки
	__host__ __device__ inline void ShowIt ()
	{
		cout << setw(15) << a << " " << setw(15) << b << " " << endl;
	};

	//присвоение существующей точке новыa координат
	//идентично a = b
	__host__ __device__ inline void set (CLine line)
	{
		a = line.a;
		b = line.b;
	};

	//присвоение существующей точке новыa координат
	//заданных в явном виде
	__host__ __device__ inline void set (int av, int bv)
	{
		a = av;
		b = bv;
	};

	//присвоение существующей точке новыa координат
	//заданных в явном виде
	__host__ __device__ inline void set (int f)
	{
		a = f;
		b = f;
	};

	//длина радиус-вектора
	//с текущими координатами
	//inline double length ()   {  return sqrt(a*a + b*b + z*z);  };

	//нормирование радиус-вектора
	//с текущими координатами
	//inline void ToSingle ()
	//{
	//	double len = length();		//Если вектор нулевой, то возвращаемой нулевой.
	//	(len > 0.? a /= len: 0.);
	//	(len > 0.? b /= len: 0.);
	//	(len > 0.? z /= len: 0.);
	//};
	//

public:
	int a; //координата X
	int b; //координата Y
};



//оператор унарный минус
//параметр line, результат  -line
//inline CLine operator- (const CLine &line)  {  return CLine(-line.a, -line.b, -line.z);  }

//оператор сложения двух точек
//параметры p1 и p2,  результат - точка p1+p2
//inline CLine operator+ (const CLine &p1, const CLine &p2)  {  return CLine (p1.a + p2.a, p1.b + p2.b, p1.z + p2.z);  }

//оператор вычитания из точки точку
//параметры p1 и p2,  результат - точка p1-p2
//inline CLine operator- (const CLine &p1, const CLine &p2)  {  return CLine (p1.a - p2.a, p1.b - p2.b, p1.z - p2.z);  }

//оператор умножения на число целого типа
//параметры line и f, результат  line*f
//inline CLine operator* (const CLine &line, const int f)  {  return CLine (line.a*f, line.b*f, line.z*f);  }

//оператор умножения на число вещественного типа
//параметры line и f, результат  line*f
//inline CLine operator* (const CLine &line, const double f)  {  return CLine (line.a*f, line.b*f, line.z*f);  }

//оператор деления на число целого типа
//параметры line и f, результат  line*f
//inline CLine operator/ (const CLine &line, const int f)  {  return CLine (line.a/f, line.b/f, line.z/f);  }

//оператор днлнния на число вещественного типа
//параметры line и f, результат  line*f
//inline CLine operator/ (const CLine &line, const double f)  {  return CLine (line.a/f, line.b/f, line.z/f);  }

__host__ __device__ inline CLine inverse (const CLine &line)
{
	return CLine (line.b, line.a);
}

//оператор сравнения двух точек на равенство
//параметры p1 и p2,  результат  true  или  false
//сравнение ведется до порядка точности EPS
__host__ __device__ inline bool operator== (const CLine &p1, const CLine &p2)
{
	if (p1.a != p2.a)  return false;
	if (p1.b != p2.b)  return false;
	return true;
}

//оператор сравнения двух точек на неравенство
//параметры p1 и p2,  результат  true  или  false
//сравнение ведется до порядка точности EPS
__host__ __device__ inline bool operator!= (const CLine &p1, const CLine &p2)
{
	if (p1.a != p2.a)  return true;
	if (p1.b != p2.b)  return true;
	return false;
}

//функция нахождения расстояния между двумя точками
//параметры p1 и p2, результат - число типа double
//inline double length (const CLine &p1, const CLine &p2)
//{
//	return (p1-p2).length ();
//}

//функция нахождения скалярного произведения
//входяцие аргументы - точки (радиус-вектора) p1 и p2
//результат  число  (p1, p2)
//inline double scalar_product (const CLine &p1, const CLine &p2)
//{
//	return (p1.a*p2.a + p1.b*p2.b + p1.z*p2.z);
//}

//функция нахождения векторного произведения
//входяцие аргументы - точки (радиус-вектора) p1 и p2
//результат  вектор  <p1, p2>
//inline CLine vector_product (const CLine &p1, const CLine &p2)
//{
//	return CLine(p1.b*p2.z - p2.b*p1.z, - p1.a*p2.z + p2.a*p1.z, p1.a*p2.b - p2.a*p1.b);
//}

//функция нахождения смешанного произведения
//входяцие аргументы - точки (радиус-вектора) p1, p2 и p3
//результат  число  (p1, <p2, p3>)
//inline double scalar_triple_product (const CLine &p1, const CLine &p2, const CLine &p3)
//{
//	CLine pp(vector_product(p2, p3));
//	return scalar_product (p1, pp);
//}


#endif
