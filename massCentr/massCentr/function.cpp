#pragma once
#include "stdafx.h"

int inline Type_elements(int N)
{
	switch(N)
	{
		case 1: return 2;
		case 2: return 3;
		case 3: return 4;
		case 4: return 4;
		case 5: return 8;
		case 6: return 6;
		case 7: return 5;
		case 8: return 3;
		case 9: return 6;
		case 10: return 9;
		case 11: return 10;
		case 12: return 27;
		case 13: return 18;
		case 14: return 14;
		case 15: return 1;
		case 16: return 8;
		default: cout << "wrong geometrical type" << endl; return 0;		
	}
}

int ReadMSH(const char *name1, vector<CPoint> &points, vector<Surface> &surface, vector<Phyname> &name_zone)
{
	int node = 4;
	const char *Nodes = "$Nodes";
	const char *Elements = "$Elements";
	Surface buffer;
	int N_nodes(0);
	double scale(1);
	if (!strcmp(name1, "SimpleHead.msh"))
		scale = 1.;
	int i(0);
	double arr[3] = { 0, 0, 0 };
	char str[STR_MAX_SIZE];
	int N_element(0), name(0), step(0);
	int buffer_phys_syrf , type;
	int n2(-1), number(0), number_n(0), zone(1);



	ifstream file(name1, ios::in);
	if (!file) {
		cout << "File \"" << name1 << "\" not found!\n";
		return 0;
	}

	while(!file.eof())
	{
		if ( !strcmp(str, "$PhysicalNames") ) 
		{
			int n;
			file >> str;
			n = atoi(str);
			Phyname buffer;
				for (int i(0); i < n; i++) 
				{
					file >> str;
					file >> str;
					buffer.set_name(atoi(str));
					file >> str;
					buffer.set_name(str);
					name_zone.push_back(buffer);
				}
			break;
		}
		if(!strcmp(str, Nodes))
		{
			file.seekg(0, ios::beg); break;
		}
		file >> str;
	}

	while (!file.eof()) 
	{
		file >> str;
		if (!strcmp(str, Nodes)) 
		{
			file >> str;
			N_nodes = atoi(str);
			CPoint point;
			for (i = 0; i < N_nodes; i++) 
			{
				file >> str;
				file >> str;
				point.x = atof(str);
				file >> str;
				point.y = atof(str);
				file >> str;
				point.z = atof(str);
				points.push_back(point);
			}
		break;
		}
	}

	//file.close();
	//file.open(name1);

	while(!file.eof())
	{
		file >> str;

		if(!strcmp(str, Elements))
		{
			file >> str;
			N_element = atoi(str);
			file >> str;
			while(strcmp(str, "$EndElements"))
			{	
				file >> str;
				if(!strcmp(str, "$EndElements")){break;}
				buffer.set_type(atoi(str));
				
				file >> str;
				file >> str;
				buffer.set_phys_serf(atoi(str));
				
				file >> str;
				buffer.set_name(atoi(str));
				step = Type_elements(buffer.type);
				for(int j(0); j<step; j++)
				{
					file >> str;
					buffer.points.push_back(atoi(str));
				}
					
				for(int i(1); i<N_element; i++)
				{
					file >> str;
					file >> str;
					type = atoi(str);
				
					file >> str;
					file >> str;
					buffer_phys_syrf = atoi(str);
				
								
					file >> str;
					if(buffer.name != atoi(str))
					{
						surface.push_back(buffer);
						buffer.points.clear();
						buffer.set_name(atoi(str));
						step = Type_elements(type);
					}
					for(int j(0); j<step; j++)
					{
						file >> str;
						buffer.points.push_back(atoi(str));
					}
					buffer.set_phys_serf(buffer_phys_syrf);
					buffer.set_type(type);
				}	
			}
			if(!strcmp(str, "$EndElements")){surface.push_back(buffer); buffer.points.clear(); break;}
		}
	}

	for(unsigned int i(0); i<name_zone.size(); i++)
	for(unsigned int j(0); j<surface.size(); j++)
		if(surface.at(j).phys_serf == name_zone.at(i).number_name)
			{
				name_zone.at(i).add_number_element((surface.at(j).points.size()/Type_elements(surface.at(j).type)));
				name_zone.at(i).set_type(surface.at(j).type);
			}
	return N_element;
}

void name_cgns(std::string name, char *cgnsname)
{
	int n(0);
	for(unsigned int i(0); i<name.size(); i++)
	{
		char a = name[i];
		if(a != '"') { cgnsname[n] = a; n++; }
	}
	cgnsname[n] = '\0';
	return;
}
