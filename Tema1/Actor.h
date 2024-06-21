#pragma once
#include"Personaj.h"

class Actor
{
protected:
	std::string numeActor;
	Personaj* rolActor;
public:
	Actor(std::string numeActor, int stareSpirit, std::string numePersonaj);
	void incrementAparitii();
	std::string getNumePersonaj();
	void setTip();
	void setNumeActor(std::string nume);
	void setStareSpirit(int stare);
	void setRepliciACTOR(std::vector <std::string> s);
	float returnStareSpirit();
};