bool __cdecl Scaleform::GFx::AS2::GAS_ParseNumber(long double *retVal)
{
  char *str; // ecx
  char v2; // al
  long double v3; // st7
  char *v4; // eax
  bool result; // al
  char *end; // [esp+0h] [ebp-4h] BYREF

  end = str;
  result = 0;
  if ( str )
  {
    v2 = *str;
    if ( *str )
    {
      if ( v2 >= 48 && v2 <= 57 || v2 == 43 || v2 == 45 || v2 == 46 )
      {
        v3 = Scaleform::SFstrtod(str, &end);
        v4 = end;
        *retVal = v3;
        if ( !v4 || !*v4 )
          return 1;
      }
    }
  }
  return result;
}
