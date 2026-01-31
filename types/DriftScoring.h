enum eDriftChainState {
	kRUNNING = 0,
	kHIT_A_WALL = 1,
	kSPAN_OUT = 2,
	kTIME_OUT = 3,
	kOFF_BOUNDS = 4,
	kNum_DriftChainBrokenReason = 5,
};

enum eDriftDirection {
	kNOT_DRIFTING = 0,
	kLEFT = 1,
	kRIGHT = 2,
	kNum_DriftDirection = 3,
};

class DriftChainInfo {
public:
	eDriftChainState reason;
	unsigned int totalPoints;
	unsigned int awardedPoints;
	bool driftBeganInSectionEntryZone;
	unsigned int sectionIndex;
	unsigned int lapIndex;
	float duration;
	float currentDriftDuration;
	float lastDriftDuration;
	float length;
	bool seamlessBonusAchieved;
	eastl::list<unsigned int,bstl::allocator> driftPoints;
};
static_assert(sizeof(DriftChainInfo) == 0x3C);

class DriftSectionReport {
public:
	unsigned int sectionScore;
	unsigned int totalScoreAtThisSection;
	eastl::vector<DriftChainInfo,bstl::allocator> driftChains;
};
static_assert(sizeof(DriftSectionReport) == 0x18);

class DriftLapReport {
public:
	unsigned int lapScore;
	unsigned int totalScoreAtThisLap;
	eastl::map<unsigned int,DriftSectionReport,eastl::less<unsigned int>,bstl::allocator> driftSectionReports;
};
static_assert(sizeof(DriftLapReport) == 0x24);

class DriftScoreReport {
public:
	unsigned int totalPoints;
	DriftChainInfo* bestDriftInDuration;
	DriftChainInfo* bestDriftInLength;
	DriftChainInfo* bestDriftInScore;
	unsigned int averageDriftScore;
	float averageDriftLength;
	float averageDriftDuration;
	unsigned int numberOfSpinOuts;
	unsigned int numberOfWallsHit;
	unsigned int numberOfDriftChains;
	unsigned int externalPoints;
	eastl::map<unsigned int,DriftLapReport,eastl::less<unsigned int>,bstl::allocator> driftLapReports;
};
static_assert(sizeof(DriftScoreReport) == 0x48);

class DriftScoring {
public:
	bool mHitAWall;
	bool mDriftScoringEngaged;
	bool mFinalized;
	bool mInDriftSection;
	bool mWasDrifting;
	bool mWentOffTrack;
	bool mStayedOnTrackBonusAwarded;
	bool mNOSBonusAwarded;
	bool mNOSWasEngaged;
	bool mNOSTimerStarted;
	bool mHighSpeedBonusAwarded;
	int mCurrentSectionIndex;
	int mCurrentLapIndex;
	eDriftDirection mDriftDirection;
	float mTimeSinceLastDirectionChange;
	float mCountDownAfterHitAWall;
	float mCountDownAfterSpanOut;
	float mTimeSinceDriftDisengaged;
	float mCurrentSectionEntryBonusMultiplier;
	float mTimeSinceNOSWasActivated;
	UMath::Vector3 mLastPosition;
	eastl::list<DriftChainInfo,bstl::allocator> mDriftChains;
	DriftScoreReport mDriftScoreReport;
};