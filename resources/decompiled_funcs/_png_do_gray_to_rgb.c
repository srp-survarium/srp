unsigned int __cdecl png_do_gray_to_rgb(unsigned int a1, int a2)
{
  unsigned int result; // eax
  int v3; // [esp+0h] [ebp-2Ch]
  _BYTE *v4; // [esp+4h] [ebp-28h]
  _BYTE *v5; // [esp+4h] [ebp-28h]
  _BYTE *v6; // [esp+8h] [ebp-24h]
  _BYTE *v7; // [esp+8h] [ebp-24h]
  _BYTE *v8; // [esp+Ch] [ebp-20h]
  _BYTE *v9; // [esp+Ch] [ebp-20h]
  _BYTE *v10; // [esp+10h] [ebp-1Ch]
  _BYTE *v11; // [esp+10h] [ebp-1Ch]
  _BYTE *v12; // [esp+14h] [ebp-18h]
  _BYTE *v13; // [esp+14h] [ebp-18h]
  _BYTE *v14; // [esp+18h] [ebp-14h]
  _BYTE *v15; // [esp+18h] [ebp-14h]
  _BYTE *v16; // [esp+1Ch] [ebp-10h]
  _BYTE *v17; // [esp+1Ch] [ebp-10h]
  _BYTE *v18; // [esp+20h] [ebp-Ch]
  unsigned int v19; // [esp+24h] [ebp-8h]
  unsigned int k; // [esp+28h] [ebp-4h]
  unsigned int m; // [esp+28h] [ebp-4h]
  unsigned int i; // [esp+28h] [ebp-4h]
  unsigned int j; // [esp+28h] [ebp-4h]

  v19 = *(_DWORD *)a1;
  result = *(unsigned __int8 *)(a1 + 9);
  if ( result >= 8 && (*(_BYTE *)(a1 + 8) & 2) == 0 )
  {
    if ( *(_BYTE *)(a1 + 8) )
    {
      if ( *(_BYTE *)(a1 + 8) == 4 )
      {
        if ( *(_BYTE *)(a1 + 9) == 8 )
        {
          v10 = (_BYTE *)(a2 + 2 * v19 - 1);
          v8 = &v10[2 * v19];
          for ( i = 0; i < v19; ++i )
          {
            *v8 = *v10;
            v9 = v8 - 1;
            v11 = v10 - 1;
            *v9-- = *v11;
            *v9-- = *v11;
            *v9 = *v11;
            v8 = v9 - 1;
            v10 = v11 - 1;
          }
        }
        else
        {
          v6 = (_BYTE *)(a2 + 4 * v19 - 1);
          v4 = &v6[4 * v19];
          for ( j = 0; j < v19; ++j )
          {
            *v4 = *v6;
            v5 = v4 - 1;
            v7 = v6 - 1;
            *v5-- = *v7;
            *v5 = *--v7;
            *--v5 = *(v7 - 1);
            *--v5 = *v7;
            *--v5 = *(v7 - 1);
            *--v5 = *v7;
            *--v5 = *--v7;
            v4 = v5 - 1;
            v6 = v7 - 1;
          }
        }
      }
    }
    else if ( *(_BYTE *)(a1 + 9) == 8 )
    {
      v18 = (_BYTE *)(a2 + v19 - 1);
      v16 = &v18[2 * v19];
      for ( k = 0; k < v19; ++k )
      {
        *v16 = *v18;
        v17 = v16 - 1;
        *v17-- = *v18;
        *v17 = *v18;
        v16 = v17 - 1;
        --v18;
      }
    }
    else
    {
      v14 = (_BYTE *)(a2 + 2 * v19 - 1);
      v12 = &v14[4 * v19];
      for ( m = 0; m < v19; ++m )
      {
        *v12 = *v14;
        v13 = v12 - 1;
        *v13-- = *(v14 - 1);
        *v13-- = *v14;
        *v13-- = *(v14 - 1);
        *v13-- = *v14;
        v15 = v14 - 1;
        *v13 = *v15;
        v12 = v13 - 1;
        v14 = v15 - 1;
      }
    }
    *(_BYTE *)(a1 + 10) += 2;
    *(_BYTE *)(a1 + 8) |= 2u;
    *(_BYTE *)(a1 + 11) = *(_BYTE *)(a1 + 9) * *(_BYTE *)(a1 + 10);
    if ( *(unsigned __int8 *)(a1 + 11) < 8u )
    {
      result = (v19 * *(unsigned __int8 *)(a1 + 11) + 7) >> 3;
      v3 = result;
    }
    else
    {
      result = a1;
      v3 = v19 * (*(unsigned __int8 *)(a1 + 11) >> 3);
    }
    *(_DWORD *)(a1 + 4) = v3;
  }
  return result;
}
