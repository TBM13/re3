#include "common.h"
#include "patcher.h"
#include "ModelInfo.h"

CBaseModelInfo **CModelInfo::ms_modelInfoPtrs = (CBaseModelInfo**)0x83D408;

//CStore<CSimpleModelInfo, SIMPLEMODELSIZE> &CModelInfo::ms_simpleModelStore = *(CStore<CSimpleModelInfo, SIMPLEMODELSIZE>*)0x885BB4;
//CStore<CTimeModelInfo, TIMEMODELSIZE> &CModelInfo::ms_timeModelStore = *(CStore<CTimeModelInfo, TIMEMODELSIZE>*)0x94076C;
//CStore<C2dEffect, TWODFXSIZE> &CModelInfo::ms_2dEffectStore = *(CStore<C2dEffect, TWODFXSIZE>*)0x9434F8;
CStore<CSimpleModelInfo, SIMPLEMODELSIZE> CModelInfo::ms_simpleModelStore;
CStore<CTimeModelInfo, TIMEMODELSIZE> CModelInfo::ms_timeModelStore;
CStore<CClumpModelInfo, CLUMPMODELSIZE> CModelInfo::ms_clumpModelStore;
CStore<CPedModelInfo, PEDMODELSIZE> CModelInfo::ms_pedModelStore;
CStore<CVehicleModelInfo, VEHICLEMODELSIZE> CModelInfo::ms_vehicleModelStore;
CStore<C2dEffect, TWODFXSIZE> CModelInfo::ms_2dEffectStore;

void
CModelInfo::Initialise(void)
{
	int i;
	for(i = 0; i < MODELINFOSIZE; i++)
		ms_modelInfoPtrs[i] = nil;
	ms_2dEffectStore.clear();
	ms_simpleModelStore.clear();
	ms_timeModelStore.clear();
	ms_clumpModelStore.clear();
	ms_pedModelStore.clear();
	ms_vehicleModelStore.clear();
}

void
CModelInfo::Shutdown(void)
{
	int i;
	for(i = 0; i < ms_simpleModelStore.allocPtr; i++)
		ms_simpleModelStore.store[i].Shutdown();
	for(i = 0; i < ms_timeModelStore.allocPtr; i++)
		ms_timeModelStore.store[i].Shutdown();
	for(i = 0; i < ms_clumpModelStore.allocPtr; i++)
		ms_clumpModelStore.store[i].Shutdown();
	for(i = 0; i < ms_pedModelStore.allocPtr; i++)
		ms_pedModelStore.store[i].Shutdown();
	for(i = 0; i < ms_vehicleModelStore.allocPtr; i++)
		ms_vehicleModelStore.store[i].Shutdown();
}

CSimpleModelInfo*
CModelInfo::AddSimpleModel(int id)
{
	CSimpleModelInfo *modelinfo;
	modelinfo = CModelInfo::ms_simpleModelStore.alloc();
	CModelInfo::ms_modelInfoPtrs[id] = modelinfo;
	modelinfo->Init();
	return modelinfo;
}

CTimeModelInfo*
CModelInfo::AddTimeModel(int id)
{
	CTimeModelInfo *modelinfo;
	modelinfo = CModelInfo::ms_timeModelStore.alloc();
	CModelInfo::ms_modelInfoPtrs[id] = modelinfo;
	modelinfo->Init();
	return modelinfo;
}

CClumpModelInfo*
CModelInfo::AddClumpModel(int id)
{
	CClumpModelInfo *modelinfo;
	modelinfo = CModelInfo::ms_clumpModelStore.alloc();
	CModelInfo::ms_modelInfoPtrs[id] = modelinfo;
	modelinfo->m_clump = nil;
	return modelinfo;
}

CPedModelInfo*
CModelInfo::AddPedModel(int id)
{
	CPedModelInfo *modelinfo;
	modelinfo = CModelInfo::ms_pedModelStore.alloc();
	CModelInfo::ms_modelInfoPtrs[id] = modelinfo;
	modelinfo->m_clump = nil;
	return modelinfo;
}

CVehicleModelInfo*
CModelInfo::AddVehicleModel(int id)
{
	CVehicleModelInfo *modelinfo;
	modelinfo = CModelInfo::ms_vehicleModelStore.alloc();
	CModelInfo::ms_modelInfoPtrs[id] = modelinfo;
	modelinfo->m_clump = nil;
	modelinfo->m_vehicleType = -1;
	modelinfo->m_wheelId = -1;
	modelinfo->m_materials1[0] = nil;
	modelinfo->m_materials2[0] = nil;
	modelinfo->m_bikeSteerAngle = 999.99f;
	return modelinfo;
}

CBaseModelInfo*
CModelInfo::GetModelInfo(const char *name, int *id)
{
	CBaseModelInfo *modelinfo;
	for(int i = 0; i < MODELINFOSIZE; i++){
		modelinfo = CModelInfo::ms_modelInfoPtrs[i];
	 	if(modelinfo && _strcmpi(modelinfo->GetName(), name) == 0){
			if(id)
				*id = i;
			return modelinfo;
		}
	}
	return nil;
}

STARTPATCHES
//	InjectHook(0x50B920, CModelInfo::AddSimpleModel, PATCH_JUMP);
//	InjectHook(0x50B9C0, CModelInfo::AddTimeModel, PATCH_JUMP);
//	InjectHook(0x50BA10, CModelInfo::AddClumpModel, PATCH_JUMP);
//	InjectHook(0x50BAD0, CModelInfo::AddPedModel, PATCH_JUMP);
//	InjectHook(0x50BA60, CModelInfo::AddPedModel, PATCH_JUMP);
	InjectHook(0x50B860, (CBaseModelInfo *(*)(const char*, int*))CModelInfo::GetModelInfo, PATCH_JUMP);
ENDPATCHES