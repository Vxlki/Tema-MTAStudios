#pragma once
#include"Angajati.h"

class Producator : public Angajati
{
protected:

public:
	Producator();
	Producator(const Producator& obj);
	void generareEfecteSpeciale();

	//Scenarist
	void setScenariu() {};
	void setScene(std::string tipScena, const char* fname) {};

	//Regizor
	void asignareActori(const char* fname) {};
	void setCadru() {};
	void asignareRepliciPtPersonaje() {};
	void setGradComp() {};
	//void efecteProducator(Producator& producator) {};

	//Director
	void creeareFilm() {};
};