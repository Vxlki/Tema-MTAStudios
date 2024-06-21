#include<iostream>
#include"SceneDinamice.h"
#include"SceneStatice.h"
#include"Scenarist.h"
#include"Regizor.h"
#include"MTAStudios.h"

using namespace std;

int main()
{
	MTAStudios& Studio = MTAStudios::getInstance();
	Studio.MTAScenarist->setScenariu();
	Studio.MTAScenarist->setScene("Statica", "Scena1.txt");
	Studio.MTAScenarist->setScene("Dinamica", "Scena2.txt");
	Studio.MTAScenarist->afisareInFisierScenarist("Film.txt");

	Studio.MTARegizor->asignareActori("Actori.txt");
	Studio.MTARegizor->setCadru();
	Studio.MTARegizor->asignareRepliciPtPersonaje();
	Studio.MTARegizor->setGradComp();
	Studio.MTARegizor->afisareInFisierRegizor("Film.txt");

	Studio.MTAProducator->generareEfecteSpeciale();
	Studio.MTAProducator->afisareInFisierProducator("Film.txt");

	Studio.MTADirector->creeareFilm();
	Studio.MTADirector->afisareInFisierDirector("Film.txt");

		
	int a = 2;

	return 0;
}