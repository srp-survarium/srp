int __usercall _input_l@<eax>(
        int a1@<ebx>,
        _iobuf *stream,
        const unsigned __int8 *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  const unsigned __int8 *v5; // edi
  int result; // eax
  int v7; // eax
  ioinfo *v8; // ecx
  ioinfo *v9; // eax
  unsigned __int8 v10; // al
  _iobuf *v11; // esi
  int v12; // eax
  unsigned __int8 v13; // cl
  const unsigned __int8 *v14; // eax
  _WORD *v15; // esi
  unsigned __int8 v16; // al
  int v17; // eax
  int v18; // eax
  int v19; // edi
  int i; // eax
  int j; // eax
  int k; // eax
  void (__cdecl *v29)(int, _WORD *, char *, _LocaleUpdate *); // eax
  _iobuf *v30; // edi
  int v32; // eax
  unsigned __int8 *v33; // edi
  unsigned __int8 *v34; // esi
  unsigned __int8 v35; // dl
  unsigned __int8 v36; // cl
  unsigned __int8 v37; // al
  unsigned int v38; // edi
  int v39; // edx
  unsigned __int8 v40; // al
  int v41; // eax
  __int64 v42; // kr00_8
  unsigned int v43; // edi
  unsigned int v44; // esi
  int v45; // edi
  int v46; // eax
  int v47; // eax
  int v48; // ecx
  int v49; // [esp-14h] [ebp-218h]
  _WORD *v50; // [esp-10h] [ebp-214h]
  char *v51; // [esp-Ch] [ebp-210h]
  char *v52; // [esp+8h] [ebp-1FCh]
  _LocaleUpdate v53; // [esp+Ch] [ebp-1F8h] BYREF
  wchar_t pwc[2]; // [esp+1Ch] [ebp-1E8h] BYREF
  char *v55; // [esp+20h] [ebp-1E4h]
  char s[4]; // [esp+24h] [ebp-1E0h] BYREF
  unsigned int pnFloatStrSz; // [esp+28h] [ebp-1DCh] BYREF
  int v58; // [esp+2Ch] [ebp-1D8h]
  unsigned __int8 v59; // [esp+33h] [ebp-1D1h]
  int pmalloc_FloatStrFlag; // [esp+34h] [ebp-1D0h] BYREF
  unsigned __int64 v61; // [esp+38h] [ebp-1CCh]
  int v62; // [esp+40h] [ebp-1C4h]
  _WORD *v63; // [esp+44h] [ebp-1C0h]
  _WORD *v64; // [esp+48h] [ebp-1BCh]
  const unsigned __int8 *v65; // [esp+4Ch] [ebp-1B8h]
  int v66; // [esp+50h] [ebp-1B4h]
  char v67; // [esp+57h] [ebp-1ADh]
  char *pFloatStr; // [esp+58h] [ebp-1ACh] BYREF
  int v69; // [esp+5Ch] [ebp-1A8h]
  int v70; // [esp+60h] [ebp-1A4h]
  char v71; // [esp+64h] [ebp-1A0h]
  char v72; // [esp+65h] [ebp-19Fh]
  char v73; // [esp+66h] [ebp-19Eh]
  char v74; // [esp+67h] [ebp-19Dh]
  _iobuf *fileptr; // [esp+68h] [ebp-19Ch]
  char v76; // [esp+6Eh] [ebp-196h]
  char v77; // [esp+6Fh] [ebp-195h]
  int v78; // [esp+70h] [ebp-194h]
  char v79; // [esp+77h] [ebp-18Dh]
  int v80; // [esp+78h] [ebp-18Ch] BYREF
  int chr; // [esp+7Ch] [ebp-188h]
  char floatstring[352]; // [esp+80h] [ebp-184h] BYREF
  _BYTE v83[32]; // [esp+1E0h] [ebp-24h] BYREF

  v5 = format;
  v55 = arglist;
  fileptr = stream;
  pFloatStr = floatstring;
  pnFloatStrSz = 350;
  pmalloc_FloatStrFlag = 0;
  *(_DWORD *)pwc = 0;
  chr = 0;
  if ( !format
    || !stream
    || (stream->_flag & 0x40) == 0
    && ((v7 = _fileno(a1, (int)format, stream), v7 == -1) || v7 == -2
      ? (v8 = &__badioinfo)
      : (a1 = v7 >> 5, v8 = (ioinfo *)((char *)__pioinfo[v7 >> 5] + 64 * (v7 & 0x1F))),
        (*((_BYTE *)v8 + 36) & 0x7F) != 0
     || (v7 == -1 || v7 == -2 ? (v9 = &__badioinfo) : (v9 = (ioinfo *)((char *)__pioinfo[v7 >> 5] + 64 * (v7 & 0x1F))),
         *((char *)v9 + 36) < 0)) )
  {
    *_errno() = 22;
    _invalid_parameter(a1, (int)format, 0);
    return -1;
  }
  _LocaleUpdate::_LocaleUpdate(&v53, plocinfo);
  v10 = *format;
  v74 = 0;
  v80 = 0;
  v62 = 0;
  if ( !v10 )
    goto LABEL_273;
  while ( 1 )
  {
    v11 = fileptr;
    if ( isspace(v10) )
    {
      --v80;
      v12 = whiteout(&v80, a1, v11);
      un_inc(a1, v12, v11);
      do
        ++v5;
      while ( isspace(*v5) );
      goto LABEL_260;
    }
    if ( *v5 == 37 )
      break;
LABEL_252:
    ++v80;
    a1 = inc(v11, a1);
    v46 = *v5++;
    chr = a1;
    v65 = v5;
    if ( v46 != a1 )
    {
      un_inc(a1, a1, v11);
      goto error_return_0;
    }
    if ( isleadbyte(a1) )
    {
      ++v80;
      v47 = inc(v11, a1);
      v48 = *v5++;
      v65 = v5;
      if ( v48 != v47 )
      {
        un_inc(a1, v47, v11);
        un_inc(a1, a1, v11);
        goto error_return_0;
      }
      --v80;
    }
LABEL_256:
    if ( chr == -1 )
    {
      if ( *v5 != 37 || v65[1] != 110 )
        goto error_return_0;
      v5 = v65;
    }
LABEL_260:
    v10 = *v5;
    if ( !*v5 )
      goto error_return_0;
  }
  if ( v5[1] == 37 )
  {
    ++v5;
    goto LABEL_252;
  }
  v63 = 0;
  v59 = 0;
  v69 = 0;
  v66 = 0;
  v78 = 0;
  v72 = 0;
  v71 = 0;
  v76 = 0;
  v67 = 0;
  v73 = 0;
  v79 = 0;
  v77 = 1;
  v58 = 0;
  do
  {
    a1 = *++v5;
    if ( isdigit((unsigned __int8)a1) )
    {
      ++v66;
      v78 = 10 * v78 + a1 - 48;
      continue;
    }
    if ( a1 > 78 )
    {
      if ( a1 == 104 )
      {
        --v77;
        --v79;
      }
      else
      {
        if ( a1 == 108 )
        {
          v14 = v5 + 1;
          if ( v5[1] == 108 )
            goto LABEL_35;
          ++v77;
        }
        else if ( a1 != 119 )
        {
          goto DEFAULT_LABEL;
        }
        ++v79;
      }
    }
    else
    {
      switch ( a1 )
      {
        case 'N':
          continue;
        case '*':
          ++v76;
          continue;
        case 'F':
          continue;
      }
      if ( a1 != 73 )
      {
        if ( a1 == 76 )
        {
          ++v77;
          continue;
        }
DEFAULT_LABEL:
        ++v67;
        continue;
      }
      v13 = v5[1];
      if ( v13 == 54 )
      {
        v14 = v5 + 2;
        if ( v5[2] == 52 )
        {
LABEL_35:
          ++v58;
          v5 = v14;
          v61 = 0;
          continue;
        }
      }
      if ( v13 == 51 && v5[2] == 50 )
      {
        v5 += 2;
        continue;
      }
      if ( v13 != 100 && v13 != 105 && v13 != 111 && v13 != 120 && v13 != 88 )
        goto DEFAULT_LABEL;
    }
  }
  while ( !v67 );
  v65 = v5;
  if ( v76 )
  {
    v15 = 0;
  }
  else
  {
    v15 = *(_WORD **)v55;
    v52 = v55;
    v55 += 4;
  }
  LOBYTE(a1) = 0;
  v64 = v15;
  if ( !v79 )
  {
    v16 = *v5;
    if ( *v5 == 83 || (v79 = -1, v16 == 67) )
      v79 = 1;
  }
  v17 = *v5 | 0x20;
  v70 = v17;
  if ( v17 == 110 )
  {
LABEL_69:
    if ( v66 && !v78 )
      goto LABEL_262;
    if ( v70 > 111 )
    {
      if ( v70 == 112 )
      {
        v77 = 1;
        goto LABEL_200;
      }
      if ( v70 != 115 )
      {
        if ( v70 == 117 )
          goto LABEL_200;
        if ( v70 == 120 )
          goto LABEL_82;
        if ( v70 != 123 )
          goto LABEL_148;
        if ( v79 > 0 )
          v73 = 1;
        v33 = (unsigned __int8 *)(v5 + 1);
        v34 = v33;
        if ( *v33 == 94 )
        {
          v34 = v33 + 1;
          v72 = -1;
        }
        memset((int)v83, 0, sizeof(v83));
        if ( *v34 == 93 )
        {
          v35 = 93;
          ++v34;
          v83[11] = 32;
        }
        else
        {
          v35 = v59;
        }
        while ( 1 )
        {
          v40 = *v34;
          if ( *v34 == 93 )
            break;
          ++v34;
          if ( v40 == 45 && v35 && (v36 = *v34, *v34 != 93) )
          {
            ++v34;
            if ( v35 >= v36 )
            {
              v37 = v35;
              v35 = v36;
            }
            else
            {
              v37 = v36;
            }
            if ( v35 <= v37 )
            {
              v38 = v35;
              v39 = (unsigned __int8)(v37 - v35 + 1);
              do
              {
                LOBYTE(a1) = 1 << (v38 & 7);
                v83[v38++ >> 3] |= a1;
                --v39;
              }
              while ( v39 );
            }
            v35 = 0;
          }
          else
          {
            v35 = v40;
            LOBYTE(a1) = 1 << (v40 & 7);
            v83[v40 >> 3] |= a1;
          }
        }
        v65 = v34;
        v15 = v64;
scanit:
        v30 = fileptr;
        --v80;
        v63 = v15;
        un_inc(a1, chr, fileptr);
        while ( 1 )
        {
          if ( v66 )
          {
            if ( !v78-- )
              break;
          }
          ++v80;
          v32 = inc(v30, a1);
          chr = v32;
          if ( v32 == -1 )
            goto LABEL_192;
          if ( v70 != 99 )
          {
            if ( v70 != 115 )
              goto LABEL_278;
            if ( v32 >= 9 && v32 <= 13 )
            {
LABEL_192:
              --v80;
              un_inc(a1, v32, v30);
              break;
            }
            if ( v32 == 32 )
            {
LABEL_278:
              if ( v70 != 123 )
                goto LABEL_192;
              a1 = v72;
              if ( ((1 << (v32 & 7)) & (v72 ^ (char)v83[v32 >> 3])) == 0 )
                goto LABEL_192;
            }
          }
          if ( v76 )
          {
            v63 = (_WORD *)((char *)v63 + 1);
          }
          else
          {
            if ( v73 )
            {
              s[0] = v32;
              if ( isleadbyte(v32) )
              {
                ++v80;
                s[1] = inc(v30, a1);
              }
              wcscpy(pwc, L"?");
              _mbtowc_l(pwc, s, v53.localeinfo.locinfo->mb_cur_max, &v53.localeinfo);
              *v15++ = pwc[0];
            }
            else
            {
              *(_BYTE *)v15 = v32;
              v15 = (_WORD *)((char *)v15 + 1);
            }
            v64 = v15;
          }
        }
        if ( v63 == v15 )
          goto error_return_0;
        if ( !v76 )
        {
          ++v62;
          if ( v70 != 99 )
          {
            if ( v73 )
              *v64 = 0;
            else
              *(_BYTE *)v64 = 0;
          }
        }
        goto LABEL_250;
      }
    }
    else
    {
      if ( v70 == 111 )
        goto LABEL_200;
      if ( v70 != 99 )
      {
        if ( v70 != 100 )
        {
          if ( v70 > 100 )
          {
            if ( v70 > 103 )
            {
              if ( v70 != 105 )
              {
                if ( v70 == 110 )
                {
                  v19 = v80;
                  if ( v76 )
                    goto LABEL_250;
assign_num:
                  if ( v58 )
                  {
                    *(_QWORD *)v15 = v61;
                  }
                  else if ( v77 )
                  {
                    *(_DWORD *)v15 = v19;
                  }
                  else
                  {
                    *v15 = v19;
                  }
                  goto LABEL_250;
                }
                goto LABEL_148;
              }
              v70 = 100;
LABEL_82:
              if ( chr == 45 )
              {
                v71 = 1;
              }
              else if ( chr != 43 )
              {
                goto LABEL_176;
              }
              if ( --v78 || !v66 )
              {
                ++v80;
                chr = inc(fileptr, a1);
              }
              else
              {
                LOBYTE(a1) = 1;
              }
LABEL_176:
              if ( chr == 48 )
              {
                ++v80;
                v41 = inc(fileptr, a1);
                chr = v41;
                if ( (_BYTE)v41 == 120 || (_BYTE)v41 == 88 )
                {
                  ++v80;
                  chr = inc(fileptr, a1);
                  if ( v66 )
                  {
                    v78 -= 2;
                    if ( v78 < 1 )
                      LOBYTE(a1) = a1 + 1;
                  }
                  v70 = 120;
                }
                else
                {
                  v69 = 1;
                  if ( v70 == 120 )
                  {
                    --v80;
                    un_inc(a1, v41, fileptr);
                    chr = 48;
                  }
                  else
                  {
                    if ( v66 )
                    {
                      if ( !--v78 )
                        LOBYTE(a1) = a1 + 1;
                    }
                    v70 = 111;
                  }
                }
              }
              goto getnum;
            }
            a1 = 0;
            if ( chr == 45 )
            {
              *pFloatStr = 45;
              a1 = 1;
            }
            else if ( chr != 43 )
            {
LABEL_88:
              if ( !v66 )
                v78 = -1;
              for ( i = (unsigned __int8)chr; isdigit(i); i = (unsigned __int8)chr )
              {
                if ( !v78-- )
                  break;
                ++v69;
                pFloatStr[a1] = chr;
                if ( !_check_float_string(++a1, &pnFloatStrSz, &pFloatStr, floatstring, &pmalloc_FloatStrFlag) )
                  goto error_return_0;
                ++v80;
                chr = inc(fileptr, a1);
              }
              v72 = *v53.localeinfo.locinfo->lconv->decimal_point;
              if ( v72 == (_BYTE)chr )
              {
                if ( v78-- )
                {
                  ++v80;
                  chr = inc(fileptr, a1);
                  pFloatStr[a1] = v72;
                  if ( !_check_float_string(++a1, &pnFloatStrSz, &pFloatStr, floatstring, &pmalloc_FloatStrFlag) )
                    goto error_return_0;
                  for ( j = (unsigned __int8)chr; isdigit(j); j = (unsigned __int8)chr )
                  {
                    if ( !v78-- )
                      break;
                    ++v69;
                    pFloatStr[a1] = chr;
                    if ( !_check_float_string(++a1, &pnFloatStrSz, &pFloatStr, floatstring, &pmalloc_FloatStrFlag) )
                      goto error_return_0;
                    ++v80;
                    chr = inc(fileptr, a1);
                  }
                }
              }
              if ( !v69 || chr != 101 && chr != 69 )
                goto LABEL_120;
              if ( !v78-- )
                goto LABEL_120;
              pFloatStr[a1] = 101;
              if ( !_check_float_string(++a1, &pnFloatStrSz, &pFloatStr, floatstring, &pmalloc_FloatStrFlag) )
                goto error_return_0;
              ++v80;
              chr = inc(fileptr, a1);
              if ( chr == 45 )
              {
                pFloatStr[a1] = 45;
                if ( !_check_float_string(++a1, &pnFloatStrSz, &pFloatStr, floatstring, &pmalloc_FloatStrFlag) )
                  goto error_return_0;
              }
              else if ( chr != 43 )
              {
                goto LABEL_115;
              }
              if ( v78-- )
              {
                ++v80;
                chr = inc(fileptr, a1);
              }
              else
              {
                v78 = 0;
              }
LABEL_115:
              for ( k = (unsigned __int8)chr; isdigit(k); k = (unsigned __int8)chr )
              {
                if ( !v78-- )
                  break;
                ++v69;
                pFloatStr[a1] = chr;
                if ( !_check_float_string(++a1, &pnFloatStrSz, &pFloatStr, floatstring, &pmalloc_FloatStrFlag) )
                  goto error_return_0;
                ++v80;
                chr = inc(fileptr, a1);
              }
LABEL_120:
              --v80;
              un_inc(a1, chr, fileptr);
              if ( !v69 )
                goto error_return_0;
              if ( !v76 )
              {
                ++v62;
                v51 = pFloatStr;
                v50 = v64;
                pFloatStr[a1] = 0;
                v49 = v77 - 1;
                v29 = (void (__cdecl *)(int, _WORD *, char *, _LocaleUpdate *))_decode_pointer(off_86F6A4[0]);
                v29(v49, v50, v51, &v53);
              }
              goto LABEL_250;
            }
            --v78;
            ++v80;
            chr = inc(fileptr, a1);
            goto LABEL_88;
          }
LABEL_148:
          if ( *v5 == chr )
          {
            --v74;
            if ( !v76 )
              v55 = v52;
            goto LABEL_250;
          }
LABEL_262:
          un_inc(a1, chr, fileptr);
          goto error_return_0;
        }
LABEL_200:
        if ( chr == 45 )
        {
          v71 = 1;
        }
        else if ( chr != 43 )
        {
          goto getnum;
        }
        if ( --v78 || !v66 )
        {
          ++v80;
          chr = inc(fileptr, a1);
        }
        else
        {
          LOBYTE(a1) = 1;
        }
getnum:
        if ( v58 )
        {
          if ( !(_BYTE)a1 )
          {
            while ( 1 )
            {
              if ( v70 == 120 || v70 == 112 )
              {
                if ( !isxdigit((unsigned __int8)chr) )
                {
LABEL_221:
                  --v80;
                  un_inc(a1, chr, fileptr);
                  break;
                }
                v43 = v61 >> 28;
                v44 = 16 * v61;
                chr = hextodec(chr);
                v42 = __PAIR64__(v43, v44);
              }
              else
              {
                if ( !isdigit((unsigned __int8)chr) )
                  goto LABEL_221;
                if ( v70 == 111 )
                {
                  if ( chr >= 56 )
                    goto LABEL_221;
                  v42 = 8 * v61;
                }
                else
                {
                  v42 = 10 * v61;
                }
              }
              ++v69;
              v61 = chr - 48 + v42;
              if ( v66 )
              {
                if ( !--v78 )
                  break;
              }
              ++v80;
              chr = inc(fileptr, a1);
            }
          }
          v19 = (int)v63;
          if ( v71 )
            v61 = -(__int64)v61;
        }
        else
        {
          v19 = (int)v63;
          if ( !(_BYTE)a1 )
          {
            while ( 1 )
            {
              if ( v70 == 120 || v70 == 112 )
              {
                if ( !isxdigit((unsigned __int8)chr) )
                {
LABEL_237:
                  --v80;
                  un_inc(a1, chr, fileptr);
                  break;
                }
                v45 = 16 * v19;
                chr = hextodec(chr);
              }
              else
              {
                if ( !isdigit((unsigned __int8)chr) )
                  goto LABEL_237;
                if ( v70 == 111 )
                {
                  if ( chr >= 56 )
                    goto LABEL_237;
                  v45 = 8 * v19;
                }
                else
                {
                  v45 = 10 * v19;
                }
              }
              ++v69;
              v19 = v45 + chr - 48;
              if ( v66 )
              {
                if ( !--v78 )
                  break;
              }
              ++v80;
              chr = inc(fileptr, a1);
            }
          }
          if ( v71 )
            v19 = -v19;
        }
        if ( v70 == 70 )
          v69 = 0;
        if ( !v69 )
          goto error_return_0;
        if ( !v76 )
        {
          ++v62;
          v15 = v64;
          goto assign_num;
        }
LABEL_250:
        ++v74;
        v5 = ++v65;
        goto LABEL_256;
      }
      if ( !v66 )
      {
        ++v78;
        v66 = 1;
      }
    }
    if ( v79 > 0 )
      v73 = 1;
    goto scanit;
  }
  if ( v17 == 99 || v17 == 123 )
  {
    ++v80;
    v18 = inc(fileptr, a1);
  }
  else
  {
    v18 = whiteout(&v80, a1, fileptr);
  }
  chr = v18;
  if ( v18 != -1 )
  {
    v15 = v64;
    v5 = v65;
    goto LABEL_69;
  }
error_return_0:
  if ( pmalloc_FloatStrFlag == 1 )
    free(pFloatStr);
  if ( chr == -1 )
  {
    result = v62;
    if ( !v62 && !v74 )
      result = -1;
    if ( v53.updated )
      v53.ptd->_ownlocale &= ~2u;
    return result;
  }
LABEL_273:
  if ( v53.updated )
    v53.ptd->_ownlocale &= ~2u;
  return v62;
}
