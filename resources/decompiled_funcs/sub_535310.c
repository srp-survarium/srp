int __cdecl sub_535310(int a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 **a4)
{
  int v5; // [esp+4h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-4h]
  unsigned __int8 *i; // [esp+1Ch] [ebp+Ch]

  if ( a2 != a3 )
  {
    if ( !a2[1] && *a2 == 120 )
      return sub_535440(a1, a2 + 2, a3, a4);
    if ( a2[1] )
      v6 = sub_534A50(a2[1], *a2);
    else
      v6 = *(unsigned __int8 *)(a1 + *a2 + 76);
    if ( v6 != 25 )
    {
      *a4 = a2;
      return 0;
    }
    for ( i = a2 + 2; i != a3; i += 2 )
    {
      if ( i[1] )
        v5 = sub_534A50(i[1], *i);
      else
        v5 = *(unsigned __int8 *)(a1 + *i + 76);
      if ( v5 == 18 )
      {
        *a4 = i + 2;
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
