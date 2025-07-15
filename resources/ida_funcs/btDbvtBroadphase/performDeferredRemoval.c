void __thiscall btDbvtBroadphase::performDeferredRemoval(
        btDbvtBroadphase *this,
        btDbvtBroadphase *dispatcher,
        btDispatcher *dispatchera)
{
  btAlignedObjectArray<btBroadphasePair> *v3; // edi
  int m_size; // eax
  __int64 v5; // rax
  int v6; // ebx
  btBroadphasePair *m_data; // esi
  btBroadphaseProxy *m_pProxy0; // ecx
  btBroadphasePair *v9; // esi
  int v10; // eax
  int v11; // ebx
  int v12; // esi
  btCollisionAlgorithm **p_m_algorithm; // ecx
  int v14; // eax
  btCollisionAlgorithm *v15; // ebx
  _DWORD *v16; // eax
  btBroadphasePair *v17; // eax
  int v18; // ecx
  int v19; // edx
  btBroadphasePair *v20; // eax
  int v21; // [esp+88h] [ebp-2Ch]
  btBroadphasePair *v22; // [esp+88h] [ebp-2Ch]
  btBroadphasePairSortPredicate CompareFunc[4]; // [esp+8Ch] [ebp-28h]
  btBroadphasePairSortPredicate CompareFunca[4]; // [esp+8Ch] [ebp-28h]
  int v25; // [esp+90h] [ebp-24h]
  __int64 v26; // [esp+94h] [ebp-20h]
  __m128 v27; // [esp+A4h] [ebp-10h]

  if ( dispatcher->m_paircache->hasDeferredRemoval(dispatcher->m_paircache) )
  {
    v3 = dispatcher->m_paircache->getOverlappingPairArray(dispatcher->m_paircache);
    m_size = v3->m_size;
    if ( m_size > 1 )
      btAlignedObjectArray<btBroadphasePair>::quickSortInternal<btBroadphasePairSortPredicate>(v3, 0, 0, m_size - 1);
    v5 = 0;
    v21 = 0;
    *(_DWORD *)CompareFunc = 0;
    if ( v3->m_size > 0 )
    {
      v6 = 0;
      while ( 1 )
      {
        m_data = v3->m_data;
        m_pProxy0 = m_data[v6].m_pProxy0;
        v9 = &m_data[v6];
        v26 = *(_QWORD *)&v9->m_pProxy0;
        if ( __PAIR64__(v9->m_pProxy1, (unsigned int)m_pProxy0) == v5
          || (v27 = _mm_or_ps(
                      _mm_cmplt_ps(
                        *((__m128 *)m_pProxy0[1].m_clientObject + 1),
                        *(__m128 *)v9->m_pProxy1[1].m_clientObject),
                      _mm_cmplt_ps(
                        *((__m128 *)v9->m_pProxy1[1].m_clientObject + 1),
                        *(__m128 *)m_pProxy0[1].m_clientObject)),
              v27.m128_i32[2] | v27.m128_i32[1] | v27.m128_i32[0]) )
        {
          dispatcher->m_paircache->cleanOverlappingPair(dispatcher->m_paircache, v9, dispatchera);
          ++v21;
          v9->m_pProxy0 = 0;
          v9->m_pProxy1 = 0;
        }
        ++v6;
        ++*(_DWORD *)CompareFunc;
        if ( *(int *)CompareFunc >= v3->m_size )
          break;
        v5 = v26;
      }
    }
    v10 = v3->m_size;
    if ( v10 > 1 )
      btAlignedObjectArray<btBroadphasePair>::quickSortInternal<btBroadphasePairSortPredicate>(v3, 0, 0, v10 - 1);
    v11 = v3->m_size;
    v12 = v11 - v21;
    v25 = v11;
    if ( v11 - v21 >= v11 )
    {
      if ( v12 > v11 && v3->m_capacity < v12 )
      {
        if ( v12 )
        {
          ++gNumAlignedAllocs;
          v22 = (btBroadphasePair *)sAlignedAllocFunc(16 * v12, 16);
        }
        else
        {
          v22 = 0;
        }
        if ( v3->m_size > 0 )
        {
          p_m_algorithm = &v22->m_algorithm;
          *(_DWORD *)CompareFunca = v3->m_size;
          do
          {
            if ( p_m_algorithm != (btCollisionAlgorithm **)8 )
            {
              v14 = (int)v3->m_data - 8 - (_DWORD)v22;
              v15 = *(btCollisionAlgorithm **)((char *)p_m_algorithm + v14);
              v16 = (btCollisionAlgorithm **)((char *)p_m_algorithm + v14);
              *(p_m_algorithm - 2) = v15;
              *(p_m_algorithm - 1) = (btCollisionAlgorithm *)v16[1];
              *p_m_algorithm = (btCollisionAlgorithm *)v16[2];
              p_m_algorithm[1] = (btCollisionAlgorithm *)v16[3];
            }
            p_m_algorithm += 4;
            --*(_DWORD *)CompareFunca;
          }
          while ( *(_DWORD *)CompareFunca );
          v11 = v25;
        }
        v17 = v3->m_data;
        if ( v17 )
        {
          if ( v3->m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v17);
          }
          v3->m_data = 0;
        }
        v3->m_ownsMemory = 1;
        v3->m_data = v22;
        v3->m_capacity = v12;
      }
      if ( v11 < v12 )
      {
        v18 = v11;
        v19 = v12 - v11;
        do
        {
          v20 = &v3->m_data[v18];
          if ( v20 )
          {
            v20->m_pProxy0 = 0;
            v20->m_pProxy1 = 0;
            v20->m_algorithm = 0;
            v20->m_internalTmpValue = 0;
          }
          ++v18;
          --v19;
        }
        while ( v19 );
      }
    }
    v3->m_size = v12;
  }
}
