void __thiscall SpeedTree::CBlockPool<1>::resize(SpeedTree::CBlockPool<1> *this, unsigned int uiSize)
{
  unsigned __int8 *v4; // ebx
  unsigned __int8 *m_pData; // eax
  unsigned __int8 *m_pFreeLocations; // eax
  unsigned int m_uiCurrent; // ecx
  unsigned int i; // eax
  char *pNewData; // [esp+Ch] [ebp+4h]

  if ( uiSize != this->m_uiSize )
  {
    pNewData = SpeedTree::st_new_array<char>(uiSize * this->m_uiBlockSize + 4);
    v4 = (unsigned __int8 *)SpeedTree::st_new_array<unsigned int>(uiSize);
    m_pData = (unsigned __int8 *)this->m_pData;
    if ( m_pData )
    {
      memcpy((unsigned __int8 *)pNewData, m_pData, this->m_uiSize * this->m_uiBlockSize);
      SpeedTree::st_delete_array<char>(&this->m_pData);
    }
    m_pFreeLocations = (unsigned __int8 *)this->m_pFreeLocations;
    if ( m_pFreeLocations )
    {
      m_uiCurrent = this->m_uiCurrent;
      if ( m_uiCurrent )
        memcpy(v4, m_pFreeLocations, 4 * m_uiCurrent);
      SpeedTree::st_delete_array<unsigned int>((void ***)&this->m_pFreeLocations);
    }
    for ( i = this->m_uiSize; i < uiSize; ++i )
      *(_DWORD *)&v4[4 * this->m_uiCurrent++] = i * this->m_uiBlockSize + 4;
    this->m_pData = pNewData;
    this->m_pFreeLocations = (unsigned int *)v4;
    this->m_uiSize = uiSize;
  }
}
