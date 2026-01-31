namespace GRace {
	enum CopDensity {
		kRaceCops_Off = 0,
		kRaceCops_Light = 1,
		kRaceCops_Medium = 2,
		kRaceCops_Heavy = 3,
		kRaceCops_NumDensities = 4,
	};

	enum AI_AggressionLevel {
		kAggression_Careful = 0,
		kAggression_Intermediate = 1,
		kAggression_Aggressive = 2,
	};

	enum AI_MistakeLevel {
		kMistake_Rookie = 0,
		kMistake_Intermediate = 1,
		kMistake_Veteran = 2,
	};

	enum RaceCarClass {
		kRaceCar_ClassNone = 0,
		kRaceCar_ClassExotic = 1,
		kRaceCar_ClassMuscle = 2,
		kRaceCar_ClassTuner = 3,
		kRaceCar_NumClasses = 4,
	};

	enum CareerElementDrawStyle {
		kDrawStyleBox = 0,
		kDrawStyleEllipse = 1,
		kDrawStyleDiamond = 2,
	};

	enum Difficulty {
		kRaceDifficulty_Easy = 0,
		kRaceDifficulty_Medium = 1,
		kRaceDifficulty_Hard = 2,
		kRaceDifficulty_Insane = 3,
		kRaceDifficulty_NumDifficulties = 4,
	};

	enum EventStyle {
		kEventStyle_BestRound = 0,
		kEventStyle_Elimination = 1,
	};

	enum HandicapMode {
		kHandicap_None = 0,
		kHandicap_Performance = 1,
		kHandicap_Group = 2,
	};

	enum RaceLigthingMode {
		kLighting_Normal = 0,
		kLightingDrift = 1,
		kLightingCanyon = 2,
	};

	enum OpponentGender {
		kOpponentGender_Male = 0,
		kOpponentGender_Female = 1,
		kOpponentGender_Ambiguous = 2,
		kOpponentType_NumGenders = 3,
	};

	enum OpponentTeam {
		kOpponentTeam_Default = 0,
		kOpponentTeam_ApexGlide = 1,
		kOpponentTeam_AfterMix = 2,
		kOpponentTeam_TougeUnion = 3,
		kOpponentTeam_GripRunners = 4,
		kOpponentTeam_Boxcut = 5,
		kOpponentTeam_LaterFire = 6,
		kOpponentTeam_NumTeams = 7,
	};

	enum OpponentType {
		kOpponentType_Default = 0,
		kOpponentType_Challenge = 1,
		kOpponentType_Rival = 2,
		kOpponentType_King = 3,
		kOpponentType_NumTypes = 4,
	};

	enum Mode {
		kRaceMode_None = 0,
		kRaceMode_Grip = 1,
		kRaceMode_HighSpeedChallenge = 2,
		kRaceMode_Drag = 3,
		kRaceMode_Drift = 4,
		kRaceMode_NumTypes = 5,
	};

	enum Behaviour {
		kRaceBehaviour_Single = 1,
		kRaceBehaviour_Dual = 2,
	};

	enum ShortcutType {
		kShortcutType_None = 0,
		kShortcutType_ParkRight = 1,
		kShortcutType_AlleyRight = 2,
		kShortcutType_SideStreetRight = 3,
		kShortcutType_TunnelRight = 4,
		kShortcutType_GenericRight = 5,
		kShortcutType_ParkLeft = 6,
		kShortcutType_AlleyLeft = 7,
		kShortcutType_SideStreetLeft = 8,
		kShortcutType_TunnelLeft = 9,
		kShortcutType_GenericLeft = 10,
	};

	enum Variant {
		kRaceVariant_Invalid = -1,
		kRaceVariant_None = 0,
		kRaceVariant_SpeedChallenge = 1,
		kRaceVariant_TopSpeed = 2,
		kRaceVariant_Circuit = 3,
		kRaceVariant_SectorShootout = 4,
		kRaceVariant_TimeAttack = 5,
		kRaceVariant_Drag = 6,
		kRaceVariant_Drag_Wheelie = 7,
		kRaceVariant_Drift_Solo = 8,
		kRaceVariant_Drift_Race = 9,
		kRaceVariant_Drift_Tandem = 10,
		kRaceVariant_NumTypes = 11,
	};

	enum WingmanShortcutTriggerHint {
		kShortcutTrigger_None = 0,
		kShortcutTrigger_Init = 1,
		kShortcutTrigger_Entry = 2,
		kShortcutTrigger_Pos = 3,
		kShortcutTrigger_Exit = 4,
		kShortcutTrigger_All = 5,
	};

	enum Tier {
		kRaceTier_None = 0,
		kRaceTier_1 = 1,
		kRaceTier_2 = 2,
		kRaceTier_3 = 3,
		kRaceTier_NumTiers = 4,
	};

	enum Context {
		kRaceContext_QuickRace = 0,
		kRaceContext_TimeTrial = 1,
		kRaceContext_Online = 2,
		kRaceContext_Career = 3,
		kRaceContext_Count = 4,
	};

	enum Type {
		kRaceType_None = -1,
		kRaceType_P2P = 0x0,
		kRaceType_P2P_Min = 0x0,
		kRaceType_SpeedChallenge_Min = 0x0,
		kRaceType_SpeedChallenge_HeadsUp = 0x0,
		kRaceType_SpeedChallenge_Mixed = 0x1,
		kRaceType_SpeedChallenge_Class = 0x2,
		kRaceType_SpeedChallenge_Max = 0x3,
		kRaceType_TopSpeed_Min = 0x3,
		kRaceType_TopSpeed_HeadsUp = 0x3,
		kRaceType_TopSpeed_Mixed = 0x4,
		kRaceType_TopSpeed_Class = 0x5,
		kRaceType_TopSpeed_Max = 0x6,
		kRaceType_P2P_Max = 0x6,
		kRaceType_Grip_Min = 0x6,
		kRaceType_Circuit_Min = 0x6,
		kRaceType_Circuit_HeadsUp = 0x6,
		kRaceType_Circuit_Mixed = 0x7,
		kRaceType_Circuit_Class = 0x8,
		kRaceType_Circuit_Max = 0x9,
		kRaceType_SectorShootout_Min = 0x9,
		kRaceType_SectorShootout_HeadsUp = 0x9,
		kRaceType_SectorShootout_Mixed = 0xA,
		kRaceType_SectorShootout_Class = 0xB,
		kRaceType_SectorShootout_Max = 0xC,
		kRaceType_TimeAttack_Min = 0xC,
		kRaceType_TimeAttack_HeadsUp = 0xC,
		kRaceType_TimeAttack_Mixed = 0xD,
		kRaceType_TimeAttack_Class = 0xE,
		kRaceType_TimeAttack_Max = 0xF,
		kRaceType_Grip_Max = 0x10,
		kRaceType_Drag_Min = 0x10,
		kRaceType_Drag_Time_Min = 0x10,
		kRaceType_Drag_HeadsUp = 0x10,
		kRaceType_Drag_Mixed = 0x11,
		kRaceType_Drag_Class = 0x12,
		kRaceType_Drag_Time_Max = 0x13,
		kRaceType_Drag_Wheelie_Min = 0x13,
		kRaceType_Drag_Wheelie_HeadsUp = 0x13,
		kRaceType_Drag_Wheelie_Mixed = 0x14,
		kRaceType_Drag_Wheelie_Class = 0x15,
		kRaceType_Drag_Wheelie_Max = 0x16,
		kRaceType_Drag_Max = 0x17,
		kRaceType_Drift_Min = 0x17,
		kRaceType_Drift_Solo_Min = 0x17,
		kRaceType_Drift_Solo_HeadsUp = 0x17,
		kRaceType_Drift_Solo_Mixed = 0x18,
		kRaceType_Drift_Solo_Class = 0x19,
		kRaceType_Drift_Solo_Max = 0x1A,
		kRaceType_Drift_Race_Min = 0x1A,
		kRaceType_Drift_Race_HeadsUp = 0x1A,
		kRaceType_Drift_Race_Mixed = 0x1B,
		kRaceType_Drift_Race_Class = 0x1C,
		kRaceType_Drift_Race_Max = 0x1D,
		kRaceType_Drift_Tandem_Min = 0x1D,
		kRaceType_Drift_Tandem_HeadsUp = 0x1D,
		kRaceType_Drift_Tandem_Mixed = 0x1E,
		kRaceType_Drift_Tandem_Class = 0x1F,
		kRaceType_Drift_Tandem_Max = 0x20,
		kRaceType_Drift_Max = 0x20,
		kRaceType_Knockout = 0x21,
		kRaceType_SpeedTrap = 0x22,
		kRaceType_Checkpoint = 0x23,
		kRaceType_Challenge = 0x24,
		kRaceType_NumTypes = 0x25,
	};

	enum {
		kHundredScale_LowerThresh = 0x1,
		kHundredScale_MiddleThresh = 0x22,
		kHundredScale_TopThresh = 0x43,
	};
}