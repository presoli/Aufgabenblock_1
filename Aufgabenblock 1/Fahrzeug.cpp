#include "Fahrzeug.h"
#include <iomanip>
//#include "main.cpp"
double dGlobaleZeit = 0.00;

void Fahrzeug::vKopf(std::ostream& out)		//Hier formt sich den Ueberschrift
{
		  out << "\nID" 
			  << std::setw(8) << "Name"
			  << std::setw(24) << "MaxGeschwindigkeit"
			  << std::setw(16) << "Gesamtstrecke\n";

		  out << std::setfill('-')
			  << std::setw(53);
}
void Fahrzeug::vAusgeben(std::ostream& out)		//Hier formt sich das untene Teil der Tabelle
{
		  out << std::setfill(' ')
			  << std::right
			  << std::setw(3) << p_iID
			  << std::setw(2) << ""
			  << std::left
			  << std::setw(22) << p_sName
			  << std::right
			  << std::fixed << std::setprecision(2)
			  << std::setw(6) << p_dMaxGeschwindigkeit
			  << std::setw(15) << p_dGesamtStrecke << "\n";
}
void Fahrzeug::vSimulieren()
{
	if (p_dZeit != dGlobaleZeit)
	{
		std::cout << "\nGlobale Zeit im Moment: " << dGlobaleZeit
				  << "\nZeit seit letzter Simulation: " << p_dZeit;
		double dtempZeit = dGlobaleZeit - p_dZeit;
		p_dGesamtZeit += dtempZeit;
		std::cout << "\nGesamte Fahrzeit des Fahrzeugs: " << p_dGesamtZeit;
		p_dGesamtStrecke = p_dMaxGeschwindigkeit * p_dGesamtZeit;
		std::cout << "\nGesamtstrecke: " << p_dGesamtStrecke << "km";
		p_dZeit = dGlobaleZeit;
		
				  
				  
	}
}