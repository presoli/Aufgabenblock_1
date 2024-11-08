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
		:Fahrzeug(p_sName, p_dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch),
		p_dTankVolumen(dTankVolumen > 0 ? dTankVolumen : 0),
		p_dTankInhalt(dTankVolumen / 2.0)
	{

	}

	
	double dTanken(double dMenge = std::numeric_limits<double>::infinity()) override 
	{
		double availableSpace = p_dTankvolumen - p_dTankinhalt;

		// Determine the amount to refuel
		double actualAmountToRefuel = (dMenge == std::numeric_limits<double>::infinity()) ? availableSpace : dMenge;
		double refueledAmount = (actualAmountToRefuel <= availableSpace) ? actualAmountToRefuel : availableSpace;

		// Add the refueled amount to the tank
		p_dTankinhalt += refueledAmount;
	}
};
#endif

