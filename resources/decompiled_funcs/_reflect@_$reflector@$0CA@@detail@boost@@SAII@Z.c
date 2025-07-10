unsigned int __cdecl boost::detail::reflector<32>::reflect(unsigned int x)
{
  unsigned int i; // [esp+0h] [ebp-Ch]
  unsigned int reflection; // [esp+8h] [ebp-4h]

  reflection = 0;
  for ( i = 0; i < 0x20; ++i )
  {
    if ( (x & 1) != 0 )
      reflection |= 1 << (31 - i);
    x >>= 1;
  }
  return reflection;
}
