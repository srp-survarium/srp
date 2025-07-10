int __usercall _input_s_l@<eax>(
        int a1@<ebx>,
        _iobuf *stream,
        const unsigned __int8 *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  int p_pFloatStr; // edi
  int result; // eax
  int v7; // eax
  ioinfo *v8; // ecx
  ioinfo *v9; // eax
  unsigned __int8 v10; // al
  unsigned int v11; // eax
  unsigned __int8 *p_charcount; // esi
  int v13; // ebx
  unsigned __int8 v14; // cl
  unsigned __int8 *v15; // eax
  unsigned __int8 v16; // al
  int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  int i; // eax
  int j; // eax
  int k; // eax
  void (__cdecl *v29)(int, void *, char *, _LocaleUpdate *); // eax
  int v31; // eax
  const unsigned __int8 *v32; // esi
  unsigned __int8 v33; // dl
  unsigned __int8 v34; // cl
  unsigned __int8 v35; // al
  unsigned int v36; // edi
  int v37; // edx
  unsigned __int8 v38; // al
  int v39; // eax
  unsigned int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // ecx
  int *v44; // eax
  bool v45; // zf
  int v46; // [esp-14h] [ebp-21Ch]
  void *v47; // [esp-10h] [ebp-218h]
  char *v48; // [esp-Ch] [ebp-214h]
  _iobuf *v49; // [esp-8h] [ebp-210h]
  int v50; // [esp-8h] [ebp-210h]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-200h] BYREF
  int format_error; // [esp+18h] [ebp-1F0h]
  int wctemp; // [esp+1Ch] [ebp-1ECh] BYREF
  char *arglistsave; // [esp+20h] [ebp-1E8h]
  int comchr; // [esp+24h] [ebp-1E4h]
  char *v56; // [esp+28h] [ebp-1E0h]
  char temp[4]; // [esp+2Ch] [ebp-1DCh] BYREF
  unsigned int nFloatStrSz; // [esp+30h] [ebp-1D8h] BYREF
  unsigned __int8 prevchar; // [esp+37h] [ebp-1D1h]
  int malloc_FloatStrFlag; // [esp+38h] [ebp-1D0h] BYREF
  unsigned int array_width; // [esp+3Ch] [ebp-1CCh]
  unsigned int number; // [esp+40h] [ebp-1C8h]
  int count; // [esp+44h] [ebp-1C4h]
  int widthset; // [esp+48h] [ebp-1C0h]
  void *pointer; // [esp+4Ch] [ebp-1BCh]
  unsigned __int64 num64; // [esp+50h] [ebp-1B8h]
  int integer64; // [esp+58h] [ebp-1B0h]
  const unsigned __int8 *v68; // [esp+5Ch] [ebp-1ACh]
  int started; // [esp+60h] [ebp-1A8h]
  char *pFloatStr; // [esp+64h] [ebp-1A4h] BYREF
  char negative; // [esp+69h] [ebp-19Fh]
  char decimal; // [esp+6Ah] [ebp-19Eh]
  char match; // [esp+6Bh] [ebp-19Dh]
  _iobuf *fileptr; // [esp+6Ch] [ebp-19Ch]
  char fl_wchar_arg; // [esp+72h] [ebp-196h]
  char longone; // [esp+73h] [ebp-195h]
  int width; // [esp+74h] [ebp-194h]
  char suppress; // [esp+79h] [ebp-18Fh]
  char widechar; // [esp+7Ah] [ebp-18Eh]
  char done_flag; // [esp+7Bh] [ebp-18Dh]
  int charcount; // [esp+7Ch] [ebp-18Ch] BYREF
  int chr; // [esp+80h] [ebp-188h]
  char floatstring[352]; // [esp+84h] [ebp-184h] BYREF
  char AsciiTable[32]; // [esp+1E4h] [ebp-24h] BYREF

  p_pFloatStr = (int)format;
  v56 = arglist;
  fileptr = stream;
  v68 = format;
  pFloatStr = floatstring;
  nFloatStrSz = 350;
  malloc_FloatStrFlag = 0;
  wctemp = 0;
  chr = 0;
  format_error = 0;
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
    goto LABEL_291;
  while ( 2 )
  {
    if ( isspace(v10) )
    {
      v49 = fileptr;
      --charcount;
      v11 = whiteout(&charcount, a1, fileptr);
      un_inc(a1, v11, v49);
      p_charcount = (unsigned __int8 *)v68;
      do
        ++p_charcount;
      while ( isspace(*p_charcount) );
      v68 = p_charcount;
      goto LABEL_268;
    }
    p_charcount = (unsigned __int8 *)v68;
    if ( *v68 != 37 )
      goto LABEL_260;
    if ( v68[1] == 37 )
    {
      p_charcount = (unsigned __int8 *)(v68 + 1);
LABEL_260:
      p_pFloatStr = (int)fileptr;
      ++charcount;
      a1 = inc(fileptr, a1);
      v41 = *p_charcount++;
      chr = a1;
      v68 = p_charcount;
      if ( v41 == a1 )
      {
        if ( !isleadbyte(a1) )
          goto LABEL_264;
        ++charcount;
        v42 = inc((_iobuf *)p_pFloatStr, a1);
        v43 = *p_charcount++;
        v68 = p_charcount;
        if ( v43 == v42 )
        {
          --charcount;
          goto LABEL_264;
        }
        un_inc(a1, v42, (_iobuf *)p_pFloatStr);
        un_inc(a1, a1, (_iobuf *)p_pFloatStr);
      }
      else
      {
        un_inc(a1, a1, (_iobuf *)p_pFloatStr);
      }
      goto error_return_1;
    }
    number = 0;
    prevchar = 0;
    started = 0;
    widthset = 0;
    width = 0;
    array_width = 0;
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
      v13 = *++p_charcount;
      if ( isdigit((unsigned __int8)v13) )
      {
        ++widthset;
        width = 10 * width + v13 - 48;
        continue;
      }
      if ( v13 > 78 )
      {
        if ( v13 == 104 )
        {
          --longone;
          --widechar;
        }
        else
        {
          if ( v13 == 108 )
          {
            v15 = p_charcount + 1;
            if ( p_charcount[1] == 108 )
              goto LABEL_35;
            ++longone;
          }
          else if ( v13 != 119 )
          {
            goto DEFAULT_LABEL_0;
          }
          ++widechar;
        }
      }
      else
      {
        switch ( v13 )
        {
          case 'N':
            continue;
          case '*':
            ++suppress;
            continue;
          case 'F':
            continue;
        }
        if ( v13 != 73 )
        {
          if ( v13 == 76 )
          {
            ++longone;
            continue;
          }
DEFAULT_LABEL_0:
          ++done_flag;
          continue;
        }
        v14 = p_charcount[1];
        if ( v14 == 54 )
        {
          v15 = p_charcount + 2;
          if ( p_charcount[2] == 52 )
          {
LABEL_35:
            ++integer64;
            p_charcount = v15;
            num64 = 0;
            continue;
          }
        }
        if ( v14 == 51 && p_charcount[2] == 50 )
        {
          p_charcount += 2;
          continue;
        }
        if ( v14 != 100 && v14 != 105 && v14 != 111 && v14 != 120 && v14 != 88 )
          goto DEFAULT_LABEL_0;
      }
    }
    while ( !done_flag );
    v68 = p_charcount;
    if ( suppress )
    {
      a1 = 0;
    }
    else
    {
      a1 = *(_DWORD *)v56;
      arglistsave = v56;
      v56 += 4;
    }
    pointer = (void *)a1;
    done_flag = 0;
    if ( !widechar )
    {
      v16 = *p_charcount;
      if ( *p_charcount == 83 || (widechar = -1, v16 == 67) )
        widechar = 1;
    }
    p_pFloatStr = *p_charcount | 0x20;
    comchr = p_pFloatStr;
    if ( p_pFloatStr != 110 )
    {
      if ( p_pFloatStr == 99 || p_pFloatStr == 123 )
      {
        ++charcount;
        v17 = inc(fileptr, a1);
      }
      else
      {
        p_charcount = (unsigned __int8 *)&charcount;
        v17 = whiteout(&charcount, a1, fileptr);
      }
      chr = v17;
      if ( v17 == -1 )
        goto error_return_1;
      a1 = (int)pointer;
      p_charcount = (unsigned __int8 *)v68;
    }
    if ( widthset && !width )
    {
      un_inc(a1, chr, fileptr);
      goto error_return_1;
    }
    if ( !suppress && (p_pFloatStr == 99 || p_pFloatStr == 115 || p_pFloatStr == 123) )
    {
      a1 = *(_DWORD *)arglistsave;
      arglistsave += 4;
      v56 = arglistsave + 4;
      v18 = *(_DWORD *)arglistsave;
      pointer = (void *)a1;
      array_width = v18;
      if ( !v18 )
      {
        if ( widechar <= 0 )
          *(_BYTE *)a1 = 0;
        else
          *(_WORD *)a1 = 0;
        *_errno() = 12;
        goto error_return_1;
      }
    }
    if ( p_pFloatStr > 111 )
    {
      if ( p_pFloatStr == 112 )
      {
        longone = 1;
        goto LABEL_209;
      }
      if ( p_pFloatStr != 115 )
      {
        if ( p_pFloatStr == 117 )
          goto LABEL_209;
        if ( p_pFloatStr == 120 )
          goto LABEL_87;
        if ( p_pFloatStr != 123 )
          goto LABEL_155;
        if ( widechar > 0 )
          fl_wchar_arg = 1;
        v32 = p_charcount + 1;
        if ( *v32 == 94 )
        {
          ++v32;
          decimal = -1;
        }
        memset((int)AsciiTable, 0, sizeof(AsciiTable));
        if ( *v32 == 93 )
        {
          v33 = 93;
          ++v32;
          AsciiTable[11] = 32;
        }
        else
        {
          v33 = prevchar;
        }
        while ( 1 )
        {
          v38 = *v32;
          if ( *v32 == 93 )
            break;
          ++v32;
          if ( v38 == 45 && v33 && (v34 = *v32, *v32 != 93) )
          {
            ++v32;
            if ( v33 >= v34 )
            {
              v35 = v33;
              v33 = v34;
            }
            else
            {
              v35 = v34;
            }
            if ( v33 <= v35 )
            {
              v36 = v33;
              v37 = (unsigned __int8)(v35 - v33 + 1);
              do
              {
                AsciiTable[v36 >> 3] |= 1 << (v36 & 7);
                ++v36;
                --v37;
              }
              while ( v37 );
              p_pFloatStr = comchr;
            }
            v33 = 0;
          }
          else
          {
            p_pFloatStr = comchr;
            v33 = v38;
            AsciiTable[v38 >> 3] |= 1 << (v38 & 7);
          }
        }
        a1 = (int)pointer;
        v68 = v32;
scanit_0:
        p_charcount = (unsigned __int8 *)fileptr;
        --charcount;
        integer64 = a1;
        un_inc(a1, chr, fileptr);
        if ( p_pFloatStr == 99 )
        {
          while ( 1 )
          {
LABEL_134:
            if ( widthset )
            {
              if ( !width-- )
                goto LABEL_202;
            }
            ++charcount;
            v31 = inc((_iobuf *)p_charcount, a1);
            chr = v31;
            if ( v31 == -1 )
              goto LABEL_201;
            if ( p_pFloatStr != 99 )
            {
              if ( p_pFloatStr != 115 )
                goto LABEL_296;
              if ( v31 >= 9 && v31 <= 13 )
              {
LABEL_201:
                --charcount;
                un_inc(a1, v31, (_iobuf *)p_charcount);
LABEL_202:
                if ( integer64 != a1 )
                {
                  if ( !suppress )
                  {
                    ++count;
                    if ( p_pFloatStr != 99 )
                    {
                      if ( fl_wchar_arg )
                        *(_WORD *)pointer = 0;
                      else
                        *(_BYTE *)pointer = 0;
                    }
                  }
                  goto LABEL_258;
                }
                goto error_return_1;
              }
              if ( v31 == 32 )
              {
LABEL_296:
                if ( p_pFloatStr != 123 )
                  goto LABEL_201;
                p_pFloatStr = comchr;
                if ( ((1 << (v31 & 7)) & (decimal ^ AsciiTable[v31 >> 3])) == 0 )
                  goto LABEL_201;
              }
            }
            if ( !suppress )
              break;
            ++integer64;
          }
          if ( !array_width )
          {
            v44 = _errno();
            v45 = fl_wchar_arg == 0;
            *v44 = 12;
            if ( v45 )
              *(_BYTE *)integer64 = 0;
            else
              *(_WORD *)integer64 = 0;
            goto error_return_1;
          }
          if ( fl_wchar_arg )
          {
            temp[0] = v31;
            if ( isleadbyte(v31) )
            {
              ++charcount;
              temp[1] = inc((_iobuf *)p_charcount, a1);
            }
            wctemp = 63;
            _mbtowc_l((wchar_t *)&wctemp, temp, _loc_update.localeinfo.locinfo->mb_cur_max, &_loc_update.localeinfo);
            *(_WORD *)a1 = wctemp;
            a1 += 2;
          }
          else
          {
            *(_BYTE *)a1++ = v31;
          }
          pointer = (void *)a1;
        }
        --array_width;
        goto LABEL_134;
      }
LABEL_130:
      if ( widechar > 0 )
        fl_wchar_arg = 1;
      goto scanit_0;
    }
    if ( p_pFloatStr == 111 )
      goto LABEL_209;
    if ( p_pFloatStr == 99 )
    {
      if ( !widthset )
      {
        ++width;
        widthset = 1;
      }
      goto LABEL_130;
    }
    if ( p_pFloatStr != 100 )
    {
      if ( p_pFloatStr > 100 )
      {
        if ( p_pFloatStr > 103 )
        {
          if ( p_pFloatStr != 105 )
          {
            if ( p_pFloatStr == 110 )
            {
              v19 = charcount;
              if ( !suppress )
              {
assign_num_0:
                if ( integer64 )
                {
                  *(_QWORD *)a1 = num64;
                }
                else if ( longone )
                {
                  *(_DWORD *)a1 = v19;
                }
                else
                {
                  *(_WORD *)a1 = v19;
                }
              }
              goto LABEL_258;
            }
            goto LABEL_155;
          }
          p_pFloatStr = 100;
LABEL_87:
          if ( chr == 45 )
          {
            negative = 1;
            goto x_incwidth_0;
          }
          if ( chr == 43 )
          {
x_incwidth_0:
            if ( --width || !widthset )
            {
              ++charcount;
              chr = inc(fileptr, a1);
            }
            else
            {
              done_flag = 1;
            }
          }
          if ( chr == 48 )
          {
            ++charcount;
            v39 = inc(fileptr, a1);
            chr = v39;
            if ( (_BYTE)v39 == 120 || (_BYTE)v39 == 88 )
            {
              ++charcount;
              chr = inc(fileptr, a1);
              if ( widthset )
              {
                width -= 2;
                if ( width < 1 )
                  ++done_flag;
              }
              v50 = 120;
LABEL_197:
              p_pFloatStr = v50;
            }
            else
            {
              started = 1;
              if ( p_pFloatStr != 120 )
              {
                if ( widthset )
                {
                  if ( !--width )
                    ++done_flag;
                }
                v50 = 111;
                goto LABEL_197;
              }
              --charcount;
              un_inc(a1, chr, fileptr);
              chr = 48;
            }
          }
          goto getnum_0;
        }
        a1 = 0;
        if ( chr == 45 )
        {
          *pFloatStr = 45;
          a1 = 1;
          goto f_incwidth_0;
        }
        if ( chr == 43 )
        {
f_incwidth_0:
          --width;
          ++charcount;
          chr = inc(fileptr, a1);
        }
        if ( !widthset )
          width = -1;
        for ( i = (unsigned __int8)chr; isdigit(i); i = (unsigned __int8)chr )
        {
          if ( !width-- )
            break;
          ++started;
          pFloatStr[a1++] = chr;
          p_pFloatStr = (int)&pFloatStr;
          p_charcount = (unsigned __int8 *)&nFloatStrSz;
          if ( !_check_float_string(&nFloatStrSz, &pFloatStr, a1, floatstring, &malloc_FloatStrFlag) )
            goto error_return_1;
          ++charcount;
          chr = inc(fileptr, a1);
        }
        decimal = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
        if ( decimal == (_BYTE)chr )
        {
          if ( width-- )
          {
            ++charcount;
            chr = inc(fileptr, a1);
            pFloatStr[a1++] = decimal;
            p_pFloatStr = (int)&pFloatStr;
            p_charcount = (unsigned __int8 *)&nFloatStrSz;
            if ( !_check_float_string(&nFloatStrSz, &pFloatStr, a1, floatstring, &malloc_FloatStrFlag) )
              goto error_return_1;
            for ( j = (unsigned __int8)chr; isdigit(j); j = (unsigned __int8)chr )
            {
              if ( !width-- )
                break;
              ++started;
              pFloatStr[a1++] = chr;
              p_pFloatStr = (int)&pFloatStr;
              p_charcount = (unsigned __int8 *)&nFloatStrSz;
              if ( !_check_float_string(&nFloatStrSz, &pFloatStr, a1, floatstring, &malloc_FloatStrFlag) )
                goto error_return_1;
              ++charcount;
              chr = inc(fileptr, a1);
            }
          }
        }
        if ( started && (chr == 101 || chr == 69) )
        {
          if ( width-- )
          {
            pFloatStr[a1++] = 101;
            p_pFloatStr = (int)&pFloatStr;
            p_charcount = (unsigned __int8 *)&nFloatStrSz;
            if ( !_check_float_string(&nFloatStrSz, &pFloatStr, a1, floatstring, &malloc_FloatStrFlag) )
              goto error_return_1;
            ++charcount;
            chr = inc(fileptr, a1);
            if ( chr == 45 )
            {
              pFloatStr[a1] = 45;
              if ( !_check_float_string(&nFloatStrSz, &pFloatStr, ++a1, floatstring, &malloc_FloatStrFlag) )
                goto error_return_1;
f_incwidth2_0:
              if ( width-- )
              {
                ++charcount;
                chr = inc(fileptr, a1);
              }
              else
              {
                width = 0;
              }
            }
            else if ( chr == 43 )
            {
              goto f_incwidth2_0;
            }
            for ( k = (unsigned __int8)chr; isdigit(k); k = (unsigned __int8)chr )
            {
              if ( !width-- )
                break;
              ++started;
              pFloatStr[a1++] = chr;
              p_pFloatStr = (int)&pFloatStr;
              p_charcount = (unsigned __int8 *)&nFloatStrSz;
              if ( !_check_float_string(&nFloatStrSz, &pFloatStr, a1, floatstring, &malloc_FloatStrFlag) )
                goto error_return_1;
              ++charcount;
              chr = inc(fileptr, a1);
            }
          }
        }
        --charcount;
        un_inc(a1, chr, fileptr);
        if ( started )
        {
          if ( !suppress )
          {
            ++count;
            v48 = pFloatStr;
            v47 = pointer;
            pFloatStr[a1] = 0;
            v46 = longone - 1;
            v29 = (void (__cdecl *)(int, void *, char *, _LocaleUpdate *))_decode_pointer(off_9AEB34);
            v29(v46, v47, v48, &_loc_update);
          }
          goto LABEL_258;
        }
        goto error_return_1;
      }
LABEL_155:
      if ( *p_charcount == chr )
      {
        --match;
        if ( !suppress )
          v56 = arglistsave;
        goto LABEL_258;
      }
      un_inc(a1, chr, fileptr);
      format_error = 1;
      goto error_return_1;
    }
LABEL_209:
    if ( chr == 45 )
    {
      negative = 1;
    }
    else if ( chr != 43 )
    {
      goto getnum_0;
    }
    if ( --width || !widthset )
    {
      ++charcount;
      chr = inc(fileptr, a1);
    }
    else
    {
      done_flag = 1;
    }
getnum_0:
    if ( integer64 )
    {
      if ( !done_flag )
      {
        while ( 1 )
        {
          if ( p_pFloatStr == 120 || p_pFloatStr == 112 )
          {
            if ( !isxdigit((unsigned __int8)chr) )
            {
LABEL_230:
              --charcount;
              un_inc(a1, chr, fileptr);
              break;
            }
            num64 *= 16LL;
            chr = hextodec(chr);
          }
          else
          {
            if ( !isdigit((unsigned __int8)chr) )
              goto LABEL_230;
            if ( p_pFloatStr == 111 )
            {
              if ( chr >= 56 )
                goto LABEL_230;
              num64 *= 8LL;
            }
            else
            {
              num64 *= 10LL;
            }
          }
          ++started;
          num64 += chr - 48;
          if ( widthset )
          {
            if ( !--width )
              break;
          }
          ++charcount;
          chr = inc(fileptr, a1);
        }
      }
      if ( negative )
        num64 = -(__int64)num64;
LABEL_233:
      v19 = number;
      goto LABEL_234;
    }
    if ( done_flag )
      goto LABEL_253;
    while ( 2 )
    {
      if ( p_pFloatStr != 120 && p_pFloatStr != 112 )
      {
        if ( !isdigit((unsigned __int8)chr) )
          break;
        if ( p_pFloatStr == 111 )
        {
          if ( chr >= 56 )
            break;
          v40 = 8 * number;
        }
        else
        {
          v40 = 10 * number;
        }
        goto LABEL_249;
      }
      if ( isxdigit((unsigned __int8)chr) )
      {
        number *= 16;
        chr = hextodec(chr);
        v40 = number;
LABEL_249:
        ++started;
        number = v40 + chr - 48;
        if ( widthset )
        {
          if ( !--width )
            goto LABEL_253;
        }
        ++charcount;
        chr = inc(fileptr, a1);
        continue;
      }
      break;
    }
    --charcount;
    un_inc(a1, chr, fileptr);
LABEL_253:
    if ( !negative )
      goto LABEL_233;
    v19 = -number;
LABEL_234:
    if ( !started )
      goto error_return_1;
    if ( !suppress )
    {
      ++count;
      a1 = (int)pointer;
      goto assign_num_0;
    }
LABEL_258:
    ++match;
    p_charcount = (unsigned __int8 *)++v68;
LABEL_264:
    if ( chr != -1 )
    {
LABEL_268:
      v10 = *p_charcount;
      if ( !*p_charcount )
        goto error_return_1;
      continue;
    }
    break;
  }
  if ( *p_charcount == 37 && v68[1] == 110 )
  {
    p_charcount = (unsigned __int8 *)v68;
    goto LABEL_268;
  }
error_return_1:
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
  if ( format_error == 1 )
  {
    *_errno() = 22;
    _invalid_parameter(a1, p_pFloatStr, (unsigned int)p_charcount);
  }
LABEL_291:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return count;
}
