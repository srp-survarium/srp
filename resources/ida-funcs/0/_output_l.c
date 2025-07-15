int __cdecl _output_l(_iobuf *stream, const char *format, localeinfo_struct *plocinfo, char *argptr)
{
  const char *v4; // ebx
  int v5; // esi
  char *v6; // edi
  int v8; // eax
  ioinfo *v9; // ecx
  ioinfo *v10; // eax
  int v11; // ecx
  signed __int8 v12; // dl
  int v13; // eax
  char v14; // al
  bool v15; // zf
  int v16; // eax
  unsigned __int8 *v17; // ebx
  int v18; // ecx
  char *v19; // eax
  __int16 *v20; // eax
  char *v21; // ecx
  int v22; // eax
  __int64 v23; // rax
  char *v24; // edi
  int v25; // esi
  void *v26; // eax
  int v27; // eax
  char *v28; // edi
  void (__cdecl *v29)(_DWORD *, unsigned __int8 *, int, int, int, int, _LocaleUpdate *); // eax
  void (__cdecl *v30)(unsigned __int8 *, _LocaleUpdate *); // eax
  void (__cdecl *v31)(unsigned __int8 *, _LocaleUpdate *); // eax
  unsigned int v32; // ebx
  char *j; // esi
  int v34; // eax
  unsigned __int64 v35; // rcx
  int v36; // ecx
  char *v37; // eax
  char *v38; // esi
  char *i; // eax
  int v40; // ebx
  _iobuf *v41; // edi
  wchar_t *v42; // esi
  wchar_t v43; // ax
  signed __int8 v44; // al
  int v45; // [esp-14h] [ebp-298h]
  int v46; // [esp-10h] [ebp-294h]
  unsigned __int64 v47; // [esp-10h] [ebp-294h]
  int v48; // [esp-Ch] [ebp-290h]
  int v49; // [esp-8h] [ebp-28Ch]
  _DWORD v50[2]; // [esp+Ch] [ebp-278h] BYREF
  int v51; // [esp+14h] [ebp-270h]
  int v52; // [esp+18h] [ebp-26Ch]
  int v53; // [esp+1Ch] [ebp-268h] BYREF
  int v54; // [esp+24h] [ebp-260h]
  _LocaleUpdate v55; // [esp+28h] [ebp-25Ch] BYREF
  _iobuf *v56; // [esp+38h] [ebp-24Ch]
  int v57; // [esp+3Ch] [ebp-248h]
  void *pointer; // [esp+40h] [ebp-244h]
  int v59; // [esp+44h] [ebp-240h]
  const char *v60; // [esp+48h] [ebp-23Ch]
  int v61; // [esp+4Ch] [ebp-238h]
  int v62; // [esp+50h] [ebp-234h]
  int v63; // [esp+54h] [ebp-230h]
  char v64[4]; // [esp+58h] [ebp-22Ch] BYREF
  int v65; // [esp+5Ch] [ebp-228h] BYREF
  char *v66; // [esp+60h] [ebp-224h]
  int pRetValue; // [esp+64h] [ebp-220h] BYREF
  char *v68; // [esp+68h] [ebp-21Ch]
  int v69; // [esp+6Ch] [ebp-218h]
  signed __int8 v70; // [esp+73h] [ebp-211h]
  int v71; // [esp+74h] [ebp-210h]
  char dst[511]; // [esp+78h] [ebp-20Ch] BYREF
  char v73; // [esp+277h] [ebp-Dh] BYREF
  char v74[8]; // [esp+278h] [ebp-Ch] BYREF

  v4 = format;
  v5 = (int)stream;
  v6 = argptr;
  v56 = stream;
  v66 = argptr;
  v57 = 0;
  v71 = 0;
  v62 = 0;
  v69 = 0;
  v63 = 0;
  v59 = 0;
  v61 = 0;
  _LocaleUpdate::_LocaleUpdate(&v55, plocinfo);
  if ( stream
    && ((stream->_flag & 0x40) != 0
     || ((v8 = _fileno((int)format, (int)argptr, stream), v8 == -1) || v8 == -2
       ? (v9 = &__badioinfo)
       : (v5 = v8 >> 5, v9 = (ioinfo *)((char *)__pioinfo[v8 >> 5] + 64 * (v8 & 0x1F))),
         (*((_BYTE *)v9 + 36) & 0x7F) == 0
      && (v8 == -1 || v8 == -2
        ? (v10 = &__badioinfo)
        : (v10 = (ioinfo *)((char *)__pioinfo[v8 >> 5] + 64 * (v8 & 0x1F))),
          *((char *)v10 + 36) >= 0)))
    && (v11 = 0, format) )
  {
    v12 = *format;
    v65 = 0;
    pRetValue = 0;
    pointer = 0;
    v70 = v12;
    if ( v12 )
    {
      while ( 1 )
      {
        v60 = ++v4;
        if ( v65 < 0 )
          break;
        if ( (unsigned __int8)(v12 - 32) > 0x58u )
          v13 = 0;
        else
          v13 = byte_6B6F90[v12] & 0xF;
        v52 = __lookuptable[8 * v13 + v11] >> 4;
        switch ( v52 )
        {
          case 0:
            goto NORMAL_STATE;
          case 1:
            v69 = -1;
            v51 = 0;
            v59 = 0;
            v62 = 0;
            v63 = 0;
            v71 = 0;
            v61 = 0;
            goto LABEL_218;
          case 2:
            switch ( v12 )
            {
              case ' ':
                v71 |= 2u;
                break;
              case '#':
                v71 |= 0x80u;
                break;
              case '+':
                v71 |= 1u;
                break;
              case '-':
                v71 |= 4u;
                break;
              case '0':
                v71 |= 8u;
                break;
            }
            goto LABEL_218;
          case 3:
            if ( v12 == 42 )
            {
              v66 = v6 + 4;
              v62 = *(_DWORD *)v6;
              if ( v62 < 0 )
              {
                v71 |= 4u;
                v62 = -v62;
              }
            }
            else
            {
              v62 = 10 * v62 + v12 - 48;
            }
            goto LABEL_218;
          case 4:
            v69 = 0;
            goto LABEL_218;
          case 5:
            if ( v12 == 42 )
            {
              v66 = v6 + 4;
              v69 = *(_DWORD *)v6;
              if ( v69 < 0 )
                v69 = -1;
            }
            else
            {
              v69 = 10 * v69 + v12 - 48;
            }
            goto LABEL_218;
          case 6:
            switch ( v12 )
            {
              case 'I':
                v14 = *v4;
                if ( *v4 == 54 && v4[1] == 52 )
                {
                  v71 |= 0x8000u;
                  v60 = v4 + 2;
                }
                else if ( v14 == 51 && v4[1] == 50 )
                {
                  v71 &= ~0x8000u;
                  v60 = v4 + 2;
                }
                else if ( v14 != 100 && v14 != 105 && v14 != 111 && v14 != 117 && v14 != 120 && v14 != 88 )
                {
                  v52 = 0;
NORMAL_STATE:
                  v61 = 0;
                  v16 = _isleadbyte_l(v12, &v55.localeinfo);
                  v15 = v16 == 0;
                  LOBYTE(v16) = v70;
                  if ( !v15 )
                  {
                    v5 = (int)&v65;
                    write_char(v16, v56, &v65, (int)v4, (int)v6);
                    LOBYTE(v16) = *v4++;
                    v60 = v4;
                    if ( !(_BYTE)v16 )
                      goto LABEL_2;
                  }
                  write_char(v16, v56, &v65, (int)v4, (int)v6);
                }
                break;
              case 'h':
                v71 |= 0x20u;
                break;
              case 'l':
                if ( *v4 == 108 )
                {
                  v71 |= 0x1000u;
                  v60 = v4 + 1;
                }
                else
                {
                  v71 |= 0x10u;
                }
                break;
              case 'w':
                v71 |= 0x800u;
                break;
            }
            goto LABEL_218;
          case 7:
            if ( v12 <= 100 )
            {
              if ( v12 == 100 )
              {
LABEL_118:
                v71 |= 0x40u;
                goto LABEL_119;
              }
              if ( v12 > 83 )
              {
                if ( v12 == 88 )
                  goto LABEL_140;
                if ( v12 == 90 )
                {
                  v20 = *(__int16 **)v6;
                  v6 += 4;
                  v66 = v6;
                  if ( v20 && (v21 = (char *)*((_DWORD *)v20 + 1)) != 0 )
                  {
                    v22 = *v20;
                    v68 = v21;
                    if ( (v71 & 0x800) != 0 )
                    {
                      v22 /= 2;
                      v61 = 1;
                    }
                    else
                    {
                      v61 = 0;
                    }
                  }
                  else
                  {
                    v68 = __nullstring;
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
                  if ( (v71 & 0x830) == 0 )
                    v71 |= 0x800u;
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
                  if ( (v71 & 0x830) == 0 )
                    v71 |= 0x800u;
LABEL_93:
                  v6 += 4;
                  v66 = v6;
                  if ( (v71 & 0x810) != 0 )
                  {
                    if ( wctomb_s(&pRetValue, dst, 512, *((_WORD *)v6 - 2)) )
                      v59 = 1;
                  }
                  else
                  {
                    dst[0] = *(v6 - 4);
                    pRetValue = 1;
                  }
                  v68 = dst;
                  goto LABEL_190;
                }
LABEL_76:
                v12 += 32;
                v51 = 1;
                v70 = v12;
              }
LABEL_77:
              v71 |= 0x40u;
              v17 = (unsigned __int8 *)dst;
              v68 = dst;
              v54 = 512;
              if ( v69 >= 0 )
              {
                if ( v69 )
                {
                  if ( v69 > 512 )
                    v69 = 512;
                  if ( v69 > 163 )
                  {
                    v25 = v69 + 349;
                    v26 = _malloc_crt(v69 + 349);
                    v12 = v70;
                    pointer = v26;
                    if ( v26 )
                    {
                      v68 = (char *)v26;
                      v54 = v25;
                      v17 = (unsigned __int8 *)v26;
                    }
                    else
                    {
                      v69 = 163;
                    }
                  }
                }
                else
                {
                  v69 = v12 == 103;
                }
              }
              else
              {
                v69 = 6;
              }
              v27 = *(_DWORD *)v6;
              v28 = v6 + 8;
              v50[0] = v27;
              v50[1] = *((_DWORD *)v28 - 1);
              v49 = v51;
              v48 = v69;
              v66 = v28;
              v46 = v12;
              v45 = v54;
              v29 = (void (__cdecl *)(_DWORD *, unsigned __int8 *, int, int, int, int, _LocaleUpdate *))_decode_pointer(codedptr);
              v29(v50, v17, v45, v46, v48, v49, &v55);
              v6 = (char *)(v71 & 0x80);
              if ( (v71 & 0x80) != 0 && !v69 )
              {
                v30 = (void (__cdecl *)(unsigned __int8 *, _LocaleUpdate *))_decode_pointer(off_86F6AC);
                v30(v17, &v55);
              }
              if ( v70 == 103 && !v6 )
              {
                v31 = (void (__cdecl *)(unsigned __int8 *, _LocaleUpdate *))_decode_pointer(off_86F6A8);
                v31(v17, &v55);
              }
              if ( *v17 == 45 )
              {
                v71 |= 0x100u;
                v68 = (char *)++v17;
              }
              strlen(v17);
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
                  v57 = 39;
                  goto COMMON_HEX;
                }
LABEL_119:
                pRetValue = 10;
                goto COMMON_INT;
              }
LABEL_83:
              v18 = v69;
              if ( v69 == -1 )
                v18 = 0x7FFFFFFF;
              v66 = v6 + 4;
              v6 = *(char **)v6;
              v68 = v6;
              if ( (v71 & 0x810) != 0 )
              {
                if ( !v6 )
                  v68 = (char *)__wnullstring;
                v19 = v68;
                v61 = 1;
                while ( v18 )
                {
                  --v18;
                  if ( !*(_WORD *)v19 )
                    break;
                  v19 += 2;
                }
                v22 = (v19 - v68) >> 1;
              }
              else
              {
                if ( !v6 )
                  v68 = __nullstring;
                for ( i = v68; v18; ++i )
                {
                  --v18;
                  if ( !*i )
                    break;
                }
                v22 = i - v68;
              }
LABEL_189:
              pRetValue = v22;
              goto LABEL_190;
            }
            if ( v12 == 112 )
            {
              v69 = 8;
LABEL_140:
              v57 = 7;
COMMON_HEX:
              pRetValue = 16;
              if ( (v71 & 0x80u) != 0 )
              {
                v64[0] = 48;
                v64[1] = v57 + 81;
                v63 = 2;
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
              pRetValue = 8;
              if ( (v71 & 0x80u) != 0 )
                v71 |= 0x200u;
COMMON_INT:
              if ( (v71 & 0x8000) != 0 || (v71 & 0x1000) != 0 )
              {
                v23 = *(_QWORD *)v6;
                v24 = v6 + 8;
              }
              else
              {
                v24 = v6 + 4;
                if ( (v71 & 0x20) != 0 )
                {
                  v66 = v24;
                  if ( (v71 & 0x40) != 0 )
                    LODWORD(v23) = *((__int16 *)v24 - 2);
                  else
                    LODWORD(v23) = *((unsigned __int16 *)v24 - 2);
                  v23 = (int)v23;
LABEL_157:
                  if ( (v71 & 0x40) != 0 && v23 < 0 )
                  {
                    v23 = -v23;
                    v71 |= 0x100u;
                  }
                  v32 = HIDWORD(v23);
                  v6 = (char *)v23;
                  if ( (v71 & 0x9000) == 0 )
                    v32 = 0;
                  if ( v69 >= 0 )
                  {
                    v71 &= ~8u;
                    if ( v69 > 512 )
                      v69 = 512;
                  }
                  else
                  {
                    v69 = 1;
                  }
                  if ( !(v32 | (unsigned int)v23) )
                    v63 = 0;
                  for ( j = &v73; ; --j )
                  {
                    v34 = v69--;
                    if ( v34 <= 0 && !(v32 | (unsigned int)v6) )
                      break;
                    v47 = __PAIR64__(v32, (unsigned int)v6);
                    v35 = __PAIR64__(v32, (unsigned int)v6) % pRetValue;
                    v36 = v35 + 48;
                    v54 = HIDWORD(v35);
                    v32 = (v47 / pRetValue) >> 32;
                    v6 = (char *)(v47 / pRetValue);
                    if ( v36 > 57 )
                      LOBYTE(v36) = v57 + v36;
                    *j = v36;
                  }
                  v37 = (char *)(&v73 - j);
                  v38 = j + 1;
                  pRetValue = (int)v37;
                  v68 = v38;
                  if ( (v71 & 0x200) != 0 && (!v37 || *v38 != 48) )
                  {
                    *--v68 = 48;
                    v22 = (int)(v37 + 1);
                    goto LABEL_189;
                  }
LABEL_190:
                  if ( v59 )
                    goto LABEL_216;
                  if ( (v71 & 0x40) != 0 )
                  {
                    if ( (v71 & 0x100) != 0 )
                    {
                      v64[0] = 45;
                      goto LABEL_198;
                    }
                    if ( (v71 & 1) != 0 )
                    {
                      v64[0] = 43;
                      goto LABEL_198;
                    }
                    if ( (v71 & 2) != 0 )
                    {
                      v64[0] = 32;
LABEL_198:
                      v63 = 1;
                    }
                  }
                  v40 = v62 - pRetValue - v63;
                  if ( (v71 & 0xC) == 0 )
                    write_multi_char(&v65, v40, (int)v6, 32, v62 - pRetValue - v63, v56);
                  v41 = v56;
                  write_string(v64, v56, &v65, v63);
                  if ( (v71 & 8) != 0 && (v71 & 4) == 0 )
                    write_multi_char(&v65, v40, (int)v41, 48, v40, v41);
                  if ( v61 && pRetValue > 0 )
                  {
                    v42 = (wchar_t *)v68;
                    v54 = pRetValue;
                    while ( 1 )
                    {
                      v43 = *v42;
                      --v54;
                      ++v42;
                      if ( wctomb_s(&v53, v74, 6, v43) || !v53 )
                        break;
                      write_string(v74, v41, &v65, v53);
                      if ( !v54 )
                        goto LABEL_213;
                    }
                    v65 = -1;
                  }
                  else
                  {
                    write_string(v68, v41, &v65, pRetValue);
                  }
LABEL_213:
                  if ( v65 >= 0 && (v71 & 4) != 0 )
                    write_multi_char(&v65, v40, (int)v41, 32, v40, v41);
                  goto LABEL_216;
                }
                LODWORD(v23) = *((_DWORD *)v24 - 1);
                if ( (v71 & 0x40) != 0 )
                  v23 = (int)v23;
                else
                  HIDWORD(v23) = 0;
              }
              v66 = v24;
              goto LABEL_157;
            }
            v5 = *(_DWORD *)v6;
            v6 += 4;
            v66 = v6;
            if ( !_get_printf_count_output() )
              goto LABEL_2;
            if ( (v71 & 0x20) != 0 )
              *(_WORD *)v5 = v65;
            else
              *(_DWORD *)v5 = v65;
            v59 = 1;
LABEL_216:
            if ( pointer )
            {
              free(pointer);
              pointer = 0;
            }
LABEL_218:
            v4 = v60;
            v44 = *v60;
            v70 = v44;
            if ( !v44 )
              goto LABEL_220;
            v11 = v52;
            v6 = v66;
            v12 = v44;
            break;
          default:
            goto LABEL_218;
        }
      }
    }
LABEL_220:
    if ( v55.updated )
      v55.ptd->_ownlocale &= ~2u;
    return v65;
  }
  else
  {
LABEL_2:
    *_errno() = 22;
    _invalid_parameter((int)v4, (int)v6, v5);
    if ( v55.updated )
      v55.ptd->_ownlocale &= ~2u;
    return -1;
  }
}
