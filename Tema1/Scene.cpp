#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include"Scene.h"

int Scene::nrScene = 0;
int Scene::printedScene = 0;

Scene::Scene(const char* fname)
{
	this->nrScene++;

	std::ifstream fin(fname);
	char* buff = new char[256];

	int n;
	fin >> n;
	fin.get();

	for (int i = 0; i < n; i++)
	{
		fin.getline(buff, 256);
		char buff2[256];
		char* p = strtok(buff, "-");
		p = strtok(NULL, "-");
		strcpy(buff2, p);
		p = strtok(NULL, "\n");
		int stare = atoi(p);

		Actor* pers = new Actor(buff, stare, buff2);

		this->personaje.push_back(pers);
	}
	fin.close();
}

void Scene::afisareScena()
{
	if (this->printedScene < this->nrScene)
	{
		std::cout << "Scena " << ++this->printedScene << ":\n";
		std::cout <<
			this->sonoreToString(this->efecte_sonore) << ", " <<
			this->efVizToString(this->efecte_vizuale) << ", " <<
			this->elNatToString(this->elemNat) << ", " <<
			this->momZiToString(this->momentZi) << ", " <<
			this->stVrToString(this->stareaVremii) << "\n\n";
	}
}

void Scene::asignareActorPtPers(std::string numeActor, int stare, int index)
{
	if (index < this->personaje.size())
	{
		this->personaje[index]->setNumeActor(numeActor);
		this->personaje[index]->setStareSpirit(stare);
	}
}

void Scene::setCadru()
{
	this->elemNat = static_cast <elemente_naturale> (rand() % index_EN);
	this->momentZi == static_cast <mom_zi> (rand() % index_MZ);
	this->stareaVremii = static_cast <starea_vremii> (rand() % index_SV);
}

std::vector <std::string> Scene::getDialogScena()
{
	std::vector <std::string> s;
	return s;
}

void Scene::setRepliciSCENA(std::vector<std::string> s)
{
	for (int i = 0; i < this->personaje.size(); i++)
		this->personaje[i]->setRepliciACTOR(s);
}

void Scene::setSumaStareSpirit()
{
	float s = 0;
	for (int i = 0; i < this->personaje.size(); i++)
		s += this->personaje[i]->returnStareSpirit();

	this->gradComp = (s * 0.5) / this->personaje.size();
}

void Scene::setEfecteSpeciale()
{
	if (this->gradComp < 25 && this->stareaVremii == 0)
	{
		this->efecte_sonore = Tunet;
		this->efecte_vizuale = Fulger;
	}
	else
	{
		this->efecte_sonore = Tunet;
		this->efecte_vizuale = Fulger;
	}
}

void Scene::ajutorCautareAparitii(std::string buff)
{
	for (int i = 0; i < this->personaje.size(); i++)
	{
		if (Personaj::findSubstring(buff, this->personaje[i]->getNumePersonaj()))
			this->personaje[i]->incrementAparitii();
	}
	
}

int Scene::getIndexPers(std::string numePers)
{
	for (int i = 0; i < this->personaje.size(); i++)
		if (numePers == this->personaje[i]->getNumePersonaj())
			return i;
	return -1;
}

std::string Scene::elNatToString(elemente_naturale i)
{
	switch (i)
	{
	case elemente_naturale::arbusti: return "arbusti";
	case elemente_naturale::copaci: return "copaci";
	case elemente_naturale::flori: return "flori";
	case elemente_naturale::gazon: return "gazon";
	case elemente_naturale::iarba: return "iarba";
	case elemente_naturale::tufisuri: return "tufisuri";
	default: return "";
	}
}

std::string Scene::momZiToString(mom_zi i)
{
	switch (i)
	{
	case mom_zi::amurg: return "amurg";
	case mom_zi::dimineata: return "dimineata";
	case mom_zi::pranz: return "pranz";
	case mom_zi::noapte: return "noapte";
	case mom_zi::rasarit: return "rasarit";
	default: return "";
	}
}

std::string Scene::stVrToString(starea_vremii i)
{
	switch (i)
	{
	case  starea_vremii::ceata: return "ceata";
	case starea_vremii::ninsoare: return "ninsoare";
	case starea_vremii::ploaie: return "ploaie";
	case starea_vremii::soare: return "soare";
	default: return "";
	}
}

std::string Scene::sonoreToString(sonore i)
{
	switch (i)
	{
	case sonore::Tunet: return "tunet";
	default: return "";
	}
}

std::string Scene::efVizToString(vizuale i)
{
	switch (i)
	{
	case::vizuale::Fulger: return "fulger";
	default: return "";
	}
}




