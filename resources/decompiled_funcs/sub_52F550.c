int __cdecl sub_52F550(int a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 **a4)
{
  char v5; // [esp+0h] [ebp-8h]
  unsigned __int8 *i; // [esp+14h] [ebp+Ch]

  if ( a2 != a3 )
  {
    if ( *a2 == 120 )
      return sub_52F620(a1, a2 + 1, a3, a4);
    if ( *(_BYTE *)(a1 + *a2 + 76) != 25 )
    {
      *a4 = a2;
      return 0;
    }
    for ( i = a2 + 1; i != a3; ++i )
    {
      v5 = *(_BYTE *)(a1 + *i + 76);
      if ( v5 == 18 )
      {
        *a4 = i + 1;
        return 10;
      }
      if ( v5 != 25 )
      {
        *a4 = i;
        return 0;
      }
    }
  }
  return -1;
}
