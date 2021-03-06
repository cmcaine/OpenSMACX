/*
 * OpenSMACX - an open source clone of Sid Meier's Alpha Centauri.
 * Copyright (C) 2013-2020 Brendan Casey
 *
 * OpenSMACX is free software: you can redistribute it and / or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenSMACX is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenSMACX. If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

 /*
  * Vehicle/unit related objects, variables and functions.
  */
enum veh_morale {
	MORALE_VERY_GREEN = 0,
	MORALE_GREEN = 1,
	MORALE_DISCIPLINED = 2,
	MORALE_HARDENED = 3,
	MORALE_VETERAN = 4,
	MORALE_COMMANDO = 5,
	MORALE_ELITE = 6,
};

enum veh_basic {
	BSC_COLONY_POD = 0,
	BSC_FORMERS = 1,
	BSC_SCOUT_PATROL = 2,
	BSC_TRANSPORT_FOIL = 3,
	BSC_SEA_FORMERS = 4,
	BSC_SUPPLY_CRAWLER = 5,
	BSC_PROBE_TEAM = 6,
	BSC_ALIEN_ARTIFACT = 7,
	BSC_MIND_WORMS = 8,
	BSC_ISLE_OF_THE_DEEP = 9,
	BSC_LOCUSTS_OF_CHIRON = 10,
	BSC_UNITY_ROVER = 11,
	BSC_UNITY_SCOUT_CHOPPER = 12,
	BSC_UNITY_FOIL = 13,
	BSC_SEALURK = 14,
	BSC_SPORE_LAUNCHER = 15,
	BSC_BATTLE_OGRE_MK1 = 16,
	BSC_BATTLE_OGRE_MK2 = 17,
	BSC_BATTLE_OGRE_MK3 = 18,
	BSC_FUNGAL_TOWER = 19,
	BSC_UNITY_MINING_LASER = 20,
	BSC_SEA_ESCAPE_POD = 21,
	BSC_UNITY_GUNSHIP = 22,
};

enum veh_triad {
	TRIAD_LAND = 0,
	TRIAD_SEA = 1,
	TRIAD_AIR = 2,
};

enum veh_abilities_bitfield {
	ABL_SUPER_TERRAFORMER = 0x1,
	ABL_DEEP_RADAR = 0x2,
	ABL_CLOAKED = 0x4,
	ABL_AMPHIBIOUS = 0x8,
	ABL_DROP_POD = 0x10,
	ABL_AIR_SUPERIORITY = 0x20,
	ABL_DEEP_PRESSURE_HULL = 0x40,
	ABL_CARRIER = 0x80,
	ABL_AAA = 0x100,
	ABL_COMM_JAMMER = 0x200,
	ABL_ANTIGRAV_STRUTS = 0x400,
	ABL_EMPATHIC = 0x800,
	ABL_POLY_ENCRYPTION = 0x1000,
	ABL_FUNGICIDAL = 0x2000,
	ABL_TRAINED = 0x4000,
	ABL_ARTILLERY = 0x8000,
	ABL_CLEAN_REACTOR = 0x10000,
	ABL_BLINK_DISPLACER = 0x20000,
	ABL_TRANCE = 0x40000,
	ABL_HEAVY_TRANSPORT = 0x80000,
	ABL_NERVE_GAS = 0x100000,
	ABL_REPAIR = 0x200000,
	ABL_POLICE_2X = 0x400000,
	ABL_SLOW = 0x800000,
	ABL_SOPORIFIC_GAS = 0x1000000,
	ABL_DISSOCIATIVE_WAVE = 0x2000000,
	ABL_MARINE_DETACHMENT = 0x4000000,
	ABL_FUEL_NANOCELLS = 0x8000000,
	ABL_ALGO_ENHANCEMENT = 0x10000000,
};

enum veh_ability_flag_bitfield {
	AFLAG_ALLOWED_LAND_UNIT = 0x1,
	AFLAG_ALLOWED_SEA_UNIT = 0x2,
	AFLAG_ALLOWED_AIR_UNIT = 0x4,
	AFLAG_ALLOWED_COMBAT_UNIT = 0x8,
	AFLAG_ALLOWED_TERRAFORM_UNIT = 0x10,
	AFLAG_ALLOWED_NONCOMBAT_UNIT = 0x20,
	AFLAG_NOT_ALLOWED_PROBE_TEAM = 0x40,
	AFLAG_NOT_ALLOWED_PSI_UNIT = 0x80,
	AFLAG_TRANSPORT_ONLY_UNIT = 0x100,
	AFLAG_NOT_ALLOWED_FAST_UNIT = 0x200,
	AFLAG_COST_INC_LAND_UNIT = 0x400,
	AFLAG_ONLY_PROBE_TEAM = 0x800,
};

enum veh_prototype_flag_bitfield {
	PROTO_ACTIVE = 0x1, // if this bit is zero, prototype has been retired
	PROTO_CUSTOM_NAME_SET = 0x2,
	PROTO_TYPED_COMPLETE = 0x4,
};

enum veh_orders {
	ORDER_NONE = 0,              //  -
	ORDER_SENTRY_BOARD = 1,      // (L)
	ORDER_HOLD = 2,              // (H); Hold (set 1st waypoint (-1, 0)), Hold 10 (-1, 10), On Alert
	ORDER_CONVOY = 3,            // (O)
	ORDER_FARM = 4,              // (f)
	ORDER_SOIL_ENRICHER = 5,     // (f)
	ORDER_MINE = 6,              // (M)
	ORDER_SOLAR_COLLECTOR = 7,   // (S)
	ORDER_PLANT_FOREST = 8,      // (F)
	ORDER_ROAD = 9,              // (R)
	ORDER_MAGTUBE = 10,          // (R)
	ORDER_BUNKER = 11,           // (K)
	ORDER_AIRBASE = 12,          // (.)
	ORDER_SENSOR_ARRAY = 13,     // (O)
	ORDER_REMOVE_FUNGUS = 14,    // (F)
	ORDER_PLANT_FUNGUS = 15,     // (F)
	ORDER_CONDENSER = 16,        // (N)
	ORDER_ECHELON_MIRROR = 17,   // (E)
	ORDER_THERMAL_BOREHOLE = 18, // (B)
	ORDER_DRILL_AQUIFIER = 19,   // (Q)
	ORDER_TERRAFORM_UP = 20,     // (])
	ORDER_TERRAFORM_DOWN = 21,   // ([)
	ORDER_TERRAFORM_LEVEL = 22,  // (_)
	ORDER_PLACE_MONOLITH = 23,   // (?)
	ORDER_MOVE_TO = 24,          // (G); Move unit to here, Go to Base, Group go to, Patrol
	ORDER_MOVE = 25,             // (>); Only used in a few places, seems to be buggy mechanic
	ORDER_EXPLORE = 26,          // (/); not set via shortcut, AI related?
	ORDER_ROAD_TO = 27,          // (r)
	ORDER_MAGTUBE_TO = 28,       // (t)
	// 29                        // max value for normal orders, seems to be unused
	ORDER_AI_GO_TO = 88,         //  - ; ORDER_GO_TO (0x18) | 0x40 > 0x58 ? only used by AI funcs
};

enum veh_orders_auto_type {
	ORDERA_TERRA_AUTO_FULL = 0,
	ORDERA_TERRA_AUTO_ROAD = 1,
	ORDERA_TERRA_AUTO_MAGTUBE = 2,
	ORDERA_TERRA_AUTOIMPROVE_BASE = 3,
	ORDERA_TERRA_FARM_SOLAR_ROAD = 4,
	ORDERA_TERRA_FARM_MINE_ROAD = 5, // displayed incorrectly as 'Mine+Solar+Road' (labels.txt:L411)
	ORDERA_TERRA_AUTO_FUNGUS_REM = 6,
	ORDERA_TERRA_AUTOMATIC_SENSOR = 7,
	// 8 unused?
	// 9 unused?
	ORDERA_BOMBING_RUN = 10, // air units only
	ORDERA_ON_ALERT = 11,
	ORDERA_AUTOMATE_AIR_DEFENSE = 12,
};

enum veh_flags_bitfield {
	VFLAG_PROBE_PACT_OPERATIONS = 0x4,
	VFLAG_IS_OBJECTIVE = 0x20,
	VFLAG_LURKER = 0x40,
	VFLAG_START_RAND_LOCATION = 0x80,
	VFLAG_START_RAND_MONOLITH = 0x100,
	VFLAG_START_RAND_FUNGUS = 0x200,
	VFLAG_INVISIBLE = 0x400,
};

enum veh_state_bitfield {
	VSTATE_UNK_1 = 0x1,
	VSTATE_UNK_2 = 0x2,
	VSTATE_UNK_4 = 0x4,
	VSTATE_UNK_8 = 0x8,
	VSTATE_REQUIRES_SUPPORT = 0x10,
	VSTATE_MADE_AIRDROP = 0x20,
	VSTATE_UNK_40 = 0x40,
	VSTATE_DESIGNATE_DEFENDER = 0x80,
	VSTATE_MONOLITH_UPGRADED = 0x100,
	VSTATE_UNK_200 = 0x200,
	VSTATE_UNK_400 = 0x400,
	VSTATE_UNK_800 = 0x800,
	VSTATE_UNK_1000 = 0x1000,
	VSTATE_UNK_2000 = 0x2000,
	VSTATE_EXPLORE = 0x4000,
	VSTATE_UNK_8000 = 0x8000,
	VSTATE_UNK_10000 = 0x10000,
	VSTATE_UNK_20000 = 0x20000,
	VSTATE_UNK_40000 = 0x40000,
	VSTATE_USED_NERVE_GAS = 0x80000, // set/reset on attacking Veh after each attack
	VSTATE_UNK_100000 = 0x100000,
	VSTATE_PACIFISM_DRONE = 0x200000,
	VSTATE_PACIFISM_FREE_SKIP = 0x400000,
	VSTATE_ASSISTANT_WORM = 0x800000, // Int: Brood Trainer; Human player's 1st spawned Mind Worm
	VSTATE_UNK_1000000 = 0x1000000,
	VSTATE_UNK_2000000 = 0x2000000,
	VSTATE_CRAWLING = 0x4000000, // more than just crawling, terraforming also?
	VSTATE_UNK_8000000 = 0x8000000,
	VSTATE_UNK_10000000 = 0x10000000,
	VSTATE_UNK_20000000 = 0x20000000,
	VSTATE_UNK_40000000 = 0x40000000,
	VSTATE_UNK_80000000 = 0x80000000,
};

enum veh_weapon_mode {
	WPN_MODE_PROJECTILE = 0,
	WPN_MODE_ENERGY = 1,
	WPN_MODE_MISSILE = 2,
	WPN_MODE_TRANSPORT = 7,
	WPN_MODE_COLONIST = 8,
	WPN_MODE_TERRAFORMER = 9,
	WPN_MODE_CONVOY = 10,
	WPN_MODE_INFOWAR = 11,
	WPN_MODE_ARTIFACT = 12,
};

enum veh_plan {
	PLAN_OFFENSIVE = 0,
	PLAN_COMBAT = 1,
	PLAN_DEFENSIVE = 2,
	PLAN_RECONNAISANCE = 3,
	PLAN_AIR_SUPERIORITY = 4,
	PLAN_PLANET_BUSTER = 5,
	PLAN_NAVAL_SUPERIORITY = 6,
	PLAN_NAVAL_TRANSPORT = 7,
	PLAN_COLONIZATION = 8,
	PLAN_TERRAFORMING = 9,
	PLAN_SUPPLY_CONVOY = 10,
	PLAN_INFO_WARFARE = 11,
	PLAN_ALIEN_ARTIFACT = 12,
	PLAN_TECTONIC_MISSILE = 13,
	PLAN_FUNGAL_MISSILE = 14,
};

enum veh_weapon {
	WPN_HAND_WEAPONS = 0,
	WPN_LASER = 1,
	WPN_PARTICLE_IMPACTOR = 2,
	WPN_GATLING_LASER = 3,
	WPN_MISSILE_LAUNCHER = 4,
	WPN_CHAOS_GUN = 5,
	WPN_FUSION_LASER = 6,
	WPN_TACHYON_BOLT = 7,
	WPN_PLASMA_SHARD = 8,
	WPN_QUANTUM_LASER = 9,
	WPN_GRAVITON_GUN = 10,
	WPN_SINGULARITY_LASER = 11,
	WPN_RESONANCE_LASER = 12,
	WPN_RESONANCE_BOLT = 13,
	WPN_STRING_DISRUPTOR = 14,
	WPN_PSI_ATTACK = 15,
	WPN_PLANET_BUSTER = 16,
	WPN_COLONY_MODULE = 17,
	WPN_TERRAFORMING_UNIT = 18,
	WPN_TROOP_TRANSPORT = 19,
	WPN_SUPPLY_TRANSPORT = 20,
	WPN_PROBE_TEAM = 21,
	WPN_ALIEN_ARTIFACT = 22,
	WPN_CONVENTIONAL_PAYLOAD = 23,
	WPN_TECTONIC_PAYLOAD = 24,
	WPN_FUNGAL_PAYLOAD = 25,
};

enum veh_armor {
	ARM_NO_ARMOR = 0,
	ARM_SYNTHMETAL_ARMOR = 1,
	ARM_PLASMA_STEEL_ARMOR = 2,
	ARM_SILKSTEEL_ARMOR = 3,
	ARM_PHOTON_WALL = 4,
	ARM_PROBABILITY_SHEATH = 5,
	ARM_NEUTRONIUM_ARMOR = 6,
	ARM_ANTIMATTER_PLATE = 7,
	ARM_STASIS_GENERATOR = 8,
	ARM_PSI_DEFENSE = 9,
	ARM_PULSE_3_ARMOR = 10,
	ARM_RESONANCE_3_ARMOR = 11,
	ARM_PULSE_8_ARMOR = 12,
	ARM_RESONANCE_8_ARMOR = 13,
};

enum veh_chassis {
	CHSI_INFANTRY = 0,
	CHSI_SPEEDER = 1,
	CHSI_HOVERTANK = 2,
	CHSI_FOIL = 3,
	CHSI_CRUISER = 4,
	CHSI_NEEDLEJET = 5,
	CHSI_COPTER = 6,
	CHSI_GRAVSHIP = 7,
	CHSI_MISSILE = 8,
};

enum veh_reactor {
	RECT_FISSION = 1,
	RECT_FUSION = 2,
	RECT_QUANTUM = 3,
	RECT_SINGULARITY = 4,
};

struct rules_chassis {
	LPSTR offsv1Name;
	LPSTR offsv2Name;
	LPSTR offsvNameLrg;
	LPSTR defsv1Name;
	LPSTR defsv2Name;
	LPSTR defsvNameLrg;
	int offsv1Gender;
	int offsv2Gender;
	int offsvGenderLrg;
	int defsv1Gender;
	int defsv2Gender;
	int defsvGenderLrg;
	BOOL offsv1IsPlural;
	BOOL offsv2IsPlural;
	BOOL offsvIsPluralLrg;
	BOOL defsv1IsPlural;
	BOOL defsv2IsPlural;
	BOOL defsvIsPluralLrg;
	uint8_t speed;
	uint8_t triad;
	uint8_t range;
	uint8_t cargo;
	uint8_t cost; // TODO: expand to uint32_t in future
	uint8_t missile; // treated as boolean
	uint8_t spriteFlagXOff[8];
	uint8_t spriteFlagYOff[8];
	uint8_t spriteUnk1XOff[8];
	uint8_t spriteUnk1YOff[8];
	uint8_t spriteUnk2XOff[8];
	uint8_t spriteUnk2YOff[8];
	uint8_t spriteUnk3XOff[8];
	uint8_t spriteUnk3YOff[8];
	int16_t preqTech;
};

struct rules_weapon {
	LPSTR name;
	LPSTR nameShort;
	int8_t offenseRating;
	int8_t icon;
	uint8_t mode;
	uint8_t cost;
	int16_t preqTech;
	int16_t padding;
};

struct rules_armor {
	LPSTR name;
	LPSTR nameShort;
	int8_t defenseRating;
	uint8_t mode;
	uint8_t cost;
	uint8_t padding1;
	int16_t preqTech;
	int16_t padding2;
};

struct veh {
	int16_t xCoord;
	int16_t yCoord;
	uint32_t state; // see veh_state_bitfield
	uint16_t flags; // see veh_flags_bitfield
	int16_t protoID;
	uint16_t unk_1; // seems to only be set by veh_clear()
	uint8_t factionID;
	uint8_t yearEndLurking;
	uint8_t dmgIncurred; // damaged taken
	int8_t orders; // see veh_orders
	uint8_t waypointCount;
	uint8_t patrolCurrentPoint;
	int16_t waypoint_xCoord[4]; // ...xCoord[0] duals as transport vehID if veh is sentry/board
	int16_t waypoint_yCoord[4];
	uint8_t morale;
	uint8_t terraformingTurns;
	uint8_t orderAutoType; // see veh_orders_auto_type
	uint8_t visibility; // faction bitfield of who can currently see Veh excluding owner
	uint8_t movesExpended; // stored as road moves (x3)
	int8_t unk_5; // related to movement
	uint8_t unk_6; // automated action iterator count
	uint8_t moveToAIType; // shown as status icon with debug mode active
	// 000 00 000 : framed faction : secondary options : primary action id (0-7)
	// secondary options: THOUGHTMENU, ADVVIRUS, DECIPHER, SUBVERTMENU
	// 000 0 0000 : framed faction : n/a : probe action id (8) ; Freeing Captured Leaders only
	uint8_t probeAction; // see above and probe_primary_action, last action taken by probe team
	uint8_t probeSabotageID; // for targeted sabotage: production: 0, abort: 99, or facilityID
	int16_t homeBaseID;
	int16_t nextVehIDStack;
	int16_t prevVehIDStack;
};

struct veh_prototype {
	char vehName[32];
	uint32_t abilityFlags;
	uint8_t chassisID;
	uint8_t weaponID;
	uint8_t armorID;
	uint8_t reactorID;
	uint8_t carryCapacity;
	uint8_t cost;
	uint8_t plan;
	int8_t unk_1; // some kind of internal prototype category?
	uint8_t obsoleteFactions; // faction bitfield of those who marked this prototype obsolete
	int8_t combatFactions; // faction bitfield for those that have seen protoID in combat (atk/def)
	int8_t iconOffset;
	int8_t padding; // unused
	uint16_t flags; // see veh_prototype_flag_bitfield
	int16_t preqTech; // only set for predefined alpha/x.txt units
};

struct rules_reactor {
	LPSTR name;
	LPSTR nameShort;
	int16_t preqTech;
	uint16_t power; // Bug fix: this value isn't originally set
};

struct rules_ability {
	LPSTR name;
	LPSTR description;
	LPSTR abbreviation;
	int costFactor;
	int unk_1; // only referenced in NetDaemon::synch
	uint32_t flags;
	int16_t preqTech;
	uint16_t padding;
};

struct rules_morale {
	LPSTR name;
	LPSTR nameLifecycle;
};

struct rules_combat_mode {
	LPSTR name;
	LPSTR hyphened;
	LPSTR abbrev;
	LPSTR letter;
};

struct rules_order {
	LPSTR order;
	LPSTR orderSea;
	LPSTR letter;
};

constexpr int MaxChassisNum = 9;
constexpr int MaxWeaponNum = 26;
constexpr int MaxArmorNum = 14;
constexpr int MaxVehProtoNum = 512;
constexpr int MaxVehProtoFactionNum = 64; // Limit per faction + max predefined from alpha/x.txt
constexpr int MaxReactorNum = 4;
constexpr int MaxAbilityNum = 29;
constexpr int MaxMoraleNum = 7;
constexpr int MaxDefenseModeNum = 3;
constexpr int MaxOffenseModeNum = 3;
constexpr int MaxOrderNum = 30;
constexpr int MaxPlanNum = 15;
constexpr int MaxTriadNum = 3;

extern veh_prototype *VehPrototype;
extern veh *Veh;
extern rules_chassis *Chassis;
extern rules_weapon *Weapon;
extern rules_armor *Armor;
extern rules_reactor *Reactor;
extern rules_ability *Ability;
extern rules_morale *Morale;
extern rules_combat_mode *DefenseModes;
extern rules_combat_mode *OffenseModes;
extern rules_order *Order;
extern LPSTR *PlansShortName;
extern LPSTR *PlansFullName;
extern LPSTR *Triad;

extern int *VehCurrentCount;
extern int *VehDropLiftVehID;
extern int *VehLift_xCoord;
extern int *VehLift_yCoord;
extern BOOL *VehBitError;
extern uint32_t *VehBasicBattleMorale;
extern int VehMoraleModifierCount;
// Battle related globals
extern uint32_t *VehBattleModCount;
extern BOOL *VehBattleTglUnk;
extern int *VehBattleModifier;
extern LPSTR *VehBattleDisplay;
extern LPSTR VehBattleDisplayTerrain;

OPENSMACX_API void __cdecl say_morale(LPSTR moraleOutput, uint32_t vehID, int factionIDvsNative);
OPENSMACX_API void __cdecl say_morale(uint32_t vehID, int factionIDvsNative);
OPENSMACX_API uint32_t __cdecl drop_range(int factionID);
OPENSMACX_API uint32_t __cdecl planet_buster2(int protoID);
OPENSMACX_API uint32_t __cdecl planet_buster(int vehID);
OPENSMACX_API uint32_t __cdecl defense_value(uint32_t factionID, uint32_t xCoord, uint32_t yCoord,
	uint32_t vehIDDef, int vehIDAtk);
OPENSMACX_API uint32_t __cdecl morale_alien(int vehID, int factionIDvsNative);
OPENSMACX_API int __cdecl psi_factor(int combatRatio, int factionID, BOOL isAttack,
	BOOL isFungalTower);
OPENSMACX_API int __cdecl get_basic_offense(uint32_t vehIDAtk, int vehIDDef, uint32_t psiCombatType,
	BOOL isBombardment, BOOL isUnkTgl);
OPENSMACX_API int __cdecl get_basic_defense(uint32_t vehIDDef, int vehIDAtk, uint32_t psiCombatType,
	BOOL isBombardment);
OPENSMACX_API void __cdecl battle_init();
OPENSMACX_API void __cdecl add_bat(uint32_t type, int modifier, LPCSTR displayStr);
OPENSMACX_API void __cdecl battle_compute(int vehIDAtk, int vehIDDef, int *offenseOutput,
	int *defenseOutput, int combatType);
OPENSMACX_API uint32_t __cdecl best_defender(uint32_t vehIDDef, int vehIDAtk, BOOL checkArtillery);
OPENSMACX_API void __cdecl invasions(uint32_t baseID);
OPENSMACX_API void __cdecl go_to(int vehID, char type, int xCoord, int yCoord);
OPENSMACX_API int __cdecl veh_top(int vehID);
OPENSMACX_API uint32_t __cdecl veh_moves(uint32_t vehID);
OPENSMACX_API uint32_t __cdecl proto_power(uint32_t vehID);
OPENSMACX_API BOOL __cdecl want_monolith(uint32_t vehID);
OPENSMACX_API int __cdecl arm_strat(int armorID, int factionID);
OPENSMACX_API int __cdecl weap_strat(int weaponID, int factionID);
OPENSMACX_API int __cdecl weap_val(int protoID, int factionID);
OPENSMACX_API int __cdecl arm_val(int armorID, int factionID);
OPENSMACX_API int __cdecl armor_val(int protoID, int factionID);
OPENSMACX_API uint32_t __cdecl transport_val(uint32_t chassisID, int ability, uint32_t reactorID);
OPENSMACX_API std::string __cdecl say_offense(int protoID);
OPENSMACX_API std::string __cdecl say_defense(int protoID);
OPENSMACX_API void __cdecl say_stats_3(LPSTR stat, int protoID);
OPENSMACX_API void __cdecl say_stats_3(int protoID);
OPENSMACX_API void __cdecl say_stats_2(LPSTR stat, int protoID);
OPENSMACX_API void __cdecl say_stats(LPSTR stat, int protoID, LPSTR customSpacer);
OPENSMACX_API uint32_t __cdecl best_reactor(int factionID);
OPENSMACX_API int __cdecl pick_chassis(int factionID, int triadChk, int speedChk);
OPENSMACX_API int __cdecl weapon_budget(int factionID, int condition, BOOL checkMode);
OPENSMACX_API int __cdecl armor_budget(int factionID, int maxCost);
OPENSMACX_API int __cdecl abil_index(int abilityID);
OPENSMACX_API int __cdecl hex_cost(int protoID, int factionID, int xCoordSrc, int yCoordSrc,
	int xCoordDst, int yCoordDst, BOOL toggle);
OPENSMACX_API void __cdecl veh_put(int vehID, int xCoord, int yCoord);
OPENSMACX_API uint32_t __cdecl veh_health(int vehID);
OPENSMACX_API uint32_t __cdecl proto_cost(uint32_t chassisID, uint32_t weaponID, uint32_t armorID,
	uint32_t ability, uint32_t reactorID);
OPENSMACX_API uint32_t __cdecl base_cost(uint32_t protoID);
OPENSMACX_API void __cdecl make_proto(int protoID, uint32_t chassisID, uint32_t weaponID,
	uint32_t armorID, uint32_t ability, uint32_t reactorID);
OPENSMACX_API int __cdecl get_plan(uint32_t factionID, uint32_t plan);
OPENSMACX_API BOOL __cdecl want_to_wake(uint32_t factionID, uint32_t vehID, int spottedVehID);
OPENSMACX_API void __cdecl wake_stack(int vehID);
OPENSMACX_API void __cdecl stack_put(int vehID, int xCoord, int yCoord);
OPENSMACX_API void __cdecl stack_sort(int vehID);
OPENSMACX_API void __cdecl stack_sort_2(int vehID);
OPENSMACX_API int __cdecl stack_fix(int vehID);
OPENSMACX_API int __cdecl stack_check(int vehID, uint32_t type, int cond1, int cond2, int cond3);
OPENSMACX_API BOOL __cdecl veh_avail(int protoID, int factionID, int baseID);
OPENSMACX_API BOOL __cdecl wants_prototype(uint32_t protoID, uint32_t factionID);
OPENSMACX_API int __cdecl veh_at(int xCoord, int yCoord);
OPENSMACX_API BOOL __cdecl has_abil(int protoID, int abilityID);
OPENSMACX_API int __cdecl veh_lift(int vehID);
OPENSMACX_API int __cdecl veh_drop(int vehID, int xCoord, int yCoord);
OPENSMACX_API void __cdecl sleep(uint32_t vehID);
OPENSMACX_API void __cdecl veh_demote(int vehID);
OPENSMACX_API void __cdecl veh_promote(int vehID);
OPENSMACX_API void __cdecl veh_clear(uint32_t vehID, int protoID, uint32_t factionID);
OPENSMACX_API BOOL __cdecl can_arty(int protoID, BOOL seaTriadRetn);
OPENSMACX_API uint32_t __cdecl morale_veh(uint32_t vehID, BOOL checkDroneRiot, 
	int factionIDvsNative);
OPENSMACX_API uint32_t __cdecl offense_proto(uint32_t protoID, int vehIDDef, BOOL isBombardment);
OPENSMACX_API uint32_t __cdecl armor_proto(uint32_t protoID, int vehIDAtk, BOOL isBombardment);
OPENSMACX_API uint32_t __cdecl speed_proto(uint32_t protoID);
OPENSMACX_API uint32_t __cdecl speed(uint32_t vehID, BOOL skipMorale);
OPENSMACX_API uint32_t __cdecl veh_cargo(uint32_t vehID);
OPENSMACX_API uint32_t __cdecl prototype_factor(uint32_t protoID);
OPENSMACX_API uint32_t __cdecl veh_cost(uint32_t protoID, int baseID, BOOL *hasProtoCost);
OPENSMACX_API BOOL __cdecl veh_jail(int vehID);
OPENSMACX_API void __cdecl veh_skip(int vehID);
OPENSMACX_API int __cdecl veh_fake(int protoID, int factionID);
OPENSMACX_API int __cdecl veh_wake(int vehID);
OPENSMACX_API uint8_t __cdecl get_proto_triad(uint32_t protoID);
OPENSMACX_API uint8_t __cdecl get_triad(uint32_t vehID);
