void __thiscall btAxisSweep3Internal<unsigned short>::calculateOverlappingPairs(
        btAxisSweep3Internal<unsigned short> *this,
        btDispatcher *dispatcher)
{
  btAxisSweep3Internal<unsigned short> *v2; // esi
  btAlignedObjectArray<btBroadphasePair> *v3; // ebx
  int m_size; // eax
  int v5; // edi
  btBroadphasePair *v6; // esi
  btCollisionAlgorithm **p_m_algorithm; // ecx
  btCollisionAlgorithm **v8; // eax
  int v9; // ecx
  int v10; // edx
  btBroadphasePair *v11; // eax
  btBroadphasePair *v12; // eax
  btBroadphaseProxy *m_pProxy0; // edx
  bool v14; // cl
  btBroadphaseProxy *v15; // ecx
  __int16 *p_m_collisionFilterMask; // edi
  btBroadphaseProxy *v17; // esi
  int v18; // ecx
  int v19; // eax
  int v20; // edi
  btBroadphasePair *v21; // esi
  btCollisionAlgorithm **v22; // ecx
  btCollisionAlgorithm **v23; // eax
  int v24; // ecx
  int v25; // edx
  btBroadphasePair *v26; // eax
  int v28; // [esp+10h] [ebp-20h]
  int v29; // [esp+10h] [ebp-20h]
  int v30; // [esp+14h] [ebp-1Ch]
  int v31; // [esp+14h] [ebp-1Ch]
  int v32; // [esp+14h] [ebp-1Ch]
  btBroadphasePairSortPredicate CompareFunc[4]; // [esp+18h] [ebp-18h]
  btBroadphasePairSortPredicate CompareFunca[4]; // [esp+18h] [ebp-18h]
  btBroadphasePair *v35; // [esp+1Ch] [ebp-14h]
  btBroadphaseProxy *v36; // [esp+20h] [ebp-10h]
  btBroadphaseProxy *m_pProxy1; // [esp+24h] [ebp-Ch]

  v2 = this;
  if ( this->m_pairCache->hasDeferredRemoval(this->m_pairCache) )
  {
    v3 = v2->m_pairCache->getOverlappingPairArray(v2->m_pairCache);
    btAlignedObjectArray<btBroadphasePair>::quickSort<btBroadphasePairSortPredicate>(v3, 0);
    m_size = v3->m_size;
    v5 = m_size - v2->m_invalidPair;
    v30 = m_size;
    if ( v5 >= m_size )
    {
      if ( v5 > m_size && v3->m_capacity < v5 )
      {
        if ( v5 )
          v6 = (btBroadphasePair *)btAlignedAllocInternal(16 * v5);
        else
          v6 = 0;
        if ( v3->m_size > 0 )
        {
          p_m_algorithm = &v6->m_algorithm;
          *(_DWORD *)CompareFunc = v3->m_size;
          do
          {
            if ( p_m_algorithm != (btCollisionAlgorithm **)8 )
            {
              v8 = (btCollisionAlgorithm **)((char *)p_m_algorithm + (unsigned int)v3->m_data - 8 - (_DWORD)v6);
              *(p_m_algorithm - 2) = *v8;
              *(p_m_algorithm - 1) = v8[1];
              *p_m_algorithm = v8[2];
              p_m_algorithm[1] = v8[3];
            }
            p_m_algorithm += 4;
            --*(_DWORD *)CompareFunc;
          }
          while ( *(_DWORD *)CompareFunc );
        }
        if ( v3->m_data )
        {
          if ( v3->m_ownsMemory )
            btAlignedFreeInternal(v3->m_data);
          v3->m_data = 0;
        }
        m_size = v30;
        v3->m_data = v6;
        v2 = this;
        v3->m_ownsMemory = 1;
        v3->m_capacity = v5;
      }
      if ( m_size < v5 )
      {
        v9 = m_size;
        v10 = v5 - m_size;
        do
        {
          v11 = &v3->m_data[v9];
          if ( v11 )
          {
            v11->m_pProxy0 = 0;
            v11->m_pProxy1 = 0;
            v11->m_algorithm = 0;
            v11->m_internalTmpValue = 0;
          }
          ++v9;
          --v10;
        }
        while ( v10 );
      }
    }
    v3->m_size = v5;
    v2->m_invalidPair = 0;
    v36 = 0;
    m_pProxy1 = 0;
    *(_DWORD *)CompareFunca = 0;
    if ( v3->m_size > 0 )
    {
      v31 = 0;
      do
      {
        v12 = &v3->m_data[v31];
        m_pProxy0 = v12->m_pProxy0;
        v35 = v12;
        v14 = v12->m_pProxy0 == v36 && v12->m_pProxy1 == m_pProxy1;
        v36 = v12->m_pProxy0;
        m_pProxy1 = v12->m_pProxy1;
        if ( !v14 )
        {
          v15 = v12->m_pProxy1;
          v28 = 0;
          p_m_collisionFilterMask = &v15[1].m_collisionFilterMask;
          v17 = m_pProxy0 + 1;
          v18 = (char *)v15 - (char *)m_pProxy0;
          while ( v17->m_collisionFilterMask >= *(_WORD *)((char *)&v17->m_clientObject + v18)
               && (unsigned __int16)*p_m_collisionFilterMask >= LOWORD(v17->m_clientObject) )
          {
            ++v28;
            v17 = (btBroadphaseProxy *)((char *)v17 + 2);
            ++p_m_collisionFilterMask;
            if ( v28 >= 3 )
              goto LABEL_36;
          }
        }
        this->m_pairCache->cleanOverlappingPair(this->m_pairCache, v12, dispatcher);
        v35->m_pProxy0 = 0;
        v35->m_pProxy1 = 0;
        ++this->m_invalidPair;
        --gOverlappingPairs;
LABEL_36:
        ++*(_DWORD *)CompareFunca;
        ++v31;
      }
      while ( *(int *)CompareFunca < v3->m_size );
      v2 = this;
    }
    btAlignedObjectArray<btBroadphasePair>::quickSort<btBroadphasePairSortPredicate>(v3, 0);
    v19 = v3->m_size;
    v20 = v19 - v2->m_invalidPair;
    v32 = v19;
    if ( v20 >= v19 )
    {
      if ( v20 > v19 && v3->m_capacity < v20 )
      {
        if ( v20 )
          v21 = (btBroadphasePair *)btAlignedAllocInternal(16 * v20);
        else
          v21 = 0;
        if ( v3->m_size > 0 )
        {
          v22 = &v21->m_algorithm;
          v29 = v3->m_size;
          do
          {
            if ( v22 != (btCollisionAlgorithm **)8 )
            {
              v23 = (btCollisionAlgorithm **)((char *)v22 + (unsigned int)v3->m_data - 8 - (_DWORD)v21);
              *(v22 - 2) = *v23;
              *(v22 - 1) = v23[1];
              *v22 = v23[2];
              v22[1] = v23[3];
            }
            v22 += 4;
            --v29;
          }
          while ( v29 );
        }
        if ( v3->m_data )
        {
          if ( v3->m_ownsMemory )
            btAlignedFreeInternal(v3->m_data);
          v3->m_data = 0;
        }
        v19 = v32;
        v3->m_data = v21;
        v2 = this;
        v3->m_ownsMemory = 1;
        v3->m_capacity = v20;
      }
      if ( v19 < v20 )
      {
        v24 = v19;
        v25 = v20 - v19;
        do
        {
          v26 = &v3->m_data[v24];
          if ( v26 )
          {
            v26->m_pProxy0 = 0;
            v26->m_pProxy1 = 0;
            v26->m_algorithm = 0;
            v26->m_internalTmpValue = 0;
          }
          ++v24;
          --v25;
        }
        while ( v25 );
      }
    }
    v3->m_size = v20;
    v2->m_invalidPair = 0;
  }
}
