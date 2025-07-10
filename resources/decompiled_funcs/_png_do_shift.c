unsigned __int8 *__cdecl png_do_shift(int a1, _BYTE *a2, unsigned __int8 *a3)
{
  unsigned __int8 *result; // eax
  __int16 v4; // dx
  int m; // [esp+0h] [ebp-70h]
  int v6; // [esp+4h] [ebp-6Ch]
  __int16 v7; // [esp+8h] [ebp-68h]
  unsigned __int16 v8; // [esp+Ch] [ebp-64h]
  unsigned int v9; // [esp+10h] [ebp-60h]
  unsigned __int8 *v10; // [esp+14h] [ebp-5Ch]
  unsigned int k; // [esp+18h] [ebp-58h]
  int j; // [esp+1Ch] [ebp-54h]
  int v13; // [esp+20h] [ebp-50h]
  unsigned __int16 v14; // [esp+24h] [ebp-4Ch]
  unsigned int v15; // [esp+28h] [ebp-48h]
  _BYTE *v16; // [esp+2Ch] [ebp-44h]
  unsigned int i; // [esp+30h] [ebp-40h]
  int ii; // [esp+34h] [ebp-3Ch]
  unsigned __int16 v19; // [esp+38h] [ebp-38h]
  unsigned int v20; // [esp+3Ch] [ebp-34h]
  char v21; // [esp+43h] [ebp-2Dh]
  _BYTE *v22; // [esp+44h] [ebp-2Ch]
  unsigned int n; // [esp+48h] [ebp-28h]
  _DWORD v24[4]; // [esp+4Ch] [ebp-24h]
  unsigned int v25; // [esp+5Ch] [ebp-14h]
  _DWORD v26[4]; // [esp+60h] [ebp-10h]

  result = (unsigned __int8 *)a1;
  if ( *(_BYTE *)(a1 + 8) != 3 )
  {
    v25 = 0;
    if ( (*(_BYTE *)(a1 + 8) & 2) != 0 )
    {
      v26[v25] = *(unsigned __int8 *)(a1 + 9) - *a3;
      v24[v25++] = *a3;
      v26[v25] = *(unsigned __int8 *)(a1 + 9) - a3[1];
      v24[v25++] = a3[1];
      v26[v25] = *(unsigned __int8 *)(a1 + 9) - a3[2];
      v24[v25] = a3[2];
    }
    else
    {
      v26[v25] = *(unsigned __int8 *)(a1 + 9) - a3[3];
      v24[v25] = a3[3];
    }
    ++v25;
    if ( (*(_BYTE *)(a1 + 8) & 4) != 0 )
    {
      v26[v25] = *(unsigned __int8 *)(a1 + 9) - a3[4];
      v24[v25++] = a3[4];
    }
    if ( *(unsigned __int8 *)(a1 + 9) >= 8u )
    {
      if ( *(_BYTE *)(a1 + 9) == 8 )
      {
        v16 = a2;
        v15 = *(_DWORD *)a1 * v25;
        for ( i = 0; ; ++i )
        {
          result = (unsigned __int8 *)i;
          if ( i >= v15 )
            break;
          v13 = i % v25;
          v14 = (unsigned __int8)*v16;
          *v16 = 0;
          for ( j = v26[v13]; j > -v24[v13]; j -= v24[v13] )
          {
            if ( j <= 0 )
              *v16 |= (int)v14 >> -(char)j;
            else
              *v16 |= v14 << j;
          }
          ++v16;
        }
      }
      else
      {
        v9 = *(_DWORD *)a1 * v25;
        result = a2;
        v10 = a2;
        for ( k = 0; k < v9; ++k )
        {
          v6 = k % v25;
          v8 = v10[1] + (*v10 << 8);
          v7 = 0;
          for ( m = v26[k % v25]; m > -v24[v6]; m -= v24[v6] )
          {
            if ( m <= 0 )
              v4 = (int)v8 >> -(char)m;
            else
              v4 = v8 << m;
            v7 |= v4;
          }
          *v10 = HIBYTE(v7);
          result = v10 + 1;
          v10[1] = v7;
          v10 += 2;
        }
      }
    }
    else
    {
      v22 = a2;
      v20 = *(_DWORD *)(a1 + 4);
      if ( a3[3] == 1 && (result = (unsigned __int8 *)a1, *(_BYTE *)(a1 + 9) == 2) )
      {
        v21 = 85;
      }
      else
      {
        result = (unsigned __int8 *)*(unsigned __int8 *)(a1 + 9);
        if ( result == (unsigned __int8 *)4 && a3[3] == 3 )
          v21 = 17;
        else
          v21 = -1;
      }
      for ( n = 0; n < v20; ++n )
      {
        v19 = (unsigned __int8)*v22;
        *v22 = 0;
        for ( ii = v26[0]; ii > -v24[0]; ii -= v24[0] )
        {
          if ( ii <= 0 )
            *v22 |= v21 & (unsigned __int8)((int)v19 >> -(char)ii);
          else
            *v22 |= v19 << ii;
        }
        result = (unsigned __int8 *)(n + 1);
        ++v22;
      }
    }
  }
  return result;
}
