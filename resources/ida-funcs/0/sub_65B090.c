int __cdecl sub_65B090(int a1)
{
  int v2; // [esp+0h] [ebp-4h]

  v2 = a1 >> 8;
  if ( a1 >> 8 > 223 )
  {
    if ( v2 == 255 && (a1 == 65534 || a1 == 0xFFFF) )
      return -1;
  }
  else
  {
    if ( v2 >= 216 )
      return -1;
    if ( !v2 && !byte_72EBFC[a1] )
      return -1;
  }
  return a1;
}
