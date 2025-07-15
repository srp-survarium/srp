char *__stdcall Scaleform::GFx::NumberUtil::ToString(long double value, __int64 destStr, int radix)
{
  int v3; // ecx
  char *v4; // esi
  int v5; // ecx
  _BYTE *v7; // eax

  v3 = radix;
  v4 = "%.14g";
  if ( radix <= 0 )
  {
    if ( radix < -14 )
      v5 = 14;
    else
      v5 = -radix;
    v4 = *(char **)&aInfinity[4 * v5 + 8];
    v3 = 10;
  }
  if ( (HIDWORD(value) & 0x7FF00000) == 0x7FF00000 )
  {
    if ( HIDWORD(value) & 0xFFFFF | LODWORD(value) )
    {
      strcpy_s(destStr, (char *)destStr, SHIDWORD(destStr), "NaN");
      return (char *)destStr;
    }
    if ( value == INFINITY )
    {
      strcpy_s(destStr, (char *)destStr, SHIDWORD(destStr), "Infinity");
      return (char *)destStr;
    }
    if ( value == -INFINITY )
    {
      strcpy_s(destStr, (char *)destStr, SHIDWORD(destStr), "-Infinity");
      return (char *)destStr;
    }
    return (char *)destStr;
  }
  if ( v3 == 10 )
  {
    if ( (double)(int)value == value )
      return Scaleform::GFx::NumberUtil::IntToString((int)value, (char *)destStr, HIDWORD(destStr));
    Scaleform::SFsprintf((char *)destStr, HIDWORD(destStr), v4, value);
    v7 = (_BYTE *)destStr;
    if ( *(_BYTE *)destStr )
    {
      while ( *v7 != 44 && *v7 != 46 )
      {
        if ( !*++v7 )
          return (char *)destStr;
      }
      *v7 = 46;
    }
    return (char *)destStr;
  }
  return Scaleform::GFx::NumberUtil::IntToString((int)value, (char *)destStr, HIDWORD(destStr), v3);
}
