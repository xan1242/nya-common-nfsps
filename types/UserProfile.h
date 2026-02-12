class VideoSettings : public EA::Memcard::IMemcardSavable {
public:
	float FEScale;
	float ScreenOffsetX;
	float ScreenOffsetY;
	bool WideScreen;
	float TimeOfDay;
	float Brightness;
};

class ForceFeedbackSettings : public EA::Memcard::IMemcardSavable {
public:
	float mFFScale;
};

class GameplaySettings : public EA::Memcard::IMemcardSavable {
public:
	bool AutosaveOn;
	bool RearviewOn;
	bool PipOn;
	bool Damage;
	uint8_t SpeedoUnits;
	uint8_t RacingMiniMapMode;
	uint8_t ExploringMiniMapMode;
	uint8_t ReplayOn;
	uint8_t CrashPlaybackOn;
	uint8_t NamesAboveOn;
	unsigned int MapItems;
	uint8_t LastMapZoom;
	uint8_t LastPursuitMapZoom;
	uint8_t LastMapView;
	bool MapScreenHelpShown;
	bool MapScreenRandEncHelpShown;
	bool JumpCam;
	float HighlightCam;
};

class AudioSettings : public EA::Memcard::IMemcardSavable {
public:
	float MasterVol;
	float SpeechVol;
	float FEMusicVol;
	float IGMusicVol;
	float SoundEffectsVol;
	float EngineVol;
	float CarVol;
	float AmbientVol;
	float SpeedVol;
	int AudioMode;
	int InteractiveMusicMode;
	int EATraxMode;
	int UseCarClassSongFiltering;
	int AudioQuality;
	int PlayState;
};

class OptionsSettings {
public:
	VideoSettings TheVideoSettings;
	ForceFeedbackSettings TheForceFeedbackSettings;
	GameplaySettings TheGameplaySettings;
	AudioSettings TheAudioSettings;
	PlayerSettings ThePlayerSettings[4];
};

struct JukeboxEntry {
	unsigned int SongIndex;
	unsigned int SongKey;
	uint8_t PlayabilityField;
};

class Jukebox : public UTL::FixedVector<JukeboxEntry,40>, EA::Memcard::IMemcardSavable {
public:
};

class UserProfile : public EA::Memcard::IMemcardSavable {
public:
	char mName[32];
	Jukebox mPlaylist;
	FEPlayerCarDB mCarStable;
	OptionsSettings mOptionsSettings;
	unsigned int mNumRaceDaySaves;
	unsigned int mNumRaceDaySavesTotal;
	//Gameplay::GHubRecord currentRaceDayConfig;
	//RaceDaySettings mRaceDaySettings;
	//unsigned int OnlineXPLevel;
	//unsigned int mEasterEggs;

	static inline auto spUserProfiles = (UserProfile**)0xAB0EAC; // spUserProfiles[4]
};
static_assert(offsetof(UserProfile, mCarStable) == 0x240);
static_assert(offsetof(UserProfile, mOptionsSettings) == 0x908C4);
static_assert(offsetof(UserProfile, mNumRaceDaySaves) == 0x90AC8);