namespace EventSys {
	class Event {
	public:
		static inline auto Allocate = (void*(__cdecl*)(uint32_t size, int))0x45AD40;

		void* operator new(size_t size) {
			return Allocate(size, 0);
		}

		uint32_t fEventSize;

		virtual void _dtor();
		virtual void Print();
		virtual const char* GetEventName();
	};
	static_assert(sizeof(Event) == 0x8);
}

class ERestartRace : public EventSys::Event {
public:
	static ERestartRace* Create() {
		return ((ERestartRace*(__thiscall*)(ERestartRace*))0x6B4550)((ERestartRace*)Allocate(8, 0));
	}
};