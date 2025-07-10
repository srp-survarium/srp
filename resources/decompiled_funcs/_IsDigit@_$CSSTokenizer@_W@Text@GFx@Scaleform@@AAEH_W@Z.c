BOOL __thiscall Scaleform::GFx::Text::CSSTokenizer<wchar_t>::IsDigit(
        Scaleform::GFx::Text::CSSTokenizer<wchar_t> *this,
        wchar_t c)
{
  int v2; // eax
  int v3; // esi
  BOOL result; // eax

  v2 = HIBYTE(c);
  v3 = Scaleform::UnicodeDigitBits[v2];
  if ( !Scaleform::UnicodeDigitBits[v2] )
    return 0;
  result = 1;
  if ( v3 != 1 )
    return (Scaleform::UnicodeDigitBits[v3 + ((unsigned __int8)c >> 4)] & (1 << (c & 0xF))) != 0;
  return result;
}
