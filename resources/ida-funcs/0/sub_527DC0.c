int __cdecl sub_527DC0(int a1, char *a2, char *a3, char **a4)
{
  int v5; // [esp+0h] [ebp-4h]

  v5 = sub_525AC0(a1, 0, *(_DWORD *)(a1 + 144), a2, a3, a4, *(_BYTE *)(a1 + 484) == 0);
  if ( v5 || sub_5259B0(a1) )
    return v5;
  else
    return 1;
}
