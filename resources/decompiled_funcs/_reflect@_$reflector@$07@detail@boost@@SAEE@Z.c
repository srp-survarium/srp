unsigned __int8 __cdecl boost::detail::reflector<8>::reflect(unsigned __int8 x)
{
  unsigned int i; // [esp+0h] [ebp-8h]
  unsigned __int8 reflection; // [esp+7h] [ebp-1h]

  reflection = 0;
  for ( i = 0; i < 8; ++i )
  {
    if ( (x & 1) != 0 )
      reflection |= 1 << (7 - i);
    x >>= 1;
  }
  return reflection;
}
