unsigned int __cdecl png_do_read_interlace(unsigned int a1, int a2, int a3, int a4)
{
  unsigned int result; // eax
  int v5; // [esp+0h] [ebp-B4h]
  char v6; // [esp+4h] [ebp-B0h]
  int kk; // [esp+8h] [ebp-ACh]
  unsigned __int8 dst[8]; // [esp+Ch] [ebp-A8h] BYREF
  unsigned int count; // [esp+18h] [ebp-9Ch]
  unsigned __int8 *v10; // [esp+1Ch] [ebp-98h]
  unsigned __int8 *src; // [esp+20h] [ebp-94h]
  unsigned int jj; // [esp+24h] [ebp-90h]
  int v13; // [esp+28h] [ebp-8Ch]
  int ii; // [esp+2Ch] [ebp-88h]
  unsigned __int8 v15; // [esp+33h] [ebp-81h]
  _BYTE *v16; // [esp+34h] [ebp-80h]
  int v17; // [esp+38h] [ebp-7Ch]
  int v18; // [esp+3Ch] [ebp-78h]
  int v19; // [esp+40h] [ebp-74h]
  unsigned __int8 *v20; // [esp+44h] [ebp-70h]
  int v21; // [esp+48h] [ebp-6Ch]
  unsigned int n; // [esp+4Ch] [ebp-68h]
  int v23; // [esp+50h] [ebp-64h]
  int v24; // [esp+54h] [ebp-60h]
  int m; // [esp+58h] [ebp-5Ch]
  unsigned __int8 v26; // [esp+5Fh] [ebp-55h]
  _BYTE *v27; // [esp+60h] [ebp-54h]
  int v28; // [esp+64h] [ebp-50h]
  int v29; // [esp+68h] [ebp-4Ch]
  int v30; // [esp+6Ch] [ebp-48h]
  unsigned __int8 *v31; // [esp+70h] [ebp-44h]
  int v32; // [esp+74h] [ebp-40h]
  unsigned int k; // [esp+78h] [ebp-3Ch]
  int v34; // [esp+7Ch] [ebp-38h]
  int v35; // [esp+80h] [ebp-34h]
  int j; // [esp+84h] [ebp-30h]
  _BYTE *v37; // [esp+88h] [ebp-2Ch]
  int v38; // [esp+8Ch] [ebp-28h]
  int v39; // [esp+90h] [ebp-24h]
  int v40; // [esp+94h] [ebp-20h]
  unsigned __int8 *v41; // [esp+98h] [ebp-1Ch]
  int v42; // [esp+9Ch] [ebp-18h]
  unsigned int i; // [esp+A0h] [ebp-14h]
  int v44; // [esp+A4h] [ebp-10h]
  unsigned __int8 v45; // [esp+ABh] [ebp-9h]
  int v46; // [esp+ACh] [ebp-8h]
  int v47; // [esp+B0h] [ebp-4h]

  if ( a2 && a1 )
  {
    v47 = dword_85F390[a3] * *(_DWORD *)a1;
    v6 = *(_BYTE *)(a1 + 11);
    switch ( v6 )
    {
      case 1:
        v41 = (unsigned __int8 *)(a2 + ((unsigned int)(*(_DWORD *)a1 - 1) >> 3));
        v37 = (_BYTE *)(a2 + ((unsigned int)(v47 - 1) >> 3));
        v46 = dword_85F390[a3];
        if ( ((unsigned int)&_sbh_sizeHeaderList & a4) != 0 )
        {
          v38 = ((unsigned __int8)*(_DWORD *)a1 + 7) & 7;
          v39 = ((_BYTE)v47 + 7) & 7;
          v44 = 7;
          v42 = 0;
          v40 = -1;
        }
        else
        {
          v38 = 7 - (((unsigned __int8)*(_DWORD *)a1 + 7) & 7);
          v39 = 7 - (((_BYTE)v47 + 7) & 7);
          v44 = 0;
          v42 = 7;
          v40 = 1;
        }
        for ( i = 0; i < *(_DWORD *)a1; ++i )
        {
          v45 = ((int)*v41 >> v38) & 1;
          for ( j = 0; j < v46; ++j )
          {
            *v37 &= 32639 >> (7 - v39);
            *v37 |= v45 << v39;
            if ( v39 == v42 )
            {
              v39 = v44;
              --v37;
            }
            else
            {
              v39 += v40;
            }
          }
          if ( v38 == v42 )
          {
            v38 = v44;
            --v41;
          }
          else
          {
            v38 += v40;
          }
        }
        break;
      case 2:
        v31 = (unsigned __int8 *)(a2 + ((unsigned int)(*(_DWORD *)a1 - 1) >> 2));
        v27 = (_BYTE *)(a2 + ((unsigned int)(v47 - 1) >> 2));
        v35 = dword_85F390[a3];
        if ( ((unsigned int)&_sbh_sizeHeaderList & a4) != 0 )
        {
          v28 = 2 * (((unsigned __int8)*(_DWORD *)a1 + 3) & 3);
          v29 = 2 * (((_BYTE)v47 + 3) & 3);
          v34 = 6;
          v32 = 0;
          v30 = -2;
        }
        else
        {
          v28 = 2 * (3 - (((unsigned __int8)*(_DWORD *)a1 + 3) & 3));
          v29 = 2 * (3 - (((_BYTE)v47 + 3) & 3));
          v34 = 0;
          v32 = 6;
          v30 = 2;
        }
        for ( k = 0; k < *(_DWORD *)a1; ++k )
        {
          v26 = ((int)*v31 >> v28) & 3;
          for ( m = 0; m < v35; ++m )
          {
            *v27 &= 16191 >> (6 - v29);
            *v27 |= v26 << v29;
            if ( v29 == v32 )
            {
              v29 = v34;
              --v27;
            }
            else
            {
              v29 += v30;
            }
          }
          if ( v28 == v32 )
          {
            v28 = v34;
            --v31;
          }
          else
          {
            v28 += v30;
          }
        }
        break;
      case 4:
        v20 = (unsigned __int8 *)(a2 + ((unsigned int)(*(_DWORD *)a1 - 1) >> 1));
        v16 = (_BYTE *)(a2 + ((unsigned int)(v47 - 1) >> 1));
        v24 = dword_85F390[a3];
        if ( ((unsigned int)&_sbh_sizeHeaderList & a4) != 0 )
        {
          v17 = 4 * (((unsigned __int8)*(_DWORD *)a1 + 1) & 1);
          v18 = 4 * (((_BYTE)v47 + 1) & 1);
          v23 = 4;
          v21 = 0;
          v19 = -4;
        }
        else
        {
          v17 = 4 * (1 - (((unsigned __int8)*(_DWORD *)a1 + 1) & 1));
          v18 = 4 * (1 - (((_BYTE)v47 + 1) & 1));
          v23 = 0;
          v21 = 4;
          v19 = 4;
        }
        for ( n = 0; n < *(_DWORD *)a1; ++n )
        {
          v15 = ((int)*v20 >> v17) & 0xF;
          for ( ii = 0; ii < v24; ++ii )
          {
            *v16 &= 3855 >> (4 - v18);
            *v16 |= v15 << v18;
            if ( v18 == v21 )
            {
              v18 = v23;
              --v16;
            }
            else
            {
              v18 += v19;
            }
          }
          if ( v17 == v21 )
          {
            v17 = v23;
            --v20;
          }
          else
          {
            v17 += v19;
          }
        }
        break;
      default:
        count = (int)*(unsigned __int8 *)(a1 + 11) >> 3;
        src = (unsigned __int8 *)(a2 + count * (*(_DWORD *)a1 - 1));
        v10 = (unsigned __int8 *)(a2 + count * (v47 - 1));
        v13 = dword_85F390[a3];
        for ( jj = 0; jj < *(_DWORD *)a1; ++jj )
        {
          memcpy(dst, src, count);
          for ( kk = 0; kk < v13; ++kk )
          {
            memcpy(v10, dst, count);
            v10 -= count;
          }
          src -= count;
        }
        break;
    }
    *(_DWORD *)a1 = v47;
    if ( *(unsigned __int8 *)(a1 + 11) < 8u )
    {
      result = (v47 * (unsigned int)*(unsigned __int8 *)(a1 + 11) + 7) >> 3;
      v5 = result;
    }
    else
    {
      result = a1;
      v5 = v47 * (*(unsigned __int8 *)(a1 + 11) >> 3);
    }
    *(_DWORD *)(a1 + 4) = v5;
  }
  return result;
}
