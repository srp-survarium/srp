int __cdecl _woutput_s_l(_iobuf *stream, const wchar_t *format, localeinfo_struct *plocinfo, ioinfo *argptr)
{
  ioinfo *OwningThread; // ebx
  int v5; // esi
  int v6; // edi
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  int osfhnd; // eax
  int v12; // eax
  __int16 v13; // ax
  unsigned __int8 *v14; // esi
  unsigned int v15; // ebx
  unsigned __int8 *i; // esi
  int osfhnd_low; // eax
  __int16 *v18; // eax
  unsigned int v19; // ecx
  int v20; // eax
  int v21; // eax
  __int16 *p_osfile; // ebx
  __int64 v23; // rax
  void *v24; // eax
  int v25; // eax
  int *p_lockinitflag; // ebx
  void (__cdecl *v27)(_DWORD *, unsigned __int8 *, void *, int, int, int, _LocaleUpdate *); // eax
  int v28; // ebx
  void (__cdecl *v29)(unsigned __int8 *, _LocaleUpdate *); // eax
  void (__cdecl *v30)(unsigned __int8 *, _LocaleUpdate *); // eax
  unsigned int v31; // ebx
  _BYTE *j; // esi
  int v33; // eax
  int v34; // ecx
  unsigned __int64 v35; // kr00_8
  _BYTE *v36; // eax
  _BYTE *v37; // esi
  _WORD *SpinCount; // eax
  void *v39; // esi
  ioinfo *v40; // ebx
  stlp_std::ioinfo **v41; // edi
  int v42; // eax
  void *LockSemaphore; // [esp-14h] [ebp-494h]
  int v44; // [esp-10h] [ebp-490h]
  int v45; // [esp-Ch] [ebp-48Ch]
  int v46; // [esp-8h] [ebp-488h]
  __int16 v47; // [esp-4h] [ebp-484h]
  int v48; // [esp+10h] [ebp-470h]
  _DWORD v49[2]; // [esp+14h] [ebp-46Ch] BYREF
  int v50; // [esp+1Ch] [ebp-464h] BYREF
  int v51; // [esp+20h] [ebp-460h]
  int v52; // [esp+24h] [ebp-45Ch]
  void *pointer; // [esp+28h] [ebp-458h]
  int v54; // [esp+2Ch] [ebp-454h]
  int v55; // [esp+30h] [ebp-450h]
  _LocaleUpdate v56; // [esp+34h] [ebp-44Ch] BYREF
  _iobuf *v57; // [esp+44h] [ebp-43Ch]
  char v58[4]; // [esp+48h] [ebp-438h] BYREF
  int v59; // [esp+4Ch] [ebp-434h]
  ioinfo v60[8]; // [esp+50h] [ebp-430h] BYREF
  _BYTE v61[513]; // [esp+27Bh] [ebp-205h] BYREF

  OwningThread = argptr;
  v5 = (int)stream;
  v6 = (int)format;
  v57 = stream;
  v60[0].lock.OwningThread = argptr;
  v54 = 0;
  LODWORD(v60[0].startpos) = 0;
  *(_DWORD *)&v60[0].osfile = 0;
  *((_DWORD *)v60 + 9) = 0;
  v60[0].lock.DebugInfo = 0;
  v55 = 0;
  v60[0].lockinitflag = 0;
  _LocaleUpdate::_LocaleUpdate(&v56, plocinfo);
  if ( !stream )
    goto LABEL_2;
  v5 = 0;
  if ( !format )
    goto LABEL_2;
  v8 = *format;
  v60[0].lock.LockCount = 0;
  v60[0].lock.LockSemaphore = 0;
  v59 = 0;
  pointer = 0;
  v60[0].lock.RecursionCount = v8;
  if ( !(_WORD)v8 )
    goto LABEL_213;
  while ( 1 )
  {
    v6 += 2;
    v51 = v6;
    if ( v60[0].lock.LockCount < 0 )
      break;
    if ( (unsigned __int16)(v8 - 32) > 0x58u )
      v9 = 0;
    else
      v9 = byte_6B6FF0[(unsigned __int16)v8] & 0xF;
    v10 = __lookuptable_s[9 * v9 + v59] >> 4;
    v5 = 8;
    v59 = v10;
    if ( v10 == 8 )
      goto LABEL_2;
    switch ( v10 )
    {
      case 0:
        goto NORMAL_STATE_1;
      case 1:
        *((_DWORD *)v60 + 9) = -1;
        v52 = 0;
        v55 = 0;
        *(_DWORD *)&v60[0].osfile = 0;
        v60[0].lock.DebugInfo = 0;
        LODWORD(v60[0].startpos) = 0;
        v60[0].lockinitflag = 0;
        goto LABEL_209;
      case 2:
        switch ( (unsigned __int16)v8 )
        {
          case ' ':
            LODWORD(v60[0].startpos) |= 2u;
            break;
          case '#':
            LODWORD(v60[0].startpos) |= 0x80u;
            break;
          case '+':
            LODWORD(v60[0].startpos) |= 1u;
            break;
          case '-':
            LODWORD(v60[0].startpos) |= 4u;
            break;
          case '0':
            LODWORD(v60[0].startpos) |= 8u;
            break;
          default:
            goto LABEL_208;
        }
        goto LABEL_209;
      case 3:
        if ( (_WORD)v8 == 42 )
        {
          osfhnd = OwningThread->osfhnd;
          OwningThread = (ioinfo *)((char *)OwningThread + 4);
          v60[0].lock.OwningThread = OwningThread;
          *(_DWORD *)&v60[0].osfile = osfhnd;
          if ( osfhnd < 0 )
          {
            LODWORD(v60[0].startpos) |= 4u;
            *(_DWORD *)&v60[0].osfile = -*(_DWORD *)&v60[0].osfile;
          }
        }
        else
        {
          *(_DWORD *)&v60[0].osfile = 10 * *(_DWORD *)&v60[0].osfile + (unsigned __int16)v8 - 48;
        }
        goto LABEL_209;
      case 4:
        *((_DWORD *)v60 + 9) = 0;
        goto LABEL_209;
      case 5:
        if ( (_WORD)v8 == 42 )
        {
          v12 = OwningThread->osfhnd;
          OwningThread = (ioinfo *)((char *)OwningThread + 4);
          v60[0].lock.OwningThread = OwningThread;
          *((_DWORD *)v60 + 9) = v12;
          if ( v12 < 0 )
            *((_DWORD *)v60 + 9) = -1;
        }
        else
        {
          *((_DWORD *)v60 + 9) = 10 * *((_DWORD *)v60 + 9) + (unsigned __int16)v8 - 48;
        }
        goto LABEL_209;
      case 6:
        switch ( (unsigned __int16)v8 )
        {
          case 'I':
            v13 = *(_WORD *)v6;
            if ( *(_WORD *)v6 == 54 && *(_WORD *)(v6 + 2) == 52 )
            {
              v6 += 4;
              LODWORD(v60[0].startpos) |= 0x8000u;
            }
            else if ( v13 == 51 && *(_WORD *)(v6 + 2) == 50 )
            {
              v6 += 4;
              LODWORD(v60[0].startpos) &= ~0x8000u;
            }
            else if ( v13 != 100 && v13 != 105 && v13 != 111 && v13 != 117 && v13 != 120 && v13 != 88 )
            {
              v59 = 0;
NORMAL_STATE_1:
              v60[0].lockinitflag = 1;
              write_char_0(v57, &v60[0].lock.LockCount, OwningThread, (stlp_std::ioinfo **)v6, v8);
            }
            break;
          case 'h':
            LODWORD(v60[0].startpos) |= 0x20u;
            break;
          case 'l':
            if ( *(_WORD *)v6 == 108 )
            {
              v6 += 2;
              LODWORD(v60[0].startpos) |= 0x1000u;
            }
            else
            {
              LODWORD(v60[0].startpos) |= 0x10u;
            }
            break;
          case 'w':
            LODWORD(v60[0].startpos) |= 0x800u;
            break;
        }
        goto LABEL_209;
      case 7:
        if ( (unsigned __int16)v8 <= 0x64u )
        {
          if ( (unsigned __int16)v8 == 100 )
          {
LABEL_112:
            LODWORD(v60[0].startpos) |= 0x40u;
            goto LABEL_113;
          }
          if ( (unsigned __int16)v8 > 0x53u )
          {
            if ( (unsigned __int16)v8 == 88 )
              goto LABEL_134;
            if ( (unsigned __int16)v8 == 90 )
            {
              v18 = (__int16 *)OwningThread->osfhnd;
              v60[0].lock.OwningThread = &OwningThread->osfile;
              if ( !v18 || (v19 = *((_DWORD *)v18 + 1)) == 0 )
              {
                v60[0].lock.SpinCount = (unsigned int)__nullstring;
                strlen((unsigned __int8 *)__nullstring);
                goto LABEL_180;
              }
              v20 = *v18;
              v60[0].lock.SpinCount = v19;
              if ( (v60[0].startpos & 0x800) == 0 )
              {
                v60[0].lockinitflag = 0;
                goto LABEL_180;
              }
              v21 = v20 - (v20 >> 31);
              v60[0].lockinitflag = 1;
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
              if ( (v60[0].startpos & 0x830) == 0 )
                LODWORD(v60[0].startpos) |= 0x20u;
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
              if ( (v60[0].startpos & 0x830) == 0 )
                LODWORD(v60[0].startpos) |= 0x20u;
LABEL_87:
              osfhnd_low = LOWORD(OwningThread->osfhnd);
              v60[0].lockinitflag = 1;
              v60[0].lock.OwningThread = &OwningThread->osfile;
              v50 = osfhnd_low;
              if ( (v60[0].startpos & 0x20) != 0 )
              {
                v58[0] = osfhnd_low;
                v58[1] = 0;
                if ( _mbtowc_l(
                       (wchar_t *)&v60[0].startpos + 2,
                       v58,
                       v56.localeinfo.locinfo->mb_cur_max,
                       &v56.localeinfo) < 0 )
                  v55 = 1;
              }
              else
              {
                WORD2(v60[0].startpos) = osfhnd_low;
              }
              v60[0].lock.SpinCount = (unsigned int)&v60[0].startpos + 4;
              v60[0].lock.LockSemaphore = (void *)1;
              goto LABEL_181;
            }
LABEL_65:
            v8 += 32;
            v52 = 1;
            v60[0].lock.RecursionCount = v8;
          }
LABEL_66:
          LODWORD(v60[0].startpos) |= 0x40u;
          v14 = (unsigned __int8 *)&v60[0].startpos + 4;
          v60[0].lock.SpinCount = (unsigned int)&v60[0].startpos + 4;
          v60[0].lock.LockSemaphore = (void *)512;
          if ( *((int *)v60 + 9) >= 0 )
          {
            if ( *((_DWORD *)v60 + 9) )
            {
              if ( *((int *)v60 + 9) > 512 )
                *((_DWORD *)v60 + 9) = 512;
              if ( *((int *)v60 + 9) > 163 )
              {
                v6 = *((_DWORD *)v60 + 9) + 349;
                v24 = _malloc_crt(*((_DWORD *)v60 + 9) + 349);
                LOBYTE(v8) = v60[0].lock.RecursionCount;
                pointer = v24;
                if ( v24 )
                {
                  v60[0].lock.SpinCount = (unsigned int)v24;
                  v60[0].lock.LockSemaphore = (void *)v6;
                  v14 = (unsigned __int8 *)v24;
                }
                else
                {
                  *((_DWORD *)v60 + 9) = 163;
                }
              }
            }
            else
            {
              *((_DWORD *)v60 + 9) = (_WORD)v8 == 103;
            }
          }
          else
          {
            *((_DWORD *)v60 + 9) = 6;
          }
          v25 = OwningThread->osfhnd;
          p_lockinitflag = &OwningThread->lockinitflag;
          v49[0] = v25;
          v49[1] = *(p_lockinitflag - 1);
          v46 = v52;
          v45 = *((_DWORD *)v60 + 9);
          v60[0].lock.OwningThread = p_lockinitflag;
          v44 = (char)v8;
          LockSemaphore = v60[0].lock.LockSemaphore;
          v27 = (void (__cdecl *)(_DWORD *, unsigned __int8 *, void *, int, int, int, _LocaleUpdate *))_decode_pointer(codedptr);
          v27(v49, v14, LockSemaphore, v44, v45, v46, &v56);
          v28 = v60[0].startpos & 0x80;
          if ( (v60[0].startpos & 0x80) != 0 && !*((_DWORD *)v60 + 9) )
          {
            v29 = (void (__cdecl *)(unsigned __int8 *, _LocaleUpdate *))_decode_pointer(off_86F6AC);
            v29(v14, &v56);
          }
          if ( LOWORD(v60[0].lock.RecursionCount) == 103 && !v28 )
          {
            v30 = (void (__cdecl *)(unsigned __int8 *, _LocaleUpdate *))_decode_pointer(off_86F6A8);
            v30(v14, &v56);
          }
          if ( *v14 == 45 )
          {
            LODWORD(v60[0].startpos) |= 0x100u;
            v60[0].lock.SpinCount = (unsigned int)++v14;
          }
          strlen(v14);
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
              v54 = 39;
              goto COMMON_HEX_1;
            }
LABEL_113:
            v60[0].lock.RecursionCount = 10;
            goto COMMON_INT_1;
          }
LABEL_72:
          v6 = *((_DWORD *)v60 + 9);
          if ( *((_DWORD *)v60 + 9) == -1 )
            v6 = 0x7FFFFFFF;
          v60[0].lock.OwningThread = &OwningThread->osfile;
          v15 = OwningThread->osfhnd;
          v60[0].lock.SpinCount = v15;
          if ( (v60[0].startpos & 0x20) != 0 )
          {
            if ( !v15 )
              v60[0].lock.SpinCount = (unsigned int)__nullstring;
            v60[0].lock.LockSemaphore = 0;
            for ( i = (unsigned __int8 *)v60[0].lock.SpinCount;
                  (int)v60[0].lock.LockSemaphore < v6;
                  ++v60[0].lock.LockSemaphore )
            {
              if ( !*i )
                break;
              if ( _isleadbyte_l(*i, &v56.localeinfo) )
                ++i;
              ++i;
            }
            goto LABEL_181;
          }
          if ( !v15 )
            v60[0].lock.SpinCount = (unsigned int)__wnullstring;
          SpinCount = (_WORD *)v60[0].lock.SpinCount;
          v60[0].lockinitflag = 1;
          while ( v6 )
          {
            --v6;
            if ( !*SpinCount )
              break;
            ++SpinCount;
          }
          v21 = (int)SpinCount - v60[0].lock.SpinCount;
LABEL_179:
          v20 = v21 >> 1;
LABEL_180:
          v60[0].lock.LockSemaphore = (void *)v20;
          goto LABEL_181;
        }
        if ( (unsigned __int16)v8 == 112 )
        {
          *((_DWORD *)v60 + 9) = 8;
LABEL_134:
          v54 = 7;
COMMON_HEX_1:
          v60[0].lock.RecursionCount = 16;
          if ( SLOBYTE(v60[0].startpos) < 0 )
          {
            LOWORD(v60[0].osfhnd) = 48;
            HIWORD(v60[0].osfhnd) = v54 + 81;
            v60[0].lock.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)2;
          }
          goto COMMON_INT_1;
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
          v60[0].lock.RecursionCount = 8;
          if ( SLOBYTE(v60[0].startpos) < 0 )
            LODWORD(v60[0].startpos) |= 0x200u;
COMMON_INT_1:
          if ( (v60[0].startpos & 0x8000) != 0 || (v60[0].startpos & 0x1000) != 0 )
          {
            p_osfile = (__int16 *)&OwningThread->lockinitflag;
            v23 = *((_QWORD *)p_osfile - 1);
          }
          else
          {
            p_osfile = (__int16 *)&OwningThread->osfile;
            if ( (v60[0].startpos & 0x20) != 0 )
            {
              v60[0].lock.OwningThread = p_osfile;
              if ( (v60[0].startpos & 0x40) != 0 )
                LODWORD(v23) = *(p_osfile - 2);
              else
                LODWORD(v23) = (unsigned __int16)*(p_osfile - 2);
              v23 = (int)v23;
LABEL_151:
              if ( (v60[0].startpos & 0x40) != 0 && v23 < 0 )
              {
                v23 = -v23;
                LODWORD(v60[0].startpos) |= 0x100u;
              }
              v31 = HIDWORD(v23);
              v6 = v23;
              if ( (v60[0].startpos & 0x9000) == 0 )
                v31 = 0;
              if ( *((int *)v60 + 9) >= 0 )
              {
                LODWORD(v60[0].startpos) &= ~8u;
                if ( *((int *)v60 + 9) > 512 )
                  *((_DWORD *)v60 + 9) = 512;
              }
              else
              {
                *((_DWORD *)v60 + 9) = 1;
              }
              if ( !(v31 | (unsigned int)v23) )
                v60[0].lock.DebugInfo = 0;
              for ( j = v61; ; --j )
              {
                v33 = (*((_DWORD *)v60 + 9))--;
                if ( v33 <= 0 && !(v31 | v6) )
                  break;
                v34 = __PAIR64__(v31, v6) % v60[0].lock.RecursionCount + 48;
                v35 = __PAIR64__(v31, v6) / v60[0].lock.RecursionCount;
                v31 = HIDWORD(v35);
                v6 = v35;
                if ( v34 > 57 )
                  LOBYTE(v34) = v54 + v34;
                *j = v34;
              }
              v36 = (_BYTE *)(v61 - j);
              v37 = j + 1;
              v60[0].lock.LockSemaphore = v36;
              v60[0].lock.SpinCount = (unsigned int)v37;
              if ( (v60[0].startpos & 0x200) != 0 && (!v36 || *v37 != 48) )
              {
                *(_BYTE *)--v60[0].lock.SpinCount = 48;
                v20 = (int)(v36 + 1);
                goto LABEL_180;
              }
LABEL_181:
              if ( v55 )
                goto LABEL_206;
              if ( (v60[0].startpos & 0x40) != 0 )
              {
                if ( (v60[0].startpos & 0x100) != 0 )
                {
                  v47 = 45;
                  goto LABEL_189;
                }
                if ( (v60[0].startpos & 1) != 0 )
                {
                  v47 = 43;
                  goto LABEL_189;
                }
                if ( (v60[0].startpos & 2) != 0 )
                {
                  v47 = 32;
LABEL_189:
                  LOWORD(v60[0].osfhnd) = v47;
                  v60[0].lock.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)1;
                }
              }
              v39 = v60[0].lock.LockSemaphore;
              v40 = (ioinfo *)(*(_DWORD *)&v60[0].osfile
                             - (unsigned int)v60[0].lock.LockSemaphore
                             - (unsigned int)v60[0].lock.DebugInfo);
              if ( (v60[0].startpos & 0xC) == 0 )
                write_multi_char_0(
                  &v60[0].lock.LockCount,
                  v40,
                  (stlp_std::ioinfo **)v6,
                  0x20u,
                  *(_DWORD *)&v60[0].osfile
                - (unsigned int)v60[0].lock.LockSemaphore
                - (unsigned int)v60[0].lock.DebugInfo,
                  v57);
              v41 = (stlp_std::ioinfo **)v57;
              write_string_0(v60, v57, &v60[0].lock.LockCount, (int)v60[0].lock.DebugInfo);
              if ( (v60[0].startpos & 8) != 0 && (v60[0].startpos & 4) == 0 )
                write_multi_char_0(&v60[0].lock.LockCount, v40, v41, 0x30u, (int)v40, (_iobuf *)v41);
              if ( v60[0].lockinitflag || (int)v39 <= 0 )
              {
                write_string_0((ioinfo *)v60[0].lock.SpinCount, (_iobuf *)v41, &v60[0].lock.LockCount, (int)v39);
              }
              else
              {
                v41 = (stlp_std::ioinfo **)v60[0].lock.SpinCount;
                v60[0].lock.RecursionCount = (int)v39;
                while ( 1 )
                {
                  --v60[0].lock.RecursionCount;
                  v48 = _mbtowc_l(
                          (wchar_t *)&v50,
                          (const char *)v41,
                          v56.localeinfo.locinfo->mb_cur_max,
                          &v56.localeinfo);
                  if ( v48 <= 0 )
                    break;
                  write_char_0(v57, &v60[0].lock.LockCount, v40, v41, v50);
                  v41 = (stlp_std::ioinfo **)((char *)v41 + v48);
                  if ( v60[0].lock.RecursionCount <= 0 )
                    goto LABEL_203;
                }
                v60[0].lock.LockCount = -1;
              }
LABEL_203:
              if ( v60[0].lock.LockCount >= 0 && (v60[0].startpos & 4) != 0 )
                write_multi_char_0(&v60[0].lock.LockCount, v40, v41, 0x20u, (int)v40, v57);
              goto LABEL_206;
            }
            LODWORD(v23) = *((_DWORD *)p_osfile - 1);
            if ( (v60[0].startpos & 0x40) != 0 )
              v23 = (int)v23;
            else
              HIDWORD(v23) = 0;
          }
          v60[0].lock.OwningThread = p_osfile;
          goto LABEL_151;
        }
        v5 = OwningThread->osfhnd;
        OwningThread = (ioinfo *)((char *)OwningThread + 4);
        v60[0].lock.OwningThread = OwningThread;
        if ( !_get_printf_count_output() )
          goto LABEL_2;
        if ( (v60[0].startpos & 0x20) != 0 )
          *(_WORD *)v5 = v60[0].lock.LockCount;
        else
          *(_DWORD *)v5 = v60[0].lock.LockCount;
        v55 = 1;
LABEL_206:
        if ( pointer )
        {
          free(pointer);
          pointer = 0;
        }
LABEL_208:
        v6 = v51;
        OwningThread = (ioinfo *)v60[0].lock.OwningThread;
LABEL_209:
        v42 = *(unsigned __int16 *)v6;
        v5 = 0;
        v60[0].lock.RecursionCount = v42;
        if ( !(_WORD)v42 )
          goto LABEL_211;
        v8 = v42;
        break;
      default:
        goto LABEL_208;
    }
  }
LABEL_211:
  if ( !v59 || v59 == 7 )
  {
LABEL_213:
    if ( v56.updated )
      v56.ptd->_ownlocale &= ~2u;
    return v60[0].lock.LockCount;
  }
  else
  {
LABEL_2:
    *_errno() = 22;
    _invalid_parameter((int)OwningThread, v6, v5);
    if ( v56.updated )
      v56.ptd->_ownlocale &= ~2u;
    return -1;
  }
}
