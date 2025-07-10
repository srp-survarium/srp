int __cdecl sub_52B200(int a1, char *a2, char *a3, char **a4)
{
  int v5; // [esp+0h] [ebp-20h]
  int v6; // [esp+4h] [ebp-1Ch]
  int v7; // [esp+8h] [ebp-18h]
  char *v8; // [esp+Ch] [ebp-14h] BYREF
  int v9; // [esp+10h] [ebp-10h]
  _DWORD *v10; // [esp+14h] [ebp-Ch]
  char *v11; // [esp+18h] [ebp-8h]
  char *v12; // [esp+1Ch] [ebp-4h]

  v10 = *(_DWORD **)(a1 + 300);
  if ( !v10 )
    return 23;
  v9 = v10[3];
  v11 = (char *)(*(_DWORD *)(v9 + 12) + *(_DWORD *)(v9 + 4));
  v12 = (char *)(*(_DWORD *)(v9 + 8) + *(_DWORD *)(v9 + 4));
  if ( *(_BYTE *)(v9 + 33) )
  {
    v6 = (**(int (__cdecl ***)(_DWORD, char *, char *, char **))(a1 + 228))(*(_DWORD *)(a1 + 228), v11, v12, &v8);
    v7 = sub_5286F0(a1, *(_DWORD *)(a1 + 228), (int)v11, (int)v12, v6, (int)v8, &v8, 0);
  }
  else
  {
    v7 = sub_525AC0(a1, v10[4], *(_DWORD *)(a1 + 228), v11, v12, &v8, 0);
  }
  if ( v7 )
    return v7;
  if ( v12 == v8 || *(_DWORD *)(a1 + 480) != 3 )
  {
    *(_BYTE *)(v9 + 32) = 0;
    *(_DWORD *)(a1 + 300) = v10[2];
    v10[2] = *(_DWORD *)(a1 + 304);
    *(_DWORD *)(a1 + 304) = v10;
    if ( *(_BYTE *)(v9 + 33) )
    {
      *(_DWORD *)(a1 + 280) = sub_528670;
      v5 = (**(int (__cdecl ***)(_DWORD, char *, char *, char **))(a1 + 144))(*(_DWORD *)(a1 + 144), a2, a3, &v8);
      return sub_5286F0(a1, *(_DWORD *)(a1 + 144), (int)a2, (int)a3, v5, (int)v8, a4, *(_BYTE *)(a1 + 484) == 0);
    }
    else
    {
      *(_DWORD *)(a1 + 280) = sub_527DC0;
      return sub_525AC0(a1, *(_DWORD *)(a1 + 476) != 0, *(_DWORD *)(a1 + 144), a2, a3, a4, *(_BYTE *)(a1 + 484) == 0);
    }
  }
  else
  {
    *(_DWORD *)(v9 + 12) = &v8[-*(_DWORD *)(v9 + 4)];
    return 0;
  }
}
