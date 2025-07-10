bool __thiscall SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::reserve(
        SpeedTree::CArray<SpeedTree::CCore *,1> *this,
        unsigned int uiSize)
{
  SpeedTree::CCore **v4; // eax
  SpeedTree::CCore **v5; // ebx
  SpeedTree::CCore **m_pData; // ecx
  unsigned int v7; // edx
  SpeedTree::CCore **v8; // eax
  _DWORD *v9; // eax

  if ( this->m_bExternalMemory )
    return this->m_uiDataSize >= uiSize;
  if ( uiSize > this->m_uiDataSize )
  {
    v4 = SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::Allocate(this, uiSize);
    v5 = v4;
    if ( this->m_uiSize )
    {
      m_pData = this->m_pData;
      v7 = 0;
      do
      {
        *v4 = *m_pData;
        ++v7;
        ++v4;
        ++m_pData;
      }
      while ( v7 < this->m_uiSize );
    }
    v8 = this->m_pData;
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( v9 )
      {
        SpeedTree::g_siHeapMemoryUsed += -4 - 4 * *v9;
        if ( SpeedTree::g_pAllocator )
          SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, v9);
      }
    }
    this->m_pData = v5;
    this->m_uiDataSize = uiSize;
  }
  return 1;
}
