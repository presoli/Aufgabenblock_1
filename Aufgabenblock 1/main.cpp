#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include <vector>



void vAufgabe_1()
{
	/*Fahrzeug object1("Audi");
	Fahrzeug* object2 = new Fahrzeug("BMW");
	delete object2;*/

	std::unique_ptr<PKW> object3(new PKW("Toyota", 150, 4.3));
	std::shared_ptr<PKW> object4(new PKW("Koenigsegg", 400.00, 40));
	std::shared_ptr<PKW> object5(new PKW("Bugatti", 380.00, 35));
	std::shared_ptr<PKW> object6(new PKW("Audi", 200, 6.7)); ;
	std::shared_ptr<PKW> object7(new PKW("Ford", 90, 20));

	std::vector<std::shared_ptr<PKW>> vector2;
	vector2.push_back(object4);
	vector2.push_back(object5);
	vector2.push_back(object6);
	vector2.push_back(object7);


	Fahrzeug::vKopf(std::cout);
	for (std::shared_ptr<PKW> vehicle : vector2)
	{
		std::cout << "\n";
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
void vTest()
{
	std::unique_ptr<PKW> pkw1(std::make_unique<PKW>("audi", 160.7, 7.8, 80));
	pkw1->dTanken(100);
	
}

int main()
{
	vAufgabe_1();
	//vTest();
	

	return 0;
}