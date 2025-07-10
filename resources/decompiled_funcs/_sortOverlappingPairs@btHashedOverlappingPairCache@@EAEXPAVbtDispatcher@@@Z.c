void __thiscall btHashedOverlappingPairCache::sortOverlappingPairs(
        btHashedOverlappingPairCache *this,
        btDispatcher *dispatcher)
{
  int m_size; // ecx
  btBroadphasePair *m_data; // edx
  int m_capacity; // esi
  bool v6; // cc
  btBroadphasePair *v7; // ebx
  btBroadphasePair *v8; // eax
  btBroadphasePair *v9; // edi
  btCollisionAlgorithm **p_m_algorithm; // eax
  int v11; // ebx
  btCollisionAlgorithm **v12; // ecx
  btBroadphasePair *v13; // eax
  int v14; // edi
  int v15; // esi
  int v16; // eax
  int v17; // edi
  int v18; // esi
  int v19; // [esp+10h] [ebp-24h]
  int v20; // [esp+14h] [ebp-20h]
  int i; // [esp+18h] [ebp-1Ch]
  btBroadphasePair *v22; // [esp+1Ch] [ebp-18h]
  btAlignedObjectArray<btBroadphasePair> tmpPairs; // [esp+20h] [ebp-14h] BYREF

  m_size = 0;
  m_data = 0;
  m_capacity = 0;
  v6 = this->m_overlappingPairArray.m_size <= 0;
  tmpPairs.m_ownsMemory = 1;
  memset(&tmpPairs.m_size, 0, 12);
  i = 0;
  if ( !v6 )
  {
    v20 = 0;
    do
    {
      v7 = &this->m_overlappingPairArray.m_data[v20];
      v22 = v7;
      if ( m_size == m_capacity )
      {
        v19 = m_size ? 2 * m_size : 1;
        if ( m_capacity < v19 )
        {
          if ( v19 )
          {
            ++gNumAlignedAllocs;
            v8 = (btBroadphasePair *)sAlignedAllocFunc(16 * v19, 16);
            m_data = tmpPairs.m_data;
            m_size = tmpPairs.m_size;
            v9 = v8;
          }
          else
          {
            v9 = 0;
          }
          if ( m_size > 0 )
          {
            p_m_algorithm = &v9->m_algorithm;
            v11 = m_size;
            do
            {
              if ( p_m_algorithm != (btCollisionAlgorithm **)8 )
              {
                v12 = (btCollisionAlgorithm **)((char *)p_m_algorithm + (_DWORD)m_data - (_DWORD)v9 - 8);
                *(p_m_algorithm - 2) = *v12;
                *(p_m_algorithm - 1) = v12[1];
                *p_m_algorithm = v12[2];
                p_m_algorithm[1] = v12[3];
                m_data = tmpPairs.m_data;
              }
              p_m_algorithm += 4;
              --v11;
            }
            while ( v11 );
            m_size = tmpPairs.m_size;
            v7 = v22;
          }
          if ( m_data && tmpPairs.m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(m_data);
            m_size = tmpPairs.m_size;
          }
          m_capacity = v19;
          m_data = v9;
          tmpPairs.m_ownsMemory = 1;
          tmpPairs.m_data = v9;
          tmpPairs.m_capacity = v19;
        }
      }
      v13 = &m_data[m_size];
      if ( v13 )
      {
        v13->m_pProxy0 = v7->m_pProxy0;
        v13->m_pProxy1 = v7->m_pProxy1;
        v13->m_algorithm = v7->m_algorithm;
        v13->m_internalTmpValue = v7->m_internalTmpValue;
        m_data = tmpPairs.m_data;
        m_capacity = tmpPairs.m_capacity;
        m_size = tmpPairs.m_size;
      }
      ++v20;
      ++m_size;
      v6 = i + 1 < this->m_overlappingPairArray.m_size;
      tmpPairs.m_size = m_size;
      ++i;
    }
    while ( v6 );
  }
  v14 = 0;
  if ( m_size > 0 )
  {
    v15 = 0;
    do
    {
      this->removeOverlappingPair(this, m_data[v15].m_pProxy0, m_data[v15].m_pProxy1, dispatcher);
      m_size = tmpPairs.m_size;
      m_data = tmpPairs.m_data;
      ++v14;
      ++v15;
    }
    while ( v14 < tmpPairs.m_size );
  }
  v16 = 0;
  if ( this->m_next.m_size > 0 )
  {
    do
      this->m_next.m_data[v16++] = -1;
    while ( v16 < this->m_next.m_size );
    m_data = tmpPairs.m_data;
    m_size = tmpPairs.m_size;
  }
  if ( m_size > 1 )
  {
    btAlignedObjectArray<btBroadphasePair>::quickSortInternal<btBroadphasePairSortPredicate>(
      &tmpPairs,
      0,
      0,
      m_size - 1);
    m_data = tmpPairs.m_data;
    m_size = tmpPairs.m_size;
  }
  v17 = 0;
  if ( m_size > 0 )
  {
    v18 = 0;
    do
    {
      this->addOverlappingPair(this, m_data[v18].m_pProxy0, m_data[v18].m_pProxy1);
      m_data = tmpPairs.m_data;
      ++v17;
      ++v18;
    }
    while ( v17 < tmpPairs.m_size );
  }
  if ( m_data )
  {
    if ( tmpPairs.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
  }
}
