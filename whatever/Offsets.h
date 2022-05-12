namespace Offsets
{
	enum Functions : DWORD
	{
		SendChat = 0x5F30D0,
		PrintChat = 0x5BF020,
		NewCastSpell = 0x5E1640,
		NewIssueOrder = 0x5F94D0,
		WorldToScreen = 0xA432B0,
		GetAttackDelay = 0x277C60,
		GetAttackCastDelay = 0x277B60,
		OnProcessSpell = 0x4FE790,
		OnCreateObject = 0x280260,
		OnDeleteObject = 0x278BC0,
		OnNewPath = 0x280540,
		GetBasicAttack = 0x139F70,
		IsTargetable = 0x1B6B20,
		IsAlive = 0x1616C0,
		IsMissile = 0x16D7D0,
		IsMinion = 0x16D7B0,
		IsTurret = 0x16D960,
		IsHero = 0x16D750,
		IsInhibitor = 0x16D5D0,
		IsNexus = 0x16D6D0,
		GetPing = 0x343DC0, // posible wrong
	};

	enum Game : DWORD
	{
		GameTime = 0x30F0D14,
		GameVersion = 0x310CDC8,
		HudInstance = 0x1859C54,
		ChatInstance = 0x24A83B0,
		UnderMouseObject = 0x24A838C,
		LocalPlayer = 0x30F9BDC,
		GameClient = 0x24A8234,
	};

	enum Managers : DWORD
	{
		Heroes = 0x1859C30,
		Minions = 0x24A8220,
		Inhibitors = 0x30F9D28,
		Turrets = 0x30EE418,
		Missiles = 0x30F9C38,
		AttackableUnits = 0x24A81C4,
		Shops = 0x30EE420,
		Buildings = 0x1859378,
	};

	enum GameObject : DWORD
	{
		Index = 0x20,
		NetworkId = 0xCC,
		Visible = 0x28C,
		VisibleOnScreen = 0x1A8,
		Team = 0x4C,
		Name = 0x6C,
		Position = 0x1F4,
		Direction = 0x1BD8,
		MaxHealth = 0xDC4,
		Health = 0xDB4,
		MaxMana = 0x2B4,
		Mana = 0x2C4,
		CombatType = 0x20B0,
		AttackDamage = 0x1284,
		BonusAttackDamage = 0x11FC,
		AbilityPower = 0x1750,
		AbilityPowerMultiplier = 0x1760,
		AbilityHaste = 0x16A0,
		Lifesteal = 0x1268,
		Omnivamp = 0x1274,
		AttackRange = 0x12CC,
		Tenacity = 0x1158,
		Crit = 0x12A8,
		CritDamage = 0x1298,
		TotalArmor = 0x12AC,
		BonusArmor = 0x12B0,
		TotalMagicResist = 0x12B4,
		BonusMagicResist = 0x12B8,
		BonusAttackSpeed = 0x1280,
		Movespeed = 0x12C4,
		HealthReg = 0x12C0,
		ManaReg = 0x1118,
		FlatMagicPen = 0x11A4,
		PercentMagicPen = 0x11AC,
		FlatArmorPen = 0x11C0,
		PercentArmorPen = 0x11A8,
		InternalName = 0x2D98,
		Level = 0x338C,
		Experience = 0x337C,
		Gold = 0x1B60,
		TotalGold = 0x1B70,
		RecallType = 0xDA8,
		RecallName = 0xD98,
		InvulnerableType = 0x3EC,
		AllShield = 0xDF4,
		PhysicalShield = 0xE04,
		MagicalShield = 0xE14,
		SpellBook = 0x27AC,
		BuffManager = 0x2180,
		Inventory = 0x33D0,
		Perks = 0x3654
	};

	enum SpellBook : DWORD
	{
		SpellSlotStart = 0x488, // dentro de hero
		SpellLevel = 0x1C, // dentro de spellslotstart
		SpellReadyTime = 0x24,
		SpellCharges = 0x54,
		SpellRechargeTime = 0x74,
		SpellTrueDamage = 0x94,
		SpellInfo = 0x120,
		SpellInfoData = 0x44, // dentro de spellinfo
		SpellName = 0x6C, // dentro de spellinfodata
		SpellCooldown = 0x288,
		SpellManaCost = 0x52C,
	};

	enum BuffManager : DWORD
	{
		BuffsStart = 0x10,
		BuffsEnd = 0x14,
		Count = 0x74,
		CountAlt = 0x24,
		BuffType = 0x4,
		BuffStartTime = 0xC,
		BuffEndTime = 0x10,
		BuffNamePtr = 0x8,
		BuffName = 0x4,
	};

	enum Inventory : DWORD
	{
		InventoryItemSlotStart = 0x8,
		InventoryItemSlot = 0xC,
		InventoryItemSlotSpellName = 0x10,
		InventoryItemSlotInfo = 0x20,
		InventoryItemSlotStacks = 0x24,
		InventoryItemSlotPrice = 0x28,
		InventoryItemSlotInfoId = 0x68,
		InventoryItemSlotInfoPercentCritChanceMod = 0x160,
	};

	enum GameClient : DWORD
	{
		GameState = 0x8
	};
}