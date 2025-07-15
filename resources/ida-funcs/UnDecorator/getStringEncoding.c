DName *__cdecl UnDecorator::getStringEncoding(DName *result, char *prefix)
{
  char v2; // al
  char v3; // al
  const char *v4; // eax
  char v5; // cl
  DName *v6; // eax
  DName v7; // [esp+0h] [ebp-10h] BYREF
  DName resulta; // [esp+8h] [ebp-8h] BYREF

  DName::DName(&resulta, prefix);
  v2 = *UnDecorator::gName++;
  if ( v2 == 64 && (v3 = *UnDecorator::gName, ++UnDecorator::gName, v3 == 95) )
  {
    ++UnDecorator::gName;
    UnDecorator::getDimension(&v7, 0);
    UnDecorator::getDimension(&v7, 0);
    v4 = UnDecorator::gName;
    v5 = *UnDecorator::gName;
    if ( *UnDecorator::gName )
    {
      do
      {
        if ( v5 == 64 )
          break;
        UnDecorator::gName = ++v4;
        v5 = *v4;
      }
      while ( *v4 );
      if ( *v4 )
      {
        UnDecorator::gName = v4 + 1;
        v6 = result;
        *result = resulta;
        return v6;
      }
    }
    UnDecorator::gName = v4 - 1;
    DName::DName(result, DN_truncated);
  }
  else
  {
    DName::DName(result, DN_invalid);
  }
  return result;
}
