char __cdecl Scaleform::IsSpace(Scaleform::StringDataPtr s)
{
  unsigned int Char_Advance0; // eax
  int v2; // ecx
  int v3; // edx
  char *putf8Buffer; // [esp+8h] [ebp-8h] BYREF

  putf8Buffer = (char *)s.pStr;
  if ( s.pStr == &s.pStr[s.Size] )
    return 1;
  while ( 1 )
  {
    Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    if ( !Char_Advance0 )
      break;
    v2 = BYTE1(Char_Advance0);
    v3 = Scaleform::UnicodeSpaceBits[v2];
    if ( !Scaleform::UnicodeSpaceBits[v2]
      || v3 != 1
      && (Scaleform::UnicodeSpaceBits[v3 + ((unsigned __int8)Char_Advance0 >> 4)] & (1 << (Char_Advance0 & 0xF))) == 0 )
    {
      break;
    }
    if ( putf8Buffer >= &s.pStr[s.Size] )
      return 1;
  }
  return 0;
}
