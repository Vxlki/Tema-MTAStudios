#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"Actor.h"


typedef enum
{
	copaci, arbusti, flori, tufisuri, gazon, iarba, index_EN
}elemente_naturale;

typedef enum
{
	rasarit, dimineata, pranz, amurg, noapte, index_MZ
}mom_zi;

typedef enum
{
	ploaie, ceata, ninsoare, soare, index_SV
}starea_vremii;

typedef enum
{
	Tunet
}sonore;

typedef enum
{
	Fulger
}vizuale;

class Scene
{
protected:
	std::vector <Actor*> personaje;

	static int nrScene;
	static int printedScene;
	elemente_naturale elemNat;
	mom_zi momentZi;
	starea_vremii stareaVremii;
	sonore efecte_sonore;
	vizuale efecte_vizuale;
	float gradComp;
	void ajutorCautareAparitii(std::string buff);
	int getIndexPers(std::string numePers);
	std::string elNatToString(elemente_naturale i);
	std::string momZiToString(mom_zi i);
	std::string stVrToString(starea_vremii i);
	std::string sonoreToString(sonore i);
	std::string efVizToString(vizuale i);
public:
	Scene(const char* fname);
	virtual void afisareScena();
	void asignareActorPtPers(std::string numeActor, int stare, int index);
	void setCadru();
	virtual std::vector <std::string> getDialogScena();
	void setRepliciSCENA(std::vector <std::string> s);
	void setSumaStareSpirit();
	void setEfecteSpeciale();
	virtual void afisareScenaInFisierScenarist(const char* fname, int ok) = 0;
	virtual void afisareScenaInFisierRegizor(const char* fname, int ok)= 0;
	virtual void afisareScenaInFisierProducator(const char* fname, int ok) = 0;
	virtual void afisareScenaInFisierDirector(const char* fname, int ok) = 0;
};