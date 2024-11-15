#include "Fahrzeug.h"
#include <iomanip>
//#include "main.cpp"
double dGlobaleZeit = 0.00;

void Fahrzeug::vKopf(std::ostream& out)		//Hier formt sich den Ueberschrift
{
	out << "\nID"
		<< std::setw(8) << "Name"
		<< std::setw(24) << "MaxGeschwindigkeit"		//Inhalt, Verbrauch, Volumen
		<< std::setw(16) << "Gesamtstrecke"
		<< std::setw(20) << "Geschwindigkeit"
		<< std::setw(13) << "TankVolumen"
		<< std::setw(13) << "TankInhalt"
		<< std::setw(13) << "Verbrauch\n";
			  

		  out << std::setfill('-')
			  << std::setw(110) << "\n";
}
std::ostream& Fahrzeug::oAusgeben(std::ostream& out) const 	//Hier formt sich das untene Teil der Tabelle
{
		  out << std::setfill(' ')
			  << std::right
			  << std::setw(3) << p_iID
			  << std::setw(2) << ""						//iskat da polzvam std::ios::setiosflags
			  << std::left
			  << std::setw(22) << p_sName
			  << std::right
			  << std::fixed << std::setprecision(2)			
			  << std::setw(6) << p_dMaxGeschwindigkeit
			  << std::setw(16) << p_dGesamtStrecke
			  << std::setw(20) << dGeschwindigkeit();
		  return out;
			  
}
void Fahrzeug::vSimulieren()
{
	if (p_dZeit != dGlobaleZeit)
	{
		/*std::cout << "\nGlobale Zeit im Moment: " << dGlobaleZeit
				  << "\nZeit seit letzter Simulation: " << p_dZeit;*/
		double dtempZeit = dGlobaleZeit - p_dZeit;
		p_dGesamtZeit += dtempZeit;
		/*std::cout << "\nGesamte Fahrzeit des Fahrzeugs: " << p_dGesamtZeit;*/
		p_dGesamtStrecke = dGeschwindigkeit() * p_dGesamtZeit;
		/*std::cout << "\nGesamtstrecke: " << p_dGesamtStrecke << "km";*/
		p_dZeit = dGlobaleZeit;				  
				  
	}
}

std::ostream& operator << (std::ostream& o, const Fahrzeug& fr)
{
	fr.oAusgeben(o);
	return o;
}