enum ePlayerList {
	PLAYER_ALL = 0,
	PLAYER_LOCAL = 1,
	PLAYER_REMOTE = 2,
	PLAYER_MAX = 3,
};

class ISimable;
class IHud;
class IFeedback;
class ISteeringWheel;
class PlayerSettings;

class IPlayer : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x4CD350;

	virtual ISimable* GetSimable();
	virtual bool IsLocal();
	virtual const UMath::Vector3* GetPosition();
	virtual bool SetPosition(const UMath::Vector3 *);
	virtual PlayerSettings* GetSettings();
	virtual void SetSettings(int);
	virtual int GetSettingsIndex();
	virtual IHud* GetHud();
	virtual void ResetHudType();
	virtual void ReleaseHud();
	virtual void SetRenderPort(int);
	virtual int GetRenderPort();
	virtual void SetControllerPort(int);
	virtual int GetControllerPort();
	virtual IFeedback* GetFFB();
	virtual ISteeringWheel* GetSteeringDevice();
	virtual bool InGameBreaker();
	virtual bool CanRechargeNOS();
	virtual void ResetGameBreaker(bool);
	virtual void ChargeGameBreaker(float);
	virtual float GetGameBreakerCharge();
	virtual bool ToggleGameBreaker();
	virtual float GetNOSModifier();
	virtual void SetNOSModifier(float);
	virtual void SetGameBreakerModifier(float);
	virtual void SetEncounterMessage(int);
};

#define PLAYER_LIST UTL::ListableSet<IPlayer, 12, ePlayerList, PLAYER_MAX, 0xACE400>
static_assert(sizeof(PLAYER_LIST::_buckets[0]) == 0x40);