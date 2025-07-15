SpeedTree::SGeometry *__thiscall SpeedTree::SGeometry::SGeometry(SpeedTree::SGeometry *this)
{
  this->m_nNumMaterials = 0;
  this->m_pMaterials = 0;
  this->m_nNumBranchLods = 0;
  this->m_pBranchLods = 0;
  this->m_nNumFrondLods = 0;
  this->m_pFrondLods = 0;
  this->m_nNumLeafMeshLods = 0;
  this->m_pLeafMeshLods = 0;
  this->m_nNumLeafCardLods = 0;
  this->m_pLeafCardLods = 0;
  SpeedTree::SVerticalBillboards::SVerticalBillboards(&this->m_sVertBBs);
  SpeedTree::SHorizontalBillboard::SHorizontalBillboard(&this->m_sHorzBB);
  this->m_pCompositeIndexedLods = 0;
  return this;
}
