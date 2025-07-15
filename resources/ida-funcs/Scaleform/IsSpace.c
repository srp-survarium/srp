char __cdecl Scaleform::IsSpace(Scaleform::StringDataPtr s)
{
  unsigned int v1; // eax
  int v2; // ecx
  int v3; // edx
  const char *pstr; // [esp+8h] [ebp-8h] BYREF

  pstr = s.pStr;
  if ( s.pStr == &s.pStr[s.Size] )
    return 1;
  while ( 1 )
  {
    v1 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&pstr);
    if ( !v1 )
      break;
    v2 = BYTE1(v1);
    v3 = Scaleform::UnicodeSpaceBits[v2];
    if ( !Scaleform::UnicodeSpaceBits[v2]
      || v3 != 1 && (Scaleform::UnicodeSpaceBits[v3 + ((unsigned __int8)v1 >> 4)] & (1 << (v1 & 0xF))) == 0 )
    {
      break;
    }
    if ( pstr >= &s.pStr[s.Size] )
      return 1;
  }
  return 0;
}
