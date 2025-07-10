int __cdecl Scaleform::SFtoupper(int c)
{
  int result; // eax

  result = c;
  if ( (unsigned int)(c - 97) <= 0x19 )
    return c - 32;
  return result;
}
