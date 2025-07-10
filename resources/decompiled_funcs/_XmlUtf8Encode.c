int __cdecl XmlUtf8Encode(int a1, _BYTE *a2)
{
  if ( a1 < 0 )
    return 0;
  if ( a1 >= 128 )
  {
    if ( a1 >= 2048 )
    {
      if ( a1 >= (int)&_sbh_sizeHeaderList )
      {
        if ( a1 >= 1114112 )
        {
          return 0;
        }
        else
        {
          *a2 = (a1 >> 18) | 0xF0;
          a2[1] = (a1 >> 12) & 0x3F | 0x80;
          a2[2] = (a1 >> 6) & 0x3F | 0x80;
          a2[3] = a1 & 0x3F | 0x80;
          return 4;
        }
      }
      else
      {
        *a2 = (a1 >> 12) | 0xE0;
        a2[1] = (a1 >> 6) & 0x3F | 0x80;
        a2[2] = a1 & 0x3F | 0x80;
        return 3;
      }
    }
    else
    {
      *a2 = (a1 >> 6) | 0xC0;
      a2[1] = a1 & 0x3F | 0x80;
      return 2;
    }
  }
  else
  {
    *a2 = a1;
    return 1;
  }
}
