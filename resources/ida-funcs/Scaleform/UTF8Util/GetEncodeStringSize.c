int __stdcall Scaleform::UTF8Util::GetEncodeStringSize(wchar_t *pchar, int length)
{
  __int64 v2; // rax
  unsigned int v3; // ecx
  int v4; // ecx
  wchar_t i; // cx
  int v6; // ecx

  v2 = 0;
  if ( length == -1 )
  {
    for ( i = *pchar; i; i = pchar[HIDWORD(v2)] )
    {
      if ( i > 0x7Fu )
      {
        if ( i > 0x7FFu )
          v6 = 3;
        else
          v6 = 2;
      }
      else
      {
        v6 = 1;
      }
      ++HIDWORD(v2);
      LODWORD(v2) = v6 + v2;
    }
  }
  else if ( length > 0 )
  {
    do
    {
      v3 = pchar[HIDWORD(v2)];
      if ( v3 > 0x7F )
      {
        if ( v3 > 0x7FF )
          v4 = 3;
        else
          v4 = 2;
      }
      else
      {
        v4 = 1;
      }
      ++HIDWORD(v2);
      LODWORD(v2) = v4 + v2;
    }
    while ( SHIDWORD(v2) < length );
  }
  return v2;
}
