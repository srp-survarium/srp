void *__thiscall btHashedOverlappingPairCache::removeOverlappingPair(
        btHashedOverlappingPairCache *this,
        btBroadphaseProxy *proxy0,
        btBroadphaseProxy *proxy1,
        btDispatcher *dispatcher)
{
  btBroadphaseProxy *v4; // eax
  int m_uniqueId; // edx
  btBroadphaseProxy *v7; // ecx
  int v8; // ebx
  int v9; // edx
  int v10; // eax
  int v11; // edi
  int v12; // eax
  btBroadphasePair *v13; // ecx
  btBroadphasePair *v15; // ebx
  void *m_internalInfo1; // ecx
  int *m_data; // edx
  int v19; // eax
  int *v20; // edi
  signed int v21; // ebx
  int *v22; // edx
  int v23; // ecx
  int v24; // edi
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int *v28; // ebp
  int v29; // eax
  btBroadphasePair *v30; // edi
  int previous; // [esp+18h] [ebp+8h]
  void *userData; // [esp+1Ch] [ebp+Ch]

  v4 = proxy0;
  m_uniqueId = proxy0->m_uniqueId;
  ++gRemovePairs;
  v7 = proxy1;
  if ( m_uniqueId > proxy1->m_uniqueId )
  {
    v4 = proxy1;
    v7 = proxy0;
    proxy0 = proxy1;
    proxy1 = v7;
  }
  v8 = v7->m_uniqueId;
  v9 = v4->m_uniqueId;
  v10 = ~((((9
           * ((~((v9 | (v8 << 16)) << 15) + (v9 | (v8 << 16))) ^ ((~((v9 | (v8 << 16)) << 15) + (v9 | (v8 << 16))) >> 10))) >> 6)
         ^ (9
          * ((~((v9 | (v8 << 16)) << 15) + (v9 | (v8 << 16))) ^ ((~((v9 | (v8 << 16)) << 15) + (v9 | (v8 << 16))) >> 10)))) << 11)
      + (((9
         * ((~((v9 | (v8 << 16)) << 15) + (v9 | (v8 << 16))) ^ ((~((v9 | (v8 << 16)) << 15) + (v9 | (v8 << 16))) >> 10))) >> 6)
       ^ (9
        * ((~((v9 | (v8 << 16)) << 15) + (v9 | (v8 << 16))) ^ ((~((v9 | (v8 << 16)) << 15) + (v9 | (v8 << 16))) >> 10))));
  v11 = (this->m_overlappingPairArray.m_capacity - 1) & (v10 ^ (v10 >> 16));
  v12 = this->m_hashTable.m_data[v11];
  if ( v12 == -1 )
    return 0;
  while ( 1 )
  {
    v13 = &this->m_overlappingPairArray.m_data[v12];
    if ( v13->m_pProxy0->m_uniqueId == v9 && v13->m_pProxy1->m_uniqueId == v8 )
      break;
    v12 = this->m_next.m_data[v12];
    if ( v12 == -1 )
      return 0;
  }
  v15 = &this->m_overlappingPairArray.m_data[v12];
  if ( !v15 )
    return 0;
  this->cleanOverlappingPair(this, v15, dispatcher);
  m_internalInfo1 = v15->m_internalInfo1;
  m_data = this->m_hashTable.m_data;
  v19 = m_data[v11];
  v20 = &m_data[v11];
  v21 = v15 - this->m_overlappingPairArray.m_data;
  userData = m_internalInfo1;
  if ( v19 == v21 )
    goto LABEL_15;
  v22 = this->m_next.m_data;
  do
  {
    v23 = v19;
    v19 = v22[v19];
  }
  while ( v19 != v21 );
  if ( v23 == -1 )
LABEL_15:
    *v20 = this->m_next.m_data[v21];
  else
    this->m_next.m_data[v23] = v22[v21];
  v24 = this->m_overlappingPairArray.m_size - 1;
  if ( this->m_ghostPairCallback )
    this->m_ghostPairCallback->removeOverlappingPair(this->m_ghostPairCallback, proxy0, proxy1, dispatcher);
  if ( v24 != v21 )
  {
    v25 = v24;
    v26 = 9
        * ((~((this->m_overlappingPairArray.m_data[v24].m_pProxy0->m_uniqueId
             | (this->m_overlappingPairArray.m_data[v24].m_pProxy1->m_uniqueId << 16)) << 15)
          + (this->m_overlappingPairArray.m_data[v24].m_pProxy0->m_uniqueId
           | (this->m_overlappingPairArray.m_data[v24].m_pProxy1->m_uniqueId << 16)))
         ^ ((~((this->m_overlappingPairArray.m_data[v24].m_pProxy0->m_uniqueId
              | (this->m_overlappingPairArray.m_data[v24].m_pProxy1->m_uniqueId << 16)) << 15)
           + (this->m_overlappingPairArray.m_data[v24].m_pProxy0->m_uniqueId
            | (this->m_overlappingPairArray.m_data[v24].m_pProxy1->m_uniqueId << 16))) >> 10));
    v27 = (this->m_overlappingPairArray.m_capacity - 1)
        & ((~(((v26 >> 6) ^ v26) << 11) + ((v26 >> 6) ^ v26))
         ^ ((~(((v26 >> 6) ^ v26) << 11) + ((v26 >> 6) ^ v26)) >> 16));
    v28 = &this->m_hashTable.m_data[v27];
    v29 = *v28;
    if ( *v28 != v24 )
    {
      do
      {
        previous = v29;
        v29 = this->m_next.m_data[v29];
      }
      while ( v29 != v24 );
      if ( previous != -1 )
      {
        this->m_next.m_data[previous] = this->m_next.m_data[v24];
LABEL_25:
        v30 = this->m_overlappingPairArray.m_data;
        *(_QWORD *)&v30[v21].m_pProxy0 = *(_QWORD *)&v30[v25].m_pProxy0;
        *(_QWORD *)&v30[v21].m_algorithm = *(_QWORD *)&v30[v25].m_algorithm;
        this->m_next.m_data[v21] = this->m_hashTable.m_data[v27];
        this->m_hashTable.m_data[v27] = v21;
        goto LABEL_26;
      }
      v28 = &this->m_hashTable.m_data[v27];
    }
    *v28 = this->m_next.m_data[v24];
    goto LABEL_25;
  }
LABEL_26:
  --this->m_overlappingPairArray.m_size;
  return userData;
}
