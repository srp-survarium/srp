int __cdecl sub_65B9A0(int a1)
{
  int i; // [esp+0h] [ebp-4h]

  if ( !a1 )
    return 6;
  for ( i = 0; i < 6; ++i )
  {
    if ( sub_65BA00(a1, off_72F918[i]) )
      return i;
  }
  return -1;
}
