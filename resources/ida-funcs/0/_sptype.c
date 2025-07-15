int __cdecl _sptype(long double x)
{
  if ( HIDWORD(x) == 2146435072 )
  {
    if ( !LODWORD(x) )
      return 1;
  }
  else if ( x == -INFINITY )
  {
    return 2;
  }
  if ( (HIWORD(x) & 0x7FF8) == 0x7FF8 )
    return 3;
  if ( (HIWORD(x) & 0x7FF8) == 0x7FF0 && ((HIDWORD(x) & 0x7FFFF) != 0 || LODWORD(x)) )
    return 4;
  return 0;
}
