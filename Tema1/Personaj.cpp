#define _CRT_SECURE_NO_WARNINGS
#include "Personaj.h"

void Personaj::setTip()
{
	if (this->aparitii < 3)
	{
		this->tipPersonaj = Figurant;
		this->stareSpirit -= (1 / 4) * stareSpirit;
	}
	else
	{
		this->stareSpirit += (1 / 4) * stareSpirit;
		this->tipPersonaj = Principal;
	}
}

int Personaj::findSubstring(std::string& string, std::string substring)
{
	size_t find = string.find(substring);

	if (find != std::string::npos)
		return 1;
	else return 0;
}

float Personaj::getStareSpirit()
{
	return this->stareSpirit;
}

void Personaj::setStareSpirit(float stare)
{
	this->stareSpirit = stare;
}

void Personaj::adaugareReplica(std::vector<std::string> replica)
{
	for (int i = 0; i < replica.size(); i++)
	{
		std::string rep = replica[i];
		char* p = strtok((char*)replica[i].c_str(), ")");
		std::string r(p);
		if (findSubstring(r, this->nume))
		{
			this->replici.push_back(rep);
		}
	}
}


Personaj::Personaj(std::string nume, int stareSpirit)
{
	this->nume = nume;
	this->stareSpirit = stareSpirit;
}

void Personaj::incrementAparitii()
{
	this->aparitii++;
}

std::string Personaj::getNumePersonaj()
{
	return this->nume;
}

