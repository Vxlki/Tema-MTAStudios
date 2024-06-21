#pragma once
#include"Scene.h"

class SceneStatice : public Scene
{
protected:
	std::string text;
public:
	SceneStatice(const char* fname);
	void afisareScena() override;
	void afisareScenaInFisierScenarist(const char* fname, int ok) override;
	void afisareScenaInFisierRegizor(const char* fname, int ok) override;
	void afisareScenaInFisierProducator(const char* fname, int ok) override;
	void afisareScenaInFisierDirector(const char* fname, int ok) override;
};