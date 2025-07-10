void __userpurge btUnionFind::allocate(btUnionFind *this@<ecx>, int a2@<esi>, int N)
{
  int v4; // ebp
  int v5; // edi
  int v6; // eax
  _DWORD *v7; // ecx
  int v8; // edx
  void *v9; // eax
  int i; // ecx
  _DWORD *v11; // eax
  int v12; // [esp+8h] [ebp-Ch]
  _DWORD *Na; // [esp+18h] [ebp+4h]

  v4 = *(_DWORD *)(a2 + 4);
  v12 = v4;
  if ( N < v4 )
  {
    *(_DWORD *)(a2 + 4) = N;
  }
  else
  {
    if ( N > v4 && *(_DWORD *)(a2 + 8) < N )
    {
      if ( N )
      {
        ++gNumAlignedAllocs;
        Na = sAlignedAllocFunc(8 * N, 16);
      }
      else
      {
        Na = 0;
      }
      v5 = *(_DWORD *)(a2 + 4);
      v6 = 0;
      if ( v5 > 0 )
      {
        v7 = Na;
        do
        {
          if ( v7 )
          {
            v8 = *(_DWORD *)(a2 + 12);
            *v7 = *(_DWORD *)(v8 + 8 * v6);
            v4 = v12;
            v7[1] = *(_DWORD *)(v8 + 8 * v6 + 4);
          }
          ++v6;
          v7 += 2;
        }
        while ( v6 < v5 );
      }
      v9 = *(void **)(a2 + 12);
      if ( v9 )
      {
        if ( *(_BYTE *)(a2 + 16) )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v9);
        }
        *(_DWORD *)(a2 + 12) = 0;
      }
      *(_BYTE *)(a2 + 16) = 1;
      *(_DWORD *)(a2 + 12) = Na;
      *(_DWORD *)(a2 + 8) = N;
    }
    for ( i = v4; i < N; ++i )
    {
      v11 = (_DWORD *)(*(_DWORD *)(a2 + 12) + 8 * i);
      if ( v11 )
      {
        *v11 = 0;
        v11[1] = 0;
      }
    }
    *(_DWORD *)(a2 + 4) = N;
  }
}
