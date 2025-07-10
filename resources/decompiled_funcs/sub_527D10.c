int __cdecl sub_527D10(int a1, int a2, int a3, int a4)
{
  int v5; // [esp+0h] [ebp-4h]

  v5 = sub_527E30(a1, *(_DWORD *)(a1 + 144), &a2, a3, a4, *(_BYTE *)(a1 + 484) == 0);
  if ( v5 )
    return v5;
  if ( !a2 )
    return 0;
  if ( *(_DWORD *)(a1 + 476) )
  {
    *(_DWORD *)(a1 + 280) = sub_525940;
    return sub_525940(a1, a2, a3, a4);
  }
  else
  {
    *(_DWORD *)(a1 + 280) = sub_527DC0;
    return sub_527DC0(a1, a2, a3, a4);
  }
}
