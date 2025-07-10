BOOL __cdecl Scaleform::SFiswalnum(wchar_t charCode)
{
  int v1; // eax
  int v2; // esi
  BOOL result; // eax

  v1 = HIBYTE(charCode);
  v2 = Scaleform::UnicodeAlnumBits[v1];
  if ( !Scaleform::UnicodeAlnumBits[v1] )
    return 0;
  result = 1;
  if ( v2 != 1 )
    return (Scaleform::UnicodeAlnumBits[v2 + ((unsigned __int8)charCode >> 4)] & (1 << (charCode & 0xF))) != 0;
  return result;
}
