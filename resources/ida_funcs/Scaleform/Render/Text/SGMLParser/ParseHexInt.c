char __cdecl Scaleform::Render::Text::SGMLParser<wchar_t>::ParseHexInt(
        unsigned int *pdestVal,
        const wchar_t *pstr,
        unsigned int len)
{
  unsigned int v4; // esi
  unsigned int v5; // ebx
  __int16 v7; // ax
  int v8; // eax

  if ( !len )
    return 0;
  v4 = 0;
  v5 = 0;
  while ( isxdigit(*pstr) )
  {
    v4 *= 16;
    v7 = Scaleform::SFtowlower(*pstr);
    if ( (unsigned __int16)(v7 - 48) <= 9u )
    {
      v8 = v7 & 0xF;
LABEL_9:
      v4 |= v8;
      goto LABEL_10;
    }
    if ( (unsigned __int16)(v7 - 97) <= 5u )
    {
      v8 = (((_BYTE)v7 - 1) & 0xF) + 10;
      goto LABEL_9;
    }
LABEL_10:
    ++v5;
    ++pstr;
    if ( v5 >= len )
    {
      *pdestVal = v4;
      return 1;
    }
  }
  return 0;
}
