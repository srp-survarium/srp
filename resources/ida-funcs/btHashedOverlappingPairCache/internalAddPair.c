btBroadphasePair *__userpurge btHashedOverlappingPairCache::internalAddPair@<eax>(
        btHashedOverlappingPairCache *this@<ecx>,
        int a2@<eax>,
        btBroadphaseProxy *proxy0,
        btBroadphaseProxy *proxy1)
{
  btBroadphaseProxy *v4; // ecx
  btBroadphaseProxy *v6; // eax
  int m_uniqueId; // ebx
  int v8; // edx
  int v9; // ebp
  int v10; // ecx
  int v11; // eax
  int v12; // edi
  int v13; // eax
  _DWORD *v14; // ecx
  btBroadphasePair *result; // eax
  int v16; // edx
  int v17; // eax
  int v18; // ebx
  char *v19; // eax
  int v20; // edx
  _DWORD *v21; // ecx
  int v22; // eax
  int v23; // edx
  _DWORD *v24; // eax
  void *v25; // eax
  _DWORD *v26; // ebx
  int v27; // ecx
  int v28; // edx
  char *v29; // [esp+10h] [ebp-18h]
  int v30; // [esp+14h] [ebp-14h]
  int v31; // [esp+18h] [ebp-10h]
  int v32; // [esp+1Ch] [ebp-Ch]
  btHashedOverlappingPairCache *v33; // [esp+20h] [ebp-8h]
  int count; // [esp+24h] [ebp-4h]

  v4 = proxy1;
  v6 = proxy0;
  if ( proxy0->m_uniqueId > proxy1->m_uniqueId )
  {
    proxy1 = proxy0;
    proxy0 = v4;
    v6 = v4;
    v4 = proxy1;
  }
  m_uniqueId = v4->m_uniqueId;
  v8 = v6->m_uniqueId;
  v9 = v8 | (m_uniqueId << 16);
  v10 = ~(v9 << 15) + v9;
  v11 = ~((((9 * (v10 ^ (v10 >> 10))) >> 6) ^ (9 * (v10 ^ (v10 >> 10)))) << 11)
      + (((9 * (v10 ^ (v10 >> 10))) >> 6) ^ (9 * (v10 ^ (v10 >> 10))));
  v33 = *(btHashedOverlappingPairCache **)(a2 + 12);
  v12 = ((unsigned int)&v33[-1].m_ghostPairCallback + 3) & (v11 ^ (v11 >> 16));
  v13 = *(_DWORD *)(*(_DWORD *)(a2 + 44) + 4 * v12);
  if ( v13 == -1 )
    goto LABEL_9;
  while ( 1 )
  {
    v14 = (_DWORD *)(*(_DWORD *)(a2 + 16) + 16 * v13);
    if ( *(_DWORD *)(*v14 + 12) == v8 && *(_DWORD *)(v14[1] + 12) == m_uniqueId )
      break;
    v13 = *(_DWORD *)(*(_DWORD *)(a2 + 64) + 4 * v13);
    if ( v13 == -1 )
      goto LABEL_9;
  }
  result = (btBroadphasePair *)(*(_DWORD *)(a2 + 16) + 16 * v13);
  if ( !result )
  {
LABEL_9:
    v16 = *(_DWORD *)(a2 + 8);
    v17 = *(_DWORD *)(a2 + 12);
    v18 = v16;
    count = v16;
    if ( v16 == v17 )
    {
      v30 = v16 ? 2 * v16 : 1;
      if ( v17 < v30 )
      {
        if ( v30 )
        {
          ++gNumAlignedAllocs;
          v19 = (char *)sAlignedAllocFunc(16 * v30, 16);
          v29 = v19;
        }
        else
        {
          v29 = 0;
          v19 = 0;
        }
        if ( *(int *)(a2 + 8) > 0 )
        {
          v20 = -8 - (_DWORD)v19;
          v21 = v19 + 8;
          v32 = -8 - (_DWORD)v19;
          v31 = *(_DWORD *)(a2 + 8);
          do
          {
            if ( v21 != (_DWORD *)8 )
            {
              v22 = v20 + *(_DWORD *)(a2 + 16);
              v23 = *(_DWORD *)((char *)v21 + v22);
              v24 = (_DWORD *)((char *)v21 + v22);
              *(v21 - 2) = v23;
              *(v21 - 1) = v24[1];
              *v21 = v24[2];
              v20 = v32;
              v21[1] = v24[3];
            }
            v21 += 4;
            --v31;
          }
          while ( v31 );
        }
        v25 = *(void **)(a2 + 16);
        if ( v25 )
        {
          if ( *(_BYTE *)(a2 + 20) )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v25);
          }
          *(_DWORD *)(a2 + 16) = 0;
        }
        *(_BYTE *)(a2 + 20) = 1;
        *(_DWORD *)(a2 + 16) = v29;
        *(_DWORD *)(a2 + 12) = v30;
      }
    }
    ++*(_DWORD *)(a2 + 8);
    v26 = (_DWORD *)(*(_DWORD *)(a2 + 16) + 16 * v18);
    if ( *(_DWORD *)(a2 + 72) )
      (*(void (__thiscall **)(_DWORD, btBroadphaseProxy *, btBroadphaseProxy *))(**(_DWORD **)(a2 + 72) + 4))(
        *(_DWORD *)(a2 + 72),
        proxy0,
        proxy1);
    if ( (int)v33 < *(_DWORD *)(a2 + 12) )
    {
      btHashedOverlappingPairCache::growTables(v33, a2);
      v27 = (9 * ((~(v9 << 15) + v9) ^ ((~(v9 << 15) + v9) >> 10))) >> 6;
      v28 = ~((v27 ^ (9 * ((~(v9 << 15) + v9) ^ ((~(v9 << 15) + v9) >> 10)))) << 11);
      v12 = (*(_DWORD *)(a2 + 12) - 1)
          & ((v28 + (v27 ^ (9 * ((~(v9 << 15) + v9) ^ ((~(v9 << 15) + v9) >> 10)))))
           ^ ((v28 + (v27 ^ (9 * ((~(v9 << 15) + v9) ^ ((~(v9 << 15) + v9) >> 10))))) >> 16));
    }
    if ( v26 )
    {
      if ( proxy0->m_uniqueId >= proxy1->m_uniqueId )
      {
        *v26 = proxy1;
        v26[1] = proxy0;
      }
      else
      {
        *v26 = proxy0;
        v26[1] = proxy1;
      }
      v26[2] = 0;
      v26[3] = 0;
    }
    else
    {
      v26 = 0;
    }
    v26[2] = 0;
    v26[3] = 0;
    *(_DWORD *)(*(_DWORD *)(a2 + 64) + 4 * count) = *(_DWORD *)(*(_DWORD *)(a2 + 44) + 4 * v12);
    *(_DWORD *)(*(_DWORD *)(a2 + 44) + 4 * v12) = count;
    return (btBroadphasePair *)v26;
  }
  return result;
}
