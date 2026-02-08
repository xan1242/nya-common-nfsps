class IDamageableVehicle : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x438720;

	virtual bool IsLightDamaged(VehicleFX::ID);
	virtual void DamageLight(VehicleFX::ID, bool);
	virtual bool IsLightCracked(VehicleFX::ID);
	virtual void CrackLight(VehicleFX::ID, bool);
	virtual bool IsWindowDamaged(VehicleFX::WindowFXID);
	virtual void DamageWindow(VehicleFX::WindowFXID, bool);
	virtual bool IsWindowCracked(VehicleFX::WindowFXID);
	virtual void CrackWindow(VehicleFX::WindowFXID, bool);
	virtual void SetHitPointsOverride(float);
};