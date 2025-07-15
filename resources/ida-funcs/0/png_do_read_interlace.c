unsigned int __cdecl png_do_read_interlace(unsigned int a1, int a2, int a3, int a4)
{
  unsigned int result; // eax
  int v5; // [esp+0h] [ebp-B4h]
  char v6; // [esp+4h] [ebp-B0h]
  int kk; // [esp+8h] [ebp-ACh]
  __m128i dst; // [esp+Ch] [ebp-A8h] BYREF
  unsigned __int8 *v9; // [esp+1Ch] [ebp-98h]
  unsigned __int8 *src; // [esp+20h] [ebp-94h]
  unsigned int jj; // [esp+24h] [ebp-90h]
  int v12; // [esp+28h] [ebp-8Ch]
  int ii; // [esp+2Ch] [ebp-88h]
  unsigned __int8 v14; // [esp+33h] [ebp-81h]
  _BYTE *v15; // [esp+34h] [ebp-80h]
  int v16; // [esp+38h] [ebp-7Ch]
  int v17; // [esp+3Ch] [ebp-78h]
  int v18; // [esp+40h] [ebp-74h]
  unsigned __int8 *v19; // [esp+44h] [ebp-70h]
  int v20; // [esp+48h] [ebp-6Ch]
  unsigned int n; // [esp+4Ch] [ebp-68h]
  int v22; // [esp+50h] [ebp-64h]
  int v23; // [esp+54h] [ebp-60h]
  int m; // [esp+58h] [ebp-5Ch]
  unsigned __int8 v25; // [esp+5Fh] [ebp-55h]
  _BYTE *v26; // [esp+60h] [ebp-54h]
  int v27; // [esp+64h] [ebp-50h]
  int v28; // [esp+68h] [ebp-4Ch]
  int v29; // [esp+6Ch] [ebp-48h]
  unsigned __int8 *v30; // [esp+70h] [ebp-44h]
  int v31; // [esp+74h] [ebp-40h]
  unsigned int k; // [esp+78h] [ebp-3Ch]
  int v33; // [esp+7Ch] [ebp-38h]
  int v34; // [esp+80h] [ebp-34h]
  int j; // [esp+84h] [ebp-30h]
  _BYTE *v36; // [esp+88h] [ebp-2Ch]
  int v37; // [esp+8Ch] [ebp-28h]
  int v38; // [esp+90h] [ebp-24h]
  int v39; // [esp+94h] [ebp-20h]
  unsigned __int8 *v40; // [esp+98h] [ebp-1Ch]
  int v41; // [esp+9Ch] [ebp-18h]
  unsigned int i; // [esp+A0h] [ebp-14h]
  int v43; // [esp+A4h] [ebp-10h]
  unsigned __int8 v44; // [esp+ABh] [ebp-9h]
  int v45; // [esp+ACh] [ebp-8h]
  int v46; // [esp+B0h] [ebp-4h]

  if ( a2 && a1 )
  {
    v46 = dword_6F2CD8[a3] * *(_DWORD *)a1;
    v6 = *(_BYTE *)(a1 + 11);
    switch ( v6 )
    {
      case 1:
        v40 = (unsigned __int8 *)(a2 + ((unsigned int)(*(_DWORD *)a1 - 1) >> 3));
        v36 = (_BYTE *)(a2 + ((unsigned int)(v46 - 1) >> 3));
        v45 = dword_6F2CD8[a3];
        if ( ((unsigned int)&_sbh_sizeHeaderList & a4) != 0 )
        {
          v37 = ((unsigned __int8)*(_DWORD *)a1 + 7) & 7;
          v38 = ((_BYTE)v46 + 7) & 7;
          v43 = 7;
          v41 = 0;
          v39 = -1;
        }
        else
        {
          v37 = 7 - (((unsigned __int8)*(_DWORD *)a1 + 7) & 7);
          v38 = 7 - (((_BYTE)v46 + 7) & 7);
          v43 = 0;
          v41 = 7;
          v39 = 1;
        }
        for ( i = 0; i < *(_DWORD *)a1; ++i )
        {
          v44 = ((int)*v40 >> v37) & 1;
          for ( j = 0; j < v45; ++j )
          {
            *v36 &= 32639 >> (7 - v38);
            *v36 |= v44 << v38;
            if ( v38 == v41 )
            {
              v38 = v43;
              --v36;
            }
            else
            {
              v38 += v39;
            }
          }
          if ( v37 == v41 )
          {
            v37 = v43;
            --v40;
          }
          else
          {
            v37 += v39;
          }
        }
        break;
      case 2:
        v30 = (unsigned __int8 *)(a2 + ((unsigned int)(*(_DWORD *)a1 - 1) >> 2));
        v26 = (_BYTE *)(a2 + ((unsigned int)(v46 - 1) >> 2));
        v34 = dword_6F2CD8[a3];
        if ( ((unsigned int)&_sbh_sizeHeaderList & a4) != 0 )
        {
          v27 = 2 * (((unsigned __int8)*(_DWORD *)a1 + 3) & 3);
          v28 = 2 * (((_BYTE)v46 + 3) & 3);
          v33 = 6;
          v31 = 0;
          v29 = -2;
        }
        else
        {
          v27 = 2 * (3 - (((unsigned __int8)*(_DWORD *)a1 + 3) & 3));
          v28 = 2 * (3 - (((_BYTE)v46 + 3) & 3));
          v33 = 0;
          v31 = 6;
          v29 = 2;
        }
        for ( k = 0; k < *(_DWORD *)a1; ++k )
        {
          v25 = ((int)*v30 >> v27) & 3;
          for ( m = 0; m < v34; ++m )
          {
            *v26 &= 16191 >> (6 - v28);
            *v26 |= v25 << v28;
            if ( v28 == v31 )
            {
              v28 = v33;
              --v26;
            }
            else
            {
              v28 += v29;
            }
          }
          if ( v27 == v31 )
          {
            v27 = v33;
            --v30;
          }
          else
          {
            v27 += v29;
          }
        }
        break;
      case 4:
        v19 = (unsigned __int8 *)(a2 + ((unsigned int)(*(_DWORD *)a1 - 1) >> 1));
        v15 = (_BYTE *)(a2 + ((unsigned int)(v46 - 1) >> 1));
        v23 = dword_6F2CD8[a3];
        if ( ((unsigned int)&_sbh_sizeHeaderList & a4) != 0 )
        {
          v16 = 4 * (((unsigned __int8)*(_DWORD *)a1 + 1) & 1);
          v17 = 4 * (((_BYTE)v46 + 1) & 1);
          v22 = 4;
          v20 = 0;
          v18 = -4;
        }
        else
        {
          v16 = 4 * (1 - (((unsigned __int8)*(_DWORD *)a1 + 1) & 1));
          v17 = 4 * (1 - (((_BYTE)v46 + 1) & 1));
          v22 = 0;
          v20 = 4;
          v18 = 4;
        }
        for ( n = 0; n < *(_DWORD *)a1; ++n )
        {
          v14 = ((int)*v19 >> v16) & 0xF;
          for ( ii = 0; ii < v23; ++ii )
          {
            *v15 &= 3855 >> (4 - v17);
            *v15 |= v14 << v17;
            if ( v17 == v20 )
            {
              v17 = v22;
              --v15;
            }
            else
            {
              v17 += v18;
            }
          }
          if ( v16 == v20 )
          {
            v16 = v22;
            --v19;
          }
          else
          {
            v16 += v18;
          }
        }
        break;
      default:
        dst.m128i_i32[3] = (int)*(unsigned __int8 *)(a1 + 11) >> 3;
        src = (unsigned __int8 *)(a2 + dst.m128i_i32[3] * (*(_DWORD *)a1 - 1));
        v9 = (unsigned __int8 *)(a2 + dst.m128i_i32[3] * (v46 - 1));
        v12 = dword_6F2CD8[a3];
        for ( jj = 0; jj < *(_DWORD *)a1; ++jj )
        {
          memcpy((int)&dst, (const __m128i *)src, dst.m128i_u32[3]);
          for ( kk = 0; kk < v12; ++kk )
          {
            memcpy((int)v9, &dst, dst.m128i_u32[3]);
            v9 -= dst.m128i_i32[3];
          }
          src -= dst.m128i_i32[3];
        }
        break;
    }
    *(_DWORD *)a1 = v46;
    if ( *(unsigned __int8 *)(a1 + 11) < 8u )
    {
      result = (v46 * (unsigned int)*(unsigned __int8 *)(a1 + 11) + 7) >> 3;
      v5 = result;
    }
    else
    {
      result = a1;
      v5 = v46 * (*(unsigned __int8 *)(a1 + 11) >> 3);
    }
    *(_DWORD *)(a1 + 4) = v5;
  }
  return result;
}
