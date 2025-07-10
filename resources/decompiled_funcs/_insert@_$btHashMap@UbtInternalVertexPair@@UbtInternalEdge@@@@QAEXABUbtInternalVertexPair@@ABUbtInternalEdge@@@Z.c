void __userpurge btHashMap<btInternalVertexPair,btInternalEdge>::insert(
        btHashMap<btInternalVertexPair,btInternalEdge> *this@<ecx>,
        btHashMap<btInternalVertexPair,btInternalEdge> *a2@<eax>,
        const btInternalVertexPair *key,
        const btInternalEdge *value)
{
  const btInternalVertexPair *v4; // ebp
  int v6; // ebx
  int Index; // eax
  int m_size; // edx
  int v9; // ecx
  int v10; // edi
  _DWORD *v11; // ebp
  int v12; // edx
  int v13; // eax
  _DWORD *v14; // ecx
  btInternalEdge *m_data; // eax
  btInternalEdge *v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // edi
  _DWORD *v20; // ebp
  int v21; // edx
  int v22; // eax
  _DWORD *v23; // ecx
  btInternalVertexPair *v24; // eax
  int v25; // ecx
  btInternalVertexPair *v26; // eax
  const btInternalVertexPair *v27; // [esp+0h] [ebp-18h]
  int hash; // [esp+Ch] [ebp-Ch]
  int m_capacity; // [esp+10h] [ebp-8h]
  int count; // [esp+14h] [ebp-4h]

  v4 = key;
  m_capacity = a2->m_valueArray.m_capacity;
  v6 = (m_capacity - 1) & (key->m_v0 + (key->m_v1 << 16));
  hash = v6;
  Index = btHashMap<btInternalVertexPair,btInternalEdge>::findIndex(a2, key);
  if ( Index == -1 )
  {
    m_size = a2->m_valueArray.m_size;
    v9 = a2->m_valueArray.m_capacity;
    count = m_size;
    if ( m_size == v9 )
    {
      v10 = 2 * m_size;
      if ( !m_size )
        v10 = 1;
      if ( v9 < v10 )
      {
        if ( v10 )
        {
          ++gNumAlignedAllocs;
          v11 = sAlignedAllocFunc(4 * v10, 16);
        }
        else
        {
          v11 = 0;
        }
        v12 = a2->m_valueArray.m_size;
        v13 = 0;
        if ( v12 > 0 )
        {
          v14 = v11;
          do
          {
            if ( v14 )
            {
              *v14 = a2->m_valueArray.m_data[v13];
              v6 = hash;
            }
            ++v13;
            ++v14;
          }
          while ( v13 < v12 );
        }
        m_data = a2->m_valueArray.m_data;
        if ( m_data )
        {
          if ( a2->m_valueArray.m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(m_data);
          }
          a2->m_valueArray.m_data = 0;
        }
        a2->m_valueArray.m_data = (btInternalEdge *)v11;
        v4 = key;
        a2->m_valueArray.m_ownsMemory = 1;
        a2->m_valueArray.m_capacity = v10;
      }
    }
    v16 = &a2->m_valueArray.m_data[a2->m_valueArray.m_size];
    if ( v16 )
      *v16 = *value;
    ++a2->m_valueArray.m_size;
    v17 = a2->m_keyArray.m_capacity;
    v18 = a2->m_keyArray.m_size;
    if ( v18 == v17 )
    {
      v19 = 2 * v18;
      if ( !v18 )
        v19 = 1;
      if ( v17 < v19 )
      {
        if ( v19 )
        {
          ++gNumAlignedAllocs;
          v20 = sAlignedAllocFunc(4 * v19, 16);
        }
        else
        {
          v20 = 0;
        }
        v21 = a2->m_keyArray.m_size;
        v22 = 0;
        if ( v21 > 0 )
        {
          v23 = v20;
          do
          {
            if ( v23 )
            {
              *v23 = a2->m_keyArray.m_data[v22];
              v6 = hash;
            }
            ++v22;
            ++v23;
          }
          while ( v22 < v21 );
        }
        v24 = a2->m_keyArray.m_data;
        if ( v24 )
        {
          if ( a2->m_keyArray.m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v24);
          }
          a2->m_keyArray.m_data = 0;
        }
        a2->m_keyArray.m_data = (btInternalVertexPair *)v20;
        v4 = key;
        a2->m_keyArray.m_ownsMemory = 1;
        a2->m_keyArray.m_capacity = v19;
      }
    }
    v25 = a2->m_keyArray.m_size;
    v26 = &a2->m_keyArray.m_data[v25];
    if ( v26 )
    {
      v25 = (int)*v4;
      *v26 = *v4;
    }
    ++a2->m_keyArray.m_size;
    if ( m_capacity < a2->m_valueArray.m_capacity )
    {
      btHashMap<btInternalVertexPair,btInternalEdge>::growTables(
        (btHashMap<btInternalVertexPair,btInternalEdge> *)v25,
        v27);
      v6 = (a2->m_valueArray.m_capacity - 1) & (v4->m_v0 + (v4->m_v1 << 16));
    }
    a2->m_next.m_data[count] = a2->m_hashTable.m_data[v6];
    a2->m_hashTable.m_data[v6] = count;
  }
  else
  {
    a2->m_valueArray.m_data[Index] = *value;
  }
}
