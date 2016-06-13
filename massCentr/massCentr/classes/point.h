#ifndef __POINT_H__
#define __POINT_H__

#include "const.h"

//����� �����
//�������� � ��� ������-��������
class CPoint
{
public:

	//����������� �����������
	CPoint (void) {};

	//����������� �����������
	//������������ � ������ �����
	CPoint (const CPoint &pnt)
	{
		x = pnt.x;
		y = pnt.y; 
		z = pnt.z;
	};

	//����������� �����������
	//������������ � ������ ��������� �����
//	CPoint (const CPoint &&pnt)
//	{
//		x = pnt.x;
//		y = pnt.y; 
//		z = pnt.z;
//	};

	//�����������
	//��� ���������� ������ � ����� ����
	CPoint (double xv, double yv, double zv):  x(xv), y(yv), z(zv) {};
	
	//����������� 
	//��� ���������� �����
	CPoint (double f):  x(f), y(f), z(f) {};

	//����������� ����������
	~CPoint (void) {};

	friend std::ostream& operator<<(std::ostream &os,CPoint &point)
{
	os<<point.x<<" "<<point.y<<" "<<point.z<<endl;
	return os;
}


	//�������� ����������
	//��������� ������������� ������ �����
	inline void operator= (const CPoint &pnt)
	{
		x = pnt.x;
		y = pnt.y;
		z = pnt.z;
	};

	//������������ �������� ����������
	//������� ������������� � �������� ��������� �����
//	inline void operator= (const CPoint &&pnt)
//	{
//		x = pnt.x;
//		y = pnt.y;
//		z = pnt.z;
//	};

	//�������� ����������
	//��� ��� ���������� �������������� ������ �����
	inline void operator= (const double f)
	{
		x = f;
		y = f;
		z = f;
	};

    //�������� ����-�����
	//�������� ����� � ������
	// a = a + b
	inline void operator+= (const CPoint &pnt)
	{
		x += pnt.x;
		y += pnt.y;
		z += pnt.z;
	};

    //������������ �������� ����-�����
	//�������� ����� � ������
	// a = a + b
//	inline void operator+= (const CPoint &&pnt)
//	{
//		x += pnt.x;
//		y += pnt.y;
//		z += pnt.z;
//	};

    //�������� �����-�����
	//��������� �� ����� ������
	// a = a - b 
	inline void operator-= (const CPoint &pnt)
	{
		x -= pnt.x;
		y -= pnt.y;
		z -= pnt.z;
	};

    //������������ �������� �����-�����
	//��������� �� ����� ������
	//a = a - b
//	inline void operator-= (const CPoint &&pnt)
//	{
//		x -= pnt.x;
//		y -= pnt.y;
//		z -= pnt.z;
//	};

	//�������� ������-����� �� �����
	//������� ��������� �� ����� ������ ����
	inline void operator/= (const int f)
	{
		x /= f;
		y /= f;
		z /= f;
	};

	//�������� ������-����� �� �����
	//������� ��������� �� ����� ������������� ����
	inline void operator/= (const double f)
	{
		x /= f;
		y /= f;
		z /= f;
	};

	//�������� ������-����� �� �����
	//������� ��������� �� ����� ������ ����
	inline void operator*= (const int f)
	{
		x *= f;
		y *= f;
		z *= f;
	};

	//�������� ������-����� �� �����
	//������� ��������� �� ����� ������������� ����
	inline void operator*= (const double f)
	{
		x *= f;
		y *= f;
		z *= f;
	};




	//����������� ����� �� ������
	//��������� ������ ���������� �����
	inline void ShowIt ()
	{
		cout << setw(15) << x << " " << setw(15) << y << " " << setw(15) << z << endl;
	};

	//���������� ������������ ����� ����x ���������
	//��������� a = b
	inline void set (CPoint pnt)
	{
		x = pnt.x;
		y = pnt.y;
		z = pnt.z;
	};

	//���������� ������������ ����� ����x ���������
	//�������� � ����� ����
	inline void set (double xv, double yv, double zv)
	{
		x = xv;
		y = yv;
		z = zv;
	};

	//���������� ������������ ����� ����x ���������
	//�������� � ����� ����
	inline void set (double f)
	{
		x = f;
		y = f;
		z = f;
	};

	//����� ������-�������
	//� �������� ������������
	inline double length ()   {  return sqrt(x*x + y*y + z*z);  };

	//������������ ������-�������
	//� �������� ������������
	inline void ToSingle ()
	{
		double len = length();		//���� ������ �������, �� ������������ �������.
		(len > 0.? x /= len: 0.);
		(len > 0.? y /= len: 0.);
		(len > 0.? z /= len: 0.);
	};
	

public:
	double x; //���������� X
	double y; //���������� Y
	double z; //���������� Z
};



//�������� ������� �����
//�������� pnt, ���������  -pnt
inline CPoint operator- (const CPoint &pnt)  {  return CPoint(-pnt.x, -pnt.y, -pnt.z);  }

//�������� �������� ���� �����
//��������� p1 � p2,  ��������� - ����� p1+p2
inline CPoint operator+ (const CPoint &p1, const CPoint &p2)  {  return CPoint (p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);  }

//�������� ��������� �� ����� �����
//��������� p1 � p2,  ��������� - ����� p1-p2
inline CPoint operator- (const CPoint &p1, const CPoint &p2)  {  return CPoint (p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);  }

//�������� ��������� �� ����� ������ ����
//��������� pnt � f, ���������  pnt*f
inline CPoint operator* (const CPoint &pnt, const int f)  {  return CPoint (pnt.x*f, pnt.y*f, pnt.z*f);  }

//�������� ��������� �� ����� ������������� ����
//��������� pnt � f, ���������  pnt*f
inline CPoint operator* (const CPoint &pnt, const double f)  {  return CPoint (pnt.x*f, pnt.y*f, pnt.z*f);  }

//�������� ������� �� ����� ������ ����
//��������� pnt � f, ���������  pnt*f
inline CPoint operator/ (const CPoint &pnt, const int f)  {  return CPoint (pnt.x/f, pnt.y/f, pnt.z/f);  }

//�������� ������� �� ����� ������������� ����
//��������� pnt � f, ���������  pnt*f
inline CPoint operator/ (const CPoint &pnt, const double f)  {  return CPoint (pnt.x/f, pnt.y/f, pnt.z/f);  }

//�������� ��������� ���� ����� �� ���������
//��������� p1 � p2,  ���������  true  ���  false
//��������� ������� �� ������� �������� EPS
inline bool operator== (const CPoint &p1, const CPoint &p2)
{
/*	if (p1.x != p2.x)  return false;
	if (p1.y != p2.y)  return false;
	if (p1.z != p2.z)  return false;*/
	if (fabs(p1.x - p2.x) >= EPS10) return false;
	if (fabs(p1.y - p2.y) >= EPS10) return false;
	if (fabs(p1.z - p2.z) >= EPS10) return false;
	return true;
}

//�������� ��������� ���� ����� �� �����������
//��������� p1 � p2,  ���������  true  ���  false
//��������� ������� �� ������� �������� EPS
inline bool operator!= (const CPoint &p1, const CPoint &p2)
{
	if (fabs(p1.x - p2.x) >= EPS10) return true;
	if (fabs(p1.y - p2.y) >= EPS10) return true;
	if (fabs(p1.z - p2.z) >= EPS10) return true;
	return false;
}

//������� ���������� ���������� ����� ����� �������
//��������� p1 � p2, ��������� - ����� ���� double
inline double length (const CPoint &p1, const CPoint &p2)
{
	return (p1-p2).length ();
}

//������� ���������� ���������� ������������
//�������� ��������� - ����� (������-�������) p1 � p2
//���������  �����  (p1, p2)
inline double scalar_product (const CPoint &p1, const CPoint &p2)
{
	return (p1.x*p2.x + p1.y*p2.y + p1.z*p2.z);
}

//������� ���������� ���������� ������������
//�������� ��������� - ����� (������-�������) p1 � p2
//���������  ������  <p1, p2>
inline CPoint vector_product (const CPoint &p1, const CPoint &p2)
{
	return CPoint(p1.y*p2.z - p2.y*p1.z, - p1.x*p2.z + p2.x*p1.z, p1.x*p2.y - p2.x*p1.y);
}

//������� ���������� ���������� ������������
//�������� ��������� - ����� (������-�������) p1, p2 � p3
//���������  �����  (p1, <p2, p3>)
inline double scalar_triple_product (const CPoint &p1, const CPoint &p2, const CPoint &p3)
{
	CPoint pp(vector_product(p2, p3));
	return scalar_product (p1, pp);
}


#endif
