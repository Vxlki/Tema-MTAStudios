#include "Angajati.h"

void Angajati::afisareInFisier(const char* fname)
{
	this->scenariu->afisareScenariuInFisier(fname);
}

void Angajati::afisareInFisierScenarist(const char* fname)
{
	this->scenariu->afisareScenariuInFisierScenarist(fname);
}

void Angajati::afisareInFisierRegizor(const char* fname)
{
	this->scenariu->afisareScenariuInFisierRegizor(fname);
}

void Angajati::afisareInFisierProducator(const char* fname)
{
	this->scenariu->afisareScenariuInFisierProducator(fname);
}

void Angajati::afisareInFisierDirector(const char* fname)
{
	this->scenariu->afisareScenariuInFisierDirector(fname);
}

