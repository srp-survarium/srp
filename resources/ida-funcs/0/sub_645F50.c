int __cdecl sub_645F50(int a1, int a2, int a3, int a4)
{
  int v5; // [esp+0h] [ebp-4h]

  v5 = sub_645FD0(a1, *(_DWORD *)(a1 + 144), &a2, a3, a4, *(_BYTE *)(a1 + 484) == 0);
  if ( v5 )
    return v5;
  if ( !a2 )
    return 0;
  *(_DWORD *)(a1 + 280) = sub_643A10;
  return sub_643A10(a1, a2, a3, a4);
}
