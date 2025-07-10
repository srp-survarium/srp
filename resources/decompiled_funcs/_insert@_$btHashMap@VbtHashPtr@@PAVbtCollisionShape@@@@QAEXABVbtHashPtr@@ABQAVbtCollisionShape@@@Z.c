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
