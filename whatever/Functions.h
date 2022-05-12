#pragma once
#ifndef FunctionsGame_HEADER
#define FunctionsGame_HEADER


#include "Globals.h"
#include "ClCObject.h"


class FunctionsGame
{
public:
	int GetPing() {
		Typedefs::orgGetPing GetPingu;
		GetPingu = (Typedefs::orgGetPing)(baseAddress + (DWORD)Offsets::GetPing);
		return GetPingu((int*)(baseAddress + Offsets::GameClient));
	}

	bool IsAlive(CObject* obj) {
		Typedefs::orgIsALive isAlive;
		isAlive = (Typedefs::orgIsALive)(baseAddress + (DWORD)Offsets::IsAlive);
		// return isAlive((int*)(baseAddress + Offsets::));
	}
	bool IsMinion(CObject* obj)
	{

	}

	bool IsTurret(CObject* obj)
	{

	}
	bool IsHero(CObject* obj)
	{

	}
	bool IsMissile(CObject* obj)
	{

	}
	bool IsTargetable(CObject* obj)
	{

	}
	bool IsNexus(CObject* obj)
	{

	}
	bool IsInhibitor(CObject* obj)
	{

	}
	bool IsTroyEnt(CObject* obj)
	{

	}
}; 

#endif