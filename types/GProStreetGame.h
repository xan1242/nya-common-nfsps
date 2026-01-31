class GHub;
class GTier;
class GDamageometer;
class LuaHubBinder;
class LuaTierBinder;
class LuaRaceParametersBinder;
class GProStreetRaceStats;

class GDamageSaveData {
public:
	unsigned int mCar;
	int mPlayerNum;
	int mDataSize;
	bool mApplyRequestPending;
	bool mSaveRequestPending;
	char mSaveBuffer[15240];
};

template<typename T>
class GCareerElementSet {
public:
	uint8_t _0[0x1C];
};

class GHubSimHelper {
public:
	virtual void CreateVehicle(int, unsigned int, unsigned int);
	virtual void WarpVehicle(int, unsigned int);
	virtual void DestroyVehicle(int, bool);
	virtual void SetPlayerVehicle(int, unsigned int, unsigned int);
};

/* 7411 */
class GCareerElement : public Attrib::Instance {
public:
	uint8_t mFlags;

	virtual const char* GetName();
};

class GHubWriter;
class GHub : public GCareerElement {
public:
	unsigned int mFlags;
	unsigned int mScores[2];
	unsigned int mEventCount;
	unsigned int mCurrentEventKey;
	unsigned int mRequestedEventKey;
	unsigned int mSelectedEventIndex;
	GTier *mTier;
	GHubWriter* mHubWriter;
	eastl::map<unsigned int,unsigned int,eastl::less<unsigned int>,bstl::allocator> mCurrentScores;
	eastl::map<unsigned int,unsigned int,eastl::less<unsigned int>,bstl::allocator> mCurrentRankings;
	int mCurrentSunAndSky;
	unsigned int mWonRaces[8];
};
static_assert(sizeof(GHub) == 0x98);

class GProStreetGame : public IVehicleCache, GHubSimHelper, ISelectionSet, UCOM::Object {
public:
	unsigned int mHubCount;
	GCareerElementSet<GHub> mHubsSet;
	GHub* mHubs;
	GHub* mCurrentHub;
	GVault* mRegionVault;
	unsigned int mTierCount;
	GTier* mTiers;
	GTier* mCurrentTier;
	Attrib::Class* mGameplayClass;
	HSIMABLE__* mHubVehicles[2];
	unsigned int mHubVehicleFEHandles[2];
	unsigned int mEmergencyHubVehicleFEHandles[2];
	GDamageometer* mDamageometer;
	char mCustomKeys[5][10];
	unsigned int mCustomHubs[5];
	unsigned int mCustomPlayHub;
	LuaHubBinder* mHubBinder;
	LuaTierBinder* mTierBinder;
	LuaRaceParametersBinder* mRaceParametersBinder;
	unsigned int mGripTrackRecordCount;
	unsigned int mDragTrackRecordCount;
	unsigned int mDriftTrackRecordCount;
	unsigned int mSpeedTrackRecordCount;
	unsigned __int8 mEliteOrgUnlockFlags;
	GProStreetRaceStats* mProStreetStats;
	Hermes::_h_HHANDLER__* mMsgNotifyVehicleDestroyed;
	GDamageSaveData mDamageSaveData[10];

	static inline auto& mObj = *(GProStreetGame**)0xAB9DC8;
};
static_assert(sizeof(GProStreetGame) == 0x254E0);

class GCareer {
public:
	static inline auto& mObj = *(GCareer**)0xAB9DD4;

	static inline auto StartNewCareer = (void(__thiscall*)(GCareer*))0x698460;
};