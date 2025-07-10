int __cdecl sub_52F620(int a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 **a4)
{
  unsigned __int8 v5; // [esp+0h] [ebp-8h]
  unsigned __int8 v6; // [esp+4h] [ebp-4h]
  unsigned __int8 *i; // [esp+14h] [ebp+Ch]

  if ( a2 != a3 )
  {
    v6 = *(_BYTE *)(a1 + *a2 + 76);
    if ( v6 < 0x18u || v6 > 0x19u )
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
      if ( v5 <= 0x17u || v5 > 0x19u )
      {
        *a4 = i;
        return 0;
      }
    }
  }
  return -1;
}
