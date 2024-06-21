#include "Actor.h"

Actor::Actor(std::string numeActor, int stareSpirit, std::string numePersonaj)
{
	Personaj* p = new Personaj(numePersonaj, stareSpirit);

	this->numeActor = numeActor;
	this->rolActor = p;
}

void Actor::incrementAparitii()
{
	this->rolActor->incrementAparitii();
}

std::string Actor::getNumePersonaj()
{
	return this->rolActor->getNumePersonaj();
}

void Actor::setTip()
{
	this->rolActor->setTip();
}

void Actor::setNumeActor(std::string nume)
{
	this->numeActor = nume;
}

void Actor::setStareSpirit(int stare)
{
	this->rolActor->setStareSpirit(stare);
}

void Actor::setRepliciACTOR(std::vector<std::string> s)
{
	this->rolActor->adaugareReplica(s);
}

float Actor::returnStareSpirit()
{
	return this->rolActor->getStareSpirit();
}
