bool __cdecl Scaleform::Render::Text::SGMLCharIter<wchar_t>::IsSpace(unsigned __int16 c)
{
  int v1; // eax
  int v2; // esi
  BOOL v4; // eax

  v1 = HIBYTE(c);
  v2 = Scaleform::UnicodeSpaceBits[v1];
  if ( !Scaleform::UnicodeSpaceBits[v1] )
    return 0;
  v4 = 1;
  if ( v2 != 1 )
    return (Scaleform::UnicodeSpaceBits[v2 + ((unsigned __int8)c >> 4)] & (1 << (c & 0xF))) != 0;
  return v4;
}
