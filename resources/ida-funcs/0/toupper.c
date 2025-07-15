int __cdecl toupper(int c)
{
  int result; // eax

  if ( __locale_changed )
    return _toupper_l(c, 0);
  result = c;
  if ( (unsigned int)(c - 97) <= 0x19 )
    return c - 32;
  return result;
}
