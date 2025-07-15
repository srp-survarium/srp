void __thiscall btHashedOverlappingPairCache::sortOverlappingPairs(
        btHashedOverlappingPairCache *this,
        btDispatcher *dispatcher)
{
  btAlignedObjectArray<GrahamVector2> *v3; // ecx
  bool v4; // cc
  btBroadphasePair *v5; // esi
  int v6; // edi
  btCollisionAlgorithm **p_m_algorithm; // ecx
  int v8; // edx
  btCollisionAlgorithm **v9; // eax
  btBroadphasePair *v10; // eax
  int v11; // edi
  int v12; // esi
  int i; // eax
  int v14; // edi
  int v15; // esi
  btAlignedObjectArray<btBroadphasePair> v16; // [esp+Ch] [ebp-28h] BYREF
  int v17; // [esp+20h] [ebp-14h]
  int m_size; // [esp+24h] [ebp-10h]
  int v19; // [esp+28h] [ebp-Ch]
  unsigned int v20; // [esp+2Ch] [ebp-8h]
  btBroadphasePair *v21; // [esp+30h] [ebp-4h]

  v3 = 0;
  v4 = this->m_overlappingPairArray.m_size <= 0;
  v16.m_ownsMemory = 1;
  memset(&v16.m_size, 0, 12);
  v19 = 0;
  if ( !v4 )
  {
    v20 = 0;
    do
    {
      v5 = &this->m_overlappingPairArray.m_data[v20 / 0x10];
      if ( v16.m_size == v16.m_capacity )
      {
        v6 = v16.m_size ? 2 * v16.m_size : 1;
        v17 = v6;
        if ( v16.m_capacity < v6 )
        {
          if ( v6 )
          {
            v21 = (btBroadphasePair *)btAlignedAllocInternal(16 * v6);
            v3 = 0;
          }
          else
          {
            v21 = 0;
          }
          if ( v16.m_size > 0 )
          {
            p_m_algorithm = &v21->m_algorithm;
            v8 = -8 - (_DWORD)v21;
            m_size = v16.m_size;
            do
            {
              if ( p_m_algorithm != (btCollisionAlgorithm **)8 )
              {
                v9 = (btCollisionAlgorithm **)((char *)v16.m_data + (unsigned int)p_m_algorithm + v8);
                *(p_m_algorithm - 2) = *v9;
                *(p_m_algorithm - 1) = v9[1];
                *p_m_algorithm = v9[2];
                p_m_algorithm[1] = v9[3];
              }
              p_m_algorithm += 4;
              --m_size;
            }
            while ( m_size );
            v6 = v17;
            v3 = 0;
          }
          if ( v16.m_data && v16.m_ownsMemory )
          {
            btAlignedFreeInternal(v16.m_data);
            v3 = 0;
          }
          v16.m_ownsMemory = 1;
          v16.m_data = v21;
          v16.m_capacity = v6;
        }
      }
      v10 = &v16.m_data[v16.m_size];
      if ( v10 )
      {
        v10->m_pProxy0 = v5->m_pProxy0;
        v10->m_pProxy1 = v5->m_pProxy1;
        v10->m_algorithm = v5->m_algorithm;
        v10->m_internalTmpValue = v5->m_internalTmpValue;
      }
      ++v16.m_size;
      ++v19;
      v20 += 16;
    }
    while ( v19 < this->m_overlappingPairArray.m_size );
  }
  v11 = 0;
  if ( v16.m_size > 0 )
  {
    v12 = 0;
    do
    {
      this->removeOverlappingPair(this, v16.m_data[v12].m_pProxy0, v16.m_data[v12].m_pProxy1, dispatcher);
      ++v11;
      ++v12;
    }
    while ( v11 < v16.m_size );
    v3 = 0;
  }
  for ( i = 0; i < this->m_next.m_size; ++i )
    this->m_next.m_data[i] = -1;
  if ( v16.m_size > 1 )
  {
    btAlignedObjectArray<btBroadphasePair>::quickSortInternal<btBroadphasePairSortPredicate>(&v16, 0, 0, v16.m_size - 1);
    v3 = 0;
  }
  v14 = 0;
  if ( v16.m_size > 0 )
  {
    v15 = 0;
    do
    {
      this->addOverlappingPair(this, v16.m_data[v15].m_pProxy0, v16.m_data[v15].m_pProxy1);
      ++v14;
      ++v15;
    }
    while ( v14 < v16.m_size );
  }
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v3, (int)&v16);
}
