bool __thiscall SpeedTree::CForest::InitBillboardSystem(SpeedTree::CForest *this)
{
  char v3; // [esp+7h] [ebp-51h]
  int m_nHintMaxNumVisibleCells; // [esp+8h] [ebp-50h]
  SpeedTree::CArray<int,1> *p_m_aAvailableBillboardVboBlocks; // [esp+Ch] [ebp-4Ch]
  int i; // [esp+50h] [ebp-8h]

  m_nHintMaxNumVisibleCells = this->m_nHintMaxNumVisibleCells;
  p_m_aAvailableBillboardVboBlocks = &this->m_aAvailableBillboardVboBlocks;
  if ( (unsigned __int8)SpeedTree::CArray<int,1>::reserve(m_nHintMaxNumVisibleCells) )
  {
    p_m_aAvailableBillboardVboBlocks->m_uiSize = m_nHintMaxNumVisibleCells;
    v3 = 1;
  }
  else
  {
    p_m_aAvailableBillboardVboBlocks->m_uiSize = p_m_aAvailableBillboardVboBlocks->m_uiDataSize;
    v3 = 0;
  }
  if ( v3 )
  {
    for ( i = 0; i < this->m_nHintMaxNumVisibleCells; ++i )
      this->m_aAvailableBillboardVboBlocks.m_pData[i] = this->m_nHintMaxNumVisibleCells - i - 1;
  }
  return 0;
}
