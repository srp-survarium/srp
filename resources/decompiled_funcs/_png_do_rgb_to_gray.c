int __cdecl png_do_rgb_to_gray(int a1, unsigned int *a2, unsigned __int8 *a3)
{
  unsigned int v4; // [esp+0h] [ebp-84h]
  unsigned __int16 v5; // [esp+4h] [ebp-80h]
  __int16 v6; // [esp+8h] [ebp-7Ch]
  unsigned __int16 v7; // [esp+Ch] [ebp-78h]
  unsigned __int16 v8; // [esp+10h] [ebp-74h]
  unsigned __int8 *v9; // [esp+14h] [ebp-70h]
  _BYTE *v10; // [esp+14h] [ebp-70h]
  unsigned __int16 *v11; // [esp+18h] [ebp-6Ch]
  unsigned __int16 *v12; // [esp+18h] [ebp-6Ch]
  _BYTE *v13; // [esp+18h] [ebp-6Ch]
  unsigned int m; // [esp+1Ch] [ebp-68h]
  unsigned __int16 v15; // [esp+20h] [ebp-64h]
  unsigned __int16 v16; // [esp+30h] [ebp-54h]
  unsigned __int16 v17; // [esp+34h] [ebp-50h]
  unsigned __int16 v18; // [esp+38h] [ebp-4Ch]
  unsigned __int16 v19; // [esp+3Ch] [ebp-48h]
  unsigned __int8 *v20; // [esp+40h] [ebp-44h]
  _BYTE *v21; // [esp+40h] [ebp-44h]
  unsigned __int16 *v22; // [esp+44h] [ebp-40h]
  unsigned __int16 *v23; // [esp+44h] [ebp-40h]
  _BYTE *v24; // [esp+44h] [ebp-40h]
  unsigned int k; // [esp+48h] [ebp-3Ch]
  unsigned __int8 v26; // [esp+4Dh] [ebp-37h]
  unsigned __int8 v27; // [esp+4Eh] [ebp-36h]
  unsigned __int8 v28; // [esp+4Fh] [ebp-35h]
  unsigned __int8 *v29; // [esp+50h] [ebp-34h]
  unsigned __int8 *v30; // [esp+54h] [ebp-30h]
  unsigned __int8 *v31; // [esp+54h] [ebp-30h]
  unsigned int j; // [esp+58h] [ebp-2Ch]
  unsigned __int8 v33; // [esp+5Dh] [ebp-27h]
  unsigned __int8 v34; // [esp+5Eh] [ebp-26h]
  unsigned __int8 v35; // [esp+5Fh] [ebp-25h]
  unsigned __int8 *v36; // [esp+60h] [ebp-24h]
  unsigned __int8 *v37; // [esp+64h] [ebp-20h]
  unsigned __int8 *v38; // [esp+64h] [ebp-20h]
  unsigned int i; // [esp+68h] [ebp-1Ch]
  int v40; // [esp+6Ch] [ebp-18h]
  unsigned int v41; // [esp+70h] [ebp-14h]
  int v42; // [esp+74h] [ebp-10h]
  int v43; // [esp+78h] [ebp-Ch]
  BOOL v44; // [esp+7Ch] [ebp-8h]
  int v45; // [esp+80h] [ebp-4h]

  v45 = 0;
  if ( (a2[2] & 1) == 0 && (a2[2] & 2) != 0 )
  {
    v43 = *(unsigned __int16 *)(a1 + 596);
    v40 = *(unsigned __int16 *)(a1 + 598);
    v42 = 0x8000 - v43 - v40;
    v41 = *a2;
    v44 = (a2[2] & 4) != 0;
    if ( *((_BYTE *)a2 + 9) == 8 )
    {
      if ( *(_DWORD *)(a1 + 392) && *(_DWORD *)(a1 + 396) )
      {
        v37 = a3;
        v36 = a3;
        for ( i = 0; i < v41; ++i )
        {
          v35 = *v37;
          v38 = v37 + 1;
          v33 = *v38++;
          v34 = *v38;
          v37 = v38 + 1;
          if ( v35 == v33 && v35 == v34 )
          {
            if ( *(_DWORD *)(a1 + 384) )
              v35 = *(_BYTE *)(v35 + *(_DWORD *)(a1 + 384));
            *v36++ = v35;
          }
          else
          {
            v45 |= 1u;
            *v36++ = *(_BYTE *)(((v40 * *(unsigned __int8 *)(v33 + *(_DWORD *)(a1 + 396))
                                + v43 * *(unsigned __int8 *)(v35 + *(_DWORD *)(a1 + 396))
                                + v42 * (unsigned int)*(unsigned __int8 *)(v34 + *(_DWORD *)(a1 + 396))
                                + 0x4000) >> 15)
                              + *(_DWORD *)(a1 + 392));
          }
          if ( v44 )
            *v36++ = *v37++;
        }
      }
      else
      {
        v30 = a3;
        v29 = a3;
        for ( j = 0; j < v41; ++j )
        {
          v28 = *v30;
          v31 = v30 + 1;
          v26 = *v31++;
          v27 = *v31;
          v30 = v31 + 1;
          if ( v28 == v26 && v28 == v27 )
          {
            *v29++ = v28;
          }
          else
          {
            v45 |= 1u;
            *v29++ = (v42 * v27 + v40 * v26 + v43 * (unsigned int)v28) >> 15;
          }
          if ( v44 )
            *v29++ = *v30++;
        }
      }
    }
    else if ( *(_DWORD *)(a1 + 404) && *(_DWORD *)(a1 + 400) )
    {
      v22 = (unsigned __int16 *)a3;
      v20 = a3;
      for ( k = 0; k < v41; ++k )
      {
        v18 = _byteswap_ushort(*v22);
        v23 = v22 + 1;
        v16 = _byteswap_ushort(*v23++);
        v17 = _byteswap_ushort(*v23);
        v22 = v23 + 1;
        if ( v18 == v16 && v18 == v17 )
        {
          if ( *(_DWORD *)(a1 + 388) )
            v19 = *(_WORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 388) + 4
                                                               * ((int)(unsigned __int8)v18 >> *(_DWORD *)(a1 + 372)))
                           + 2 * ((int)v18 >> 8));
          else
            v19 = v18;
        }
        else
        {
          v15 = (v40
               * *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(a1 + 404)
                                                 + 4 * ((int)(unsigned __int8)v16 >> *(_DWORD *)(a1 + 372)))
                                     + 2 * ((int)v16 >> 8))
               + v43
               * *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(a1 + 404)
                                                 + 4 * ((int)(unsigned __int8)v18 >> *(_DWORD *)(a1 + 372)))
                                     + 2 * ((int)v18 >> 8))
               + v42
               * (unsigned int)*(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(a1 + 404)
                                                               + 4
                                                               * ((int)(unsigned __int8)v17 >> *(_DWORD *)(a1 + 372)))
                                                   + 2 * ((int)v17 >> 8))
               + 0x4000) >> 15;
          v19 = *(_WORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 400) + 4 * ((int)(unsigned __int8)v15 >> *(_DWORD *)(a1 + 372)))
                         + 2 * ((int)v15 >> 8));
          v45 |= 1u;
        }
        *v20 = HIBYTE(v19);
        v20[1] = v19;
        v20 += 2;
        if ( v44 )
        {
          *v20 = *(_BYTE *)v22;
          v21 = v20 + 1;
          v24 = (char *)v22 + 1;
          *v21 = *v24;
          v20 = v21 + 1;
          v22 = (unsigned __int16 *)(v24 + 1);
        }
      }
    }
    else
    {
      v11 = (unsigned __int16 *)a3;
      v9 = a3;
      for ( m = 0; m < v41; ++m )
      {
        v8 = _byteswap_ushort(*v11);
        v12 = v11 + 1;
        v5 = _byteswap_ushort(*v12++);
        v7 = _byteswap_ushort(*v12);
        v11 = v12 + 1;
        if ( v8 != v5 || v8 != v7 )
          v45 |= 1u;
        v6 = (v40 * v5 + v43 * v8 + v42 * (unsigned int)v7 + 0x4000) >> 15;
        *v9 = HIBYTE(v6);
        v9[1] = v6;
        v9 += 2;
        if ( v44 )
        {
          *v9 = *(_BYTE *)v11;
          v10 = v9 + 1;
          v13 = (char *)v11 + 1;
          *v10 = *v13;
          v9 = v10 + 1;
          v11 = (unsigned __int16 *)(v13 + 1);
        }
      }
    }
    *((_BYTE *)a2 + 10) -= 2;
    *((_BYTE *)a2 + 8) &= ~2u;
    *((_BYTE *)a2 + 11) = *((_BYTE *)a2 + 9) * *((_BYTE *)a2 + 10);
    if ( *((unsigned __int8 *)a2 + 11) < 8u )
      v4 = (v41 * *((unsigned __int8 *)a2 + 11) + 7) >> 3;
    else
      v4 = v41 * (*((unsigned __int8 *)a2 + 11) >> 3);
    a2[1] = v4;
  }
  return v45;
}
