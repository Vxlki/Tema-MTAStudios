#include "SceneStatice.h"
#include<string>

SceneStatice::SceneStatice(const char* fname) : Scene(fname)
{
	std::ifstream fin(fname);
	char* buff = new char[256];

	int n;
	fin >> n;
	fin.get();
	for (int i = 0; i < n; i++)
		fin.getline(buff, 256);
	delete[] buff;

	std::string pov;

	while (std::getline(fin, pov))
	{
		this->text += pov;
	}

	fin.close();

	this->ajutorCautareAparitii(this->text);
}

void SceneStatice::afisareScena()
{
	if(this->printedScene<this->nrScene)
	{
		Scene::afisareScena();
		std::cout << this->text;
		std::cout << std::endl << std::endl;
	}
}

void SceneStatice::afisareScenaInFisierScenarist(const char* fname, int ok)
{
	std::ofstream fout(fname, std::ios::app);

	if (ok == 1)
		fout << "SCENARIST ADDONS:\n";

	fout << "Scena statica" << ":\n";
	fout << this->text;
	fout << std::endl << std::endl;

	if(ok == 1)
		fout.close();
}

void SceneStatice::afisareScenaInFisierRegizor(const char* fname, int ok)
{
	std::ofstream fout(fname, std::ios::app);

	if (ok == 1)
		fout << "REGIZOR ADDONS:\n";

	fout <<
		this->elNatToString(this->elemNat) << ", " <<
		this->momZiToString(this->momentZi) << ", " <<
		this->stVrToString(this->stareaVremii) << "\n\n";

	SceneStatice::afisareScenaInFisierScenarist(fname, 0);

	if (ok == 1)
		fout.close();
}

void SceneStatice::afisareScenaInFisierProducator(const char* fname, int ok)
{
	std::ofstream fout(fname, std::ios::app);

	if (ok == 1)
		fout << "PRODUCATOR ADDONS:\n";

	fout <<
		this->sonoreToString(this->efecte_sonore) << ", " <<
		this->efVizToString(this->efecte_vizuale) << "\n\n";

	SceneStatice::afisareScenaInFisierRegizor(fname, 0);

	if (ok == 1)
		fout.close();
}

void SceneStatice::afisareScenaInFisierDirector(const char* fname, int ok)
{
	std::ofstream fout(fname, std::ios::app);
	fout << "DIRECTOR ADDONS\n";

	SceneStatice::afisareScenaInFisierRegizor(fname, 0);

	fout.close();
	//Nu am reusit sa le pun sa le afiseze in ordine in fisier
}