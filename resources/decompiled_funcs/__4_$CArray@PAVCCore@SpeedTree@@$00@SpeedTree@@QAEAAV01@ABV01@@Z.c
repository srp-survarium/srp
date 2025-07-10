SpeedTree::CArray<SpeedTree::CCore *,1> *__userpurge SpeedTree::CArray<SpeedTree::CCore *,1>::operator=@<eax>(
        SpeedTree::CArray<SpeedTree::CCore *,1> *this@<ecx>,
        SpeedTree::CArray<SpeedTree::CCore *,1> *a2@<esi>,
        const SpeedTree::CArray<SpeedTree::CCore *,1> *cRight)
{
  unsigned int m_uiSize; // eax
  unsigned int m_uiDataSize; // ecx
  SpeedTree::CCore **v5; // edi
  SpeedTree::CCore **m_pData; // eax
  _DWORD *v7; // eax
  SpeedTree::CCore **v8; // eax
  SpeedTree::CCore **v9; // ecx
  unsigned int v10; // edx

  m_uiSize = cRight->m_uiSize;
  if ( a2->m_bExternalMemory )
  {
    m_uiDataSize = a2->m_uiDataSize;
    a2->m_uiSize = m_uiSize;
    if ( m_uiSize > m_uiDataSize )
      a2->m_uiSize = m_uiDataSize;
  }
  else
  {
    if ( m_uiSize > a2->m_uiDataSize )
    {
      v5 = SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::Allocate(a2, cRight->m_uiSize);
      m_pData = a2->m_pData;
      if ( m_pData )
      {
        v7 = m_pData - 1;
        if ( v7 )
        {
          SpeedTree::g_siHeapMemoryUsed += -4 - 4 * *v7;
          if ( SpeedTree::g_pAllocator )
            SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, v7);
        }
      }
      a2->m_pData = v5;
      a2->m_uiDataSize = cRight->m_uiSize;
    }
    a2->m_uiSize = cRight->m_uiSize;
  }
  if ( a2->m_uiSize )
  {
    v8 = a2->m_pData;
    v9 = cRight->m_pData;
    v10 = 0;
    do
    {
      *v8 = *v9;
      ++v10;
      ++v8;
      ++v9;
    }
    while ( v10 < a2->m_uiSize );
  }
  return a2;
}
