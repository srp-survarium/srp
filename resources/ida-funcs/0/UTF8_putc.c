int __cdecl UTF8_putc(unsigned __int8 *str, int len, unsigned int value)
{
  int v3; // edx

  if ( str )
  {
    v3 = len;
    if ( len <= 0 )
      return -1;
  }
  else
  {
    v3 = 6;
  }
  if ( value < 0x80 )
  {
    if ( str )
      *str = value;
    return 1;
  }
  if ( value < 0x800 )
  {
    if ( v3 >= 2 )
    {
      if ( str )
      {
        *str = (value >> 6) & 0x1F | 0xC0;
        str[1] = value & 0x3F | 0x80;
      }
      return 2;
    }
    return -1;
  }
  if ( value >= (unsigned int)&_sbh_sizeHeaderList )
  {
    if ( value >= (unsigned int)&loc_200000 )
    {
      if ( value >= 0x4000000 )
      {
        if ( v3 < 6 )
          return -1;
        if ( str )
        {
          *str = ((value & 0x40000000) != 0) | 0xFC;
          str[1] = HIBYTE(value) & 0x3F | 0x80;
          str[2] = (value >> 18) & 0x3F | 0x80;
          str[3] = (value >> 12) & 0x3F | 0x80;
          str[4] = (value >> 6) & 0x3F | 0x80;
          str[5] = value & 0x3F | 0x80;
        }
        return 6;
      }
      else
      {
        if ( v3 < 5 )
          return -1;
        if ( str )
        {
          *str = HIBYTE(value) & 3 | 0xF8;
          str[1] = (value >> 18) & 0x3F | 0x80;
          str[2] = (value >> 12) & 0x3F | 0x80;
          str[3] = (value >> 6) & 0x3F | 0x80;
          str[4] = value & 0x3F | 0x80;
        }
        return 5;
      }
    }
    else
    {
      if ( v3 < 4 )
        return -1;
      if ( str )
      {
        *str = (value >> 18) & 7 | 0xF0;
        str[1] = (value >> 12) & 0x3F | 0x80;
        str[2] = (value >> 6) & 0x3F | 0x80;
        str[3] = value & 0x3F | 0x80;
      }
      return 4;
    }
  }
  else
  {
    if ( v3 < 3 )
      return -1;
    if ( str )
    {
      *str = (value >> 12) & 0xF | 0xE0;
      str[1] = (value >> 6) & 0x3F | 0x80;
      str[2] = value & 0x3F | 0x80;
    }
    return 3;
  }
}
