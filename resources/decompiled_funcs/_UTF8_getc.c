int __cdecl UTF8_getc(const unsigned __int8 *str, int len, unsigned int *val)
{
  int result; // eax
  char v4; // cl
  unsigned __int8 v5; // dl
  unsigned int v6; // ecx
  unsigned int v7; // ecx
  char v8; // al
  unsigned int v9; // ecx
  char v10; // al
  unsigned int v11; // ecx
  const unsigned __int8 *v12; // esi
  char v13; // al
  unsigned int v14; // ecx

  if ( len <= 0 )
    return 0;
  v4 = *str;
  if ( *(char *)str >= 0 )
  {
    result = 1;
    *val = v4 & 0x7F;
    return result;
  }
  if ( (v4 & 0xE0) != 0xC0 )
  {
    if ( (v4 & 0xF0) == 0xE0 )
    {
      if ( len < 3 )
        return -1;
      if ( (str[1] & 0xC0) == 0x80 && (str[2] & 0xC0) == 0x80 )
      {
        v7 = str[2] & 0x3F | ((str[1] & 0x3F) << 6) | ((v4 & 0xF) << 12);
        if ( v7 >= 0x800 )
        {
          result = 3;
          *val = v7;
          return result;
        }
        return -4;
      }
      return -3;
    }
    if ( (v4 & 0xF8) == 0xF0 )
    {
      if ( len < 4 )
        return -1;
      if ( (str[1] & 0xC0) != 0x80 )
        return -3;
      v8 = str[2] & 0xC0;
      if ( v8 != (char)0x80 || (str[3] & 0xC0) != v8 )
        return -3;
      v9 = str[3] & 0x3F | ((str[2] & 0x3F) << 6) | ((str[1] & 0x3F) << 12) | ((v4 & 7) << 18);
      if ( v9 >= (unsigned int)&_sbh_sizeHeaderList )
      {
        result = 4;
        *val = v9;
        return result;
      }
    }
    else if ( (v4 & 0xFC) == 0xF8 )
    {
      if ( len < 5 )
        return -1;
      if ( (str[1] & 0xC0) != 0x80 )
        return -3;
      if ( (str[2] & 0xC0) != 0x80 )
        return -3;
      v10 = str[3] & 0xC0;
      if ( v10 != (char)0x80 || (str[4] & 0xC0) != v10 )
        return -3;
      v11 = str[4] & 0x3F
          | ((str[3] & 0x3F) << 6)
          | ((str[2] & 0x3F) << 12)
          | ((str[1] & 0x3F) << 18)
          | ((v4 & 3) << 24);
      if ( v11 >= 0x200000 )
      {
        result = 5;
        *val = v11;
        return result;
      }
    }
    else
    {
      if ( (v4 & 0xFE) != 0xFC )
        return -2;
      if ( len < 6 )
        return -1;
      if ( (str[1] & 0xC0) != 0x80 )
        return -3;
      if ( (str[2] & 0xC0) != 0x80 )
        return -3;
      if ( (str[3] & 0xC0) != 0x80 )
        return -3;
      v13 = str[4] & 0xC0;
      if ( v13 != (char)0x80 || (str[5] & 0xC0) != v13 )
        return -3;
      v12 = str + 1;
      v14 = v12[4] & 0x3F
          | ((v12[3] & 0x3F) << 6)
          | ((v12[2] & 0x3F) << 12)
          | ((v12[1] & 0x3F) << 18)
          | ((*v12 & 0x3F) << 24)
          | ((v4 & 1) << 30);
      if ( v14 >= (unsigned int)&vostok::memory::s_CRT_arena[55905848] )
      {
        result = 6;
        *val = v14;
        return result;
      }
    }
    return -4;
  }
  if ( len < 2 )
    return -1;
  v5 = str[1];
  if ( (v5 & 0xC0) != 0x80 )
    return -3;
  v6 = v5 & 0x3F | ((v4 & 0x1F) << 6);
  if ( v6 < 0x80 )
    return -4;
  result = 2;
  *val = v6;
  return result;
}
