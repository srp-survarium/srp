char __thiscall SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::push_back(
        SpeedTree::CArray<SpeedTree::CCore *,1> *this,
        SpeedTree::CCore **a2)
{
  char v4; // [esp+47h] [ebp-1h]

  v4 = 1;
  if ( this->m_bExternalMemory )
  {
    if ( this->m_uiSize >= this->m_uiDataSize )
      return 0;
    else
      this->m_pData[this->m_uiSize++] = *a2;
  }
  else
  {
    if ( this->m_uiSize == this->m_uiDataSize )
    {
      if ( this->m_uiDataSize < 8 )
        this->m_uiDataSize = 8;
      SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::reserve(this, 2 * this->m_uiDataSize + 1);
    }
    this->m_pData[this->m_uiSize++] = *a2;
  }
  return v4;
}
