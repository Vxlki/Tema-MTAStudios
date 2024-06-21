#pragma once
#include"SceneStatice.h"
#include"SceneDinamice.h"

class Scenariul
{
protected:
	std::vector<Scene*> scena;
	void helperSetReplici(std::vector<std::string>& s1, std::vector <std::string> s2);
public:
	void setScena(std::string tipScena, const char* fname);
	void setNumeActori(std::string numeActor, int stareSpirit, int index);
	void afisareScene();
	void setCadru();
	void setRepliciFiecarePersonaj();
	void setGradComp();
	void setEfecteSpeciale();
	void afisareFirNarativ();
	void afisareScenariuInFisier(const char* fname);
	void afisareScenariuInFisierScenarist(const char* fname);
	void afisareScenariuInFisierRegizor(const char* fname);
	void afisareScenariuInFisierProducator(const char* fname);
	void afisareScenariuInFisierDirector(const char* fname);
};