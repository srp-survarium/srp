BOOL __cdecl Scaleform::SFiswspace(wchar_t charCode)
{
  int v1; // eax
  int v2; // esi
  BOOL result; // eax

  v1 = HIBYTE(charCode);
  v2 = Scaleform::UnicodeSpaceBits[v1];
  if ( !Scaleform::UnicodeSpaceBits[v1] )
    return 0;
  result = 1;
  if ( v2 != 1 )
    return (Scaleform::UnicodeSpaceBits[v2 + ((unsigned __int8)charCode >> 4)] & (1 << (charCode & 0xF))) != 0;
  return result;
}
