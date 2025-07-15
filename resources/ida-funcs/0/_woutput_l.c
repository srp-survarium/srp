int __cdecl _woutput_l(_iobuf *stream, wchar_t *format, localeinfo_struct *plocinfo, char *argptr)
{
  int *v4; // ebx
  wchar_t *v5; // esi
  unsigned int v6; // edi
  int v8; // edx
  STATE v9; // ecx
  wchar_t *v10; // esi
  int v11; // eax
  wchar_t v12; // ax
  _woutput_l::__l2::<unnamed_type_buffer> *p_buffer; // esi
  int v14; // edi
  _woutput_l::__l2::<unnamed_type_text> v15; // ebx
  unsigned __int8 *j; // esi
  int v17; // eax
  __int16 *v18; // eax
  _woutput_l::__l2::<unnamed_type_text> v19; // ecx
  int v20; // eax
  int v21; // eax
  __int64 v22; // rax
  int *v23; // ebx
  int v24; // edi
  char *v25; // eax
  int v26; // eax
  char *v27; // ebx
  void (__cdecl *v28)(_CRT_DOUBLE *, _woutput_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *); // eax
  int v29; // ebx
  void (__cdecl *v30)(_woutput_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  void (__cdecl *v31)(_woutput_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  unsigned int v32; // ebx
  unsigned int v33; // edi
  char *i; // esi
  int v35; // eax
  int v36; // ecx
  unsigned __int64 v37; // kr08_8
  char *v38; // eax
  _BYTE *v39; // esi
  char *sz; // eax
  int v41; // esi
  int v42; // ebx
  _iobuf *v43; // edi
  const char *v44; // edi
  int v45; // eax
  int v46; // [esp-14h] [ebp-494h]
  int v47; // [esp-10h] [ebp-490h]
  int v48; // [esp-Ch] [ebp-48Ch]
  int v49; // [esp-8h] [ebp-488h]
  wchar_t v50; // [esp-4h] [ebp-484h]
  int retval; // [esp+10h] [ebp-470h]
  _CRT_DOUBLE tmp; // [esp+14h] [ebp-46Ch] BYREF
  int wchar; // [esp+1Ch] [ebp-464h] BYREF
  int capexp; // [esp+20h] [ebp-460h]
  STATE state; // [esp+24h] [ebp-45Ch]
  _LocaleUpdate _loc_update; // [esp+28h] [ebp-458h] BYREF
  int hexadd; // [esp+38h] [ebp-448h]
  char *heapbuf; // [esp+3Ch] [ebp-444h]
  wchar_t *v59; // [esp+40h] [ebp-440h]
  int no_output; // [esp+44h] [ebp-43Ch]
  wchar_t prefix[2]; // [esp+48h] [ebp-438h] BYREF
  char tempchar[4]; // [esp+4Ch] [ebp-434h] BYREF
  _iobuf *f; // [esp+50h] [ebp-430h]
  int fldwidth; // [esp+54h] [ebp-42Ch]
  int bufferiswide; // [esp+58h] [ebp-428h]
  int prefixlen; // [esp+5Ch] [ebp-424h]
  int charsout; // [esp+60h] [ebp-420h] BYREF
  char *v68; // [esp+64h] [ebp-41Ch]
  int count; // [esp+68h] [ebp-418h]
  int textlen; // [esp+6Ch] [ebp-414h]
  _woutput_l::__l2::<unnamed_type_text> text; // [esp+70h] [ebp-410h]
  int precision; // [esp+74h] [ebp-40Ch]
  int flags; // [esp+78h] [ebp-408h]
  _woutput_l::__l2::<unnamed_type_buffer> buffer; // [esp+7Ch] [ebp-404h] BYREF

  v4 = (int *)argptr;
  v5 = format;
  v6 = 0;
  f = stream;
  v68 = argptr;
  hexadd = 0;
  flags = 0;
  fldwidth = 0;
  precision = 0;
  prefixlen = 0;
  no_output = 0;
  bufferiswide = 0;
  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  if ( !f || !format )
  {
    *_errno() = 22;
    goto LABEL_3;
  }
  v8 = *format;
  v9 = ST_NORMAL;
  charsout = 0;
  textlen = 0;
  heapbuf = 0;
  count = v8;
  if ( !(_WORD)v8 )
  {
LABEL_210:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return charsout;
  }
  while ( 2 )
  {
    v6 = 2;
    v10 = v5 + 1;
    v59 = v10;
    if ( charsout < 0 )
      goto LABEL_210;
    if ( (unsigned __int16)(v8 - 32) > 0x58u )
      v11 = 0;
    else
      v11 = byte_81EE40[(unsigned __int16)v8] & 0xF;
    state = __lookuptable[8 * v11 + v9] >> 4;
    switch ( state )
    {
      case ST_NORMAL:
        goto NORMAL_STATE_1;
      case ST_PERCENT:
        precision = -1;
        capexp = 0;
        no_output = 0;
        fldwidth = 0;
        prefixlen = 0;
        flags = 0;
        bufferiswide = 0;
        goto LABEL_207;
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
        }
        goto LABEL_207;
      case ST_WIDTH:
        if ( (_WORD)v8 == 42 )
        {
          v68 = (char *)(v4 + 1);
          fldwidth = *v4;
          if ( fldwidth < 0 )
          {
            flags |= 4u;
            fldwidth = -fldwidth;
          }
        }
        else
        {
          fldwidth = 10 * fldwidth + (unsigned __int16)v8 - 48;
        }
        goto LABEL_207;
      case ST_DOT:
        precision = 0;
        goto LABEL_207;
      case ST_PRECIS:
        if ( (_WORD)v8 == 42 )
        {
          v68 = (char *)(v4 + 1);
          precision = *v4;
          if ( precision < 0 )
            precision = -1;
        }
        else
        {
          precision = 10 * precision + (unsigned __int16)v8 - 48;
        }
        goto LABEL_207;
      case ST_SIZE:
        switch ( (unsigned __int16)v8 )
        {
          case 'I':
            v12 = *v10;
            if ( *v10 == 54 && v10[1] == 52 )
            {
              flags |= 0x8000u;
              v59 = v10 + 2;
            }
            else if ( v12 == 51 && v10[1] == 50 )
            {
              flags &= ~0x8000u;
              v59 = v10 + 2;
            }
            else if ( v12 != 100 && v12 != 105 && v12 != 111 && v12 != 117 && v12 != 120 && v12 != 88 )
            {
              state = ST_NORMAL;
NORMAL_STATE_1:
              bufferiswide = 1;
              write_char_0(f, &charsout, v8);
            }
            break;
          case 'h':
            flags |= 0x20u;
            break;
          case 'l':
            if ( *v10 == 108 )
            {
              flags |= 0x1000u;
              v59 = v10 + 1;
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
        goto LABEL_207;
      case ST_TYPE:
        if ( (unsigned __int16)v8 <= 0x64u )
        {
          if ( (unsigned __int16)v8 == 100 )
            goto LABEL_111;
          if ( (unsigned __int16)v8 > 0x53u )
          {
            if ( (unsigned __int16)v8 != 88 )
            {
              if ( (unsigned __int16)v8 == 90 )
              {
                v18 = (__int16 *)*v4;
                v68 = (char *)(v4 + 1);
                if ( v18 && (v19.sz = *(char **)(v18 + 2)) != 0 )
                {
                  v20 = *v18;
                  text.sz = v19.sz;
                  if ( (flags & 0x800) != 0 )
                  {
                    v21 = v20 - (v20 >> 31);
                    bufferiswide = 1;
LABEL_178:
                    v20 = v21 >> 1;
                    goto LABEL_179;
                  }
                  bufferiswide = 0;
                }
                else
                {
                  text.sz = __nullstring;
                  strlen((unsigned __int8 *)__nullstring);
                }
LABEL_179:
                textlen = v20;
                goto LABEL_180;
              }
              if ( (unsigned __int16)v8 == 97 )
                goto LABEL_65;
              if ( (unsigned __int16)v8 != 99 )
                goto LABEL_180;
              goto LABEL_86;
            }
LABEL_133:
            hexadd = 7;
COMMON_HEX_1:
            count = 16;
            if ( (flags & 0x80u) != 0 )
            {
              prefix[0] = 48;
              prefix[1] = hexadd + 81;
              prefixlen = 2;
            }
COMMON_INT_1:
            if ( (flags & 0x8000) != 0 || (flags & 0x1000) != 0 )
            {
              v22 = *(_QWORD *)v4;
              v23 = v4 + 2;
            }
            else
            {
              v23 = v4 + 1;
              if ( (flags & 0x20) != 0 )
              {
                v68 = (char *)v23;
                if ( (flags & 0x40) != 0 )
                  LODWORD(v22) = *((__int16 *)v23 - 2);
                else
                  LODWORD(v22) = *((unsigned __int16 *)v23 - 2);
                v22 = (int)v22;
LABEL_150:
                if ( (flags & 0x40) != 0 && v22 < 0 )
                {
                  v22 = -v22;
                  flags |= 0x100u;
                }
                v32 = HIDWORD(v22);
                v33 = v22;
                if ( (flags & 0x9000) == 0 )
                  v32 = 0;
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
                if ( !(v32 | (unsigned int)v22) )
                  prefixlen = 0;
                for ( i = &buffer.sz[511]; ; --i )
                {
                  v35 = precision--;
                  if ( v35 <= 0 && !(v32 | v33) )
                    break;
                  v36 = __PAIR64__(v32, v33) % count + 48;
                  v37 = __PAIR64__(v32, v33) / count;
                  v32 = HIDWORD(v37);
                  v33 = v37;
                  if ( v36 > 57 )
                    LOBYTE(v36) = hexadd + v36;
                  *i = v36;
                }
                v38 = (char *)((char *)&buffer.wz[255] + 1 - i);
                v39 = i + 1;
                textlen = (int)v38;
                text.sz = v39;
                if ( (flags & 0x200) != 0 && (!v38 || *v39 != 48) )
                {
                  *--text.sz = 48;
                  v20 = (int)(v38 + 1);
                  goto LABEL_179;
                }
                goto LABEL_180;
              }
              LODWORD(v22) = *(v23 - 1);
              if ( (flags & 0x40) != 0 )
                v22 = (int)v22;
              else
                HIDWORD(v22) = 0;
            }
            v68 = (char *)v23;
            goto LABEL_150;
          }
          switch ( (unsigned __int16)v8 )
          {
            case 'S':
              if ( (flags & 0x830) == 0 )
                flags |= 0x20u;
LABEL_71:
              v14 = precision;
              if ( precision == -1 )
                v14 = 0x7FFFFFFF;
              v68 = (char *)(v4 + 1);
              v15.sz = (char *)*v4;
              text.sz = v15.sz;
              if ( (flags & 0x20) == 0 )
              {
                if ( !v15.sz )
                  text.sz = (char *)__wnullstring;
                sz = text.sz;
                bufferiswide = 1;
                while ( v14 )
                {
                  --v14;
                  if ( !*(_WORD *)sz )
                    break;
                  sz += 2;
                }
                v21 = sz - text.sz;
                goto LABEL_178;
              }
              if ( !v15.sz )
                text.sz = __nullstring;
              textlen = 0;
              for ( j = (unsigned __int8 *)text.sz; textlen < v14; ++textlen )
              {
                if ( !*j )
                  break;
                if ( _isleadbyte_l(*j, &_loc_update.localeinfo) )
                  ++j;
                ++j;
              }
              break;
            case 'A':
              goto LABEL_64;
            case 'C':
              if ( (flags & 0x830) == 0 )
                flags |= 0x20u;
LABEL_86:
              v17 = *(unsigned __int16 *)v4;
              bufferiswide = 1;
              v68 = (char *)(v4 + 1);
              wchar = v17;
              if ( (flags & 0x20) != 0 )
              {
                tempchar[0] = v17;
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
                buffer.wz[0] = v17;
              }
              text.sz = (char *)&buffer;
              textlen = 1;
              break;
            case 'E':
            case 'G':
LABEL_64:
              v8 += 32;
              capexp = 1;
              count = v8;
LABEL_65:
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
                    v24 = precision + 349;
                    v25 = (char *)_malloc_crt(precision + 349);
                    LOBYTE(v8) = count;
                    heapbuf = v25;
                    if ( v25 )
                    {
                      text.sz = v25;
                      textlen = v24;
                      p_buffer = (_woutput_l::__l2::<unnamed_type_buffer> *)v25;
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
              v26 = *v4;
              v27 = (char *)(v4 + 2);
              LODWORD(tmp.x) = v26;
              HIDWORD(tmp.x) = *((_DWORD *)v27 - 1);
              v49 = capexp;
              v48 = precision;
              v68 = v27;
              v47 = (char)v8;
              v46 = textlen;
              v28 = (void (__cdecl *)(_CRT_DOUBLE *, _woutput_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *))_decode_pointer(codedptr);
              v28(&tmp, p_buffer, v46, v47, v48, v49, &_loc_update);
              v29 = flags & 0x80;
              if ( (flags & 0x80) != 0 && !precision )
              {
                v30 = (void (__cdecl *)(_woutput_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))_decode_pointer(off_9AEB3C);
                v30(p_buffer, &_loc_update);
              }
              if ( (_WORD)count == 103 && !v29 )
              {
                v31 = (void (__cdecl *)(_woutput_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))_decode_pointer(off_9AEB38);
                v31(p_buffer, &_loc_update);
              }
              if ( p_buffer->sz[0] == 45 )
              {
                flags |= 0x100u;
                p_buffer = (_woutput_l::__l2::<unnamed_type_buffer> *)((char *)p_buffer + 1);
                text.sz = (char *)p_buffer;
              }
              strlen((unsigned __int8 *)p_buffer);
              goto LABEL_179;
          }
LABEL_180:
          if ( no_output )
            goto LABEL_205;
          if ( (flags & 0x40) == 0 )
            goto LABEL_189;
          if ( (flags & 0x100) != 0 )
          {
            v50 = 45;
LABEL_188:
            prefix[0] = v50;
            prefixlen = 1;
            goto LABEL_189;
          }
          if ( (flags & 1) != 0 )
          {
            v50 = 43;
            goto LABEL_188;
          }
          if ( (flags & 2) != 0 )
          {
            v50 = 32;
            goto LABEL_188;
          }
LABEL_189:
          v41 = textlen;
          v42 = fldwidth - textlen - prefixlen;
          if ( (flags & 0xC) == 0 )
            write_multi_char_0(&charsout, 0x20u, fldwidth - textlen - prefixlen, f);
          v43 = f;
          write_string_0(prefix, f, &charsout, prefixlen);
          if ( (flags & 8) != 0 && (flags & 4) == 0 )
            write_multi_char_0(&charsout, 0x30u, v42, v43);
          if ( bufferiswide || v41 <= 0 )
          {
            write_string_0(text.wz, v43, &charsout, v41);
          }
          else
          {
            v44 = text.sz;
            count = v41;
            while ( 1 )
            {
              --count;
              retval = _mbtowc_l(
                         (wchar_t *)&wchar,
                         v44,
                         _loc_update.localeinfo.locinfo->mb_cur_max,
                         &_loc_update.localeinfo);
              if ( retval <= 0 )
                break;
              write_char_0(f, &charsout, wchar);
              v44 += retval;
              if ( count <= 0 )
                goto LABEL_202;
            }
            charsout = -1;
          }
LABEL_202:
          if ( charsout >= 0 && (flags & 4) != 0 )
            write_multi_char_0(&charsout, 0x20u, v42, f);
LABEL_205:
          if ( heapbuf )
          {
            free(heapbuf);
            heapbuf = 0;
          }
LABEL_207:
          v5 = v59;
          v45 = *v59;
          count = v45;
          if ( !(_WORD)v45 )
            goto LABEL_210;
          v9 = state;
          v4 = (int *)v68;
          v8 = v45;
          continue;
        }
        if ( (unsigned __int16)v8 > 0x70u )
        {
          if ( (unsigned __int16)v8 != 115 )
          {
            if ( (unsigned __int16)v8 != 117 )
            {
              if ( (unsigned __int16)v8 != 120 )
                goto LABEL_180;
              hexadd = 39;
              goto COMMON_HEX_1;
            }
            goto LABEL_112;
          }
          goto LABEL_71;
        }
        if ( (unsigned __int16)v8 == 112 )
        {
          precision = 8;
          goto LABEL_133;
        }
        if ( (unsigned __int16)v8 < 0x65u )
          goto LABEL_180;
        if ( (unsigned __int16)v8 <= 0x67u )
          goto LABEL_65;
        if ( (unsigned __int16)v8 == 105 )
        {
LABEL_111:
          flags |= 0x40u;
LABEL_112:
          count = 10;
          goto COMMON_INT_1;
        }
        if ( (unsigned __int16)v8 != 110 )
        {
          if ( (unsigned __int16)v8 != 111 )
            goto LABEL_180;
          count = 8;
          if ( (flags & 0x80u) != 0 )
            flags |= 0x200u;
          goto COMMON_INT_1;
        }
        v5 = (wchar_t *)*v4++;
        v68 = (char *)v4;
        if ( _get_printf_count_output() )
        {
          if ( (flags & 0x20) != 0 )
            *v5 = charsout;
          else
            *(_DWORD *)v5 = charsout;
          no_output = 1;
          goto LABEL_205;
        }
        *_errno() = 22;
LABEL_3:
        _invalid_parameter((unsigned int)v4, v6, (unsigned int)v5);
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return -1;
      default:
        goto LABEL_207;
    }
  }
}
