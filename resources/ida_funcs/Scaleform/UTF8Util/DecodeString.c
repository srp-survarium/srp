int __stdcall Scaleform::UTF8Util::DecodeString(wchar_t *pbuff, const char *putf8str, int bytesLen)
{
  wchar_t *v3; // esi
  int v4; // edi
  unsigned int v5; // eax
  const char *v7; // ebx
  unsigned int v8; // eax

  v3 = pbuff;
  v4 = bytesLen;
  if ( bytesLen != -1 )
  {
    v7 = putf8str;
    if ( bytesLen > 0 )
    {
      do
      {
        v8 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8str);
        if ( v8 >= 0xFFFF )
          LOWORD(v8) = -3;
        *v3++ = v8;
      }
      while ( putf8str - v7 < v4 );
    }
    goto LABEL_11;
  }
  v5 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8str);
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
    v5 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8str);
  }
  while ( v5 );
  *v3 = 0;
  return v3 - pbuff;
}
