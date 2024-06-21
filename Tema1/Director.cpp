#include "Director.h"

Director::Director()
{
	this->nume = "Director";
	this->cod = rand() % 8192;
}

void Director::creeareFilm()
{
	this->scenariu->afisareFirNarativ();
}
