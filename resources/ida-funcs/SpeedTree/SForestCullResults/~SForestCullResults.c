void __thiscall SpeedTree::SForestCullResults::~SForestCullResults(SpeedTree::SForestCullResults *this)
{
  SpeedTree::CArray<void *,1> *v2; // ecx
  SpeedTree::CArray<SpeedTree::CTreeCell *,1> *p_m_aPreviousVisibleCells; // esi
  SpeedTree::CArray<void *,1> *v4; // ecx
  SpeedTree::CArray<SpeedTree::CTreeCell *,1> *p_m_aNewVisibleCells; // esi

  this->__vftable = (SpeedTree::SForestCullResults_vtbl *)&SpeedTree::SForestCullResults::`vftable';
  SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::~CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>(&this->m_m3dInstances);
  p_m_aPreviousVisibleCells = &this->m_aPreviousVisibleCells;
  this->m_aPreviousVisibleCells.__vftable = (SpeedTree::CArray<SpeedTree::CTreeCell *,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CTreeCell *,1>::`vftable';
  if ( this->m_aPreviousVisibleCells.m_bExternalMemory )
  {
    SpeedTree::CArray<void *,1>::clear(v2, (int)p_m_aPreviousVisibleCells);
    if ( this->m_aPreviousVisibleCells.m_bExternalMemory )
    {
      this->m_aPreviousVisibleCells.m_uiDataSize = 0;
      this->m_aPreviousVisibleCells.m_pData = 0;
    }
    this->m_aPreviousVisibleCells.m_bExternalMemory = 0;
  }
  SpeedTree::CArray<void *,1>::clear(v2, (int)p_m_aPreviousVisibleCells);
  p_m_aNewVisibleCells = &this->m_aNewVisibleCells;
  this->m_aNewVisibleCells.__vftable = (SpeedTree::CArray<SpeedTree::CTreeCell *,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CTreeCell *,1>::`vftable';
  if ( this->m_aNewVisibleCells.m_bExternalMemory )
  {
    SpeedTree::CArray<void *,1>::clear(v4, (int)p_m_aNewVisibleCells);
    if ( this->m_aNewVisibleCells.m_bExternalMemory )
    {
      this->m_aNewVisibleCells.m_uiDataSize = 0;
      this->m_aNewVisibleCells.m_pData = 0;
    }
    this->m_aNewVisibleCells.m_bExternalMemory = 0;
  }
  SpeedTree::CArray<void *,1>::clear(v4, (int)p_m_aNewVisibleCells);
  this->m_aVisibleCells.__vftable = (SpeedTree::CArray<SpeedTree::CTreeCell const *,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::`vftable';
  if ( this->m_aVisibleCells.m_bExternalMemory )
  {
    SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::clear((SpeedTree::CArray<SpeedTree::CCore *,1> *)&this->m_aVisibleCells);
    if ( this->m_aVisibleCells.m_bExternalMemory )
    {
      this->m_aVisibleCells.m_uiDataSize = 0;
      this->m_aVisibleCells.m_pData = 0;
    }
    this->m_aVisibleCells.m_bExternalMemory = 0;
  }
  SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::clear((SpeedTree::CArray<SpeedTree::CCore *,1> *)&this->m_aVisibleCells);
}
