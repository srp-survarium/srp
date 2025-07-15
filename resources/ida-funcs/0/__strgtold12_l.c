unsigned int __cdecl __strgtold12_l(
        _LDBL12 *pld12,
        const char **p_end_ptr,
        const char *str,
        int mult12,
        int scale,
        int decpt,
        int implicit_E,
        localeinfo_struct *_Locale)
{
  int v8; // ecx
  char *v9; // edi
  unsigned int result; // eax
  const char *v11; // edx
  char v12; // al
  char v13; // al
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  bool v18; // zf
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // eax
  _LDBL12 *v23; // ecx
  char v24; // al
  _LDBL12 *v25; // ecx
  int v26; // eax
  _LDBL12 *v27; // ebx
  __int16 v28; // cx
  __int16 v29; // si
  unsigned __int16 v30; // cx
  __int16 v31; // si
  unsigned __int16 v32; // dx
  int v33; // eax
  _WORD *v34; // edi
  unsigned int v35; // eax
  unsigned int v36; // ecx
  unsigned int v37; // esi
  __int16 v38; // dx
  unsigned int v39; // eax
  int v40; // esi
  int v41; // eax
  int v42; // esi
  int v43; // eax
  int v44; // edi
  int v45; // eax
  __int16 v46; // cx
  int v47; // esi
  unsigned int v48; // edx
  __int16 v49; // ax
  int v50; // [esp-4h] [ebp-8Ch]
  int v51; // [esp-4h] [ebp-8Ch]
  _LDBL12 *v52; // [esp+Ch] [ebp-7Ch]
  __int16 v53; // [esp+14h] [ebp-74h]
  __int16 v54; // [esp+18h] [ebp-70h]
  unsigned int v55; // [esp+1Ch] [ebp-6Ch]
  int v56; // [esp+20h] [ebp-68h]
  int v57; // [esp+20h] [ebp-68h]
  int v58; // [esp+24h] [ebp-64h]
  int v59; // [esp+24h] [ebp-64h]
  int v60; // [esp+28h] [ebp-60h]
  unsigned __int8 *v61; // [esp+28h] [ebp-60h]
  int v62; // [esp+2Ch] [ebp-5Ch]
  unsigned __int8 *v63; // [esp+2Ch] [ebp-5Ch]
  int v64; // [esp+30h] [ebp-58h]
  int i; // [esp+30h] [ebp-58h]
  const char *v66; // [esp+34h] [ebp-54h]
  int v67; // [esp+34h] [ebp-54h]
  int v68; // [esp+38h] [ebp-50h]
  int v69; // [esp+38h] [ebp-50h]
  unsigned int manlen; // [esp+3Ch] [ebp-4Ch]
  unsigned int manlena; // [esp+3Ch] [ebp-4Ch]
  __int64 v72; // [esp+40h] [ebp-48h] BYREF
  int v73; // [esp+48h] [ebp-40h]
  _LDBL12 ld12; // [esp+4Ch] [ebp-3Ch] BYREF
  _BYTE v75[12]; // [esp+5Ch] [ebp-2Ch] BYREF
  char manptr[23]; // [esp+68h] [ebp-20h] BYREF
  char v77; // [esp+7Fh] [ebp-9h]

  v8 = 0;
  v9 = manptr;
  v53 = 0;
  v56 = 1;
  manlen = 0;
  v64 = 0;
  v62 = 0;
  v60 = 0;
  v58 = 0;
  v68 = 0;
  v55 = 0;
  if ( !_Locale )
  {
    *_errno() = 22;
    _invalid_parameter(0, (int)manptr, 1);
    return 0;
  }
  v11 = str;
  v66 = str;
  while ( 1 )
  {
    v12 = *v11;
    if ( *v11 != 32 && v12 != 9 && v12 != 10 && v12 != 13 )
      break;
    ++v11;
  }
  while ( 2 )
  {
    v13 = *v11++;
    switch ( v8 )
    {
      case 0:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_14;
        v14 = v13 - 43;
        if ( !v14 )
        {
          v53 = 0;
          v8 = 2;
          continue;
        }
        v15 = v14 - 2;
        if ( !v15 )
        {
          v8 = 2;
          v53 = 0x8000;
          continue;
        }
        if ( v15 != 3 )
          goto LABEL_75;
        goto LABEL_19;
      case 1:
        v64 = 1;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_24;
        if ( v13 == 43 || v13 == 45 )
          goto LABEL_33;
        if ( v13 == 48 )
          goto LABEL_19;
LABEL_28:
        if ( v13 <= 67 || v13 > 69 && (v13 <= 99 || v13 > 101) )
          goto LABEL_75;
        v51 = 6;
        goto LABEL_15;
      case 2:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
        {
LABEL_11:
          v50 = 3;
LABEL_12:
          v8 = v50;
          --v11;
        }
        else
        {
          if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          {
LABEL_14:
            v51 = 5;
            goto LABEL_15;
          }
          if ( v13 != 48 )
          {
LABEL_37:
            v11 = v66;
            goto LABEL_82;
          }
LABEL_19:
          v8 = 1;
        }
        continue;
      case 3:
        v64 = 1;
        while ( v13 >= 48 && v13 <= 57 )
        {
          if ( manlen >= 0x19 )
          {
            ++v68;
          }
          else
          {
            ++manlen;
            *v9++ = v13 - 48;
          }
          v13 = *v11++;
        }
        if ( v13 != *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_46;
LABEL_24:
        v51 = 4;
        goto LABEL_15;
      case 4:
        v64 = 1;
        v62 = 1;
        if ( !manlen )
        {
          while ( v13 == 48 )
          {
            --v68;
            v13 = *v11++;
          }
        }
        while ( v13 >= 48 && v13 <= 57 )
        {
          if ( manlen < 0x19 )
          {
            ++manlen;
            *v9++ = v13 - 48;
            --v68;
          }
          v13 = *v11++;
        }
LABEL_46:
        if ( v13 != 43 && v13 != 45 )
          goto LABEL_28;
LABEL_33:
        --v11;
        v51 = 11;
        goto LABEL_15;
      case 5:
        v62 = 1;
        if ( (unsigned __int8)(v13 - 48) > 9u )
          goto LABEL_37;
        v50 = 4;
        goto LABEL_12;
      case 6:
        v66 = v11 - 2;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_63;
        v16 = v13 - 43;
        if ( !v16 )
          goto LABEL_70;
        v17 = v16 - 2;
        if ( !v17 )
          goto LABEL_69;
        v18 = v17 == 3;
LABEL_67:
        if ( !v18 )
          goto LABEL_37;
        v51 = 8;
        goto LABEL_15;
      case 7:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_63;
        v18 = v13 == 48;
        goto LABEL_67;
      case 8:
        v60 = 1;
        while ( v13 == 48 )
          v13 = *v11++;
        if ( (unsigned __int8)(v13 - 49) > 8u )
          goto LABEL_75;
LABEL_63:
        v50 = 9;
        goto LABEL_12;
      case 9:
        v60 = 1;
        v20 = 0;
        while ( 2 )
        {
          if ( v13 >= 48 && v13 <= 57 )
          {
            v20 = 10 * v20 + v13 - 48;
            if ( v20 <= 5200 )
            {
              v13 = *v11++;
              continue;
            }
            v20 = 5201;
          }
          break;
        }
        v58 = v20;
        while ( v13 >= 48 && v13 <= 57 )
          v13 = *v11++;
LABEL_75:
        --v11;
        goto LABEL_82;
      case 11:
        if ( !implicit_E )
        {
          v8 = 10;
          --v11;
LABEL_90:
          if ( v8 == 10 )
            goto LABEL_82;
          continue;
        }
        v19 = v13 - 43;
        v66 = v11 - 1;
        if ( !v19 )
        {
LABEL_70:
          v51 = 7;
LABEL_15:
          v8 = v51;
          continue;
        }
        if ( v19 == 2 )
        {
LABEL_69:
          v56 = -1;
          v8 = 7;
          continue;
        }
        --v11;
LABEL_82:
        *p_end_ptr = v11;
        if ( !v64 )
        {
          v55 = 4;
LABEL_179:
          v46 = 0;
          v49 = 0;
          v48 = 0;
          v47 = 0;
          goto LABEL_180;
        }
        if ( manlen > 0x18 )
        {
          if ( v77 >= 5 )
            ++v77;
          --v9;
          ++v68;
          manlen = 24;
        }
        if ( !manlen )
          goto LABEL_179;
        while ( !*--v9 )
        {
          --manlen;
          ++v68;
        }
        __mtold12(manptr, manlen, &ld12);
        v21 = v58;
        if ( v56 < 0 )
          v21 = -v58;
        v22 = v68 + v21;
        if ( !v60 )
          v22 += scale;
        if ( !v62 )
          v22 -= decpt;
        if ( v22 > 5200 )
        {
          v47 = 0;
          v49 = 0x7FFF;
          v48 = 0x80000000;
          v46 = 0;
          v55 = 2;
          goto LABEL_180;
        }
        if ( v22 < -5200 )
        {
          v55 = 1;
          goto LABEL_179;
        }
        v23 = &_pow10pos[-8];
        v67 = v22;
        if ( v22 )
        {
          if ( v22 < 0 )
          {
            v67 = -v22;
            v23 = &_pow10neg[-8];
          }
          if ( !mult12 )
            *(_WORD *)ld12.ld12 = 0;
          if ( v67 )
          {
            while ( 1 )
            {
              v24 = v67;
              v67 >>= 3;
              v25 = v23 + 7;
              v26 = v24 & 7;
              v52 = v25;
              if ( !v26 )
                goto LABEL_174;
              v27 = &v25[v26];
              if ( *(_WORD *)v27->ld12 >= 0x8000u )
              {
                v72 = *(_QWORD *)v27->ld12;
                v73 = *(_DWORD *)&v27->ld12[8];
                --*(_DWORD *)((char *)&v72 + 2);
                v27 = (_LDBL12 *)&v72;
              }
              v28 = *(_WORD *)&v27->ld12[10];
              v69 = 0;
              memset(v75, 0, sizeof(v75));
              v29 = *(_WORD *)&ld12.ld12[10] ^ v28;
              v30 = v28 & 0x7FFF;
              v31 = v29 & 0x8000;
              v54 = v31;
              v32 = v30 + (*(_WORD *)&ld12.ld12[10] & 0x7FFF);
              if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0x7FFF || v30 >= 0x7FFFu || v32 > 0xBFFDu )
                break;
              if ( v32 <= 0x3FBFu )
              {
                v33 = 0;
                *(_DWORD *)&ld12.ld12[4] = 0;
                *(_DWORD *)ld12.ld12 = 0;
LABEL_173:
                *(_DWORD *)&ld12.ld12[8] = v33;
                goto LABEL_174;
              }
              if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) != 0
                || (++v32, (*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) != 0)
                || *(_DWORD *)&ld12.ld12[4]
                || *(_DWORD *)ld12.ld12 )
              {
                if ( v30
                  || (++v32, (*(_DWORD *)&v27->ld12[8] & 0x7FFFFFFF) != 0)
                  || *(_DWORD *)&v27->ld12[4]
                  || *(_DWORD *)v27->ld12 )
                {
                  v57 = 0;
                  v34 = &v75[4];
                  for ( i = 5; i > 0; --i )
                  {
                    v59 = i;
                    v63 = &ld12.ld12[2 * v57];
                    v61 = &v27->ld12[8];
                    do
                    {
                      manlena = 0;
                      v35 = *(unsigned __int16 *)v63 * *(unsigned __int16 *)v61;
                      v36 = *((_DWORD *)v34 - 1);
                      v37 = v36 + v35;
                      if ( v36 + v35 < v36 || v37 < v35 )
                        manlena = 1;
                      *((_DWORD *)v34 - 1) = v37;
                      if ( manlena )
                        ++*v34;
                      v63 += 2;
                      v61 -= 2;
                      --v59;
                    }
                    while ( v59 > 0 );
                    ++v34;
                    ++v57;
                  }
                  v38 = v32 - 16382;
                  if ( v38 <= 0 )
                    goto LABEL_183;
                  do
                  {
                    if ( *(int *)&v75[8] < 0 )
                      break;
                    v39 = *(_DWORD *)v75;
                    *(_DWORD *)v75 *= 2;
                    v40 = (v39 >> 31) | (2 * *(_DWORD *)&v75[4]);
                    v41 = *(__int64 *)&v75[4] >> 31;
                    --v38;
                    *(_DWORD *)&v75[4] = v40;
                    *(_DWORD *)&v75[8] = v41;
                  }
                  while ( v38 > 0 );
                  if ( v38 <= 0 )
                  {
LABEL_183:
                    if ( --v38 < 0 )
                    {
                      v42 = (unsigned __int16)-v38;
                      v38 = 0;
                      do
                      {
                        if ( (v75[0] & 1) != 0 )
                          ++v69;
                        v43 = *(_DWORD *)&v75[8];
                        *(_DWORD *)&v75[8] >>= 1;
                        v44 = (v43 << 31) | (*(_DWORD *)&v75[4] >> 1);
                        v45 = *(__int64 *)v75 >> 1;
                        --v42;
                        *(_DWORD *)&v75[4] = v44;
                        *(_DWORD *)v75 = v45;
                      }
                      while ( v42 );
                      if ( v69 )
                        *(_WORD *)v75 |= 1u;
                    }
                  }
                  if ( *(_WORD *)v75 > 0x8000u || ((unsigned int)&loc_1FFFF & *(_DWORD *)v75) == 0x18000 )
                  {
                    if ( *(_DWORD *)&v75[2] == -1 )
                    {
                      *(_DWORD *)&v75[2] = 0;
                      if ( *(_DWORD *)&v75[6] == -1 )
                      {
                        *(_DWORD *)&v75[6] = 0;
                        if ( *(_WORD *)&v75[10] == 0xFFFF )
                        {
                          *(_WORD *)&v75[10] = 0x8000;
                          ++v38;
                        }
                        else
                        {
                          ++*(_WORD *)&v75[10];
                        }
                      }
                      else
                      {
                        ++*(_DWORD *)&v75[6];
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)&v75[2];
                    }
                  }
                  if ( (unsigned __int16)v38 < 0x7FFFu )
                  {
                    *(_WORD *)ld12.ld12 = *(_WORD *)&v75[2];
                    *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)&v75[4];
                    *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&v75[8];
                    *(_WORD *)&ld12.ld12[10] = v54 | v38;
                  }
                  else
                  {
                    *(_DWORD *)&ld12.ld12[4] = 0;
                    *(_DWORD *)ld12.ld12 = 0;
                    *(_DWORD *)&ld12.ld12[8] = v54 == 0 ? 2147450880 : -32768;
                  }
                }
                else
                {
                  memset(&ld12, 0, sizeof(ld12));
                }
              }
              else
              {
                *(_WORD *)&ld12.ld12[10] = 0;
              }
LABEL_174:
              if ( !v67 )
                goto LABEL_175;
              v23 = v52;
            }
            *(_DWORD *)&ld12.ld12[4] = 0;
            v33 = v31 == 0 ? 2147450880 : -32768;
            *(_DWORD *)ld12.ld12 = 0;
            goto LABEL_173;
          }
        }
LABEL_175:
        v46 = *(_WORD *)ld12.ld12;
        v47 = *(_DWORD *)&ld12.ld12[2];
        v48 = *(_DWORD *)&ld12.ld12[6];
        v49 = *(_WORD *)&ld12.ld12[10];
LABEL_180:
        *(_WORD *)pld12->ld12 = v46;
        *(_WORD *)&pld12->ld12[10] = v53 | v49;
        result = v55;
        *(_DWORD *)&pld12->ld12[2] = v47;
        *(_DWORD *)&pld12->ld12[6] = v48;
        return result;
      default:
        goto LABEL_90;
    }
  }
}
