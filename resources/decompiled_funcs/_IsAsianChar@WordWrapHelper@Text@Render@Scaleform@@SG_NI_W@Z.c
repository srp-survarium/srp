bool __stdcall Scaleform::Render::Text::WordWrapHelper::IsAsianChar(char wwMode, wchar_t c)
{
  if ( (wwMode & 4) != 0
    && (c >= 0x1100u && c <= 0x11FFu || c >= 0x3130u && c <= 0x318Fu || (unsigned __int16)(c + 21504) <= 0x2BA3u) )
  {
    return 0;
  }
  return c >= 0x1100u && c <= 0x11FFu
      || c >= 0x3000u && c <= 0xD7AFu
      || c >= 0xF900u && c <= 0xFAFFu
      || (unsigned __int16)(c + 256) <= 0xDCu;
}
