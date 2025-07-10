unsigned int __cdecl hextodec(unsigned __int8 chr)
{
  bool v1; // zf
  unsigned int result; // eax

  v1 = isdigit(chr) == 0;
  result = (char)chr;
  if ( v1 )
    return ((char)chr & 0xFFFFFFDF) - 7;
  return result;
}
