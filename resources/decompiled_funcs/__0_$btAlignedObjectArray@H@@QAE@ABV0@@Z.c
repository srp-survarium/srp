btAlignedObjectArray<btConvexHullInternal::Vertex *> *__userpurge btAlignedObjectArray<int>::btAlignedObjectArray<int>@<eax>(
        btAlignedObjectArray<btConvexHullInternal::Vertex *> *this@<ecx>,
        btAlignedObjectArray<btConvexHullInternal::Vertex *> *a2@<esi>,
        const btAlignedObjectArray<btConvexHullInternal::Vertex *> *otherArray)
{
  const btAlignedObjectArray<btConvexHullInternal::Vertex *> *v3; // edx
  int m_size; // edi
  _DWORD *v5; // eax
  int v6; // edx
  _DWORD *v7; // ebp
  int v8; // eax
  _DWORD *v9; // ecx
  btConvexHullInternal::Vertex **m_data; // eax
  int i; // eax
  btConvexHullInternal::Vertex **v12; // ecx
  btConvexHullInternal::Vertex **v13; // ecx
  int v14; // eax

  v3 = otherArray;
  a2->m_ownsMemory = 1;
  a2->m_data = 0;
  a2->m_size = 0;
  a2->m_capacity = 0;
  m_size = otherArray->m_size;
  if ( m_size >= 0 )
  {
    if ( m_size > 0 )
    {
      ++gNumAlignedAllocs;
      v5 = sAlignedAllocFunc(4 * m_size, 16);
      v6 = a2->m_size;
      v7 = v5;
      v8 = 0;
      if ( v6 > 0 )
      {
        v9 = v7;
        do
        {
          if ( v9 )
            *v9 = a2->m_data[v8];
          ++v8;
          ++v9;
        }
        while ( v8 < v6 );
      }
      m_data = a2->m_data;
      if ( m_data )
      {
        if ( a2->m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(m_data);
        }
        a2->m_data = 0;
      }
      v3 = otherArray;
      a2->m_ownsMemory = 1;
      a2->m_data = (btConvexHullInternal::Vertex **)v7;
      a2->m_capacity = m_size;
    }
    for ( i = 0; i < m_size; ++i )
    {
      v12 = &a2->m_data[i];
      if ( v12 )
        *v12 = 0;
    }
  }
  v13 = a2->m_data;
  v14 = 0;
  for ( a2->m_size = m_size; v14 < m_size; ++v13 )
  {
    if ( v13 )
      *v13 = v3->m_data[v14];
    ++v14;
  }
  return a2;
}
