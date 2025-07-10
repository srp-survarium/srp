void __cdecl SpeedTree::st_delete_array<SpeedTree::CInstance>(SpeedTree::CInstance **pRawBlock)
{
  SpeedTree::CCellBaseTreeItr *v1; // edi
  unsigned int *p_m_pCell; // ebx
  unsigned int v3; // eax
  unsigned int v4; // esi

  v1 = (SpeedTree::CCellBaseTreeItr *)*pRawBlock;
  if ( *pRawBlock )
  {
    p_m_pCell = (unsigned int *)&v1[-1].m_pCell;
    if ( v1 != (SpeedTree::CCellBaseTreeItr *)4 )
    {
      v3 = *p_m_pCell;
      SpeedTree::g_siHeapMemoryUsed += -4 - 36 * *p_m_pCell;
      v4 = 0;
      if ( v3 )
      {
        do
        {
          SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr(v1);
          ++v4;
          v1 += 3;
        }
        while ( v4 < *p_m_pCell );
      }
      if ( SpeedTree::g_pAllocator )
        SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, p_m_pCell);
      *pRawBlock = 0;
    }
  }
}
