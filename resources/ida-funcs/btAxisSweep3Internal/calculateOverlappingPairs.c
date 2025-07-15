void __thiscall btAxisSweep3Internal<unsigned short>::calculateOverlappingPairs(
        btAxisSweep3Internal<unsigned short> *this,
        btDispatcher *dispatcher)
{
  btAlignedObjectArray<btBroadphasePair> *v3; // edi
  int m_size; // eax
  int v5; // ebx
  int v6; // esi
  btCollisionAlgorithm **p_m_algorithm; // ecx
  int v8; // eax
  btCollisionAlgorithm *v9; // ebx
  _DWORD *v10; // eax
  btBroadphasePair *m_data; // eax
  int v12; // ecx
  int v13; // edx
  btBroadphasePair *v14; // eax
  __int64 v15; // rax
  int v16; // ebx
  btBroadphasePair *v17; // esi
  btBroadphaseProxy *m_pProxy0; // ecx
  btBroadphasePair *v19; // esi
  int v20; // eax
  int v21; // ebx
  int v22; // esi
  btCollisionAlgorithm **v23; // ecx
  int v24; // eax
  btCollisionAlgorithm *v25; // ebx
  _DWORD *v26; // eax
  btBroadphasePair *v27; // eax
  int v28; // ecx
  int v29; // edx
  btBroadphasePair *v30; // eax
  btAxisSweep3Internal<unsigned short> *v31; // [esp+24h] [ebp-30h]
  btBroadphasePair *v33; // [esp+38h] [ebp-1Ch]
  btBroadphasePair *v34; // [esp+38h] [ebp-1Ch]
  int v35; // [esp+3Ch] [ebp-18h]
  int v36; // [esp+3Ch] [ebp-18h]
  btBroadphasePairSortPredicate CompareFunc[4]; // [esp+40h] [ebp-14h]
  btBroadphasePairSortPredicate CompareFunca[4]; // [esp+40h] [ebp-14h]
  btBroadphasePairSortPredicate CompareFuncb[4]; // [esp+40h] [ebp-14h]
  __int64 v40; // [esp+44h] [ebp-10h]

  if ( this->m_pairCache->hasDeferredRemoval(this->m_pairCache) )
  {
    v3 = this->m_pairCache->getOverlappingPairArray(this->m_pairCache);
    m_size = v3->m_size;
    if ( m_size > 1 )
      btAlignedObjectArray<btBroadphasePair>::quickSortInternal<btBroadphasePairSortPredicate>(v3, 0, 0, m_size - 1);
    v5 = v3->m_size;
    v6 = v5 - this->m_invalidPair;
    v35 = v5;
    if ( v6 >= v5 )
    {
      if ( v6 > v5 && v3->m_capacity < v6 )
      {
        if ( v6 )
        {
          ++gNumAlignedAllocs;
          v33 = (btBroadphasePair *)sAlignedAllocFunc(16 * v6, 16);
        }
        else
        {
          v33 = 0;
        }
        if ( v3->m_size > 0 )
        {
          p_m_algorithm = &v33->m_algorithm;
          *(_DWORD *)CompareFunc = v3->m_size;
          do
          {
            if ( p_m_algorithm != (btCollisionAlgorithm **)8 )
            {
              v8 = (int)v3->m_data - 8 - (_DWORD)v33;
              v9 = *(btCollisionAlgorithm **)((char *)p_m_algorithm + v8);
              v10 = (btCollisionAlgorithm **)((char *)p_m_algorithm + v8);
              *(p_m_algorithm - 2) = v9;
              *(p_m_algorithm - 1) = (btCollisionAlgorithm *)v10[1];
              *p_m_algorithm = (btCollisionAlgorithm *)v10[2];
              v5 = v35;
              p_m_algorithm[1] = (btCollisionAlgorithm *)v10[3];
            }
            p_m_algorithm += 4;
            --*(_DWORD *)CompareFunc;
          }
          while ( *(_DWORD *)CompareFunc );
        }
        m_data = v3->m_data;
        if ( m_data )
        {
          if ( v3->m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(m_data);
          }
          v3->m_data = 0;
        }
        v3->m_ownsMemory = 1;
        v3->m_data = v33;
        v3->m_capacity = v6;
      }
      if ( v5 < v6 )
      {
        v12 = v5;
        v13 = v6 - v5;
        do
        {
          v14 = &v3->m_data[v12];
          if ( v14 )
          {
            v14->m_pProxy0 = 0;
            v14->m_pProxy1 = 0;
            v14->m_algorithm = 0;
            v14->m_internalTmpValue = 0;
          }
          ++v12;
          --v13;
        }
        while ( v13 );
      }
    }
    v15 = 0;
    v3->m_size = v6;
    this->m_invalidPair = 0;
    *(_DWORD *)CompareFunca = 0;
    if ( v3->m_size > 0 )
    {
      v16 = 0;
      while ( 1 )
      {
        v17 = v3->m_data;
        m_pProxy0 = v17[v16].m_pProxy0;
        v19 = &v17[v16];
        v40 = *(_QWORD *)&v19->m_pProxy0;
        if ( __PAIR64__(v19->m_pProxy1, (unsigned int)m_pProxy0) == v15
          || !btAxisSweep3Internal<unsigned short>::testAabbOverlap(v31, m_pProxy0, v19->m_pProxy1) )
        {
          this->m_pairCache->cleanOverlappingPair(this->m_pairCache, v19, dispatcher);
          v19->m_pProxy0 = 0;
          v19->m_pProxy1 = 0;
          ++this->m_invalidPair;
          --gOverlappingPairs;
        }
        ++v16;
        ++*(_DWORD *)CompareFunca;
        if ( *(int *)CompareFunca >= v3->m_size )
          break;
        v15 = v40;
      }
    }
    v20 = v3->m_size;
    if ( v20 > 1 )
      btAlignedObjectArray<btBroadphasePair>::quickSortInternal<btBroadphasePairSortPredicate>(v3, 0, 0, v20 - 1);
    v21 = v3->m_size;
    v22 = v21 - this->m_invalidPair;
    v36 = v21;
    if ( v22 >= v21 )
    {
      if ( v22 > v21 && v3->m_capacity < v22 )
      {
        if ( v22 )
        {
          ++gNumAlignedAllocs;
          v34 = (btBroadphasePair *)sAlignedAllocFunc(16 * v22, 16);
        }
        else
        {
          v34 = 0;
        }
        if ( v3->m_size > 0 )
        {
          v23 = &v34->m_algorithm;
          *(_DWORD *)CompareFuncb = v3->m_size;
          do
          {
            if ( v23 != (btCollisionAlgorithm **)8 )
            {
              v24 = (int)v3->m_data - 8 - (_DWORD)v34;
              v25 = *(btCollisionAlgorithm **)((char *)v23 + v24);
              v26 = (btCollisionAlgorithm **)((char *)v23 + v24);
              *(v23 - 2) = v25;
              *(v23 - 1) = (btCollisionAlgorithm *)v26[1];
              *v23 = (btCollisionAlgorithm *)v26[2];
              v21 = v36;
              v23[1] = (btCollisionAlgorithm *)v26[3];
            }
            v23 += 4;
            --*(_DWORD *)CompareFuncb;
          }
          while ( *(_DWORD *)CompareFuncb );
        }
        v27 = v3->m_data;
        if ( v27 )
        {
          if ( v3->m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v27);
          }
          v3->m_data = 0;
        }
        v3->m_ownsMemory = 1;
        v3->m_data = v34;
        v3->m_capacity = v22;
      }
      if ( v21 < v22 )
      {
        v28 = v21;
        v29 = v22 - v21;
        do
        {
          v30 = &v3->m_data[v28];
          if ( v30 )
          {
            v30->m_pProxy0 = 0;
            v30->m_pProxy1 = 0;
            v30->m_algorithm = 0;
            v30->m_internalTmpValue = 0;
          }
          ++v28;
          --v29;
        }
        while ( v29 );
      }
    }
    v3->m_size = v22;
    this->m_invalidPair = 0;
  }
}
