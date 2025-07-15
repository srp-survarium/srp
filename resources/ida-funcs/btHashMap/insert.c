void __userpurge btHashMap<btInternalVertexPair,btInternalEdge>::insert(
        btHashMap<btInternalVertexPair,btInternalEdge> *this@<ecx>,
        btHashMap<btInternalVertexPair,btInternalEdge> *a2@<eax>,
        const btInternalVertexPair *key,
        const btInternalEdge *value)
{
  const btInternalVertexPair *v4; // ebx
  int v6; // edi
  int Index; // eax
  int m_size; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // edx
  int v12; // eax
  btInternalEdge *v13; // ecx
  btInternalEdge *v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ebx
  int v18; // edx
  int v19; // eax
  btInternalVertexPair *v20; // ecx
  btInternalVertexPair *m_data; // ecx
  btInternalVertexPair *v22; // eax
  int v23; // [esp+Ch] [ebp-10h]
  int m_capacity; // [esp+10h] [ebp-Ch]
  int v25; // [esp+14h] [ebp-8h]
  int v26; // [esp+14h] [ebp-8h]
  btInternalEdge *v27; // [esp+18h] [ebp-4h]
  btInternalVertexPair *v28; // [esp+28h] [ebp+Ch]

  v4 = key;
  m_capacity = a2->m_valueArray.m_capacity;
  v6 = (m_capacity - 1) & (key->m_v0 + (key->m_v1 << 16));
  Index = btHashMap<btInternalVertexPair,btInternalEdge>::findIndex(a2, key);
  if ( Index == -1 )
  {
    m_size = a2->m_valueArray.m_size;
    v9 = a2->m_valueArray.m_capacity;
    v23 = m_size;
    if ( m_size == v9 )
    {
      if ( m_size )
      {
        v10 = 2 * m_size;
        v25 = v10;
      }
      else
      {
        v25 = 1;
        v10 = 1;
      }
      if ( v9 < v10 )
      {
        if ( v10 )
          v27 = (btInternalEdge *)btAlignedAllocInternal(4 * v10);
        else
          v27 = 0;
        v11 = a2->m_valueArray.m_size;
        v12 = 0;
        if ( v11 > 0 )
        {
          v13 = v27;
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
        if ( a2->m_valueArray.m_data )
        {
          if ( a2->m_valueArray.m_ownsMemory )
            btAlignedFreeInternal(a2->m_valueArray.m_data);
          a2->m_valueArray.m_data = 0;
        }
        a2->m_valueArray.m_data = v27;
        a2->m_valueArray.m_ownsMemory = 1;
        a2->m_valueArray.m_capacity = v25;
      }
    }
    v14 = &a2->m_valueArray.m_data[a2->m_valueArray.m_size];
    if ( v14 )
      *v14 = *value;
    ++a2->m_valueArray.m_size;
    v15 = a2->m_keyArray.m_capacity;
    v16 = a2->m_keyArray.m_size;
    if ( v16 == v15 )
    {
      if ( v16 )
        v17 = 2 * v16;
      else
        v17 = 1;
      v26 = v17;
      if ( v15 < v17 )
      {
        if ( v17 )
          v28 = (btInternalVertexPair *)btAlignedAllocInternal(4 * v17);
        else
          v28 = 0;
        v18 = a2->m_keyArray.m_size;
        v19 = 0;
        if ( v18 > 0 )
        {
          v20 = v28;
          do
          {
            if ( v20 )
            {
              *v20 = a2->m_keyArray.m_data[v19];
              v17 = v26;
            }
            ++v19;
            ++v20;
          }
          while ( v19 < v18 );
        }
        if ( a2->m_keyArray.m_data )
        {
          if ( a2->m_keyArray.m_ownsMemory )
            btAlignedFreeInternal(a2->m_keyArray.m_data);
          a2->m_keyArray.m_data = 0;
        }
        a2->m_keyArray.m_ownsMemory = 1;
        a2->m_keyArray.m_data = v28;
        a2->m_keyArray.m_capacity = v17;
      }
      v4 = key;
    }
    m_data = a2->m_keyArray.m_data;
    v22 = &m_data[a2->m_keyArray.m_size];
    if ( v22 )
    {
      m_data = (btInternalVertexPair *)*v4;
      *v22 = *v4;
    }
    ++a2->m_keyArray.m_size;
    if ( m_capacity < a2->m_valueArray.m_capacity )
    {
      btHashMap<btInternalVertexPair,btInternalEdge>::growTables(
        (btHashMap<btInternalVertexPair,btInternalEdge> *)m_data,
        (int)a2);
      v6 = (a2->m_valueArray.m_capacity - 1) & (v4->m_v0 + (v4->m_v1 << 16));
    }
    a2->m_next.m_data[v23] = a2->m_hashTable.m_data[v6];
    a2->m_hashTable.m_data[v6] = v23;
  }
  else
  {
    a2->m_valueArray.m_data[Index] = *value;
  }
}


void __userpurge btHashMap<btHashPtr,btCollisionShape *>::insert(
        btHashMap<btHashPtr,btCollisionShape *> *this@<ecx>,
        btHashMap<btHashPtr,btCollisionShape *> *a2@<eax>,
        const btHashPtr *key,
        btCollisionShape **value)
{
  int v6; // edi
  int Index; // eax
  int m_size; // eax
  int v9; // ecx
  int v10; // ebx
  int v11; // edx
  int v12; // ecx
  btCollisionShape **v13; // eax
  btCollisionShape **v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ebx
  int v18; // edx
  _DWORD *m_hashValues; // ecx
  btHashPtr *m_data; // eax
  btHashPtr *v21; // ecx
  int *v22; // eax
  int v23; // ecx
  int v24; // [esp+8h] [ebp-10h]
  int m_capacity; // [esp+Ch] [ebp-Ch]
  int v26; // [esp+10h] [ebp-8h]
  int v27; // [esp+10h] [ebp-8h]
  btCollisionShape **v28; // [esp+14h] [ebp-4h]
  int v29; // [esp+14h] [ebp-4h]
  btHashPtr *v30; // [esp+24h] [ebp+Ch]

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
  Index = btHashMap<btHashPtr,btCollisionShape *>::findIndex(a2, key);
  if ( Index == -1 )
  {
    m_size = a2->m_valueArray.m_size;
    v9 = a2->m_valueArray.m_capacity;
    v24 = m_size;
    if ( m_size == v9 )
    {
      v10 = m_size ? 2 * m_size : 1;
      v26 = v10;
      if ( v9 < v10 )
      {
        if ( v10 )
          v28 = (btCollisionShape **)btAlignedAllocInternal(4 * v10);
        else
          v28 = 0;
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
              v10 = v26;
            }
            ++v12;
            ++v13;
          }
          while ( v12 < v11 );
        }
        if ( a2->m_valueArray.m_data )
        {
          if ( a2->m_valueArray.m_ownsMemory )
            btAlignedFreeInternal(a2->m_valueArray.m_data);
          a2->m_valueArray.m_data = 0;
        }
        a2->m_valueArray.m_ownsMemory = 1;
        a2->m_valueArray.m_data = v28;
        a2->m_valueArray.m_capacity = v10;
      }
    }
    v14 = &a2->m_valueArray.m_data[a2->m_valueArray.m_size];
    if ( v14 )
      *v14 = *value;
    ++a2->m_valueArray.m_size;
    v15 = a2->m_keyArray.m_capacity;
    v16 = a2->m_keyArray.m_size;
    if ( v16 == v15 )
    {
      v17 = v16 ? 2 * v16 : 1;
      v27 = v17;
      if ( v15 < v17 )
      {
        if ( v17 )
          v30 = (btHashPtr *)btAlignedAllocInternal(8 * v17);
        else
          v30 = 0;
        v18 = 0;
        v29 = a2->m_keyArray.m_size;
        if ( v29 > 0 )
        {
          m_hashValues = v30->m_hashValues;
          do
          {
            if ( m_hashValues )
            {
              m_data = a2->m_keyArray.m_data;
              *m_hashValues = m_data[v18].m_pointer;
              v17 = v27;
              m_hashValues[1] = m_data[v18].m_hashValues[1];
            }
            ++v18;
            m_hashValues += 2;
          }
          while ( v18 < v29 );
        }
        if ( a2->m_keyArray.m_data )
        {
          if ( a2->m_keyArray.m_ownsMemory )
            btAlignedFreeInternal(a2->m_keyArray.m_data);
          a2->m_keyArray.m_data = 0;
        }
        a2->m_keyArray.m_ownsMemory = 1;
        a2->m_keyArray.m_data = v30;
        a2->m_keyArray.m_capacity = v17;
      }
    }
    v21 = a2->m_keyArray.m_data;
    v22 = (int *)&v21[a2->m_keyArray.m_size];
    if ( v22 )
    {
      *v22 = key->m_hashValues[0];
      v21 = (btHashPtr *)key->m_hashValues[1];
      v22[1] = (int)v21;
    }
    ++a2->m_keyArray.m_size;
    if ( m_capacity < a2->m_valueArray.m_capacity )
    {
      btHashMap<btHashPtr,btCollisionShape *>::growTables((btHashMap<btHashPtr,btCollisionShape *> *)v21, (int)a2);
      v23 = ~((((9
               * ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0])
                ^ ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0]) >> 10))) >> 6)
             ^ (9
              * ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0])
               ^ ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0]) >> 10)))) << 11);
      v6 = (a2->m_valueArray.m_capacity - 1)
         & ((v23
           + (((9
              * ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0])
               ^ ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0]) >> 10))) >> 6)
            ^ (9
             * ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0])
              ^ ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0]) >> 10)))))
          ^ ((v23
            + (((9
               * ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0])
                ^ ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0]) >> 10))) >> 6)
             ^ (9
              * ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0])
               ^ ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0]) >> 10))))) >> 16));
    }
    a2->m_next.m_data[v24] = a2->m_hashTable.m_data[v6];
    a2->m_hashTable.m_data[v6] = v24;
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
  int m_size; // eax
  int v8; // ecx
  int v9; // ebx
  int v10; // edx
  btTriIndex *v11; // ecx
  btTriIndex *m_data; // eax
  btTriIndex *v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // ebx
  int v17; // edx
  int v18; // ecx
  btHashKey<btTriIndex> *v19; // eax
  btHashKey<btTriIndex> *m_uid; // ecx
  btHashKey<btTriIndex> *v21; // eax
  int v22; // ecx
  int v23; // [esp+8h] [ebp-14h]
  int m_capacity; // [esp+Ch] [ebp-10h]
  int v25; // [esp+10h] [ebp-Ch]
  int v26; // [esp+14h] [ebp-8h]
  int v27; // [esp+14h] [ebp-8h]
  btTriIndex *v28; // [esp+18h] [ebp-4h]
  btHashKey<btTriIndex> *v29; // [esp+28h] [ebp+Ch]

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
    v23 = m_size;
    if ( m_size == v8 )
    {
      v9 = m_size ? 2 * m_size : 1;
      v26 = v9;
      if ( v8 < v9 )
      {
        if ( v9 )
          v28 = (btTriIndex *)btAlignedAllocInternal(8 * v9);
        else
          v28 = 0;
        v10 = 0;
        v25 = a2->m_valueArray.m_size;
        if ( v25 > 0 )
        {
          v11 = v28;
          do
          {
            if ( v11 )
            {
              m_data = a2->m_valueArray.m_data;
              v11->m_PartIdTriangleIndex = m_data[v10].m_PartIdTriangleIndex;
              v9 = v26;
              v11->m_childShape = m_data[v10].m_childShape;
            }
            ++v10;
            ++v11;
          }
          while ( v10 < v25 );
        }
        if ( a2->m_valueArray.m_data )
        {
          if ( a2->m_valueArray.m_ownsMemory )
            btAlignedFreeInternal(a2->m_valueArray.m_data);
          a2->m_valueArray.m_data = 0;
        }
        a2->m_valueArray.m_ownsMemory = 1;
        a2->m_valueArray.m_data = v28;
        a2->m_valueArray.m_capacity = v9;
      }
    }
    v13 = &a2->m_valueArray.m_data[a2->m_valueArray.m_size];
    if ( v13 )
      *v13 = *value;
    ++a2->m_valueArray.m_size;
    v14 = a2->m_keyArray.m_capacity;
    v15 = a2->m_keyArray.m_size;
    if ( v15 == v14 )
    {
      v16 = v15 ? 2 * v15 : 1;
      v27 = v16;
      if ( v14 < v16 )
      {
        if ( v16 )
          v29 = (btHashKey<btTriIndex> *)btAlignedAllocInternal(4 * v16);
        else
          v29 = 0;
        v17 = a2->m_keyArray.m_size;
        v18 = 0;
        if ( v17 > 0 )
        {
          v19 = v29;
          do
          {
            if ( v19 )
            {
              v19->m_uid = (int)a2->m_keyArray.m_data[v18];
              v16 = v27;
            }
            ++v18;
            ++v19;
          }
          while ( v18 < v17 );
        }
        if ( a2->m_keyArray.m_data )
        {
          if ( a2->m_keyArray.m_ownsMemory )
            btAlignedFreeInternal(a2->m_keyArray.m_data);
          a2->m_keyArray.m_data = 0;
        }
        a2->m_keyArray.m_ownsMemory = 1;
        a2->m_keyArray.m_data = v29;
        a2->m_keyArray.m_capacity = v16;
      }
    }
    m_uid = a2->m_keyArray.m_data;
    v21 = &m_uid[a2->m_keyArray.m_size];
    if ( v21 )
    {
      m_uid = (btHashKey<btTriIndex> *)key->m_uid;
      v21->m_uid = key->m_uid;
    }
    ++a2->m_keyArray.m_size;
    if ( m_capacity < a2->m_valueArray.m_capacity )
    {
      btHashMap<btHashKey<btTriIndex>,btTriIndex>::growTables(
        (btHashMap<btHashKey<btTriIndex>,btTriIndex> *)m_uid,
        (int)a2);
      v22 = ~((((9 * ((~(key->m_uid << 15) + key->m_uid) ^ ((~(key->m_uid << 15) + key->m_uid) >> 10))) >> 6)
             ^ (9 * ((~(key->m_uid << 15) + key->m_uid) ^ ((~(key->m_uid << 15) + key->m_uid) >> 10)))) << 11);
      v5 = (a2->m_valueArray.m_capacity - 1)
         & ((v22
           + (((9 * ((~(key->m_uid << 15) + key->m_uid) ^ ((~(key->m_uid << 15) + key->m_uid) >> 10))) >> 6)
            ^ (9 * ((~(key->m_uid << 15) + key->m_uid) ^ ((~(key->m_uid << 15) + key->m_uid) >> 10)))))
          ^ ((v22
            + (((9 * ((~(key->m_uid << 15) + key->m_uid) ^ ((~(key->m_uid << 15) + key->m_uid) >> 10))) >> 6)
             ^ (9 * ((~(key->m_uid << 15) + key->m_uid) ^ ((~(key->m_uid << 15) + key->m_uid) >> 10))))) >> 16));
    }
    a2->m_next.m_data[v23] = a2->m_hashTable.m_data[v5];
    a2->m_hashTable.m_data[v5] = v23;
  }
  else
  {
    a2->m_valueArray.m_data[Index] = *value;
  }
}
