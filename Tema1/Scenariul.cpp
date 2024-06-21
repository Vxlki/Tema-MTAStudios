#include "Scenariul.h"
#include<vector>

void Scenariul::helperSetReplici(std::vector<std::string>& s1, std::vector<std::string> s2)
{
	for (int i = 0; i < s2.size(); i++)
		s1.push_back(s2[i]);
}

void Scenariul::setScena(std::string tipScena, const char* fname)
{
	if (tipScena == "Dinamica")
	{
		Scene* scena = new SceneDinamice(fname);
		this->scena.push_back(scena);
	}
	if (tipScena == "Statica")
	{
		Scene* scena = new SceneStatice(fname);
		this->scena.push_back(scena);
	}
}

void Scenariul::setNumeActori(std::string numeActor, int stareSpirit, int index)
{
	for (int i = 0; i < this->scena.size(); i++)
	{
		this->scena[i]->asignareActorPtPers(numeActor, stareSpirit, index);
	}
}

void Scenariul::afisareScene()
{
	for (int i = 0; i < this->scena.size(); i++)
		this->scena[i]->afisareScena();
}

void Scenariul::setCadru()
{
	for (int i = 0; i < this->scena.size(); i++)
		this->scena[i]->setCadru();
}

void Scenariul::setRepliciFiecarePersonaj()
{
	std::vector <std::string> replici;

	for (int i = 0; i < this->scena.size(); i++)
	{
		helperSetReplici(replici, this->scena[i]->getDialogScena());
	}

	for(int i=0;i<this->scena.size();i++)
		this->scena[i]->setRepliciSCENA(replici);

}

void Scenariul::setGradComp()
{
	for (int i = 0; i < this->scena.size(); i++)
		this->scena[i]->setSumaStareSpirit();
}

void Scenariul::setEfecteSpeciale()
{
	for (int i = 0; i < this->scena.size(); i++)
		this->scena[i]->setEfecteSpeciale();
}

void Scenariul::afisareFirNarativ()
{
	for (int i = 0; i < this->scena.size(); i++)
		this->scena[i]->afisareScena();
}

void Scenariul::afisareScenariuInFisier(const char* fname)
{
	for (int i = 0; i < this->scena.size(); i++)
	{
		this->scena[i]->afisareScenaInFisierScenarist(fname, 1);
		this->scena[i]->afisareScenaInFisierRegizor(fname, 1);
		this->scena[i]->afisareScenaInFisierProducator(fname, 1);
		this->scena[i]->afisareScenaInFisierDirector(fname, 1);
	}
}

void Scenariul::afisareScenariuInFisierScenarist(const char* fname)
{
	for (int i = 0; i < this->scena.size(); i++)
		this->scena[i]->afisareScenaInFisierScenarist(fname, 1);
}

void Scenariul::afisareScenariuInFisierRegizor(const char* fname)
{
	for (int i = 0; i < this->scena.size(); i++)
		this->scena[i]->afisareScenaInFisierRegizor(fname, 1);
}

void Scenariul::afisareScenariuInFisierProducator(const char* fname)
{
	for (int i = 0; i < this->scena.size(); i++)
		this->scena[i]->afisareScenaInFisierProducator(fname, 1);
}

void Scenariul::afisareScenariuInFisierDirector(const char* fname)
{
	for (int i = 0; i < this->scena.size(); i++)
		this->scena[i]->afisareScenaInFisierDirector(fname, 1);
}
