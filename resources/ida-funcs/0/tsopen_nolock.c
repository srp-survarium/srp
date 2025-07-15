int __usercall tsopen_nolock@<eax>(
        int *pfh@<eax>,
        int a2@<edi>,
        int *punlock_flag,
        const char *path,
        int oflag,
        int shflag,
        char pmode)
{
  int v8; // edi
  unsigned int v9; // eax
  int v10; // eax
  char *v11; // eax
  DWORD LastError; // eax
  DWORD FileType; // eax
  char *v15; // eax
  DWORD v16; // esi
  char v17; // cl
  _BYTE *v18; // eax
  int v19; // edi
  HINSTANCE__ *v20; // eax
  DWORD v21; // eax
  int v22; // eax
  __int64 v23; // rax
  unsigned int nolock; // eax
  __int64 v25; // rax
  DWORD v26; // eax
  int v27; // eax
  _BYTE *v28; // eax
  _BYTE *v29; // eax
  char *v30; // eax
  DWORD v31; // edi
  HANDLE v32; // eax
  DWORD v33; // eax
  char *v34; // eax
  int v35; // [esp-Ch] [ebp-48h]
  DWORD v36; // [esp-8h] [ebp-44h]
  _SECURITY_ATTRIBUTES SecurityAttributes; // [esp+Ch] [ebp-30h] BYREF
  int pMode; // [esp+1Ch] [ebp-20h] BYREF
  HANDLE hFile; // [esp+20h] [ebp-1Ch]
  __int64 size; // [esp+24h] [ebp-18h] BYREF
  DWORD dwShareMode; // [esp+2Ch] [ebp-10h]
  DWORD dwFlagsAndAttributes; // [esp+30h] [ebp-Ch]
  DWORD dwDesiredAccess; // [esp+34h] [ebp-8h]
  char v44; // [esp+38h] [ebp-4h] BYREF
  char v45; // [esp+39h] [ebp-3h]
  char v46; // [esp+3Ah] [ebp-2h]
  char v47; // [esp+3Bh] [ebp-1h]

  pMode = 0;
  v46 = 0;
  SecurityAttributes.nLength = 12;
  SecurityAttributes.lpSecurityDescriptor = 0;
  if ( (oflag & 0x80u) == 0 )
  {
    SecurityAttributes.bInheritHandle = 1;
    v47 = 0;
  }
  else
  {
    SecurityAttributes.bInheritHandle = 0;
    v47 = 16;
  }
  if ( _get_fmode(0, a2, &pMode) )
    _invoke_watson(0, a2, (int)pfh);
  if ( (oflag & 0x8000) == 0 && ((oflag & 0x74000) != 0 || pMode != 0x8000) )
    v47 |= 0x80u;
  v8 = 0x80000000;
  if ( (oflag & 3) != 0 )
  {
    if ( (oflag & 3) != 1 )
    {
      if ( (oflag & 3) != 2 )
      {
LABEL_13:
        *__doserrno() = 0;
        *pfh = -1;
        *_errno() = 22;
        _invalid_parameter(0, v8, 22);
        return 22;
      }
      goto LABEL_14;
    }
    if ( (oflag & 8) != 0 && (((unsigned int)&loc_6FFFB + 5) & oflag) != 0 )
    {
LABEL_14:
      dwDesiredAccess = -1073741824;
      goto LABEL_19;
    }
    dwDesiredAccess = 0x40000000;
  }
  else
  {
    dwDesiredAccess = 0x80000000;
  }
LABEL_19:
  switch ( shflag )
  {
    case 16:
      dwShareMode = 0;
      break;
    case 32:
      dwShareMode = 1;
      break;
    case 48:
      dwShareMode = 2;
      break;
    case 64:
      dwShareMode = 3;
      break;
    case 128:
      dwShareMode = dwDesiredAccess == 0x80000000;
      break;
    default:
      goto LABEL_13;
  }
  v9 = oflag & 0x700;
  v8 = 256;
  if ( v9 > 0x400 )
  {
    if ( v9 != 1280 )
    {
      if ( v9 == 1536 )
        goto LABEL_51;
      if ( v9 != 1792 )
        goto LABEL_13;
    }
    HIDWORD(size) = 1;
    goto LABEL_42;
  }
  if ( (oflag & 0x700) == 0x400 || (oflag & 0x700) == 0 )
  {
    HIDWORD(size) = 3;
    goto LABEL_42;
  }
  if ( v9 == 256 )
  {
    HIDWORD(size) = 4;
    goto LABEL_42;
  }
  if ( v9 == 512 )
  {
LABEL_51:
    HIDWORD(size) = 5;
    goto LABEL_42;
  }
  if ( v9 != 768 )
    goto LABEL_13;
  HIDWORD(size) = 2;
LABEL_42:
  dwFlagsAndAttributes = 128;
  if ( (oflag & 0x100) != 0 && (pmode & ~(_BYTE)_umaskval & 0x80u) == 0 )
    dwFlagsAndAttributes = 1;
  if ( (oflag & 0x40) != 0 )
  {
    dwFlagsAndAttributes |= 0x4000000u;
    dwDesiredAccess |= (unsigned int)&_sbh_sizeHeaderList;
    dwShareMode |= 4u;
  }
  if ( (oflag & 0x1000) != 0 )
    dwFlagsAndAttributes |= 0x100u;
  if ( (oflag & 0x20) != 0 )
  {
    dwFlagsAndAttributes |= 0x8000000u;
  }
  else if ( (oflag & 0x10) != 0 )
  {
    dwFlagsAndAttributes |= 0x10000000u;
  }
  v10 = _alloc_osfhnd();
  *pfh = v10;
  if ( v10 == -1 )
  {
    *__doserrno() = 0;
    *pfh = -1;
    *_errno() = 24;
    return *_errno();
  }
  v36 = dwFlagsAndAttributes;
  *punlock_flag = 1;
  hFile = CreateFileA(path, dwDesiredAccess, dwShareMode, &SecurityAttributes, HIDWORD(size), v36, 0);
  if ( hFile == (HANDLE)-1 )
  {
    if ( (dwDesiredAccess & 0xC0000000) != 0xC0000000
      || (oflag & 1) == 0
      || (dwDesiredAccess &= ~0x80000000,
          hFile = CreateFileA(
                    path,
                    dwDesiredAccess,
                    dwShareMode,
                    &SecurityAttributes,
                    HIDWORD(size),
                    dwFlagsAndAttributes,
                    0),
          hFile == (HANDLE)-1) )
    {
      v11 = &__pioinfo[*pfh >> 5]->osfile + 64 * (*pfh & 0x1F);
      *v11 &= ~1u;
      LastError = GetLastError();
      _dosmaperr(LastError);
      return *_errno();
    }
  }
  FileType = GetFileType(hFile);
  switch ( FileType )
  {
    case 0u:
      v15 = &__pioinfo[*pfh >> 5]->osfile + 64 * (*pfh & 0x1F);
      *v15 &= ~1u;
      v16 = GetLastError();
      _dosmaperr(v16);
      CloseHandle(hFile);
      if ( !v16 )
        *_errno() = 13;
      return *_errno();
    case 2u:
      v47 |= 0x40u;
      break;
    case 3u:
      v47 |= 8u;
      break;
  }
  _set_osfhnd(*pfh, hFile);
  v17 = v47 | 1;
  *(&__pioinfo[*pfh >> 5]->osfile + 64 * (*pfh & 0x1F)) = v47 | 1;
  v18 = (char *)&__pioinfo[*pfh >> 5][1] + 64 * (*pfh & 0x1F);
  *v18 &= 0x80u;
  v45 = v17 & 0x48;
  v47 = v17;
  if ( (v17 & 0x48) == 0 )
  {
    if ( v17 >= 0 )
      goto LABEL_131;
    if ( (oflag & 2) != 0 )
    {
      v19 = -1;
      LODWORD(size) = _lseek_nolock(0, -1, *pfh, -1, 2u);
      if ( (_DWORD)size == -1 )
      {
        if ( *__doserrno() != 131 )
        {
LABEL_74:
          _close_nolock(0, v19, *pfh);
          return *_errno();
        }
      }
      else
      {
        v35 = *pfh;
        v44 = 0;
        if ( !_read_nolock(-1, v35, &v44, 1u) && v44 == 26 && _chsize_nolock(*pfh, (int)size) == -1
          || _lseek_nolock(0, -1, *pfh, 0, 0) == -1 )
        {
          goto LABEL_74;
        }
      }
    }
  }
  if ( v47 >= 0 )
    goto LABEL_131;
  v19 = 475136;
  if ( (oflag & 0x74000) == 0 )
  {
    if ( (pMode & 0x74000) != 0 )
      oflag |= pMode & 0x74000;
    else
      oflag |= 0x4000u;
  }
  v20 = (HINSTANCE__ *)(oflag & 0x74000);
  if ( (oflag & 0x74000) == 0x4000 )
  {
    v46 = 0;
    goto LABEL_95;
  }
  if ( v20 == &_sbh_sizeHeaderList || v20 == (HINSTANCE__ *)&loc_14000 )
  {
    if ( (oflag & 0x301) != 0x301 )
      goto LABEL_95;
LABEL_93:
    v46 = 2;
    goto LABEL_95;
  }
  if ( v20 == (HINSTANCE__ *)&loc_20000 || v20 == (HINSTANCE__ *)((char *)&loc_23FFE + 2) )
    goto LABEL_93;
  if ( v20 == (HINSTANCE__ *)((char *)&loc_3FFFF + 1) || v20 == (HINSTANCE__ *)((char *)&loc_43FFE + 2) )
    v46 = 1;
LABEL_95:
  if ( (((unsigned int)&loc_6FFFB + 5) & oflag) == 0 )
    goto LABEL_131;
  LODWORD(size) = 0;
  if ( (v47 & 0x40) != 0 )
    goto LABEL_131;
  v21 = dwDesiredAccess & 0xC0000000;
  if ( (dwDesiredAccess & 0xC0000000) == 0x40000000 )
  {
    v22 = HIDWORD(size);
    if ( !HIDWORD(size) )
      goto LABEL_131;
    if ( HIDWORD(size) > 2 )
    {
      if ( HIDWORD(size) > 4 )
      {
LABEL_103:
        if ( v22 != 5 )
          goto LABEL_131;
        goto LABEL_104;
      }
      if ( _lseeki64_nolock(0, 475136, *pfh, 0, 2u) )
      {
        v25 = _lseeki64_nolock(0, 475136, *pfh, 0, 0);
        v26 = HIDWORD(v25) & v25;
        goto LABEL_119;
      }
    }
    goto LABEL_104;
  }
  if ( v21 == 0x80000000 )
    goto LABEL_109;
  if ( v21 != -1073741824 )
    goto LABEL_131;
  v22 = HIDWORD(size);
  if ( !HIDWORD(size) )
    goto LABEL_131;
  if ( HIDWORD(size) <= 2 )
    goto LABEL_104;
  if ( HIDWORD(size) > 4 )
    goto LABEL_103;
  if ( !_lseeki64_nolock(0, 475136, *pfh, 0, 2u) )
  {
LABEL_104:
    v19 = 0;
    if ( v46 == 1 )
    {
      size = 0x300BFBBEFLL;
LABEL_129:
      while ( 1 )
      {
        v27 = _write(0, (int)pfh, *pfh, (char *)&size + v19, HIDWORD(size) - v19);
        if ( v27 == -1 )
          goto LABEL_74;
        v19 += v27;
        if ( SHIDWORD(size) <= v19 )
          goto LABEL_131;
      }
    }
    if ( v46 == 2 )
    {
      size = 0x20000FEFFLL;
      goto LABEL_129;
    }
    goto LABEL_131;
  }
  v23 = _lseeki64_nolock(0, 475136, *pfh, 0, 0);
  if ( (HIDWORD(v23) & (unsigned int)v23) == 0xFFFFFFFF )
    goto LABEL_74;
LABEL_109:
  nolock = _read_nolock(475136, *pfh, (char *)&size, 3u);
  if ( nolock == -1 )
    goto LABEL_74;
  if ( nolock != 2 )
  {
    if ( nolock != 3 )
    {
LABEL_127:
      v26 = _lseek_nolock(0, 475136, *pfh, 0, 0);
LABEL_119:
      if ( v26 == -1 )
        goto LABEL_74;
      goto LABEL_131;
    }
    if ( (_DWORD)size == 12565487 )
    {
      v46 = 1;
      goto LABEL_131;
    }
  }
  if ( (unsigned __int16)size == 65534 )
  {
    _close_nolock(0, 475136, *pfh);
    *_errno() = 22;
    return 22;
  }
  if ( (unsigned __int16)size != 65279 )
    goto LABEL_127;
  if ( _lseek_nolock(0, 475136, *pfh, 2, 0) == -1 )
    goto LABEL_74;
  v46 = 2;
LABEL_131:
  v28 = (char *)&__pioinfo[*pfh >> 5][1] + 64 * (*pfh & 0x1F);
  *v28 ^= (v46 ^ *v28) & 0x7F;
  v29 = (char *)&__pioinfo[*pfh >> 5][1] + 64 * (*pfh & 0x1F);
  *v29 = *v29 & 0x7F | (BYTE2(oflag) << 7);
  if ( !v45 && (oflag & 8) != 0 )
  {
    v30 = &__pioinfo[*pfh >> 5]->osfile + 64 * (*pfh & 0x1F);
    *v30 |= 0x20u;
  }
  v31 = dwDesiredAccess;
  if ( (dwDesiredAccess & 0xC0000000) == 0xC0000000 && (oflag & 1) != 0 )
  {
    CloseHandle(hFile);
    v32 = CreateFileA(path, v31 & 0x7FFFFFFF, dwShareMode, &SecurityAttributes, 3u, dwFlagsAndAttributes, 0);
    if ( v32 == (HANDLE)-1 )
    {
      v33 = GetLastError();
      _dosmaperr(v33);
      v34 = &__pioinfo[*pfh >> 5]->osfile + 64 * (*pfh & 0x1F);
      *v34 &= ~1u;
      _free_osfhnd(*pfh);
      return *_errno();
    }
    *(&__pioinfo[*pfh >> 5]->osfhnd + 16 * (*pfh & 0x1F)) = (int)v32;
  }
  return 0;
}
