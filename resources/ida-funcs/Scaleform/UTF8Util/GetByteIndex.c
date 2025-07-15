char *__stdcall Scaleform::UTF8Util::GetByteIndex(int index, char *putf8str, int length)
{
  char *v3; // ebx
  int v4; // edi
  char *v5; // eax
  int i; // esi
  int v8; // esi

  v3 = putf8str;
  v4 = length;
  v5 = putf8str;
  if ( length == -1 )
  {
    v8 = index;
    if ( index > 0 )
    {
      do
        --v8;
      while ( Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8str) && v8 > 0 );
      v5 = putf8str;
    }
  }
  else if ( length > 0 )
  {
    for ( i = index; i > 0; --i )
    {
      Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8str);
      v5 = putf8str;
      if ( putf8str - v3 >= v4 )
        return (char *)(putf8str - v3);
    }
  }
  return (char *)(v5 - v3);
}
