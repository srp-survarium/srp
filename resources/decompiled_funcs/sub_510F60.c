int __cdecl sub_510F60(int a1, unsigned __int8 **a2)
{
  int v3; // [esp+0h] [ebp-4h]
  unsigned __int8 *i; // [esp+Ch] [ebp+8h]

  v3 = *(unsigned __int8 *)(a1 + 1);
  for ( i = (unsigned __int8 *)(a1 + 2); *i; ++i )
  {
    if ( *i == 92 && i[1] == 93 )
    {
      ++i;
    }
    else
    {
      if ( *i == 93 )
        return 0;
      if ( *i == v3 && i[1] == 93 )
      {
        *a2 = i;
        return 1;
      }
      if ( *i == 91 && (i[1] == 58 || i[1] == 46 || i[1] == 61) && sub_510F60(i, a2) )
        return 0;
    }
  }
  return 0;
}
