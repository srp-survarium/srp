void __thiscall SpeedTree::CArray<SpeedTree::CInstance,1>::clear(SpeedTree::CArray<SpeedTree::CInstance,1> *this)
{
  SpeedTree::CInstance *pRawBlock; // [esp+8h] [ebp-4h] BYREF

  if ( !this->m_bExternalMemory )
  {
    pRawBlock = this->m_pData;
    SpeedTree::st_delete_array<SpeedTree::CInstance>(&pRawBlock);
    this->m_pData = 0;
    this->m_uiDataSize = 0;
  }
  this->m_uiSize = 0;
}
