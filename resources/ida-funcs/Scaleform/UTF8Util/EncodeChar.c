void __stdcall Scaleform::UTF8Util::EncodeChar(char *pbuffer, int *pindex, unsigned int ucs_character)
{
  int *v3; // ecx
  char *v4; // esi

  if ( ucs_character <= 0x7F )
  {
    pbuffer[(*pindex)++] = ucs_character;
    return;
  }
  if ( ucs_character <= 0x7FF )
  {
    pbuffer[(*pindex)++] = (ucs_character >> 6) | 0xC0;
    pbuffer[(*pindex)++] = ucs_character & 0x3F | 0x80;
    return;
  }
  if ( ucs_character > 0xFFFF )
  {
    if ( ucs_character > 0x1FFFFF )
    {
      if ( ucs_character > (unsigned int)&vostok::memory::s_CRT_arena[55905847] )
      {
        if ( ucs_character > 0x7FFFFFFF )
          return;
        v3 = pindex;
        v4 = pbuffer;
        pbuffer[(*pindex)++] = (ucs_character >> 30) | 0xFC;
        pbuffer[*pindex] = HIBYTE(ucs_character) & 0x3F | 0x80;
      }
      else
      {
        v3 = pindex;
        v4 = pbuffer;
        pbuffer[*pindex] = HIBYTE(ucs_character) | 0xF8;
      }
      v4[++*v3] = (ucs_character >> 18) & 0x3F | 0x80;
    }
    else
    {
      v3 = pindex;
      v4 = pbuffer;
      pbuffer[*pindex] = (ucs_character >> 18) | 0xF0;
    }
    v4[++*v3] = (ucs_character >> 12) & 0x3F | 0x80;
  }
  else
  {
    v3 = pindex;
    v4 = pbuffer;
    pbuffer[*pindex] = (ucs_character >> 12) | 0xE0;
  }
  v4[++*v3] = (ucs_character >> 6) & 0x3F | 0x80;
  v4[++*v3] = ucs_character & 0x3F | 0x80;
  ++*v3;
}
