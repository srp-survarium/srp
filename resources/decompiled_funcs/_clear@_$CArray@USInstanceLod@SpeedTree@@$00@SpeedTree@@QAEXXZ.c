void __thiscall SpeedTree::CArray<SpeedTree::SInstanceLod,1>::clear(SpeedTree::CArray<SpeedTree::SInstanceLod,1> *this)
{
  SpeedTree::SInstanceLod *m_pData; // eax
  SpeedTree::SLodSnapshot *p_m_sLodSnapshot; // eax

  if ( !this->m_bExternalMemory )
  {
    m_pData = this->m_pData;
    if ( m_pData )
    {
      p_m_sLodSnapshot = &m_pData[-1].m_sLodSnapshot;
      if ( p_m_sLodSnapshot )
      {
        SpeedTree::g_siHeapMemoryUsed += -4 - 32 * *(_DWORD *)p_m_sLodSnapshot;
        if ( SpeedTree::g_pAllocator )
          SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, p_m_sLodSnapshot);
      }
    }
    this->m_pData = 0;
    this->m_uiDataSize = 0;
  }
  this->m_uiSize = 0;
}
