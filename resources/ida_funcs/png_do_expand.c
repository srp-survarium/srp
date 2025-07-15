__int16 __cdecl png_do_expand(unsigned int *a1, int a2, _WORD *a3)
{
  unsigned int v3; // eax
  int v5; // [esp+0h] [ebp-38h]
  unsigned int v6; // [esp+4h] [ebp-34h]
  char v7; // [esp+8h] [ebp-30h]
  __int16 v8; // [esp+Ch] [ebp-2Ch]
  char v9; // [esp+11h] [ebp-27h]
  char v10; // [esp+12h] [ebp-26h]
  char v11; // [esp+13h] [ebp-25h]
  char v12; // [esp+14h] [ebp-24h]
  char v13; // [esp+15h] [ebp-23h]
  char v14; // [esp+16h] [ebp-22h]
  char v15; // [esp+17h] [ebp-21h]
  char v16; // [esp+18h] [ebp-20h]
  char v17; // [esp+19h] [ebp-1Fh]
  __int16 v18; // [esp+1Ch] [ebp-1Ch]
  int v19; // [esp+20h] [ebp-18h]
  int v20; // [esp+20h] [ebp-18h]
  int v21; // [esp+20h] [ebp-18h]
  unsigned int v22; // [esp+24h] [ebp-14h]
  _BYTE *v23; // [esp+28h] [ebp-10h]
  _BYTE *v24; // [esp+28h] [ebp-10h]
  _BYTE *v25; // [esp+28h] [ebp-10h]
  _BYTE *v26; // [esp+28h] [ebp-10h]
  _BYTE *v27; // [esp+28h] [ebp-10h]
  _BYTE *v28; // [esp+28h] [ebp-10h]
  _BYTE *v29; // [esp+28h] [ebp-10h]
  _BYTE *v30; // [esp+28h] [ebp-10h]
  _BYTE *v31; // [esp+28h] [ebp-10h]
  _BYTE *v32; // [esp+28h] [ebp-10h]
  _BYTE *v33; // [esp+28h] [ebp-10h]
  _BYTE *v34; // [esp+28h] [ebp-10h]
  _BYTE *v35; // [esp+28h] [ebp-10h]
  unsigned __int8 *v36; // [esp+2Ch] [ebp-Ch]
  unsigned __int8 *v37; // [esp+2Ch] [ebp-Ch]
  unsigned __int8 *v38; // [esp+2Ch] [ebp-Ch]
  _BYTE *v39; // [esp+2Ch] [ebp-Ch]
  _BYTE *v40; // [esp+2Ch] [ebp-Ch]
  _BYTE *v41; // [esp+2Ch] [ebp-Ch]
  _BYTE *v42; // [esp+2Ch] [ebp-Ch]
  _BYTE *v43; // [esp+2Ch] [ebp-Ch]
  _BYTE *v44; // [esp+2Ch] [ebp-Ch]
  _BYTE *v45; // [esp+2Ch] [ebp-Ch]
  unsigned int k; // [esp+30h] [ebp-8h]
  unsigned int m; // [esp+30h] [ebp-8h]
  unsigned int n; // [esp+30h] [ebp-8h]
  unsigned int ii; // [esp+30h] [ebp-8h]
  unsigned int jj; // [esp+30h] [ebp-8h]
  unsigned int i; // [esp+30h] [ebp-8h]
  unsigned int j; // [esp+30h] [ebp-8h]

  v22 = *a1;
  if ( *((_BYTE *)a1 + 8) )
  {
    v3 = *((unsigned __int8 *)a1 + 8);
    if ( v3 == 2 && a3 )
    {
      if ( *((_BYTE *)a1 + 9) == 8 )
      {
        v17 = a3[1];
        v15 = a3[2];
        v16 = a3[3];
        v42 = (_BYTE *)(a2 + a1[1] - 1);
        v30 = (_BYTE *)(a2 + 4 * v22 - 1);
        for ( i = 0; i < v22; ++i )
        {
          if ( *(v42 - 2) == v17 && *(v42 - 1) == v15 && *v42 == v16 )
          {
            *v30 = 0;
            v31 = v30 - 1;
          }
          else
          {
            *v30 = -1;
            v31 = v30 - 1;
          }
          *v31 = *v42;
          v32 = v31 - 1;
          v43 = v42 - 1;
          *v32-- = *v43;
          *v32 = *--v43;
          v30 = v32 - 1;
          v42 = v43 - 1;
        }
      }
      else if ( *((_BYTE *)a1 + 9) == 16 )
      {
        v11 = HIBYTE(a3[1]);
        v13 = HIBYTE(a3[2]);
        v12 = HIBYTE(a3[3]);
        v9 = a3[1];
        v10 = a3[2];
        v14 = a3[3];
        v44 = (_BYTE *)(a2 + a1[1] - 1);
        v33 = (_BYTE *)(a2 + 8 * v22 - 1);
        for ( j = 0; j < v22; ++j )
        {
          if ( *(v44 - 5) == v11
            && *(v44 - 4) == v9
            && *(v44 - 3) == v13
            && *(v44 - 2) == v10
            && *(v44 - 1) == v12
            && *v44 == v14 )
          {
            *v33 = 0;
            *(v33 - 1) = 0;
            v34 = v33 - 2;
          }
          else
          {
            *v33 = -1;
            *(v33 - 1) = -1;
            v34 = v33 - 2;
          }
          *v34 = *v44;
          v35 = v34 - 1;
          v45 = v44 - 1;
          *v35-- = *v45;
          *v35-- = *--v45;
          *v35-- = *--v45;
          *v35-- = *--v45;
          *v35 = *--v45;
          v33 = v35 - 1;
          v44 = v45 - 1;
        }
      }
      *((_BYTE *)a1 + 8) = 6;
      *((_BYTE *)a1 + 10) = 4;
      *((_BYTE *)a1 + 11) = 4 * *((_BYTE *)a1 + 9);
      if ( *((unsigned __int8 *)a1 + 11) < 8u )
      {
        v3 = (v22 * *((unsigned __int8 *)a1 + 11) + 7) >> 3;
        v5 = v3;
      }
      else
      {
        LOWORD(v3) = (_WORD)a1;
        v5 = v22 * (*((unsigned __int8 *)a1 + 11) >> 3);
      }
      a1[1] = v5;
    }
  }
  else
  {
    if ( a3 )
      v8 = a3[4];
    else
      v8 = 0;
    LOWORD(v3) = v8;
    v18 = v8;
    if ( *((unsigned __int8 *)a1 + 9) < 8u )
    {
      v7 = *((_BYTE *)a1 + 9);
      switch ( v7 )
      {
        case 1:
          v18 = 255 * (v8 & 1);
          v36 = (unsigned __int8 *)(a2 + ((v22 - 1) >> 3));
          v23 = (_BYTE *)(a2 + v22 - 1);
          v19 = 7 - (((_BYTE)v22 + 7) & 7);
          for ( k = 0; k < v22; ++k )
          {
            if ( (((int)*v36 >> v19) & 1) != 0 )
              *v23 = -1;
            else
              *v23 = 0;
            if ( v19 == 7 )
            {
              v19 = 0;
              --v36;
            }
            else
            {
              ++v19;
            }
            --v23;
          }
          break;
        case 2:
          v18 = 85 * (v8 & 3);
          v37 = (unsigned __int8 *)(a2 + ((v22 - 1) >> 2));
          v24 = (_BYTE *)(a2 + v22 - 1);
          v20 = 2 * (3 - (((_BYTE)v22 + 3) & 3));
          for ( m = 0; m < v22; ++m )
          {
            *v24 = ((((int)*v37 >> v20) & 3) << 6)
                 | (16 * (((int)*v37 >> v20) & 3))
                 | ((int)*v37 >> v20) & 3
                 | (4 * (((int)*v37 >> v20) & 3));
            if ( v20 == 6 )
            {
              v20 = 0;
              --v37;
            }
            else
            {
              v20 += 2;
            }
            --v24;
          }
          break;
        case 4:
          v18 = 17 * (v8 & 0xF);
          v38 = (unsigned __int8 *)(a2 + ((v22 - 1) >> 1));
          v25 = (_BYTE *)(a2 + v22 - 1);
          v21 = 4 * (1 - (((_BYTE)v22 + 1) & 1));
          for ( n = 0; n < v22; ++n )
          {
            *v25 = ((int)*v38 >> v21) & 0xF | (16 * (((int)*v38 >> v21) & 0xF));
            if ( v21 == 4 )
            {
              v21 = 0;
              --v38;
            }
            else
            {
              v21 = 4;
            }
            --v25;
          }
          break;
      }
      *((_BYTE *)a1 + 9) = 8;
      LOWORD(v3) = (_WORD)a1;
      *((_BYTE *)a1 + 11) = 8;
      a1[1] = v22;
    }
    if ( a3 )
    {
      if ( *((_BYTE *)a1 + 9) == 8 )
      {
        v39 = (_BYTE *)(a2 + v22 - 1);
        v26 = (_BYTE *)(a2 + 2 * v22 - 1);
        for ( ii = 0; ii < v22; ++ii )
        {
          if ( (unsigned __int8)*v39 == (unsigned __int8)v18 )
            *v26 = 0;
          else
            *v26 = -1;
          v27 = v26 - 1;
          *v27 = *v39;
          v26 = v27 - 1;
          --v39;
        }
      }
      else if ( *((_BYTE *)a1 + 9) == 16 )
      {
        v40 = (_BYTE *)(a2 + a1[1] - 1);
        v28 = (_BYTE *)(a2 + 2 * a1[1] - 1);
        for ( jj = 0; jj < v22; ++jj )
        {
          if ( __PAIR64__((unsigned __int8)*v40, (unsigned __int8)*(v40 - 1)) == __PAIR64__(
                                                                                   (unsigned __int8)v18,
                                                                                   HIBYTE(v18)) )
          {
            *v28 = 0;
            *(v28 - 1) = 0;
          }
          else
          {
            *v28 = -1;
            *(v28 - 1) = -1;
          }
          v29 = v28 - 2;
          *v29-- = *v40;
          v41 = v40 - 1;
          *v29 = *v41;
          v28 = v29 - 1;
          v40 = v41 - 1;
        }
      }
      *((_BYTE *)a1 + 8) = 4;
      *((_BYTE *)a1 + 10) = 2;
      *((_BYTE *)a1 + 11) = 2 * *((_BYTE *)a1 + 9);
      if ( *((unsigned __int8 *)a1 + 11) < 8u )
        v6 = (v22 * *((unsigned __int8 *)a1 + 11) + 7) >> 3;
      else
        v6 = v22 * (*((unsigned __int8 *)a1 + 11) >> 3);
      LOWORD(v3) = (_WORD)a1;
      a1[1] = v6;
    }
  }
  return v3;
}
