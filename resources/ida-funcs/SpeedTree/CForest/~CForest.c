void __thiscall SpeedTree::CForest::~CForest(SpeedTree::CForest *this)
{
  SpeedTree::CArray<SpeedTree::CCore *,1> *p_m_aBaseTrees; // [esp+8h] [ebp-6Ch]
  signed int i; // [esp+64h] [ebp-10h]

  this->__vftable = (SpeedTree::CForest_vtbl *)&SpeedTree::CForest::`vftable';
  for ( i = 0; i < (signed int)this->m_aBaseTrees.m_uiSize; ++i )
    SpeedTree::st_delete<SpeedTree::CCore>(&this->m_aBaseTrees.m_pData[i]);
  SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr((SpeedTree::CCellBaseTreeItr *)&this->m_cWindLeader);
  this->m_aAvailableBillboardVboBlocks.__vftable = (SpeedTree::CArray<int,1>_vtbl *)&SpeedTree::CArray<float,1>::`vftable';
  if ( this->m_aAvailableBillboardVboBlocks.m_bExternalMemory )
    SpeedTree::CArray<float,1>::SetExternalMemory(0, 0);
  SpeedTree::CArray<int,1>::clear(&this->m_aAvailableBillboardVboBlocks);
  this->m_cTreeCellMap.__vftable = (SpeedTree::CCellContainer<SpeedTree::CTreeCell>_vtbl *)&SpeedTree::CCellContainer<SpeedTree::CTreeCell>::`vftable';
  this->m_cTreeCellMap.__vftable = (SpeedTree::CCellContainer<SpeedTree::CTreeCell>_vtbl *)&SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::`vftable';
  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::clear(&this->m_cTreeCellMap);
  this->m_cTreeCellMap.m_cPool.__vftable = (SpeedTree::CBlockPool<1>_vtbl *)&SpeedTree::CBlockPool<1>::`vftable';
  SpeedTree::CBlockPool<1>::clear(&this->m_cTreeCellMap.m_cPool, 0);
  p_m_aBaseTrees = &this->m_aBaseTrees;
  this->m_aBaseTrees.__vftable = (SpeedTree::CArray<SpeedTree::CCore *,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CCore *,1>::`vftable';
  if ( this->m_aBaseTrees.m_bExternalMemory )
    SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::SetExternalMemory(p_m_aBaseTrees, 0, 0);
  SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::clear(p_m_aBaseTrees);
}
