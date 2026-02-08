class UserProfile : public EA::Memcard::IMemcardSavable {
public:
	char mName[32]; // +18
	uint8_t _mPlaylist[0x208]; // +38 placeholder
	FEPlayerCarDB mCarStable; // +240

	static inline auto spUserProfiles = (UserProfile**)0xAB0EAC; // spUserProfiles[4]
};
static_assert(offsetof(UserProfile, mCarStable) == 0x240);