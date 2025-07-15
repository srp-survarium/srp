unsigned int __cdecl png_do_gamma(unsigned int a1, _BYTE *a2, _DWORD *a3)
{
  unsigned int result; // eax
  __int16 v4; // [esp+4h] [ebp-40h]
  int v5; // [esp+10h] [ebp-34h]
  int v6; // [esp+18h] [ebp-2Ch]
  int v7; // [esp+1Ch] [ebp-28h]
  __int16 v8; // [esp+20h] [ebp-24h]
  __int16 v9; // [esp+24h] [ebp-20h]
  __int16 v10; // [esp+24h] [ebp-20h]
  __int16 v11; // [esp+24h] [ebp-20h]
  __int16 v12; // [esp+28h] [ebp-1Ch]
  __int16 v13; // [esp+28h] [ebp-1Ch]
  __int16 v14; // [esp+28h] [ebp-1Ch]
  int v15; // [esp+2Ch] [ebp-18h]
  int v16; // [esp+30h] [ebp-14h]
  unsigned int v17; // [esp+34h] [ebp-10h]
  _BYTE *v18; // [esp+38h] [ebp-Ch]
  _BYTE *v19; // [esp+38h] [ebp-Ch]
  unsigned __int8 *v20; // [esp+38h] [ebp-Ch]
  unsigned __int8 *v21; // [esp+38h] [ebp-Ch]
  _BYTE *v22; // [esp+38h] [ebp-Ch]
  _BYTE *v23; // [esp+38h] [ebp-Ch]
  unsigned __int8 *v24; // [esp+38h] [ebp-Ch]
  unsigned __int8 *v25; // [esp+38h] [ebp-Ch]
  _BYTE *v26; // [esp+38h] [ebp-Ch]
  unsigned __int8 *v27; // [esp+38h] [ebp-Ch]
  _BYTE *v28; // [esp+38h] [ebp-Ch]
  _BYTE *v29; // [esp+38h] [ebp-Ch]
  _BYTE *v30; // [esp+38h] [ebp-Ch]
  unsigned __int8 *v31; // [esp+38h] [ebp-Ch]
  unsigned int n; // [esp+3Ch] [ebp-8h]
  unsigned int ii; // [esp+3Ch] [ebp-8h]
  unsigned int mm; // [esp+3Ch] [ebp-8h]
  unsigned int nn; // [esp+3Ch] [ebp-8h]
  unsigned int jj; // [esp+3Ch] [ebp-8h]
  unsigned int kk; // [esp+3Ch] [ebp-8h]
  unsigned int i; // [esp+3Ch] [ebp-8h]
  unsigned int j; // [esp+3Ch] [ebp-8h]
  unsigned int k; // [esp+3Ch] [ebp-8h]
  unsigned int m; // [esp+3Ch] [ebp-8h]
  int v42; // [esp+40h] [ebp-4h]

  v15 = a3[96];
  v42 = a3[97];
  v16 = a3[93];
  v17 = *(_DWORD *)a1;
  result = *(unsigned __int8 *)(a1 + 9);
  if ( result <= 8 && v15 || *(_BYTE *)(a1 + 9) == 16 && v42 )
  {
    result = a1;
    switch ( *(_BYTE *)(a1 + 8) )
    {
      case 0:
        if ( *(_BYTE *)(a1 + 9) == 2 )
        {
          v28 = a2;
          for ( i = 0; i < v17; i += 4 )
          {
            v7 = *v28 & 0xC0;
            v6 = *v28 & 0x30;
            v5 = *v28 & 0xC;
            *v28 = ((int)*(unsigned __int8 *)(v15 + (*v28 & 3 | (4 * (*v28 & 3)) | (16 * (*v28 & 3)) | ((*v28 & 3) << 6))) >> 6)
                 | ((int)*(unsigned __int8 *)(v15 + ((v5 >> 2) | v5 | (4 * v5) | (16 * v5))) >> 4) & 0xC
                 | ((int)*(unsigned __int8 *)(v15 + ((v6 >> 4) | (v6 >> 2) | v6 | (4 * v6))) >> 2) & 0x30
                 | *(_BYTE *)(v15 + ((v7 >> 6) | (v7 >> 4) | v7 | (v7 >> 2))) & 0xC0;
            ++v28;
          }
        }
        if ( *(_BYTE *)(a1 + 9) == 4 )
        {
          v29 = a2;
          for ( j = 0; ; j += 2 )
          {
            result = j;
            if ( j >= v17 )
              break;
            *v29 = ((int)*(unsigned __int8 *)(v15 + (*v29 & 0xF | (16 * (*v29 & 0xF)))) >> 4)
                 | *(_BYTE *)(v15 + (*v29 & 0xF0 | ((*v29 & 0xF0) >> 4))) & 0xF0;
            ++v29;
          }
        }
        else
        {
          result = *(unsigned __int8 *)(a1 + 9);
          if ( result == 8 )
          {
            v30 = a2;
            for ( k = 0; ; ++k )
            {
              result = k;
              if ( k >= v17 )
                break;
              *v30 = *(_BYTE *)(v15 + (unsigned __int8)*v30);
              ++v30;
            }
          }
          else if ( *(_BYTE *)(a1 + 9) == 16 )
          {
            result = (unsigned int)a2;
            v31 = a2;
            for ( m = 0; m < v17; ++m )
            {
              v4 = *(_WORD *)(*(_DWORD *)(v42 + 4 * ((int)v31[1] >> v16)) + 2 * *v31);
              *v31 = HIBYTE(v4);
              result = (unsigned __int8)v4;
              v31[1] = v4;
              v31 += 2;
            }
          }
        }
        break;
      case 2:
        result = a1;
        if ( *(_BYTE *)(a1 + 9) == 8 )
        {
          v18 = a2;
          for ( n = 0; n < v17; ++n )
          {
            *v18 = *(_BYTE *)(v15 + (unsigned __int8)*v18);
            v19 = v18 + 1;
            *v19 = *(_BYTE *)(v15 + (unsigned __int8)*v19);
            ++v19;
            *v19 = *(_BYTE *)(v15 + (unsigned __int8)*v19);
            v18 = v19 + 1;
            result = n + 1;
          }
        }
        else
        {
          v20 = a2;
          for ( ii = 0; ii < v17; ++ii )
          {
            v12 = *(_WORD *)(*(_DWORD *)(v42 + 4 * ((int)v20[1] >> v16)) + 2 * *v20);
            *v20 = HIBYTE(v12);
            v20[1] = v12;
            v21 = v20 + 2;
            v13 = *(_WORD *)(*(_DWORD *)(v42 + 4 * ((int)v21[1] >> v16)) + 2 * *v21);
            *v21 = HIBYTE(v13);
            v21[1] = v13;
            v21 += 2;
            v14 = *(_WORD *)(*(_DWORD *)(v42 + 4 * ((int)v21[1] >> v16)) + 2 * *v21);
            *v21 = HIBYTE(v14);
            v21[1] = v14;
            v20 = v21 + 2;
            result = ii + 1;
          }
        }
        break;
      case 4:
        result = a1;
        if ( *(_BYTE *)(a1 + 9) == 8 )
        {
          v26 = a2;
          for ( jj = 0; jj < v17; ++jj )
          {
            *v26 = *(_BYTE *)(v15 + (unsigned __int8)*v26);
            v26 += 2;
            result = jj + 1;
          }
        }
        else
        {
          v27 = a2;
          for ( kk = 0; kk < v17; ++kk )
          {
            v8 = *(_WORD *)(*(_DWORD *)(v42 + 4 * ((int)v27[1] >> v16)) + 2 * *v27);
            *v27 = HIBYTE(v8);
            v27[1] = v8;
            v27 += 4;
            result = kk + 1;
          }
        }
        break;
      case 6:
        result = a1;
        if ( *(_BYTE *)(a1 + 9) == 8 )
        {
          v22 = a2;
          for ( mm = 0; mm < v17; ++mm )
          {
            *v22 = *(_BYTE *)(v15 + (unsigned __int8)*v22);
            v23 = v22 + 1;
            *v23 = *(_BYTE *)(v15 + (unsigned __int8)*v23);
            ++v23;
            *v23 = *(_BYTE *)(v15 + (unsigned __int8)*v23);
            v22 = v23 + 2;
            result = mm + 1;
          }
        }
        else
        {
          result = (unsigned int)a2;
          v24 = a2;
          for ( nn = 0; nn < v17; ++nn )
          {
            v9 = *(_WORD *)(*(_DWORD *)(v42 + 4 * ((int)v24[1] >> v16)) + 2 * *v24);
            *v24 = HIBYTE(v9);
            v24[1] = v9;
            v25 = v24 + 2;
            v10 = *(_WORD *)(*(_DWORD *)(v42 + 4 * ((int)v25[1] >> v16)) + 2 * *v25);
            *v25 = HIBYTE(v10);
            v25[1] = v10;
            v25 += 2;
            v11 = *(_WORD *)(*(_DWORD *)(v42 + 4 * ((int)v25[1] >> v16)) + 2 * *v25);
            *v25 = HIBYTE(v11);
            result = (unsigned __int8)v11;
            v25[1] = v11;
            v24 = v25 + 4;
          }
        }
        break;
      default:
        return result;
    }
  }
  return result;
}
