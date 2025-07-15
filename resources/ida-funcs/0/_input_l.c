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
  void (__cdecl *v29)(int, void *, char *, _LocaleUpdate *); // eax
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
  unsigned __int64 v42; // kr00_8
  unsigned int v43; // edi
  unsigned int v44; // esi
  int v45; // edi
  int v46; // eax
  int v47; // eax
  int v48; // ecx
  int v49; // [esp-14h] [ebp-218h]
  void *v50; // [esp-10h] [ebp-214h]
  char *v51; // [esp-Ch] [ebp-210h]
  char *arglistsave; // [esp+8h] [ebp-1FCh]
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-1F8h] BYREF
  int wctemp; // [esp+1Ch] [ebp-1E8h] BYREF
  char *v55; // [esp+20h] [ebp-1E4h]
  char temp[4]; // [esp+24h] [ebp-1E0h] BYREF
  unsigned int nFloatStrSz; // [esp+28h] [ebp-1DCh] BYREF
  int integer64; // [esp+2Ch] [ebp-1D8h]
  unsigned __int8 prevchar; // [esp+33h] [ebp-1D1h]
  int malloc_FloatStrFlag; // [esp+34h] [ebp-1D0h] BYREF
  unsigned __int64 num64; // [esp+38h] [ebp-1CCh]
  int count; // [esp+40h] [ebp-1C4h]
  void *start; // [esp+44h] [ebp-1C0h]
  void *pointer; // [esp+48h] [ebp-1BCh]
  const unsigned __int8 *v65; // [esp+4Ch] [ebp-1B8h]
  int widthset; // [esp+50h] [ebp-1B4h]
  char done_flag; // [esp+57h] [ebp-1ADh]
  char *pFloatStr; // [esp+58h] [ebp-1ACh] BYREF
  int started; // [esp+5Ch] [ebp-1A8h]
  int comchr; // [esp+60h] [ebp-1A4h]
  char negative; // [esp+64h] [ebp-1A0h]
  char decimal; // [esp+65h] [ebp-19Fh]
  char fl_wchar_arg; // [esp+66h] [ebp-19Eh]
  char match; // [esp+67h] [ebp-19Dh]
  _iobuf *fileptr; // [esp+68h] [ebp-19Ch]
  char suppress; // [esp+6Eh] [ebp-196h]
  char longone; // [esp+6Fh] [ebp-195h]
  int width; // [esp+70h] [ebp-194h]
  char widechar; // [esp+77h] [ebp-18Dh]
  int charcount; // [esp+78h] [ebp-18Ch] BYREF
  int chr; // [esp+7Ch] [ebp-188h]
  char floatstring[352]; // [esp+80h] [ebp-184h] BYREF
  char AsciiTable[32]; // [esp+1E0h] [ebp-24h] BYREF

  v5 = format;
  v55 = arglist;
  fileptr = stream;
  pFloatStr = floatstring;
  nFloatStrSz = 350;
  malloc_FloatStrFlag = 0;
  wctemp = 0;
  chr = 0;
  if ( !format
    || !stream
    || (stream->_flag & 0x40) == 0
    && ((v7 = _fileno(a1, (unsigned int)format, stream), v7 == -1) || v7 == -2
      ? (v8 = &__badioinfo)
      : (a1 = v7 >> 5, v8 = (ioinfo *)((char *)__pioinfo[v7 >> 5] + 64 * (v7 & 0x1F))),
        (*((_BYTE *)v8 + 36) & 0x7F) != 0
     || (v7 == -1 || v7 == -2 ? (v9 = &__badioinfo) : (v9 = (ioinfo *)((char *)__pioinfo[v7 >> 5] + 64 * (v7 & 0x1F))),
         *((char *)v9 + 36) < 0)) )
  {
    *_errno() = 22;
    _invalid_parameter(a1, (unsigned int)format, 0);
    return -1;
  }
  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  v10 = *format;
  match = 0;
  charcount = 0;
  count = 0;
  if ( !v10 )
    goto LABEL_273;
  while ( 1 )
  {
    v11 = fileptr;
    if ( isspace(v10) )
    {
      --charcount;
      v12 = whiteout(&charcount, v11);
      un_inc(a1, v12, v11);
      do
        ++v5;
      while ( isspace(*v5) );
      goto LABEL_260;
    }
    if ( *v5 == 37 )
      break;
LABEL_252:
    ++charcount;
    a1 = inc(v11);
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
      ++charcount;
      v47 = inc(v11);
      v48 = *v5++;
      v65 = v5;
      if ( v48 != v47 )
      {
        un_inc(a1, v47, v11);
        un_inc(a1, a1, v11);
        goto error_return_0;
      }
      --charcount;
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
  start = 0;
  prevchar = 0;
  started = 0;
  widthset = 0;
  width = 0;
  decimal = 0;
  negative = 0;
  suppress = 0;
  done_flag = 0;
  fl_wchar_arg = 0;
  widechar = 0;
  longone = 1;
  integer64 = 0;
  do
  {
    a1 = *++v5;
    if ( isdigit((unsigned __int8)a1) )
    {
      ++widthset;
      width = 10 * width + a1 - 48;
      continue;
    }
    if ( a1 > 78 )
    {
      if ( a1 == 104 )
      {
        --longone;
        --widechar;
      }
      else
      {
        if ( a1 == 108 )
        {
          v14 = v5 + 1;
          if ( v5[1] == 108 )
            goto LABEL_35;
          ++longone;
        }
        else if ( a1 != 119 )
        {
          goto DEFAULT_LABEL;
        }
        ++widechar;
      }
    }
    else
    {
      switch ( a1 )
      {
        case 'N':
          continue;
        case '*':
          ++suppress;
          continue;
        case 'F':
          continue;
      }
      if ( a1 != 73 )
      {
        if ( a1 == 76 )
        {
          ++longone;
          continue;
        }
DEFAULT_LABEL:
        ++done_flag;
        continue;
      }
      v13 = v5[1];
      if ( v13 == 54 )
      {
        v14 = v5 + 2;
        if ( v5[2] == 52 )
        {
LABEL_35:
          ++integer64;
          v5 = v14;
          num64 = 0;
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
  while ( !done_flag );
  v65 = v5;
  if ( suppress )
  {
    v15 = 0;
  }
  else
  {
    v15 = *(_WORD **)v55;
    arglistsave = v55;
    v55 += 4;
  }
  LOBYTE(a1) = 0;
  pointer = v15;
  if ( !widechar )
  {
    v16 = *v5;
    if ( *v5 == 83 || (widechar = -1, v16 == 67) )
      widechar = 1;
  }
  v17 = *v5 | 0x20;
  comchr = v17;
  if ( v17 == 110 )
  {
LABEL_69:
    if ( widthset && !width )
      goto LABEL_262;
    if ( comchr > 111 )
    {
      if ( comchr == 112 )
      {
        longone = 1;
        goto LABEL_200;
      }
      if ( comchr != 115 )
      {
        if ( comchr == 117 )
          goto LABEL_200;
        if ( comchr == 120 )
          goto LABEL_82;
        if ( comchr != 123 )
          goto LABEL_148;
        if ( widechar > 0 )
          fl_wchar_arg = 1;
        v33 = (unsigned __int8 *)(v5 + 1);
        v34 = v33;
        if ( *v33 == 94 )
        {
          v34 = v33 + 1;
          decimal = -1;
        }
        memset((int)AsciiTable, 0, sizeof(AsciiTable));
        if ( *v34 == 93 )
        {
          v35 = 93;
          ++v34;
          AsciiTable[11] = 32;
        }
        else
        {
          v35 = prevchar;
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
                AsciiTable[v38++ >> 3] |= a1;
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
            AsciiTable[v40 >> 3] |= a1;
          }
        }
        v65 = v34;
        v15 = pointer;
scanit:
        v30 = fileptr;
        --charcount;
        start = v15;
        un_inc(a1, chr, fileptr);
        while ( 1 )
        {
          if ( widthset )
          {
            if ( !width-- )
              break;
          }
          ++charcount;
          v32 = inc(v30);
          chr = v32;
          if ( v32 == -1 )
            goto LABEL_192;
          if ( comchr != 99 )
          {
            if ( comchr != 115 )
              goto LABEL_278;
            if ( v32 >= 9 && v32 <= 13 )
            {
LABEL_192:
              --charcount;
              un_inc(a1, v32, v30);
              break;
            }
            if ( v32 == 32 )
            {
LABEL_278:
              if ( comchr != 123 )
                goto LABEL_192;
              a1 = decimal;
              if ( ((1 << (v32 & 7)) & (decimal ^ AsciiTable[v32 >> 3])) == 0 )
                goto LABEL_192;
            }
          }
          if ( suppress )
          {
            start = (char *)start + 1;
          }
          else
          {
            if ( fl_wchar_arg )
            {
              temp[0] = v32;
              if ( isleadbyte(v32) )
              {
                ++charcount;
                temp[1] = inc(v30);
              }
              wctemp = 63;
              _mbtowc_l((wchar_t *)&wctemp, temp, _loc_update.localeinfo.locinfo->mb_cur_max, &_loc_update.localeinfo);
              *v15++ = wctemp;
            }
            else
            {
              *(_BYTE *)v15 = v32;
              v15 = (_WORD *)((char *)v15 + 1);
            }
            pointer = v15;
          }
        }
        if ( start == v15 )
          goto error_return_0;
        if ( !suppress )
        {
          ++count;
          if ( comchr != 99 )
          {
            if ( fl_wchar_arg )
              *(_WORD *)pointer = 0;
            else
              *(_BYTE *)pointer = 0;
          }
        }
        goto LABEL_250;
      }
    }
    else
    {
      if ( comchr == 111 )
        goto LABEL_200;
      if ( comchr != 99 )
      {
        if ( comchr != 100 )
        {
          if ( comchr > 100 )
          {
            if ( comchr > 103 )
            {
              if ( comchr != 105 )
              {
                if ( comchr == 110 )
                {
                  v19 = charcount;
                  if ( suppress )
                    goto LABEL_250;
assign_num:
                  if ( integer64 )
                  {
                    *(_QWORD *)v15 = num64;
                  }
                  else if ( longone )
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
              comchr = 100;
LABEL_82:
              if ( chr == 45 )
              {
                negative = 1;
              }
              else if ( chr != 43 )
              {
                goto LABEL_176;
              }
              if ( --width || !widthset )
              {
                ++charcount;
                chr = inc(fileptr);
              }
              else
              {
                LOBYTE(a1) = 1;
              }
LABEL_176:
              if ( chr == 48 )
              {
                ++charcount;
                v41 = inc(fileptr);
                chr = v41;
                if ( (_BYTE)v41 == 120 || (_BYTE)v41 == 88 )
                {
                  ++charcount;
                  chr = inc(fileptr);
                  if ( widthset )
                  {
                    width -= 2;
                    if ( width < 1 )
                      LOBYTE(a1) = a1 + 1;
                  }
                  comchr = 120;
                }
                else
                {
                  started = 1;
                  if ( comchr == 120 )
                  {
                    --charcount;
                    un_inc(a1, v41, fileptr);
                    chr = 48;
                  }
                  else
                  {
                    if ( widthset )
                    {
                      if ( !--width )
                        LOBYTE(a1) = a1 + 1;
                    }
                    comchr = 111;
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
              if ( !widthset )
                width = -1;
              for ( i = (unsigned __int8)chr; isdigit(i); i = (unsigned __int8)chr )
              {
                if ( !width-- )
                  break;
                ++started;
                pFloatStr[a1] = chr;
                if ( !_check_float_string(++a1, &nFloatStrSz, &pFloatStr, floatstring, &malloc_FloatStrFlag) )
                  goto error_return_0;
                ++charcount;
                chr = inc(fileptr);
              }
              decimal = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
              if ( decimal == (_BYTE)chr )
              {
                if ( width-- )
                {
                  ++charcount;
                  chr = inc(fileptr);
                  pFloatStr[a1] = decimal;
                  if ( !_check_float_string(++a1, &nFloatStrSz, &pFloatStr, floatstring, &malloc_FloatStrFlag) )
                    goto error_return_0;
                  for ( j = (unsigned __int8)chr; isdigit(j); j = (unsigned __int8)chr )
                  {
                    if ( !width-- )
                      break;
                    ++started;
                    pFloatStr[a1] = chr;
                    if ( !_check_float_string(++a1, &nFloatStrSz, &pFloatStr, floatstring, &malloc_FloatStrFlag) )
                      goto error_return_0;
                    ++charcount;
                    chr = inc(fileptr);
                  }
                }
              }
              if ( !started || chr != 101 && chr != 69 )
                goto LABEL_120;
              if ( !width-- )
                goto LABEL_120;
              pFloatStr[a1] = 101;
              if ( !_check_float_string(++a1, &nFloatStrSz, &pFloatStr, floatstring, &malloc_FloatStrFlag) )
                goto error_return_0;
              ++charcount;
              chr = inc(fileptr);
              if ( chr == 45 )
              {
                pFloatStr[a1] = 45;
                if ( !_check_float_string(++a1, &nFloatStrSz, &pFloatStr, floatstring, &malloc_FloatStrFlag) )
                  goto error_return_0;
              }
              else if ( chr != 43 )
              {
                goto LABEL_115;
              }
              if ( width-- )
              {
                ++charcount;
                chr = inc(fileptr);
              }
              else
              {
                width = 0;
              }
LABEL_115:
              for ( k = (unsigned __int8)chr; isdigit(k); k = (unsigned __int8)chr )
              {
                if ( !width-- )
                  break;
                ++started;
                pFloatStr[a1] = chr;
                if ( !_check_float_string(++a1, &nFloatStrSz, &pFloatStr, floatstring, &malloc_FloatStrFlag) )
                  goto error_return_0;
                ++charcount;
                chr = inc(fileptr);
              }
LABEL_120:
              --charcount;
              un_inc(a1, chr, fileptr);
              if ( !started )
                goto error_return_0;
              if ( !suppress )
              {
                ++count;
                v51 = pFloatStr;
                v50 = pointer;
                pFloatStr[a1] = 0;
                v49 = longone - 1;
                v29 = (void (__cdecl *)(int, void *, char *, _LocaleUpdate *))_decode_pointer(off_9AEB34);
                v29(v49, v50, v51, &_loc_update);
              }
              goto LABEL_250;
            }
            --width;
            ++charcount;
            chr = inc(fileptr);
            goto LABEL_88;
          }
LABEL_148:
          if ( *v5 == chr )
          {
            --match;
            if ( !suppress )
              v55 = arglistsave;
            goto LABEL_250;
          }
LABEL_262:
          un_inc(a1, chr, fileptr);
          goto error_return_0;
        }
LABEL_200:
        if ( chr == 45 )
        {
          negative = 1;
        }
        else if ( chr != 43 )
        {
          goto getnum;
        }
        if ( --width || !widthset )
        {
          ++charcount;
          chr = inc(fileptr);
        }
        else
        {
          LOBYTE(a1) = 1;
        }
getnum:
        if ( integer64 )
        {
          if ( !(_BYTE)a1 )
          {
            while ( 1 )
            {
              if ( comchr == 120 || comchr == 112 )
              {
                if ( !isxdigit((unsigned __int8)chr) )
                {
LABEL_221:
                  --charcount;
                  un_inc(a1, chr, fileptr);
                  break;
                }
                v43 = num64 >> 28;
                v44 = 16 * num64;
                chr = hextodec(chr);
                v42 = __PAIR64__(v43, v44);
              }
              else
              {
                if ( !isdigit((unsigned __int8)chr) )
                  goto LABEL_221;
                if ( comchr == 111 )
                {
                  if ( chr >= 56 )
                    goto LABEL_221;
                  v42 = 8 * num64;
                }
                else
                {
                  v42 = 10 * num64;
                }
              }
              ++started;
              num64 = chr - 48 + v42;
              if ( widthset )
              {
                if ( !--width )
                  break;
              }
              ++charcount;
              chr = inc(fileptr);
            }
          }
          v19 = (int)start;
          if ( negative )
            num64 = -(__int64)num64;
        }
        else
        {
          v19 = (int)start;
          if ( !(_BYTE)a1 )
          {
            while ( 1 )
            {
              if ( comchr == 120 || comchr == 112 )
              {
                if ( !isxdigit((unsigned __int8)chr) )
                {
LABEL_237:
                  --charcount;
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
                if ( comchr == 111 )
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
              ++started;
              v19 = v45 + chr - 48;
              if ( widthset )
              {
                if ( !--width )
                  break;
              }
              ++charcount;
              chr = inc(fileptr);
            }
          }
          if ( negative )
            v19 = -v19;
        }
        if ( comchr == 70 )
          started = 0;
        if ( !started )
          goto error_return_0;
        if ( !suppress )
        {
          ++count;
          v15 = pointer;
          goto assign_num;
        }
LABEL_250:
        ++match;
        v5 = ++v65;
        goto LABEL_256;
      }
      if ( !widthset )
      {
        ++width;
        widthset = 1;
      }
    }
    if ( widechar > 0 )
      fl_wchar_arg = 1;
    goto scanit;
  }
  if ( v17 == 99 || v17 == 123 )
  {
    ++charcount;
    v18 = inc(fileptr);
  }
  else
  {
    v18 = whiteout(&charcount, fileptr);
  }
  chr = v18;
  if ( v18 != -1 )
  {
    v15 = pointer;
    v5 = v65;
    goto LABEL_69;
  }
error_return_0:
  if ( malloc_FloatStrFlag == 1 )
    free(pFloatStr);
  if ( chr == -1 )
  {
    result = count;
    if ( !count && !match )
      result = -1;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
LABEL_273:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return count;
}
