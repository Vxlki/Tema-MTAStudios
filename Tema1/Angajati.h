#pragma once
#include<iostream>
#include"Scenariul.h"

class Angajati
{
protected:
	std::string nume;
	int cod;
	static Scenariul* scenariu;
public:
	void afisareInFisier(const char* fname);
	void afisareInFisierScenarist(const char* fname);
	void afisareInFisierRegizor(const char* fname);
	void afisareInFisierProducator(const char* fname);
	void afisareInFisierDirector(const char* fname);

	//Scenarist
	virtual void setScenariu() = 0;
	virtual void setScene(std::string tipScena, const char* fname) = 0;
	
	//Regizor
	virtual void asignareActori(const char* fname) = 0;
	virtual void setCadru() = 0;
	virtual void asignareRepliciPtPersonaje() = 0;
	virtual void setGradComp() = 0;
	//virtual void efecteProducator(Producator& producator) = 0;

	//Producator
	virtual void generareEfecteSpeciale() = 0;

	//Director
	virtual void creeareFilm() = 0;
};