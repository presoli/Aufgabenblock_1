#pragma once
#ifndef PKW_H_
#define PKW_H_
#include "Fahrzeug.h"
#include <limits>

class PKW : public Fahrzeug
{
	//using Fahrzeug::Fahrzeug; tova kakvo pravi na teoriq?
private:
	const double p_dVerbrauch;
	const double p_dTankVolumen;
	double p_dTankInhalt;

public:
	PKW(std::string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankVolumen = 55.0)
		:Fahrzeug(sName, dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch), //tuk bqh slojil p_sName i p_MaxGeschwindigkeit, a to e trqbvalo da bude tova, koeto e sega, ZASHTO??!
		p_dTankVolumen(dTankVolumen > 0 ? dTankVolumen : 0), // 0 trqbva li da e po skoro 55 ili ne?
		p_dTankInhalt(dTankVolumen / 2.0) {}	

	
	double dTanken(double dMenge = std::numeric_limits<double>::infinity()) override;	
	
};
#endif

