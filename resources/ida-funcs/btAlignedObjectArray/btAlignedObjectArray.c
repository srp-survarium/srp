btAlignedObjectArray<int> *__userpurge btAlignedObjectArray<int>::btAlignedObjectArray<int>@<eax>(
        btAlignedObjectArray<int> *this@<ecx>,
        btAlignedObjectArray<int> *a2@<esi>,
        const btAlignedObjectArray<int> *otherArray)
{
  int m_size; // edi
  int *v4; // edx
  int v5; // eax
  int v6; // ecx
  int j; // ecx
  int *v8; // eax
  int *m_data; // ecx
  int v10; // eax
  int *i; // [esp+8h] [ebp-4h]

  a2->m_ownsMemory = 1;
  a2->m_data = 0;
  a2->m_size = 0;
  a2->m_capacity = 0;
  m_size = otherArray->m_size;
  if ( m_size >= 0 )
  {
    if ( m_size > 0 )
    {
      v4 = (int *)btAlignedAllocInternal(4 * m_size);
      v5 = a2->m_size;
      v6 = 0;
      for ( i = v4; v6 < v5; ++v4 )
      {
        if ( v4 )
          *v4 = a2->m_data[v6];
        ++v6;
      }
      if ( a2->m_data )
      {
        if ( a2->m_ownsMemory )
          btAlignedFreeInternal(a2->m_data);
        a2->m_data = 0;
      }
      a2->m_ownsMemory = 1;
      a2->m_data = i;
      a2->m_capacity = m_size;
    }
    for ( j = 0; j < m_size; ++j )
    {
      v8 = &a2->m_data[j];
      if ( v8 )
        *v8 = 0;
    }
  }
  m_data = a2->m_data;
  v10 = 0;
  for ( a2->m_size = m_size; v10 < m_size; ++m_data )
  {
    if ( m_data )
      *m_data = otherArray->m_data[v10];
    ++v10;
  }
  return a2;
}
