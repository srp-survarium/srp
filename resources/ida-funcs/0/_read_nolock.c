int __usercall _read_nolock@<eax>(unsigned int a1@<edi>, int fh, _BYTE *inputbuf, unsigned int cnt)
{
  unsigned int v4; // edx
  int result; // eax
  stlp_std::ioinfo **v6; // edi
  unsigned int v7; // esi
  char *v8; // eax
  char v9; // cl
  _BYTE *v10; // eax
  __int64 v11; // rax
  stlp_std::ioinfo *v12; // ecx
  char *v13; // ecx
  char v14; // cl
  stlp_std::ioinfo *v15; // ecx
  char v16; // cl
  stlp_std::ioinfo *v17; // ecx
  bool v18; // zf
  char v19; // cl
  stlp_std::ioinfo *v20; // ecx
  stlp_std::ioinfo *v21; // eax
  char *v22; // eax
  char *v23; // ebx
  char v24; // al
  char *v25; // eax
  char *v26; // ebx
  int v27; // ecx
  int v28; // eax
  char v29; // dl
  char *v30; // ecx
  _BYTE *v31; // ebx
  int v32; // ebx
  DWORD LastError; // eax
  stlp_std::ioinfo *v34; // edx
  BOOL v35; // ecx
  char *v36; // ebx
  __int16 v37; // cx
  char *v38; // esi
  __int16 v39; // [esp-Ch] [ebp-2Ch]
  unsigned int inputsize; // [esp+4h] [ebp-1Ch]
  int os_read; // [esp+8h] [ebp-18h] BYREF
  int retval; // [esp+Ch] [ebp-14h]
  int bytes_read; // [esp+10h] [ebp-10h]
  void *buf; // [esp+14h] [ebp-Ch]
  wchar_t wpeekchr; // [esp+18h] [ebp-8h] BYREF
  char tmode; // [esp+1Eh] [ebp-2h]
  char peekchr; // [esp+1Fh] [ebp-1h] BYREF
  char *p; // [esp+30h] [ebp+10h]
  char *pa; // [esp+30h] [ebp+10h]

  v4 = cnt;
  retval = -2;
  inputsize = cnt;
  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(0, a1, fh);
    return -1;
  }
  v6 = &__pioinfo[fh >> 5];
  v7 = (fh & 0x1F) << 6;
  v8 = (char *)*v6 + v7;
  v9 = v8[4];
  if ( (v9 & 1) == 0 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
LABEL_19:
    _invalid_parameter(0, (unsigned int)v6, v7);
    return -1;
  }
  if ( cnt > 0x7FFFFFFF )
    goto LABEL_18;
  bytes_read = 0;
  if ( !cnt || (v9 & 2) != 0 )
    return 0;
  if ( !inputbuf )
    goto LABEL_18;
  tmode = (char)(2 * v8[36]) >> 1;
  if ( tmode != 1 )
  {
    if ( tmode != 2 )
    {
LABEL_16:
      v10 = inputbuf;
      buf = inputbuf;
      goto LABEL_26;
    }
    if ( (cnt & 1) == 0 )
    {
      cnt &= ~1u;
      goto LABEL_16;
    }
LABEL_18:
    *__doserrno() = 0;
    *_errno() = 22;
    goto LABEL_19;
  }
  if ( (cnt & 1) != 0 )
    goto LABEL_18;
  cnt = 4;
  if ( v4 >> 1 >= 4 )
    cnt = v4 >> 1;
  buf = _malloc_crt(cnt);
  if ( !buf )
  {
    *_errno() = 12;
    *__doserrno() = 8;
    return -1;
  }
  v11 = _lseeki64_nolock(fh, 0, 1);
  v12 = *v6;
  *(_DWORD *)(&v12[1].osfile + v7) = v11;
  v10 = buf;
  *(int *)((char *)&v12[1].lockinitflag + v7) = HIDWORD(v11);
LABEL_26:
  v13 = (char *)*v6 + v7;
  if ( (v13[4] & 0x48) != 0 )
  {
    v14 = v13[5];
    if ( v14 != 10 )
    {
      if ( cnt )
      {
        *v10 = v14;
        v15 = *v6;
        ++v10;
        --cnt;
        bytes_read = 1;
        *(&v15->pipech + v7) = 10;
        if ( tmode )
        {
          v16 = *((_BYTE *)&(*v6)[1].osfhnd + v7 + 1);
          if ( v16 != 10 )
          {
            if ( cnt )
            {
              *v10 = v16;
              v17 = *v6;
              ++v10;
              --cnt;
              v18 = tmode == 1;
              bytes_read = 2;
              *((_BYTE *)&v17[1].osfhnd + v7 + 1) = 10;
              if ( v18 )
              {
                v19 = *((_BYTE *)&(*v6)[1].osfhnd + v7 + 2);
                if ( v19 != 10 )
                {
                  if ( cnt )
                  {
                    *v10 = v19;
                    v20 = *v6;
                    ++v10;
                    --cnt;
                    bytes_read = 3;
                    *((_BYTE *)&v20[1].osfhnd + v7 + 2) = 10;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( !ReadFile(*(HANDLE *)((char *)&(*v6)->osfhnd + v7), v10, cnt, (LPDWORD)&os_read, 0)
    || os_read < 0
    || os_read > cnt )
  {
    LastError = GetLastError();
    if ( LastError == 5 )
    {
      *_errno() = 9;
      *__doserrno() = 5;
      goto LABEL_93;
    }
    if ( LastError == 109 )
    {
      retval = 0;
      goto error_return;
    }
    goto LABEL_92;
  }
  v21 = *v6;
  bytes_read += os_read;
  v22 = &v21->osfile + v7;
  if ( *v22 < 0 )
  {
    if ( tmode != 2 )
    {
      if ( os_read && *(_BYTE *)buf == 10 )
        *v22 |= 4u;
      else
        *v22 &= ~4u;
      v23 = (char *)buf;
      p = (char *)buf;
      bytes_read += (int)buf;
      if ( (unsigned int)buf < bytes_read )
      {
        do
        {
          v24 = *p;
          if ( *p == 26 )
          {
            v25 = &(*v6)->osfile + v7;
            if ( (*v25 & 0x40) != 0 )
              *v23++ = *p;
            else
              *v25 |= 2u;
            break;
          }
          if ( v24 == 13 )
          {
            if ( (unsigned int)p < bytes_read - 1 )
            {
              if ( p[1] == 10 )
              {
                p += 2;
                goto LABEL_52;
              }
              ++p;
LABEL_63:
              *v23 = 13;
LABEL_64:
              ++v23;
              continue;
            }
            ++p;
            if ( !ReadFile(*(HANDLE *)((char *)&(*v6)->osfhnd + v7), &peekchr, 1u, (LPDWORD)&os_read, 0)
              && GetLastError()
              || !os_read )
            {
              goto LABEL_63;
            }
            if ( (*(&(*v6)->osfile + v7) & 0x48) != 0 )
            {
              if ( peekchr != 10 )
              {
                *v23 = 13;
                *(&(*v6)->pipech + v7) = peekchr;
                goto LABEL_64;
              }
LABEL_52:
              *v23 = 10;
              goto LABEL_64;
            }
            if ( v23 == buf && peekchr == 10 )
              goto LABEL_52;
            _lseeki64_nolock(fh, -1, 1);
            if ( peekchr != 10 )
              goto LABEL_63;
          }
          else
          {
            *v23++ = v24;
            ++p;
          }
        }
        while ( (unsigned int)p < bytes_read );
      }
      bytes_read = v23 - (_BYTE *)buf;
      if ( tmode != 1 || v23 == buf )
        goto error_return;
      v26 = v23 - 1;
      LOBYTE(v27) = *v26;
      if ( *v26 < 0 )
      {
        v28 = 1;
        v27 = (unsigned __int8)v27;
        while ( !_lookuptrailbytes[v27] && v28 <= 4 && v26 >= buf )
        {
          v27 = (unsigned __int8)*--v26;
          ++v28;
        }
        v29 = *v26;
        if ( !_lookuptrailbytes[(unsigned __int8)*v26] )
        {
          *_errno() = 42;
LABEL_93:
          retval = -1;
          goto error_return;
        }
        if ( _lookuptrailbytes[(unsigned __int8)*v26] + 1 == v28 )
        {
          v26 += v28;
        }
        else
        {
          v30 = (char *)*v6 + v7;
          if ( (v30[4] & 0x48) != 0 )
          {
            v31 = v26 + 1;
            v30[5] = v29;
            if ( v28 >= 2 )
              *((_BYTE *)&(*v6)[1].osfhnd + v7 + 1) = *v31++;
            if ( v28 == 3 )
              *((_BYTE *)&(*v6)[1].osfhnd + v7 + 2) = *v31++;
            v26 = &v31[-v28];
          }
          else
          {
            _lseeki64_nolock(fh, -v28, 1);
          }
        }
      }
      else
      {
        ++v26;
      }
      v32 = v26 - (_BYTE *)buf;
      bytes_read = MultiByteToWideChar(0xFDE9u, 0, (LPCCH)buf, v32, (LPWSTR)inputbuf, inputsize >> 1);
      if ( bytes_read )
      {
        v34 = *v6;
        v35 = bytes_read != v32;
        bytes_read *= 2;
        *(_RTL_CRITICAL_SECTION_DEBUG **)((char *)&v34[1].lock.DebugInfo + v7) = (_RTL_CRITICAL_SECTION_DEBUG *)v35;
        goto error_return;
      }
      LastError = GetLastError();
LABEL_92:
      _dosmaperr(LastError);
      goto LABEL_93;
    }
    if ( os_read && *(_WORD *)buf == 10 )
      *v22 |= 4u;
    else
      *v22 &= ~4u;
    v36 = (char *)buf;
    pa = (char *)buf;
    bytes_read += (int)buf;
    if ( (unsigned int)buf >= bytes_read )
    {
LABEL_129:
      bytes_read = v36 - (_BYTE *)buf;
      goto error_return;
    }
    while ( 1 )
    {
      v37 = *(_WORD *)pa;
      if ( *(_WORD *)pa == 26 )
      {
        v38 = &(*v6)->osfile + v7;
        if ( (*v38 & 0x40) != 0 )
        {
          *(_WORD *)v36 = *(_WORD *)pa;
          v36 += 2;
        }
        else
        {
          *v38 |= 2u;
        }
        goto LABEL_129;
      }
      if ( v37 == 13 )
      {
        if ( (unsigned int)pa < bytes_read - 2 )
        {
          if ( *((_WORD *)pa + 1) == 10 )
          {
            pa += 4;
            goto LABEL_110;
          }
          pa += 2;
LABEL_121:
          v39 = 13;
LABEL_122:
          *(_WORD *)v36 = v39;
          goto LABEL_123;
        }
        pa += 2;
        if ( !ReadFile(*(HANDLE *)((char *)&(*v6)->osfhnd + v7), &wpeekchr, 2u, (LPDWORD)&os_read, 0) && GetLastError()
          || !os_read )
        {
          goto LABEL_121;
        }
        if ( (*(&(*v6)->osfile + v7) & 0x48) != 0 )
        {
          if ( wpeekchr != 10 )
          {
            *(_WORD *)v36 = 13;
            *(&(*v6)->pipech + v7) = wpeekchr;
            *((_BYTE *)&(*v6)[1].osfhnd + v7 + 1) = HIBYTE(wpeekchr);
            *((_BYTE *)&(*v6)[1].osfhnd + v7 + 2) = 10;
LABEL_123:
            v36 += 2;
            goto LABEL_124;
          }
LABEL_110:
          v39 = 10;
          goto LABEL_122;
        }
        if ( v36 == buf && wpeekchr == 10 )
          goto LABEL_110;
        _lseeki64_nolock(fh, -2, 1);
        if ( wpeekchr != 10 )
          goto LABEL_121;
      }
      else
      {
        *(_WORD *)v36 = v37;
        v36 += 2;
        pa += 2;
      }
LABEL_124:
      if ( (unsigned int)pa >= bytes_read )
        goto LABEL_129;
    }
  }
error_return:
  if ( buf != inputbuf )
    free(buf);
  result = retval;
  if ( retval == -2 )
    return bytes_read;
  return result;
}
