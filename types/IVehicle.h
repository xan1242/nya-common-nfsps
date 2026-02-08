enum eVehicleList {
	VEHICLE_ALL = 0,
	VEHICLE_PLAYERS = 1,
	VEHICLE_AI = 2,
	VEHICLE_AIRACERS = 3,
	VEHICLE_AICOPS = 4,
	VEHICLE_AITRAFFIC = 5,
	VEHICLE_RACERS = 6,
	VEHICLE_REMOTE = 7,
	VEHICLE_INACTIVE = 8,
	VEHICLE_TRAILERS = 9,
	VEHICLE_ACTIVERACERS = 10,
	VEHICLE_GHOST = 11,
	VEHICLE_MAX = 12,
};

enum DriverStyle {
	STYLE_NONE = -1,
	STYLE_RACING = 0,
	STYLE_DRAG = 1,
	STYLE_DRIFT = 2,
	STYLE_HIGH_SPEED = 3,
	STYLE_TRAFFIC = 4,
	NUM_DRIVER_STYLES = 5,
};

enum PhysicsMode {
	PHYSICS_MODE_INACTIVE = 0,
	PHYSICS_MODE_SIMULATED = 1,
	PHYSICS_MODE_EMULATED = 2,
};

enum DriverClass {
	DRIVER_HUMAN = 0,
	DRIVER_TRAFFIC = 1,
	DRIVER_COP = 2,
	DRIVER_RACER = 3,
	DRIVER_NONE = 4,
	DRIVER_NIS = 5,
	DRIVER_REMOTE = 6,
	DRIVER_REMOTE_RACER = 7,
	DRIVER_GHOST = 8,
	DRIVER_HUB = 9,
	DRIVER_MAX = 10,
};

typedef int CarType;

namespace VehicleFX {
	enum ID {
		LIGHT_NONE = 0x0,
		LIGHT_LHEAD = 0x1,
		LIGHT_RHEAD = 0x2,
		LIGHT_CHEAD = 0x4,
		LIGHT_LBRAKE = 0x8,
		LIGHT_RBRAKE = 0x10,
		LIGHT_CBRAKE = 0x20,
		LIGHT_LREVERSE = 0x40,
		LIGHT_RREVERSE = 0x80,
		LIGHT_LRSIGNAL = 0x100,
		LIGHT_RRSIGNAL = 0x200,
		LIGHT_LFSIGNAL = 0x400,
		LIGHT_RFSIGNAL = 0x800,
		LIGHT_COPRED = 0x1000,
		LIGHT_COPBLUE = 0x2000,
		LIGHT_COPWHITE = 0x4000,
		LIGHT_COPS = 0x7000,
		LIGHT_LSIGNAL = 0x500,
		LIGHT_RSIGNAL = 0xA00,
		LIGHT_HEADLIGHTS = 0x7,
		LIGHT_REVERSE = 0xC0,
		LIGHT_BRAKELIGHTS = 0x38,
	};
}

enum DriverAidType {
	TRACTION_CONTROL = 0x0,
	ANTI_BRAKE_LOCK = 0x1,
	STABILITY_MANAGEMENT = 0x2,
	DRIFT_STEERING_ASSIST = 0x3,
	DRIFT_GLUE_TO_ROAD = 0x4,
	DRIFT_DYNAMIC_BRAKE = 0x5,
	DRIFT_SPEED_CONTROL = 0x6,
	RACELINE_ASSIST = 0x7,
	BRAKING_ASSIST = 0x8,
	NUM_DRIVER_AIDS = 0x9,
};

class IVehicleAI;

namespace EventSequencer {
	class System;
}

namespace EventSys {
	class DynamicData;
}

class IVehicle : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x402440;

	virtual ISimable* GetSimable();
	virtual const ISimable* _GetSimable();
	virtual const UMath::Vector3* GetPosition();
	virtual void SetBehaviorOverride(UCrc32, UCrc32);
	virtual void RemoveBehaviorOverride(UCrc32);
	virtual void CommitBehaviorOverrides();
	virtual void ReleaseBehaviorAudio();
	virtual void SetStaging(bool);
	virtual bool IsStaging();
	virtual void SetDragStaging(bool);
	virtual bool IsDragStaging();
	virtual void SetUseDragStagingCamera(bool);
	virtual bool ShouldUseDragStagingCamera();
	virtual void Launch();
	virtual float GetPerfectLaunch();
	virtual void SetDriverStyle(DriverStyle);
	virtual DriverStyle GetDriverStyle();
	virtual void SetPhysicsMode(PhysicsMode);
	virtual PhysicsMode GetPhysicsMode();
	virtual void SetDraftZoneModifier(float);
	virtual float GetDraftZoneModifier();
	virtual int GetModelType();
	virtual bool IsSpooled();
	virtual bool IsLowRez();
	virtual const UCrc32* GetVehicleClass();
	virtual const Attrib::Instance* GetVehicleAttributes();
	virtual const char* GetVehicleName();
	virtual unsigned int GetVehicleKey();
	virtual unsigned int GetStockVehicleKey();
	virtual void SetDriverClass(DriverClass);
	virtual DriverClass GetDriverClass();
	virtual bool IsLoading();
	virtual float GetOffscreenTime();
	virtual float GetOnScreenTime();
	virtual bool SetVehicleOnGround(const UMath::Vector3 *, const UMath::Vector3 *, bool);
	virtual void ForceStopOn(char);
	virtual void ForceStopOff(char);
	virtual char GetForceStop();
	virtual bool InShock();
	virtual bool IsDestroyed();
	virtual void Activate();
	virtual void Deactivate();
	virtual bool IsActive();
	virtual float GetSpeedometer();
	virtual float GetSpeed();
	virtual void SetSpeed(float);
	virtual void SetVelocity(float, float, float);
	virtual float GetAbsoluteSpeed();
	virtual bool IsGlareOn(VehicleFX::ID);
	virtual void GlareOn(VehicleFX::ID);
	virtual void GlareOff(VehicleFX::ID);
	virtual bool IsCollidingWithSoftBarrier();
	virtual IVehicleAI* GetAIVehiclePtr();
	virtual float GetSlipAngle();
	virtual const UMath::Vector3* GetLocalVelocity();
	virtual void ComputeHeading(UMath::Vector3 *);
	virtual bool IsAnimating();
	virtual void SetAnimating(bool);
	virtual bool IsOffWorld();
	virtual const VehicleCustomizations* GetCustomizations();
	virtual void SetCustomizations(const VehicleCustomizations *);
	virtual const Physics::Tunings* GetTunings();
	virtual void SetTunings(const Physics::Tunings *);
	virtual bool GetPerformance(Physics::Info::CorrectedPerformance *);
	virtual const char* GetCacheName();
	virtual bool GetDynamicData(const EventSequencer::System *, EventSys::DynamicData *);
	virtual bool IsDriverAidOn(DriverAidType);
	virtual void SetDriverAidLevel(DriverAidType driverAidType, int driverAidLevel, bool persistChanges);
	virtual int GetDriverAidLevel(DriverAidType);
	virtual int GetDriverAidMaxLevel(DriverAidType);
	virtual void RestoreDriverAidLevels_All();
	virtual void RestoreDriverAidLevel(DriverAidType);
	virtual ISimable* SpawnPart(UCrc32, UCrc32, UCrc32);
	virtual void HidePart(UCrc32);
	virtual void ResetPart(UCrc32);
};

#define VEHICLE_LIST UTL::ListableSet<IVehicle, 12, eVehicleList, VEHICLE_MAX, 0xACE100>
static_assert(sizeof(VEHICLE_LIST::_buckets[0]) == 0x40);