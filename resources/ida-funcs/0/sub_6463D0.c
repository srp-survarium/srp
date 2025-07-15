int __cdecl sub_6463D0(int a1, int a2, char a3)
{
  int v4; // [esp+0h] [ebp-18h]
  int v5; // [esp+4h] [ebp-14h]
  int v6; // [esp+8h] [ebp-10h] BYREF
  int v7; // [esp+Ch] [ebp-Ch]
  int v8; // [esp+10h] [ebp-8h]
  int v9; // [esp+14h] [ebp-4h]

  if ( *(_DWORD *)(a1 + 304) )
  {
    v7 = *(_DWORD *)(a1 + 304);
    *(_DWORD *)(a1 + 304) = *(_DWORD *)(v7 + 8);
  }
  else
  {
    v7 = (*(int (__cdecl **)(int))(a1 + 12))(24);
    if ( !v7 )
      return 1;
  }
  *(_BYTE *)(a2 + 32) = 1;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(v7 + 8) = *(_DWORD *)(a1 + 300);
  *(_DWORD *)(a1 + 300) = v7;
  *(_DWORD *)(v7 + 12) = a2;
  *(_DWORD *)(v7 + 16) = *(_DWORD *)(a1 + 312);
  *(_BYTE *)(v7 + 20) = a3;
  *(_DWORD *)v7 = 0;
  *(_DWORD *)(v7 + 4) = 0;
  v8 = *(_DWORD *)(a2 + 4);
  v9 = *(_DWORD *)(a2 + 8) + *(_DWORD *)(a2 + 4);
  if ( *(_BYTE *)(a2 + 33) )
  {
    v4 = (**(int (__cdecl ***)(_DWORD, int, int, int *))(a1 + 228))(*(_DWORD *)(a1 + 228), v8, v9, &v6);
    v5 = sub_643A90(a1, *(_DWORD *)(a1 + 228), v8, v9, v4, v6, &v6, 0);
  }
  else
  {
    v5 = sub_640E60(a1, *(_DWORD *)(a1 + 312), *(_DWORD *)(a1 + 228), v8, v9, &v6, 0);
  }
  if ( !v5 )
  {
    if ( v9 == v6 || *(_DWORD *)(a1 + 480) != 3 )
    {
      *(_BYTE *)(a2 + 32) = 0;
      *(_DWORD *)(a1 + 300) = *(_DWORD *)(v7 + 8);
      *(_DWORD *)(v7 + 8) = *(_DWORD *)(a1 + 304);
      *(_DWORD *)(a1 + 304) = v7;
    }
    else
    {
      *(_DWORD *)(a2 + 12) = v6 - v8;
      *(_DWORD *)(a1 + 280) = sub_6465A0;
    }
  }
  return v5;
}
