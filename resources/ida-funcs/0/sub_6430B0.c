int __cdecl sub_6430B0(int a1, int a2, int a3, int a4)
{
  int v5; // [esp+0h] [ebp-4h]

  v5 = sub_6431D0(a1, *(_DWORD *)(a1 + 144), &a2, a3, a4, *(_BYTE *)(a1 + 484) == 0);
  if ( v5 )
    return v5;
  if ( !a2 )
    return 0;
  if ( *(_DWORD *)(a1 + 476) )
  {
    *(_DWORD *)(a1 + 280) = sub_640CE0;
    return sub_640CE0(a1, a2, a3, a4);
  }
  else
  {
    *(_DWORD *)(a1 + 280) = sub_643160;
    return sub_643160(a1, a2, a3, a4);
  }
}
