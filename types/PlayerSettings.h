namespace EA {
	namespace Memcard {
		class MemcardChunk {
		public:
			unsigned int ID;
			int Size;
			bool isNestedChunk;
		};

		class IMemcardSavable {
		public:
			unsigned int mNameHash;
			EA::Memcard::MemcardChunk* mpChunk;
			char* mpEndOfBuffer;
			char* mpStartOfBuffer;
			unsigned int mSize;

			virtual void _vf0();
			virtual void RegisterForSave(const char*, int);
			virtual void SaveData(int);
			virtual bool LoadData(int);
			virtual void DefaultData(int);
		};
	}
}

enum eSensitivitySetting {
	SS_LOW = 0,
	SS_MEDUIM = 1,
	SS_HIGH = 2,
	NUM_SENSITIVITY_SETTINGS = 3,
	SS_MIN = 0,
	SS_MAX = 2,
};

enum eControllerConfig {
	CC_CONFIG1 = 0,
	CC_CONFIG2 = 1,
	CC_MSWHEEL = 2,
	NUM_CONTROLLER_CONFIGS = 2,
	NUM_CONTROLLER_DRIVE_CONFIGS = 3,
	MIN_CONFIG = 0,
	MAX_CONFIG = 1,
	MIN_WHEEL_CONFIG = 0,
	MAX_WHEEL_CONFIG = 0,
};

enum ePlayerSettingsCameras {
	PSC_BUMPER = 0,
	PSC_HOOD = 1,
	PSC_CLOSE = 2,
	PSC_FAR = 3,
	PSC_DRIFT = 4,
	NUM_CAMERAS_IN_OPTIONS = 5,
	PSC_STAGING = 6,
	PSC_PAUSE = 7,
	PSC_SLOTCAR = 8,
	PSC_TUNING = 9,
	PSC_MIN = 0,
	PSC_MAX = 4,
	PSC_DEFAULT = 3,
};

enum eDriverAssistLevel {
	DA_FAMILY = 0,
	DA_RACER = 1,
	DA_KING = 2,
	NUM_ASSIST_LEVELS = 3,
};

class PlayerSettings : public EA::Memcard::IMemcardSavable {
public:
	bool GaugesOn;
	bool PositionOn;
	bool LapInfoOn;
	bool RaceInfoOn;
	bool ScoreOn;
	bool Rumble;
	bool LeaderboardOn;
	bool SectorDisplayOn;
	bool CrewInfoOn;
	bool TransmissionPromptOn;
	bool DriveWithAnalog;
	uint8_t GripTransmission;
	uint8_t GripCarCamera;
	uint8_t GripBrakes;
	uint8_t GripTractionControl;
	uint8_t GripElectronicControl;
	uint8_t DriftTransmission;
	uint8_t DriftCarCamera;
	uint8_t DriftTractionControl;
	uint8_t DriftElectronicControl;
	uint8_t DragClutch;
	uint8_t DragCarCamera;
	uint8_t SpeedTransmission;
	uint8_t SpeedCarCamera;
	uint8_t SpeedTractionControl;
	uint8_t SpeedElectronicControl;
	eSensitivitySetting SensitivitySetting;
	eControllerConfig Config;
	ePlayerSettingsCameras CurCam;
	eDriverAssistLevel DriverAssistLevel;
	uint8_t SplitTimeType;
	uint8_t Transmission;
	uint8_t Handling;
	uint8_t Player;
	uint8_t TextPopupsOn;
	uint8_t BestLineOn;
	uint8_t ArrowIndicatorsOn;
	uint8_t InGameLeaderboardOn;
};