#include "PKW.h"

double PKW::dTanken(double dMenge)
{	
	double leereRaum = p_dTankVolumen - p_dTankInhalt;	
	double echteBetankungsMenge = (dMenge == std::numeric_limits<double>::infinity()) ? leereRaum : dMenge;
	double betankteMenge = (echteBetankungsMenge <= leereRaum) ? echteBetankungsMenge : leereRaum;	
	std::cout << "\nTank Inhalt vorher:\t" << p_dTankInhalt;
	p_dTankInhalt += betankteMenge;
	std::cout << "\nTank Inhalt jetzt:\t" << p_dTankInhalt;
	std::cout << "\nBetankte Menge:\t\t" << betankteMenge; //zashto tuk trqbva DVA puti tab
	return betankteMenge;
}

