int __cdecl sub_525940(int a1, int a2, int a3, int a4)
{
  int v5; // [esp+0h] [ebp-4h]

  v5 = sub_525AC0(a1, 1, *(_DWORD *)(a1 + 144), a2, a3, a4, *(_BYTE *)(a1 + 484) == 0);
  if ( v5 || (unsigned __int8)sub_5259B0(a1) )
    return v5;
  else
    return 1;
}
