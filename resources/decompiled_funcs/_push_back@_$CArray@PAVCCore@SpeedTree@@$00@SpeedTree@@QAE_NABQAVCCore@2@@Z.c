char __thiscall SpeedTree::CArray<SpeedTree::CCore *,1>::push_back(
        SpeedTree::CArray<SpeedTree::CCore *,1> *this,
        SpeedTree::CCore *const *tNew)
{
  unsigned int m_uiSize; // eax
  unsigned int m_uiDataSize; // eax

  if ( this->m_bExternalMemory )
  {
    m_uiSize = this->m_uiSize;
    if ( m_uiSize >= this->m_uiDataSize )
    {
      return 0;
    }
    else
    {
      this->m_pData[m_uiSize] = *tNew;
      ++this->m_uiSize;
      return 1;
    }
  }
  else
  {
    m_uiDataSize = this->m_uiDataSize;
    if ( this->m_uiSize == m_uiDataSize )
    {
      if ( m_uiDataSize < 8 )
        this->m_uiDataSize = 8;
      SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::reserve(this, 2 * this->m_uiDataSize + 1);
    }
    this->m_pData[this->m_uiSize++] = *tNew;
    return 1;
  }
}
