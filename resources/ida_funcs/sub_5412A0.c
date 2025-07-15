int (__cdecl **__cdecl sub_5412A0(int a1, int a2, int a3))(int, int, int, int)
{
  char v4[127]; // [esp+0h] [ebp-90h] BYREF
  char v5; // [esp+7Fh] [ebp-11h] BYREF
  int v6; // [esp+88h] [ebp-8h]
  char *v7; // [esp+8Ch] [ebp-4h] BYREF

  v7 = v4;
  (*(void (__cdecl **)(int, int *, int, char **, char *))(a1 + 60))(a1, &a2, a3, &v7, &v5);
  if ( a2 != a3 )
    return 0;
  *v7 = 0;
  if ( sub_540670(v4, "UTF-16") && *(_DWORD *)(a1 + 68) == 2 )
    return (int (__cdecl **)(int, int, int, int))a1;
  v6 = sub_540610((int)v4);
  if ( v6 == -1 )
    return 0;
  else
    return off_88BED4[v6];
}
