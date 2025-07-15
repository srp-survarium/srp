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


void __userpurge btHashMap<btHashPtr,btCollisionShape *>::insert(
        btHashMap<btHashPtr,int> *this@<ecx>,
        btHashMap<btHashPtr,int> *a2@<eax>,
        const btHashPtr *key,
        int *value)
{
  const btHashPtr *v4; // ebp
  int v6; // edi
  int Index; // eax
  int m_size; // eax
  int v9; // ecx
  int v10; // ebx
  int v11; // edx
  int v12; // eax
  _DWORD *v13; // ecx
  int *m_data; // eax
  int *v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // ebx
  int v19; // ebp
  int v20; // eax
  int *v21; // ecx
  btHashPtr *v22; // edx
  btHashPtr *v23; // eax
  int v24; // ecx
  int *v25; // eax
  int v26; // ecx
  int v27; // edx
  _DWORD *v28; // [esp+Ch] [ebp-Ch]
  int v29; // [esp+Ch] [ebp-Ch]
  int m_capacity; // [esp+10h] [ebp-8h]
  int count; // [esp+14h] [ebp-4h]
  const int *valuea; // [esp+20h] [ebp+8h]

  v4 = key;
  m_capacity = a2->m_valueArray.m_capacity;
  v6 = (m_capacity - 1)
     & ((~((((9
            * ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0])
             ^ ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0]) >> 10))) >> 6)
          ^ (9
           * ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0])
            ^ ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0]) >> 10)))) << 11)
       + (((9
          * ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0])
           ^ ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0]) >> 10))) >> 6)
        ^ (9
         * ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0])
          ^ ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0]) >> 10)))))
      ^ ((~((((9
             * ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0])
              ^ ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0]) >> 10))) >> 6)
           ^ (9
            * ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0])
             ^ ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0]) >> 10)))) << 11)
        + (((9
           * ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0])
            ^ ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0]) >> 10))) >> 6)
         ^ (9
          * ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0])
           ^ ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0]) >> 10))))) >> 16));
  Index = btHashMap<btHashPtr,int>::findIndex(a2, key);
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
          v28 = sAlignedAllocFunc(4 * v10, 16);
        }
        else
        {
          v28 = 0;
        }
        v11 = a2->m_valueArray.m_size;
        v12 = 0;
        if ( v11 > 0 )
        {
          v13 = v28;
          do
          {
            if ( v13 )
            {
              *v13 = a2->m_valueArray.m_data[v12];
              v4 = key;
            }
            ++v12;
            ++v13;
          }
          while ( v12 < v11 );
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
        a2->m_valueArray.m_ownsMemory = 1;
        a2->m_valueArray.m_data = v28;
        a2->m_valueArray.m_capacity = v10;
      }
    }
    v15 = &a2->m_valueArray.m_data[a2->m_valueArray.m_size];
    if ( v15 )
      *v15 = *value;
    ++a2->m_valueArray.m_size;
    v16 = a2->m_keyArray.m_capacity;
    v17 = a2->m_keyArray.m_size;
    if ( v17 == v16 )
    {
      if ( v17 )
      {
        v18 = 2 * v17;
        v29 = 2 * v17;
      }
      else
      {
        v18 = 1;
        v29 = 1;
      }
      if ( v16 < v18 )
      {
        if ( v18 )
        {
          ++gNumAlignedAllocs;
          valuea = (const int *)sAlignedAllocFunc(8 * v18, 16);
        }
        else
        {
          valuea = 0;
        }
        v19 = a2->m_keyArray.m_size;
        v20 = 0;
        if ( v19 > 0 )
        {
          v21 = (int *)valuea;
          do
          {
            if ( v21 )
            {
              v22 = a2->m_keyArray.m_data;
              *v21 = v22[v20].m_hashValues[0];
              v18 = v29;
              v21[1] = v22[v20].m_hashValues[1];
            }
            ++v20;
            v21 += 2;
          }
          while ( v20 < v19 );
        }
        v23 = a2->m_keyArray.m_data;
        if ( v23 )
        {
          if ( a2->m_keyArray.m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v23);
          }
          a2->m_keyArray.m_data = 0;
        }
        v4 = key;
        a2->m_keyArray.m_ownsMemory = 1;
        a2->m_keyArray.m_data = (btHashPtr *)valuea;
        a2->m_keyArray.m_capacity = v18;
      }
    }
    v24 = a2->m_keyArray.m_size;
    v25 = (int *)&a2->m_keyArray.m_data[v24];
    if ( v25 )
    {
      v24 = v4->m_hashValues[0];
      *v25 = v4->m_hashValues[0];
      v25[1] = v4->m_hashValues[1];
    }
    ++a2->m_keyArray.m_size;
    if ( m_capacity < a2->m_valueArray.m_capacity )
    {
      btHashMap<btHashPtr,btCollisionShape *>::growTables((btHashMap<btHashPtr,int> *)v24, (int)a2);
      v26 = (9
           * ((~(v4->m_hashValues[0] << 15) + v4->m_hashValues[0])
            ^ ((~(v4->m_hashValues[0] << 15) + v4->m_hashValues[0]) >> 10))) >> 6;
      v27 = ~((v26
             ^ (9
              * ((~(v4->m_hashValues[0] << 15) + v4->m_hashValues[0])
               ^ ((~(v4->m_hashValues[0] << 15) + v4->m_hashValues[0]) >> 10)))) << 11);
      v6 = (a2->m_valueArray.m_capacity - 1)
         & ((v27
           + (v26
            ^ (9
             * ((~(v4->m_hashValues[0] << 15) + v4->m_hashValues[0])
              ^ ((~(v4->m_hashValues[0] << 15) + v4->m_hashValues[0]) >> 10)))))
          ^ ((v27
            + (v26
             ^ (9
              * ((~(v4->m_hashValues[0] << 15) + v4->m_hashValues[0])
               ^ ((~(v4->m_hashValues[0] << 15) + v4->m_hashValues[0]) >> 10))))) >> 16));
    }
    a2->m_next.m_data[count] = a2->m_hashTable.m_data[v6];
    a2->m_hashTable.m_data[v6] = count;
  }
  else
  {
    a2->m_valueArray.m_data[Index] = *value;
  }
}


void __userpurge btHashMap<btHashKey<btTriIndex>,btTriIndex>::insert(
        btHashMap<btHashKey<btTriIndex>,btTriIndex> *this@<ecx>,
        btHashMap<btHashKey<btTriIndex>,btTriIndex> *a2@<eax>,
        const btHashKey<btTriIndex> *key,
        const btTriIndex *value)
{
  int v5; // edi
  int Index; // eax
  int m_size; // edx
  int v8; // ecx
  int v9; // ebx
  int v10; // ebp
  int v11; // eax
  btTriIndex *v12; // ecx
  btTriIndex *m_data; // edx
  btTriIndex *v14; // eax
  btTriIndex *v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // ebx
  btTriIndex *v19; // ebp
  int v20; // edx
  int v21; // eax
  int *p_m_PartIdTriangleIndex; // ecx
  btHashKey<btTriIndex> *v23; // eax
  btHashMap<btHashKey<btTriIndex>,btTriIndex> *m_uid; // ecx
  btHashKey<btTriIndex> *v25; // eax
  int v26; // ecx
  int v27; // edx
  const btHashKey<btTriIndex> *v28; // [esp+0h] [ebp-18h]
  btTriIndex *v29; // [esp+8h] [ebp-10h]
  int v30; // [esp+Ch] [ebp-Ch]
  int m_capacity; // [esp+10h] [ebp-8h]
  int count; // [esp+14h] [ebp-4h]
  const btTriIndex *valuea; // [esp+20h] [ebp+8h]

  m_capacity = a2->m_valueArray.m_capacity;
  v5 = (m_capacity - 1)
     & ((~((((9 * ((~(key->m_uid << 15) + key->m_uid) ^ ((~(key->m_uid << 15) + key->m_uid) >> 10))) >> 6)
          ^ (9 * ((~(key->m_uid << 15) + key->m_uid) ^ ((~(key->m_uid << 15) + key->m_uid) >> 10)))) << 11)
       + (((9 * ((~(key->m_uid << 15) + key->m_uid) ^ ((~(key->m_uid << 15) + key->m_uid) >> 10))) >> 6)
        ^ (9 * ((~(key->m_uid << 15) + key->m_uid) ^ ((~(key->m_uid << 15) + key->m_uid) >> 10)))))
      ^ ((~((((9 * ((~(key->m_uid << 15) + key->m_uid) ^ ((~(key->m_uid << 15) + key->m_uid) >> 10))) >> 6)
           ^ (9 * ((~(key->m_uid << 15) + key->m_uid) ^ ((~(key->m_uid << 15) + key->m_uid) >> 10)))) << 11)
        + (((9 * ((~(key->m_uid << 15) + key->m_uid) ^ ((~(key->m_uid << 15) + key->m_uid) >> 10))) >> 6)
         ^ (9 * ((~(key->m_uid << 15) + key->m_uid) ^ ((~(key->m_uid << 15) + key->m_uid) >> 10))))) >> 16));
  Index = btHashMap<btHashKey<btTriIndex>,btTriIndex>::findIndex(a2, key);
  if ( Index == -1 )
  {
    m_size = a2->m_valueArray.m_size;
    v8 = a2->m_valueArray.m_capacity;
    count = m_size;
    if ( m_size == v8 )
    {
      v9 = 2 * m_size;
      if ( !m_size )
        v9 = 1;
      v30 = v9;
      if ( v8 < v9 )
      {
        if ( v9 )
        {
          ++gNumAlignedAllocs;
          v29 = (btTriIndex *)sAlignedAllocFunc(8 * v9, 16);
        }
        else
        {
          v29 = 0;
        }
        v10 = a2->m_valueArray.m_size;
        v11 = 0;
        if ( v10 > 0 )
        {
          v12 = v29;
          do
          {
            if ( v12 )
            {
              m_data = a2->m_valueArray.m_data;
              v12->m_PartIdTriangleIndex = m_data[v11].m_PartIdTriangleIndex;
              v9 = v30;
              v12->m_childShape = m_data[v11].m_childShape;
            }
            ++v11;
            ++v12;
          }
          while ( v11 < v10 );
        }
        v14 = a2->m_valueArray.m_data;
        if ( v14 )
        {
          if ( a2->m_valueArray.m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v14);
          }
          a2->m_valueArray.m_data = 0;
        }
        a2->m_valueArray.m_ownsMemory = 1;
        a2->m_valueArray.m_data = v29;
        a2->m_valueArray.m_capacity = v9;
      }
    }
    v15 = &a2->m_valueArray.m_data[a2->m_valueArray.m_size];
    if ( v15 )
      *v15 = *value;
    ++a2->m_valueArray.m_size;
    v16 = a2->m_keyArray.m_capacity;
    v17 = a2->m_keyArray.m_size;
    if ( v17 == v16 )
    {
      v18 = 2 * v17;
      if ( !v17 )
        v18 = 1;
      if ( v16 < v18 )
      {
        if ( v18 )
        {
          ++gNumAlignedAllocs;
          v19 = (btTriIndex *)sAlignedAllocFunc(4 * v18, 16);
          valuea = v19;
        }
        else
        {
          v19 = 0;
          valuea = 0;
        }
        v20 = a2->m_keyArray.m_size;
        v21 = 0;
        if ( v20 > 0 )
        {
          p_m_PartIdTriangleIndex = &v19->m_PartIdTriangleIndex;
          do
          {
            if ( p_m_PartIdTriangleIndex )
              *p_m_PartIdTriangleIndex = a2->m_keyArray.m_data[v21].m_uid;
            ++v21;
            ++p_m_PartIdTriangleIndex;
          }
          while ( v21 < v20 );
          v19 = (btTriIndex *)valuea;
        }
        v23 = a2->m_keyArray.m_data;
        if ( v23 )
        {
          if ( a2->m_keyArray.m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v23);
          }
          a2->m_keyArray.m_data = 0;
        }
        a2->m_keyArray.m_ownsMemory = 1;
        a2->m_keyArray.m_data = (btHashKey<btTriIndex> *)v19;
        a2->m_keyArray.m_capacity = v18;
      }
    }
    m_uid = (btHashMap<btHashKey<btTriIndex>,btTriIndex> *)a2->m_keyArray.m_data;
    v25 = (btHashKey<btTriIndex> *)((char *)m_uid + 4 * a2->m_keyArray.m_size);
    if ( v25 )
    {
      m_uid = (btHashMap<btHashKey<btTriIndex>,btTriIndex> *)key->m_uid;
      v25->m_uid = key->m_uid;
    }
    ++a2->m_keyArray.m_size;
    if ( m_capacity < a2->m_valueArray.m_capacity )
    {
      btHashMap<btHashKey<btTriIndex>,btTriIndex>::growTables(m_uid, v28);
      v26 = (9 * ((~(key->m_uid << 15) + key->m_uid) ^ ((~(key->m_uid << 15) + key->m_uid) >> 10))) >> 6;
      v27 = ~((v26 ^ (9 * ((~(key->m_uid << 15) + key->m_uid) ^ ((~(key->m_uid << 15) + key->m_uid) >> 10)))) << 11);
      v5 = (a2->m_valueArray.m_capacity - 1)
         & ((v27 + (v26 ^ (9 * ((~(key->m_uid << 15) + key->m_uid) ^ ((~(key->m_uid << 15) + key->m_uid) >> 10)))))
          ^ ((v27 + (v26 ^ (9 * ((~(key->m_uid << 15) + key->m_uid) ^ ((~(key->m_uid << 15) + key->m_uid) >> 10))))) >> 16));
    }
    a2->m_next.m_data[count] = a2->m_hashTable.m_data[v5];
    a2->m_hashTable.m_data[v5] = count;
  }
  else
  {
    a2->m_valueArray.m_data[Index] = *value;
  }
}
