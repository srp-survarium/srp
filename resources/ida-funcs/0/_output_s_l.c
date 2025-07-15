int __cdecl _output_s_l(_iobuf *stream, const char *format, localeinfo_struct *plocinfo, char *argptr)
{
  const char *v4; // ebx
  unsigned int p_charsout; // esi
  int v6; // edi
  int v8; // eax
  ioinfo *v9; // ecx
  ioinfo *v10; // eax
  char v11; // dl
  int v12; // eax
  STATE v13; // eax
  char v14; // al
  bool v15; // zf
  int v16; // eax
  _output_s_l::__l2::<unnamed_type_buffer> *p_buffer; // ebx
  int v18; // ecx
  char *sz; // eax
  __int16 *v20; // eax
  _output_s_l::__l2::<unnamed_type_text> v21; // ecx
  signed int v22; // eax
  char *v23; // edi
  __int64 v24; // rax
  int v25; // esi
  char *v26; // eax
  char *v27; // edi
  void (__cdecl *v28)(_CRT_DOUBLE *, _output_s_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *); // eax
  void (__cdecl *v29)(_output_s_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  void (__cdecl *v30)(_output_s_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  unsigned int v31; // ebx
  char *j; // esi
  int v33; // eax
  unsigned __int64 v34; // rcx
  int v35; // ecx
  char *v36; // eax
  _BYTE *v37; // esi
  _BYTE *i; // eax
  int v39; // ebx
  wchar_t *v40; // esi
  wchar_t v41; // ax
  char v42; // al
  int v43; // [esp-14h] [ebp-298h]
  int v44; // [esp-10h] [ebp-294h]
  unsigned __int64 v45; // [esp-10h] [ebp-294h]
  int v46; // [esp-Ch] [ebp-290h]
  int v47; // [esp-8h] [ebp-28Ch]
  _CRT_DOUBLE tmp; // [esp+Ch] [ebp-278h] BYREF
  int retval; // [esp+14h] [ebp-270h] BYREF
  int capexp; // [esp+18h] [ebp-26Ch]
  int count; // [esp+20h] [ebp-264h]
  _iobuf *f; // [esp+24h] [ebp-260h]
  int hexadd; // [esp+28h] [ebp-25Ch]
  int no_output; // [esp+2Ch] [ebp-258h]
  char *heapbuf; // [esp+30h] [ebp-254h]
  _LocaleUpdate _loc_update; // [esp+34h] [ebp-250h] BYREF
  STATE state; // [esp+44h] [ebp-240h]
  char *v58; // [esp+48h] [ebp-23Ch]
  int bufferiswide; // [esp+4Ch] [ebp-238h]
  int fldwidth; // [esp+50h] [ebp-234h]
  int prefixlen; // [esp+54h] [ebp-230h]
  char prefix[4]; // [esp+58h] [ebp-22Ch] BYREF
  int charsout; // [esp+5Ch] [ebp-228h] BYREF
  char *v64; // [esp+60h] [ebp-224h]
  int radix; // [esp+64h] [ebp-220h] BYREF
  _output_s_l::__l2::<unnamed_type_text> text; // [esp+68h] [ebp-21Ch]
  int precision; // [esp+6Ch] [ebp-218h]
  char v68; // [esp+73h] [ebp-211h]
  int flags; // [esp+74h] [ebp-210h]
  _output_s_l::__l2::<unnamed_type_buffer> buffer; // [esp+78h] [ebp-20Ch] BYREF
  char L_buffer[8]; // [esp+278h] [ebp-Ch] BYREF

  v4 = format;
  p_charsout = (unsigned int)stream;
  v6 = (int)argptr;
  f = stream;
  v64 = argptr;
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
  if ( (stream->_flag & 0x40) == 0 )
  {
    v8 = _fileno((unsigned int)format, (unsigned int)argptr, stream);
    if ( v8 == -1 || v8 == -2 )
    {
      v9 = &__badioinfo;
    }
    else
    {
      p_charsout = v8 >> 5;
      v9 = (ioinfo *)((char *)__pioinfo[v8 >> 5] + 64 * (v8 & 0x1F));
    }
    if ( (*((_BYTE *)v9 + 36) & 0x7F) != 0 )
      goto LABEL_2;
    v10 = v8 == -1 || v8 == -2 ? &__badioinfo : (ioinfo *)((char *)__pioinfo[v8 >> 5] + 64 * (v8 & 0x1F));
    if ( *((char *)v10 + 36) < 0 )
      goto LABEL_2;
  }
  if ( !format )
    goto LABEL_2;
  v11 = *format;
  charsout = 0;
  radix = 0;
  state = ST_NORMAL;
  heapbuf = 0;
  v68 = v11;
  if ( !v11 )
    goto LABEL_222;
  while ( 1 )
  {
    ++v4;
    v12 = 0;
    v58 = (char *)v4;
    if ( charsout < 0 )
      break;
    if ( (unsigned __int8)(v11 - 32) <= 0x58u )
      v12 = byte_81EEA0[v11] & 0xF;
    v13 = __lookuptable_s[9 * v12 + state] >> 4;
    p_charsout = 8;
    state = v13;
    if ( v13 == 8 )
      goto LABEL_2;
    switch ( v13 )
    {
      case ST_NORMAL:
        goto NORMAL_STATE_0;
      case ST_PERCENT:
        precision = -1;
        capexp = 0;
        no_output = 0;
        fldwidth = 0;
        prefixlen = 0;
        flags = 0;
        bufferiswide = 0;
        goto LABEL_218;
      case ST_FLAG:
        switch ( v11 )
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
        goto LABEL_218;
      case ST_WIDTH:
        if ( v11 == 42 )
        {
          v64 = (char *)(v6 + 4);
          v6 = *(_DWORD *)v6;
          fldwidth = v6;
          if ( v6 < 0 )
          {
            flags |= 4u;
            fldwidth = -fldwidth;
          }
        }
        else
        {
          fldwidth = 10 * fldwidth + v11 - 48;
        }
        goto LABEL_218;
      case ST_DOT:
        precision = 0;
        goto LABEL_218;
      case ST_PRECIS:
        if ( v11 == 42 )
        {
          v64 = (char *)(v6 + 4);
          v6 = *(_DWORD *)v6;
          precision = v6;
          if ( v6 < 0 )
            precision = -1;
        }
        else
        {
          precision = 10 * precision + v11 - 48;
        }
        goto LABEL_218;
      case ST_SIZE:
        switch ( v11 )
        {
          case 'I':
            v14 = *v4;
            if ( *v4 == 54 && v4[1] == 52 )
            {
              flags |= 0x8000u;
              v58 = (char *)(v4 + 2);
            }
            else if ( v14 == 51 && v4[1] == 50 )
            {
              flags &= ~0x8000u;
              v58 = (char *)(v4 + 2);
            }
            else if ( v14 != 100 && v14 != 105 && v14 != 111 && v14 != 117 && v14 != 120 && v14 != 88 )
            {
              state = ST_NORMAL;
NORMAL_STATE_0:
              bufferiswide = 0;
              v16 = _isleadbyte_l((unsigned __int8)v11, &_loc_update.localeinfo);
              v15 = v16 == 0;
              LOBYTE(v16) = v68;
              if ( !v15 )
              {
                p_charsout = (unsigned int)&charsout;
                write_char(v16, f, &charsout);
                LOBYTE(v16) = *v4++;
                v58 = (char *)v4;
                if ( !(_BYTE)v16 )
                  goto LABEL_2;
              }
              write_char(v16, f, &charsout);
            }
            break;
          case 'h':
            flags |= 0x20u;
            break;
          case 'l':
            if ( *v4 == 108 )
            {
              flags |= 0x1000u;
              v58 = (char *)(v4 + 1);
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
        goto LABEL_218;
      case ST_TYPE:
        if ( v11 <= 100 )
        {
          if ( v11 == 100 )
          {
LABEL_118:
            flags |= 0x40u;
            goto LABEL_119;
          }
          if ( v11 > 83 )
          {
            if ( v11 == 88 )
              goto LABEL_140;
            if ( v11 == 90 )
            {
              v20 = *(__int16 **)v6;
              v6 += 4;
              v64 = (char *)v6;
              if ( v20 && (v21.sz = *(char **)(v20 + 2)) != 0 )
              {
                v22 = *v20;
                text.sz = v21.sz;
                if ( (flags & 0x800) != 0 )
                {
                  v22 /= 2;
                  bufferiswide = 1;
                }
                else
                {
                  bufferiswide = 0;
                }
              }
              else
              {
                text.sz = __nullstring;
                strlen((unsigned __int8 *)__nullstring);
              }
              goto LABEL_189;
            }
            if ( v11 != 97 )
            {
              if ( v11 != 99 )
                goto LABEL_190;
              goto LABEL_93;
            }
          }
          else
          {
            if ( v11 == 83 )
            {
              if ( (flags & 0x830) == 0 )
                flags |= 0x800u;
              goto LABEL_83;
            }
            if ( v11 != 65 )
            {
              if ( v11 != 67 )
              {
                if ( v11 != 69 && v11 != 71 )
                  goto LABEL_190;
                goto LABEL_76;
              }
              if ( (flags & 0x830) == 0 )
                flags |= 0x800u;
LABEL_93:
              v6 += 4;
              v64 = (char *)v6;
              if ( (flags & 0x810) != 0 )
              {
                if ( wctomb_s(&radix, buffer.sz, 0x200u, *(_WORD *)(v6 - 4)) )
                  no_output = 1;
              }
              else
              {
                buffer.sz[0] = *(_BYTE *)(v6 - 4);
                radix = 1;
              }
              text.sz = (char *)&buffer;
              goto LABEL_190;
            }
LABEL_76:
            v11 += 32;
            capexp = 1;
            v68 = v11;
          }
LABEL_77:
          flags |= 0x40u;
          p_buffer = &buffer;
          text.sz = (char *)&buffer;
          count = 512;
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
                v11 = v68;
                heapbuf = v26;
                if ( v26 )
                {
                  text.sz = v26;
                  count = v25;
                  p_buffer = (_output_s_l::__l2::<unnamed_type_buffer> *)v26;
                }
                else
                {
                  precision = 163;
                }
              }
            }
            else
            {
              precision = v11 == 103;
            }
          }
          else
          {
            precision = 6;
          }
          v27 = (char *)(v6 + 8);
          *(_CRT_DOUBLE *)&tmp.x = (_CRT_DOUBLE)*((_QWORD *)v27 - 1);
          v47 = capexp;
          v46 = precision;
          v64 = v27;
          v44 = v11;
          v43 = count;
          v28 = (void (__cdecl *)(_CRT_DOUBLE *, _output_s_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *))_decode_pointer(codedptr);
          v28(&tmp, p_buffer, v43, v44, v46, v47, &_loc_update);
          v6 = flags & 0x80;
          if ( (flags & 0x80) != 0 && !precision )
          {
            v29 = (void (__cdecl *)(_output_s_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))_decode_pointer(off_9AEB3C);
            v29(p_buffer, &_loc_update);
          }
          if ( v68 == 103 && !v6 )
          {
            v30 = (void (__cdecl *)(_output_s_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))_decode_pointer(off_9AEB38);
            v30(p_buffer, &_loc_update);
          }
          if ( p_buffer->sz[0] == 45 )
          {
            flags |= 0x100u;
            p_buffer = (_output_s_l::__l2::<unnamed_type_buffer> *)((char *)p_buffer + 1);
            text.sz = (char *)p_buffer;
          }
          strlen((unsigned __int8 *)p_buffer);
          goto LABEL_189;
        }
        if ( v11 > 112 )
        {
          if ( v11 != 115 )
          {
            if ( v11 != 117 )
            {
              if ( v11 != 120 )
                goto LABEL_190;
              hexadd = 39;
              goto COMMON_HEX_0;
            }
LABEL_119:
            radix = 10;
            goto COMMON_INT_0;
          }
LABEL_83:
          v18 = precision;
          if ( precision == -1 )
            v18 = 0x7FFFFFFF;
          v64 = (char *)(v6 + 4);
          v6 = *(_DWORD *)v6;
          text.sz = (char *)v6;
          if ( (flags & 0x810) != 0 )
          {
            if ( !v6 )
              text.sz = (char *)__wnullstring;
            sz = text.sz;
            bufferiswide = 1;
            while ( v18 )
            {
              --v18;
              if ( !*(_WORD *)sz )
                break;
              sz += 2;
            }
            v22 = (sz - text.sz) >> 1;
          }
          else
          {
            if ( !v6 )
              text.sz = __nullstring;
            for ( i = text.sz; v18; ++i )
            {
              --v18;
              if ( !*i )
                break;
            }
            v22 = i - text.sz;
          }
LABEL_189:
          radix = v22;
          goto LABEL_190;
        }
        if ( v11 == 112 )
        {
          precision = 8;
LABEL_140:
          hexadd = 7;
COMMON_HEX_0:
          radix = 16;
          if ( (flags & 0x80u) != 0 )
          {
            prefix[0] = 48;
            prefix[1] = hexadd + 81;
            prefixlen = 2;
          }
          goto COMMON_INT_0;
        }
        if ( v11 < 101 )
          goto LABEL_190;
        if ( v11 <= 103 )
          goto LABEL_77;
        if ( v11 == 105 )
          goto LABEL_118;
        if ( v11 != 110 )
        {
          if ( v11 != 111 )
            goto LABEL_190;
          radix = 8;
          if ( (flags & 0x80u) != 0 )
            flags |= 0x200u;
COMMON_INT_0:
          if ( (flags & 0x8000) != 0 || (flags & 0x1000) != 0 )
          {
            v23 = (char *)(v6 + 8);
            v24 = *((_QWORD *)v23 - 1);
          }
          else
          {
            v23 = (char *)(v6 + 4);
            if ( (flags & 0x20) != 0 )
            {
              v64 = v23;
              if ( (flags & 0x40) != 0 )
                LODWORD(v24) = *((__int16 *)v23 - 2);
              else
                LODWORD(v24) = *((unsigned __int16 *)v23 - 2);
              v24 = (int)v24;
LABEL_157:
              if ( (flags & 0x40) != 0 && v24 < 0 )
              {
                v24 = -v24;
                flags |= 0x100u;
              }
              v31 = HIDWORD(v24);
              v6 = v24;
              if ( (flags & 0x9000) == 0 )
                v31 = 0;
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
              if ( !(v31 | (unsigned int)v24) )
                prefixlen = 0;
              for ( j = &buffer.sz[511]; ; --j )
              {
                v33 = precision--;
                if ( v33 <= 0 && !(v31 | v6) )
                  break;
                v45 = __PAIR64__(v31, v6);
                v34 = __PAIR64__(v31, v6) % radix;
                v35 = v34 + 48;
                count = HIDWORD(v34);
                v31 = (v45 / radix) >> 32;
                v6 = v45 / radix;
                if ( v35 > 57 )
                  LOBYTE(v35) = hexadd + v35;
                *j = v35;
              }
              v36 = (char *)(&buffer.sz[511] - j);
              v37 = j + 1;
              radix = (int)v36;
              text.sz = v37;
              if ( (flags & 0x200) != 0 && (!v36 || *v37 != 48) )
              {
                *--text.sz = 48;
                v22 = (signed int)(v36 + 1);
                goto LABEL_189;
              }
LABEL_190:
              if ( no_output )
                goto LABEL_216;
              if ( (flags & 0x40) != 0 )
              {
                if ( (flags & 0x100) != 0 )
                {
                  prefix[0] = 45;
                  goto LABEL_198;
                }
                if ( (flags & 1) != 0 )
                {
                  prefix[0] = 43;
                  goto LABEL_198;
                }
                if ( (flags & 2) != 0 )
                {
                  prefix[0] = 32;
LABEL_198:
                  prefixlen = 1;
                }
              }
              v39 = fldwidth - radix - prefixlen;
              if ( (flags & 0xC) == 0 )
                write_multi_char(&charsout, 32, fldwidth - radix - prefixlen, f);
              v6 = (int)f;
              write_string(prefix, f, &charsout, prefixlen);
              if ( (flags & 8) != 0 && (flags & 4) == 0 )
                write_multi_char(&charsout, 48, v39, (_iobuf *)v6);
              if ( bufferiswide && radix > 0 )
              {
                v40 = (wchar_t *)text.sz;
                count = radix;
                while ( 1 )
                {
                  v41 = *v40;
                  --count;
                  ++v40;
                  if ( wctomb_s(&retval, L_buffer, 6u, v41) || !retval )
                    break;
                  write_string(L_buffer, (_iobuf *)v6, &charsout, retval);
                  if ( !count )
                    goto LABEL_213;
                }
                charsout = -1;
              }
              else
              {
                write_string(text.sz, (_iobuf *)v6, &charsout, radix);
              }
LABEL_213:
              if ( charsout >= 0 && (flags & 4) != 0 )
                write_multi_char(&charsout, 32, v39, (_iobuf *)v6);
              goto LABEL_216;
            }
            LODWORD(v24) = *((_DWORD *)v23 - 1);
            if ( (flags & 0x40) != 0 )
              v24 = (int)v24;
            else
              HIDWORD(v24) = 0;
          }
          v64 = v23;
          goto LABEL_157;
        }
        p_charsout = *(_DWORD *)v6;
        v6 += 4;
        v64 = (char *)v6;
        if ( !_get_printf_count_output() )
          goto LABEL_2;
        if ( (flags & 0x20) != 0 )
          *(_WORD *)p_charsout = charsout;
        else
          *(_DWORD *)p_charsout = charsout;
        no_output = 1;
LABEL_216:
        if ( heapbuf )
        {
          free(heapbuf);
          heapbuf = 0;
        }
LABEL_218:
        v4 = v58;
        v42 = *v58;
        v68 = v42;
        if ( !v42 )
          goto LABEL_220;
        v6 = (int)v64;
        v11 = v42;
        break;
      default:
        goto LABEL_218;
    }
  }
LABEL_220:
  p_charsout = 0;
  if ( state == ST_NORMAL || state == ST_TYPE )
  {
LABEL_222:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return charsout;
  }
  else
  {
LABEL_2:
    *_errno() = 22;
    _invalid_parameter((unsigned int)v4, v6, p_charsout);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return -1;
  }
}
