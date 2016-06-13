#ifndef __E_STRUCT_H__
#define __E_STRUCT_H__



struct FlowConditions
{
	double Mach;
	double gamma;
	double alfa;
	double Re;
	double L0;
	double Prantdl;
	double Twall;
	double H_km;
	double V_ms;
	int input;
	double P8;
	double ro8;

	string String()
	{
		char str[STR_MAX_SIZE];
		string c_str;

		sprintf(str, "%4.1lf\t%3.1lf\t%4.1lf\t%7.2e\t%3.1lf\t%4.2lf\t%.0lf\t%6.3lf\t%.0lf\t%d\t%.0lf\t%5.3lf\n", Mach, gamma, alfa/PI*180., Re, L0, Pr, Twall, H_km, V_ms, input, P8, ro8);
		c_str = str;

		return c_str;
	};

	FlowConditions()
	{};

	FlowConditions(const double &Mach_, const double &gamma_, const double &alfa_, const double &Re_, const double &L0_, const double &Pr_, const double &Twall_, 
				   const double &H_km_, const double &V_ms_, const int &input_, const double &P8_, const double &ro8_)
				   :Mach(Mach_),
					gamma(gamma_),
					alfa(alfa_),
					Re(Re_),
					L0(L0_),
					Prantdl(Pr_),
					Twall(Twall_),
					H_km(H_km_),
					V_ms(V_ms_),
					input(input_),
					P8(P8_),
					ro8(ro8_)
					{/*cout << "Inside constructor FlowConditions" << endl;*/};

	~FlowConditions()
	{};

};

struct ProblemConfig
{
	bool Start;
	int N_iter;
	double cfl0;
	double cfl1;
	bool viscid;
	bool implicit;
	bool CHEM;
	bool TURB;
	bool RAD;

	string String()
	{
		char str[STR_MAX_SIZE];
		string c_str;

		sprintf(str, "%d\t%d\t%.1lf\t%.1lf\t\t%d\t%d\t\t%d\t%d\t%d\n", Start, N_iter, cfl0, cfl1, viscid, implicit, CHEM, TURB, RAD);
		c_str = str;

		return c_str;
	};

	ProblemConfig()
	{};

	ProblemConfig(const bool &Start_, const int &N_iter_, const double &cfl0_, const double &cfl1_, const bool &viscid_, const bool &implicit_, 
				  const bool &CHEM_, const bool &TURB_, const bool &RAD_)
				  :Start(Start_),
			      N_iter(N_iter_),
			      cfl0(cfl0_),
			      cfl1(cfl1_),
			      viscid(viscid_),
			      implicit(implicit_),
			      CHEM(CHEM_),
			      TURB(TURB_),
			      RAD(RAD_)
				 {/*cout << "Inside constructor ProblemConfig" << endl;*/};

	~ProblemConfig()
	{};

};

struct GridSpecification
{
	char filename[STR_MAX_SIZE];
	int Scale;
	bool Rebuild;
	double Compression;
	int new_ny;

	string String()
	{
		char str[STR_MAX_SIZE];
		string c_str;

		sprintf(str, "%s\t\t%d\t\t%d\t%.0e\t\t%d\n", filename, Scale, Rebuild, Compression, new_ny);
		c_str = str;

		return c_str;
	};

	GridSpecification()
	{};

	GridSpecification(const char *filename_, const int &Scale_, const bool &Rebuild_, const double &Compression_, const int &new_ny_)
					  :Scale(Scale_),
					  Rebuild(Rebuild_),
					  Compression(Compression_),
					  new_ny(new_ny_)
				      {
						//cout << "Inside constructor GridSpecification" << endl;
						//cout << filename_ << endl;
				      	strcpy(filename, filename_);
				      };

	~GridSpecification()
	{};

};

struct SolverConfig
{
	char Riemann[STR_MAX_SIZE];
	int GS_iter;
	bool FIX;
	bool MUSCL;
	char LSOLV[STR_MAX_SIZE];

	string String()
	{
		char str[STR_MAX_SIZE];
		string c_str;

		sprintf(str, "%s\t\t%d\t\t%d\t\t%d\t%s\n", Riemann, GS_iter, FIX, MUSCL, LSOLV);
		c_str = str;

		return c_str;
	};

	SolverConfig()
	{};

	SolverConfig(const char *Riemann_, const int &GS_iter_, const bool &FIX_, const bool &MUSCL_, const char *LSOLV_)
				 :GS_iter(GS_iter_),
				 FIX(FIX_),
				 MUSCL(MUSCL_)
				 {
					 //cout << "Inside constructor SolverConfig" << endl;
					 //cout << Riemann_ << endl;
				 	 strcpy(Riemann, Riemann_);
					 //cout << LSOLV_ << endl;
				 	 strcpy(LSOLV, LSOLV_);
					 //cout << "finished" << endl;
				 };

	~SolverConfig()
	{};
};




#endif