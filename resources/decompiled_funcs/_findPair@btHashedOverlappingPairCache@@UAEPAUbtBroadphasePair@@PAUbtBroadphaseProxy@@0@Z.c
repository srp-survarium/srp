btBroadphasePair *__thiscall btHashedOverlappingPairCache::findPair(
        btHashedOverlappingPairCache *this,
        btBroadphaseProxy *proxy0,
        btBroadphaseProxy *proxy1)
{
  btBroadphaseProxy *v3; // eax
  btBroadphaseProxy *v4; // edx
  int m_uniqueId; // ebx
  int v6; // edi
  int v7; // eax
  int v8; // edx
  int v10; // eax
  btBroadphasePair *m_data; // edx

  v3 = proxy0;
  v4 = proxy1;
  ++gFindPairs;
  if ( proxy0->m_uniqueId > proxy1->m_uniqueId )
  {
    v3 = proxy1;
    v4 = proxy0;
  }
  m_uniqueId = v4->m_uniqueId;
  v6 = v3->m_uniqueId;
  v7 = ~((((9
          * ((~((v6 | (m_uniqueId << 16)) << 15) + (v6 | (m_uniqueId << 16)))
           ^ ((~((v6 | (m_uniqueId << 16)) << 15) + (v6 | (m_uniqueId << 16))) >> 10))) >> 6)
        ^ (9
         * ((~((v6 | (m_uniqueId << 16)) << 15) + (v6 | (m_uniqueId << 16)))
          ^ ((~((v6 | (m_uniqueId << 16)) << 15) + (v6 | (m_uniqueId << 16))) >> 10)))) << 11)
     + (((9
        * ((~((v6 | (m_uniqueId << 16)) << 15) + (v6 | (m_uniqueId << 16)))
         ^ ((~((v6 | (m_uniqueId << 16)) << 15) + (v6 | (m_uniqueId << 16))) >> 10))) >> 6)
      ^ (9
       * ((~((v6 | (m_uniqueId << 16)) << 15) + (v6 | (m_uniqueId << 16)))
        ^ ((~((v6 | (m_uniqueId << 16)) << 15) + (v6 | (m_uniqueId << 16))) >> 10))));
  v8 = (this->m_overlappingPairArray.m_capacity - 1) & (v7 ^ (v7 >> 16));
  if ( v8 >= this->m_hashTable.m_size )
    return 0;
  v10 = this->m_hashTable.m_data[v8];
  if ( v10 == -1 )
    return 0;
  m_data = this->m_overlappingPairArray.m_data;
  while ( m_data[v10].m_pProxy0->m_uniqueId != v6 || m_data[v10].m_pProxy1->m_uniqueId != m_uniqueId )
  {
    v10 = this->m_next.m_data[v10];
    if ( v10 == -1 )
      return 0;
  }
  return &m_data[v10];
}
