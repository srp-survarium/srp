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


const char *__cdecl Scaleform::GFx::ASUtils::SkipWhiteSpace(const char *str, unsigned int len)
{
  const char *result; // eax
  const char *v3; // edi
  const char *v4; // esi
  unsigned int v5; // eax

  result = str;
  v3 = &str[len];
  if ( str < &str[len] )
  {
    while ( 1 )
    {
      v4 = result;
      v5 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&str);
      if ( v5 != 32
        && v5 != 10
        && v5 != 13
        && v5 != 9
        && v5 != 12
        && v5 != 11
        && (v5 < 0x2000 || v5 > 0x200B)
        && v5 != 8232
        && v5 != 8233
        && v5 != 8287
        && v5 != 12288 )
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
