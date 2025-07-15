void __usercall btHashMap<btInternalVertexPair,btInternalEdge>::growTables(
        btHashMap<btInternalVertexPair,btInternalEdge> *this@<ecx>,
        int a2@<esi>)
{
  int v2; // ecx
  int v3; // edi
  int v4; // edx
  int v5; // eax
  _DWORD *v6; // ecx
  _DWORD *v7; // eax
  int v8; // ebx
  int v9; // edx
  int v10; // eax
  _DWORD *v11; // ecx
  int i; // ecx
  _DWORD *v13; // eax
  int v14; // edx
  int v15; // eax
  int j; // eax
  int v17; // eax
  int v18; // [esp+4h] [ebp-Ch]
  int v19; // [esp+8h] [ebp-8h]
  _DWORD *v20; // [esp+Ch] [ebp-4h]
  _DWORD *v21; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 4);
  v3 = *(_DWORD *)(a2 + 48);
  v19 = v2;
  if ( v3 > v2 )
  {
    if ( *(_DWORD *)(a2 + 8) < v3 )
    {
      if ( v3 )
        v20 = btAlignedAllocInternal(4 * v3);
      else
        v20 = 0;
      v4 = *(_DWORD *)(a2 + 4);
      v5 = 0;
      if ( v4 > 0 )
      {
        v6 = v20;
        do
        {
          if ( v6 )
            *v6 = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v5);
          ++v5;
          ++v6;
        }
        while ( v5 < v4 );
      }
      if ( *(_DWORD *)(a2 + 12) )
      {
        if ( *(_BYTE *)(a2 + 16) )
          btAlignedFreeInternal(*(void **)(a2 + 12));
        *(_DWORD *)(a2 + 12) = 0;
      }
      v2 = v19;
      *(_BYTE *)(a2 + 16) = 1;
      *(_DWORD *)(a2 + 12) = v20;
      *(_DWORD *)(a2 + 8) = v3;
    }
    while ( v2 < v3 )
    {
      v7 = (_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v2);
      if ( v7 )
        *v7 = 0;
      ++v2;
    }
    *(_DWORD *)(a2 + 4) = v3;
    v8 = *(_DWORD *)(a2 + 24);
    v18 = v8;
    if ( v3 >= v8 )
    {
      if ( v3 > v8 && *(_DWORD *)(a2 + 28) < v3 )
      {
        if ( v3 )
          v21 = btAlignedAllocInternal(4 * v3);
        else
          v21 = 0;
        v9 = *(_DWORD *)(a2 + 24);
        v10 = 0;
        if ( v9 > 0 )
        {
          v11 = v21;
          do
          {
            if ( v11 )
            {
              *v11 = *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * v10);
              v8 = v18;
            }
            ++v10;
            ++v11;
          }
          while ( v10 < v9 );
        }
        if ( *(_DWORD *)(a2 + 32) )
        {
          if ( *(_BYTE *)(a2 + 36) )
            btAlignedFreeInternal(*(void **)(a2 + 32));
          *(_DWORD *)(a2 + 32) = 0;
        }
        *(_BYTE *)(a2 + 36) = 1;
        *(_DWORD *)(a2 + 32) = v21;
        *(_DWORD *)(a2 + 28) = v3;
      }
      for ( i = v8; i < v3; ++i )
      {
        v13 = (_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * i);
        if ( v13 )
          *v13 = 0;
      }
    }
    v14 = 0;
    v15 = 0;
    for ( *(_DWORD *)(a2 + 24) = v3; v15 < v3; ++v15 )
      *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v15) = -1;
    for ( j = 0; j < v3; ++j )
      *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * j) = -1;
    if ( v19 > 0 )
    {
      do
      {
        v17 = 4
            * ((*(_DWORD *)(a2 + 48) - 1)
             & (*(__int16 *)(4 * v14 + *(_DWORD *)(a2 + 72)) + (*(__int16 *)(4 * v14 + *(_DWORD *)(a2 + 72) + 2) << 16)));
        *(_DWORD *)(4 * v14 + *(_DWORD *)(a2 + 32)) = *(_DWORD *)(v17 + *(_DWORD *)(a2 + 12));
        *(_DWORD *)(v17 + *(_DWORD *)(a2 + 12)) = v14++;
      }
      while ( v14 < v19 );
    }
  }
}


void __usercall btHashMap<btHashPtr,btCollisionShape *>::growTables(
        btHashMap<btHashPtr,btCollisionShape *> *this@<ecx>,
        int a2@<esi>)
{
  int v2; // ecx
  int v3; // edi
  int v4; // edx
  int v5; // eax
  _DWORD *v6; // ecx
  _DWORD *v7; // eax
  int v8; // ebx
  int v9; // edx
  int v10; // eax
  _DWORD *v11; // ecx
  int i; // ecx
  _DWORD *v13; // eax
  int v14; // edx
  int v15; // eax
  int j; // eax
  int v17; // eax
  int v18; // eax
  int v19; // [esp+4h] [ebp-Ch]
  int v20; // [esp+8h] [ebp-8h]
  _DWORD *v21; // [esp+Ch] [ebp-4h]
  _DWORD *v22; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 4);
  v3 = *(_DWORD *)(a2 + 48);
  v20 = v2;
  if ( v3 > v2 )
  {
    if ( *(_DWORD *)(a2 + 8) < v3 )
    {
      if ( v3 )
        v21 = btAlignedAllocInternal(4 * v3);
      else
        v21 = 0;
      v4 = *(_DWORD *)(a2 + 4);
      v5 = 0;
      if ( v4 > 0 )
      {
        v6 = v21;
        do
        {
          if ( v6 )
            *v6 = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v5);
          ++v5;
          ++v6;
        }
        while ( v5 < v4 );
      }
      if ( *(_DWORD *)(a2 + 12) )
      {
        if ( *(_BYTE *)(a2 + 16) )
          btAlignedFreeInternal(*(void **)(a2 + 12));
        *(_DWORD *)(a2 + 12) = 0;
      }
      v2 = v20;
      *(_BYTE *)(a2 + 16) = 1;
      *(_DWORD *)(a2 + 12) = v21;
      *(_DWORD *)(a2 + 8) = v3;
    }
    while ( v2 < v3 )
    {
      v7 = (_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v2);
      if ( v7 )
        *v7 = 0;
      ++v2;
    }
    *(_DWORD *)(a2 + 4) = v3;
    v8 = *(_DWORD *)(a2 + 24);
    v19 = v8;
    if ( v3 >= v8 )
    {
      if ( v3 > v8 && *(_DWORD *)(a2 + 28) < v3 )
      {
        if ( v3 )
          v22 = btAlignedAllocInternal(4 * v3);
        else
          v22 = 0;
        v9 = *(_DWORD *)(a2 + 24);
        v10 = 0;
        if ( v9 > 0 )
        {
          v11 = v22;
          do
          {
            if ( v11 )
            {
              *v11 = *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * v10);
              v8 = v19;
            }
            ++v10;
            ++v11;
          }
          while ( v10 < v9 );
        }
        if ( *(_DWORD *)(a2 + 32) )
        {
          if ( *(_BYTE *)(a2 + 36) )
            btAlignedFreeInternal(*(void **)(a2 + 32));
          *(_DWORD *)(a2 + 32) = 0;
        }
        *(_BYTE *)(a2 + 36) = 1;
        *(_DWORD *)(a2 + 32) = v22;
        *(_DWORD *)(a2 + 28) = v3;
      }
      for ( i = v8; i < v3; ++i )
      {
        v13 = (_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * i);
        if ( v13 )
          *v13 = 0;
      }
    }
    v14 = 0;
    v15 = 0;
    for ( *(_DWORD *)(a2 + 24) = v3; v15 < v3; ++v15 )
      *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v15) = -1;
    for ( j = 0; j < v3; ++j )
      *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * j) = -1;
    if ( v20 > 0 )
    {
      do
      {
        v17 = ~((((9
                 * ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * v14) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * v14))
                  ^ ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * v14) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * v14)) >> 10))) >> 6)
               ^ (9
                * ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * v14) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * v14))
                 ^ ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * v14) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * v14)) >> 10)))) << 11)
            + (((9
               * ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * v14) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * v14))
                ^ ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * v14) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * v14)) >> 10))) >> 6)
             ^ (9
              * ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * v14) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * v14))
               ^ ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * v14) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 8 * v14)) >> 10))));
        v18 = 4 * ((*(_DWORD *)(a2 + 48) - 1) & (v17 ^ (v17 >> 16)));
        *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * v14) = *(_DWORD *)(v18 + *(_DWORD *)(a2 + 12));
        *(_DWORD *)(v18 + *(_DWORD *)(a2 + 12)) = v14++;
      }
      while ( v14 < v20 );
    }
  }
}


void __usercall btHashMap<btHashKey<btTriIndex>,btTriIndex>::growTables(
        btHashMap<btHashKey<btTriIndex>,btTriIndex> *this@<ecx>,
        int a2@<esi>)
{
  int v2; // ecx
  int v3; // edi
  int v4; // edx
  int v5; // eax
  _DWORD *v6; // ecx
  _DWORD *v7; // eax
  int v8; // ebx
  int v9; // edx
  int v10; // eax
  _DWORD *v11; // ecx
  int i; // ecx
  _DWORD *v13; // eax
  int v14; // edx
  int v15; // eax
  int j; // eax
  int v17; // eax
  int v18; // eax
  int v19; // [esp+4h] [ebp-Ch]
  int v20; // [esp+8h] [ebp-8h]
  _DWORD *v21; // [esp+Ch] [ebp-4h]
  _DWORD *v22; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 4);
  v3 = *(_DWORD *)(a2 + 48);
  v20 = v2;
  if ( v3 > v2 )
  {
    if ( *(_DWORD *)(a2 + 8) < v3 )
    {
      if ( v3 )
        v21 = btAlignedAllocInternal(4 * v3);
      else
        v21 = 0;
      v4 = *(_DWORD *)(a2 + 4);
      v5 = 0;
      if ( v4 > 0 )
      {
        v6 = v21;
        do
        {
          if ( v6 )
            *v6 = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v5);
          ++v5;
          ++v6;
        }
        while ( v5 < v4 );
      }
      if ( *(_DWORD *)(a2 + 12) )
      {
        if ( *(_BYTE *)(a2 + 16) )
          btAlignedFreeInternal(*(void **)(a2 + 12));
        *(_DWORD *)(a2 + 12) = 0;
      }
      v2 = v20;
      *(_BYTE *)(a2 + 16) = 1;
      *(_DWORD *)(a2 + 12) = v21;
      *(_DWORD *)(a2 + 8) = v3;
    }
    while ( v2 < v3 )
    {
      v7 = (_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v2);
      if ( v7 )
        *v7 = 0;
      ++v2;
    }
    *(_DWORD *)(a2 + 4) = v3;
    v8 = *(_DWORD *)(a2 + 24);
    v19 = v8;
    if ( v3 >= v8 )
    {
      if ( v3 > v8 && *(_DWORD *)(a2 + 28) < v3 )
      {
        if ( v3 )
          v22 = btAlignedAllocInternal(4 * v3);
        else
          v22 = 0;
        v9 = *(_DWORD *)(a2 + 24);
        v10 = 0;
        if ( v9 > 0 )
        {
          v11 = v22;
          do
          {
            if ( v11 )
            {
              *v11 = *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * v10);
              v8 = v19;
            }
            ++v10;
            ++v11;
          }
          while ( v10 < v9 );
        }
        if ( *(_DWORD *)(a2 + 32) )
        {
          if ( *(_BYTE *)(a2 + 36) )
            btAlignedFreeInternal(*(void **)(a2 + 32));
          *(_DWORD *)(a2 + 32) = 0;
        }
        *(_BYTE *)(a2 + 36) = 1;
        *(_DWORD *)(a2 + 32) = v22;
        *(_DWORD *)(a2 + 28) = v3;
      }
      for ( i = v8; i < v3; ++i )
      {
        v13 = (_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * i);
        if ( v13 )
          *v13 = 0;
      }
    }
    v14 = 0;
    v15 = 0;
    for ( *(_DWORD *)(a2 + 24) = v3; v15 < v3; ++v15 )
      *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v15) = -1;
    for ( j = 0; j < v3; ++j )
      *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * j) = -1;
    if ( v20 > 0 )
    {
      do
      {
        v17 = ~((((9
                 * ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * v14) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * v14))
                  ^ ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * v14) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * v14)) >> 10))) >> 6)
               ^ (9
                * ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * v14) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * v14))
                 ^ ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * v14) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * v14)) >> 10)))) << 11)
            + (((9
               * ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * v14) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * v14))
                ^ ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * v14) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * v14)) >> 10))) >> 6)
             ^ (9
              * ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * v14) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * v14))
               ^ ((~(*(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * v14) << 15) + *(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * v14)) >> 10))));
        v18 = 4 * ((*(_DWORD *)(a2 + 48) - 1) & (v17 ^ (v17 >> 16)));
        *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * v14) = *(_DWORD *)(v18 + *(_DWORD *)(a2 + 12));
        *(_DWORD *)(v18 + *(_DWORD *)(a2 + 12)) = v14++;
      }
      while ( v14 < v20 );
    }
  }
}
