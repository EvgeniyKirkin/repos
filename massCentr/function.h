#pragma once
#include "stdafx.h"

int ReadMSH(const char *name1,  vector<CPoint> &coord, vector<Surface> &surface, vector<Phyname> &name_zone);

int inline Type_elements(int N);

void name_cgns(std::string name, char *cgnsname);
//int Read_MSH_element(char *name1, const char *name2, vector<Surface> &surface, vector<Phyname> &name_zone);
//void Read_MSH_zone(char *name1, const char *name2, int N, int *type_elm, char **name_zone);
//int Read_MSH_file(const char *name1, const char *name2, int number, int *nodes, double *x, double *y, double *z);