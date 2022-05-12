#pragma once
#include "Globals.h"
#include "Vector.h"
#include "SpellBook.h"
void StartSpell();
enum class ObjectTypeFlags {
	GameObject = (1 << 0),  //0x1
	NeutralCamp = (1 << 1),  //0x2
	DeadObject = (1 << 4),  //0x10
	InvalidObject = (1 << 5),  //0x20
	AIBaseCommon = (1 << 7),  //0x80
	AttackableUnit = (1 << 9),  //0x200
	AI = (1 << 10), //0x400
	Minion = (1 << 11), //0x800
	Hero = (1 << 12), //0x1000
	Turret = (1 << 13), //0x2000
	Unknown0 = (1 << 14), //0x4000
	Missile = (1 << 15), //0x8000
	Unknown1 = (1 << 16), //0x10000
	Building = (1 << 17), //0x20000
	Unknown2 = (1 << 18), //0x40000
};

class CObject {
public:

	SpellBook spellbook;
	DWORD *me;
	char* name;
	int32_t* team;
	
	bool IsTurret();
	bool IsMinion();
	bool IsAlive();
	bool IsHero();
	bool IsMissile();
	bool IsNexus();

	bool IsInhibitor();
	bool IsTroyEnt();

	bool IsTargetable();
	

	void StartSpell()
	{
		
		
		
		spellbook.SpellBook = (DWORD*)((int)me +Offsets::SpellBook);
		

		 spellbook.slot.SpellSlotStart = (DWORD*)(*spellbook.SpellBook + Offsets::SpellSlotStart);

		 for (int i = 0; i < 6; i++)
		 {

			 DWORD* transfer = (DWORD*)*(spellbook.slot.SpellSlotStart + i);
			 spellbook.slot.Habilidades[i].habistart = (DWORD*)transfer;


			 spellbook.slot.Habilidades[i].level = (int32_t*)((int)spellbook.slot.Habilidades[i].habistart + Offsets::SpellLevel);
			 spellbook.slot.Habilidades[i].spellReadyTime = (float*)((int)spellbook.slot.Habilidades[i].habistart + Offsets::SpellReadyTime);
			 spellbook.slot.Habilidades[i].spellCharges = (int32_t*)((int)spellbook.slot.Habilidades[i].habistart + Offsets::SpellCharges);
			 spellbook.slot.Habilidades[i].spellRechargeTime = (float*)((int)spellbook.slot.Habilidades[i].habistart + Offsets::SpellRechargeTime);
			 spellbook.slot.Habilidades[i].spellTrueDmg = (float*)((int)spellbook.slot.Habilidades[i].habistart + Offsets::SpellTrueDamage);


			 transfer = (DWORD*)((int)spellbook.slot.Habilidades[i].habistart + Offsets::SpellInfo);

			 spellbook.slot.Habilidades[i].info.startaddr = (DWORD *) * transfer;

			 transfer = (DWORD*)((int)spellbook.slot.Habilidades[i].info.startaddr + Offsets::SpellInfoData);

			 spellbook.slot.Habilidades[i].info.data.startaddr = (DWORD*)*transfer;
			 DWORD* nameAux = (DWORD*)((int)spellbook.slot.Habilidades[i].info.data.startaddr + Offsets::Name);

			 spellbook.slot.Habilidades[i].info.data.name = (char*)*nameAux;

			 spellbook.slot.Habilidades[i].info.data.startCD = (float *)((int)spellbook.slot.Habilidades[i].info.data.startaddr + Offsets::SpellCooldown);
			 spellbook.slot.Habilidades[i].info.data.manaCost = (float*)((int)spellbook.slot.Habilidades[i].info.data.startaddr + Offsets::SpellManaCost);
			 spellbook.slot.Habilidades[i].info.data.name = (char*)*nameAux;
			 //console.Print("%s\n", spellbook.slot.Habilidades[i].info.data.name);
			//console.Print("Level: %i    ReadyTime: %.2f    SpellCharges: %i    SpellRechargeTime: %.2f \n", *spellbook.slot.Habilidades[i].level, *spellbook.slot.Habilidades[i].spellReadyTime, *spellbook.slot.Habilidades[i].spellCharges, *spellbook.slot.Habilidades[i].spellRechargeTime);

		 }
		
		
		
	}
	short GetIndex() {
		return *(short*)(me + Offsets::Index);
	}
	void GetAll()
	{
		team = (int32_t*)((int)me + Offsets::Team);
		DWORD* nameAux = (DWORD*)((int)me + Offsets::Name);
		
		
		name = (char *)nameAux;
	}
	DWORD GetNetworkID() {
		return *(DWORD*)(me + Offsets::NetworkId);
	}

	Vector GetPos() {
		return *(Vector*)(me + Offsets::Position);
	}

	int GetLevel() {
		return *(int*)(me + Offsets::Level);
	}

	float GetHealth() {
		return *(float*)(me + Offsets::Health);
	}

	float GetBaseAttackDamage() {
		return *(float*)(me + Offsets::AttackDamage);
	}


	float GetBonusAttackDamage() {
		return *(float*)((DWORD)this + Offsets::BonusAttackDamage);
	}

	float GetTotalAttackDamage() {
		return this->GetBonusAttackDamage() + this->GetBaseAttackDamage();
	}

	float GetArmor() {
		return *(float*)((DWORD)this + Offsets::TotalArmor);
	}

	float GetMaxHealth() {
		return *(float*)((DWORD)this + Offsets::MaxHealth);
	}

	float GetAttackRange() {
		return *(float*)((DWORD)this + Offsets::AttackRange);
	}

	bool IsVisible() {
		return *(bool*)((DWORD)this + Offsets::Visible);
	}








	float GetAttackDelay();

	float GetAttackCastDelay();
	float GetDistance(CObject* target, CObject* target2);
};

