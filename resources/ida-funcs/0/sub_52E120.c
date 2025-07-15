int __cdecl sub_52E120(int a1)
{
  _DWORD *v2; // [esp+0h] [ebp-14h]
  int v3; // [esp+4h] [ebp-10h]
  _DWORD *v4; // [esp+8h] [ebp-Ch]
  int v5; // [esp+Ch] [ebp-8h]
  _DWORD *v6; // [esp+10h] [ebp-4h]

  v6 = *(_DWORD **)(a1 + 356);
  if ( !v6[46] )
  {
    v6[46] = (*(int (__cdecl **)(int))(a1 + 12))(4 * *(_DWORD *)(a1 + 468));
    if ( !v6[46] )
      return -1;
    *(_DWORD *)v6[46] = 0;
  }
  if ( v6[44] >= v6[43] )
  {
    if ( v6[41] )
    {
      v3 = (*(int (__cdecl **)(_DWORD, int))(a1 + 16))(v6[41], 56 * v6[43]);
      if ( !v3 )
        return -1;
      v6[43] *= 2;
    }
    else
    {
      v3 = (*(int (__cdecl **)(int))(a1 + 12))(896);
      if ( !v3 )
        return -1;
      v6[43] = 32;
    }
    v6[41] = v3;
  }
  v5 = v6[44];
  v6[44] = v5 + 1;
  v4 = (_DWORD *)(v6[41] + 28 * v5);
  if ( v6[45] )
  {
    v2 = (_DWORD *)(v6[41] + 28 * *(_DWORD *)(v6[46] + 4 * v6[45] - 4));
    if ( v2[4] )
      *(_DWORD *)(v6[41] + 28 * v2[4] + 24) = v5;
    if ( !v2[5] )
      v2[3] = v5;
    v2[4] = v5;
    ++v2[5];
  }
  v4[6] = 0;
  v4[5] = 0;
  v4[4] = 0;
  v4[3] = 0;
  return v5;
}
