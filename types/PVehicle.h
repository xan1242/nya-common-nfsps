namespace Sim {
	class Param {
	public:
		UCrc32 mType;
		const Sim::Param* mSource;
		unsigned int pad;
		unsigned int pad1;
	};
}

class IVehicleCache;

class VehicleParams : public Sim::Param {
public:
	DriverClass carClass;
	Attrib::Instance pvehicle;
	const UMath::Vector3* initialVec;
	const UMath::Vector3* initialPos;
	RideInfo* rideInfo;
	IVehicleCache* VehicleCache;
	const Physics::Info::PerformanceMatching* matched;
	unsigned int Flags;

	VehicleParams() {
		mType.mCRC = Attrib::StringHash32("VehicleParams");
		mSource = this;
	}
};
static_assert(sizeof(VehicleParams) == 0x3C);

class PVehicle {
public:
	static inline auto Construct = (ISimable*(__cdecl*)(Sim::Param params))0x72FBC0;
};