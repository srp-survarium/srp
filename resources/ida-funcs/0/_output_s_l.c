int __cdecl _output_s_l(_iobuf *stream, const char *format, localeinfo_struct *plocinfo, char *argptr)
{
  const char *v4; // ebx
  int v5; // esi
  int v6; // edi
  int v8; // eax
  ioinfo *v9; // ecx
  ioinfo *v10; // eax
  signed __int8 v11; // dl
  int v12; // eax
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
  char *v23; // edi
  __int64 v24; // rax
  int v25; // esi
  void *v26; // eax
  char *v27; // edi
  void (__cdecl *v28)(_DWORD *, unsigned __int8 *, int, int, int, int, _LocaleUpdate *); // eax
  void (__cdecl *v29)(unsigned __int8 *, _LocaleUpdate *); // eax
  void (__cdecl *v30)(unsigned __int8 *, _LocaleUpdate *); // eax
  unsigned int v31; // ebx
  char *j; // esi
  int v33; // eax
  unsigned __int64 v34; // rcx
  int v35; // ecx
  char *v36; // eax
  char *v37; // esi
  char *i; // eax
  int v39; // ebx
  wchar_t *v40; // esi
  wchar_t v41; // ax
  signed __int8 v42; // al
  int v43; // [esp-14h] [ebp-298h]
  int v44; // [esp-10h] [ebp-294h]
  unsigned __int64 v45; // [esp-10h] [ebp-294h]
  int v46; // [esp-Ch] [ebp-290h]
  int v47; // [esp-8h] [ebp-28Ch]
  _DWORD v48[2]; // [esp+Ch] [ebp-278h] BYREF
  int v49; // [esp+14h] [ebp-270h] BYREF
  int v50; // [esp+18h] [ebp-26Ch]
  int v51; // [esp+20h] [ebp-264h]
  _iobuf *v52; // [esp+24h] [ebp-260h]
  int v53; // [esp+28h] [ebp-25Ch]
  int v54; // [esp+2Ch] [ebp-258h]
  void *pointer; // [esp+30h] [ebp-254h]
  _LocaleUpdate v56; // [esp+34h] [ebp-250h] BYREF
  int v57; // [esp+44h] [ebp-240h]
  const char *v58; // [esp+48h] [ebp-23Ch]
  int v59; // [esp+4Ch] [ebp-238h]
  int v60; // [esp+50h] [ebp-234h]
  int v61; // [esp+54h] [ebp-230h]
  char v62[4]; // [esp+58h] [ebp-22Ch] BYREF
  int v63; // [esp+5Ch] [ebp-228h] BYREF
  char *v64; // [esp+60h] [ebp-224h]
  int pRetValue; // [esp+64h] [ebp-220h] BYREF
  char *v66; // [esp+68h] [ebp-21Ch]
  int v67; // [esp+6Ch] [ebp-218h]
  signed __int8 v68; // [esp+73h] [ebp-211h]
  int v69; // [esp+74h] [ebp-210h]
  char dst[511]; // [esp+78h] [ebp-20Ch] BYREF
  char v71; // [esp+277h] [ebp-Dh] BYREF
  char v72[8]; // [esp+278h] [ebp-Ch] BYREF

  v4 = format;
  v5 = (int)stream;
  v6 = (int)argptr;
  v52 = stream;
  v64 = argptr;
  v53 = 0;
  v69 = 0;
  v60 = 0;
  v67 = 0;
  v61 = 0;
  v54 = 0;
  v59 = 0;
  _LocaleUpdate::_LocaleUpdate(&v56, plocinfo);
  if ( !stream )
    goto LABEL_2;
  if ( (stream->_flag & 0x40) == 0 )
  {
    v8 = _fileno((int)format, (int)argptr, stream);
    if ( v8 == -1 || v8 == -2 )
    {
      v9 = &__badioinfo;
    }
    else
    {
      v5 = v8 >> 5;
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
  v63 = 0;
  pRetValue = 0;
  v57 = 0;
  pointer = 0;
  v68 = v11;
  if ( !v11 )
    goto LABEL_222;
  while ( 1 )
  {
    ++v4;
    v12 = 0;
    v58 = v4;
    if ( v63 < 0 )
      break;
    if ( (unsigned __int8)(v11 - 32) <= 0x58u )
      v12 = byte_6B6FF0[v11] & 0xF;
    v13 = __lookuptable_s[9 * v12 + v57] >> 4;
    v5 = 8;
    v57 = v13;
    if ( v13 == 8 )
      goto LABEL_2;
    switch ( v13 )
    {
      case 0:
        goto NORMAL_STATE_0;
      case 1:
        v67 = -1;
        v50 = 0;
        v54 = 0;
        v60 = 0;
        v61 = 0;
        v69 = 0;
        v59 = 0;
        goto LABEL_218;
      case 2:
        switch ( v11 )
        {
          case ' ':
            v69 |= 2u;
            break;
          case '#':
            v69 |= 0x80u;
            break;
          case '+':
            v69 |= 1u;
            break;
          case '-':
            v69 |= 4u;
            break;
          case '0':
            v69 |= 8u;
            break;
        }
        goto LABEL_218;
      case 3:
        if ( v11 == 42 )
        {
          v64 = (char *)(v6 + 4);
          v6 = *(_DWORD *)v6;
          v60 = v6;
          if ( v6 < 0 )
          {
            v69 |= 4u;
            v60 = -v60;
          }
        }
        else
        {
          v60 = 10 * v60 + v11 - 48;
        }
        goto LABEL_218;
      case 4:
        v67 = 0;
        goto LABEL_218;
      case 5:
        if ( v11 == 42 )
        {
          v64 = (char *)(v6 + 4);
          v6 = *(_DWORD *)v6;
          v67 = v6;
          if ( v6 < 0 )
            v67 = -1;
        }
        else
        {
          v67 = 10 * v67 + v11 - 48;
        }
        goto LABEL_218;
      case 6:
        switch ( v11 )
        {
          case 'I':
            v14 = *v4;
            if ( *v4 == 54 && v4[1] == 52 )
            {
              v69 |= 0x8000u;
              v58 = v4 + 2;
            }
            else if ( v14 == 51 && v4[1] == 50 )
            {
              v69 &= ~0x8000u;
              v58 = v4 + 2;
            }
            else if ( v14 != 100 && v14 != 105 && v14 != 111 && v14 != 117 && v14 != 120 && v14 != 88 )
            {
              v57 = 0;
NORMAL_STATE_0:
              v59 = 0;
              v16 = _isleadbyte_l(v11, &v56.localeinfo);
              v15 = v16 == 0;
              LOBYTE(v16) = v68;
              if ( !v15 )
              {
                v5 = (int)&v63;
                write_char(v16, v52, &v63, (int)v4, v6);
                LOBYTE(v16) = *v4++;
                v58 = v4;
                if ( !(_BYTE)v16 )
                  goto LABEL_2;
              }
              write_char(v16, v52, &v63, (int)v4, v6);
            }
            break;
          case 'h':
            v69 |= 0x20u;
            break;
          case 'l':
            if ( *v4 == 108 )
            {
              v69 |= 0x1000u;
              v58 = v4 + 1;
            }
            else
            {
              v69 |= 0x10u;
            }
            break;
          case 'w':
            v69 |= 0x800u;
            break;
        }
        goto LABEL_218;
      case 7:
        if ( v11 <= 100 )
        {
          if ( v11 == 100 )
          {
LABEL_118:
            v69 |= 0x40u;
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
              if ( v20 && (v21 = (char *)*((_DWORD *)v20 + 1)) != 0 )
              {
                v22 = *v20;
                v66 = v21;
                if ( (v69 & 0x800) != 0 )
                {
                  v22 /= 2;
                  v59 = 1;
                }
                else
                {
                  v59 = 0;
                }
              }
              else
              {
                v66 = __nullstring;
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
              if ( (v69 & 0x830) == 0 )
                v69 |= 0x800u;
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
              if ( (v69 & 0x830) == 0 )
                v69 |= 0x800u;
LABEL_93:
              v6 += 4;
              v64 = (char *)v6;
              if ( (v69 & 0x810) != 0 )
              {
                if ( wctomb_s(&pRetValue, dst, 512, *(_WORD *)(v6 - 4)) )
                  v54 = 1;
              }
              else
              {
                dst[0] = *(_BYTE *)(v6 - 4);
                pRetValue = 1;
              }
              v66 = dst;
              goto LABEL_190;
            }
LABEL_76:
            v11 += 32;
            v50 = 1;
            v68 = v11;
          }
LABEL_77:
          v69 |= 0x40u;
          v17 = (unsigned __int8 *)dst;
          v66 = dst;
          v51 = 512;
          if ( v67 >= 0 )
          {
            if ( v67 )
            {
              if ( v67 > 512 )
                v67 = 512;
              if ( v67 > 163 )
              {
                v25 = v67 + 349;
                v26 = _malloc_crt(v67 + 349);
                v11 = v68;
                pointer = v26;
                if ( v26 )
                {
                  v66 = (char *)v26;
                  v51 = v25;
                  v17 = (unsigned __int8 *)v26;
                }
                else
                {
                  v67 = 163;
                }
              }
            }
            else
            {
              v67 = v11 == 103;
            }
          }
          else
          {
            v67 = 6;
          }
          v27 = (char *)(v6 + 8);
          v48[0] = *((_DWORD *)v27 - 2);
          v48[1] = *((_DWORD *)v27 - 1);
          v47 = v50;
          v46 = v67;
          v64 = v27;
          v44 = v11;
          v43 = v51;
          v28 = (void (__cdecl *)(_DWORD *, unsigned __int8 *, int, int, int, int, _LocaleUpdate *))_decode_pointer(codedptr);
          v28(v48, v17, v43, v44, v46, v47, &v56);
          v6 = v69 & 0x80;
          if ( (v69 & 0x80) != 0 && !v67 )
          {
            v29 = (void (__cdecl *)(unsigned __int8 *, _LocaleUpdate *))_decode_pointer(off_86F6AC);
            v29(v17, &v56);
          }
          if ( v68 == 103 && !v6 )
          {
            v30 = (void (__cdecl *)(unsigned __int8 *, _LocaleUpdate *))_decode_pointer(off_86F6A8);
            v30(v17, &v56);
          }
          if ( *v17 == 45 )
          {
            v69 |= 0x100u;
            v66 = (char *)++v17;
          }
          strlen(v17);
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
              v53 = 39;
              goto COMMON_HEX_0;
            }
LABEL_119:
            pRetValue = 10;
            goto COMMON_INT_0;
          }
LABEL_83:
          v18 = v67;
          if ( v67 == -1 )
            v18 = 0x7FFFFFFF;
          v64 = (char *)(v6 + 4);
          v6 = *(_DWORD *)v6;
          v66 = (char *)v6;
          if ( (v69 & 0x810) != 0 )
          {
            if ( !v6 )
              v66 = (char *)__wnullstring;
            v19 = v66;
            v59 = 1;
            while ( v18 )
            {
              --v18;
              if ( !*(_WORD *)v19 )
                break;
              v19 += 2;
            }
            v22 = (v19 - v66) >> 1;
          }
          else
          {
            if ( !v6 )
              v66 = __nullstring;
            for ( i = v66; v18; ++i )
            {
              --v18;
              if ( !*i )
                break;
            }
            v22 = i - v66;
          }
LABEL_189:
          pRetValue = v22;
          goto LABEL_190;
        }
        if ( v11 == 112 )
        {
          v67 = 8;
LABEL_140:
          v53 = 7;
COMMON_HEX_0:
          pRetValue = 16;
          if ( (v69 & 0x80u) != 0 )
          {
            v62[0] = 48;
            v62[1] = v53 + 81;
            v61 = 2;
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
          pRetValue = 8;
          if ( (v69 & 0x80u) != 0 )
            v69 |= 0x200u;
COMMON_INT_0:
          if ( (v69 & 0x8000) != 0 || (v69 & 0x1000) != 0 )
          {
            v23 = (char *)(v6 + 8);
            v24 = *((_QWORD *)v23 - 1);
          }
          else
          {
            v23 = (char *)(v6 + 4);
            if ( (v69 & 0x20) != 0 )
            {
              v64 = v23;
              if ( (v69 & 0x40) != 0 )
                LODWORD(v24) = *((__int16 *)v23 - 2);
              else
                LODWORD(v24) = *((unsigned __int16 *)v23 - 2);
              v24 = (int)v24;
LABEL_157:
              if ( (v69 & 0x40) != 0 && v24 < 0 )
              {
                v24 = -v24;
                v69 |= 0x100u;
              }
              v31 = HIDWORD(v24);
              v6 = v24;
              if ( (v69 & 0x9000) == 0 )
                v31 = 0;
              if ( v67 >= 0 )
              {
                v69 &= ~8u;
                if ( v67 > 512 )
                  v67 = 512;
              }
              else
              {
                v67 = 1;
              }
              if ( !(v31 | (unsigned int)v24) )
                v61 = 0;
              for ( j = &v71; ; --j )
              {
                v33 = v67--;
                if ( v33 <= 0 && !(v31 | v6) )
                  break;
                v45 = __PAIR64__(v31, v6);
                v34 = __PAIR64__(v31, v6) % pRetValue;
                v35 = v34 + 48;
                v51 = HIDWORD(v34);
                v31 = (v45 / pRetValue) >> 32;
                v6 = v45 / pRetValue;
                if ( v35 > 57 )
                  LOBYTE(v35) = v53 + v35;
                *j = v35;
              }
              v36 = (char *)(&v71 - j);
              v37 = j + 1;
              pRetValue = (int)v36;
              v66 = v37;
              if ( (v69 & 0x200) != 0 && (!v36 || *v37 != 48) )
              {
                *--v66 = 48;
                v22 = (int)(v36 + 1);
                goto LABEL_189;
              }
LABEL_190:
              if ( v54 )
                goto LABEL_216;
              if ( (v69 & 0x40) != 0 )
              {
                if ( (v69 & 0x100) != 0 )
                {
                  v62[0] = 45;
                  goto LABEL_198;
                }
                if ( (v69 & 1) != 0 )
                {
                  v62[0] = 43;
                  goto LABEL_198;
                }
                if ( (v69 & 2) != 0 )
                {
                  v62[0] = 32;
LABEL_198:
                  v61 = 1;
                }
              }
              v39 = v60 - pRetValue - v61;
              if ( (v69 & 0xC) == 0 )
                write_multi_char(&v63, v39, v6, 32, v60 - pRetValue - v61, v52);
              v6 = (int)v52;
              write_string(v62, v52, &v63, v61);
              if ( (v69 & 8) != 0 && (v69 & 4) == 0 )
                write_multi_char(&v63, v39, v6, 48, v39, (_iobuf *)v6);
              if ( v59 && pRetValue > 0 )
              {
                v40 = (wchar_t *)v66;
                v51 = pRetValue;
                while ( 1 )
                {
                  v41 = *v40;
                  --v51;
                  ++v40;
                  if ( wctomb_s(&v49, v72, 6, v41) || !v49 )
                    break;
                  write_string(v72, (_iobuf *)v6, &v63, v49);
                  if ( !v51 )
                    goto LABEL_213;
                }
                v63 = -1;
              }
              else
              {
                write_string(v66, (_iobuf *)v6, &v63, pRetValue);
              }
LABEL_213:
              if ( v63 >= 0 && (v69 & 4) != 0 )
                write_multi_char(&v63, v39, v6, 32, v39, (_iobuf *)v6);
              goto LABEL_216;
            }
            LODWORD(v24) = *((_DWORD *)v23 - 1);
            if ( (v69 & 0x40) != 0 )
              v24 = (int)v24;
            else
              HIDWORD(v24) = 0;
          }
          v64 = v23;
          goto LABEL_157;
        }
        v5 = *(_DWORD *)v6;
        v6 += 4;
        v64 = (char *)v6;
        if ( !_get_printf_count_output() )
          goto LABEL_2;
        if ( (v69 & 0x20) != 0 )
          *(_WORD *)v5 = v63;
        else
          *(_DWORD *)v5 = v63;
        v54 = 1;
LABEL_216:
        if ( pointer )
        {
          free(pointer);
          pointer = 0;
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
  v5 = 0;
  if ( !v57 || v57 == 7 )
  {
LABEL_222:
    if ( v56.updated )
      v56.ptd->_ownlocale &= ~2u;
    return v63;
  }
  else
  {
LABEL_2:
    *_errno() = 22;
    _invalid_parameter((int)v4, v6, v5);
    if ( v56.updated )
      v56.ptd->_ownlocale &= ~2u;
    return -1;
  }
}
