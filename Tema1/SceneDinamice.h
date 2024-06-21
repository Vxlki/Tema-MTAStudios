#pragma once
#include"Scene.h"

class SceneDinamice : public Scene
{
protected:
	std::vector <std::string> vectorDeDialog;
	void putDialogueInVector(const char* vdialog, const char* personaj);
public:
	SceneDinamice(const char* fname);
	~SceneDinamice();
	void afisareScena() override;
	std::vector <std::string> getDialogScena() override;
	void afisareScenaInFisierScenarist(const char* fname, int ok);
	void afisareScenaInFisierRegizor(const char* fname, int ok);
	void afisareScenaInFisierProducator(const char* fname, int ok);
	void afisareScenaInFisierDirector(const char* fname, int ok);
};