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
  int v11; // eax
  unsigned int *p_pnFloatStrSz; // esi
  int v13; // ebx
  char v14; // cl
  unsigned int *v15; // eax
  unsigned __int8 v16; // al
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int i; // eax
  int j; // eax
  int k; // eax
  void (__cdecl *v29)(int, _WORD *, char *, _LocaleUpdate *); // eax
  int v31; // eax
  const unsigned __int8 *v32; // esi
  unsigned __int8 v33; // dl
  unsigned __int8 v34; // cl
  unsigned __int8 v35; // al
  unsigned int v36; // edi
  int v37; // edx
  unsigned __int8 v38; // al
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // ecx
  int *v44; // eax
  bool v45; // zf
  int v46; // [esp-14h] [ebp-21Ch]
  _WORD *v47; // [esp-10h] [ebp-218h]
  char *v48; // [esp-Ch] [ebp-214h]
  _iobuf *v49; // [esp-8h] [ebp-210h]
  int v50; // [esp-8h] [ebp-210h]
  _LocaleUpdate v51; // [esp+8h] [ebp-200h] BYREF
  int v52; // [esp+18h] [ebp-1F0h]
  wchar_t pwc[2]; // [esp+1Ch] [ebp-1ECh] BYREF
  int *v54; // [esp+20h] [ebp-1E8h]
  int v55; // [esp+24h] [ebp-1E4h]
  int *v56; // [esp+28h] [ebp-1E0h]
  char s[4]; // [esp+2Ch] [ebp-1DCh] BYREF
  unsigned int pnFloatStrSz; // [esp+30h] [ebp-1D8h] BYREF
  unsigned __int8 v59; // [esp+37h] [ebp-1D1h]
  int pmalloc_FloatStrFlag; // [esp+38h] [ebp-1D0h] BYREF
  int v61; // [esp+3Ch] [ebp-1CCh]
  int v62; // [esp+40h] [ebp-1C8h]
  int v63; // [esp+44h] [ebp-1C4h]
  int v64; // [esp+48h] [ebp-1C0h]
  _WORD *v65; // [esp+4Ch] [ebp-1BCh]
  __int64 v66; // [esp+50h] [ebp-1B8h]
  _BYTE *v67; // [esp+58h] [ebp-1B0h]
  const unsigned __int8 *v68; // [esp+5Ch] [ebp-1ACh]
  int v69; // [esp+60h] [ebp-1A8h]
  char *pFloatStr; // [esp+64h] [ebp-1A4h] BYREF
  char v71; // [esp+69h] [ebp-19Fh]
  char v72; // [esp+6Ah] [ebp-19Eh]
  char v73; // [esp+6Bh] [ebp-19Dh]
  _iobuf *v74; // [esp+6Ch] [ebp-19Ch]
  char v75; // [esp+72h] [ebp-196h]
  char v76; // [esp+73h] [ebp-195h]
  int v77; // [esp+74h] [ebp-194h]
  char v78; // [esp+79h] [ebp-18Fh]
  char v79; // [esp+7Ah] [ebp-18Eh]
  char v80; // [esp+7Bh] [ebp-18Dh]
  int v81; // [esp+7Ch] [ebp-18Ch] BYREF
  int v82; // [esp+80h] [ebp-188h]
  char floatstring[352]; // [esp+84h] [ebp-184h] BYREF
  _BYTE v84[32]; // [esp+1E4h] [ebp-24h] BYREF

  p_pFloatStr = (int)format;
  v56 = (int *)arglist;
  v74 = stream;
  v68 = format;
  pFloatStr = floatstring;
  pnFloatStrSz = 350;
  pmalloc_FloatStrFlag = 0;
  *(_DWORD *)pwc = 0;
  v82 = 0;
  v52 = 0;
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
  _LocaleUpdate::_LocaleUpdate(&v51, plocinfo);
  v10 = *format;
  v73 = 0;
  v81 = 0;
  v63 = 0;
  if ( !v10 )
    goto LABEL_291;
  while ( 2 )
  {
    if ( isspace(v10) )
    {
      v49 = v74;
      --v81;
      v11 = whiteout(&v81, a1, v74);
      un_inc(a1, p_pFloatStr, v11, v49);
      p_pnFloatStrSz = (unsigned int *)v68;
      do
        p_pnFloatStrSz = (unsigned int *)((char *)p_pnFloatStrSz + 1);
      while ( isspace(*(unsigned __int8 *)p_pnFloatStrSz) );
      v68 = (const unsigned __int8 *)p_pnFloatStrSz;
      goto LABEL_268;
    }
    p_pnFloatStrSz = (unsigned int *)v68;
    if ( *v68 != 37 )
      goto LABEL_260;
    if ( v68[1] == 37 )
    {
      p_pnFloatStrSz = (unsigned int *)(v68 + 1);
LABEL_260:
      p_pFloatStr = (int)v74;
      ++v81;
      a1 = inc(v74, a1);
      v41 = *(unsigned __int8 *)p_pnFloatStrSz;
      p_pnFloatStrSz = (unsigned int *)((char *)p_pnFloatStrSz + 1);
      v82 = a1;
      v68 = (const unsigned __int8 *)p_pnFloatStrSz;
      if ( v41 == a1 )
      {
        if ( !isleadbyte(a1) )
          goto LABEL_264;
        ++v81;
        v42 = inc((_iobuf *)p_pFloatStr, a1);
        v43 = *(unsigned __int8 *)p_pnFloatStrSz;
        p_pnFloatStrSz = (unsigned int *)((char *)p_pnFloatStrSz + 1);
        v68 = (const unsigned __int8 *)p_pnFloatStrSz;
        if ( v43 == v42 )
        {
          --v81;
          goto LABEL_264;
        }
        un_inc(a1, p_pFloatStr, v42, (_iobuf *)p_pFloatStr);
        un_inc(a1, p_pFloatStr, a1, (_iobuf *)p_pFloatStr);
      }
      else
      {
        un_inc(a1, p_pFloatStr, a1, (_iobuf *)p_pFloatStr);
      }
      goto error_return_1;
    }
    v62 = 0;
    v59 = 0;
    v69 = 0;
    v64 = 0;
    v77 = 0;
    v61 = 0;
    v72 = 0;
    v71 = 0;
    v78 = 0;
    v80 = 0;
    v75 = 0;
    v79 = 0;
    v76 = 1;
    v67 = 0;
    do
    {
      p_pnFloatStrSz = (unsigned int *)((char *)p_pnFloatStrSz + 1);
      v13 = *(unsigned __int8 *)p_pnFloatStrSz;
      if ( isdigit((unsigned __int8)v13) )
      {
        ++v64;
        v77 = 10 * v77 + v13 - 48;
        continue;
      }
      if ( v13 > 78 )
      {
        if ( v13 == 104 )
        {
          --v76;
          --v79;
        }
        else
        {
          if ( v13 == 108 )
          {
            v15 = (unsigned int *)((char *)p_pnFloatStrSz + 1);
            if ( *((_BYTE *)p_pnFloatStrSz + 1) == 108 )
              goto LABEL_35;
            ++v76;
          }
          else if ( v13 != 119 )
          {
            goto DEFAULT_LABEL_0;
          }
          ++v79;
        }
      }
      else
      {
        switch ( v13 )
        {
          case 'N':
            continue;
          case '*':
            ++v78;
            continue;
          case 'F':
            continue;
        }
        if ( v13 != 73 )
        {
          if ( v13 == 76 )
          {
            ++v76;
            continue;
          }
DEFAULT_LABEL_0:
          ++v80;
          continue;
        }
        v14 = *((_BYTE *)p_pnFloatStrSz + 1);
        if ( v14 == 54 )
        {
          v15 = (unsigned int *)((char *)p_pnFloatStrSz + 2);
          if ( *((_BYTE *)p_pnFloatStrSz + 2) == 52 )
          {
LABEL_35:
            ++v67;
            p_pnFloatStrSz = v15;
            v66 = 0;
            continue;
          }
        }
        if ( v14 == 51 && *((_BYTE *)p_pnFloatStrSz + 2) == 50 )
        {
          p_pnFloatStrSz = (unsigned int *)((char *)p_pnFloatStrSz + 2);
          continue;
        }
        if ( v14 != 100 && v14 != 105 && v14 != 111 && v14 != 120 && v14 != 88 )
          goto DEFAULT_LABEL_0;
      }
    }
    while ( !v80 );
    v68 = (const unsigned __int8 *)p_pnFloatStrSz;
    if ( v78 )
    {
      a1 = 0;
    }
    else
    {
      a1 = *v56;
      v54 = v56++;
    }
    v65 = (_WORD *)a1;
    v80 = 0;
    if ( !v79 )
    {
      v16 = *(_BYTE *)p_pnFloatStrSz;
      if ( *(_BYTE *)p_pnFloatStrSz == 83 || (v79 = -1, v16 == 67) )
        v79 = 1;
    }
    p_pFloatStr = *(unsigned __int8 *)p_pnFloatStrSz | 0x20;
    v55 = p_pFloatStr;
    if ( p_pFloatStr != 110 )
    {
      if ( p_pFloatStr == 99 || p_pFloatStr == 123 )
      {
        ++v81;
        v17 = inc(v74, a1);
      }
      else
      {
        p_pnFloatStrSz = (unsigned int *)&v81;
        v17 = whiteout(&v81, a1, v74);
      }
      v82 = v17;
      if ( v17 == -1 )
        goto error_return_1;
      a1 = (int)v65;
      p_pnFloatStrSz = (unsigned int *)v68;
    }
    if ( v64 && !v77 )
    {
      un_inc(a1, p_pFloatStr, v82, v74);
      goto error_return_1;
    }
    if ( !v78 && (p_pFloatStr == 99 || p_pFloatStr == 115 || p_pFloatStr == 123) )
    {
      a1 = *v54++;
      v56 = v54 + 1;
      v18 = *v54;
      v65 = (_WORD *)a1;
      v61 = v18;
      if ( !v18 )
      {
        if ( v79 <= 0 )
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
        v76 = 1;
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
        if ( v79 > 0 )
          v75 = 1;
        v32 = (const unsigned __int8 *)p_pnFloatStrSz + 1;
        if ( *v32 == 94 )
        {
          ++v32;
          v72 = -1;
        }
        memset((int)v84, 0, sizeof(v84));
        if ( *v32 == 93 )
        {
          v33 = 93;
          ++v32;
          v84[11] = 32;
        }
        else
        {
          v33 = v59;
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
                v84[v36 >> 3] |= 1 << (v36 & 7);
                ++v36;
                --v37;
              }
              while ( v37 );
              p_pFloatStr = v55;
            }
            v33 = 0;
          }
          else
          {
            p_pFloatStr = v55;
            v33 = v38;
            v84[v38 >> 3] |= 1 << (v38 & 7);
          }
        }
        a1 = (int)v65;
        v68 = v32;
scanit_0:
        p_pnFloatStrSz = (unsigned int *)v74;
        --v81;
        v67 = (_BYTE *)a1;
        un_inc(a1, p_pFloatStr, v82, v74);
        if ( p_pFloatStr == 99 )
        {
          while ( 1 )
          {
LABEL_134:
            if ( v64 )
            {
              if ( !v77-- )
                goto LABEL_202;
            }
            ++v81;
            v31 = inc((_iobuf *)p_pnFloatStrSz, a1);
            v82 = v31;
            if ( v31 == -1 )
              goto LABEL_201;
            if ( p_pFloatStr != 99 )
            {
              if ( p_pFloatStr != 115 )
                goto LABEL_296;
              if ( v31 >= 9 && v31 <= 13 )
              {
LABEL_201:
                --v81;
                un_inc(a1, p_pFloatStr, v31, (_iobuf *)p_pnFloatStrSz);
LABEL_202:
                if ( v67 != (_BYTE *)a1 )
                {
                  if ( !v78 )
                  {
                    ++v63;
                    if ( p_pFloatStr != 99 )
                    {
                      if ( v75 )
                        *v65 = 0;
                      else
                        *(_BYTE *)v65 = 0;
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
                p_pFloatStr = v55;
                if ( ((1 << (v31 & 7)) & (v72 ^ (char)v84[v31 >> 3])) == 0 )
                  goto LABEL_201;
              }
            }
            if ( !v78 )
              break;
            ++v67;
          }
          if ( !v61 )
          {
            v44 = _errno();
            v45 = v75 == 0;
            *v44 = 12;
            if ( v45 )
              *v67 = 0;
            else
              *(_WORD *)v67 = 0;
            goto error_return_1;
          }
          if ( v75 )
          {
            s[0] = v31;
            if ( isleadbyte(v31) )
            {
              ++v81;
              s[1] = inc((_iobuf *)p_pnFloatStrSz, a1);
            }
            wcscpy(pwc, L"?");
            _mbtowc_l(pwc, s, v51.localeinfo.locinfo->mb_cur_max, &v51.localeinfo);
            *(_WORD *)a1 = pwc[0];
            a1 += 2;
          }
          else
          {
            *(_BYTE *)a1++ = v31;
          }
          v65 = (_WORD *)a1;
        }
        --v61;
        goto LABEL_134;
      }
LABEL_130:
      if ( v79 > 0 )
        v75 = 1;
      goto scanit_0;
    }
    if ( p_pFloatStr == 111 )
      goto LABEL_209;
    if ( p_pFloatStr == 99 )
    {
      if ( !v64 )
      {
        ++v77;
        v64 = 1;
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
              v19 = v81;
              if ( !v78 )
              {
assign_num_0:
                if ( v67 )
                {
                  *(_QWORD *)a1 = v66;
                }
                else if ( v76 )
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
          if ( v82 == 45 )
          {
            v71 = 1;
            goto x_incwidth_0;
          }
          if ( v82 == 43 )
          {
x_incwidth_0:
            if ( --v77 || !v64 )
            {
              ++v81;
              v82 = inc(v74, a1);
            }
            else
            {
              v80 = 1;
            }
          }
          if ( v82 == 48 )
          {
            ++v81;
            v39 = inc(v74, a1);
            v82 = v39;
            if ( (_BYTE)v39 == 120 || (_BYTE)v39 == 88 )
            {
              ++v81;
              v82 = inc(v74, a1);
              if ( v64 )
              {
                v77 -= 2;
                if ( v77 < 1 )
                  ++v80;
              }
              v50 = 120;
LABEL_197:
              p_pFloatStr = v50;
            }
            else
            {
              v69 = 1;
              if ( p_pFloatStr != 120 )
              {
                if ( v64 )
                {
                  if ( !--v77 )
                    ++v80;
                }
                v50 = 111;
                goto LABEL_197;
              }
              --v81;
              un_inc(a1, 120, v82, v74);
              v82 = 48;
            }
          }
          goto getnum_0;
        }
        a1 = 0;
        if ( v82 == 45 )
        {
          *pFloatStr = 45;
          a1 = 1;
          goto f_incwidth_0;
        }
        if ( v82 == 43 )
        {
f_incwidth_0:
          --v77;
          ++v81;
          v82 = inc(v74, a1);
        }
        if ( !v64 )
          v77 = -1;
        for ( i = (unsigned __int8)v82; isdigit(i); i = (unsigned __int8)v82 )
        {
          if ( !v77-- )
            break;
          ++v69;
          pFloatStr[a1++] = v82;
          p_pFloatStr = (int)&pFloatStr;
          p_pnFloatStrSz = &pnFloatStrSz;
          if ( !_check_float_string(a1, &pnFloatStrSz, &pFloatStr, floatstring, &pmalloc_FloatStrFlag) )
            goto error_return_1;
          ++v81;
          v82 = inc(v74, a1);
        }
        v72 = *v51.localeinfo.locinfo->lconv->decimal_point;
        if ( v72 == (_BYTE)v82 )
        {
          if ( v77-- )
          {
            ++v81;
            v82 = inc(v74, a1);
            pFloatStr[a1++] = v72;
            p_pFloatStr = (int)&pFloatStr;
            p_pnFloatStrSz = &pnFloatStrSz;
            if ( !_check_float_string(a1, &pnFloatStrSz, &pFloatStr, floatstring, &pmalloc_FloatStrFlag) )
              goto error_return_1;
            for ( j = (unsigned __int8)v82; isdigit(j); j = (unsigned __int8)v82 )
            {
              if ( !v77-- )
                break;
              ++v69;
              pFloatStr[a1++] = v82;
              p_pFloatStr = (int)&pFloatStr;
              p_pnFloatStrSz = &pnFloatStrSz;
              if ( !_check_float_string(a1, &pnFloatStrSz, &pFloatStr, floatstring, &pmalloc_FloatStrFlag) )
                goto error_return_1;
              ++v81;
              v82 = inc(v74, a1);
            }
          }
        }
        if ( v69 && (v82 == 101 || v82 == 69) )
        {
          if ( v77-- )
          {
            pFloatStr[a1++] = 101;
            p_pFloatStr = (int)&pFloatStr;
            p_pnFloatStrSz = &pnFloatStrSz;
            if ( !_check_float_string(a1, &pnFloatStrSz, &pFloatStr, floatstring, &pmalloc_FloatStrFlag) )
              goto error_return_1;
            ++v81;
            v82 = inc(v74, a1);
            if ( v82 == 45 )
            {
              pFloatStr[a1] = 45;
              if ( !_check_float_string(++a1, &pnFloatStrSz, &pFloatStr, floatstring, &pmalloc_FloatStrFlag) )
                goto error_return_1;
f_incwidth2_0:
              if ( v77-- )
              {
                ++v81;
                v82 = inc(v74, a1);
              }
              else
              {
                v77 = 0;
              }
            }
            else if ( v82 == 43 )
            {
              goto f_incwidth2_0;
            }
            for ( k = (unsigned __int8)v82; isdigit(k); k = (unsigned __int8)v82 )
            {
              if ( !v77-- )
                break;
              ++v69;
              pFloatStr[a1++] = v82;
              p_pFloatStr = (int)&pFloatStr;
              p_pnFloatStrSz = &pnFloatStrSz;
              if ( !_check_float_string(a1, &pnFloatStrSz, &pFloatStr, floatstring, &pmalloc_FloatStrFlag) )
                goto error_return_1;
              ++v81;
              v82 = inc(v74, a1);
            }
          }
        }
        --v81;
        un_inc(a1, p_pFloatStr, v82, v74);
        if ( v69 )
        {
          if ( !v78 )
          {
            ++v63;
            v48 = pFloatStr;
            v47 = v65;
            pFloatStr[a1] = 0;
            v46 = v76 - 1;
            v29 = (void (__cdecl *)(int, _WORD *, char *, _LocaleUpdate *))_decode_pointer(off_86F6A4[0]);
            v29(v46, v47, v48, &v51);
          }
          goto LABEL_258;
        }
        goto error_return_1;
      }
LABEL_155:
      if ( *(unsigned __int8 *)p_pnFloatStrSz == v82 )
      {
        --v73;
        if ( !v78 )
          v56 = v54;
        goto LABEL_258;
      }
      un_inc(a1, p_pFloatStr, v82, v74);
      v52 = 1;
      goto error_return_1;
    }
LABEL_209:
    if ( v82 == 45 )
    {
      v71 = 1;
    }
    else if ( v82 != 43 )
    {
      goto getnum_0;
    }
    if ( --v77 || !v64 )
    {
      ++v81;
      v82 = inc(v74, a1);
    }
    else
    {
      v80 = 1;
    }
getnum_0:
    if ( v67 )
    {
      if ( !v80 )
      {
        while ( 1 )
        {
          if ( p_pFloatStr == 120 || p_pFloatStr == 112 )
          {
            if ( !isxdigit((unsigned __int8)v82) )
            {
LABEL_230:
              --v81;
              un_inc(a1, p_pFloatStr, v82, v74);
              break;
            }
            v66 *= 16;
            v82 = hextodec(v82);
          }
          else
          {
            if ( !isdigit((unsigned __int8)v82) )
              goto LABEL_230;
            if ( p_pFloatStr == 111 )
            {
              if ( v82 >= 56 )
                goto LABEL_230;
              v66 *= 8;
            }
            else
            {
              v66 *= 10;
            }
          }
          ++v69;
          v66 += v82 - 48;
          if ( v64 )
          {
            if ( !--v77 )
              break;
          }
          ++v81;
          v82 = inc(v74, a1);
        }
      }
      if ( v71 )
        v66 = -v66;
LABEL_233:
      v19 = v62;
      goto LABEL_234;
    }
    if ( v80 )
      goto LABEL_253;
    while ( 2 )
    {
      if ( p_pFloatStr != 120 && p_pFloatStr != 112 )
      {
        if ( !isdigit((unsigned __int8)v82) )
          break;
        if ( p_pFloatStr == 111 )
        {
          if ( v82 >= 56 )
            break;
          v40 = 8 * v62;
        }
        else
        {
          v40 = 10 * v62;
        }
        goto LABEL_249;
      }
      if ( isxdigit((unsigned __int8)v82) )
      {
        v62 *= 16;
        v82 = hextodec(v82);
        v40 = v62;
LABEL_249:
        ++v69;
        v62 = v40 + v82 - 48;
        if ( v64 )
        {
          if ( !--v77 )
            goto LABEL_253;
        }
        ++v81;
        v82 = inc(v74, a1);
        continue;
      }
      break;
    }
    --v81;
    un_inc(a1, p_pFloatStr, v82, v74);
LABEL_253:
    if ( !v71 )
      goto LABEL_233;
    v19 = -v62;
LABEL_234:
    if ( !v69 )
      goto error_return_1;
    if ( !v78 )
    {
      ++v63;
      a1 = (int)v65;
      goto assign_num_0;
    }
LABEL_258:
    ++v73;
    p_pnFloatStrSz = (unsigned int *)++v68;
LABEL_264:
    if ( v82 != -1 )
    {
LABEL_268:
      v10 = *(_BYTE *)p_pnFloatStrSz;
      if ( !*(_BYTE *)p_pnFloatStrSz )
        goto error_return_1;
      continue;
    }
    break;
  }
  if ( *(_BYTE *)p_pnFloatStrSz == 37 && v68[1] == 110 )
  {
    p_pnFloatStrSz = (unsigned int *)v68;
    goto LABEL_268;
  }
error_return_1:
  if ( pmalloc_FloatStrFlag == 1 )
    free(pFloatStr);
  if ( v82 == -1 )
  {
    result = v63;
    if ( !v63 && !v73 )
      result = -1;
    if ( v51.updated )
      v51.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( v52 == 1 )
  {
    *_errno() = 22;
    _invalid_parameter(a1, p_pFloatStr, (int)p_pnFloatStrSz);
  }
LABEL_291:
  if ( v51.updated )
    v51.ptd->_ownlocale &= ~2u;
  return v63;
}
