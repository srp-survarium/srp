void __cdecl SpeedTree::st_delete_array<SpeedTree::SInstanceLod>(SpeedTree::SInstanceLod **pRawBlock)
{
  SpeedTree::SLodSnapshot *p_m_sLodSnapshot; // eax

  if ( *pRawBlock )
  {
    p_m_sLodSnapshot = &(*pRawBlock)[-1].m_sLodSnapshot;
    if ( *pRawBlock != (SpeedTree::SInstanceLod *)4 )
    {
      SpeedTree::g_siHeapMemoryUsed += -4 - 32 * *(_DWORD *)p_m_sLodSnapshot;
      if ( SpeedTree::g_pAllocator )
        SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, p_m_sLodSnapshot);
      *pRawBlock = 0;
    }
  }
}
