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
