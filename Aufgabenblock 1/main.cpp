#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include <vector>



void vAufgabe_1()
{
	/*Fahrzeug object1("Audi");
	Fahrzeug* object2 = new Fahrzeug("BMW");
	delete object2;*/

	std::unique_ptr<Fahrzeug> object3(new Fahrzeug("Toyota"));
	std::shared_ptr<Fahrzeug> object4(new Fahrzeug("Koenigsegg"));
	std::shared_ptr<Fahrzeug> object5(new Fahrzeug("Bugatti"));
	std::shared_ptr<Fahrzeug> object6(new Fahrzeug("Audi")); ;
	std::shared_ptr<Fahrzeug> object7(new Fahrzeug("Ford", 150));

	std::vector<std::shared_ptr<Fahrzeug>> vector2;
	vector2.push_back(object4);
	vector2.push_back(object5);
	vector2.push_back(object6);
	vector2.push_back(object7);


	Fahrzeug::vKopf(std::cout);
	for (std::shared_ptr<Fahrzeug> vehicle : vector2)
	{
		vehicle->vAusgeben(std::cout);
	}

}
void vAufgabe_1a()
{
	//dGlobaleZeit = 0.00;
	std::vector<std::unique_ptr<Fahrzeug>> vector1;
	for (int i = 0; i < 3; i++)
	{
		std::string name;
		double maxGeschwindigkeit;
		std::cout << "\nName eingeben: "; std::cin >> name;
		std::cout << "\nMaximale Geschwindigkeit des Fahrzeugs: "; std::cin >> maxGeschwindigkeit;
		//vector1.push_back(std::make_unique<Fahrzeug>(name, maxGeschwindigkeit));
		std::unique_ptr<Fahrzeug> obj(new Fahrzeug(name, maxGeschwindigkeit));
		vector1.push_back(std::move(obj));
	}
	while(dGlobaleZeit <= 5.0)
	{
		for (std::unique_ptr<Fahrzeug>& fahrzeug : vector1)	
		{
			fahrzeug->vSimulieren();
		}	
		dGlobaleZeit += 0.5;
	}

}
void Test()
{
	PKW pkw1("audi", 160, 5.4, 70);
	pkw1.dTanken(21);
}

int main()
{
	//Май трябваше да направим Аусгебен функцията с ostream, за да избегнем "cout::endl"
	//vAufgabe_1a();

	return 0;
}