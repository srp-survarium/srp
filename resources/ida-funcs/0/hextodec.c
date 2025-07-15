unsigned int __cdecl hextodec(char chr)
{
  bool v1; // zf
  unsigned int result; // eax

  v1 = isdigit((unsigned __int8)chr) == 0;
  result = chr;
  if ( v1 )
    return (chr & 0xFFFFFFDF) - 7;
  return result;
}
