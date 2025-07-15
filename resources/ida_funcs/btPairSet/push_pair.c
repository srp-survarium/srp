void __userpurge btPairSet::push_pair(btPairSet *this@<ecx>, int a2@<esi>, int index1, int index2)
{
  int v4; // ecx
  int v5; // eax
  int v6; // ebp
  _DWORD *v7; // ebx
  int v8; // edi
  int v9; // ecx
  _DWORD *v10; // eax
  int v11; // edx
  void *v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // [esp+Ch] [ebp-4h]

  v4 = *(_DWORD *)(a2 + 8);
  v5 = *(_DWORD *)(a2 + 4);
  if ( v5 == v4 )
  {
    v6 = 2 * v5;
    if ( !v5 )
      v6 = 1;
    if ( v4 < v6 )
    {
      if ( v6 )
      {
        ++gNumAlignedAllocs;
        v7 = sAlignedAllocFunc(8 * v6, 16);
        v14 = v7;
      }
      else
      {
        v7 = 0;
        v14 = 0;
      }
      v8 = *(_DWORD *)(a2 + 4);
      v9 = 0;
      if ( v8 > 0 )
      {
        v10 = v7;
        do
        {
          if ( v10 )
          {
            v11 = *(_DWORD *)(a2 + 12);
            *v10 = *(_DWORD *)(v11 + 8 * v9);
            v10[1] = *(_DWORD *)(v11 + 8 * v9 + 4);
          }
          ++v9;
          v10 += 2;
        }
        while ( v9 < v8 );
        v7 = v14;
      }
      v12 = *(void **)(a2 + 12);
      if ( v12 )
      {
        if ( *(_BYTE *)(a2 + 16) )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v12);
        }
        *(_DWORD *)(a2 + 12) = 0;
      }
      *(_BYTE *)(a2 + 16) = 1;
      *(_DWORD *)(a2 + 12) = v7;
      *(_DWORD *)(a2 + 8) = v6;
    }
  }
  v13 = (_DWORD *)(*(_DWORD *)(a2 + 12) + 8 * *(_DWORD *)(a2 + 4));
  if ( v13 )
  {
    *v13 = index1;
    v13[1] = index2;
  }
  ++*(_DWORD *)(a2 + 4);
}
