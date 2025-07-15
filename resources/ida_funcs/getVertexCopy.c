int __usercall getVertexCopy@<eax>(
        btAlignedObjectArray<btConvexHullInternal::Vertex *> *vertices@<esi>,
        btConvexHullInternal::Vertex *vertex)
{
  btConvexHullInternal::Vertex *v2; // edx
  int result; // eax
  int m_size; // ebx
  int m_capacity; // ecx
  int v6; // eax
  int v7; // edi
  btConvexHullInternal::Vertex **v8; // ebp
  int v9; // edx
  int v10; // eax
  btConvexHullInternal::Vertex **v11; // ecx
  btConvexHullInternal::Vertex **m_data; // eax
  btConvexHullInternal::Vertex **v13; // eax

  v2 = vertex;
  result = vertex->copy;
  if ( result < 0 )
  {
    m_size = vertices->m_size;
    vertex->copy = m_size;
    m_capacity = vertices->m_capacity;
    v6 = vertices->m_size;
    if ( v6 == m_capacity )
    {
      v7 = 2 * v6;
      if ( !v6 )
        v7 = 1;
      if ( m_capacity < v7 )
      {
        if ( v7 )
        {
          ++gNumAlignedAllocs;
          v8 = (btConvexHullInternal::Vertex **)sAlignedAllocFunc(4 * v7, 16);
        }
        else
        {
          v8 = 0;
        }
        v9 = vertices->m_size;
        v10 = 0;
        if ( v9 > 0 )
        {
          v11 = v8;
          do
          {
            if ( v11 )
              *v11 = vertices->m_data[v10];
            ++v10;
            ++v11;
          }
          while ( v10 < v9 );
        }
        m_data = vertices->m_data;
        if ( m_data )
        {
          if ( vertices->m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(m_data);
          }
          vertices->m_data = 0;
        }
        v2 = vertex;
        vertices->m_data = v8;
        vertices->m_ownsMemory = 1;
        vertices->m_capacity = v7;
      }
    }
    v13 = &vertices->m_data[vertices->m_size];
    if ( v13 )
      *v13 = v2;
    ++vertices->m_size;
    return m_size;
  }
  return result;
}
