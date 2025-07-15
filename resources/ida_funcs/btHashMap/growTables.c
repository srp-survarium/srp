void __usercall btHashMap<btInternalVertexPair,btInternalEdge>::growTables(
        btHashMap<btInternalVertexPair,btInternalEdge> *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax
  int v3; // edi
  _DWORD *v4; // ebp
  int v5; // edx
  int v6; // eax
  _DWORD *v7; // ecx
  void *v8; // eax
  _DWORD *v9; // ecx
  int v10; // ebx
  _DWORD *v11; // ebp
  int v12; // edx
  int v13; // eax
  _DWORD *v14; // ecx
  void *v15; // eax
  int i; // eax
  _DWORD *v17; // ecx
  int v18; // eax
  int j; // eax
  int k; // edx
  int v21; // eax
  int v22; // [esp+4h] [ebp-8h]
  int v23; // [esp+8h] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 4);
  v3 = *(_DWORD *)(a2 + 48);
  v22 = v2;
  if ( v3 > v2 )
  {
    if ( *(_DWORD *)(a2 + 8) < v3 )
    {
      if ( v3 )
      {
        ++gNumAlignedAllocs;
        v4 = sAlignedAllocFunc(4 * v3, 16);
      }
      else
      {
        v4 = 0;
      }
      v5 = *(_DWORD *)(a2 + 4);
      v6 = 0;
      if ( v5 > 0 )
      {
        v7 = v4;
        do
        {
          if ( v7 )
            *v7 = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v6);
          ++v6;
          ++v7;
        }
        while ( v6 < v5 );
      }
      v8 = *(void **)(a2 + 12);
      if ( v8 )
      {
        if ( *(_BYTE *)(a2 + 16) )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v8);
        }
        *(_DWORD *)(a2 + 12) = 0;
      }
      v2 = v22;
      *(_BYTE *)(a2 + 16) = 1;
      *(_DWORD *)(a2 + 12) = v4;
      *(_DWORD *)(a2 + 8) = v3;
    }
    for ( ; v2 < v3; ++v2 )
    {
      v9 = (_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v2);
      if ( v9 )
        *v9 = 0;
    }
    *(_DWORD *)(a2 + 4) = v3;
    v10 = *(_DWORD *)(a2 + 24);
    v23 = v10;
    if ( v3 >= v10 )
    {
      if ( v3 > v10 && *(_DWORD *)(a2 + 28) < v3 )
      {
        if ( v3 )
        {
          ++gNumAlignedAllocs;
          v11 = sAlignedAllocFunc(4 * v3, 16);
        }
        else
        {
          v11 = 0;
        }
        v12 = *(_DWORD *)(a2 + 24);
        v13 = 0;
        if ( v12 > 0 )
        {
          v14 = v11;
          do
          {
            if ( v14 )
            {
              *v14 = *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * v13);
              v10 = v23;
            }
            ++v13;
            ++v14;
          }
          while ( v13 < v12 );
        }
        v15 = *(void **)(a2 + 32);
        if ( v15 )
        {
          if ( *(_BYTE *)(a2 + 36) )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v15);
          }
          *(_DWORD *)(a2 + 32) = 0;
        }
        *(_BYTE *)(a2 + 36) = 1;
        *(_DWORD *)(a2 + 32) = v11;
        *(_DWORD *)(a2 + 28) = v3;
      }
      for ( i = v10; i < v3; ++i )
      {
        v17 = (_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * i);
        if ( v17 )
          *v17 = 0;
      }
    }
    v18 = 0;
    for ( *(_DWORD *)(a2 + 24) = v3; v18 < v3; ++v18 )
      *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v18) = -1;
    for ( j = 0; j < v3; ++j )
      *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * j) = -1;
    for ( k = 0; k < v22; ++k )
    {
      v21 = (*(_DWORD *)(a2 + 48) - 1)
          & (*(__int16 *)(4 * k + *(_DWORD *)(a2 + 72)) + (*(__int16 *)(*(_DWORD *)(a2 + 72) + 4 * k + 2) << 16));
      *(_DWORD *)(4 * k + *(_DWORD *)(a2 + 32)) = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v21);
      *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v21) = k;
    }
  }
}


void __usercall btHashMap<btHashPtr,btCollisionShape *>::growTables(btHashMap<btHashPtr,int> *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  int v3; // edi
  _DWORD *v4; // ebp
  int v5; // edx
  int v6; // eax
  _DWORD *v7; // ecx
  void *v8; // eax
  _DWORD *v9; // ecx
  int v10; // ebx
  _DWORD *v11; // ebp
  int v12; // edx
  int v13; // eax
  _DWORD *v14; // ecx
  void *v15; // eax
  int i; // eax
  _DWORD *v17; // ecx
  int v18; // eax
  int j; // eax
  int k; // edx
  int v21; // eax
  int v22; // ecx
  int v23; // [esp+4h] [ebp-8h]
  int v24; // [esp+8h] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 4);
  v3 = *(_DWORD *)(a2 + 48);
  v23 = v2;
  if ( v3 > v2 )
  {
    if ( *(_DWORD *)(a2 + 8) < v3 )
    {
      if ( v3 )
      {
        ++gNumAlignedAllocs;
        v4 = sAlignedAllocFunc(4 * v3, 16);
      }
      else
      {
        v4 = 0;
      }
      v5 = *(_DWORD *)(a2 + 4);
      v6 = 0;
      if ( v5 > 0 )
      {
        v7 = v4;
        do
        {
          if ( v7 )
            *v7 = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v6);
          ++v6;
          ++v7;
        }
        while ( v6 < v5 );
      }
      v8 = *(void **)(a2 + 12);
      if ( v8 )
      {
        if ( *(_BYTE *)(a2 + 16) )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v8);
        }
        *(_DWORD *)(a2 + 12) = 0;
      }
      v2 = v23;
      *(_BYTE *)(a2 + 16) = 1;
      *(_DWORD *)(a2 + 12) = v4;
      *(_DWORD *)(a2 + 8) = v3;
    }
    for ( ; v2 < v3; ++v2 )
    {
      v9 = (_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v2);
      if ( v9 )
        *v9 = 0;
    }
    *(_DWORD *)(a2 + 4) = v3;
    v10 = *(_DWORD *)(a2 + 24);
    v24 = v10;
    if ( v3 >= v10 )
    {
      if ( v3 > v10 && *(_DWORD *)(a2 + 28) < v3 )
      {
        if ( v3 )
        {
          ++gNumAlignedAllocs;
          v11 = sAlignedAllocFunc(4 * v3, 16);
        }
        else
        {
          v11 = 0;
        }
        v12 = *(_DWORD *)(a2 + 24);
        v13 = 0;
        if ( v12 > 0 )
        {
          v14 = v11;
          do
          {
            if ( v14 )
            {
              *v14 = *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * v13);
              v10 = v24;
            }
            ++v13;
            ++v14;
          }
          while ( v13 < v12 );
        }
        v15 = *(void **)(a2 + 32);
        if ( v15 )
        {
          if ( *(_BYTE *)(a2 + 36) )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v15);
          }
          *(_DWORD *)(a2 + 32) = 0;
        }
        *(_BYTE *)(a2 + 36) = 1;
        *(_DWORD *)(a2 + 32) = v11;
        *(_DWORD *)(a2 + 28) = v3;
      }
      for ( i = v10; i < v3; ++i )
      {
        v17 = (_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * i);
        if ( v17 )
          *v17 = 0;
      }
    }
    v18 = 0;
    for ( *(_DWORD *)(a2 + 24) = v3; v18 < v3; ++v18 )
      *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v18) = -1;
    for ( j = 0; j < v3; ++j )
      *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * j) = -1;
    for ( k = 0; k < v23; ++k )
    {
      v21 = ~((((9
               * ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * k) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * k))
                ^ ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * k) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * k)) >> 10))) >> 6)
             ^ (9
              * ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * k) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * k))
               ^ ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * k) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * k)) >> 10)))) << 11)
          + (((9
             * ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * k) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * k))
              ^ ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * k) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * k)) >> 10))) >> 6)
           ^ (9
            * ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * k) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * k))
             ^ ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * k) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * k)) >> 10))));
      v22 = (*(_DWORD *)(a2 + 48) - 1) & (v21 ^ (v21 >> 16));
      *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * k) = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v22);
      *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v22) = k;
    }
  }
}


void __usercall btHashMap<btHashKey<btTriIndex>,btTriIndex>::growTables(
        btHashMap<btHashKey<btTriIndex>,btTriIndex> *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax
  int v3; // edi
  _DWORD *v4; // ebp
  int v5; // edx
  int v6; // eax
  _DWORD *v7; // ecx
  void *v8; // eax
  _DWORD *v9; // ecx
  int v10; // ebx
  _DWORD *v11; // ebp
  int v12; // edx
  int v13; // eax
  _DWORD *v14; // ecx
  void *v15; // eax
  int i; // eax
  _DWORD *v17; // ecx
  int v18; // eax
  int j; // eax
  int k; // edx
  int v21; // eax
  int v22; // ecx
  int v23; // [esp+4h] [ebp-8h]
  int v24; // [esp+8h] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 4);
  v3 = *(_DWORD *)(a2 + 48);
  v23 = v2;
  if ( v3 > v2 )
  {
    if ( *(_DWORD *)(a2 + 8) < v3 )
    {
      if ( v3 )
      {
        ++gNumAlignedAllocs;
        v4 = sAlignedAllocFunc(4 * v3, 16);
      }
      else
      {
        v4 = 0;
      }
      v5 = *(_DWORD *)(a2 + 4);
      v6 = 0;
      if ( v5 > 0 )
      {
        v7 = v4;
        do
        {
          if ( v7 )
            *v7 = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v6);
          ++v6;
          ++v7;
        }
        while ( v6 < v5 );
      }
      v8 = *(void **)(a2 + 12);
      if ( v8 )
      {
        if ( *(_BYTE *)(a2 + 16) )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v8);
        }
        *(_DWORD *)(a2 + 12) = 0;
      }
      v2 = v23;
      *(_BYTE *)(a2 + 16) = 1;
      *(_DWORD *)(a2 + 12) = v4;
      *(_DWORD *)(a2 + 8) = v3;
    }
    for ( ; v2 < v3; ++v2 )
    {
      v9 = (_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v2);
      if ( v9 )
        *v9 = 0;
    }
    *(_DWORD *)(a2 + 4) = v3;
    v10 = *(_DWORD *)(a2 + 24);
    v24 = v10;
    if ( v3 >= v10 )
    {
      if ( v3 > v10 && *(_DWORD *)(a2 + 28) < v3 )
      {
        if ( v3 )
        {
          ++gNumAlignedAllocs;
          v11 = sAlignedAllocFunc(4 * v3, 16);
        }
        else
        {
          v11 = 0;
        }
        v12 = *(_DWORD *)(a2 + 24);
        v13 = 0;
        if ( v12 > 0 )
        {
          v14 = v11;
          do
          {
            if ( v14 )
            {
              *v14 = *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * v13);
              v10 = v24;
            }
            ++v13;
            ++v14;
          }
          while ( v13 < v12 );
        }
        v15 = *(void **)(a2 + 32);
        if ( v15 )
        {
          if ( *(_BYTE *)(a2 + 36) )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v15);
          }
          *(_DWORD *)(a2 + 32) = 0;
        }
        *(_BYTE *)(a2 + 36) = 1;
        *(_DWORD *)(a2 + 32) = v11;
        *(_DWORD *)(a2 + 28) = v3;
      }
      for ( i = v10; i < v3; ++i )
      {
        v17 = (_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * i);
        if ( v17 )
          *v17 = 0;
      }
    }
    v18 = 0;
    for ( *(_DWORD *)(a2 + 24) = v3; v18 < v3; ++v18 )
      *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v18) = -1;
    for ( j = 0; j < v3; ++j )
      *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * j) = -1;
    for ( k = 0; k < v23; ++k )
    {
      v21 = ~((((9
               * ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * k) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * k))
                ^ ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * k) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * k)) >> 10))) >> 6)
             ^ (9
              * ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * k) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * k))
               ^ ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * k) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * k)) >> 10)))) << 11)
          + (((9
             * ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * k) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * k))
              ^ ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * k) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * k)) >> 10))) >> 6)
           ^ (9
            * ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * k) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * k))
             ^ ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * k) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * k)) >> 10))));
      v22 = (*(_DWORD *)(a2 + 48) - 1) & (v21 ^ (v21 >> 16));
      *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * k) = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v22);
      *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v22) = k;
    }
  }
}
