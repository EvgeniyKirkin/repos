#ifndef __LINE_H__
#define __LINE_H__

#include "const.h"

//����� �����
//�������� � ��� ������-��������
class CLine
{
public:

	//����������� �����������
	CLine (void) {};

	//����������� �����������
	//������������ � ������ �����
	CLine (const CLine &line)
	{
		a = line.a;
		b = line.b; 
	};

	////����������� �����������
	////������������ � ������ ��������� �����
	//CLine (const CLine &&line)
	//{
	//	a = line.a;
	//	b = line.b; 
	//};

	//�����������
	//��� ���������� ������ � ����� ����
	CLine (int av, int bv):  a(av), b(bv) {};
	
	//����������� 
	//��� ���������� �����
	CLine (int f):  a(f), b(f) {};

	//����������� ����������
	~CLine (void) {};


	//�������� ����������
	//��������� ������������� ������ �����
	inline void operator= (const CLine &line)
	{
		a = line.a;
		b = line.b;
	};

	////������������ �������� ����������
	////������� ������������� � �������� ��������� �����
	//inline void operator= (const CLine &&line)
	//{
	//	a = line.a;
	//	b = line.b;
	//};

	//�������� ����������
	//��� ��� ���������� �������������� ������ �����
	inline void operator= (const int f)
	{
		a = f;
		b = f;
	};

    //�������� ����-�����
	//�������� ����� � ������
	// a = a + b
	/*inline void operator+= (const CLine &line)
	{
		a += line.a;
		b += line.b;
		z += line.z;
	};*/

    //������������ �������� ����-�����
	//�������� ����� � ������
	// a = a + b
	/*inline void operator+= (const CLine &&line)
	{
		a += line.a;
		b += line.b;
		z += line.z;
	};*/

    //�������� �����-�����
	//��������� �� ����� ������
	// a = a - b
	/*inline void operator-= (const CLine &line)
	{
		a -= line.a;
		b -= line.b;
		z -= line.z;
	};*/

    //������������ �������� �����-�����
	//��������� �� ����� ������
	//a = a - b
	/*inline void operator-= (const CLine &&line)
	{
		a -= line.a;
		b -= line.b;
		z -= line.z;
	};*/

	//�������� ������-����� �� �����
	//������� ��������� �� ����� ������ ����
	/*inline void operator/= (const int f)
	{
		a /= f;
		b /= f;
		z /= f;
	};*/

	//�������� ������-����� �� �����
	//������� ��������� �� ����� ������������� ����
	/*inline void operator/= (const double f)
	{
		a /= f;
		b /= f;
		z /= f;
	};*/

	//�������� ������-����� �� �����
	//������� ��������� �� ����� ������ ����
	/*inline void operator*= (const int f)
	{
		a *= f;
		b *= f;
		z *= f;
	};*/

	//�������� ������-����� �� �����
	//������� ��������� �� ����� ������������� ����
	/*inline void operator*= (const double f)
	{
		a *= f;
		b *= f;
		z *= f;
	};*/




	//����������� ����� �� ������
	//��������� ������ ���������� �����
	inline void ShowIt ()
	{
		cout << setw(15) << a << " " << setw(15) << b << " " << endl;
	};

	//���������� ������������ ����� ����a ���������
	//��������� a = b
	inline void set (CLine line)
	{
		a = line.a;
		b = line.b;
	};

	//���������� ������������ ����� ����a ���������
	//�������� � ����� ����
	inline void set (int av, int bv)
	{
		a = av;
		b = bv;
	};

	//���������� ������������ ����� ����a ���������
	//�������� � ����� ����
	inline void set (int f)
	{
		a = f;
		b = f;
	};

	//����� ������-�������
	//� �������� ������������
	//inline double length ()   {  return sqrt(a*a + b*b + z*z);  };

	//������������ ������-�������
	//� �������� ������������
	//inline void ToSingle ()
	//{
	//	double len = length();		//���� ������ �������, �� ������������ �������.
	//	(len > 0.? a /= len: 0.);
	//	(len > 0.? b /= len: 0.);
	//	(len > 0.? z /= len: 0.);
	//};
	//

public:
	int a; //���������� X
	int b; //���������� Y
};



//�������� ������� �����
//�������� line, ���������  -line
//inline CLine operator- (const CLine &line)  {  return CLine(-line.a, -line.b, -line.z);  }

//�������� �������� ���� �����
//��������� p1 � p2,  ��������� - ����� p1+p2
//inline CLine operator+ (const CLine &p1, const CLine &p2)  {  return CLine (p1.a + p2.a, p1.b + p2.b, p1.z + p2.z);  }

//�������� ��������� �� ����� �����
//��������� p1 � p2,  ��������� - ����� p1-p2
//inline CLine operator- (const CLine &p1, const CLine &p2)  {  return CLine (p1.a - p2.a, p1.b - p2.b, p1.z - p2.z);  }

//�������� ��������� �� ����� ������ ����
//��������� line � f, ���������  line*f
//inline CLine operator* (const CLine &line, const int f)  {  return CLine (line.a*f, line.b*f, line.z*f);  }

//�������� ��������� �� ����� ������������� ����
//��������� line � f, ���������  line*f
//inline CLine operator* (const CLine &line, const double f)  {  return CLine (line.a*f, line.b*f, line.z*f);  }

//�������� ������� �� ����� ������ ����
//��������� line � f, ���������  line*f
//inline CLine operator/ (const CLine &line, const int f)  {  return CLine (line.a/f, line.b/f, line.z/f);  }

//�������� ������� �� ����� ������������� ����
//��������� line � f, ���������  line*f
//inline CLine operator/ (const CLine &line, const double f)  {  return CLine (line.a/f, line.b/f, line.z/f);  }

inline CLine inverse (const CLine &line)
{
	return CLine (line.b, line.a);
}

//�������� ��������� ���� ����� �� ���������
//��������� p1 � p2,  ���������  true  ���  false
//��������� ������� �� ������� �������� EPS
inline bool operator== (const CLine &p1, const CLine &p2)
{
	if (p1.a != p2.a)  return false;
	if (p1.b != p2.b)  return false;
	return true;
}

//�������� ��������� ���� ����� �� �����������
//��������� p1 � p2,  ���������  true  ���  false
//��������� ������� �� ������� �������� EPS
inline bool operator!= (const CLine &p1, const CLine &p2)
{
	if (p1.a != p2.a)  return true;
	if (p1.b != p2.b)  return true;
	return false;
}

//������� ���������� ���������� ����� ����� �������
//��������� p1 � p2, ��������� - ����� ���� double
//inline double length (const CLine &p1, const CLine &p2)
//{
//	return (p1-p2).length ();
//}

//������� ���������� ���������� ������������
//�������� ��������� - ����� (������-�������) p1 � p2
//���������  �����  (p1, p2)
//inline double scalar_product (const CLine &p1, const CLine &p2)
//{
//	return (p1.a*p2.a + p1.b*p2.b + p1.z*p2.z);
//}

//������� ���������� ���������� ������������
//�������� ��������� - ����� (������-�������) p1 � p2
//���������  ������  <p1, p2>
//inline CLine vector_product (const CLine &p1, const CLine &p2)
//{
//	return CLine(p1.b*p2.z - p2.b*p1.z, - p1.a*p2.z + p2.a*p1.z, p1.a*p2.b - p2.a*p1.b);
//}

//������� ���������� ���������� ������������
//�������� ��������� - ����� (������-�������) p1, p2 � p3
//���������  �����  (p1, <p2, p3>)
//inline double scalar_triple_product (const CLine &p1, const CLine &p2, const CLine &p3)
//{
//	CLine pp(vector_product(p2, p3));
//	return scalar_product (p1, pp);
//}


#endif
