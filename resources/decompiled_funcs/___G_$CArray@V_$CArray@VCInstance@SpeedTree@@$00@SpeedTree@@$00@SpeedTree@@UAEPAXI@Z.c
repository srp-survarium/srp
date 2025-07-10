SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *__thiscall SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::`scalar deleting destructor'(
        SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *this,
        char a2)
{
  SpeedTree::CArray<SpeedTree::CInstance,1> *pRawBlock; // [esp+8h] [ebp-4h] BYREF

  this->__vftable = (SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::`vftable';
  if ( !this->m_bExternalMemory
    || (SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::SetExternalMemory(this, (int)this),
        !this->m_bExternalMemory) )
  {
    pRawBlock = this->m_pData;
    SpeedTree::st_delete_array<SpeedTree::CArray<SpeedTree::CInstance,1>>(&pRawBlock);
    this->m_pData = 0;
    this->m_uiDataSize = 0;
  }
  this->m_uiSize = 0;
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
