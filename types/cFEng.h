class cFEng {
public:
	static inline auto& mInstance = *(cFEng**)0xAB27D8;

	static inline auto IsPackagePushed = (bool(__thiscall*)(cFEng*, const char* pPackageName))0x5B4D70;
};