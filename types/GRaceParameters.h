class GVault;
class GActivity;

class GRaceIndexData {
public:
	enum {
		kFlag_AvailQuickRace = 0x1,
		kFlag_AvailOnline = 0x2,
		kFlag_AvailChallenge = 0x4,
		kFlag_CanBeReversed = 0x8,
		kFlag_IsDDayRace = 0x10,
		kFlag_IsBossRace = 0x20,
		kFlag_IsMarkerRace = 0x40,
		kFlag_IsPursuitRace = 0x80,
		kFlag_IsLoopingRace = 0x100,
		kFlag_RankByPoints = 0x200,
		kFlag_RankByDistance = 0x400,
		kFlag_CopsInRace = 0x800,
		kFlag_ScriptedCops = 0x1000,
		kFlag_NeverQuickRace = 0x2000,
		kFlag_ChallengeRace = 0x4000,
		kFlag_CollectorsRace = 0x8000,
		kFlag_IsTutorialRace = 0x10000,
		kFlag_OnlinePlatformRace = 0x20000,
		kFlag_RaceWarsRace = 0x40000,
		kFlag_UsePresetRide = 0x80000,
		kFlag_IsPracticeMode = 0x100000,
		kFlag_IsSlotcarRace = 0x200000,
		kFlag_IsDynamicRace = 0x400000,
	};

	unsigned int mKey;
	char mEventID[10];
	unsigned int mRaceHash;
	unsigned int mFlags;
	float mLength;
	int16_t mLocalizationTag;
	int16_t mCash;
	uint16_t mRivalBest;
	uint8_t mNumLaps;
	char mRaceType;
	char mNumHeats;
	unsigned int mPlayerCarTypeHash;
	float mTrackRecord;
	unsigned int mTrack;
	unsigned int mTrackLayout;
	unsigned int mParentKey;
	unsigned int mTrackRecordHolder;
};
static_assert(sizeof(GRaceIndexData) == 0x40);

class GRaceParameters {
public:
	enum ScoreUnitType {
		kScore_None = 0,
		kScore_Time = 1,
		kScore_Speed = 2,
		kScore_Points = 3,
	};

	GRaceIndexData* mIndex;
	Attrib::Instance* mRaceRecord;
	GVault* mParentVault;
	GVault* mChildVault;
	GVault* mTrackVault;
	GVault* mRegionVault;

	static inline auto GetIsLoopingRace = (bool(__thiscall*)(GRaceParameters*))0x686180;

	virtual void _vf0();
};
static_assert(sizeof(GRaceParameters) == 0x1C);

class GRaceCustom : public GRaceParameters {
public:
	GActivity* mRaceActivity;
	unsigned int mNumOpponents;
	bool mReversed;
	bool mFreedByOwner;
	bool mNosEnabled;
	bool mTakeCrew;
	int mHeatLevel;
	bool mPracticeMode;
	GRaceIndexData mCustomIndexData;

	static inline auto SetReversed = (void(__thiscall*)(GRaceCustom*, bool))0x657F10;
	static inline auto SetNumLaps = (void(__thiscall*)(GRaceCustom*, int))0x6676F0;
	static inline auto SetIsPracticeMode = (void(__thiscall*)(GRaceCustom*, bool))0x667810;
	static inline auto SetIsSlotcarRace = (void(__thiscall*)(GRaceCustom*, bool))0x667850;
	static inline auto SetTrafficDensity = (void(__thiscall*)(GRaceCustom*, int))0x667710;
	static inline auto SetNumOpponents = (void(__thiscall*)(GRaceCustom*, int))0x831480;
	static inline auto SetDifficulty = (void(__thiscall*)(GRaceCustom*, int))0x667740;
	static inline auto SetCopsEnabled = (void(__thiscall*)(GRaceCustom*, bool))0x6677D0;
};
static_assert(sizeof(GRaceCustom) == 0x70);