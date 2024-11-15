#include "PKW.h"
#include <iomanip>

double PKW::dTanken(double dMenge)
{
	double leereRaum = p_dTankVolumen - p_dTankInhalt;
	double echteBetankungsMenge = (dMenge == std::numeric_limits<double>::infinity()) ? leereRaum : dMenge;
	double betankteMenge = (echteBetankungsMenge <= leereRaum) ? echteBetankungsMenge : leereRaum;
	//std::cout << "\nTank Inhalt vorher:\t" << p_dTankInhalt;
	p_dTankInhalt += betankteMenge;
	//std::cout << "\nTank Inhalt jetzt:\t" << p_dTankInhalt;
	//std::cout << "\nBetankte Menge:\t\t" << betankteMenge; //zashto tuk trqbva DVA puti tab
	return betankteMenge;
}
void PKW::vSimulieren()
{
	if (p_dTankInhalt > 0)
	{
		if (p_dZeit != dGlobaleZeit) //Zur Vereinfachung soll die Reserve so
									//groﬂ sein, dass der PKW im letzten Schritt noch die komplette Teilstrecke fahren kann.
		{
			/*std::cout << "\nGlobale Zeit im Moment: " << dGlobaleZeit
				<< "\nZeit seit letzter Simulation: " << p_dZeit;*/
			double dtempZeit = dGlobaleZeit - p_dZeit;
			p_dGesamtZeit += dtempZeit;
			//std::cout << "\nGesamte Fahrzeit des Fahrzeugs: " << p_dGesamtZeit;
			p_dGesamtStrecke = dGeschwindigkeit() * p_dGesamtZeit;

			p_dTankInhalt -= (p_dGesamtStrecke * p_dVerbrauch) / 100;

			//std::cout << "\nGesamtstrecke: " << p_dGesamtStrecke << "km";
			p_dZeit = dGlobaleZeit;		

		}
	}
}
std::ostream& PKW::oAusgeben(std::ostream& out) const
{
		Fahrzeug::oAusgeben(out)
		    << std::right
			<< std::setw(13) << p_dTankVolumen
			<< std::setw(12) << p_dTankInhalt
			<< std::setw(13) << p_dVerbrauch  << "\n";
		return out;
}

