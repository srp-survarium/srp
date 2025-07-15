void __thiscall btHashedOverlappingPairCache::removeOverlappingPair(
        btHashedOverlappingPairCache *this,
        btBroadphaseProxy *proxy0,
        btBroadphaseProxy *proxy1,
        btDispatcher *dispatcher)
{
  btBroadphaseProxy *v4; // edx
  btBroadphaseProxy *v5; // eax
  int m_uniqueId; // edx
  int v8; // eax
  int v9; // eax
  int v10; // esi
  int v11; // eax
  btBroadphasePair *v12; // ecx
  btBroadphasePair *v13; // edi
  int *v14; // esi
  int v15; // eax
  signed int v16; // edi
  int *m_data; // edx
  int v18; // ecx
  int v19; // esi
  btBroadphasePair *v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int *v24; // edx
  int v25; // ecx
  btBroadphasePair *v26; // ecx
  btBroadphaseProxy **p_m_pProxy0; // edi
  int v28; // [esp+8h] [ebp-4h]
  int v29; // [esp+8h] [ebp-4h]
  int v30; // [esp+14h] [ebp+8h]
  int v31; // [esp+18h] [ebp+Ch]

  v4 = proxy0;
  v5 = proxy1;
  ++gRemovePairs;
  if ( proxy0->m_uniqueId > proxy1->m_uniqueId )
  {
    proxy1 = proxy0;
    proxy0 = v5;
    v4 = v5;
    v5 = proxy1;
  }
  m_uniqueId = v4->m_uniqueId;
  v28 = v5->m_uniqueId;
  v8 = 9
     * ((~((m_uniqueId | (v28 << 16)) << 15) + (m_uniqueId | (v28 << 16)))
      ^ ((~((m_uniqueId | (v28 << 16)) << 15) + (m_uniqueId | (v28 << 16))) >> 10));
  v9 = ~(((v8 >> 6) ^ v8) << 11) + ((v8 >> 6) ^ v8);
  v10 = (this->m_overlappingPairArray.m_capacity - 1) & (v9 ^ (v9 >> 16));
  v11 = this->m_hashTable.m_data[v10];
  if ( v11 != -1 )
  {
    while ( 1 )
    {
      v12 = &this->m_overlappingPairArray.m_data[v11];
      if ( v12->m_pProxy0->m_uniqueId == m_uniqueId && v12->m_pProxy1->m_uniqueId == v28 )
        break;
      v11 = this->m_next.m_data[v11];
      if ( v11 == -1 )
        return;
    }
    v13 = &this->m_overlappingPairArray.m_data[v11];
    if ( v13 )
    {
      this->cleanOverlappingPair(this, v13, dispatcher);
      v14 = &this->m_hashTable.m_data[v10];
      v15 = *v14;
      v16 = v13 - this->m_overlappingPairArray.m_data;
      v29 = v16;
      if ( *v14 == v16 )
        goto LABEL_14;
      m_data = this->m_next.m_data;
      do
      {
        v18 = v15;
        v15 = m_data[v15];
      }
      while ( v15 != v16 );
      if ( v18 == -1 )
LABEL_14:
        *v14 = this->m_next.m_data[v16];
      else
        this->m_next.m_data[v18] = m_data[v16];
      v19 = this->m_overlappingPairArray.m_size - 1;
      if ( this->m_ghostPairCallback )
        this->m_ghostPairCallback->removeOverlappingPair(this->m_ghostPairCallback, proxy0, proxy1, dispatcher);
      if ( v19 != v16 )
      {
        v20 = this->m_overlappingPairArray.m_data;
        v31 = v19;
        v21 = 9
            * ((~((v20[v19].m_pProxy0->m_uniqueId | (v20[v19].m_pProxy1->m_uniqueId << 16)) << 15)
              + (v20[v19].m_pProxy0->m_uniqueId | (v20[v19].m_pProxy1->m_uniqueId << 16)))
             ^ ((~((v20[v19].m_pProxy0->m_uniqueId | (v20[v19].m_pProxy1->m_uniqueId << 16)) << 15)
               + (v20[v19].m_pProxy0->m_uniqueId | (v20[v19].m_pProxy1->m_uniqueId << 16))) >> 10));
        v22 = ~(((v21 >> 6) ^ v21) << 11) + ((v21 >> 6) ^ v21);
        v23 = (this->m_overlappingPairArray.m_capacity - 1) & (v22 ^ (v22 >> 16));
        v24 = &this->m_hashTable.m_data[v23];
        v25 = *v24;
        if ( *v24 == v19 )
          goto LABEL_22;
        do
        {
          v30 = v25;
          v25 = this->m_next.m_data[v25];
        }
        while ( v25 != v19 );
        if ( v30 == -1 )
LABEL_22:
          *v24 = this->m_next.m_data[v19];
        else
          this->m_next.m_data[v30] = this->m_next.m_data[v19];
        v26 = this->m_overlappingPairArray.m_data;
        p_m_pProxy0 = &v26[v16].m_pProxy0;
        *p_m_pProxy0++ = v26[v31].m_pProxy0;
        *p_m_pProxy0++ = v26[v31].m_pProxy1;
        *p_m_pProxy0 = (btBroadphaseProxy *)v26[v31].m_algorithm;
        p_m_pProxy0[1] = (btBroadphaseProxy *)v26[v31].m_internalInfo1;
        this->m_next.m_data[v29] = this->m_hashTable.m_data[v23];
        this->m_hashTable.m_data[v23] = v29;
      }
      --this->m_overlappingPairArray.m_size;
    }
  }
}
