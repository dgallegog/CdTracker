#include "Globals.h"
class SpellBook
{
public:
	int32_t* pos;//0x0000
	char pad_0000[1156]; 
	class SpellSlotStartCL* SpellSlotStart; //0x0488
	class SpellSlotStartCL* SpellSlotStart; //0x048C
	class SpellSlotStartCL* SpellSlotStart; //0x0490
	class SpellSlotStartCL* SpellSlotStart; //0x0494
	class SpellSlotStartCL* SpellSlotStart; //0x0498
	class SpellSlotStartCL* SpellSlotStart; //0x049C
	class SpellSlotStartCL* SpellSlotStart; //0x04A0
	char pad_04A4[2976]; //0x04A4
}; //Size: 0x1044


class SpellSlotStartCL
{
public:

	char pad_0000[28]; //0x0000
	int32_t SpellLevel; //0x001C
	char pad_0020[4]; //0x0020
	float SpellReadyTime; //0x0024
	char pad_0028[44]; //0x0028
	int32_t SpellCharges; //0x0054
	char pad_0058[28]; //0x0058
	float SpellRechargeTime; //0x0074
	char pad_0078[28]; //0x0078
	int32_t SpellTrueDmg; //0x0094
	char pad_0098[136]; //0x0098
	class SpellInfoc* SpellInfo; //0x0120
}; //Size: 0x0124


class SpellInfoc
{
public:
	char pad_0000[68]; //0x0000
	class SpellInfodatacl* SpellInfoData; //0x0044
}; //Size: 0x0048


class SpellInfodatacl
{
public:
	char pad_0000[648]; //0x0000
	float SpellCD; //0x0288
	char pad_028C[672]; //0x028C
	float ManaCost; //0x052C
	char pad_0530[20]; //0x0530
}; //Size: 0x0544

