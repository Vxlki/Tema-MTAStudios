#define _CRT_SECURE_NO_WARNINGS
#include "Regizor.h"

void Regizor::asignareActori(const char* fname)
{
	std::ifstream fin(fname);

	std::string buff;
	
	int c = 0;
	while (getline(fin, buff))
	{
		char* p = strtok((char*)buff.c_str(), "-");
		p = strtok(NULL, "\n");
		this->scenariu->setNumeActori(buff, atoi(p), c);
		c++;
	}
}

void Regizor::setCadru()
{
	this->scenariu->setCadru();
}

void Regizor::asignareRepliciPtPersonaje()
{
	this->scenariu->setRepliciFiecarePersonaj();
}

void Regizor::setGradComp()
{
	this->scenariu->setGradComp();
}

//void Regizor::efecteProducator(Producator& producator)
//{
//	producator.generareEfecteSpeciale();
//}