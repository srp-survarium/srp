void __usercall btHashedOverlappingPairCache::growTables(btHashedOverlappingPairCache *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // edx
  int v6; // eax
  _DWORD *v7; // ecx
  int i; // ecx
  _DWORD *v9; // eax
  int v10; // ebx
  int v11; // edx
  int v12; // eax
  _DWORD *v13; // ecx
  int j; // ecx
  _DWORD *v15; // eax
  int v16; // eax
  int k; // eax
  int v18; // edi
  int m; // edx
  int v20; // eax
  int v21; // eax
  int v22; // [esp+4h] [ebp-Ch]
  int v23; // [esp+4h] [ebp-Ch]
  int v24; // [esp+8h] [ebp-8h]
  _DWORD *v25; // [esp+Ch] [ebp-4h]
  _DWORD *v26; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 36);
  v3 = *(_DWORD *)(a2 + 12);
  v24 = v2;
  if ( v2 < v3 )
  {
    v4 = *(_DWORD *)(a2 + 36);
    v22 = v4;
    if ( v3 >= v2 )
    {
      if ( v3 > v2 && *(_DWORD *)(a2 + 40) < v3 )
      {
        if ( v3 )
          v25 = btAlignedAllocInternal(4 * v3);
        else
          v25 = 0;
        v5 = *(_DWORD *)(a2 + 36);
        v6 = 0;
        if ( v5 > 0 )
        {
          v7 = v25;
          do
          {
            if ( v7 )
            {
              *v7 = *(_DWORD *)(*(_DWORD *)(a2 + 44) + 4 * v6);
              v4 = v22;
            }
            ++v6;
            ++v7;
          }
          while ( v6 < v5 );
        }
        if ( *(_DWORD *)(a2 + 44) )
        {
          if ( *(_BYTE *)(a2 + 48) )
            btAlignedFreeInternal(*(void **)(a2 + 44));
          *(_DWORD *)(a2 + 44) = 0;
        }
        *(_BYTE *)(a2 + 48) = 1;
        *(_DWORD *)(a2 + 44) = v25;
        *(_DWORD *)(a2 + 40) = v3;
      }
      for ( i = v4; i < v3; ++i )
      {
        v9 = (_DWORD *)(*(_DWORD *)(a2 + 44) + 4 * i);
        if ( v9 )
          *v9 = 0;
      }
    }
    *(_DWORD *)(a2 + 36) = v3;
    v10 = *(_DWORD *)(a2 + 56);
    v23 = v10;
    if ( v3 >= v10 )
    {
      if ( v3 > v10 && *(_DWORD *)(a2 + 60) < v3 )
      {
        if ( v3 )
          v26 = btAlignedAllocInternal(4 * v3);
        else
          v26 = 0;
        v11 = *(_DWORD *)(a2 + 56);
        v12 = 0;
        if ( v11 > 0 )
        {
          v13 = v26;
          do
          {
            if ( v13 )
            {
              *v13 = *(_DWORD *)(*(_DWORD *)(a2 + 64) + 4 * v12);
              v10 = v23;
            }
            ++v12;
            ++v13;
          }
          while ( v12 < v11 );
        }
        if ( *(_DWORD *)(a2 + 64) )
        {
          if ( *(_BYTE *)(a2 + 68) )
            btAlignedFreeInternal(*(void **)(a2 + 64));
          *(_DWORD *)(a2 + 64) = 0;
        }
        *(_BYTE *)(a2 + 68) = 1;
        *(_DWORD *)(a2 + 64) = v26;
        *(_DWORD *)(a2 + 60) = v3;
      }
      for ( j = v10; j < v3; ++j )
      {
        v15 = (_DWORD *)(*(_DWORD *)(a2 + 64) + 4 * j);
        if ( v15 )
          *v15 = 0;
      }
    }
    v16 = 0;
    for ( *(_DWORD *)(a2 + 56) = v3; v16 < v3; ++v16 )
      *(_DWORD *)(*(_DWORD *)(a2 + 44) + 4 * v16) = -1;
    for ( k = 0; k < v3; ++k )
      *(_DWORD *)(*(_DWORD *)(a2 + 64) + 4 * k) = -1;
    v18 = 0;
    for ( m = 0; m < v24; v18 += 16 )
    {
      v20 = 9
          * ((~((*(_DWORD *)(*(_DWORD *)(v18 + *(_DWORD *)(a2 + 16)) + 12)
               | (*(_DWORD *)(*(_DWORD *)(v18 + *(_DWORD *)(a2 + 16) + 4) + 12) << 16)) << 15)
            + (*(_DWORD *)(*(_DWORD *)(v18 + *(_DWORD *)(a2 + 16)) + 12)
             | (*(_DWORD *)(*(_DWORD *)(v18 + *(_DWORD *)(a2 + 16) + 4) + 12) << 16)))
           ^ ((~((*(_DWORD *)(*(_DWORD *)(v18 + *(_DWORD *)(a2 + 16)) + 12)
                | (*(_DWORD *)(*(_DWORD *)(v18 + *(_DWORD *)(a2 + 16) + 4) + 12) << 16)) << 15)
             + (*(_DWORD *)(*(_DWORD *)(v18 + *(_DWORD *)(a2 + 16)) + 12)
              | (*(_DWORD *)(*(_DWORD *)(v18 + *(_DWORD *)(a2 + 16) + 4) + 12) << 16))) >> 10));
      v21 = 4
          * ((*(_DWORD *)(a2 + 12) - 1)
           & ((~(((v20 >> 6) ^ v20) << 11) + ((v20 >> 6) ^ v20))
            ^ ((~(((v20 >> 6) ^ v20) << 11) + ((v20 >> 6) ^ v20)) >> 16)));
      *(_DWORD *)(*(_DWORD *)(a2 + 64) + 4 * m) = *(_DWORD *)(v21 + *(_DWORD *)(a2 + 44));
      *(_DWORD *)(v21 + *(_DWORD *)(a2 + 44)) = m++;
    }
  }
}
