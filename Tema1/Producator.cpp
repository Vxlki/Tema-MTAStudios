#include "Producator.h"

void Producator::generareEfecteSpeciale()
{
	this->scenariu->setEfecteSpeciale();
}

Producator::Producator()
{
	this->nume = "Producator";
	this->cod = rand() % 8192;
}

Producator::Producator(const Producator& obj)
{
	this->nume = obj.nume;
	this->cod = obj.cod;
}
