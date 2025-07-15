unsigned int __cdecl boost::detail::crc_helper<32,1>::reflect(unsigned int x)
{
  unsigned int result; // eax
  unsigned int i; // edx

  result = 0;
  for ( i = 0; i < 0x20; ++i )
  {
    if ( (x & 1) != 0 )
      result |= 1 << (31 - i);
    x >>= 1;
  }
  return result;
}
