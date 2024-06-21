#pragma once
#include<iostream>
#include<vector>


typedef enum
{
	Principal, Figurant
} tip;

class Personaj
{
protected:
	std::string nume;
	int aparitii = 0;
	tip tipPersonaj;
	float stareSpirit;
	std::vector <std::string> replici;
public:
	Personaj(std::string nume, int stareSpirit);
	void incrementAparitii();
	std::string getNumePersonaj();
	void setTip();
	void setStareSpirit(float stare);
	void adaugareReplica(std::vector<std::string> replica);
	static int findSubstring(std::string& string, std::string substring);
	float getStareSpirit();
};