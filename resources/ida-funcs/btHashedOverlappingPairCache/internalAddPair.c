void __userpurge btHashedOverlappingPairCache::internalAddPair(
        btHashedOverlappingPairCache *this@<ecx>,
        int a2@<eax>,
        btBroadphaseProxy *proxy0,
        btBroadphaseProxy *proxy1)
{
  btBroadphaseProxy *v4; // ecx
  btBroadphaseProxy *v6; // eax
  int m_uniqueId; // edx
  int v8; // ebx
  int v9; // ecx
  int v10; // eax
  int v11; // edi
  int v12; // eax
  _DWORD *v13; // ecx
  btHashedOverlappingPairCache *v14; // eax
  btHashedOverlappingPairCache *v15; // ecx
  _DWORD *v16; // ecx
  _DWORD *v17; // eax
  int v18; // ebx
  int v19; // ecx
  int v20; // eax
  btHashedOverlappingPairCache *v21; // [esp+Ch] [ebp-1Ch]
  int v22; // [esp+10h] [ebp-18h]
  int v23; // [esp+14h] [ebp-14h]
  btBroadphasePair *v24; // [esp+14h] [ebp-14h]
  char *v25; // [esp+18h] [ebp-10h]
  btHashedOverlappingPairCache *v26; // [esp+1Ch] [ebp-Ch]
  int v27; // [esp+24h] [ebp-4h]

  v4 = proxy1;
  v6 = proxy0;
  if ( proxy0->m_uniqueId > proxy1->m_uniqueId )
  {
    proxy0 = proxy1;
    proxy1 = v6;
    v4 = v6;
    v6 = proxy0;
  }
  m_uniqueId = v6->m_uniqueId;
  v8 = m_uniqueId | (v4->m_uniqueId << 16);
  v9 = ~(v8 << 15) + v8;
  v10 = ~((((9 * (v9 ^ (v9 >> 10))) >> 6) ^ (9 * (v9 ^ (v9 >> 10)))) << 11)
      + (((9 * (v9 ^ (v9 >> 10))) >> 6) ^ (9 * (v9 ^ (v9 >> 10))));
  v22 = *(_DWORD *)(a2 + 12);
  v11 = (v22 - 1) & (v10 ^ (v10 >> 16));
  v12 = *(_DWORD *)(*(_DWORD *)(a2 + 44) + 4 * v11);
  if ( v12 == -1 )
    goto LABEL_9;
  while ( 1 )
  {
    v13 = (_DWORD *)(*(_DWORD *)(a2 + 16) + 16 * v12);
    if ( *(_DWORD *)(*v13 + 12) == m_uniqueId && *(_DWORD *)(v13[1] + 12) == proxy1->m_uniqueId )
      break;
    v12 = *(_DWORD *)(*(_DWORD *)(a2 + 64) + 4 * v12);
    if ( v12 == -1 )
      goto LABEL_9;
  }
  if ( !(*(_DWORD *)(a2 + 16) + 16 * v12) )
  {
LABEL_9:
    v14 = *(btHashedOverlappingPairCache **)(a2 + 8);
    v15 = *(btHashedOverlappingPairCache **)(a2 + 12);
    v21 = v14;
    v26 = v14;
    if ( v14 == v15 )
    {
      v27 = v14 ? 2 * (_DWORD)v14 : 1;
      if ( (int)v15 < v27 )
      {
        if ( v27 )
        {
          v25 = (char *)btAlignedAllocInternal(16 * v27);
          v14 = v26;
        }
        else
        {
          v25 = 0;
        }
        if ( *(int *)(a2 + 8) > 0 )
        {
          v16 = v25 + 8;
          v23 = *(_DWORD *)(a2 + 8);
          do
          {
            if ( v16 != (_DWORD *)8 )
            {
              v17 = (_DWORD *)((char *)v16 + -8 - (_DWORD)v25 + *(_DWORD *)(a2 + 16));
              *(v16 - 2) = *v17;
              *(v16 - 1) = v17[1];
              *v16 = v17[2];
              v16[1] = v17[3];
            }
            v16 += 4;
            --v23;
          }
          while ( v23 );
          v14 = v26;
        }
        if ( *(_DWORD *)(a2 + 16) )
        {
          if ( *(_BYTE *)(a2 + 20) )
          {
            btAlignedFreeInternal(*(void **)(a2 + 16));
            v14 = v26;
          }
          *(_DWORD *)(a2 + 16) = 0;
        }
        *(_DWORD *)(a2 + 16) = v25;
        v15 = (btHashedOverlappingPairCache *)v27;
        *(_BYTE *)(a2 + 20) = 1;
        *(_DWORD *)(a2 + 12) = v27;
      }
    }
    ++*(_DWORD *)(a2 + 8);
    v24 = (btBroadphasePair *)(*(_DWORD *)(a2 + 16) + 16 * (_DWORD)v14);
    if ( *(_DWORD *)(a2 + 72) )
      (*(void (__thiscall **)(_DWORD, btBroadphaseProxy *, btBroadphaseProxy *))(**(_DWORD **)(a2 + 72) + 4))(
        *(_DWORD *)(a2 + 72),
        proxy0,
        proxy1);
    if ( v22 < *(_DWORD *)(a2 + 12) )
    {
      btHashedOverlappingPairCache::growTables(v15, a2);
      v18 = ~(v8 << 15) + v8;
      v19 = ~((((9 * (v18 ^ (v18 >> 10))) >> 6) ^ (9 * (v18 ^ (v18 >> 10)))) << 11);
      v11 = (*(_DWORD *)(a2 + 12) - 1)
          & ((v19 + (((9 * (v18 ^ (v18 >> 10))) >> 6) ^ (9 * (v18 ^ (v18 >> 10)))))
           ^ ((v19 + (((9 * (v18 ^ (v18 >> 10))) >> 6) ^ (9 * (v18 ^ (v18 >> 10))))) >> 16));
    }
    v20 = 0;
    if ( v24 )
      btBroadphasePair::btBroadphasePair(v24);
    *(_DWORD *)(v20 + 8) = 0;
    *(_DWORD *)(v20 + 12) = 0;
    *(_DWORD *)(*(_DWORD *)(a2 + 64) + 4 * (_DWORD)v21) = *(_DWORD *)(4 * v11 + *(_DWORD *)(a2 + 44));
    *(_DWORD *)(4 * v11 + *(_DWORD *)(a2 + 44)) = v21;
  }
}
