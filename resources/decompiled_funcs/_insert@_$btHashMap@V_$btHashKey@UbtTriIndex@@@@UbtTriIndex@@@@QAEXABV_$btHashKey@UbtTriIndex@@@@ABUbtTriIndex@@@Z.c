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
