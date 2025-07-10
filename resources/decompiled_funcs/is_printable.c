BOOL __cdecl is_printable(signed int value)
{
  BOOL result; // eax
  int v2; // eax

  result = 0;
  if ( (unsigned int)value <= 0x7F )
  {
    if ( value >= 97 && value <= 122 )
      return 1;
    if ( value >= 65 && value <= 90 )
      return 1;
    if ( value >= 48 && value <= 57 )
      return 1;
    if ( value == 32 )
      return 1;
    strchr("'()+,-./:=?", value);
    if ( v2 )
      return 1;
  }
  return result;
}
