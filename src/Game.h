#pragma once

enum eLevelName
{
	LEVEL_NONE = 0,
	LEVEL_INDUSTRIAL,
	LEVEL_COMMERCIAL,
	LEVEL_SUBURBAN
};

class CGame
{
public:
	static int &currLevel;
	static bool &bDemoMode;
	static bool &nastyGame;

	static void Process(void);
	static Bool InitialiseOnceBeforeRW(void);
	static Bool InitialiseRenderWare(void);
	static void ShutdownRenderWare(void);
	static void FinalShutdown(void);
};