int __cdecl pcre_exec(int a1, int *a2, int a3, int a4, int a5, int a6, _DWORD *a7, int a8)
{
  int v9; // ecx
  int v10; // [esp+4h] [ebp-200h]
  BOOL v11; // [esp+8h] [ebp-1FCh]
  BOOL v12; // [esp+Ch] [ebp-1F8h]
  BOOL v13; // [esp+10h] [ebp-1F4h]
  BOOL v14; // [esp+18h] [ebp-1ECh]
  BOOL v15; // [esp+1Ch] [ebp-1E8h]
  BOOL v16; // [esp+20h] [ebp-1E4h]
  BOOL v17; // [esp+24h] [ebp-1E0h]
  BOOL v18; // [esp+28h] [ebp-1DCh]
  BOOL v19; // [esp+2Ch] [ebp-1D8h]
  BOOL v20; // [esp+30h] [ebp-1D4h]
  BOOL v21; // [esp+34h] [ebp-1D0h]
  BOOL v22; // [esp+38h] [ebp-1CCh]
  BOOL v23; // [esp+3Ch] [ebp-1C8h]
  BOOL v24; // [esp+40h] [ebp-1C4h]
  BOOL v25; // [esp+44h] [ebp-1C0h]
  char *v26; // [esp+48h] [ebp-1BCh]
  int v27; // [esp+4Ch] [ebp-1B8h]
  int v28; // [esp+50h] [ebp-1B4h]
  int v30; // [esp+58h] [ebp-1ACh]
  int v31; // [esp+5Ch] [ebp-1A8h]
  _DWORD *i; // [esp+60h] [ebp-1A4h]
  int v33; // [esp+68h] [ebp-19Ch]
  unsigned __int8 *v34; // [esp+6Ch] [ebp-198h]
  unsigned __int8 *v35; // [esp+74h] [ebp-190h]
  unsigned __int8 *v36; // [esp+78h] [ebp-18Ch]
  unsigned __int8 *v37; // [esp+7Ch] [ebp-188h]
  _DWORD *v38; // [esp+80h] [ebp-184h]
  unsigned int v39; // [esp+84h] [ebp-180h]
  int v40; // [esp+88h] [ebp-17Ch]
  int v41; // [esp+8Ch] [ebp-178h] BYREF
  int valid; // [esp+90h] [ebp-174h]
  BOOL v43; // [esp+94h] [ebp-170h]
  int v44; // [esp+98h] [ebp-16Ch]
  BOOL v45; // [esp+9Ch] [ebp-168h]
  int v46; // [esp+A0h] [ebp-164h]
  unsigned __int8 *v47; // [esp+A4h] [ebp-160h]
  unsigned int v48; // [esp+A8h] [ebp-15Ch]
  int v49; // [esp+ACh] [ebp-158h]
  BOOL v50; // [esp+B0h] [ebp-154h]
  int v51; // [esp+B4h] [ebp-150h]
  BOOL v52; // [esp+B8h] [ebp-14Ch]
  char *v53; // [esp+BCh] [ebp-148h]
  _BYTE *v54; // [esp+C0h] [ebp-144h]
  char v55[40]; // [esp+C4h] [ebp-140h] BYREF
  char *v56; // [esp+ECh] [ebp-118h]
  _BYTE *v57; // [esp+F0h] [ebp-114h]
  int v58; // [esp+F4h] [ebp-110h]
  int v59; // [esp+F8h] [ebp-10Ch]
  int v60; // [esp+FCh] [ebp-108h]
  int v61; // [esp+100h] [ebp-104h]
  char v62; // [esp+104h] [ebp-100h] BYREF
  unsigned __int8 *v63; // [esp+1BCh] [ebp-48h]
  int v64; // [esp+1C0h] [ebp-44h]
  _BYTE v65[44]; // [esp+1C4h] [ebp-40h] BYREF
  int v66; // [esp+1F4h] [ebp-10h]
  int v67; // [esp+1F8h] [ebp-Ch]
  BOOL v68; // [esp+1FCh] [ebp-8h]
  int v69; // [esp+200h] [ebp-4h]

  v49 = -1;
  v58 = -1;
  v66 = -1;
  v44 = 0;
  v52 = 0;
  v50 = 0;
  v56 = &v62;
  v57 = 0;
  v47 = (unsigned __int8 *)(a5 + a3);
  v64 = 0;
  v48 = a5 + a3 - 1;
  v61 = a1;
  v51 = a1;
  if ( (a6 & 0xE20F5A6F) != 0 )
    return -3;
  if ( !v51 || !a3 || !a7 && a8 > 0 )
    return -2;
  if ( a8 < 0 )
    return -15;
  if ( a5 < 0 || a5 > a4 )
    return -24;
  *((_DWORD *)v56 + 17) = (*(_DWORD *)(v51 + 8) & 0x800) != 0;
  v46 = *((_DWORD *)v56 + 17);
  if ( (a6 & 0x8000000) != 0 )
    v30 = 2;
  else
    v30 = (a6 & 0x8000) != 0;
  *((_DWORD *)v56 + 33) = v30;
  if ( v46 && (a6 & 0x2000) == 0 )
  {
    valid = _pcre_valid_utf8(a3, a4, &v41);
    if ( valid )
    {
      if ( a8 >= 2 )
      {
        *a7 = v41;
        a7[1] = valid;
      }
      if ( valid > 5 || *((int *)v56 + 33) <= 1 )
        return -10;
      else
        return -25;
    }
    if ( a5 > 0 && a5 < a4 && (*(_BYTE *)(a5 + a3) & 0xC0) == 0x80 )
      return -11;
  }
  *((_DWORD *)v56 + 10) = v51 + *(unsigned __int16 *)(v51 + 24);
  *((_DWORD *)v56 + 8) = *(unsigned __int16 *)(v51 + 28);
  *((_DWORD *)v56 + 9) = *(unsigned __int16 *)(v51 + 26);
  v54 = 0;
  *((_DWORD *)v56 + 1) = 10000000;
  *((_DWORD *)v56 + 2) = 10000000;
  *((_DWORD *)v56 + 41) = 0;
  v53 = *(char **)(v61 + 32);
  if ( a2 )
  {
    v40 = *a2;
    if ( (*a2 & 1) != 0 )
      v54 = (_BYTE *)a2[1];
    if ( (v40 & 2) != 0 )
      *((_DWORD *)v56 + 1) = a2[2];
    if ( (v40 & 0x10) != 0 )
      *((_DWORD *)v56 + 2) = a2[5];
    if ( (v40 & 4) != 0 )
      *((_DWORD *)v56 + 41) = a2[3];
    if ( (v40 & 8) != 0 )
      v53 = (char *)a2[4];
  }
  if ( !v53 )
    v53 = (char *)&_pcre_default_tables;
  if ( *(_DWORD *)v51 != 1346589253 )
  {
    v51 = _pcre_try_flipped(v51, v55, v54, v65);
    if ( !v51 )
      return -4;
    if ( v54 )
      v54 = v65;
  }
  v43 = (((unsigned __int8)a6 | (unsigned __int8)*(_DWORD *)(v51 + 8)) & 0x10) != 0;
  v68 = (*(_WORD *)(v51 + 12) & 8) != 0;
  v45 = (*(_DWORD *)(v51 + 8) & 0x40000) != 0;
  *((_DWORD *)v56 + 27) = *(unsigned __int16 *)(v51 + 26) * *(unsigned __int16 *)(v51 + 28)
                        + v61
                        + *(unsigned __int16 *)(v51 + 24);
  *((_DWORD *)v56 + 28) = a3;
  *((_DWORD *)v56 + 36) = a5;
  *((_DWORD *)v56 + 29) = a4 + *((_DWORD *)v56 + 28);
  v63 = (unsigned __int8 *)*((_DWORD *)v56 + 29);
  *((_DWORD *)v56 + 20) = (*(_DWORD *)(v51 + 8) & 0x20) != 0;
  *((_DWORD *)v56 + 19) = (*(_DWORD *)(v51 + 8) & 0x20000000) != 0;
  *((_DWORD *)v56 + 18) = (*(_DWORD *)(v51 + 8) & 0x2000000) != 0;
  *((_DWORD *)v56 + 26) = 0;
  *((_DWORD *)v56 + 15) = (a6 & 0x80) != 0;
  *((_DWORD *)v56 + 16) = (a6 & 0x100) != 0;
  *((_DWORD *)v56 + 21) = (a6 & 0x400) != 0;
  *((_DWORD *)v56 + 22) = (a6 & 0x10000000) != 0;
  *((_DWORD *)v56 + 23) = 0;
  *((_DWORD *)v56 + 43) = 0;
  *((_DWORD *)v56 + 42) = 0;
  *((_DWORD *)v56 + 40) = 0;
  *((_DWORD *)v56 + 25) = (*(_WORD *)(v51 + 12) & 0x40) != 0;
  *((_DWORD *)v56 + 12) = v53;
  *((_DWORD *)v56 + 13) = v53 + 832;
  v28 = a6 & 0x1800000;
  if ( (a6 & 0x1800000) != 0 )
  {
    if ( v28 == 0x800000 )
    {
      *((_DWORD *)v56 + 24) = 1;
    }
    else
    {
      if ( v28 != 0x1000000 )
        return -23;
      *((_DWORD *)v56 + 24) = 0;
    }
  }
  else
  {
    *((_DWORD *)v56 + 24) = (*(_DWORD *)(v51 + 8) & 0x1800000) == 0 || (*(_DWORD *)(v51 + 8) & 0x800000) != 0;
  }
  if ( (a6 & 0x700000) != 0 )
    v27 = a6;
  else
    v27 = *(_DWORD *)(v51 + 8);
  v26 = (char *)(v27 & 0x700000);
  if ( (v27 & 0x700000u) > (unsigned int)&loc_300000 )
  {
    if ( v26 == (char *)&loc_400000 )
    {
      v67 = -1;
    }
    else
    {
      if ( v26 != (_BYTE *)&loc_4FFFFE + 2 )
        return -23;
      v67 = -2;
    }
  }
  else if ( v26 == (char *)&loc_300000 )
  {
    v67 = 3338;
  }
  else if ( v26 )
  {
    if ( v26 == (char *)&loc_100000 )
    {
      v67 = 13;
    }
    else
    {
      if ( v26 != (char *)&loc_200000 )
        return -23;
      v67 = 10;
    }
  }
  else
  {
    v67 = -2;
  }
  if ( v67 == -2 )
  {
    *((_DWORD *)v56 + 6) = 2;
  }
  else if ( v67 >= 0 )
  {
    *((_DWORD *)v56 + 6) = 0;
    if ( v67 <= 255 )
    {
      *((_DWORD *)v56 + 7) = 1;
      v56[44] = v67;
    }
    else
    {
      *((_DWORD *)v56 + 7) = 2;
      v56[44] = BYTE1(v67);
      v56[45] = v67;
    }
  }
  else
  {
    *((_DWORD *)v56 + 6) = 1;
  }
  if ( *((_DWORD *)v56 + 33) && (*(_WORD *)(v51 + 12) & 1) != 0 )
    return -13;
  v59 = a8 - a8 % 3;
  v60 = 2 * v59 / 3;
  if ( *(_WORD *)(v51 + 18) && *(unsigned __int16 *)(v51 + 18) >= v59 / 3 )
  {
    v59 = 3 * *(unsigned __int16 *)(v51 + 18) + 3;
    *((_DWORD *)v56 + 3) = pcre_malloc(4 * v59);
    if ( !*((_DWORD *)v56 + 3) )
      return -6;
    v44 = 1;
  }
  else
  {
    *((_DWORD *)v56 + 3) = a7;
  }
  *((_DWORD *)v56 + 4) = v59;
  *((_DWORD *)v56 + 5) = 2 * v59 / 3;
  *((_DWORD *)v56 + 14) = 0;
  *((_DWORD *)v56 + 35) = -1;
  if ( *((_DWORD *)v56 + 3) )
  {
    v38 = (_DWORD *)(*((_DWORD *)v56 + 3) + 4 * v59);
    v39 = (unsigned int)&v38[-*(unsigned __int16 *)(v51 + 16)];
    if ( v39 < *((_DWORD *)v56 + 3) + 8 )
      v39 = *((_DWORD *)v56 + 3) + 8;
    while ( (unsigned int)--v38 >= v39 )
      *v38 = -1;
    *(_DWORD *)(*((_DWORD *)v56 + 3) + 4) = -1;
    **((_DWORD **)v56 + 3) = -1;
  }
  if ( !v43 )
  {
    if ( (*(_WORD *)(v51 + 12) & 2) != 0 )
    {
      v49 = (unsigned __int8)*(_WORD *)(v51 + 20);
      v52 = (*(_WORD *)(v51 + 20) & 0x100) != 0;
      if ( v52 )
        v49 = *(unsigned __int8 *)(*((_DWORD *)v56 + 12) + v49);
    }
    else if ( !v68 && v54 && (*((_DWORD *)v54 + 1) & 1) != 0 )
    {
      v57 = v54 + 8;
    }
  }
  if ( (*(_WORD *)(v51 + 12) & 4) != 0 )
  {
    v58 = (unsigned __int8)*(_WORD *)(v51 + 22);
    v50 = (*(_WORD *)(v51 + 22) & 0x100) != 0;
    v66 = (unsigned __int8)v53[v58 + 256];
  }
  while ( 1 )
  {
    v36 = v63;
    if ( v45 )
    {
      v35 = v47;
      if ( v46 )
      {
        while ( (unsigned int)v35 < *((_DWORD *)v56 + 29) )
        {
          if ( *((_DWORD *)v56 + 6) )
          {
            v25 = (unsigned int)v35 < *((_DWORD *)v56 + 29)
               && _pcre_is_newline(v35, *((_DWORD *)v56 + 6), *((_DWORD *)v56 + 29), v56 + 28, v46);
            v24 = v25;
          }
          else
          {
            v23 = (unsigned int)v35 <= *((_DWORD *)v56 + 29) - *((_DWORD *)v56 + 7)
               && *v35 == (unsigned __int8)v56[44]
               && (*((_DWORD *)v56 + 7) == 1 || v35[1] == (unsigned __int8)v56[45]);
            v24 = v23;
          }
          if ( v24 )
            break;
          ++v35;
          while ( v35 < v63 && (*v35 & 0xC0) == 0x80 )
            ++v35;
        }
      }
      else
      {
        while ( (unsigned int)v35 < *((_DWORD *)v56 + 29) )
        {
          if ( *((_DWORD *)v56 + 6) )
          {
            v22 = (unsigned int)v35 < *((_DWORD *)v56 + 29)
               && _pcre_is_newline(v35, *((_DWORD *)v56 + 6), *((_DWORD *)v56 + 29), v56 + 28, v46);
            v21 = v22;
          }
          else
          {
            v20 = (unsigned int)v35 <= *((_DWORD *)v56 + 29) - *((_DWORD *)v56 + 7)
               && *v35 == (unsigned __int8)v56[44]
               && (*((_DWORD *)v56 + 7) == 1 || v35[1] == (unsigned __int8)v56[45]);
            v21 = v20;
          }
          if ( v21 )
            break;
          ++v35;
        }
      }
      v63 = v35;
    }
    if ( ((*(_DWORD *)(v51 + 8) | a6) & 0x4000000) == 0 )
    {
      if ( v49 < 0 )
      {
        if ( v68 )
        {
          if ( (unsigned int)v47 > a5 + *((_DWORD *)v56 + 28) )
          {
            if ( v46 )
            {
              while ( v47 < v63 )
              {
                if ( *((_DWORD *)v56 + 6) )
                {
                  v19 = (unsigned int)v47 > *((_DWORD *)v56 + 28)
                     && _pcre_was_newline(v47, *((_DWORD *)v56 + 6), *((_DWORD *)v56 + 28), v56 + 28, v46);
                  v18 = v19;
                }
                else
                {
                  v17 = (unsigned int)v47 >= *((_DWORD *)v56 + 7) + *((_DWORD *)v56 + 28)
                     && v47[-*((_DWORD *)v56 + 7)] == (unsigned __int8)v56[44]
                     && (*((_DWORD *)v56 + 7) == 1 || v47[-*((_DWORD *)v56 + 7) + 1] == (unsigned __int8)v56[45]);
                  v18 = v17;
                }
                if ( v18 )
                  break;
                ++v47;
                while ( v47 < v63 && (*v47 & 0xC0) == 0x80 )
                  ++v47;
              }
            }
            else
            {
              while ( v47 < v63 )
              {
                if ( *((_DWORD *)v56 + 6) )
                {
                  v16 = (unsigned int)v47 > *((_DWORD *)v56 + 28)
                     && _pcre_was_newline(v47, *((_DWORD *)v56 + 6), *((_DWORD *)v56 + 28), v56 + 28, v46);
                  v15 = v16;
                }
                else
                {
                  v14 = (unsigned int)v47 >= *((_DWORD *)v56 + 7) + *((_DWORD *)v56 + 28)
                     && v47[-*((_DWORD *)v56 + 7)] == (unsigned __int8)v56[44]
                     && (*((_DWORD *)v56 + 7) == 1 || v47[-*((_DWORD *)v56 + 7) + 1] == (unsigned __int8)v56[45]);
                  v15 = v14;
                }
                if ( v15 )
                  break;
                ++v47;
              }
            }
            if ( *(v47 - 1) == 13 && (*((_DWORD *)v56 + 6) == 1 || *((_DWORD *)v56 + 6) == 2) && v47 < v63 && *v47 == 10 )
              ++v47;
          }
        }
        else if ( v57 )
        {
          while ( v47 < v63 && ((1 << (*v47 & 7)) & (unsigned __int8)v57[*v47 >> 3]) == 0 )
          {
            ++v47;
            if ( v46 )
            {
              while ( v47 < v63 && (*v47 & 0xC0) == 0x80 )
                ++v47;
            }
          }
        }
      }
      else if ( v52 )
      {
        while ( v47 < v63 && *(unsigned __int8 *)(*((_DWORD *)v56 + 12) + *v47) != v49 )
          ++v47;
      }
      else
      {
        while ( v47 < v63 && *v47 != v49 )
          ++v47;
      }
    }
    v63 = v36;
    if ( ((*(_DWORD *)(v51 + 8) | a6) & 0x4000000) == 0 && !*((_DWORD *)v56 + 33) )
    {
      if ( v54 && (*((_DWORD *)v54 + 1) & 2) != 0 && (unsigned int)(v63 - v47) < *((_DWORD *)v54 + 10) )
      {
        v69 = 0;
        goto LABEL_286;
      }
      if ( v58 >= 0 && v63 - v47 < 1000 )
      {
        v34 = &v47[v49 >= 0];
        if ( (unsigned int)v34 > v48 )
        {
          if ( v50 )
          {
            while ( v34 < v63 )
            {
              v33 = *v34++;
              if ( v33 == v58 || v33 == v66 )
              {
                --v34;
                break;
              }
            }
          }
          else
          {
            while ( v34 < v63 )
            {
              v9 = *v34++;
              if ( v9 == v58 )
              {
                --v34;
                break;
              }
            }
          }
          if ( v34 >= v63 )
          {
            v69 = 0;
            goto LABEL_286;
          }
          v48 = (unsigned int)v34;
        }
      }
    }
    *((_DWORD *)v56 + 30) = v47;
    *((_DWORD *)v56 + 32) = v47;
    *(_DWORD *)v56 = 0;
    *((_DWORD *)v56 + 37) = 0;
    *((_DWORD *)v56 + 34) = 0;
    v69 = sub_62FB60(v47, *((_DWORD *)v56 + 27), v47, 2, v56, 0, 0);
    if ( *((_DWORD *)v56 + 23) && !v64 )
      v64 = *((_DWORD *)v56 + 32);
    if ( v69 <= -995 )
      break;
    if ( v69 > -992 )
    {
      if ( v69 )
        goto LABEL_286;
    }
    else if ( v69 != -992 )
    {
      if ( v69 != -994 )
      {
        v37 = v47;
        *((_DWORD *)v56 + 26) = 1;
        goto LABEL_259;
      }
      if ( *((unsigned __int8 **)v56 + 30) != v47 )
      {
        v37 = (unsigned __int8 *)*((_DWORD *)v56 + 30);
        goto LABEL_259;
      }
    }
LABEL_253:
    *((_DWORD *)v56 + 26) = 0;
    v37 = v47 + 1;
    if ( v46 )
    {
      while ( v37 < v63 && (*v37 & 0xC0) == 0x80 )
        ++v37;
    }
LABEL_259:
    v69 = 0;
    if ( v45 )
    {
      if ( *((_DWORD *)v56 + 6) )
      {
        v13 = (unsigned int)v47 < *((_DWORD *)v56 + 29)
           && _pcre_is_newline(v47, *((_DWORD *)v56 + 6), *((_DWORD *)v56 + 29), v56 + 28, v46);
        v12 = v13;
      }
      else
      {
        v11 = (unsigned int)v47 <= *((_DWORD *)v56 + 29) - *((_DWORD *)v56 + 7)
           && *v47 == (unsigned __int8)v56[44]
           && (*((_DWORD *)v56 + 7) == 1 || v47[1] == (unsigned __int8)v56[45]);
        v12 = v11;
      }
      if ( v12 )
        goto LABEL_286;
    }
    v47 = v37;
    if ( v43 || v47 > v63 )
      goto LABEL_286;
    if ( *(v47 - 1) == 13
      && v47 < v63
      && *v47 == 10
      && (*(_WORD *)(v51 + 12) & 0x20) == 0
      && (*((_DWORD *)v56 + 6) == 1 || *((_DWORD *)v56 + 6) == 2 || *((_DWORD *)v56 + 7) == 2) )
    {
      ++v47;
    }
    *((_DWORD *)v56 + 42) = 0;
  }
  if ( v69 == -995 )
    goto LABEL_253;
  if ( v69 == -998 )
    v69 = 0;
LABEL_286:
  if ( v69 == 1 || v69 == -999 )
  {
    if ( v44 )
    {
      if ( v60 >= 4 )
        memcpy((int)(a7 + 2), (const __m128i *)(*((_DWORD *)v56 + 3) + 8), 4 * v60 - 8);
      if ( *((_DWORD *)v56 + 34) > v60 )
        *((_DWORD *)v56 + 14) = 1;
      pcre_free(*((void **)v56 + 3));
    }
    if ( *((_DWORD *)v56 + 14) && *((_DWORD *)v56 + 34) >= v60 )
      v10 = 0;
    else
      v10 = *((_DWORD *)v56 + 34) / 2;
    v69 = v10;
    if ( *((_DWORD *)v56 + 34) / 2 <= *(unsigned __int16 *)(v51 + 16) && a7 )
    {
      v31 = 2 * *(unsigned __int16 *)(v51 + 16) + 2;
      if ( v31 > a8 )
        v31 = v59;
      for ( i = &a7[*((_DWORD *)v56 + 34)]; i < &a7[v31]; ++i )
        *i = -1;
    }
    if ( a8 >= 2 )
    {
      *a7 = *((_DWORD *)v56 + 30) - *((_DWORD *)v56 + 28);
      a7[1] = *((_DWORD *)v56 + 31) - *((_DWORD *)v56 + 28);
    }
    else
    {
      v69 = 0;
    }
    if ( a2 && (*a2 & 0x20) != 0 )
      *(_DWORD *)a2[6] = *((_DWORD *)v56 + 42);
    return v69;
  }
  else
  {
    if ( v44 )
      pcre_free(*((void **)v56 + 3));
    if ( !v69 || v69 == -12 )
    {
      if ( v64 )
      {
        *((_DWORD *)v56 + 42) = 0;
        if ( a8 > 1 )
        {
          *a7 = v64 - a3;
          a7[1] = &v63[-a3];
        }
        v69 = -12;
      }
      else
      {
        v69 = -1;
      }
      if ( a2 && (*a2 & 0x20) != 0 )
        *(_DWORD *)a2[6] = *((_DWORD *)v56 + 43);
      return v69;
    }
    else
    {
      return v69;
    }
  }
}
