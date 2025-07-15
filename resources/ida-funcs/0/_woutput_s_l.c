int __cdecl _woutput_s_l(_iobuf *stream, const wchar_t *format, localeinfo_struct *plocinfo, char *argptr)
{
  char *v4; // ebx
  unsigned int v5; // esi
  const wchar_t *v6; // edi
  int v8; // ecx
  int v9; // eax
  STATE v10; // eax
  int v11; // eax
  int v12; // eax
  wchar_t v13; // ax
  _woutput_s_l::__l2::<unnamed_type_buffer> *p_buffer; // esi
  int v15; // edi
  _woutput_s_l::__l2::<unnamed_type_text> v16; // ebx
  unsigned __int8 *i; // esi
  int v18; // eax
  __int16 *v19; // eax
  _woutput_s_l::__l2::<unnamed_type_text> v20; // ecx
  int v21; // eax
  int v22; // eax
  char *v23; // ebx
  __int64 v24; // rax
  int v25; // edi
  char *v26; // eax
  int v27; // eax
  char *v28; // ebx
  void (__cdecl *v29)(_CRT_DOUBLE *, _woutput_s_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *); // eax
  int v30; // ebx
  void (__cdecl *v31)(_woutput_s_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  void (__cdecl *v32)(_woutput_s_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  unsigned int v33; // ebx
  unsigned int v34; // edi
  char *j; // esi
  int v36; // eax
  int v37; // ecx
  unsigned __int64 v38; // kr00_8
  char *v39; // eax
  _BYTE *v40; // esi
  char *sz; // eax
  int v42; // esi
  int v43; // ebx
  _iobuf *v44; // edi
  const char *v45; // edi
  int v46; // eax
  int v47; // [esp-14h] [ebp-494h]
  int v48; // [esp-10h] [ebp-490h]
  int v49; // [esp-Ch] [ebp-48Ch]
  int v50; // [esp-8h] [ebp-488h]
  wchar_t v51; // [esp-4h] [ebp-484h]
  int retval; // [esp+10h] [ebp-470h]
  _CRT_DOUBLE tmp; // [esp+14h] [ebp-46Ch] BYREF
  int wchar; // [esp+1Ch] [ebp-464h] BYREF
  const wchar_t *v55; // [esp+20h] [ebp-460h]
  int capexp; // [esp+24h] [ebp-45Ch]
  char *heapbuf; // [esp+28h] [ebp-458h]
  int hexadd; // [esp+2Ch] [ebp-454h]
  int no_output; // [esp+30h] [ebp-450h]
  _LocaleUpdate _loc_update; // [esp+34h] [ebp-44Ch] BYREF
  _iobuf *f; // [esp+44h] [ebp-43Ch]
  char tempchar[4]; // [esp+48h] [ebp-438h] BYREF
  STATE state; // [esp+4Ch] [ebp-434h]
  wchar_t prefix[2]; // [esp+50h] [ebp-430h] BYREF
  int fldwidth; // [esp+54h] [ebp-42Ch]
  int bufferiswide; // [esp+58h] [ebp-428h]
  int prefixlen; // [esp+5Ch] [ebp-424h]
  int charsout; // [esp+60h] [ebp-420h] BYREF
  int count; // [esp+64h] [ebp-41Ch]
  char *v70; // [esp+68h] [ebp-418h]
  int textlen; // [esp+6Ch] [ebp-414h]
  _woutput_s_l::__l2::<unnamed_type_text> text; // [esp+70h] [ebp-410h]
  int precision; // [esp+74h] [ebp-40Ch]
  int flags; // [esp+78h] [ebp-408h]
  _woutput_s_l::__l2::<unnamed_type_buffer> buffer; // [esp+7Ch] [ebp-404h] BYREF

  v4 = argptr;
  v5 = (unsigned int)stream;
  v6 = format;
  f = stream;
  v70 = argptr;
  hexadd = 0;
  flags = 0;
  fldwidth = 0;
  precision = 0;
  prefixlen = 0;
  no_output = 0;
  bufferiswide = 0;
  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  if ( !stream )
    goto LABEL_2;
  v5 = 0;
  if ( !format )
    goto LABEL_2;
  v8 = *format;
  charsout = 0;
  textlen = 0;
  state = ST_NORMAL;
  heapbuf = 0;
  count = v8;
  if ( !(_WORD)v8 )
    goto LABEL_213;
  while ( 1 )
  {
    v55 = ++v6;
    if ( charsout < 0 )
      break;
    if ( (unsigned __int16)(v8 - 32) > 0x58u )
      v9 = 0;
    else
      v9 = byte_81EEA0[(unsigned __int16)v8] & 0xF;
    v10 = __lookuptable_s[9 * v9 + state] >> 4;
    v5 = 8;
    state = v10;
    if ( v10 == 8 )
      goto LABEL_2;
    switch ( v10 )
    {
      case ST_NORMAL:
        goto NORMAL_STATE_2;
      case ST_PERCENT:
        precision = -1;
        capexp = 0;
        no_output = 0;
        fldwidth = 0;
        prefixlen = 0;
        flags = 0;
        bufferiswide = 0;
        goto LABEL_209;
      case ST_FLAG:
        switch ( (unsigned __int16)v8 )
        {
          case ' ':
            flags |= 2u;
            break;
          case '#':
            flags |= 0x80u;
            break;
          case '+':
            flags |= 1u;
            break;
          case '-':
            flags |= 4u;
            break;
          case '0':
            flags |= 8u;
            break;
          default:
            goto LABEL_208;
        }
        goto LABEL_209;
      case ST_WIDTH:
        if ( (_WORD)v8 == 42 )
        {
          v11 = *(_DWORD *)v4;
          v4 += 4;
          v70 = v4;
          fldwidth = v11;
          if ( v11 < 0 )
          {
            flags |= 4u;
            fldwidth = -fldwidth;
          }
        }
        else
        {
          fldwidth = 10 * fldwidth + (unsigned __int16)v8 - 48;
        }
        goto LABEL_209;
      case ST_DOT:
        precision = 0;
        goto LABEL_209;
      case ST_PRECIS:
        if ( (_WORD)v8 == 42 )
        {
          v12 = *(_DWORD *)v4;
          v4 += 4;
          v70 = v4;
          precision = v12;
          if ( v12 < 0 )
            precision = -1;
        }
        else
        {
          precision = 10 * precision + (unsigned __int16)v8 - 48;
        }
        goto LABEL_209;
      case ST_SIZE:
        switch ( (unsigned __int16)v8 )
        {
          case 'I':
            v13 = *v6;
            if ( *v6 == 54 && v6[1] == 52 )
            {
              v6 += 2;
              flags |= 0x8000u;
            }
            else if ( v13 == 51 && v6[1] == 50 )
            {
              v6 += 2;
              flags &= ~0x8000u;
            }
            else if ( v13 != 100 && v13 != 105 && v13 != 111 && v13 != 117 && v13 != 120 && v13 != 88 )
            {
              state = ST_NORMAL;
NORMAL_STATE_2:
              bufferiswide = 1;
              write_char_0(f, &charsout, v8);
            }
            break;
          case 'h':
            flags |= 0x20u;
            break;
          case 'l':
            if ( *v6 == 108 )
            {
              ++v6;
              flags |= 0x1000u;
            }
            else
            {
              flags |= 0x10u;
            }
            break;
          case 'w':
            flags |= 0x800u;
            break;
        }
        goto LABEL_209;
      case ST_TYPE:
        if ( (unsigned __int16)v8 <= 0x64u )
        {
          if ( (unsigned __int16)v8 == 100 )
          {
LABEL_112:
            flags |= 0x40u;
            goto LABEL_113;
          }
          if ( (unsigned __int16)v8 > 0x53u )
          {
            if ( (unsigned __int16)v8 == 88 )
              goto LABEL_134;
            if ( (unsigned __int16)v8 == 90 )
            {
              v19 = *(__int16 **)v4;
              v70 = v4 + 4;
              if ( !v19 || (v20.sz = *(char **)(v19 + 2)) == 0 )
              {
                text.sz = __nullstring;
                strlen((unsigned __int8 *)__nullstring);
                goto LABEL_180;
              }
              v21 = *v19;
              text.sz = v20.sz;
              if ( (flags & 0x800) == 0 )
              {
                bufferiswide = 0;
                goto LABEL_180;
              }
              v22 = v21 - (v21 >> 31);
              bufferiswide = 1;
              goto LABEL_179;
            }
            if ( (unsigned __int16)v8 != 97 )
            {
              if ( (unsigned __int16)v8 != 99 )
                goto LABEL_181;
              goto LABEL_87;
            }
          }
          else
          {
            if ( (unsigned __int16)v8 == 83 )
            {
              if ( (flags & 0x830) == 0 )
                flags |= 0x20u;
              goto LABEL_72;
            }
            if ( (unsigned __int16)v8 != 65 )
            {
              if ( (unsigned __int16)v8 != 67 )
              {
                if ( (unsigned __int16)v8 != 69 && (unsigned __int16)v8 != 71 )
                  goto LABEL_181;
                goto LABEL_65;
              }
              if ( (flags & 0x830) == 0 )
                flags |= 0x20u;
LABEL_87:
              v18 = *(unsigned __int16 *)v4;
              bufferiswide = 1;
              v70 = v4 + 4;
              wchar = v18;
              if ( (flags & 0x20) != 0 )
              {
                tempchar[0] = v18;
                tempchar[1] = 0;
                if ( _mbtowc_l(
                       (wchar_t *)&buffer,
                       tempchar,
                       _loc_update.localeinfo.locinfo->mb_cur_max,
                       &_loc_update.localeinfo) < 0 )
                  no_output = 1;
              }
              else
              {
                buffer.wz[0] = v18;
              }
              text.sz = (char *)&buffer;
              textlen = 1;
              goto LABEL_181;
            }
LABEL_65:
            v8 += 32;
            capexp = 1;
            count = v8;
          }
LABEL_66:
          flags |= 0x40u;
          p_buffer = &buffer;
          text.sz = (char *)&buffer;
          textlen = 512;
          if ( precision >= 0 )
          {
            if ( precision )
            {
              if ( precision > 512 )
                precision = 512;
              if ( precision > 163 )
              {
                v25 = precision + 349;
                v26 = (char *)_malloc_crt(precision + 349);
                LOBYTE(v8) = count;
                heapbuf = v26;
                if ( v26 )
                {
                  text.sz = v26;
                  textlen = v25;
                  p_buffer = (_woutput_s_l::__l2::<unnamed_type_buffer> *)v26;
                }
                else
                {
                  precision = 163;
                }
              }
            }
            else
            {
              precision = (_WORD)v8 == 103;
            }
          }
          else
          {
            precision = 6;
          }
          v27 = *(_DWORD *)v4;
          v28 = v4 + 8;
          LODWORD(tmp.x) = v27;
          HIDWORD(tmp.x) = *((_DWORD *)v28 - 1);
          v50 = capexp;
          v49 = precision;
          v70 = v28;
          v48 = (char)v8;
          v47 = textlen;
          v29 = (void (__cdecl *)(_CRT_DOUBLE *, _woutput_s_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *))_decode_pointer(codedptr);
          v29(&tmp, p_buffer, v47, v48, v49, v50, &_loc_update);
          v30 = flags & 0x80;
          if ( (flags & 0x80) != 0 && !precision )
          {
            v31 = (void (__cdecl *)(_woutput_s_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))_decode_pointer(off_9AEB3C);
            v31(p_buffer, &_loc_update);
          }
          if ( (_WORD)count == 103 && !v30 )
          {
            v32 = (void (__cdecl *)(_woutput_s_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))_decode_pointer(off_9AEB38);
            v32(p_buffer, &_loc_update);
          }
          if ( p_buffer->sz[0] == 45 )
          {
            flags |= 0x100u;
            p_buffer = (_woutput_s_l::__l2::<unnamed_type_buffer> *)((char *)p_buffer + 1);
            text.sz = (char *)p_buffer;
          }
          strlen((unsigned __int8 *)p_buffer);
          goto LABEL_180;
        }
        if ( (unsigned __int16)v8 > 0x70u )
        {
          if ( (unsigned __int16)v8 != 115 )
          {
            if ( (unsigned __int16)v8 != 117 )
            {
              if ( (unsigned __int16)v8 != 120 )
                goto LABEL_181;
              hexadd = 39;
              goto COMMON_HEX_2;
            }
LABEL_113:
            count = 10;
            goto COMMON_INT_2;
          }
LABEL_72:
          v15 = precision;
          if ( precision == -1 )
            v15 = 0x7FFFFFFF;
          v70 = v4 + 4;
          v16.sz = *(char **)v4;
          text.sz = v16.sz;
          if ( (flags & 0x20) != 0 )
          {
            if ( !v16.sz )
              text.sz = __nullstring;
            textlen = 0;
            for ( i = (unsigned __int8 *)text.sz; textlen < v15; ++textlen )
            {
              if ( !*i )
                break;
              if ( _isleadbyte_l(*i, &_loc_update.localeinfo) )
                ++i;
              ++i;
            }
            goto LABEL_181;
          }
          if ( !v16.sz )
            text.sz = (char *)__wnullstring;
          sz = text.sz;
          bufferiswide = 1;
          while ( v15 )
          {
            --v15;
            if ( !*(_WORD *)sz )
              break;
            sz += 2;
          }
          v22 = sz - text.sz;
LABEL_179:
          v21 = v22 >> 1;
LABEL_180:
          textlen = v21;
          goto LABEL_181;
        }
        if ( (unsigned __int16)v8 == 112 )
        {
          precision = 8;
LABEL_134:
          hexadd = 7;
COMMON_HEX_2:
          count = 16;
          if ( (flags & 0x80u) != 0 )
          {
            prefix[0] = 48;
            prefix[1] = hexadd + 81;
            prefixlen = 2;
          }
          goto COMMON_INT_2;
        }
        if ( (unsigned __int16)v8 < 0x65u )
          goto LABEL_181;
        if ( (unsigned __int16)v8 <= 0x67u )
          goto LABEL_66;
        if ( (unsigned __int16)v8 == 105 )
          goto LABEL_112;
        if ( (unsigned __int16)v8 != 110 )
        {
          if ( (unsigned __int16)v8 != 111 )
            goto LABEL_181;
          count = 8;
          if ( (flags & 0x80u) != 0 )
            flags |= 0x200u;
COMMON_INT_2:
          if ( (flags & 0x8000) != 0 || (flags & 0x1000) != 0 )
          {
            v23 = v4 + 8;
            v24 = *((_QWORD *)v23 - 1);
          }
          else
          {
            v23 = v4 + 4;
            if ( (flags & 0x20) != 0 )
            {
              v70 = v23;
              if ( (flags & 0x40) != 0 )
                LODWORD(v24) = *((__int16 *)v23 - 2);
              else
                LODWORD(v24) = *((unsigned __int16 *)v23 - 2);
              v24 = (int)v24;
LABEL_151:
              if ( (flags & 0x40) != 0 && v24 < 0 )
              {
                v24 = -v24;
                flags |= 0x100u;
              }
              v33 = HIDWORD(v24);
              v34 = v24;
              if ( (flags & 0x9000) == 0 )
                v33 = 0;
              if ( precision >= 0 )
              {
                flags &= ~8u;
                if ( precision > 512 )
                  precision = 512;
              }
              else
              {
                precision = 1;
              }
              if ( !(v33 | (unsigned int)v24) )
                prefixlen = 0;
              for ( j = &buffer.sz[511]; ; --j )
              {
                v36 = precision--;
                if ( v36 <= 0 && !(v33 | v34) )
                  break;
                v37 = __PAIR64__(v33, v34) % count + 48;
                v38 = __PAIR64__(v33, v34) / count;
                v33 = HIDWORD(v38);
                v34 = v38;
                if ( v37 > 57 )
                  LOBYTE(v37) = hexadd + v37;
                *j = v37;
              }
              v39 = (char *)((char *)&buffer.wz[255] + 1 - j);
              v40 = j + 1;
              textlen = (int)v39;
              text.sz = v40;
              if ( (flags & 0x200) != 0 && (!v39 || *v40 != 48) )
              {
                *--text.sz = 48;
                v21 = (int)(v39 + 1);
                goto LABEL_180;
              }
LABEL_181:
              if ( no_output )
                goto LABEL_206;
              if ( (flags & 0x40) != 0 )
              {
                if ( (flags & 0x100) != 0 )
                {
                  v51 = 45;
                  goto LABEL_189;
                }
                if ( (flags & 1) != 0 )
                {
                  v51 = 43;
                  goto LABEL_189;
                }
                if ( (flags & 2) != 0 )
                {
                  v51 = 32;
LABEL_189:
                  prefix[0] = v51;
                  prefixlen = 1;
                }
              }
              v42 = textlen;
              v43 = fldwidth - textlen - prefixlen;
              if ( (flags & 0xC) == 0 )
                write_multi_char_0(&charsout, 0x20u, fldwidth - textlen - prefixlen, f);
              v44 = f;
              write_string_0(prefix, f, &charsout, prefixlen);
              if ( (flags & 8) != 0 && (flags & 4) == 0 )
                write_multi_char_0(&charsout, 0x30u, v43, v44);
              if ( bufferiswide || v42 <= 0 )
              {
                write_string_0(text.wz, v44, &charsout, v42);
              }
              else
              {
                v45 = text.sz;
                count = v42;
                while ( 1 )
                {
                  --count;
                  retval = _mbtowc_l(
                             (wchar_t *)&wchar,
                             v45,
                             _loc_update.localeinfo.locinfo->mb_cur_max,
                             &_loc_update.localeinfo);
                  if ( retval <= 0 )
                    break;
                  write_char_0(f, &charsout, wchar);
                  v45 += retval;
                  if ( count <= 0 )
                    goto LABEL_203;
                }
                charsout = -1;
              }
LABEL_203:
              if ( charsout >= 0 && (flags & 4) != 0 )
                write_multi_char_0(&charsout, 0x20u, v43, f);
              goto LABEL_206;
            }
            LODWORD(v24) = *((_DWORD *)v23 - 1);
            if ( (flags & 0x40) != 0 )
              v24 = (int)v24;
            else
              HIDWORD(v24) = 0;
          }
          v70 = v23;
          goto LABEL_151;
        }
        v5 = *(_DWORD *)v4;
        v4 += 4;
        v70 = v4;
        if ( !_get_printf_count_output() )
          goto LABEL_2;
        if ( (flags & 0x20) != 0 )
          *(_WORD *)v5 = charsout;
        else
          *(_DWORD *)v5 = charsout;
        no_output = 1;
LABEL_206:
        if ( heapbuf )
        {
          free(heapbuf);
          heapbuf = 0;
        }
LABEL_208:
        v6 = v55;
        v4 = v70;
LABEL_209:
        v46 = *v6;
        v5 = 0;
        count = v46;
        if ( !(_WORD)v46 )
          goto LABEL_211;
        v8 = v46;
        break;
      default:
        goto LABEL_208;
    }
  }
LABEL_211:
  if ( state == ST_NORMAL || state == ST_TYPE )
  {
LABEL_213:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return charsout;
  }
  else
  {
LABEL_2:
    *_errno() = 22;
    _invalid_parameter((unsigned int)v4, (unsigned int)v6, v5);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return -1;
  }
}
