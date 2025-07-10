unsigned int __stdcall Scaleform::UTF8Util::GetCharAt(int index, const char *putf8str, int length)
{
  const char *v3; // ebx
  int v4; // edi
  unsigned int result; // eax
  int v6; // esi
  int v7; // esi

  v3 = putf8str;
  v4 = length;
  result = 0;
  if ( length == -1 )
  {
    v7 = index;
    do
    {
      result = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8str);
      --v7;
    }
    while ( result && v7 >= 0 );
  }
  else if ( length > 0 )
  {
    v6 = index;
    do
    {
      result = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8str);
      if ( !v6 )
        break;
      --v6;
    }
    while ( putf8str - v3 < v4 );
  }
  return result;
}
