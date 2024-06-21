#pragma once
#include"Angajati.h"
#include"Scenariul.h"
#include"Producator.h"

class Scenarist : public Angajati
{
protected:
	
public:
	Scenarist();
	void setScenariu();
	void setScene(std::string tipScena, const char* fname);

	//Regizor
	void asignareActori(const char* fname) {};
	void setCadru() {};
	void asignareRepliciPtPersonaje() {};
	void setGradComp() {};
	//void efecteProducator(Producator& producator) {};

	//Producator
	void generareEfecteSpeciale() {};

	//Director
	void creeareFilm() {};
};