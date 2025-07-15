void __userpurge btUnionFind::allocate(btUnionFind *this@<ecx>, int a2@<esi>, int N)
{
  int v3; // ecx
  int v4; // ebx
  int v5; // edi
  int v6; // edx
  _DWORD *v7; // ecx
  int v8; // eax
  _DWORD *v9; // eax
  int v10; // [esp+10h] [ebp-8h]
  _DWORD *v11; // [esp+14h] [ebp-4h]

  v3 = *(_DWORD *)(a2 + 4);
  v4 = N;
  v10 = v3;
  if ( N >= v3 )
  {
    if ( N > v3 && *(_DWORD *)(a2 + 8) < N )
    {
      if ( N )
        v11 = btAlignedAllocInternal(8 * N);
      else
        v11 = 0;
      v5 = *(_DWORD *)(a2 + 4);
      v6 = 0;
      if ( v5 > 0 )
      {
        v7 = v11;
        do
        {
          if ( v7 )
          {
            v8 = *(_DWORD *)(a2 + 12);
            *v7 = *(_DWORD *)(v8 + 8 * v6);
            v4 = N;
            v7[1] = *(_DWORD *)(v8 + 8 * v6 + 4);
          }
          ++v6;
          v7 += 2;
        }
        while ( v6 < v5 );
      }
      if ( *(_DWORD *)(a2 + 12) )
      {
        if ( *(_BYTE *)(a2 + 16) )
          btAlignedFreeInternal(*(void **)(a2 + 12));
        *(_DWORD *)(a2 + 12) = 0;
      }
      v3 = v10;
      *(_BYTE *)(a2 + 16) = 1;
      *(_DWORD *)(a2 + 12) = v11;
      *(_DWORD *)(a2 + 8) = v4;
    }
    while ( v3 < v4 )
    {
      v9 = (_DWORD *)(*(_DWORD *)(a2 + 12) + 8 * v3);
      if ( v9 )
      {
        *v9 = 0;
        v9[1] = 0;
      }
      ++v3;
    }
  }
  *(_DWORD *)(a2 + 4) = v4;
}
