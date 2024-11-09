#pragma once
#ifndef FAHRRAD_H_
#define FAHRRAD_H_
#include "Fahrzeug.h"

class Fahrrad : public Fahrzeug
{
	public:
		double dTanken(double dMenge = std::numeric_limits<double>::infinity()) override;
};

#endif