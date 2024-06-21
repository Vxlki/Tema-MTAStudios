#pragma once
#include"Angajati.h"
#include"Producator.h"

class Regizor : public Angajati
{
protected:

public:
	void asignareActori(const char* fname);
	void setCadru();
	void asignareRepliciPtPersonaje();
	void setGradComp();
	//todo cere producatorului sa puna efecte.
	//void efecteProducator(Producator& producator);

	//Scenarist
	void setScenariu() {};
	void setScene(std::string tipScena, const char* fname) {};

	//Producator
	void generareEfecteSpeciale() {};

	//Director
	void creeareFilm() {};

};