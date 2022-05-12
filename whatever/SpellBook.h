#pragma once
#include "Globals.h"

class SpellInfoData
{
public:
	DWORD* startaddr;
	char* name;
	float* startCD;
	float* manaCost;
};
class SpellInfo
{
public:
	DWORD* startaddr;
	SpellInfoData data;
};


class Spells
{
public:
	DWORD* habistart;
	int32_t* level;
	float* spellReadyTime;
	int32_t* spellCharges;
	float* spellRechargeTime;
	float* spellTrueDmg;
	SpellInfo info;

};
class SpellSlotStart
{
public:
	DWORD* SpellSlotStart;
	Spells Habilidades[6];
};

class SpellBook
{
public:
	DWORD *SpellBook;
	SpellSlotStart slot;
};






