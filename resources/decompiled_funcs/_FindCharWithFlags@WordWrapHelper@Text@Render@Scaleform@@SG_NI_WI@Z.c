bool __stdcall Scaleform::Render::Text::WordWrapHelper::FindCharWithFlags(
        char wwMode,
        wchar_t c,
        unsigned __int8 charBreakFlags)
{
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  wchar_t Char; // dx

  if ( (wwMode & 2) == 0 )
    return 0;
  v4 = 0;
  v5 = 111;
  while ( 1 )
  {
    v6 = v4 + (v5 - v4) / 2;
    Char = Scaleform::Render::Text::WordWrapHelper::CharBreakInfoArray[v6].Char;
    if ( c == Char )
      break;
    if ( c >= Char )
      v4 = v6 + 1;
    else
      v5 = v6 - 1;
    if ( v4 > v5 )
      return 0;
  }
  return (charBreakFlags & (unsigned __int8)byte_9B37CA[4 * v6]) != 0;
}
