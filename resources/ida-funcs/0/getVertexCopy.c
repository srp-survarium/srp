int __usercall getVertexCopy@<eax>(
        btAlignedObjectArray<btConvexHullInternal::Vertex *> *vertices@<esi>,
        btConvexHullInternal::Vertex *vertex)
{
  btConvexHullInternal::Vertex *v2; // edx
  int copy; // ebx
  int m_capacity; // ecx
  int m_size; // eax
  int v6; // edi
  int v7; // edx
  int v8; // ecx
  btConvexHullInternal::Vertex **v9; // eax
  btConvexHullInternal::Vertex **v10; // eax
  int v12; // [esp+4h] [ebp-8h]
  btConvexHullInternal::Vertex **v13; // [esp+8h] [ebp-4h]

  v2 = vertex;
  copy = vertex->copy;
  if ( copy < 0 )
  {
    copy = vertices->m_size;
    vertex->copy = copy;
    m_capacity = vertices->m_capacity;
    m_size = vertices->m_size;
    v12 = copy;
    if ( m_size == m_capacity )
    {
      v6 = m_size ? 2 * m_size : 1;
      if ( m_capacity < v6 )
      {
        if ( v6 )
          v13 = (btConvexHullInternal::Vertex **)btAlignedAllocInternal(4 * v6);
        else
          v13 = 0;
        v7 = vertices->m_size;
        v8 = 0;
        if ( v7 > 0 )
        {
          v9 = v13;
          do
          {
            if ( v9 )
            {
              *v9 = vertices->m_data[v8];
              copy = v12;
            }
            ++v8;
            ++v9;
          }
          while ( v8 < v7 );
        }
        if ( vertices->m_data )
        {
          if ( vertices->m_ownsMemory )
            btAlignedFreeInternal(vertices->m_data);
          vertices->m_data = 0;
        }
        v2 = vertex;
        vertices->m_ownsMemory = 1;
        vertices->m_data = v13;
        vertices->m_capacity = v6;
      }
    }
    v10 = &vertices->m_data[vertices->m_size];
    if ( v10 )
      *v10 = v2;
    ++vertices->m_size;
  }
  return copy;
}
