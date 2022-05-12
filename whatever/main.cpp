
#pragma once
#include "Globals.h"
#include <iostream>
#include <TlHelp32.h>
#include "Functions.h"
#include "ClCObject.h"
#include "DebugConsole.h"

DebugConsole console;
float* gameTime;
DWORD baseAddress;
CObject player[10];

Typedefs::tPrintChat fnPrintChat;

class TemplateManager
{
public:

	DWORD* VTable;
	DWORD* Map;
	UINT Size;
};








static void PrintChat(const char* Message) {
	
	 fnPrintChat = (Typedefs::tPrintChat)(baseAddress + Offsets::PrintChat);
	  int i = fnPrintChat(*(DWORD*)(baseAddress + Offsets::ChatInstance), Message, 0);
	 
	
}


void ReadChampions()
{

	DWORD* Objmanager = (DWORD*)(baseAddress + Offsets::Heroes);
	
	
	Objmanager = (DWORD*)*Objmanager + 0x1;
	Objmanager = (DWORD*)*Objmanager;
	
	
	

	
		
	
	for (int i = 0; i < 10; i++)
	{

		int* obj = (int*)Objmanager + i ;
		player[i].me = (DWORD*) * obj;
		player[i].GetAll();
		//console.Print("%s\n", player[i].name);
		player[i].StartSpell();
		
		//console.Print("----------------------------\n");
		
		
		
		
	}
	
	
}
Vector getpos(DWORD* localplayer)
{
	
	
	float* posxPtr = (float*)(*localplayer + Offsets::Position);

	Vector u;
	
	u.X = *posxPtr;
	u.Y = *posxPtr+4;
	u.Z = *posxPtr+8;
	
	char array[300];
	sprintf(array, "<font color='#b00095'>[CdTracker]:</font><font color='#C1FFAF'>tiempo: %0.2f tu pos es: x: %f y: %f z: %f </font>", *gameTime,u.X,u.Y,u.Z);

			
	PrintChat(array);
	return u;
	
	 
}

void cdTracker()
{
	char array[300];
	


	for (int i = 0; i < 10; i++)
	{
		for (int u = 0; u < 6; u++)
		{
			
			if (*player[i].team != 100)
			{
				
				if (*player[i].spellbook.slot.Habilidades[u].spellReadyTime > *gameTime)
				{
					sprintf(array, "<font color='#b00095'>[CdTracker]:</font><font color='#C1FFAF'>El jugador: %s tendra su: %s en: %0.2f s  </font>", player[i].name, player[i].spellbook.slot.Habilidades[u].info.data.name, *player[i].spellbook.slot.Habilidades[u].spellReadyTime - *gameTime);
					PrintChat(array);
				}
			}

		}
	
	}
}

DWORD WINAPI MainThread(LPVOID param)
{
	

	
	//console.Init("uwu", 200, 200, "owo");
	

	 baseAddress = DWORD(GetModuleHandle(NULL));
	//Set up
		 
	 gameTime = (float*)((int)baseAddress + Offsets::GameTime);
	 DWORD *localplayer = (DWORD* )(baseAddress+Offsets::LocalPlayer);
	 //DWORD *manaPtr = (DWORD*)localplayer + oObjMana;
	 //float mana = (float)*manaPtr;


	 
	PrintChat("<font color='#b00095'>[CdTracker]:</font><font color='#C1FFAF'> Loaded...</font>");

	ReadChampions();
	while (!GetAsyncKeyState(VK_END))
	{
		cdTracker();
		
		
		if (GetAsyncKeyState(VK_NUMPAD2) & 1)
		{
			exit(1);
			
		}
		if (GetAsyncKeyState(VK_NUMPAD3) & 1)
		{
			
		}
		
		Sleep(1000);
	}
	FreeLibraryAndExitThread((HMODULE)param, 0);
	
	return 0;
}

BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, MainThread, hModule, 0, 0);
		break;
	default:
		
		break;
	}
	return TRUE;
}