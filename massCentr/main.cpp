#include "stdafx.h"	

int main(int argc, const char *argv[]) 
{

	cout<<"read MSH file by gmsh fyd"


	char nameoffile[STR_MAX_SIZE];				//, nameofMSHfile[STR_MAX_SIZE];	
	int N_element(0);

	ArgumentsController ac(argc, argv);
	clock_t t;
	t = clock();
	
	if (ac["-f"] != "")
	{ 
		cout<<"Open "<<ac["-f"]<<" file "<<endl;
		for(unsigned int i(0); i<ac["-f"].size(); i++)
			nameoffile[i] = ac["-f"].at(i);
		nameoffile[ac["-f"].size()] = '\0';

		vector<Phyname> name_zone;
		vector<Surface> surface;
		vector<CPoint> points;

		N_element = ReadMSH(nameoffile, points, surface, name_zone);


				vector <Volume> mass_volume;

		for(int i(0); i<surface.size(); i++)
		{
			if( surface.at(i).type == 4 )	// указан номер surface для конкретного файла !!!!!!!!!!!!!!!!!!!!!
			//if(surface.at(i).name == 649 && surface.at(i).type == 4)	
				//new comment
			{
				double a11,a12,a13,a21,a22,a23,a31,a32,a33;
				for(int j(0); j<surface.at(i).points.size();)
				{
					Volume buffer;
					a11 = (points[surface.at(i).points.at(j+1)-1].x-points[surface.at(i).points.at(j)-1].x);
					a12 = (points[surface.at(i).points.at(j+1)-1].y-points[surface.at(i).points.at(j)-1].y);
					a13 = (points[surface.at(i).points.at(j+1)-1].z-points[surface.at(i).points.at(j)-1].z);
					a21 = (points[surface.at(i).points.at(j+2)-1].x-points[surface.at(i).points.at(j)-1].x);
					a22 = (points[surface.at(i).points.at(j+2)-1].y-points[surface.at(i).points.at(j)-1].y);
					a23 = (points[surface.at(i).points.at(j+2)-1].z-points[surface.at(i).points.at(j)-1].z);
					a31 = (points[surface.at(i).points.at(j+3)-1].x-points[surface.at(i).points.at(j)-1].x);
					a32 = (points[surface.at(i).points.at(j+3)-1].y-points[surface.at(i).points.at(j)-1].y);
					a33 = (points[surface.at(i).points.at(j+3)-1].z-points[surface.at(i).points.at(j)-1].z);

					buffer.volume = ( a11*(a22*a33-a23*a32)-a12*(a21*a33-a23*a31)+a13*(a21*a32-a22*a31) )/6.;
					for(int k(0); k<4; k++)
					{
						buffer.x += points[surface.at(i).points.at(j+k)-1].x;
						buffer.y += points[surface.at(i).points.at(j+k)-1].y;
						buffer.z += points[surface.at(i).points.at(j+k)-1].z;
					}
					buffer.x = buffer.x/4.;
					buffer.y = buffer.y/4.;
					buffer.z = buffer.z/4.;

					mass_volume.push_back(buffer);
					j+=4;
				}
			}
			surface.at(i).points.clear();
		}
		surface.clear();
		cout<<"mass_volume.size = "<<mass_volume.size()<<endl;

		Volume centr_mass;
		double sum_mx(0),sum_my(0),sum_mz(0);
		double vol(0);
		for(int i(0); i<mass_volume.size(); i++)
		{
			sum_mx += mass_volume.at(i).xvolume();
			sum_my += mass_volume.at(i).yvolume();
			sum_mz += mass_volume.at(i).zvolume();
			vol += mass_volume.at(i).volume;
		}

		centr_mass.volume = vol;
		centr_mass.x = sum_mx/vol;
		centr_mass.y = sum_my/vol;
		centr_mass.z = sum_mz/vol;
		ofstream file("parametrs.txt", ios::out);
		double Jx(0.), Jy(0.), Jz(0.);
		for(int i(0); i<mass_volume.size(); i++)
		{
			Jx += mass_volume.at(i).momemtx(centr_mass);
			Jy += mass_volume.at(i).momemty(centr_mass);
			Jz += mass_volume.at(i).momemtz(centr_mass);
		}
		Jx = Jx/centr_mass.volume;
		Jy = Jy/centr_mass.volume;
		Jz = Jz/centr_mass.volume;

		mass_volume.clear();
		cout<<"Jx = "<<Jx<<endl;
		cout<<"Jy = "<<Jy<<endl;
		cout<<"Jz = "<<Jz<<endl;
		file<<"Jx = "<<Jx<<endl;
		file<<"Jy = "<<Jy<<endl;
		file<<"Jz = "<<Jz<<endl;

		file<<"volume = "<<centr_mass.volume<<endl;
		file<<"x_centr = "<<centr_mass.x<<endl;
		file<<"y_centr = "<<centr_mass.y<<endl;
		file<<"z_centr = "<<centr_mass.z<<endl;

		file.close();

		centr_mass.showIt();


		cout<<"surface.size() = "<<surface.size()<<endl;
		cout<<"name_zone.size() = "<<name_zone.size()<<endl;
		cout<<"N_Nodes = "<<points.size()<<endl;

		t = clock() - t;
		cout << "*************************** MshReader time = "
			 << (double) t / CLOCKS_PER_SEC
			 << " ****************************" << endl;
	}
	else 
	{
		cout<<"type name file: -f=name_of_file\n end of program"<<endl;
		system("PAUSE");
	}
	return 0;
}
