int __cdecl _pcre_was_newline(int a1, int a2, unsigned int a3, int *a4, int a5)
{
  int v6; // [esp+0h] [ebp-14h]
  int v7; // [esp+8h] [ebp-Ch]
  int v8; // [esp+10h] [ebp-4h]
  unsigned __int8 *v9; // [esp+1Ch] [ebp+8h]

  v9 = (unsigned __int8 *)(a1 - 1);
  if ( a5 )
  {
    while ( (*v9 & 0xC0) == 0x80 )
      --v9;
    v8 = *v9;
    if ( (unsigned int)v8 >= 0xC0 )
    {
      if ( (v8 & 0x20) != 0 )
      {
        if ( (v8 & 0x10) != 0 )
        {
          if ( (v8 & 8) != 0 )
          {
            if ( (v8 & 4) != 0 )
              v8 = v9[5] & 0x3F
                 | ((v9[4] & 0x3F) << 6)
                 | ((v9[3] & 0x3F) << 12)
                 | ((v9[2] & 0x3F) << 18)
                 | ((v9[1] & 0x3F) << 24)
                 | ((v8 & 1) << 30);
            else
              v8 = v9[4] & 0x3F
                 | ((v9[3] & 0x3F) << 6)
                 | ((v9[2] & 0x3F) << 12)
                 | ((v9[1] & 0x3F) << 18)
                 | ((v8 & 3) << 24);
          }
          else
          {
            v8 = v9[3] & 0x3F | ((v9[2] & 0x3F) << 6) | ((v9[1] & 0x3F) << 12) | ((v8 & 7) << 18);
          }
        }
        else
        {
          v8 = v9[2] & 0x3F | ((v9[1] & 0x3F) << 6) | ((v8 & 0xF) << 12);
        }
      }
      else
      {
        v8 = v9[1] & 0x3F | ((v8 & 0x1F) << 6);
      }
    }
  }
  else
  {
    v8 = *v9;
  }
  if ( a2 == 2 )
  {
    if ( v8 == 10 )
    {
      if ( (unsigned int)v9 > a3 && *(v9 - 1) == 13 )
        v7 = 2;
      else
        v7 = 1;
      *a4 = v7;
      return 1;
    }
    else if ( v8 == 13 )
    {
      *a4 = 1;
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
  if ( v8 != 10 )
  {
    if ( v8 > 10 && v8 <= 13 )
    {
      *a4 = 1;
      return 1;
    }
    return 0;
  }
  if ( (unsigned int)v9 > a3 && *(v9 - 1) == 13 )
    v6 = 2;
  else
    v6 = 1;
  *a4 = v6;
  return 1;
}
