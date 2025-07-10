void __thiscall SpeedTree::CBlockPool<1>::clear(SpeedTree::CBlockPool<1> *this, bool bForce)
{
  char *m_pData; // eax
  char *v4; // eax

  m_pData = this->m_pData;
  if ( m_pData )
  {
    v4 = m_pData - 4;
    if ( v4 )
    {
      SpeedTree::g_siHeapMemoryUsed += -4 - *(_DWORD *)v4;
      if ( SpeedTree::g_pAllocator )
        SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, v4);
      this->m_pData = 0;
    }
  }
  SpeedTree::st_delete_array<unsigned int>((void ***)&this->m_pFreeLocations);
  this->m_pFreeLocations = 0;
  this->m_pData = 0;
  this->m_uiSize = 0;
  this->m_uiCurrent = 0;
}
