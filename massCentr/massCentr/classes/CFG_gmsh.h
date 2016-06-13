#ifndef __CFG_GMSH_H__
#define __CFG_GMSH_H__

#include "const.h"




class CFG_GMSH
{
public:
	inline int load_folder_path()
	{
		int i;
		int rd;
		double d;
		char str[_STR_LEN_MAX_], str_[_STR_LEN_MAX_];

		initialize();
		//err = 0;

		sprintf_s (str, "%s", str_geocfgfl);
		geocfgfl = fopen (str, "r");
		if (!geocfgfl)
		{
			fprintf (stderr, "Error open Geo.cfg file: %s!!!\n", str);
			sprintf_s (str_err, "\"%s\" not found!", str_geocfgfl);
			err = 1;
			return err;
		}

		rd = fscanf (geocfgfl, "*****FILE LIST*****\n"); //printf ("1st line:   rd = %d\n", rd);
		if (rd != 0) 
		{
			sprintf_s (str_err, "Line 1: can't read \"*****FILE LIST*****\"");
			err = 11;
			return err;
		}
		rd = fscanf (geocfgfl, "filesrc=%s\n", str_geofl);  //printf ("2nd line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 2: can't read \"filesrc=*string*\"");
			err = 12;
			return err;
		}
//		fscanf (geocfgfl, "trajsrc=%s\n", str_trajfl);

		rd = fscanf (geocfgfl, "loader=%d\n", &i);  //printf ("3rd line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 3: can't read \"loader=*int*\"");
			err = 13;
			return err;
		}

		rd = fscanf (geocfgfl, "scale=%lf\n", &d);  //printf ("4th line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 4: can't read \"scale=*double*\"");
			err = 14;
			return err;
		}

		rd = fscanf (geocfgfl, "axis=%d\n", &i);  //printf ("5th line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 5: can't read \"axis=*int*\"");
			err = 15;
			return err;
		}

		rd = fscanf (geocfgfl, "%d %d %d\n", &i, &i, &i);  //printf ("6th line:   rd = %d\n", rd);
		if (rd != 3)
		{
			sprintf_s (str_err, "Line 6: can't read \"*int* *int* *int*\"");
			err = 16;
			return err;
		}

		rd = fscanf (geocfgfl, "%d %d %d\n", &i, &i, &i);  //printf ("7th line:   rd = %d\n", rd);
		if (rd != 3)
		{
			sprintf_s (str_err, "Line 7: can't read \"*int* *int* *int*\"");
			err = 17;
			return err;
		}

		rd = fscanf (geocfgfl, "%lf\n", &d);  //printf ("8th line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 8: can't read \"*double*\"");
			err = 18;
			return err;
		}

		rd = fscanf (geocfgfl, "%lf\n", &d);  //printf ("9th line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 9: can't read \"*double*\"");
			err = 19;
			return err;
		}

		rd = fscanf (geocfgfl, "exp_HeatTransfer=%d\n", &i);  //printf ("10th line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 10: can't read \"exp_HeatTransfer=*int*\"");
			err = 20;
			return err;
		}

		rd = fscanf (geocfgfl, "silent_mode=%d\n", &i);  //printf ("11th line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 11: can't read \"silent_mode=*int*\"");
			err = 21;
			return err;
		}

		rd = fscanf (geocfgfl, "calc_height=%d\n", &i);  //printf ("12th line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 12: can't read \"calc_height=*int*\"");
			err = 22;
			return err;
		}

		rd = fscanf (geocfgfl, "%s\n", str_);  //printf ("13th line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 13: can't read \"endcfg\"");
			err = 23;
			return err;
		}

		rd = fscanf (geocfgfl, "trajsrc=%s\n", str_trajfl);  //printf ("14th line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 14: can't read \"trajsrc=*string*\"");
			err = 24;
			return err;
		}

		fclose (geocfgfl);

		sprintf_s (str, "%s", strrchr(str_geofl, '/'));
		*strrchr (str, '.') = '\0';
		sprintf_s (str_path_folder, ".%s/", str);	
		sprintf_s (str_folderR, "%sResult/", str_path_folder);
		sprintf_s (str_folderS, "%sService/", str_path_folder);
		sprintf_s (str_folderD, "%sDebug/", str_path_folder);
		sprintf_s (str_folderG, "%sGeom/", str_path_folder);
		sprintf_s (str_folderL, "%sLogs/", str_path_folder);
		sprintf_s (str_folderI, "%sInitia/", str_path_folder);
	//	sprintf_s (str_folderE, "%s../_Service/", str_path_folder);
		sprintf_s (str_folderC, "%s", str_path_folder);
		ird_mkdir (str_path_folder);
		ird_mkdir (str_folderR);
		ird_mkdir (str_folderS);
		ird_mkdir (str_folderD);
		ird_mkdir (str_folderG);
		ird_mkdir (str_folderL);
		ird_mkdir (str_folderI);
		ird_mkdir (str_folderC);

		sprintf_s (str_end, "%s", strrchr(str_geofl, '.'));
	//	strupr (str_end);

		return err;
	};


	inline int load_folder_path(char *ss)
	{
		int i;
		int rd;
		double d;
		char str[_STR_LEN_MAX_], str_[_STR_LEN_MAX_];
		char str_trajfl1[_STR_LEN_MAX_], str_geofl1[_STR_LEN_MAX_];

		initialize();
		//err = 0;

		sprintf_s (str, "%s%s", ss, str_geocfgfl);
		geocfgfl = fopen (str, "r");
		if (!geocfgfl)
		{
			fprintf (stderr, "Error open Geo.cfg file: %s!!!\n", str);
			sprintf_s (str_err, "\"%s\" not found!", str_geocfgfl);
			err = 1;
			return err;
		}

		rd = fscanf (geocfgfl, "*****FILE LIST*****\n"); //printf ("1st line:   rd = %d\n", rd);
		if (rd != 0) 
		{
			sprintf_s (str_err, "Line 1: can't read \"*****FILE LIST*****\"");
			err = 11;
			return err;
		}
		rd = fscanf (geocfgfl, "filesrc=%s\n", str_geofl1);  //printf ("2nd line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 2: can't read \"filesrc=*string*\"");
			err = 12;
			return err;
		}
		sprintf (str_geofl, "%s%s", ss, str_geofl1);
//		fscanf (geocfgfl, "trajsrc=%s\n", str_trajfl);

		rd = fscanf (geocfgfl, "loader=%d\n", &i);  //printf ("3rd line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 3: can't read \"loader=*int*\"");
			err = 13;
			return err;
		}

		rd = fscanf (geocfgfl, "scale=%lf\n", &d);  //printf ("4th line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 4: can't read \"scale=*double*\"");
			err = 14;
			return err;
		}

		rd = fscanf (geocfgfl, "axis=%d\n", &i);  //printf ("5th line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 5: can't read \"axis=*int*\"");
			err = 15;
			return err;
		}

		rd = fscanf (geocfgfl, "%d %d %d\n", &i, &i, &i);  //printf ("6th line:   rd = %d\n", rd);
		if (rd != 3)
		{
			sprintf_s (str_err, "Line 6: can't read \"*int* *int* *int*\"");
			err = 16;
			return err;
		}

		rd = fscanf (geocfgfl, "%d %d %d\n", &i, &i, &i);  //printf ("7th line:   rd = %d\n", rd);
		if (rd != 3)
		{
			sprintf_s (str_err, "Line 7: can't read \"*int* *int* *int*\"");
			err = 17;
			return err;
		}

		rd = fscanf (geocfgfl, "%lf\n", &d);  //printf ("8th line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 8: can't read \"*double*\"");
			err = 18;
			return err;
		}

		rd = fscanf (geocfgfl, "%lf\n", &d);  //printf ("9th line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 9: can't read \"*double*\"");
			err = 19;
			return err;
		}

		rd = fscanf (geocfgfl, "exp_HeatTransfer=%d\n", &i);  //printf ("10th line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 10: can't read \"exp_HeatTransfer=*int*\"");
			err = 20;
			return err;
		}

		rd = fscanf (geocfgfl, "silent_mode=%d\n", &i);  //printf ("11th line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 11: can't read \"silent_mode=*int*\"");
			err = 21;
			return err;
		}

		rd = fscanf (geocfgfl, "calc_height=%d\n", &i);  //printf ("12th line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 12: can't read \"calc_height=*int*\"");
			err = 22;
			return err;
		}

		rd = fscanf (geocfgfl, "%s\n", str_);  //printf ("13th line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 13: can't read \"endcfg\"");
			err = 23;
			return err;
		}

		rd = fscanf (geocfgfl, "trajsrc=%s\n", str_trajfl1);  //printf ("14th line:   rd = %d\n", rd);
		if (rd != 1)
		{
			sprintf_s (str_err, "Line 14: can't read \"trajsrc=*string*\"");
			err = 24;
			return err;
		}
		sprintf (str_trajfl, "%s%s", ss, str_trajfl1);

		fclose (geocfgfl);

		sprintf_s (str, "%s", strrchr(str_geofl, '/'));
		*strrchr (str, '.') = '\0';
		sprintf_s (str_path_folder, "%s.%s/", ss, str);	
		sprintf_s (str_folderR, "%sResult/", str_path_folder);
		sprintf_s (str_folderS, "%sService/", str_path_folder);
		sprintf_s (str_folderD, "%sDebug/", str_path_folder);
		sprintf_s (str_folderG, "%sGeom/", str_path_folder);
		sprintf_s (str_folderL, "%sLogs/", str_path_folder);
		sprintf_s (str_folderI, "%sInitia/", str_path_folder);
	//	sprintf_s (str_folderE, "%s../_Service/", str_path_folder);
		sprintf_s (str_folderC, "%s", str_path_folder);
		ird_mkdir (str_path_folder);
		ird_mkdir (str_folderR);
		ird_mkdir (str_folderS);
		ird_mkdir (str_folderD);
		ird_mkdir (str_folderG);
		ird_mkdir (str_folderL);
		ird_mkdir (str_folderI);
		ird_mkdir (str_folderC);

		sprintf_s (str_end, "%s", strrchr(str_geofl, '.'));
	//	strupr (str_end);

		return err;
	};


	inline void initialize()
	{
		err = 0;
		sprintf_s (str_err, "NULL");
		sprintf_s (str_end, "NULL");
		sprintf_s (str_logfile, "NULL");
		sprintf_s (str_geofl, "NULL");
		sprintf_s (str_trajfl, "NULL");
		sprintf_s (str_path_folder, "NULL");
		sprintf_s (str_folderR, "NULL");
		sprintf_s (str_folderS, "NULL");
		sprintf_s (str_folderD, "NULL");
		sprintf_s (str_folderG, "NULL");
		sprintf_s (str_folderL, "NULL");
		sprintf_s (str_folderI, "NULL");
		sprintf_s (str_folderC, "NULL");
		sprintf_s (str_ini_folder, "NULL");
	};


	inline int show_results()
	{
		fprintf (stdout, "Geo_cfg_file = \"%s\"\n", str_geocfgfl);
		fprintf (stdout, "Type of file = \"%s\"\n", str_end);
		fprintf (stdout, "Home folder = \"%s\"\n", str_folderC);
		fprintf (stdout, "Debug folder = \"%s\"\n", str_folderD);
		fprintf (stdout, "Geometry folder = \"%s\"\n", str_folderG);
		fprintf (stdout, "Init folder = \"%s\"\n", str_folderI);
		fprintf (stdout, "Log folder = \"%s\"\n", str_folderL);
		fprintf (stdout, "Result folder = \"%s\"\n", str_folderR);
		fprintf (stdout, "Service folder = \"%s\"\n", str_folderS);
		fprintf (stdout, "Mesh file = \"%s\"\n", str_geofl);
		fprintf (stdout, "Unknown (str_ini_folder, unused) folder = \"%s\"\n", str_ini_folder);
		fprintf (stdout, "Log file (unused) = \"%s\"\n", str_logfile);
		fprintf (stdout, "Home path folder = \"%s\"\n", str_path_folder);
		fprintf (stdout, "Input trajectory folder = \"%s\"\n", str_trajfl);
		return 0;
	};


	inline int show_results_in_log(FILE *logfl)
	{
		fprintf (logfl, "Geo_cfg_file = \"%s\"\n", str_geocfgfl);
		fprintf (logfl, "Type of file = \"%s\"\n", str_end);
		fprintf (logfl, "Home folder = \"%s\"\n", str_folderC);
		fprintf (logfl, "Debug folder = \"%s\"\n", str_folderD);
		fprintf (logfl, "Geometry folder = \"%s\"\n", str_folderG);
		fprintf (logfl, "Init folder = \"%s\"\n", str_folderI);
		fprintf (logfl, "Log folder = \"%s\"\n", str_folderL);
		fprintf (logfl, "Result folder = \"%s\"\n", str_folderR);
		fprintf (logfl, "Service folder = \"%s\"\n", str_folderS);
		fprintf (logfl, "Mesh file = \"%s\"\n", str_geofl);
		fprintf (logfl, "Unknown (str_ini_folder, unused) folder = \"%s\"\n", str_ini_folder);
		fprintf (logfl, "Log file (unused) = \"%s\"\n", str_logfile);
		fprintf (logfl, "Home path folder = \"%s\"\n", str_path_folder);
		fprintf (logfl, "Input trajectory folder = \"%s\"\n", str_trajfl);
		fflush (logfl);
		return 0;
	};


	inline void create_geo_file(const char *nm)
	{
		FILE* fl = fopen (nm, "w+");
		fprintf (fl, "*****FILE LIST*****\n");
		fprintf (fl, "filesrc=./_Mesh/sphere-stl.stl\n");
		fprintf (fl, "loader=3\n");
		fprintf (fl, "scale=1.000\n");
		fprintf (fl, "axis=0\n");
		fprintf (fl, "0 0 0\n");
		fprintf (fl, "1 0 0\n");
		fprintf (fl, "0.01\n");
		fprintf (fl, "0.0000001\n");
		fprintf (fl, "exp_HeatTransfer=1\n");
		fprintf (fl, "silent_mode=1\n");
		fprintf (fl, "calc_height=0\n");
		fprintf (fl, "endcfg\n");
		fprintf (fl, "trajsrc=./_Service/traject.dat\n");
		fclose (fl);
		return;
	};




	//*****FILE LIST*****
	//filesrc=./_Mesh/sphere-stl.stl
	//loader=3
	//scale=1.000
	//axis=0
	//0 0 0
	//1 0 0
	//0.01
	//0.0000001
	//exp_HeatTransfer=1
	//silent_mode=1
	//calc_height=0
	//endcfg
	//trajsrc=./_Service/traject.dat


public:
	FILE *geocfgfl;
	char str_logfile[_STR_LEN_MAX_];
	char str_geofl[_STR_LEN_MAX_];
	char str_end[_STR_LEN_MAX_];

	char str_trajfl[_STR_LEN_MAX_];           //файл с траекторией

	char str_path_folder[_STR_LEN_MAX_];      //Path to project root
//	char str_out_folder[_STR_LEN_MAX_];       //hz
	char str_folderR[_STR_LEN_MAX_];          //Result - for user
	char str_folderS[_STR_LEN_MAX_];          //Service - dump, data exchange with module
	char str_folderD[_STR_LEN_MAX_];          //Debug
	char str_folderG[_STR_LEN_MAX_];          //Geometry
	char str_folderL[_STR_LEN_MAX_];          //Logs
	char str_folderI[_STR_LEN_MAX_];          //Initia
//	char str_folderE[_STR_LEN_MAX_];          //Envirement - common data
	char str_folderC[_STR_LEN_MAX_];          //CFG - files .cfg
	char str_ini_folder[_STR_LEN_MAX_];

	int  err;                                 //номер ошибки чтения
	char str_err[_STR_LEN_MAX_];              //ЗАЩИТА на ошибку чтения
};



#endif
