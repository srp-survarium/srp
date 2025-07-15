int __stdcall Scaleform::UTF8Util::DecodeString(wchar_t *pbuff, char *putf8str, int bytesLen)
{
  wchar_t *v3; // esi
  int v4; // edi
  unsigned int v5; // eax
  char *v7; // ebx
  unsigned int Char_Advance0; // eax

  v3 = pbuff;
  v4 = bytesLen;
  if ( bytesLen != -1 )
  {
    v7 = putf8str;
    if ( bytesLen > 0 )
    {
      do
      {
        Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8str);
        if ( Char_Advance0 >= 0xFFFF )
          LOWORD(Char_Advance0) = -3;
        *v3++ = Char_Advance0;
      }
      while ( putf8str - v7 < v4 );
    }
    goto LABEL_11;
  }
  v5 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8str);
  if ( !v5 )
  {
LABEL_11:
    *v3 = 0;
    return v3 - pbuff;
  }
  do
  {
    if ( v5 >= 0xFFFF )
      LOWORD(v5) = -3;
    *v3++ = v5;
    v5 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8str);
  }
  while ( v5 );
  *v3 = 0;
  return v3 - pbuff;
}
