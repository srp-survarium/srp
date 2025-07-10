void __thiscall SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::clear(SpeedTree::CArray<SpeedTree::CCore *,1> *this)
{
  SpeedTree::CCore **m_pData; // eax
  _DWORD *v3; // eax

  if ( !this->m_bExternalMemory )
  {
    m_pData = this->m_pData;
    if ( m_pData )
    {
      v3 = m_pData - 1;
      if ( v3 )
      {
        SpeedTree::g_siHeapMemoryUsed += -4 - 4 * *v3;
        if ( SpeedTree::g_pAllocator )
          SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, v3);
      }
    }
    this->m_pData = 0;
    this->m_uiDataSize = 0;
  }
  this->m_uiSize = 0;
}
