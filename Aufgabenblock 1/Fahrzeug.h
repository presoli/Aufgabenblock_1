#pragma once
#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_
#include <string>
#include <iostream>
#include <chrono>
extern double dGlobaleZeit;

class Fahrzeug
{
	inline static int p_iMaxID = 1;
protected:
	const int p_iID;
	std::string p_sName;
	const double p_dMaxGeschwindigkeit = 0.00;		//Initialisierung aller Variablen
	double p_dGesamtStrecke = 0.00;
	double p_dGesamtZeit = 0.;
	double p_dZeit = 0.;

public:
	Fahrzeug()		//Default Konstruktor
		:p_sName(""), p_iID(p_iMaxID++)
	{
		std::cout << "Fahrzeug erzeugt: ID: " << p_iID << "\n";
		
	}

	Fahrzeug(std::string sName)		//Konstruktor mit einem Namen als Parameter
		:p_sName(sName), p_iID(p_iMaxID++)
	{
		std::cout << "Fahrzeug erzeugt: Name: " << p_sName
				  << " ID: " << p_iID << ".\n";
		
	}

	Fahrzeug(std::string sName, double dMaxGeschwindigkeit)		//Konstruktor mit einem Namen und der MaxGeschwindigkeit als Parametern
		:p_sName(sName), p_iID(p_iMaxID++), p_dMaxGeschwindigkeit(dMaxGeschwindigkeit > 0 ? dMaxGeschwindigkeit : 0)
	{
		std::cout << "Fahrzeug erzeugt: Name: " << p_sName
				  << " ID: " << p_iID
				  << " MaxGeschwindigkeit: " << p_dMaxGeschwindigkeit << "\n";
		
	}

	virtual ~Fahrzeug()		//Den Destruktor
	{
		std::cout << "\n\nFahrzeug " << p_sName << " mit ID " << p_iID << " geloescht.";
	}

	void vAusgeben(std::ostream& out);

	static void vKopf(std::ostream& out);

	void vSimulieren();

	virtual double dTanken(double p_dMenge = std::numeric_limits<double>::infinity()) 
	{
		return 0.0;
	}



};

#endif