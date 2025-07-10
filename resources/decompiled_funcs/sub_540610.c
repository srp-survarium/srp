int __cdecl sub_540610(int a1)
{
  int i; // [esp+0h] [ebp-4h]

  if ( !a1 )
    return 6;
  for ( i = 0; i < 6; ++i )
  {
    if ( sub_540670(a1, off_88BEA0[i]) )
      return i;
  }
  return -1;
}
