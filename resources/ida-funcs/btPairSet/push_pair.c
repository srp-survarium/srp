void __userpurge btPairSet::push_pair(btPairSet *this@<ecx>, int a2@<esi>, int index1, int index2)
{
  int v4; // ecx
  int v5; // eax
  int v6; // ebx
  int v7; // edi
  int v8; // edx
  _DWORD *v9; // ecx
  _DWORD *v10; // eax
  _DWORD *v11; // eax
  int v12; // [esp+0h] [ebp-8h]
  _DWORD *v13; // [esp+4h] [ebp-4h]

  v4 = *(_DWORD *)(a2 + 8);
  v5 = *(_DWORD *)(a2 + 4);
  if ( v5 == v4 )
  {
    v6 = v5 ? 2 * v5 : 1;
    v12 = v6;
    if ( v4 < v6 )
    {
      if ( v6 )
        v13 = btAlignedAllocInternal(8 * v6);
      else
        v13 = 0;
      v7 = *(_DWORD *)(a2 + 4);
      v8 = 0;
      if ( v7 > 0 )
      {
        v9 = v13;
        do
        {
          if ( v9 )
          {
            v10 = (_DWORD *)(*(_DWORD *)(a2 + 12) + 8 * v8);
            *v9 = *v10;
            v6 = v12;
            v9[1] = v10[1];
          }
          ++v8;
          v9 += 2;
        }
        while ( v8 < v7 );
      }
      if ( *(_DWORD *)(a2 + 12) )
      {
        if ( *(_BYTE *)(a2 + 16) )
          btAlignedFreeInternal(*(void **)(a2 + 12));
        *(_DWORD *)(a2 + 12) = 0;
      }
      *(_BYTE *)(a2 + 16) = 1;
      *(_DWORD *)(a2 + 12) = v13;
      *(_DWORD *)(a2 + 8) = v6;
    }
  }
  v11 = (_DWORD *)(*(_DWORD *)(a2 + 12) + 8 * *(_DWORD *)(a2 + 4));
  if ( v11 )
  {
    *v11 = index1;
    v11[1] = index2;
  }
  ++*(_DWORD *)(a2 + 4);
}
