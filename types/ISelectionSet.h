class GPresentationController;
class ISelectionSet : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x6560D0;

	virtual void GetEnabledSelectionSets(GPresentationController* controller, void* enabledSets, bool inRace) = 0;
};