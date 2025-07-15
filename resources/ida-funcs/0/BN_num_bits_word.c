int __cdecl BN_num_bits_word(unsigned int l)
{
  if ( (l & 0xFFFF0000) != 0 )
  {
    if ( (l & 0xFF000000) != 0 )
      return bits[HIBYTE(l)] + 24;
    else
      return bits[HIWORD(l)] + 16;
  }
  else if ( (l & 0xFF00) != 0 )
  {
    return bits[l >> 8] + 8;
  }
  else
  {
    return bits[l];
  }
}
