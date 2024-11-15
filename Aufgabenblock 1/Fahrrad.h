#pragma once
#ifndef FAHRRAD_H_
#define FAHRRAD_H_
#include "Fahrzeug.h"

class Fahrrad : public Fahrzeug
{
	public:
		double dTanken(double dMenge = std::numeric_limits<double>::infinity()) override;
		double dGeschwindigkeit() const override;
		std::ostream& oAusgeben(std::ostream& out) const override;

		Fahrrad(std::string sName, double dMaxGeschwindigkeit)
			:Fahrzeug(sName, dMaxGeschwindigkeit) { }
};

#endif