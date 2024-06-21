#include "Scenarist.h"

Scenarist::Scenarist()
{
	this->nume = "Scenarist";
	this->cod = rand() % 8192;
}

void Scenarist::setScenariu()
{
	this->scenariu = new Scenariul;
}

void Scenarist::setScene(std::string tipScena, const char* fname)
{
	this->scenariu->setScena(tipScena, fname);
}
