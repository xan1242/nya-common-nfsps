enum eInvulnerablitiy {
	INVULNERABLE_NONE = 0,
	INVULNERABLE_FROM_MANUAL_RESET = 1,
	INVULNERABLE_FROM_RESET = 2,
	INVULNERABLE_FROM_CONTROL_SWITCH = 3,
	INVULNERABLE_FROM_PHYSICS_SWITCH = 4,
};

class IRBVehicle : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x402270;

	virtual void SetTargetPosition(const UMath::Vector3 *);
	virtual void SetCollisionMass(float);
	virtual void SetCollisionCOG(const UMath::Vector3 *);
	virtual void EnableObjectCollisions(bool);
	virtual bool AreObjectCollisionsEnabled();
	virtual void EnableVehicleCollisions(bool);
	virtual void SetInvulnerability(eInvulnerablitiy, float);
	virtual eInvulnerablitiy GetInvulnerability();
	virtual void SetReactions(DriverClass, const Attrib::Instance *);
	virtual const Attrib::Instance *GetReactions(DriverClass);
};