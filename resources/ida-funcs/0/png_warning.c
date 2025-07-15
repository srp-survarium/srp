int __cdecl png_warning(int a1, _BYTE *a2)
{
  int i; // [esp+0h] [ebp-4h]

  i = 0;
  if ( a1 && *a2 == 35 )
  {
    for ( i = 1; i < 15 && a2[i] != 32; ++i )
      ;
  }
  if ( a1 && *(_DWORD *)(a1 + 72) )
    return (*(int (__cdecl **)(int, _BYTE *))(a1 + 72))(a1, &a2[i]);
  else
    return sub_462B40(a1, &a2[i]);
}
