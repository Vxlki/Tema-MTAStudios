#include "MTAStudios.h"

MTAStudios* MTAStudios::instance = NULL;
Scenariul* Angajati::scenariu = NULL;

MTAStudios::MTAStudios()
{
	this->MTAProducator = new Producator;
	this->MTARegizor = new Regizor;
	this->MTAScenarist = new Scenarist;
	this->MTADirector = new Director;
}

MTAStudios::MTAStudios(const MTAStudios& obj)
{
	this->MTAProducator = new Producator;
	this->MTARegizor = new Regizor;
	this->MTAScenarist = new Scenarist;
	this->MTADirector = new Director;

	this->MTAProducator = obj.MTAProducator;
	this->MTAScenarist = obj.MTAScenarist;
	this->MTARegizor = obj.MTARegizor;
	this->MTADirector = obj.MTADirector;
}

MTAStudios::~MTAStudios()
{
	delete this->MTAProducator;
	delete this->MTARegizor;
	delete this->MTAScenarist;
	delete this->MTADirector;
}

MTAStudios& MTAStudios::getInstance()
{
	// TODO: insert return statement here
	if (instance == NULL)
		instance = new MTAStudios;
	return (*instance);
}

void MTAStudios::destroyInstance()
{
	if (instance)
	{
		std::cout << "Se face cleanup la MTAStudios...\n";
		delete instance;
		instance = NULL;
	}
	else
	{
		std::cout << "Instanta a fost deja stearsa.\n";
	}
}
