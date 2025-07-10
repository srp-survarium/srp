void __thiscall btUnionFind::sortIslands(btUnionFind *this)
{
  int m_size; // eax
  int v2; // edi
  int v3; // ebx
  int v4; // edx
  int v5; // eax
  btElement *m_data; // edx
  int m_id; // esi
  int v8; // eax
  int numElements; // [esp+4h] [ebp-4h]

  m_size = this->m_elements.m_size;
  v2 = 0;
  for ( numElements = m_size; v2 < m_size; this->m_elements.m_data[v3].m_id = v4 )
  {
    v3 = v2;
    v4 = v2;
    if ( v2 != this->m_elements.m_data[v2].m_id )
    {
      v5 = v2;
      do
      {
        m_data = this->m_elements.m_data;
        m_id = m_data[v5].m_id;
        m_data[v5].m_id = m_data[m_id].m_id;
        v4 = m_data[m_id].m_id;
        v5 = v4;
      }
      while ( v4 != this->m_elements.m_data[v4].m_id );
      m_size = numElements;
    }
    ++v2;
  }
  v8 = this->m_elements.m_size;
  if ( v8 > 1 )
    btAlignedObjectArray<btElement>::quickSortInternal<btUnionFindElementSortPredicate>(&this->m_elements, 0, 0, v8 - 1);
}
