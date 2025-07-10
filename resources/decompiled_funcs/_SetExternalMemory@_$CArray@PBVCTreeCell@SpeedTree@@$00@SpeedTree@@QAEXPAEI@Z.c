void __thiscall SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::SetExternalMemory(
        SpeedTree::CArray<SpeedTree::CCore *,1> *this,
        unsigned __int8 *pMemory,
        unsigned int uiSize)
{
  SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::clear(this);
  if ( this->m_bExternalMemory )
  {
    this->m_uiDataSize = 0;
    this->m_pData = 0;
  }
  if ( pMemory )
  {
    this->m_uiDataSize = uiSize >> 2;
    this->m_pData = (SpeedTree::CCore **)pMemory;
    this->m_bExternalMemory = 1;
  }
  else
  {
    this->m_bExternalMemory = 0;
  }
}
