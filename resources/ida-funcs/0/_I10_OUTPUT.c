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
  _LDBL12 *p_tmp12; // eax
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
  unsigned __int8 *v32; // eax
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
  __int16 sign; // [esp+10h] [ebp-70h]
  unsigned __int8 *v69; // [esp+14h] [ebp-6Ch]
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
  __int16 digcount; // [esp+34h] [ebp-4Ch]
  int digcounta; // [esp+34h] [ebp-4Ch]
  __int16 v82; // [esp+38h] [ebp-48h]
  unsigned __int8 *v83; // [esp+38h] [ebp-48h]
  _LDBL12 *v84; // [esp+3Ch] [ebp-44h]
  int v85; // [esp+3Ch] [ebp-44h]
  int v86; // [esp+3Ch] [ebp-44h]
  unsigned int v87; // [esp+3Ch] [ebp-44h]
  int i; // [esp+40h] [ebp-40h]
  int j; // [esp+40h] [ebp-40h]
  char *v90; // [esp+40h] [ebp-40h]
  _LDBL12 tmp12; // [esp+44h] [ebp-3Ch] BYREF
  _LDBL12 ld12_one_tenth; // [esp+50h] [ebp-30h] BYREF
  _LDBL12 ld12; // [esp+60h] [ebp-20h] BYREF
  _BYTE v94[12]; // [esp+70h] [ebp-10h] BYREF

  *(_LDOUBLE *)v94 = ld;
  v4 = *(_WORD *)&ld.ld[8] & 0x8000;
  v5 = *(_WORD *)&ld.ld[8] & 0x7FFF;
  memset(&ld12_one_tenth, 204, 10);
  ld12_one_tenth.ld12[10] = -5;
  ld12_one_tenth.ld12[11] = 63;
  sign = *(_WORD *)&ld.ld[8] & 0x8000;
  if ( *(__int16 *)&ld.ld[8] >= 0 )
    fos->sign = 32;
  else
    fos->sign = 45;
  v6 = *(_QWORD *)v94;
  if ( !v5 && !*(_QWORD *)v94 )
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
      v8 = strcpy_s(fos->man, 0x16u, "1#SNAN");
LABEL_22:
      if ( v8 )
        _invoke_watson((unsigned int)fos, v6, 0);
      fos->ManLen = 6;
      return 0;
    }
    if ( v4 && HIDWORD(v6) == -1073741824 )
    {
      if ( !(_DWORD)v6 )
      {
        v9 = strcpy_s(fos->man, 0x16u, "1#IND");
LABEL_18:
        if ( v9 )
          _invoke_watson((unsigned int)fos, 0, 0);
        fos->ManLen = 5;
        return 0;
      }
    }
    else if ( v6 == 0x8000000000000000uLL )
    {
      v9 = strcpy_s(fos->man, 0x16u, "1#INF");
      goto LABEL_18;
    }
    v8 = strcpy_s(fos->man, 0x16u, "1#QNAN");
    goto LABEL_22;
  }
  v10 = (77 * (HIBYTE(v5) + 2 * HIBYTE(*(_DWORD *)&v94[4])) + 19728 * (unsigned int)v5 - 323162868) >> 16;
  *(_WORD *)ld12.ld12 = 0;
  v11 = -v10;
  digcount = v10;
  *(_WORD *)&ld12.ld12[10] = *(_WORD *)&ld.ld[8] & 0x7FFF;
  *(_QWORD *)&ld12.ld12[2] = *(_QWORD *)v94;
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
        p_tmp12 = &v71[v12];
        v84 = p_tmp12;
        if ( *(_WORD *)p_tmp12->ld12 >= 0x8000u )
        {
          *(_DWORD *)tmp12.ld12 = *(_DWORD *)p_tmp12->ld12;
          *(_DWORD *)&tmp12.ld12[4] = *(_DWORD *)&p_tmp12->ld12[4];
          v14 = &p_tmp12->ld12[8];
          p_tmp12 = &tmp12;
          *(_DWORD *)&tmp12.ld12[8] = *(_DWORD *)v14;
          --*(_DWORD *)&tmp12.ld12[2];
          v84 = &tmp12;
        }
        v15 = *(_WORD *)&p_tmp12->ld12[10];
        v76 = 0;
        memset(v94, 0, sizeof(v94));
        v82 = (*(_WORD *)&ld12.ld12[10] ^ v15) & 0x8000;
        v16 = v15 & 0x7FFF;
        v17 = v16 + (*(_WORD *)&ld12.ld12[10] & 0x7FFF);
        if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0x7FFF || v16 >= 0x7FFFu || v17 > 0xBFFDu )
        {
          *(_DWORD *)&ld12.ld12[8] = v82 == 0 ? 2147450880 : -32768;
        }
        else
        {
          if ( v17 > 0x3FBFu )
          {
            if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0 )
            {
              ++v17;
              if ( (*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) == 0 && !*(_DWORD *)&ld12.ld12[4] && !*(_DWORD *)ld12.ld12 )
              {
                *(_WORD *)&ld12.ld12[10] = 0;
                continue;
              }
            }
            if ( v16
              || (++v17, (*(_DWORD *)&p_tmp12->ld12[8] & 0x7FFFFFFF) != 0)
              || *(_DWORD *)&p_tmp12->ld12[4]
              || *(_DWORD *)p_tmp12->ld12 )
            {
              v74 = 0;
              v18 = &v94[4];
              for ( i = 5; i > 0; --i )
              {
                v78 = i;
                v69 = &ld12.ld12[2 * v74];
                v70 = &p_tmp12->ld12[8];
                do
                {
                  v19 = *((_DWORD *)v18 - 1);
                  v20 = *(unsigned __int16 *)v70 * *(unsigned __int16 *)v69;
                  v72 = 0;
                  v21 = v19 + v20;
                  if ( v19 + v20 < v19 || v21 < v20 )
                    v72 = 1;
                  *((_DWORD *)v18 - 1) = v21;
                  if ( v72 )
                    ++*v18;
                  v69 += 2;
                  v70 -= 2;
                  --v78;
                }
                while ( v78 > 0 );
                p_tmp12 = v84;
                ++v18;
                ++v74;
              }
              v22 = v17 - 16382;
              if ( v22 <= 0 )
                goto LABEL_170;
              do
              {
                if ( *(int *)&v94[8] < 0 )
                  break;
                v23 = *(_DWORD *)v94;
                *(_DWORD *)v94 *= 2;
                v24 = *(_DWORD *)&v94[4];
                *(_DWORD *)&v94[4] = (v23 >> 31) | (2 * *(_DWORD *)&v94[4]);
                --v22;
                *(_DWORD *)&v94[8] = (v24 >> 31) | (2 * *(_DWORD *)&v94[8]);
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
                    if ( (v94[0] & 1) != 0 )
                      ++v76;
                    v26 = *(_DWORD *)&v94[8];
                    *(_DWORD *)&v94[8] >>= 1;
                    v27 = __SPAIR64__(v26, *(unsigned int *)&v94[4]) >> 1;
                    v28 = *(__int64 *)v94 >> 1;
                    --v25;
                    *(_DWORD *)&v94[4] = v27;
                    *(_DWORD *)v94 = v28;
                  }
                  while ( v25 );
                  if ( v76 )
                    *(_WORD *)v94 |= 1u;
                }
              }
              if ( *(_WORD *)v94 > 0x8000u || (*(_DWORD *)v94 & 0x1FFFF) == 0x18000 )
              {
                if ( *(_DWORD *)&v94[2] == -1 )
                {
                  *(_DWORD *)&v94[2] = 0;
                  if ( *(_DWORD *)&v94[6] == -1 )
                  {
                    *(_DWORD *)&v94[6] = 0;
                    if ( *(_WORD *)&v94[10] == 0xFFFF )
                    {
                      *(_WORD *)&v94[10] = 0x8000;
                      ++v22;
                    }
                    else
                    {
                      ++*(_WORD *)&v94[10];
                    }
                  }
                  else
                  {
                    ++*(_DWORD *)&v94[6];
                  }
                }
                else
                {
                  ++*(_DWORD *)&v94[2];
                }
              }
              if ( (unsigned __int16)v22 < 0x7FFFu )
              {
                *(_WORD *)ld12.ld12 = *(_WORD *)&v94[2];
                *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)&v94[4];
                *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&v94[8];
                *(_WORD *)&ld12.ld12[10] = v82 | v22;
              }
              else
              {
                *(_DWORD *)&ld12.ld12[4] = 0;
                *(_DWORD *)ld12.ld12 = 0;
                *(_DWORD *)&ld12.ld12[8] = v82 == 0 ? 2147450880 : -32768;
              }
              continue;
            }
          }
          *(_DWORD *)&ld12.ld12[8] = 0;
        }
        *(_DWORD *)&ld12.ld12[4] = 0;
        *(_DWORD *)ld12.ld12 = 0;
      }
    }
  }
  if ( *(_WORD *)&ld12.ld12[10] >= 0x3FFFu )
  {
    ++digcount;
    v79 = 0;
    memset(v94, 0, sizeof(v94));
    v73 = (*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&ld12_one_tenth.ld12[10]) & 0x8000;
    v29 = (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) + (*(_WORD *)&ld12.ld12[10] & 0x7FFF);
    if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0x7FFF
      || (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) == 0x7FFF
      || v29 > 0xBFFDu )
    {
      *(_DWORD *)&ld12.ld12[4] = 0;
      v30 = ((*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&ld12_one_tenth.ld12[10]) & 0x8000u) == 0 ? 2147450880 : -32768;
      *(_DWORD *)ld12.ld12 = 0;
    }
    else
    {
      if ( v29 > 0x3FBFu )
      {
        v30 = 0;
        if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0 )
        {
          ++v29;
          if ( (*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) == 0 && !*(_DWORD *)&ld12.ld12[4] && !*(_DWORD *)ld12.ld12 )
          {
            *(_WORD *)&ld12.ld12[10] = 0;
            goto LABEL_132;
          }
        }
        if ( (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) != 0
          || (++v29, (*(_DWORD *)&ld12_one_tenth.ld12[8] & 0x7FFFFFFF) != 0)
          || *(_DWORD *)&ld12_one_tenth.ld12[4]
          || *(_DWORD *)ld12_one_tenth.ld12 )
        {
          v75 = 0;
          v31 = &v94[4];
          for ( j = 5; j > 0; --j )
          {
            v77 = j;
            v83 = &ld12_one_tenth.ld12[8];
            v32 = &ld12.ld12[2 * v75];
            do
            {
              v85 = 0;
              v33 = *(unsigned __int16 *)v32 * *(unsigned __int16 *)v83;
              v34 = *((_DWORD *)v31 - 1);
              v35 = v34 + v33;
              if ( v34 + v33 < v34 || v35 < v33 )
                v85 = 1;
              *((_DWORD *)v31 - 1) = v35;
              if ( v85 )
                ++*v31;
              v83 -= 2;
              v32 += 2;
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
            if ( *(int *)&v94[8] < 0 )
              break;
            v37 = *(_DWORD *)v94;
            *(_DWORD *)v94 *= 2;
            v38 = *(_DWORD *)&v94[4];
            *(_DWORD *)&v94[4] = (v37 >> 31) | (2 * *(_DWORD *)&v94[4]);
            --v36;
            *(_DWORD *)&v94[8] = (v38 >> 31) | (2 * *(_DWORD *)&v94[8]);
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
                if ( (v94[0] & 1) != 0 )
                  ++v79;
                v40 = *(_DWORD *)&v94[8];
                *(_DWORD *)&v94[8] >>= 1;
                v41 = __SPAIR64__(v40, *(unsigned int *)&v94[4]) >> 1;
                v42 = *(__int64 *)v94 >> 1;
                --v39;
                *(_DWORD *)&v94[4] = v41;
                *(_DWORD *)v94 = v42;
              }
              while ( v39 );
              if ( v79 )
                *(_WORD *)v94 |= 1u;
            }
          }
          if ( *(_WORD *)v94 > 0x8000u || (*(_DWORD *)v94 & 0x1FFFF) == 0x18000 )
          {
            if ( *(_DWORD *)&v94[2] == -1 )
            {
              *(_DWORD *)&v94[2] = 0;
              if ( *(_DWORD *)&v94[6] == -1 )
              {
                *(_DWORD *)&v94[6] = 0;
                if ( *(_WORD *)&v94[10] == 0xFFFF )
                {
                  *(_WORD *)&v94[10] = 0x8000;
                  ++v36;
                }
                else
                {
                  ++*(_WORD *)&v94[10];
                }
              }
              else
              {
                ++*(_DWORD *)&v94[6];
              }
            }
            else
            {
              ++*(_DWORD *)&v94[2];
            }
          }
          if ( (unsigned __int16)v36 < 0x7FFFu )
          {
            *(_WORD *)ld12.ld12 = *(_WORD *)&v94[2];
            *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)&v94[4];
            *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&v94[8];
            *(_WORD *)&ld12.ld12[10] = v73 | v36;
          }
          else
          {
            *(_DWORD *)&ld12.ld12[4] = 0;
            *(_DWORD *)ld12.ld12 = 0;
            *(_DWORD *)&ld12.ld12[8] = v73 == 0 ? 2147450880 : -32768;
          }
          goto LABEL_132;
        }
      }
      else
      {
        v30 = 0;
      }
      *(_DWORD *)&ld12.ld12[4] = 0;
      *(_DWORD *)ld12.ld12 = 0;
    }
    *(_DWORD *)&ld12.ld12[8] = v30;
  }
LABEL_132:
  v43 = ndigits;
  fos->exp = digcount;
  if ( (output_flags & 1) != 0 )
  {
    v43 = digcount + ndigits;
    if ( v43 <= 0 )
    {
      fos->exp = 0;
      fos->ManLen = 1;
      fos->sign = sign != -32768 ? 32 : 45;
      fos->man[0] = 48;
      fos->man[1] = 0;
      return 1;
    }
  }
  if ( v43 > 21 )
    v43 = 21;
  v44 = *(unsigned __int16 *)&ld12.ld12[10] - 16382;
  *(_WORD *)&ld12.ld12[10] = 0;
  v86 = 8;
  do
  {
    v45 = *(_DWORD *)ld12.ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v46 = (v45 >> 31) | (2 * *(_DWORD *)&ld12.ld12[4]);
    v47 = *(__int64 *)&ld12.ld12[4] >> 31;
    v48 = v86-- == 1;
    *(_DWORD *)&ld12.ld12[4] = v46;
    *(_DWORD *)&ld12.ld12[8] = v47;
  }
  while ( !v48 );
  if ( v44 < 0 )
  {
    v49 = (unsigned __int8)-(char)v44;
    if ( v49 )
    {
      do
      {
        v50 = *(_DWORD *)&ld12.ld12[8];
        *(_DWORD *)&ld12.ld12[8] >>= 1;
        v51 = (v50 << 31) | (*(_DWORD *)&ld12.ld12[4] >> 1);
        v52 = *(__int64 *)ld12.ld12 >> 1;
        --v49;
        *(_DWORD *)&ld12.ld12[4] = v51;
        *(_DWORD *)ld12.ld12 = v52;
      }
      while ( v49 > 0 );
    }
  }
  man = fos->man;
  v90 = fos->man;
  for ( digcounta = v43 + 1; digcounta > 0; ld12.ld12[11] = 0 )
  {
    v54 = *(_DWORD *)ld12.ld12;
    tmp12 = ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v55 = *(_DWORD *)ld12.ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v56 = (v54 >> 31) | (2 * *(_DWORD *)&ld12.ld12[4]);
    v57 = 2 * v56;
    v58 = (v56 >> 31) | (2 * (*(__int64 *)&ld12.ld12[4] >> 31));
    v59 = (v55 >> 31) | v57;
    v60 = *(_DWORD *)tmp12.ld12 + *(_DWORD *)ld12.ld12;
    if ( (unsigned int)(*(_DWORD *)tmp12.ld12 + *(_DWORD *)ld12.ld12) < *(_DWORD *)ld12.ld12
      || v60 < *(_DWORD *)tmp12.ld12 )
    {
      v61 = 0;
      if ( v59 + 1 < v59 || v59 == -1 )
        v61 = 1;
      ++v59;
      if ( v61 )
        ++v58;
    }
    v62 = *(_DWORD *)&tmp12.ld12[4] + v59;
    v87 = *(_DWORD *)&tmp12.ld12[4] + v59;
    if ( *(_DWORD *)&tmp12.ld12[4] + v59 < v59 || v62 < *(_DWORD *)&tmp12.ld12[4] )
      ++v58;
    *(_DWORD *)ld12.ld12 = 2 * v60;
    *(_DWORD *)&ld12.ld12[8] = (v62 >> 31) | (2 * (*(_DWORD *)&tmp12.ld12[8] + v58));
    *man++ = ld12.ld12[11] + 48;
    --digcounta;
    *(_DWORD *)&ld12.ld12[4] = (v60 >> 31) | (2 * v87);
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
      fos->sign = sign != -32768 ? 32 : 45;
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
