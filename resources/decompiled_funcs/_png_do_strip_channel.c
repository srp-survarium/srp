int __cdecl png_do_strip_channel(int a1, _BYTE *a2, int a3)
{
  int result; // eax
  unsigned int v4; // [esp+0h] [ebp-Ch]
  _BYTE *v5; // [esp+4h] [ebp-8h]
  _BYTE *v6; // [esp+4h] [ebp-8h]
  _BYTE *v7; // [esp+4h] [ebp-8h]
  _BYTE *v8; // [esp+4h] [ebp-8h]
  _BYTE *v9; // [esp+8h] [ebp-4h]
  _BYTE *v10; // [esp+8h] [ebp-4h]
  _BYTE *v11; // [esp+8h] [ebp-4h]
  _BYTE *v12; // [esp+8h] [ebp-4h]
  _BYTE *v13; // [esp+8h] [ebp-4h]
  _BYTE *v14; // [esp+8h] [ebp-4h]
  _BYTE *v15; // [esp+8h] [ebp-4h]

  v5 = a2;
  v4 = (unsigned int)&a2[*(_DWORD *)(a1 + 4)];
  if ( *(_BYTE *)(a1 + 10) == 2 )
  {
    if ( *(_BYTE *)(a1 + 9) == 8 )
    {
      if ( a3 )
      {
        v9 = a2 + 1;
      }
      else
      {
        v9 = a2 + 2;
        v5 = a2 + 1;
      }
      while ( (unsigned int)v9 < v4 )
      {
        *v5++ = *v9;
        v9 += 2;
      }
      *(_BYTE *)(a1 + 11) = 8;
LABEL_17:
      *(_BYTE *)(a1 + 10) = 1;
      if ( *(_BYTE *)(a1 + 8) == 4 )
        *(_BYTE *)(a1 + 8) = 0;
LABEL_40:
      result = a1;
      *(_DWORD *)(a1 + 4) = v5 - a2;
      return result;
    }
    result = a1;
    if ( *(_BYTE *)(a1 + 9) == 16 )
    {
      if ( a3 )
      {
        v10 = a2 + 2;
      }
      else
      {
        v10 = a2 + 4;
        v5 = a2 + 2;
      }
      while ( (unsigned int)v10 < v4 )
      {
        *v5 = *v10;
        v6 = v5 + 1;
        v11 = v10 + 1;
        *v6 = *v11;
        v5 = v6 + 1;
        v10 = v11 + 3;
      }
      *(_BYTE *)(a1 + 11) = 16;
      goto LABEL_17;
    }
  }
  else
  {
    result = a1;
    if ( *(_BYTE *)(a1 + 10) == 4 )
    {
      if ( *(_BYTE *)(a1 + 9) == 8 )
      {
        if ( a3 )
        {
          v12 = a2 + 1;
        }
        else
        {
          v12 = a2 + 4;
          v5 = a2 + 3;
        }
        while ( (unsigned int)v12 < v4 )
        {
          *v5 = *v12;
          v7 = v5 + 1;
          v13 = v12 + 1;
          *v7++ = *v13;
          *v7 = *++v13;
          v5 = v7 + 1;
          v12 = v13 + 2;
        }
        *(_BYTE *)(a1 + 11) = 24;
      }
      else
      {
        result = a1;
        if ( *(_BYTE *)(a1 + 9) != 16 )
          return result;
        if ( a3 )
        {
          v14 = a2 + 2;
        }
        else
        {
          v14 = a2 + 8;
          v5 = a2 + 6;
        }
        while ( (unsigned int)v14 < v4 )
        {
          *v5 = *v14;
          v8 = v5 + 1;
          v15 = v14 + 1;
          *v8++ = *v15;
          *v8++ = *++v15;
          *v8++ = *++v15;
          *v8++ = *++v15;
          *v8 = *++v15;
          v5 = v8 + 1;
          v14 = v15 + 3;
        }
        *(_BYTE *)(a1 + 11) = 48;
      }
      *(_BYTE *)(a1 + 10) = 3;
      if ( *(_BYTE *)(a1 + 8) == 6 )
        *(_BYTE *)(a1 + 8) = 2;
      goto LABEL_40;
    }
  }
  return result;
}
