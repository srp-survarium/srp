_BYTE *__cdecl png_do_invert(int a1, _BYTE *a2)
{
  _BYTE *result; // eax
  _BYTE *v3; // [esp+0h] [ebp-24h]
  _BYTE *v4; // [esp+4h] [ebp-20h]
  unsigned int j; // [esp+8h] [ebp-1Ch]
  unsigned int v6; // [esp+Ch] [ebp-18h]
  _BYTE *v7; // [esp+10h] [ebp-14h]
  unsigned int i; // [esp+14h] [ebp-10h]
  unsigned int v9; // [esp+18h] [ebp-Ch]
  _BYTE *v10; // [esp+1Ch] [ebp-8h]
  _BYTE *k; // [esp+20h] [ebp-4h]

  if ( *(_BYTE *)(a1 + 8) )
  {
    if ( *(_BYTE *)(a1 + 8) == 4 && *(_BYTE *)(a1 + 9) == 8 )
    {
      result = a2;
      v7 = a2;
      v6 = *(_DWORD *)(a1 + 4);
      for ( i = 0; i < v6; i += 2 )
      {
        *v7 = ~*v7;
        v7 += 2;
        result = (_BYTE *)(i + 2);
      }
    }
    else
    {
      result = (_BYTE *)a1;
      if ( *(_BYTE *)(a1 + 8) == 4 )
      {
        result = (_BYTE *)*(unsigned __int8 *)(a1 + 9);
        if ( result == (_BYTE *)16 )
        {
          v4 = a2;
          result = *(_BYTE **)(a1 + 4);
          v3 = result;
          for ( j = 0; j < (unsigned int)v3; j += 4 )
          {
            *v4 = ~*v4;
            v4[1] = ~v4[1];
            result = v4 + 4;
            v4 += 4;
          }
        }
      }
    }
  }
  else
  {
    v10 = a2;
    v9 = *(_DWORD *)(a1 + 4);
    for ( k = 0; ; ++k )
    {
      result = k;
      if ( (unsigned int)k >= v9 )
        break;
      *v10 = ~*v10;
      ++v10;
    }
  }
  return result;
}
