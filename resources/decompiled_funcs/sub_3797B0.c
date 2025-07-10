int __cdecl sub_3797B0(int *a1)
{
  int *v1; // ebp
  int result; // eax
  int v3; // ecx
  int v4; // edi
  double v5; // st7
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // esi
  double *v24; // eax
  int v25; // edx
  int v26; // ecx
  int *v27; // ecx
  unsigned __int16 *v28; // eax
  __int16 *v29; // edx
  int v30; // esi
  int v31; // ecx
  int i; // eax
  bool v33; // cc
  int (__cdecl *v34)(int, int, int, int, int); // [esp+8h] [ebp-10h]
  int *v35; // [esp+Ch] [ebp-Ch]
  int v36; // [esp+10h] [ebp-8h]
  int v37; // [esp+14h] [ebp-4h]
  int v38; // [esp+14h] [ebp-4h]

  v1 = a1;
  result = a1[107];
  v3 = a1[49];
  v4 = 0;
  v34 = 0;
  v36 = 0;
  if ( a1[9] > 0 )
  {
    v5 = 0.125;
    v6 = v3 + 40;
    v37 = v3 + 40;
    v35 = (int *)(result + 44);
    do
    {
      v7 = *(_DWORD *)v6 + (*(_DWORD *)(v6 - 4) << 8);
      if ( v7 > 1806 )
      {
        if ( v7 > 3078 )
        {
          if ( v7 > 3598 )
          {
            v21 = v7 - 3855;
            if ( v21 )
            {
              v22 = v21 - 249;
              if ( v22 )
              {
                if ( v22 != 8 )
                {
LABEL_78:
                  *(_DWORD *)(*v1 + 20) = 7;
                  *(_DWORD *)(*v1 + 24) = *(_DWORD *)(v6 - 4);
                  *(_DWORD *)(*v1 + 28) = *(_DWORD *)v6;
                  (*(void (__cdecl **)(int *))*v1)(v1);
                  v5 = 0.125;
                  goto LABEL_83;
                }
                v34 = jpeg_idct_16x16;
              }
              else
              {
                v34 = jpeg_idct_16x8;
              }
            }
            else
            {
              v34 = jpeg_idct_15x15;
            }
          }
          else
          {
            switch ( v7 )
            {
              case 3598:
                v34 = jpeg_idct_14x14;
                break;
              case 3084:
                v34 = jpeg_idct_12x12;
                break;
              case 3341:
                v34 = jpeg_idct_13x13;
                break;
              case 3591:
                v34 = jpeg_idct_14x7;
                break;
              default:
                goto LABEL_78;
            }
          }
        }
        else if ( v7 == 3078 )
        {
          v34 = jpeg_idct_12x6;
        }
        else if ( v7 > 2313 )
        {
          v19 = v7 - 2565;
          if ( v19 )
          {
            v20 = v19 - 5;
            if ( v20 )
            {
              if ( v20 != 257 )
                goto LABEL_78;
              v34 = jpeg_idct_11x11;
            }
            else
            {
              v34 = jpeg_idct_10x10;
            }
          }
          else
          {
            v34 = jpeg_idct_10x5;
          }
        }
        else if ( v7 == 2313 )
        {
          v34 = jpeg_idct_9x9;
        }
        else
        {
          v15 = v7 - 2052;
          if ( v15 )
          {
            v16 = v15 - 4;
            if ( v16 )
            {
              if ( v16 != 8 )
                goto LABEL_78;
              v34 = jpeg_idct_8x16;
            }
            else
            {
              v17 = v1[17];
              if ( v17 )
              {
                v18 = v17 - 1;
                if ( v18 )
                {
                  if ( v18 == 1 )
                  {
                    v34 = jpeg_idct_float;
                    v4 = 2;
                  }
                  else
                  {
                    *(_DWORD *)(*v1 + 20) = 49;
                    (*(void (__cdecl **)(int *))*v1)(v1);
                    v5 = 0.125;
                  }
                }
                else
                {
                  v34 = jpeg_idct_ifast;
                  v4 = 1;
                }
                goto LABEL_83;
              }
              v34 = jpeg_idct_islow;
            }
          }
          else
          {
            v34 = jpeg_idct_8x4;
          }
        }
      }
      else if ( v7 == 1806 )
      {
        v34 = jpeg_idct_7x14;
      }
      else if ( v7 > 1028 )
      {
        if ( v7 > 1539 )
        {
          v13 = v7 - 1542;
          if ( v13 )
          {
            v14 = v13 - 6;
            if ( v14 )
            {
              if ( v14 != 251 )
                goto LABEL_78;
              v34 = jpeg_idct_7x7;
            }
            else
            {
              v34 = jpeg_idct_6x12;
            }
          }
          else
          {
            v34 = jpeg_idct_6x6;
          }
        }
        else if ( v7 == 1539 )
        {
          v34 = jpeg_idct_6x3;
        }
        else
        {
          v11 = v7 - 1032;
          if ( v11 )
          {
            v12 = v11 - 253;
            if ( v12 )
            {
              if ( v12 != 5 )
                goto LABEL_78;
              v34 = jpeg_idct_5x10;
            }
            else
            {
              v34 = jpeg_idct_5x5;
            }
          }
          else
          {
            v34 = jpeg_idct_4x8;
          }
        }
      }
      else if ( v7 == 1028 )
      {
        v34 = jpeg_idct_4x4;
      }
      else if ( v7 > 516 )
      {
        v9 = v7 - 771;
        if ( v9 )
        {
          v10 = v9 - 3;
          if ( v10 )
          {
            if ( v10 != 252 )
              goto LABEL_78;
            v34 = jpeg_idct_4x2;
          }
          else
          {
            v34 = jpeg_idct_3x6;
          }
        }
        else
        {
          v34 = jpeg_idct_3x3;
        }
      }
      else if ( v7 == 516 )
      {
        v34 = jpeg_idct_2x4;
      }
      else if ( v7 > 513 )
      {
        if ( v7 != 514 )
          goto LABEL_78;
        v34 = jpeg_idct_2x2;
      }
      else if ( v7 == 513 )
      {
        v34 = jpeg_idct_2x1;
      }
      else
      {
        v8 = v7 - 257;
        if ( v8 )
        {
          if ( v8 != 1 )
            goto LABEL_78;
          v34 = jpeg_idct_1x2;
        }
        else
        {
          v34 = jpeg_idct_1x1;
        }
      }
      v4 = 0;
LABEL_83:
      *(v35 - 10) = (int)v34;
      if ( *(_BYTE *)(v6 + 12) )
      {
        if ( *v35 != v4 )
        {
          v23 = *(_DWORD *)(v6 + 40);
          if ( v23 )
          {
            *v35 = v4;
            if ( v4 )
            {
              if ( v4 == 1 )
              {
                v27 = (int *)(*(_DWORD *)(v6 + 44) + 8);
                v28 = (unsigned __int16 *)(v23 + 4);
                v29 = &word_862E8A;
                v30 = -v23;
                do
                {
                  *(v27 - 2) = (*(v29 - 1) * *(v28 - 2) + 2048) >> 12;
                  *(v27 - 1) = (*v29 * *(v28 - 1) + 2048) >> 12;
                  *v27 = (*v28 * *(__int16 *)((char *)&word_862E88 + (_DWORD)v28 + v30) + 2048) >> 12;
                  v27[1] = (v28[1] * *(__int16 *)((char *)&word_862E8A + (_DWORD)v28 + v30) + 2048) >> 12;
                  v29 += 4;
                  v27 += 4;
                  v28 += 4;
                }
                while ( (int)v29 < (int)word_862F0A );
                v6 = v37;
                v1 = a1;
              }
              else
              {
                v24 = (double *)&unk_862F08;
                v25 = *(_DWORD *)(v6 + 44) + 8;
                v26 = v23 + 4;
                do
                {
                  v38 = *(unsigned __int16 *)(v26 - 4);
                  ++v24;
                  v26 += 16;
                  v25 += 32;
                  *(float *)(v25 - 40) = (double)v38 * *(v24 - 1) * v5;
                  *(float *)(v25 - 36) = (double)*(unsigned __int16 *)(v26 - 18) * *(v24 - 1) * 1.387039845 * v5;
                  *(float *)(v25 - 32) = (double)*(unsigned __int16 *)(v26 - 16) * *(v24 - 1) * 1.306562965 * v5;
                  *(float *)(v25 - 28) = (double)*(unsigned __int16 *)(v26 - 14) * *(v24 - 1) * 1.175875602 * v5;
                  *(float *)(v25 - 24) = (double)*(unsigned __int16 *)(v26 - 12) * *(v24 - 1) * v5;
                  *(float *)(v25 - 20) = (double)*(unsigned __int16 *)(v26 - 10) * *(v24 - 1) * 0.785694958 * v5;
                  *(float *)(v25 - 16) = (double)*(unsigned __int16 *)(v26 - 8) * *(v24 - 1) * 0.5411961 * v5;
                  *(float *)(v25 - 12) = (double)*(unsigned __int16 *)(v26 - 6) * *(v24 - 1) * 0.275899379 * v5;
                }
                while ( (int)v24 < (int)dbl_862F48 );
              }
            }
            else
            {
              v31 = *(_DWORD *)(v6 + 44);
              for ( i = 0; i < 64; ++i )
                *(_DWORD *)(v31 + 4 * i) = *(unsigned __int16 *)(v23 + 2 * i);
            }
          }
        }
      }
      ++v35;
      result = v36 + 1;
      v6 += 88;
      v33 = ++v36 < v1[9];
      v37 = v6;
    }
    while ( v33 );
  }
  return result;
}
