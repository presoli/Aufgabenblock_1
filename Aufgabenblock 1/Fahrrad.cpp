#include "Fahrrad.h"
//#include 

double Fahrrad::dTanken(double dMenge)
{
	return 0.0;
}
double Fahrrad::dGeschwindigkeit() const
{
	double geschwindigkeitsKoeffizient = std::floor(p_dGesamtStrecke / 20); //fuer die Abnahme der Geschwindigkeit
	double geschwindigkeit = p_dMaxGeschwindigkeit - (p_dMaxGeschwindigkeit * geschwindigkeitsKoeffizient * 10 / 100);
	if (geschwindigkeit < 12)
	{
		geschwindigkeit = 12;
	}
	return geschwindigkeit;
}
std::ostream& Fahrrad::oAusgeben(std::ostream& out) const
{
	Fahrzeug::oAusgeben(out) << "\n";
	return out;
}
