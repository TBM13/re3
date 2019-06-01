#include "common.h"
#include "Timecycle.h"

int   (*CTimeCycle::m_nAmbientRed)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x86AF78;
int   (*CTimeCycle::m_nAmbientGreen)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x665308;
int   (*CTimeCycle::m_nAmbientBlue)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x72CF88;
int   (*CTimeCycle::m_nDirectionalRed)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x6FAB78;
int   (*CTimeCycle::m_nDirectionalGreen)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x6F4528;
int   (*CTimeCycle::m_nDirectionalBlue)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x83CE58;
int   (*CTimeCycle::m_nSkyTopRed)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x87FB90;
int   (*CTimeCycle::m_nSkyTopGreen)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x8460A8;
int   (*CTimeCycle::m_nSkyTopBlue)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x87B158;
int   (*CTimeCycle::m_nSkyBottomRed)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x6FA960;
int   (*CTimeCycle::m_nSkyBottomGreen)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x70D6A8;
int   (*CTimeCycle::m_nSkyBottomBlue)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x83D288;
int   (*CTimeCycle::m_nSunCoreRed)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x878360;
int   (*CTimeCycle::m_nSunCoreGreen)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x6EE088;
int   (*CTimeCycle::m_nSunCoreBlue)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x773A68;
int   (*CTimeCycle::m_nSunCoronaRed)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x664B60;
int   (*CTimeCycle::m_nSunCoronaGreen)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x6F01E0;
int   (*CTimeCycle::m_nSunCoronaBlue)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x6E6340;
float (*CTimeCycle::m_fSunSize)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x733510;
float (*CTimeCycle::m_fSpriteSize)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x87F820;
float (*CTimeCycle::m_fSpriteBrightness)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x6E96F0;
short (*CTimeCycle::m_nShadowStrength)[NUMWEATHERS] = (short(*)[NUMWEATHERS])0x83CFD8;
short (*CTimeCycle::m_nLightShadowStrength)[NUMWEATHERS] = (short(*)[NUMWEATHERS])0x72B0F8;
short (*CTimeCycle::m_nTreeShadowStrength)[NUMWEATHERS] = (short(*)[NUMWEATHERS])0x733450;
float (*CTimeCycle::m_fFogStart)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x8806C8;
float (*CTimeCycle::m_fFarClip)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x8804E0;
float (*CTimeCycle::m_fLightsOnGroundBrightness)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x83D108;
int   (*CTimeCycle::m_nLowCloudsRed)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x726770;
int   (*CTimeCycle::m_nLowCloudsGreen)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x87BF08;
int   (*CTimeCycle::m_nLowCloudsBlue)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x87FA10;
int   (*CTimeCycle::m_nFluffyCloudsTopRed)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x70F2B0;
int   (*CTimeCycle::m_nFluffyCloudsTopGreen)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x72D288;
int   (*CTimeCycle::m_nFluffyCloudsTopBlue)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x86B108;
int   (*CTimeCycle::m_nFluffyCloudsBottomRed)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x6E8DA8;
int   (*CTimeCycle::m_nFluffyCloudsBottomGreen)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x715AA8;
int   (*CTimeCycle::m_nFluffyCloudsBottomBlue)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x6EE2D0;
float (*CTimeCycle::m_fBlurRed)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x87C7E0;
float (*CTimeCycle::m_fBlurGreen)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x774C10;
float (*CTimeCycle::m_fBlurBlue)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x8784E0;
float (*CTimeCycle::m_fBlurAlpha)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x733690;

float &CTimeCycle::m_fCurrentAmbientRed = *(float*)0x8F29B4;
float &CTimeCycle::m_fCurrentAmbientGreen = *(float*)0x94144C;
float &CTimeCycle::m_fCurrentAmbientBlue = *(float*)0x942FC0;
float &CTimeCycle::m_fCurrentDirectionalRed = *(float*)0x8F29D8;
float &CTimeCycle::m_fCurrentDirectionalGreen = *(float*)0x940594;
float &CTimeCycle::m_fCurrentDirectionalBlue = *(float*)0x942FAC;
int   &CTimeCycle::m_nCurrentSkyTopRed = *(int*)0x9403C0;
int   &CTimeCycle::m_nCurrentSkyTopGreen = *(int*)0x943074;
int   &CTimeCycle::m_nCurrentSkyTopBlue = *(int*)0x8F29B8;
int   &CTimeCycle::m_nCurrentSkyBottomRed = *(int*)0x9414D0;
int   &CTimeCycle::m_nCurrentSkyBottomGreen = *(int*)0x8F2BD0;
int   &CTimeCycle::m_nCurrentSkyBottomBlue = *(int*)0x8F625C;
int   &CTimeCycle::m_nCurrentSunCoreRed = *(int*)0x8F2534;
int   &CTimeCycle::m_nCurrentSunCoreGreen = *(int*)0x8F6264;
int   &CTimeCycle::m_nCurrentSunCoreBlue = *(int*)0x94149C;
int   &CTimeCycle::m_nCurrentSunCoronaRed = *(int*)0x8F2C1C;
int   &CTimeCycle::m_nCurrentSunCoronaGreen = *(int*)0x885B54;
int   &CTimeCycle::m_nCurrentSunCoronaBlue = *(int*)0x880F60;
float &CTimeCycle::m_fCurrentSunSize = *(float*)0x940588;
float &CTimeCycle::m_fCurrentSpriteSize = *(float*)0x8F1AA8;
float &CTimeCycle::m_fCurrentSpriteBrightness = *(float*)0x8F5FDC;
int   &CTimeCycle::m_nCurrentShadowStrength = *(int*)0x95CC76;
int   &CTimeCycle::m_nCurrentLightShadowStrength = *(int*)0x95CC66;
int   &CTimeCycle::m_nCurrentTreeShadowStrength = *(int*)0x95CC86;
float &CTimeCycle::m_fCurrentFogStart = *(float*)0x8F1AE0;
float &CTimeCycle::m_fCurrentFarClip = *(float*)0x8F5FD8;
float &CTimeCycle::m_fCurrentLightsOnGroundBrightness = *(float*)0x8F1B60;
int   &CTimeCycle::m_nCurrentLowCloudsRed = *(int*)0x95CB54;
int   &CTimeCycle::m_nCurrentLowCloudsGreen = *(int*)0x95CB48;
int   &CTimeCycle::m_nCurrentLowCloudsBlue = *(int*)0x95CC1C;
int   &CTimeCycle::m_nCurrentFluffyCloudsTopRed = *(int*)0x8F2550;
int   &CTimeCycle::m_nCurrentFluffyCloudsTopGreen = *(int*)0x8F59CC;
int   &CTimeCycle::m_nCurrentFluffyCloudsTopBlue = *(int*)0x941434;
int   &CTimeCycle::m_nCurrentFluffyCloudsBottomRed = *(int*)0x8F1A38;
int   &CTimeCycle::m_nCurrentFluffyCloudsBottomGreen = *(int*)0x8E28B8;
int   &CTimeCycle::m_nCurrentFluffyCloudsBottomBlue = *(int*)0x8F3960;
float &CTimeCycle::m_fCurrentBlurRed = *(float*)0x8F6000;
float &CTimeCycle::m_fCurrentBlurGreen = *(float*)0x9405A0;
float &CTimeCycle::m_fCurrentBlurBlue = *(float*)0x8F250C;
float &CTimeCycle::m_fCurrentBlurAlpha = *(float*)0x940728;
int   &CTimeCycle::m_nCurrentFogColourRed = *(int*)0x940714;
int   &CTimeCycle::m_nCurrentFogColourGreen = *(int*)0x8E2A60;
int   &CTimeCycle::m_nCurrentFogColourBlue = *(int*)0x8F57EC;

int   &CTimeCycle::m_FogReduction = *(int*)0x880FB8;

int   &CTimeCycle::m_CurrentStoredValue = *(int*)0x94057C;
CVector *CTimeCycle::m_VectorToSun = (CVector*)0x665548;	// [16]