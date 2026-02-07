class CAnimScene;
class ICEScene;

class INIS : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x4CFAE0;

	static inline auto& mInstance = *(INIS**)0xFFD744;

	virtual void AddRaceCars(int, const char *);
	virtual IVehicle *GetCar(UCrc32);
	virtual void StartLocation(const UMath::Vector3 *, float);
	virtual void StartLocationInRenderCoords(const bVector3 *, uint16_t);
	virtual const UMath::Vector3 *GetStartLocation();
	virtual const UMath::Vector3 *GetStartCameraLocation();
	virtual void SetPreMovie(const char *);
	virtual void SetPostMovie(const char *);
	virtual int GetType();
	virtual void Load(int, const char *, int, bool);
	virtual bool SkipOverNIS();
	virtual bool HasSkipped();
	virtual void Pause();
	virtual void UnPause();
	virtual bool IsLoaded();
	virtual bool IsPlaying();
	virtual bool GetDrawHud();
	virtual void SetDrawHud(bool);
	virtual bool InMovie();
	virtual bool InPreRaceMatchUp();
	virtual void ServiceLoads();
	virtual ICEScene *GetScene();
	virtual CAnimScene *GetAnimScene();
	virtual unsigned int GetSceneKey();
	virtual void Release();
	virtual void UpdateCarList(HSIMABLE__ **, int);
	virtual void StartEvents();
	virtual void FireEventTag(unsigned int);
	virtual void ResetEvents(float);
	virtual void StartPlayingNow();
	virtual bool IsWorldMomement();
	virtual void StartRaceCountdown(bool);
	virtual bool UseNISAudio();
	virtual int GetGameCarCount();
	virtual void Unload();
	virtual int GetAvatarCount();
	virtual const char *GetAvatarName(int);
	virtual void GetAvatarMatrix(int, bMatrix4 *, bool);
};