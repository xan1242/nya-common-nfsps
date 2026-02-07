enum EVIEW_ID {
	EVIEW_NONE = 0xFFFFFFFF,
	EVIEW_FLAILER = 0x0,
	EVIEW_PLAYER1 = 0x1,
	EVIEW_PLAYER2 = 0x2,
	EVIEW_PLAYER1_RVM = 0x3,
	EVIEW_SNAP = 0x4,
	EVIEW_PLAYER1_REFLECTION = 0x5,
	EVIEW_PLAYER2_REFLECTION = 0x6,
	EVIEW_PLAYER1_GLOW = 0x7,
	EVIEW_PLAYER2_GLOW = 0x8,
	EVIEW_PLAYER1_TIREBLUR0 = 0x9,
	EVIEW_PLAYER1_TIREBLUR1 = 0xA,
	EVIEW_PLAYER1_TIREBLUR2 = 0xB,
	EVIEW_PLAYER1_TIREBLUR3 = 0xC,
	EVIEW_PLAYER1_SMOKE = 0xD,
	EVIEW_PLAYER2_SMOKE = 0xE,
	EVIEW_PLAYER1_PIP = 0xF,
	EVIEW_PLAYER1_SPECULAR = 0x10,
	EVIEW_PLAYER2_SPECULAR = 0x11,
	EVIEW_ANTI_ALIAS = 0x12,
	EVIEW_HEADLIGHT_P1 = 0x13,
	EVIEW_HEADLIGHT_P2 = 0x14,
	EVIEW_QUADRANT_TOP_LEFT = 0x15,
	EVIEW_QUADRANT_TOP_RIGHT = 0x16,
	EVIEW_QUADRANT_BOTTOM_LEFT = 0x17,
	EVIEW_QUADRANT_BOTTOM_RIGHT = 0x18,
	EVIEW_DEPTHTEXTURE = 0x19,
	EVIEW_HDR_SCENE = 0x1A,
	EVIEW_SHADOWMAP1 = 0x1B,
	EVIEW_SHADOWMAP2 = 0x1C,
	EVIEW_SHADOWPROJ1 = 0x1D,
	EVIEW_SHADOWPROJ2 = 0x1E,
	EVIEW_LIGHTPROJ1 = 0x1F,
	EVIEW_LIGHTPROJ2 = 0x20,
	EVIEW_SHADOWMAPCAR1 = 0x21,
	EVIEW_SHADOWMAPCAR2 = 0x22,
	EVIEW_SHADOWPROJCAR1 = 0x23,
	EVIEW_SHADOWPROJCAR2 = 0x24,
	EVIEW_LIGHTPROJCAR1 = 0x25,
	EVIEW_LIGHTPROJCAR2 = 0x26,
	EVIEW_LIGHTSTREAKS = 0x27,
	EVIEW_SHADOWMATTE = 0x28,
	EVIEW_ENVMAP0F = 0x29,
	EVIEW_ENVMAP0R = 0x2A,
	EVIEW_ENVMAP0B = 0x2B,
	EVIEW_ENVMAP0L = 0x2C,
	EVIEW_ENVMAP0U = 0x2D,
	EVIEW_ENVMAP0D = 0x2E,
	EVIEW_FIRST = 0x0,
	EVIEW_LAST = 0x2E,
	EVIEW_FIRST_RENDER = 0x1,
	EVIEW_LAST_RENDER = 0x2E,
	EVIEW_FIRST_PLAYER = 0x1,
	EVIEW_LAST_PLAYER = 0x2,
	EVIEW_FIRST_RVM = 0x3,
	EVIEW_LAST_RVM = 0x3,
	EVIEW_FIRST_ENVMAP = 0x29,
	EVIEW_LAST_ENVMAP = 0x2E,
	NUM_EVIEWS = 0x2F,
	NUM_RENDER_VIEWS = 0x2E,
	NUM_PLAYER_VIEWS = 0x2,
	NUM_RVM_VIEWS = 0x1,
};

class eViewPlatInfo {
public:
	bMatrix4 ViewMatrix;
	bMatrix4 ProjectionMatrix;
	bMatrix4 ProjectionZBiasMatrix;
	bMatrix4 ViewProjectionMatrix;
	bMatrix4 ViewProjectionZBiasMatrix;
	bVector4 ClippingPlanes[6];
};

class eViewPlatInterface {
public:
	eViewPlatInfo* PlatInfo;

	static inline auto GetScreenPosition = (void(__thiscall*)(eViewPlatInterface*, bVector3* screen_position, const bVector3* world_position))0x6F8B40;
};

class eView : public eViewPlatInterface {
public:
	char* Name;
	int ID;
	char Active;
	char LetterBox;
	char pad0;
	char pad1;
	float H;
	float NearZ;
	float FarZ;
	float FovBias;
	float FovDegrees;
	uint16_t FovbAngle;
	int BlackAndWhiteMode;
	int PixelMinSize;
	bVector3 ViewDirection;
	Camera *pCamera;
	//bTList<CameraMover> CameraMoverList;
	//eDynamicLightContext *WorldLightContext;
	uint8_t _[0x3C];
};
static_assert(sizeof(eView) == 0x80);

auto eViews = (eView*)0xFFACE0;