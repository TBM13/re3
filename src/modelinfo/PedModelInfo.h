#pragma once

#include "ClumpModelInfo.h"

enum PedNode {
	PED_WAIST,
	PED_TORSO,	// Smid on PS2/PC, Storso on mobile/xbox
	PED_HEAD,
	PED_UPPERARML,
	PED_UPPERARMR,
	PED_HANDL,
	PED_HANDR,
	PED_UPPERLEGL,
	PED_UPPERLEGR,
	PED_FOOTL,
	PED_FOOTR,
	PED_LOWERLEGR,
	// This is not valid apparently
	PED_LOWERLEGL,
};

class CPedModelInfo : public CClumpModelInfo
{
public:
	void *m_animGroup;	// TODO
	int32 m_pedType;
	int32 m_pedStatType;
	uint32 m_carsCanDrive;
	CColModel *m_hitColModel;
	RpAtomic *m_head;
	RpAtomic *m_lhand;
	RpAtomic *m_rhand;

	static RwObjectNameIdAssocation m_pPedIds[12];

	CPedModelInfo(void) : CClumpModelInfo(MITYPE_PED) { }
	void DeleteRwObject(void);
	void SetClump(RpClump *);

	void SetLowDetailClump(RpClump*);
	void CreateHitColModel(void);


	void DeleteRwObject_(void) { this->CPedModelInfo::DeleteRwObject(); }
	void SetClump_(RpClump *clump) { this->CPedModelInfo::SetClump(clump); }
};
static_assert(sizeof(CPedModelInfo) == 0x54, "CPedModelInfo: error");