#ifndef __FACE_CUDA_H__
#define __FACE_CUDA_H__

#include "point_cuda.h"



class CFace
{
public:
	int N_Ind;            //количество точек
	int Ind[4];           //индексы точек (лежат в отдельном массиве в программе)
	int Line[4];          //индексы линий;
	CPoint norm;          //нормаль
	CPoint center;        //центр масс
	int visibility;       //видимость частицы вектором потока (задается в функции Find_invisible_faces)


	//конструкторы-деструктор
	__host__ __device__ CFace (void) {};                              //стандартный конструктор
	
	__host__ __device__ CFace (const CFace &face)                     //конструктор копирования
	{
		for (int i = 0; i < 4; i++)
		{
			Ind[i] = face.Ind[i];
			Line[i] = face.Line[i];
			Line[i] = face.Line[i];
		}
	    N_Ind = face.N_Ind;
	    norm = face.norm;
	    center = face.center;
	    visibility = 1;
    };

	//CFace (const CFace &&face)                    //конструктор перемещения
	//{
	//	for (int i = 0; i < 4; i++)
	//	{
	//		Ind[i] = face.Ind[i];
	//		Line[i] = face.Line[i];
	//		Line[i] = face.Line[i];
	//	}
	//    N_Ind = face.N_Ind; 
	//	  norm = face.norm;
	//    center = face.center;
	//    visibility = 1;
	//};
    
	__host__ __device__ CFace (int *Indv, int *Linev, int N_Indv, CPoint normv, CPoint centerv)  //конструктор
    {
		for (int i = 0; i < 4; i++)
		{
			Ind[i] = Indv[i];
			Line[i] = Linev[i];
			Line[i] = Linev[i];
		}
	    N_Ind = N_Indv; 
	    norm = normv;
	    center = centerv;
	    visibility = 1;
    };
    
	__host__ __device__ ~CFace (void) {};                             //деструктор

	__host__ __device__ CFace& operator= (const CFace &face)               //оператор присвоения
    {
	    if (this == &face)  return *this;
		for (int i = 0; i < 4; i++)
		{
			this->Ind[i] = face.Ind[i];
			this->Line[i] = face.Line[i];
			this->Line[i] = face.Line[i];
		}
	    this->N_Ind = face.N_Ind;
	    this->norm = face.norm;
	    this->center = face.center;
	    this->visibility = face.visibility;
	    return *this;
    };
    
	//CFace& operator= (const CFace &&face)              //перемещающий оператор присвоения
	//{
	//    if (this == &face)  return *this;
	//	for (int i = 0; i < 4; i++)
	//	{
	//		this->Ind[i] = face.Ind[i];
	//		this->Line[i] = face.Line[i];
	//		this->Line[i] = face.Line[i];
	//	}
	//    this->N_Ind = face.N_Ind;
	//    this->norm = face.norm;
	//    this->center = face.center;
	//    this->visibility = face.visibility;
	//    return *this;
	//};
    
	__host__ __device__ inline bool operator== (const CFace &face)                //оператор сравнения фигур
    {
        //	bool sig(false);
	    if (N_Ind != face.N_Ind)  return false;
	    for (int i=0; i<face.N_Ind; i++)//  sig = (sig) && (Ind[i]==face.Ind[i]);
		    if (Ind[i] != face.Ind[i])
			    return false;
        if (norm != face.norm)  return false;
	    if (center != face.center)  return false;
	    return true;
        //	return ((sig) && (N_Ind==face.N_Ind) && (norm==face.norm) && (center==face.center));
    };
    
/*	inline bool operator!= (const CFace &face)                //оператор сравнения фигур
    {
        //	bool sig(false);
	    if (norm == face.norm)  return false;
	    if (center == face.center)  return false;
	    if (N_Ind == face.N_Ind)  return false;
	    for (int i=0; i<face.N_Ind; i++)  //sig = (sig) || (Ind[i]!=face.Ind[i]);
		    if (Ind[i] == face.Ind[i])
			   return false;
	    return true;
        //	return ((sig) || (N_Ind!=face.N_Ind) || (norm!=face.norm) || (center!=face.center));
    };
*/


	__host__ __device__ inline void ShowIt ()
    {
	    cout << "center  ";  center.ShowIt ();
	    cout << "normal  ";  norm.ShowIt ();
	    cout << "Indexes:";
	    for (int i=0; i<N_Ind; i++)
		    cout << setw(15) << Ind[i] << " ";
        cout << endl;
    };

	__host__ __device__ inline void set (int *Indv, int *Linev, int N_Indv, CPoint normv, CPoint centerv)
    {
	    N_Ind = N_Indv;
	    center = centerv;
	    norm = normv;
		for (int i = 0; i < N_Indv; i++)
		{
			Ind[i] = Indv[i];
			Line[i] = Linev[i];
			Line[i] = Linev[i];
		}
	    visibility = 1;
    };
};


#endif
