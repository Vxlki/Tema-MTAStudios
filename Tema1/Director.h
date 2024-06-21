#pragma once
#include<string>
#include"Angajati.h"
#include"Producator.h"

class Director : public Angajati
{
protected:

public:
	Director();
	void creeareFilm();

	//Scenarist
	void setScenariu() {};
	void setScene(std::string tipScena, const char* fname) {};

	//Regizor
	void asignareActori(const char* fname) {};
	void setCadru() {};
	void asignareRepliciPtPersonaje() {};
	void setGradComp() {};
	void efecteProducator(Producator& producator) {};

	//Producator
	void generareEfecteSpeciale() {};
};