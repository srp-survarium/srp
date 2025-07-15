unsigned int __cdecl Scaleform::GFx::ASUtils::SkipWhiteSpace(Scaleform::String *str)
{
  unsigned int v1; // esi
  unsigned int Length; // edi
  unsigned int CharAt; // eax

  v1 = 0;
  Length = Scaleform::String::GetLength(str);
  if ( Length )
  {
    do
    {
      CharAt = Scaleform::String::GetCharAt(str, v1);
      if ( CharAt != 32
        && CharAt != 10
        && CharAt != 13
        && CharAt != 9
        && CharAt != 12
        && CharAt != 11
        && (CharAt < 0x2000 || CharAt > 0x200B)
        && CharAt != 8232
        && CharAt != 8233
        && CharAt != 8287
        && CharAt != 12288 )
      {
        break;
      }
      ++v1;
    }
    while ( v1 < Length );
  }
  return v1;
}


char *__cdecl Scaleform::GFx::ASUtils::SkipWhiteSpace(char *str, unsigned int len)
{
  char *result; // eax
  char *v3; // edi
  char *v4; // esi
  unsigned int Char_Advance0; // eax

  result = str;
  v3 = &str[len];
  if ( str < &str[len] )
  {
    while ( 1 )
    {
      v4 = result;
      Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&str);
      if ( Char_Advance0 != 32
        && Char_Advance0 != 10
        && Char_Advance0 != 13
        && Char_Advance0 != 9
        && Char_Advance0 != 12
        && Char_Advance0 != 11
        && (Char_Advance0 < 0x2000 || Char_Advance0 > 0x200B)
        && Char_Advance0 != 8232
        && Char_Advance0 != 8233
        && Char_Advance0 != 8287
        && Char_Advance0 != 12288 )
      {
        break;
      }
      result = str;
      if ( str >= v3 )
        return result;
    }
    return v4;
  }
  return result;
}
