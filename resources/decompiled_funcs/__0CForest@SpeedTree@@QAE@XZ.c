SpeedTree::CForest *__thiscall SpeedTree::CForest::CForest(SpeedTree::CForest *this)
{
  SpeedTree::CCellContainer<SpeedTree::CTreeCell> *p_m_cTreeCellMap; // [esp+14h] [ebp-18h]

  this->__vftable = (SpeedTree::CForest_vtbl *)&SpeedTree::CForest::`vftable';
  this->m_aBaseTrees.__vftable = (SpeedTree::CArray<SpeedTree::CCore *,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CCore *,1>::`vftable';
  this->m_aBaseTrees.m_pData = 0;
  this->m_aBaseTrees.m_uiSize = 0;
  this->m_aBaseTrees.m_uiDataSize = 0;
  this->m_aBaseTrees.m_bExternalMemory = 0;
  this->m_bBaseTreesChanged = 1;
  p_m_cTreeCellMap = &this->m_cTreeCellMap;
  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>(0xAu);
  p_m_cTreeCellMap->__vftable = (SpeedTree::CCellContainer<SpeedTree::CTreeCell>_vtbl *)&SpeedTree::CCellContainer<SpeedTree::CTreeCell>::`vftable';
  p_m_cTreeCellMap->m_fCellSize = 1200.0;
  this->m_fLargestInstanceCullRadius = 0.0;
  this->m_nUpdateIndex = 1;
  this->m_bCellDeletedSinceLastCull = 0;
  this->m_aAvailableBillboardVboBlocks.__vftable = (SpeedTree::CArray<int,1>_vtbl *)&SpeedTree::CArray<float,1>::`vftable';
  this->m_aAvailableBillboardVboBlocks.m_pData = 0;
  this->m_aAvailableBillboardVboBlocks.m_uiSize = 0;
  this->m_aAvailableBillboardVboBlocks.m_uiDataSize = 0;
  this->m_aAvailableBillboardVboBlocks.m_bExternalMemory = 0;
  this->m_bWindEnabled = 1;
  this->m_fGlobalWindStrength = 1.0;
  this->m_vWindDir.x = 1.0;
  this->m_vWindDir.y = 0.0;
  this->m_vWindDir.z = 0.0;
  this->m_fGlobalTime = 0.0;
  SpeedTree::CWind::CWind(&this->m_cWindLeader);
  this->m_vLightDir.x = 0.57700002;
  this->m_vLightDir.y = 0.57700002;
  this->m_vLightDir.z = 0.57700002;
  this->m_bLightDirChanged = 1;
  this->m_fShadowFadePercentage = 0.85000002;
  this->m_nHintMaxNumVisibleCells = 50;
  this->m_nHintMaxNumCollisionTrees = 3;
  this->m_afCascadedShadowMapSplits[4] = 1.0;
  this->m_afCascadedShadowMapSplits[3] = this->m_afCascadedShadowMapSplits[4] * 0.5;
  this->m_afCascadedShadowMapSplits[2] = this->m_afCascadedShadowMapSplits[3] * 0.5;
  this->m_afCascadedShadowMapSplits[1] = this->m_afCascadedShadowMapSplits[2] * 0.5;
  this->m_afCascadedShadowMapSplits[0] = 0.0;
  return this;
}
