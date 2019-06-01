#pragma once

#include "BaseModelInfo.h"

class CSimpleModelInfo : public CBaseModelInfo
{
public:
	// atomics[2] is often a pointer to the non-LOD modelinfo
	RpAtomic *m_atomics[3];
	// m_lodDistances[2] holds the near distance for LODs
	float  m_lodDistances[3];
	uint8  m_numAtomics;
	uint8  m_alpha;
	uint16 m_furthest      : 2; // 0: numAtomics-1 is furthest visible
	                         // 1: atomic 0 is furthest
	                         // 2: atomic 1 is furthest
	uint16  m_normalCull    : 1;
	uint16  m_isDamaged     : 1;
	uint16  m_isBigBuilding : 1;
	uint16  m_noFade        : 1;
	uint16  m_drawLast      : 1;
	uint16  m_additive      : 1;
	uint16  m_isSubway      : 1;
	uint16  m_ignoreLight   : 1;
	uint16  m_noZwrite      : 1;

	CSimpleModelInfo(void) : CBaseModelInfo(MITYPE_SIMPLE) {}
	CSimpleModelInfo(ModeInfoType id) : CBaseModelInfo(id) {}
	~CSimpleModelInfo() {}
	void DeleteRwObject(void);
	RwObject *CreateInstance(void);
	RwObject *CreateInstance(RwMatrix *);
	RwObject *GetRwObject(void) { return (RwObject*)m_atomics[0]; }

	void Init(void);
	void IncreaseAlpha(void);
	void SetAtomic(int n, RpAtomic *atomic);
	void SetLodDistances(float *dist);
	float GetLodDistance(int i) { return m_lodDistances[i]; }
	float GetNearDistance(void);
	float GetLargestLodDistance(void);
	RpAtomic *GetAtomicFromDistance(float dist);
	void FindRelatedModel(void);
	void SetupBigBuilding(void);

	void SetNumAtomics(int n) { m_numAtomics = n; }
	CSimpleModelInfo *GetRelatedModel(void){
		return (CSimpleModelInfo*)m_atomics[2]; }
	void SetRelatedModel(CSimpleModelInfo *m){
		m_atomics[2] = (RpAtomic*)m; }

	void DeleteRwObject_(void) { this->CSimpleModelInfo::DeleteRwObject(); }
	RwObject *CreateInstance_1(void) { return this->CSimpleModelInfo::CreateInstance(); }
	RwObject *CreateInstance_2(RwMatrix *m) { return this->CSimpleModelInfo::CreateInstance(m); }
	RwObject *GetRwObject_(void) { return this->CSimpleModelInfo::GetRwObject(); }
};
static_assert(sizeof(CSimpleModelInfo) == 0x4C, "CSimpleModelInfo: error");