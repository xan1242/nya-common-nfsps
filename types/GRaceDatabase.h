class GRaceBin;
class GRaceDatabase {
public:
	enum { kMaxDynamicRaces = 8 };

	unsigned int mRaceCountStatic;
	unsigned int mRaceCountDynamic;
	GRaceIndexData* mRaceIndex;
	GRaceParameters* mRaceParameters;
	GRaceCustom* mRaceCustom[kMaxDynamicRaces];
	unsigned int mBinCount;
	GRaceBin* mBins;
	Attrib::Class* mGameplayClass;
	GRaceCustom* mStartupRace;
	GRace::Context mStartupRaceContext;
	unsigned int mNumInitialUnlocks;
	unsigned int* mInitialUnlockHash;
	eastl::map<unsigned int,int,eastl::less<unsigned int>,bstl::allocator> mTrackLayoutLocTags;

	static inline auto& mObj = *(GRaceDatabase**)0xAB9D80;

	static inline auto GetRaceFromHash = (GRaceParameters*(__thiscall*)(GRaceDatabase*, uint32_t))0x685C10;
	static inline auto AllocCustomRace = (GRaceCustom*(__thiscall*)(GRaceDatabase*, GRaceParameters*))0x697700;
	static inline auto FreeCustomRace = (GRaceCustom*(__thiscall*)(GRaceDatabase*, GRaceParameters*))0x65EBB0;
	static inline auto SetStartupRace = (void(__thiscall*)(GRaceDatabase*, GRaceCustom*, GRace::Context))0x657BC0;
};