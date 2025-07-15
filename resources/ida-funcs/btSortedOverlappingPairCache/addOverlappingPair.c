btBroadphasePair *__thiscall btSortedOverlappingPairCache::addOverlappingPair(
        btSortedOverlappingPairCache *this,
        btBroadphaseProxy *proxy0,
        btBroadphaseProxy *proxy1)
{
  btBroadphaseProxy *v4; // edi
  btBroadphaseProxy *v5; // ebp
  bool v6; // al
  int m_capacity; // eax
  int m_size; // ebx
  int v10; // edi
  btBroadphasePair *v11; // ebp
  btCollisionAlgorithm **p_m_algorithm; // ecx
  int v13; // edi
  char *v14; // eax
  btCollisionAlgorithm *v15; // ebx
  char *v16; // eax
  btBroadphasePair *m_data; // eax
  btBroadphasePair *v18; // ebx
  int v19; // [esp+Ch] [ebp-8h]
  int v20; // [esp+10h] [ebp-4h]

  if ( this->m_overlapFilterCallback )
  {
    v4 = proxy1;
    v5 = proxy0;
    v6 = this->m_overlapFilterCallback->needBroadphaseCollision(this->m_overlapFilterCallback, proxy0, proxy1);
  }
  else
  {
    v6 = (proxy0->m_collisionFilterGroup & proxy1->m_collisionFilterMask) != 0
      && (proxy0->m_collisionFilterMask & proxy1->m_collisionFilterGroup) != 0;
    v5 = proxy0;
    v4 = proxy1;
  }
  if ( !v6 )
    return 0;
  m_capacity = this->m_overlappingPairArray.m_capacity;
  m_size = this->m_overlappingPairArray.m_size;
  v20 = m_size;
  if ( m_size == m_capacity )
  {
    if ( m_size )
    {
      v10 = 2 * m_size;
      v19 = 2 * m_size;
    }
    else
    {
      v19 = 1;
      v10 = 1;
    }
    if ( m_capacity < v10 )
    {
      if ( v10 )
      {
        ++gNumAlignedAllocs;
        v11 = (btBroadphasePair *)sAlignedAllocFunc(16 * v10, 16);
      }
      else
      {
        v11 = 0;
      }
      if ( this->m_overlappingPairArray.m_size > 0 )
      {
        p_m_algorithm = &v11->m_algorithm;
        v13 = this->m_overlappingPairArray.m_size;
        do
        {
          if ( p_m_algorithm != (btCollisionAlgorithm **)8 )
          {
            v14 = (char *)this->m_overlappingPairArray.m_data - 8 - (_DWORD)v11;
            v15 = *(btCollisionAlgorithm **)((char *)p_m_algorithm + (_DWORD)v14);
            v16 = &v14[(_DWORD)p_m_algorithm];
            *(p_m_algorithm - 2) = v15;
            *(p_m_algorithm - 1) = (btCollisionAlgorithm *)*((_DWORD *)v16 + 1);
            *p_m_algorithm = (btCollisionAlgorithm *)*((_DWORD *)v16 + 2);
            m_size = v20;
            p_m_algorithm[1] = (btCollisionAlgorithm *)*((_DWORD *)v16 + 3);
          }
          p_m_algorithm += 4;
          --v13;
        }
        while ( v13 );
        v10 = v19;
      }
      m_data = this->m_overlappingPairArray.m_data;
      if ( m_data )
      {
        if ( this->m_overlappingPairArray.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(m_data);
        }
        this->m_overlappingPairArray.m_data = 0;
      }
      this->m_overlappingPairArray.m_data = v11;
      v5 = proxy0;
      this->m_overlappingPairArray.m_ownsMemory = 1;
      this->m_overlappingPairArray.m_capacity = v10;
    }
    v4 = proxy1;
  }
  ++this->m_overlappingPairArray.m_size;
  v18 = &this->m_overlappingPairArray.m_data[m_size];
  if ( v18 )
  {
    if ( v5->m_uniqueId >= v4->m_uniqueId )
    {
      v18->m_pProxy0 = v4;
      v18->m_pProxy1 = v5;
    }
    else
    {
      v18->m_pProxy0 = v5;
      v18->m_pProxy1 = v4;
    }
    v18->m_algorithm = 0;
    v18->m_internalTmpValue = 0;
  }
  else
  {
    v18 = 0;
  }
  ++gOverlappingPairs;
  ++gAddedPairs;
  if ( this->m_ghostPairCallback )
    this->m_ghostPairCallback->addOverlappingPair(this->m_ghostPairCallback, v5, v4);
  return v18;
}
