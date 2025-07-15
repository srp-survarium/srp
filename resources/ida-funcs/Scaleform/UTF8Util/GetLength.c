int __stdcall Scaleform::UTF8Util::GetLength(char *buf, int buflen)
{
  char *v2; // ebx
  int v3; // edi
  int v4; // esi

  v2 = buf;
  v3 = buflen;
  v4 = 0;
  if ( buflen == -1 )
  {
    for ( ; Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&buf); ++v4 )
      ;
    return v4;
  }
  if ( buflen <= 0 )
    return v4;
  do
  {
    Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&buf);
    ++v4;
  }
  while ( buf - v2 < v3 );
  return v4;
}
