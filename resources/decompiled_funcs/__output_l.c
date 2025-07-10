int __cdecl _output_l(_iobuf *stream, const char *format, localeinfo_struct *plocinfo, char *argptr)
{
  const char *v4; // ebx
  unsigned int p_charsout; // esi
  int *v6; // edi
  int v8; // eax
  ioinfo *v9; // ecx
  ioinfo *v10; // eax
  STATE v11; // ecx
  char v12; // dl
  int v13; // eax
  char v14; // al
  bool v15; // zf
  char v16; // al
  _output_l::__l2::<unnamed_type_buffer> *p_buffer; // ebx
  int v18; // ecx
  _output_l::__l2::<unnamed_type_text> v19; // edi
  char *sz; // eax
  char *v21; // edi
  __int16 *v22; // eax
  _output_l::__l2::<unnamed_type_text> v23; // ecx
  signed int v24; // eax
  __int64 v25; // rax
  int *v26; // edi
  int v27; // esi
  char *v28; // eax
  int v29; // eax
  char *v30; // edi
  void (__cdecl *v31)(_CRT_DOUBLE *, _output_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *); // eax
  int v32; // edi
  void (__cdecl *v33)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  void (__cdecl *v34)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  unsigned int v35; // ebx
  unsigned int v36; // edi
  char *j; // esi
  int v38; // eax
  unsigned __int64 v39; // rcx
  int v40; // ecx
  char *v41; // eax
  _BYTE *v42; // esi
  _BYTE *i; // eax
  int v44; // ebx
  _iobuf *v45; // edi
  wchar_t *v46; // esi
  wchar_t v47; // ax
  char v48; // al
  int v49; // [esp-14h] [ebp-298h]
  int v50; // [esp-10h] [ebp-294h]
  unsigned __int64 v51; // [esp-10h] [ebp-294h]
  int v52; // [esp-Ch] [ebp-290h]
  int v53; // [esp-8h] [ebp-28Ch]
  _CRT_DOUBLE tmp; // [esp+Ch] [ebp-278h] BYREF
  int capexp; // [esp+14h] [ebp-270h]
  STATE state; // [esp+18h] [ebp-26Ch]
  int retval; // [esp+1Ch] [ebp-268h] BYREF
  int count; // [esp+24h] [ebp-260h]
  _LocaleUpdate _loc_update; // [esp+28h] [ebp-25Ch] BYREF
  _iobuf *f; // [esp+38h] [ebp-24Ch]
  int hexadd; // [esp+3Ch] [ebp-248h]
  char *heapbuf; // [esp+40h] [ebp-244h]
  int no_output; // [esp+44h] [ebp-240h]
  char *v64; // [esp+48h] [ebp-23Ch]
  int bufferiswide; // [esp+4Ch] [ebp-238h]
  int fldwidth; // [esp+50h] [ebp-234h]
  int prefixlen; // [esp+54h] [ebp-230h]
  char prefix[4]; // [esp+58h] [ebp-22Ch] BYREF
  int charsout; // [esp+5Ch] [ebp-228h] BYREF
  char *v70; // [esp+60h] [ebp-224h]
  int radix; // [esp+64h] [ebp-220h] BYREF
  _output_l::__l2::<unnamed_type_text> text; // [esp+68h] [ebp-21Ch]
  int precision; // [esp+6Ch] [ebp-218h]
  char v74; // [esp+73h] [ebp-211h]
  int flags; // [esp+74h] [ebp-210h]
  _output_l::__l2::<unnamed_type_buffer> buffer; // [esp+78h] [ebp-20Ch] BYREF
  char L_buffer[8]; // [esp+278h] [ebp-Ch] BYREF

  v4 = format;
  p_charsout = (unsigned int)stream;
  v6 = (int *)argptr;
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
  if ( stream
    && ((stream->_flag & 0x40) != 0
     || ((v8 = _fileno((unsigned int)format, (unsigned int)argptr, stream), v8 == -1) || v8 == -2
       ? (v9 = &__badioinfo)
       : (p_charsout = v8 >> 5, v9 = (ioinfo *)((char *)__pioinfo[v8 >> 5] + 64 * (v8 & 0x1F))),
         (*((_BYTE *)v9 + 36) & 0x7F) == 0
      && (v8 == -1 || v8 == -2
        ? (v10 = &__badioinfo)
        : (v10 = (ioinfo *)((char *)__pioinfo[v8 >> 5] + 64 * (v8 & 0x1F))),
          *((char *)v10 + 36) >= 0)))
    && (v11 = ST_NORMAL, format) )
  {
    v12 = *format;
    charsout = 0;
    radix = 0;
    heapbuf = 0;
    v74 = v12;
    if ( v12 )
    {
      while ( 1 )
      {
        v64 = (char *)++v4;
        if ( charsout < 0 )
          break;
        if ( (unsigned __int8)(v12 - 32) > 0x58u )
          v13 = 0;
        else
          v13 = byte_81EE40[v12] & 0xF;
        state = __lookuptable[8 * v13 + v11] >> 4;
        switch ( state )
        {
          case ST_NORMAL:
            goto NORMAL_STATE;
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
            switch ( v12 )
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
            if ( v12 == 42 )
            {
              v70 = (char *)(v6 + 1);
              fldwidth = *v6;
              if ( fldwidth < 0 )
              {
                flags |= 4u;
                fldwidth = -fldwidth;
              }
            }
            else
            {
              fldwidth = 10 * fldwidth + v12 - 48;
            }
            goto LABEL_218;
          case ST_DOT:
            precision = 0;
            goto LABEL_218;
          case ST_PRECIS:
            if ( v12 == 42 )
            {
              v70 = (char *)(v6 + 1);
              precision = *v6;
              if ( precision < 0 )
                precision = -1;
            }
            else
            {
              precision = 10 * precision + v12 - 48;
            }
            goto LABEL_218;
          case ST_SIZE:
            switch ( v12 )
            {
              case 'I':
                v14 = *v4;
                if ( *v4 == 54 && v4[1] == 52 )
                {
                  flags |= 0x8000u;
                  v64 = (char *)(v4 + 2);
                }
                else if ( v14 == 51 && v4[1] == 50 )
                {
                  flags &= ~0x8000u;
                  v64 = (char *)(v4 + 2);
                }
                else if ( v14 != 100 && v14 != 105 && v14 != 111 && v14 != 117 && v14 != 120 && v14 != 88 )
                {
                  state = ST_NORMAL;
NORMAL_STATE:
                  bufferiswide = 0;
                  v15 = _isleadbyte_l((unsigned __int8)v12, &_loc_update.localeinfo) == 0;
                  v16 = v74;
                  if ( !v15 )
                  {
                    p_charsout = (unsigned int)&charsout;
                    write_char(v74, f, &charsout);
                    v16 = *v4++;
                    v64 = (char *)v4;
                    if ( !v16 )
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
                  v64 = (char *)(v4 + 1);
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
            if ( v12 <= 100 )
            {
              if ( v12 == 100 )
              {
LABEL_118:
                flags |= 0x40u;
                goto LABEL_119;
              }
              if ( v12 > 83 )
              {
                if ( v12 == 88 )
                  goto LABEL_140;
                if ( v12 == 90 )
                {
                  v22 = (__int16 *)*v6;
                  v70 = (char *)(v6 + 1);
                  if ( v22 && (v23.sz = *(char **)(v22 + 2)) != 0 )
                  {
                    v24 = *v22;
                    text.sz = v23.sz;
                    if ( (flags & 0x800) != 0 )
                    {
                      v24 /= 2;
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
                if ( v12 != 97 )
                {
                  if ( v12 != 99 )
                    goto LABEL_190;
                  goto LABEL_93;
                }
              }
              else
              {
                if ( v12 == 83 )
                {
                  if ( (flags & 0x830) == 0 )
                    flags |= 0x800u;
                  goto LABEL_83;
                }
                if ( v12 != 65 )
                {
                  if ( v12 != 67 )
                  {
                    if ( v12 != 69 && v12 != 71 )
                      goto LABEL_190;
                    goto LABEL_76;
                  }
                  if ( (flags & 0x830) == 0 )
                    flags |= 0x800u;
LABEL_93:
                  v21 = (char *)(v6 + 1);
                  v70 = v21;
                  if ( (flags & 0x810) != 0 )
                  {
                    if ( wctomb_s(&radix, buffer.sz, 0x200u, *((_WORD *)v21 - 2)) )
                      no_output = 1;
                  }
                  else
                  {
                    buffer.sz[0] = *(v21 - 4);
                    radix = 1;
                  }
                  text.sz = (char *)&buffer;
                  goto LABEL_190;
                }
LABEL_76:
                v12 += 32;
                capexp = 1;
                v74 = v12;
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
                    v27 = precision + 349;
                    v28 = (char *)_malloc_crt(precision + 349);
                    v12 = v74;
                    heapbuf = v28;
                    if ( v28 )
                    {
                      text.sz = v28;
                      count = v27;
                      p_buffer = (_output_l::__l2::<unnamed_type_buffer> *)v28;
                    }
                    else
                    {
                      precision = 163;
                    }
                  }
                }
                else
                {
                  precision = v12 == 103;
                }
              }
              else
              {
                precision = 6;
              }
              v29 = *v6;
              v30 = (char *)(v6 + 2);
              LODWORD(tmp.x) = v29;
              HIDWORD(tmp.x) = *((_DWORD *)v30 - 1);
              v53 = capexp;
              v52 = precision;
              v70 = v30;
              v50 = v12;
              v49 = count;
              v31 = (void (__cdecl *)(_CRT_DOUBLE *, _output_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *))_decode_pointer(codedptr);
              v31(&tmp, p_buffer, v49, v50, v52, v53, &_loc_update);
              v32 = flags & 0x80;
              if ( (flags & 0x80) != 0 && !precision )
              {
                v33 = (void (__cdecl *)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))_decode_pointer(off_9AEB3C);
                v33(p_buffer, &_loc_update);
              }
              if ( v74 == 103 && !v32 )
              {
                v34 = (void (__cdecl *)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))_decode_pointer(off_9AEB38);
                v34(p_buffer, &_loc_update);
              }
              if ( p_buffer->sz[0] == 45 )
              {
                flags |= 0x100u;
                p_buffer = (_output_l::__l2::<unnamed_type_buffer> *)((char *)p_buffer + 1);
                text.sz = (char *)p_buffer;
              }
              strlen((unsigned __int8 *)p_buffer);
              goto LABEL_189;
            }
            if ( v12 > 112 )
            {
              if ( v12 != 115 )
              {
                if ( v12 != 117 )
                {
                  if ( v12 != 120 )
                    goto LABEL_190;
                  hexadd = 39;
                  goto COMMON_HEX;
                }
LABEL_119:
                radix = 10;
                goto COMMON_INT;
              }
LABEL_83:
              v18 = precision;
              if ( precision == -1 )
                v18 = 0x7FFFFFFF;
              v70 = (char *)(v6 + 1);
              v19.sz = (char *)*v6;
              text.sz = v19.sz;
              if ( (flags & 0x810) != 0 )
              {
                if ( !v19.sz )
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
                v24 = (sz - text.sz) >> 1;
              }
              else
              {
                if ( !v19.sz )
                  text.sz = __nullstring;
                for ( i = text.sz; v18; ++i )
                {
                  --v18;
                  if ( !*i )
                    break;
                }
                v24 = i - text.sz;
              }
LABEL_189:
              radix = v24;
              goto LABEL_190;
            }
            if ( v12 == 112 )
            {
              precision = 8;
LABEL_140:
              hexadd = 7;
COMMON_HEX:
              radix = 16;
              if ( (flags & 0x80u) != 0 )
              {
                prefix[0] = 48;
                prefix[1] = hexadd + 81;
                prefixlen = 2;
              }
              goto COMMON_INT;
            }
            if ( v12 < 101 )
              goto LABEL_190;
            if ( v12 <= 103 )
              goto LABEL_77;
            if ( v12 == 105 )
              goto LABEL_118;
            if ( v12 != 110 )
            {
              if ( v12 != 111 )
                goto LABEL_190;
              radix = 8;
              if ( (flags & 0x80u) != 0 )
                flags |= 0x200u;
COMMON_INT:
              if ( (flags & 0x8000) != 0 || (flags & 0x1000) != 0 )
              {
                v25 = *(_QWORD *)v6;
                v26 = v6 + 2;
              }
              else
              {
                v26 = v6 + 1;
                if ( (flags & 0x20) != 0 )
                {
                  v70 = (char *)v26;
                  if ( (flags & 0x40) != 0 )
                    LODWORD(v25) = *((__int16 *)v26 - 2);
                  else
                    LODWORD(v25) = *((unsigned __int16 *)v26 - 2);
                  v25 = (int)v25;
LABEL_157:
                  if ( (flags & 0x40) != 0 && v25 < 0 )
                  {
                    v25 = -v25;
                    flags |= 0x100u;
                  }
                  v35 = HIDWORD(v25);
                  v36 = v25;
                  if ( (flags & 0x9000) == 0 )
                    v35 = 0;
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
                  if ( !(v35 | (unsigned int)v25) )
                    prefixlen = 0;
                  for ( j = &buffer.sz[511]; ; --j )
                  {
                    v38 = precision--;
                    if ( v38 <= 0 && !(v35 | v36) )
                      break;
                    v51 = __PAIR64__(v35, v36);
                    v39 = __PAIR64__(v35, v36) % radix;
                    v40 = v39 + 48;
                    count = HIDWORD(v39);
                    v35 = (v51 / radix) >> 32;
                    v36 = v51 / radix;
                    if ( v40 > 57 )
                      LOBYTE(v40) = hexadd + v40;
                    *j = v40;
                  }
                  v41 = (char *)(&buffer.sz[511] - j);
                  v42 = j + 1;
                  radix = (int)v41;
                  text.sz = v42;
                  if ( (flags & 0x200) != 0 && (!v41 || *v42 != 48) )
                  {
                    *--text.sz = 48;
                    v24 = (signed int)(v41 + 1);
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
                  v44 = fldwidth - radix - prefixlen;
                  if ( (flags & 0xC) == 0 )
                    write_multi_char(32, fldwidth - radix - prefixlen, f, &charsout);
                  v45 = f;
                  write_string(prefix, prefixlen, f, &charsout);
                  if ( (flags & 8) != 0 && (flags & 4) == 0 )
                    write_multi_char(48, v44, v45, &charsout);
                  if ( bufferiswide && radix > 0 )
                  {
                    v46 = (wchar_t *)text.sz;
                    count = radix;
                    while ( 1 )
                    {
                      v47 = *v46;
                      --count;
                      ++v46;
                      if ( wctomb_s(&retval, L_buffer, 6u, v47) || !retval )
                        break;
                      write_string(L_buffer, retval, v45, &charsout);
                      if ( !count )
                        goto LABEL_213;
                    }
                    charsout = -1;
                  }
                  else
                  {
                    write_string(text.sz, radix, v45, &charsout);
                  }
LABEL_213:
                  if ( charsout >= 0 && (flags & 4) != 0 )
                    write_multi_char(32, v44, v45, &charsout);
                  goto LABEL_216;
                }
                LODWORD(v25) = *(v26 - 1);
                if ( (flags & 0x40) != 0 )
                  v25 = (int)v25;
                else
                  HIDWORD(v25) = 0;
              }
              v70 = (char *)v26;
              goto LABEL_157;
            }
            p_charsout = *v6++;
            v70 = (char *)v6;
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
            v4 = v64;
            v48 = *v64;
            v74 = v48;
            if ( !v48 )
              goto LABEL_220;
            v11 = state;
            v6 = (int *)v70;
            v12 = v48;
            break;
          default:
            goto LABEL_218;
        }
      }
    }
LABEL_220:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return charsout;
  }
  else
  {
LABEL_2:
    *_errno() = 22;
    _invalid_parameter((unsigned int)v4, (unsigned int)v6, p_charsout);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return -1;
  }
}
