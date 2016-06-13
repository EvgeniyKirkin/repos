#include "stdafx.h"

class Phyname
{
public:
	std::string name;
	int number_name;
	int number_element;
	int type;


	Phyname()
	{
		number_element = 0;
		type = 0;
	}

	void set_type(int n){type = n;}

	void set_name(std::string n){name = n;}

	void add_number_element(int n){number_element += n;}

	void set_name(int n){number_name = n;}

	friend inline std::ostream& operator<<(std::ostream &os,Phyname &name)
	{
		os<<name.name<<" "<<name.number_name<<" "<<name.number_element<<" "<<name.type;
		return os;
	}
	void change_name()
	{
		char* cgnsname;
		cgnsname = new char[STR_MAX_SIZE];
		int n(0);
		for(unsigned int i(0); i<name.size(); i++)
		{
			char a = name[i];
			if(a != '"') { cgnsname[n] = a; n++; }
		}
		cgnsname[n] = '\0';
		name = cgnsname;
		delete cgnsname;
	}
};

class Surface
{
public:
	int name;
	int type;
	int phys_serf;
	vector<int> points;

	Surface()
	{
		name = 0;
		type = 0;
		phys_serf = 0;
	}

	Surface( const Surface &n)
	{
		name = n.name;
		type = n.type;
		phys_serf = n.phys_serf;
		points.assign(n.points.begin(),n.points.end());
	}

	inline void operator= ( const Surface &n)
	{
		name = n.name;
		type = n.type;
		phys_serf = n.phys_serf;
	}

	inline bool operator!= ( const Surface &n)
		{
			if(name != n.name) return true;
			if(type != n.type) return true;
			if(phys_serf != n.phys_serf) return true;
			else return false;
		}

	void set_name(int n) {name = n;}
	void set_type(int n) {type = n;}
	void set_phys_serf(int n) {phys_serf = n;}
	//void inline calc_num(Surface n) {num = n.start-start;}
	//void inline calc_num(int n) {num = n-start;}

	friend std::ostream& operator<<(std::ostream &os,Surface &surfase)
{
	os<<surfase.name<<" "<<surfase.type<<" "<<surfase.phys_serf;
	return os;
}
};

class Volume
{
public:
	double volume;
	double x;
	double y;
	double z;
	Volume() : x(0.), y(0.), z(0.)
	{}
	double xvolume() {return x*volume;}
	double yvolume() {return y*volume;}
	double zvolume() {return z*volume;}

	double momemtx(Volume centr_mass) {return ((y-centr_mass.y)*(y-centr_mass.y)+(z-centr_mass.z)*(z-centr_mass.z))*volume;}
	double momemty(Volume centr_mass) {return ((x-centr_mass.x)*(x-centr_mass.x)+(z-centr_mass.z)*(z-centr_mass.z))*volume;}
	double momemtz(Volume centr_mass) {return ((x-centr_mass.x)*(x-centr_mass.x)+(y-centr_mass.y)*(y-centr_mass.y))*volume;}

	void showIt()
	{
		cout<<"volume = "<<volume<<endl;
		cout<<"x = "<<x<<endl;
		cout<<"y = "<<y<<endl;
		cout<<"z = "<<z<<endl;
	}
};