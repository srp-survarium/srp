void __usercall btHashedOverlappingPairCache::growTables(btHashedOverlappingPairCache *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  int v3; // edi
  int v4; // ebp
  _DWORD *v5; // ebx
  int v6; // edx
  int v7; // eax
  _DWORD *v8; // ecx
  void *v9; // eax
  int i; // eax
  _DWORD *v11; // ecx
  int v12; // ebx
  _DWORD *v13; // ebp
  int v14; // edx
  int v15; // eax
  _DWORD *v16; // ecx
  void *v17; // eax
  int j; // eax
  _DWORD *v19; // ecx
  int v20; // eax
  int k; // eax
  int v22; // edx
  int v23; // edi
  int v24; // eax
  int v25; // ecx
  _DWORD *v26; // [esp+4h] [ebp-8h]
  int v27; // [esp+4h] [ebp-8h]
  int v28; // [esp+8h] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 36);
  v3 = *(_DWORD *)(a2 + 12);
  v28 = v2;
  if ( v2 < v3 )
  {
    v4 = *(_DWORD *)(a2 + 36);
    if ( v3 >= v2 )
    {
      if ( v3 > v2 && *(_DWORD *)(a2 + 40) < v3 )
      {
        if ( v3 )
        {
          ++gNumAlignedAllocs;
          v5 = sAlignedAllocFunc(4 * v3, 16);
          v26 = v5;
        }
        else
        {
          v5 = 0;
          v26 = 0;
        }
        v6 = *(_DWORD *)(a2 + 36);
        v7 = 0;
        if ( v6 > 0 )
        {
          v8 = v5;
          do
          {
            if ( v8 )
              *v8 = *(_DWORD *)(*(_DWORD *)(a2 + 44) + 4 * v7);
            ++v7;
            ++v8;
          }
          while ( v7 < v6 );
          v5 = v26;
        }
        v9 = *(void **)(a2 + 44);
        if ( v9 )
        {
          if ( *(_BYTE *)(a2 + 48) )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v9);
          }
          *(_DWORD *)(a2 + 44) = 0;
        }
        *(_BYTE *)(a2 + 48) = 1;
        *(_DWORD *)(a2 + 44) = v5;
        *(_DWORD *)(a2 + 40) = v3;
      }
      for ( i = v4; i < v3; ++i )
      {
        v11 = (_DWORD *)(*(_DWORD *)(a2 + 44) + 4 * i);
        if ( v11 )
          *v11 = 0;
      }
    }
    *(_DWORD *)(a2 + 36) = v3;
    v12 = *(_DWORD *)(a2 + 56);
    v27 = v12;
    if ( v3 >= v12 )
    {
      if ( v3 > v12 && *(_DWORD *)(a2 + 60) < v3 )
      {
        if ( v3 )
        {
          ++gNumAlignedAllocs;
          v13 = sAlignedAllocFunc(4 * v3, 16);
        }
        else
        {
          v13 = 0;
        }
        v14 = *(_DWORD *)(a2 + 56);
        v15 = 0;
        if ( v14 > 0 )
        {
          v16 = v13;
          do
          {
            if ( v16 )
            {
              *v16 = *(_DWORD *)(*(_DWORD *)(a2 + 64) + 4 * v15);
              v12 = v27;
            }
            ++v15;
            ++v16;
          }
          while ( v15 < v14 );
        }
        v17 = *(void **)(a2 + 64);
        if ( v17 )
        {
          if ( *(_BYTE *)(a2 + 68) )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v17);
          }
          *(_DWORD *)(a2 + 64) = 0;
        }
        *(_BYTE *)(a2 + 68) = 1;
        *(_DWORD *)(a2 + 64) = v13;
        *(_DWORD *)(a2 + 60) = v3;
      }
      for ( j = v12; j < v3; ++j )
      {
        v19 = (_DWORD *)(*(_DWORD *)(a2 + 64) + 4 * j);
        if ( v19 )
          *v19 = 0;
      }
    }
    v20 = 0;
    for ( *(_DWORD *)(a2 + 56) = v3; v20 < v3; ++v20 )
      *(_DWORD *)(*(_DWORD *)(a2 + 44) + 4 * v20) = -1;
    for ( k = 0; k < v3; ++k )
      *(_DWORD *)(*(_DWORD *)(a2 + 64) + 4 * k) = -1;
    v22 = 0;
    if ( v28 > 0 )
    {
      v23 = 0;
      do
      {
        v24 = 9
            * ((~((*(_DWORD *)(*(_DWORD *)(v23 + *(_DWORD *)(a2 + 16)) + 12)
                 | (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 16) + v23 + 4) + 12) << 16)) << 15)
              + (*(_DWORD *)(*(_DWORD *)(v23 + *(_DWORD *)(a2 + 16)) + 12)
               | (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 16) + v23 + 4) + 12) << 16)))
             ^ ((~((*(_DWORD *)(*(_DWORD *)(v23 + *(_DWORD *)(a2 + 16)) + 12)
                  | (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 16) + v23 + 4) + 12) << 16)) << 15)
               + (*(_DWORD *)(*(_DWORD *)(v23 + *(_DWORD *)(a2 + 16)) + 12)
                | (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 16) + v23 + 4) + 12) << 16))) >> 10));
        v25 = (*(_DWORD *)(a2 + 12) - 1)
            & ((~(((v24 >> 6) ^ v24) << 11) + ((v24 >> 6) ^ v24))
             ^ ((~(((v24 >> 6) ^ v24) << 11) + ((v24 >> 6) ^ v24)) >> 16));
        *(_DWORD *)(*(_DWORD *)(a2 + 64) + 4 * v22) = *(_DWORD *)(*(_DWORD *)(a2 + 44) + 4 * v25);
        *(_DWORD *)(*(_DWORD *)(a2 + 44) + 4 * v25) = v22++;
        v23 += 16;
      }
      while ( v22 < v28 );
    }
  }
}
