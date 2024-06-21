#pragma once
#include<iostream>
#include"Scenarist.h"
#include"Regizor.h"
#include"Producator.h"
#include"Director.h"

class MTAStudios
{
protected:
	static MTAStudios* instance;
	MTAStudios();
	MTAStudios(const MTAStudios& obj);
	~MTAStudios();
public:
	Angajati* MTAProducator, * MTARegizor, * MTAScenarist, * MTADirector;
	static MTAStudios& getInstance();
	void destroyInstance();
};