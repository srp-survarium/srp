int __cdecl _I10_OUTPUT(_LDOUBLE ld, int ndigits, char output_flags, _FloatOutStruct *fos)
{
  __int16 v4; // cx
  unsigned __int16 v5; // dx
  __int64 v6; // rdi
  int v8; // eax
  int v9; // eax
  __int16 v10; // ax
  int v11; // ebx
  int v12; // ecx
  _LDBL12 *v13; // eax
  unsigned __int8 *v14; // esi
  __int16 v15; // dx
  unsigned __int16 v16; // dx
  unsigned __int16 v17; // di
  _WORD *v18; // esi
  unsigned int v19; // edx
  unsigned int v20; // ecx
  unsigned int v21; // eax
  __int16 v22; // di
  unsigned int v23; // ecx
  unsigned int v24; // edx
  int v25; // eax
  unsigned int v26; // ecx
  int v27; // esi
  int v28; // ecx
  unsigned __int16 v29; // si
  int v30; // eax
  _WORD *v31; // edi
  unsigned __int16 *v32; // eax
  unsigned int v33; // ecx
  unsigned int v34; // edx
  unsigned int v35; // ebx
  __int16 v36; // si
  unsigned int v37; // ecx
  unsigned int v38; // edx
  int v39; // eax
  unsigned int v40; // ecx
  int v41; // edi
  int v42; // ecx
  int v43; // edi
  int v44; // esi
  unsigned int v45; // eax
  int v46; // ebx
  int v47; // eax
  bool v48; // zf
  int v49; // esi
  int v50; // eax
  int v51; // ebx
  int v52; // eax
  char *man; // ebx
  unsigned int v54; // edx
  unsigned int v55; // edi
  unsigned int v56; // ecx
  int v57; // esi
  int v58; // ecx
  unsigned int v59; // esi
  unsigned int v60; // edi
  int v61; // edx
  unsigned int v62; // edx
  char *v63; // ebx
  char v64; // al
  char *v65; // ebx
  _FloatOutStruct *v66; // eax
  char v67; // bl
  __int16 v68; // [esp+10h] [ebp-70h]
  unsigned __int16 *v69; // [esp+14h] [ebp-6Ch]
  unsigned __int8 *v70; // [esp+18h] [ebp-68h]
  _LDBL12 *v71; // [esp+1Ch] [ebp-64h]
  int v72; // [esp+24h] [ebp-5Ch]
  __int16 v73; // [esp+24h] [ebp-5Ch]
  int v74; // [esp+28h] [ebp-58h]
  int v75; // [esp+28h] [ebp-58h]
  int v76; // [esp+2Ch] [ebp-54h]
  int v77; // [esp+2Ch] [ebp-54h]
  int v78; // [esp+30h] [ebp-50h]
  int v79; // [esp+30h] [ebp-50h]
  __int16 v80; // [esp+34h] [ebp-4Ch]
  int k; // [esp+34h] [ebp-4Ch]
  __int16 v82; // [esp+38h] [ebp-48h]
  int *v83; // [esp+38h] [ebp-48h]
  _LDBL12 *v84; // [esp+3Ch] [ebp-44h]
  int v85; // [esp+3Ch] [ebp-44h]
  int v86; // [esp+3Ch] [ebp-44h]
  unsigned int v87; // [esp+3Ch] [ebp-44h]
  int i; // [esp+40h] [ebp-40h]
  int j; // [esp+40h] [ebp-40h]
  char *v90; // [esp+40h] [ebp-40h]
  __int64 v91; // [esp+44h] [ebp-3Ch] BYREF
  int v92; // [esp+4Ch] [ebp-34h]
  int v93; // [esp+50h] [ebp-30h]
  int v94; // [esp+54h] [ebp-2Ch]
  int v95; // [esp+58h] [ebp-28h] BYREF
  _BYTE v96[12]; // [esp+60h] [ebp-20h] BYREF
  _BYTE v97[12]; // [esp+70h] [ebp-10h] BYREF

  *(_LDOUBLE *)v97 = ld;
  v4 = *(_WORD *)&ld.ld[8] & 0x8000;
  v5 = *(_WORD *)&ld.ld[8] & 0x7FFF;
  v93 = -858993460;
  v94 = -858993460;
  v95 = 1073466572;
  v68 = *(_WORD *)&ld.ld[8] & 0x8000;
  if ( *(__int16 *)&ld.ld[8] >= 0 )
    fos->sign = 32;
  else
    fos->sign = 45;
  v6 = *(_QWORD *)v97;
  if ( !v5 && !*(_QWORD *)v97 )
  {
    fos->exp = 0;
    fos->sign = v4 != -32768 ? 32 : 45;
    fos->ManLen = 1;
    fos->man[0] = 48;
    fos->man[1] = 0;
    return 1;
  }
  if ( v5 == 0x7FFF )
  {
    fos->exp = 1;
    if ( v6 != 0x8000000000000000uLL && (v6 & 0x4000000000000000LL) == 0 )
    {
      v8 = strcpy_s(v6, fos->man, 22, "1#SNAN");
LABEL_22:
      if ( v8 )
        _invoke_watson((int)fos, v6, 0);
      fos->ManLen = 6;
      return 0;
    }
    if ( v4 && HIDWORD(v6) == -1073741824 )
    {
      if ( !(_DWORD)v6 )
      {
        v9 = strcpy_s(0, fos->man, 22, "1#IND");
LABEL_18:
        if ( v9 )
          _invoke_watson((int)fos, 0, 0);
        fos->ManLen = 5;
        return 0;
      }
    }
    else if ( v6 == 0x8000000000000000uLL )
    {
      v9 = strcpy_s(0, fos->man, 22, "1#INF");
      goto LABEL_18;
    }
    v8 = strcpy_s(v6, fos->man, 22, "1#QNAN");
    goto LABEL_22;
  }
  v10 = (77 * (HIBYTE(v5) + 2 * HIBYTE(*(_DWORD *)&v97[4])) + 19728 * (unsigned int)v5 - 323162868) >> 16;
  *(_WORD *)v96 = 0;
  v11 = -v10;
  v80 = v10;
  *(_WORD *)&v96[10] = *(_WORD *)&ld.ld[8] & 0x7FFF;
  *(_QWORD *)&v96[2] = *(_QWORD *)v97;
  v71 = &_pow10pos[-8];
  if ( v10 )
  {
    if ( v10 > 0 )
    {
      v11 = v10;
      v71 = &_pow10neg[-8];
    }
    while ( v11 )
    {
      v71 += 7;
      v12 = v11 & 7;
      v11 >>= 3;
      if ( v12 )
      {
        v13 = &v71[v12];
        v84 = v13;
        if ( *(_WORD *)v13->ld12 >= 0x8000u )
        {
          v91 = *(_QWORD *)v13->ld12;
          v14 = &v13->ld12[8];
          v13 = (_LDBL12 *)&v91;
          v92 = *(_DWORD *)v14;
          --*(_DWORD *)((char *)&v91 + 2);
          v84 = (_LDBL12 *)&v91;
        }
        v15 = *(_WORD *)&v13->ld12[10];
        v76 = 0;
        memset(v97, 0, sizeof(v97));
        v82 = (*(_WORD *)&v96[10] ^ v15) & 0x8000;
        v16 = v15 & 0x7FFF;
        v17 = v16 + (*(_WORD *)&v96[10] & 0x7FFF);
        if ( (*(_WORD *)&v96[10] & 0x7FFF) == 0x7FFF || v16 >= 0x7FFFu || v17 > 0xBFFDu )
        {
          *(_DWORD *)&v96[8] = v82 == 0 ? 2147450880 : -32768;
        }
        else
        {
          if ( v17 > 0x3FBFu )
          {
            if ( (*(_WORD *)&v96[10] & 0x7FFF) == 0 )
            {
              ++v17;
              if ( (*(_DWORD *)&v96[8] & 0x7FFFFFFF) == 0 && !*(_DWORD *)&v96[4] && !*(_DWORD *)v96 )
              {
                *(_WORD *)&v96[10] = 0;
                continue;
              }
            }
            if ( v16
              || (++v17, (*(_DWORD *)&v13->ld12[8] & 0x7FFFFFFF) != 0)
              || *(_DWORD *)&v13->ld12[4]
              || *(_DWORD *)v13->ld12 )
            {
              v74 = 0;
              v18 = &v97[4];
              for ( i = 5; i > 0; --i )
              {
                v78 = i;
                v69 = (unsigned __int16 *)&v96[2 * v74];
                v70 = &v13->ld12[8];
                do
                {
                  v19 = *((_DWORD *)v18 - 1);
                  v20 = *(unsigned __int16 *)v70 * *v69;
                  v72 = 0;
                  v21 = v19 + v20;
                  if ( v19 + v20 < v19 || v21 < v20 )
                    v72 = 1;
                  *((_DWORD *)v18 - 1) = v21;
                  if ( v72 )
                    ++*v18;
                  ++v69;
                  v70 -= 2;
                  --v78;
                }
                while ( v78 > 0 );
                v13 = v84;
                ++v18;
                ++v74;
              }
              v22 = v17 - 16382;
              if ( v22 <= 0 )
                goto LABEL_170;
              do
              {
                if ( *(int *)&v97[8] < 0 )
                  break;
                v23 = *(_DWORD *)v97;
                *(_DWORD *)v97 *= 2;
                v24 = *(_DWORD *)&v97[4];
                *(_DWORD *)&v97[4] = (v23 >> 31) | (2 * *(_DWORD *)&v97[4]);
                --v22;
                *(_DWORD *)&v97[8] = (v24 >> 31) | (2 * *(_DWORD *)&v97[8]);
              }
              while ( v22 > 0 );
              if ( v22 <= 0 )
              {
LABEL_170:
                if ( --v22 < 0 )
                {
                  v25 = (unsigned __int16)-v22;
                  v22 = 0;
                  do
                  {
                    if ( (v97[0] & 1) != 0 )
                      ++v76;
                    v26 = *(_DWORD *)&v97[8];
                    *(_DWORD *)&v97[8] >>= 1;
                    v27 = __SPAIR64__(v26, *(unsigned int *)&v97[4]) >> 1;
                    v28 = *(__int64 *)v97 >> 1;
                    --v25;
                    *(_DWORD *)&v97[4] = v27;
                    *(_DWORD *)v97 = v28;
                  }
                  while ( v25 );
                  if ( v76 )
                    *(_WORD *)v97 |= 1u;
                }
              }
              if ( *(_WORD *)v97 > 0x8000u || ((unsigned int)&loc_1FFFF & *(_DWORD *)v97) == 0x18000 )
              {
                if ( *(_DWORD *)&v97[2] == -1 )
                {
                  *(_DWORD *)&v97[2] = 0;
                  if ( *(_DWORD *)&v97[6] == -1 )
                  {
                    *(_DWORD *)&v97[6] = 0;
                    if ( *(_WORD *)&v97[10] == 0xFFFF )
                    {
                      *(_WORD *)&v97[10] = 0x8000;
                      ++v22;
                    }
                    else
                    {
                      ++*(_WORD *)&v97[10];
                    }
                  }
                  else
                  {
                    ++*(_DWORD *)&v97[6];
                  }
                }
                else
                {
                  ++*(_DWORD *)&v97[2];
                }
              }
              if ( (unsigned __int16)v22 < 0x7FFFu )
              {
                *(_WORD *)v96 = *(_WORD *)&v97[2];
                *(_DWORD *)&v96[2] = *(_DWORD *)&v97[4];
                *(_DWORD *)&v96[6] = *(_DWORD *)&v97[8];
                *(_WORD *)&v96[10] = v82 | v22;
              }
              else
              {
                *(_DWORD *)&v96[4] = 0;
                *(_DWORD *)v96 = 0;
                *(_DWORD *)&v96[8] = v82 == 0 ? 2147450880 : -32768;
              }
              continue;
            }
          }
          *(_DWORD *)&v96[8] = 0;
        }
        *(_DWORD *)&v96[4] = 0;
        *(_DWORD *)v96 = 0;
      }
    }
  }
  if ( *(_WORD *)&v96[10] >= 0x3FFFu )
  {
    ++v80;
    v79 = 0;
    memset(v97, 0, sizeof(v97));
    v73 = (*(_WORD *)&v96[10] ^ HIWORD(v95)) & 0x8000;
    v29 = (HIWORD(v95) & 0x7FFF) + (*(_WORD *)&v96[10] & 0x7FFF);
    if ( (*(_WORD *)&v96[10] & 0x7FFF) == 0x7FFF || (HIWORD(v95) & 0x7FFF) == 0x7FFF || v29 > 0xBFFDu )
    {
      *(_DWORD *)&v96[4] = 0;
      v30 = ((*(_WORD *)&v96[10] ^ HIWORD(v95)) & 0x8000u) == 0 ? 2147450880 : -32768;
      *(_DWORD *)v96 = 0;
    }
    else
    {
      if ( v29 > 0x3FBFu )
      {
        v30 = 0;
        if ( (*(_WORD *)&v96[10] & 0x7FFF) == 0 )
        {
          ++v29;
          if ( (*(_DWORD *)&v96[8] & 0x7FFFFFFF) == 0 && !*(_DWORD *)&v96[4] && !*(_DWORD *)v96 )
          {
            *(_WORD *)&v96[10] = 0;
            goto LABEL_132;
          }
        }
        if ( (v95 & 0x7FFF0000) != 0 || (++v29, (v95 & 0x7FFFFFFF) != 0) || v94 || v93 )
        {
          v75 = 0;
          v31 = &v97[4];
          for ( j = 5; j > 0; --j )
          {
            v77 = j;
            v83 = &v95;
            v32 = (unsigned __int16 *)&v96[2 * v75];
            do
            {
              v85 = 0;
              v33 = *v32 * *(unsigned __int16 *)v83;
              v34 = *((_DWORD *)v31 - 1);
              v35 = v34 + v33;
              if ( v34 + v33 < v34 || v35 < v33 )
                v85 = 1;
              *((_DWORD *)v31 - 1) = v35;
              if ( v85 )
                ++*v31;
              v83 = (int *)((char *)v83 - 2);
              ++v32;
              --v77;
            }
            while ( v77 > 0 );
            ++v31;
            ++v75;
          }
          v36 = v29 - 16382;
          if ( v36 <= 0 )
            goto LABEL_171;
          do
          {
            if ( *(int *)&v97[8] < 0 )
              break;
            v37 = *(_DWORD *)v97;
            *(_DWORD *)v97 *= 2;
            v38 = *(_DWORD *)&v97[4];
            *(_DWORD *)&v97[4] = (v37 >> 31) | (2 * *(_DWORD *)&v97[4]);
            --v36;
            *(_DWORD *)&v97[8] = (v38 >> 31) | (2 * *(_DWORD *)&v97[8]);
          }
          while ( v36 > 0 );
          if ( v36 <= 0 )
          {
LABEL_171:
            if ( --v36 < 0 )
            {
              v39 = (unsigned __int16)-v36;
              v36 = 0;
              do
              {
                if ( (v97[0] & 1) != 0 )
                  ++v79;
                v40 = *(_DWORD *)&v97[8];
                *(_DWORD *)&v97[8] >>= 1;
                v41 = __SPAIR64__(v40, *(unsigned int *)&v97[4]) >> 1;
                v42 = *(__int64 *)v97 >> 1;
                --v39;
                *(_DWORD *)&v97[4] = v41;
                *(_DWORD *)v97 = v42;
              }
              while ( v39 );
              if ( v79 )
                *(_WORD *)v97 |= 1u;
            }
          }
          if ( *(_WORD *)v97 > 0x8000u || ((unsigned int)&loc_1FFFF & *(_DWORD *)v97) == 0x18000 )
          {
            if ( *(_DWORD *)&v97[2] == -1 )
            {
              *(_DWORD *)&v97[2] = 0;
              if ( *(_DWORD *)&v97[6] == -1 )
              {
                *(_DWORD *)&v97[6] = 0;
                if ( *(_WORD *)&v97[10] == 0xFFFF )
                {
                  *(_WORD *)&v97[10] = 0x8000;
                  ++v36;
                }
                else
                {
                  ++*(_WORD *)&v97[10];
                }
              }
              else
              {
                ++*(_DWORD *)&v97[6];
              }
            }
            else
            {
              ++*(_DWORD *)&v97[2];
            }
          }
          if ( (unsigned __int16)v36 < 0x7FFFu )
          {
            *(_WORD *)v96 = *(_WORD *)&v97[2];
            *(_DWORD *)&v96[2] = *(_DWORD *)&v97[4];
            *(_DWORD *)&v96[6] = *(_DWORD *)&v97[8];
            *(_WORD *)&v96[10] = v73 | v36;
          }
          else
          {
            *(_DWORD *)&v96[4] = 0;
            *(_DWORD *)v96 = 0;
            *(_DWORD *)&v96[8] = v73 == 0 ? 2147450880 : -32768;
          }
          goto LABEL_132;
        }
      }
      else
      {
        v30 = 0;
      }
      *(_DWORD *)&v96[4] = 0;
      *(_DWORD *)v96 = 0;
    }
    *(_DWORD *)&v96[8] = v30;
  }
LABEL_132:
  v43 = ndigits;
  fos->exp = v80;
  if ( (output_flags & 1) != 0 )
  {
    v43 = v80 + ndigits;
    if ( v43 <= 0 )
    {
      fos->exp = 0;
      fos->ManLen = 1;
      fos->sign = v68 != -32768 ? 32 : 45;
      fos->man[0] = 48;
      fos->man[1] = 0;
      return 1;
    }
  }
  if ( v43 > 21 )
    v43 = 21;
  v44 = *(unsigned __int16 *)&v96[10] - 16382;
  *(_WORD *)&v96[10] = 0;
  v86 = 8;
  do
  {
    v45 = *(_DWORD *)v96;
    *(_DWORD *)v96 *= 2;
    v46 = (v45 >> 31) | (2 * *(_DWORD *)&v96[4]);
    v47 = *(__int64 *)&v96[4] >> 31;
    v48 = v86-- == 1;
    *(_DWORD *)&v96[4] = v46;
    *(_DWORD *)&v96[8] = v47;
  }
  while ( !v48 );
  if ( v44 < 0 )
  {
    v49 = (unsigned __int8)-(char)v44;
    if ( v49 )
    {
      do
      {
        v50 = *(_DWORD *)&v96[8];
        *(_DWORD *)&v96[8] >>= 1;
        v51 = (v50 << 31) | (*(_DWORD *)&v96[4] >> 1);
        v52 = *(__int64 *)v96 >> 1;
        --v49;
        *(_DWORD *)&v96[4] = v51;
        *(_DWORD *)v96 = v52;
      }
      while ( v49 > 0 );
    }
  }
  man = fos->man;
  v90 = fos->man;
  for ( k = v43 + 1; k > 0; v96[11] = 0 )
  {
    v54 = *(_DWORD *)v96;
    v91 = *(_QWORD *)v96;
    v92 = *(_DWORD *)&v96[8];
    *(_DWORD *)v96 *= 2;
    v55 = *(_DWORD *)v96;
    *(_DWORD *)v96 *= 2;
    v56 = (v54 >> 31) | (2 * *(_DWORD *)&v96[4]);
    v57 = 2 * v56;
    v58 = (v56 >> 31) | (2 * (*(__int64 *)&v96[4] >> 31));
    v59 = (v55 >> 31) | v57;
    v60 = v91 + *(_DWORD *)v96;
    if ( (unsigned int)(v91 + *(_DWORD *)v96) < *(_DWORD *)v96 || v60 < (unsigned int)v91 )
    {
      v61 = 0;
      if ( v59 + 1 < v59 || v59 == -1 )
        v61 = 1;
      ++v59;
      if ( v61 )
        ++v58;
    }
    v62 = HIDWORD(v91) + v59;
    v87 = HIDWORD(v91) + v59;
    if ( HIDWORD(v91) + v59 < v59 || v62 < HIDWORD(v91) )
      ++v58;
    *(_DWORD *)v96 = 2 * v60;
    *(_DWORD *)&v96[8] = (v62 >> 31) | (2 * (v92 + v58));
    *man++ = v96[11] + 48;
    --k;
    *(_DWORD *)&v96[4] = (v60 >> 31) | (2 * v87);
  }
  v63 = man - 1;
  v64 = *v63;
  v65 = v63 - 1;
  if ( v64 >= 53 )
  {
    while ( v65 >= v90 && *v65 == 57 )
      *v65-- = 48;
    v66 = fos;
    if ( v65 < v90 )
    {
      ++v65;
      ++fos->exp;
    }
    ++*v65;
  }
  else
  {
    while ( v65 >= v90 && *v65 == 48 )
      --v65;
    v66 = fos;
    if ( v65 < v90 )
    {
      fos->exp = 0;
      fos->ManLen = 1;
      fos->sign = v68 != -32768 ? 32 : 45;
      *v90 = 48;
      fos->man[1] = 0;
      return 1;
    }
  }
  v67 = (_BYTE)v65 - (_BYTE)v66 - 3;
  v66->ManLen = v67;
  v66->man[v67] = 0;
  return 1;
}
