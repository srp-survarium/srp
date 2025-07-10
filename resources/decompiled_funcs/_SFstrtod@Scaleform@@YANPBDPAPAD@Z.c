long double __cdecl Scaleform::SFstrtod(const char *string, char **tailptr)
{
  char v2; // bl
  char *v3; // eax
  char buffer[348]; // [esp+4h] [ebp-15Ch] BYREF

  v2 = *localeconv()->decimal_point;
  if ( v2 == 46 )
    return strtod(string, tailptr);
  strcpy_s(buffer, 0x15Cu, string);
  v3 = buffer;
  if ( buffer[0] )
  {
    while ( *v3 != 46 )
    {
      if ( !*++v3 )
        return strtod(buffer, tailptr);
    }
    *v3 = v2;
  }
  return strtod(buffer, tailptr);
}
