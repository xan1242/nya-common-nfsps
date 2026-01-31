class AcidEffect;
class GIcon;

namespace EventSys {
	class StaticData;
}

namespace CARP {
	class Trigger {
	public:
		UMath::Vector4 fMatRow0Width;
		uint32_t fFlags : 24;
		uint32_t fShape : 4;
		uint32_t fType : 4;
		float fHeight;
		EventSys::StaticData* fEvent;
		uint16_t fIterStamp;
		uint16_t fFingerprint;
		UMath::Vector4 fMatRow2Length;
		UMath::Vector4 fPosRadius;
	};
}

class WTrigger : public CARP::Trigger {};

enum GameplayObjType {
	kGameplayObjType_Invalid = -1,
	kGameplayObjType_Activity = 0x0,
	kGameplayObjType_Handler = 0x1,
	kGameplayObjType_State = 0x2,
	kGameplayObjType_Character = 0x3,
	kGameplayObjType_Trigger = 0x4,
	kGameplayObjType_Marker = 0x5,
	kGameplayObjType_TrackLayout = 0x6,
	kGameplayObjType_Count = 0x7,
};

class GRuntimeInstance : public Attrib::Instance {
public:
	class ConnectedInstance;

	uint16_t mFlags;
	uint16_t mNumConnected;
	GRuntimeInstance::ConnectedInstance* mConnected;
	GRuntimeInstance* mPrev;
	GRuntimeInstance* mNext;

	virtual void _vf0();
	virtual GameplayObjType GetType();
};
static_assert(sizeof(GRuntimeInstance) == 0x24);

class GTrigger : public GRuntimeInstance {
public:
	WTrigger mWorldTrigger;
	uint8_t _64[0xC];
	UMath::Vector3 mDirection;
	unsigned int mTriggerEnabled;
	bstl::derived_with_name<eastl::vector<ISimable*,bstl::allocator>> mSimObjInside;
	char mTriggerEventData[16];
	AcidEffect* mParticleEffect[2];
	GIcon* mIcon;
	bool mEnabled;
	int mActivationReferences;
};