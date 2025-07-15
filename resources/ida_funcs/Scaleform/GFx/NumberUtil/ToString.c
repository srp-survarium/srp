char *__stdcall Scaleform::GFx::NumberUtil::ToString(
        long double value,
        char *destStr,
        unsigned int destStrSize,
        int radix)
{
  int v4; // ecx
  const char *v5; // esi
  int v6; // ecx
  char *v8; // eax

  v4 = radix;
  v5 = "%.14g";
  if ( radix <= 0 )
  {
    if ( radix < -14 )
      v6 = 14;
    else
      v6 = -radix;
    v5 = *(const char **)&aInfinity[4 * v6 + 8];
    v4 = 10;
  }
  if ( (HIDWORD(value) & 0x7FF00000) == 0x7FF00000 )
  {
    if ( (unsigned int)&loc_FFFFF & HIDWORD(value) | LODWORD(value) )
    {
      strcpy_s(destStr, destStrSize, "NaN");
      return destStr;
    }
    if ( value == INFINITY )
    {
      strcpy_s(destStr, destStrSize, "Infinity");
      return destStr;
    }
    if ( value == -INFINITY )
    {
      strcpy_s(destStr, destStrSize, "-Infinity");
      return destStr;
    }
    return destStr;
  }
  if ( v4 == 10 )
  {
    if ( (double)(int)value == value )
      return Scaleform::GFx::NumberUtil::IntToString((int)value, destStr, destStrSize);
    Scaleform::SFsprintf(destStr, destStrSize, v5, value);
    v8 = destStr;
    if ( *destStr )
    {
      while ( *v8 != 44 && *v8 != 46 )
      {
        if ( !*++v8 )
          return destStr;
      }
      *v8 = 46;
    }
    return destStr;
  }
  return Scaleform::GFx::NumberUtil::IntToString((int)value, destStr, destStrSize, v4);
}
