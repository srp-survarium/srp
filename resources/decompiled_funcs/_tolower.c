unsigned int __cdecl tolower(unsigned int c)
{
  unsigned int result; // eax

  if ( __locale_changed )
    return _tolower_l(c, 0);
  result = c;
  if ( c - 65 <= 0x19 )
    return c + 32;
  return result;
}
