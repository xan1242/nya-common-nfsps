enum GameFlowState {
	GAMEFLOW_STATE_NONE = 0x0,
	GAMEFLOW_STATE_LOADING_FRONTEND = 0x1,
	GAMEFLOW_STATE_UNLOADING_FRONTEND = 0x2,
	GAMEFLOW_STATE_IN_FRONTEND = 0x3,
	GAMEFLOW_STATE_LOADING_REGION = 0x4,
	GAMEFLOW_STATE_LOADING_TRACK = 0x5,
	GAMEFLOW_STATE_RACING = 0x6,
	GAMEFLOW_STATE_UNLOADING_TRACK = 0x7,
	GAMEFLOW_STATE_UNLOADING_REGION = 0x8,
	GAMEFLOW_STATE_EXIT_DEMO_DISC = 0x9,
};

class GameFlowManager {
public:
	void* pSingleFunction;
	uint32_t SingleFunctionParam;
	const char* pSingleFunctionName;
	void* pLoopingFunction;
	const char* pLoopingFunctionName;
	bool WaitingForCallback;
	const char* pCallbackName;
	uint32_t CallbackPhase;
	uint32_t CurrentGameFlowState;

	static inline auto UnloadTrack = (void(__thiscall*)(GameFlowManager*))0x6DBC60;
	static inline auto LoadFrontend = (void(__thiscall*)(GameFlowManager*))0x6D3230;
	static inline auto UnloadFrontend = (void(__thiscall*)(GameFlowManager*))0x6D3290;
	static inline auto ReloadTrack = (void(__thiscall*)(GameFlowManager*))0x6DBC10;
};
static_assert(sizeof(GameFlowManager) == 0x24);

auto& TheGameFlowManager = *(GameFlowManager*)0xABB4F0;