namespace Sim {
	enum State {
		STATE_NONE = 0,
		STATE_INITIALIZING = 1,
		STATE_ACTIVE = 3,
		STATE_IDLE = 4,
	};

	auto Exists = (bool(*)())0x4CEBC0;
	auto GetTime = (float(*)())0x4CEFB0;
	auto GetState = (State(*)())0x4CEBD0;
}

class SimSystem;

namespace Sim {
	namespace Internal {
		auto& mSystem = *(SimSystem**)0xBFB400;
	}
}