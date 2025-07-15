void __thiscall btDbvtBroadphase::performDeferredRemoval(btDbvtBroadphase *this, btDispatcher *dispatcher, int a3)
{
  btAlignedObjectArray<btBroadphasePair> *v3; // ebx
  btBroadphasePair *v4; // eax
  bool v5; // cl
  int m_size; // esi
  int v7; // edi
  btCollisionAlgorithm **p_m_algorithm; // ecx
  btCollisionAlgorithm **v9; // eax
  int v10; // ecx
  int v11; // edx
  btBroadphasePair *v12; // eax
  int v13; // [esp+10h] [ebp-30h]
  btBroadphasePair *v14; // [esp+10h] [ebp-30h]
  int v15; // [esp+14h] [ebp-2Ch]
  btBroadphasePairSortPredicate CompareFunc[4]; // [esp+18h] [ebp-28h]
  btBroadphasePairSortPredicate CompareFunca[4]; // [esp+18h] [ebp-28h]
  btBroadphasePair *v18; // [esp+1Ch] [ebp-24h]
  btBroadphasePairSortPredicate v19[4]; // [esp+1Ch] [ebp-24h]
  btBroadphaseProxy *m_pProxy0; // [esp+20h] [ebp-20h]
  btBroadphaseProxy *m_pProxy1; // [esp+24h] [ebp-1Ch]
  __m128 v22; // [esp+30h] [ebp-10h]

  if ( (*((unsigned __int8 (__thiscall **)(btDispatcher_vtbl *))dispatcher[24].~btDispatcher + 13))(dispatcher[24].__vftable) )
  {
    v3 = (btAlignedObjectArray<btBroadphasePair> *)(*((int (__thiscall **)(btDispatcher_vtbl *))dispatcher[24].~btDispatcher
                                                    + 6))(dispatcher[24].__vftable);
    btAlignedObjectArray<btBroadphasePair>::quickSort<btBroadphasePairSortPredicate>(v3, 0);
    *(_DWORD *)CompareFunc = 0;
    m_pProxy0 = 0;
    m_pProxy1 = 0;
    v15 = 0;
    if ( v3->m_size > 0 )
    {
      v13 = 0;
      do
      {
        v4 = &v3->m_data[v13];
        v18 = v4;
        v5 = v4->m_pProxy0 == m_pProxy0 && v4->m_pProxy1 == m_pProxy1;
        m_pProxy0 = v4->m_pProxy0;
        m_pProxy1 = v4->m_pProxy1;
        if ( v5
          || (v22 = _mm_or_ps(
                      _mm_cmplt_ps(
                        *((__m128 *)v4->m_pProxy0[1].m_clientObject + 1),
                        *(__m128 *)v4->m_pProxy1[1].m_clientObject),
                      _mm_cmplt_ps(
                        *((__m128 *)v4->m_pProxy1[1].m_clientObject + 1),
                        *(__m128 *)v4->m_pProxy0[1].m_clientObject)),
              v22.m128_i32[2] | v22.m128_i32[1] | v22.m128_i32[0]) )
        {
          (*((void (__thiscall **)(btDispatcher_vtbl *, btBroadphasePair *, int))dispatcher[24].~btDispatcher + 7))(
            dispatcher[24].__vftable,
            v4,
            a3);
          v18->m_pProxy0 = 0;
          v18->m_pProxy1 = 0;
          ++*(_DWORD *)CompareFunc;
        }
        ++v15;
        ++v13;
      }
      while ( v15 < v3->m_size );
    }
    btAlignedObjectArray<btBroadphasePair>::quickSort<btBroadphasePairSortPredicate>(v3, 0);
    m_size = v3->m_size;
    v7 = m_size - *(_DWORD *)CompareFunc;
    *(_DWORD *)v19 = m_size;
    if ( m_size - *(_DWORD *)CompareFunc >= m_size )
    {
      if ( v7 > m_size && v3->m_capacity < v7 )
      {
        if ( v7 )
          v14 = (btBroadphasePair *)btAlignedAllocInternal(16 * v7);
        else
          v14 = 0;
        if ( v3->m_size > 0 )
        {
          p_m_algorithm = &v14->m_algorithm;
          *(_DWORD *)CompareFunca = v3->m_size;
          do
          {
            if ( p_m_algorithm != (btCollisionAlgorithm **)8 )
            {
              v9 = (btCollisionAlgorithm **)((char *)p_m_algorithm + (unsigned int)v3->m_data - 8 - (_DWORD)v14);
              *(p_m_algorithm - 2) = *v9;
              *(p_m_algorithm - 1) = v9[1];
              *p_m_algorithm = v9[2];
              m_size = *(_DWORD *)v19;
              p_m_algorithm[1] = v9[3];
            }
            p_m_algorithm += 4;
            --*(_DWORD *)CompareFunca;
          }
          while ( *(_DWORD *)CompareFunca );
        }
        if ( v3->m_data )
        {
          if ( v3->m_ownsMemory )
            btAlignedFreeInternal(v3->m_data);
          v3->m_data = 0;
        }
        v3->m_ownsMemory = 1;
        v3->m_data = v14;
        v3->m_capacity = v7;
      }
      if ( m_size < v7 )
      {
        v10 = m_size;
        v11 = v7 - m_size;
        do
        {
          v12 = &v3->m_data[v10];
          if ( v12 )
          {
            v12->m_pProxy0 = 0;
            v12->m_pProxy1 = 0;
            v12->m_algorithm = 0;
            v12->m_internalTmpValue = 0;
          }
          ++v10;
          --v11;
        }
        while ( v11 );
      }
    }
    v3->m_size = v7;
  }
}
