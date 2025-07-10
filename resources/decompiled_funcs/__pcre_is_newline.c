int __cdecl _pcre_is_newline(unsigned __int8 *a1, int a2, int a3, int *a4, int a5)
{
  int v6; // [esp+0h] [ebp-14h]
  int v7; // [esp+8h] [ebp-Ch]
  int v8; // [esp+10h] [ebp-4h]

  if ( a5 )
  {
    v8 = *a1;
    if ( (unsigned int)v8 >= 0xC0 )
    {
      if ( (v8 & 0x20) != 0 )
      {
        if ( (v8 & 0x10) != 0 )
        {
          if ( (v8 & 8) != 0 )
          {
            if ( (v8 & 4) != 0 )
              v8 = a1[5] & 0x3F
                 | ((a1[4] & 0x3F) << 6)
                 | ((a1[3] & 0x3F) << 12)
                 | ((a1[2] & 0x3F) << 18)
                 | ((a1[1] & 0x3F) << 24)
                 | ((v8 & 1) << 30);
            else
              v8 = a1[4] & 0x3F
                 | ((a1[3] & 0x3F) << 6)
                 | ((a1[2] & 0x3F) << 12)
                 | ((a1[1] & 0x3F) << 18)
                 | ((v8 & 3) << 24);
          }
          else
          {
            v8 = a1[3] & 0x3F | ((a1[2] & 0x3F) << 6) | ((a1[1] & 0x3F) << 12) | ((v8 & 7) << 18);
          }
        }
        else
        {
          v8 = a1[2] & 0x3F | ((a1[1] & 0x3F) << 6) | ((v8 & 0xF) << 12);
        }
      }
      else
      {
        v8 = a1[1] & 0x3F | ((v8 & 0x1F) << 6);
      }
    }
  }
  else
  {
    v8 = *a1;
  }
  if ( a2 == 2 )
  {
    if ( v8 == 10 )
    {
      *a4 = 1;
      return 1;
    }
    else if ( v8 == 13 )
    {
      if ( (unsigned int)a1 < a3 - 1 && a1[1] == 10 )
        v7 = 2;
      else
        v7 = 1;
      *a4 = v7;
      return 1;
    }
    else
    {
      return 0;
    }
  }
  if ( v8 > 133 )
  {
    if ( v8 >= 8232 && v8 <= 8233 )
    {
      *a4 = 3;
      return 1;
    }
    return 0;
  }
  if ( v8 == 133 )
  {
    *a4 = (a5 != 0) + 1;
    return 1;
  }
  if ( v8 < 10 )
    return 0;
  if ( v8 <= 12 )
  {
    *a4 = 1;
    return 1;
  }
  if ( v8 != 13 )
    return 0;
  if ( (unsigned int)a1 < a3 - 1 && a1[1] == 10 )
    v6 = 2;
  else
    v6 = 1;
  *a4 = v6;
  return 1;
}
