#define _CRT_SECURE_NO_WARNINGS
#include "SceneDinamice.h"

void SceneDinamice::putDialogueInVector(const char* vdialog, const char* personaj)
{
	//char** v = new char* [++c];
	//*v = NULL;
	//if(this->vectorDeDialog)
	//	v = this->vectorDeDialog;
	//this->vectorDeDialog = new char* [c]; 
	//this->vectorDeDialog[c - 1] = new char[strlen(vdialog) + strlen(personaj) + 6];
	//strcpy(this->vectorDeDialog[c - 1], "(");
	//strcat(this->vectorDeDialog[c - 1], personaj);
	//strcat(this->vectorDeDialog[c - 1], "): ");
	//strcat(this->vectorDeDialog[c - 1], vdialog);

	//if(v)
	//{
	//	for (int i = 0; i < c - 1; i++)
	//	{
	//		this->vectorDeDialog[i] = v[i];
	//	}
	//}

	std::string str;
	str = "(";
	str += personaj;
	str += "): ";
	str += vdialog;

	this->vectorDeDialog.push_back(str);
}

SceneDinamice::SceneDinamice(const char* fname) : Scene(fname)
{
	std::ifstream fin(fname);
	char* buff = new char[256];

	int n;
	fin >> n;
	fin.get();
	for (int i = 0; i < n; i++)
		fin.getline(buff, 256);

	while (fin.is_open())
	{
		fin.get();
		fin.getline(buff, 256);

		this->ajutorCautareAparitii(buff);

		char *p = strtok(buff, "*");
		p = strtok(NULL, "\n");
		if (p)
			this->putDialogueInVector(buff, p);
		else
			fin.close();
	}

	for (int i = 0; i < this->personaje.size(); i++)
		this->personaje[i]->setTip();
}

SceneDinamice::~SceneDinamice()
{

}

void SceneDinamice::afisareScena()
{
	if (this->printedScene < this->nrScene)
	{
		Scene::afisareScena();
		for (int i = 0; i < this->vectorDeDialog.size(); i++)
			std::cout << this->vectorDeDialog[i] << std::endl << std::endl;
	}
}

std::vector <std::string> SceneDinamice::getDialogScena()
{
	return this->vectorDeDialog;
}

void SceneDinamice::afisareScenaInFisierScenarist(const char* fname, int ok)
{
	std::ofstream fout(fname, std::ios::app);

	if (ok == 1)
		fout << "SCENARIST ADDONS:\n";

	fout << "Scena dinamica" << ":\n";
	for (int i = 0; i < this->vectorDeDialog.size(); i++)
		fout << this->vectorDeDialog[i] << std::endl << std::endl;

	fout.close();
}

void SceneDinamice::afisareScenaInFisierRegizor(const char* fname, int ok)
{
	std::ofstream fout(fname, std::ios::app);

	if (ok == 1)
		fout << "REGIZOR ADDONS:\n";

	fout <<
		this->elNatToString(this->elemNat) << ", " <<
		this->momZiToString(this->momentZi) << ", " <<
		this->stVrToString(this->stareaVremii) << "\n\n";

	SceneDinamice::afisareScenaInFisierScenarist(fname, 0);

	fout.close();
}

void SceneDinamice::afisareScenaInFisierProducator(const char* fname, int ok)
{
	std::ofstream fout(fname, std::ios::app);

	if (ok == 1)
		fout << "PRODUCATOR ADDONS:\n";

	fout << 
		this->sonoreToString(this->efecte_sonore) << ", " <<
		this->efVizToString(this->efecte_vizuale) << "\n\n";

	SceneDinamice::afisareScenaInFisierRegizor(fname, 0);

		fout.close();
}

void SceneDinamice::afisareScenaInFisierDirector(const char* fname, int ok)
{
	std::ofstream fout(fname, std::ios::app);
	
	fout << "DIRECTOR ADDONS\n";

	SceneDinamice::afisareScenaInFisierRegizor(fname, 0);

	fout.close();
}
