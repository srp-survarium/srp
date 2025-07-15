int __cdecl sub_643160(int a1, int a2, int a3, _DWORD *a4)
{
  int v5; // [esp+0h] [ebp-4h]

  v5 = sub_640E60(a1, 0, *(_DWORD *)(a1 + 144), a2, a3, a4, *(_BYTE *)(a1 + 484) == 0);
  if ( v5 || sub_640D50(a1) )
    return v5;
  else
    return 1;
}
