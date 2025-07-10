int __usercall tsopen_nolock@<eax>(
        int *pfh@<eax>,
        unsigned int a2@<edi>,
        int *punlock_flag,
        const char *path,
        int oflag,
        int shflag,
        char pmode)
{
  unsigned int v8; // edi
  unsigned int v9; // eax
  int v10; // eax
  char *v11; // eax
  DWORD LastError; // eax
  DWORD FileType; // eax
  char *v15; // eax
  DWORD v16; // esi
  char v17; // cl
  _BYTE *v18; // eax
  HINSTANCE__ *v19; // eax
  unsigned int v20; // eax
  int v21; // eax
  int v22; // edi
  doubleint v23; // rax
  int v24; // eax
  doubleint v25; // rax
  unsigned int v26; // eax
  int v27; // eax
  _BYTE *v28; // eax
  _BYTE *v29; // eax
  char *v30; // eax
  unsigned int v31; // edi
  HANDLE v32; // eax
  DWORD v33; // eax
  char *v34; // eax
  int v35; // [esp-Ch] [ebp-48h]
  DWORD v36; // [esp-8h] [ebp-44h]
  _SECURITY_ATTRIBUTES SecurityAttributes; // [esp+Ch] [ebp-30h] BYREF
  int fmode; // [esp+1Ch] [ebp-20h] BYREF
  void *osfh; // [esp+20h] [ebp-1Ch]
  int bom; // [esp+24h] [ebp-18h] BYREF
  int bomlen; // [esp+28h] [ebp-14h]
  unsigned int fileshare; // [esp+2Ch] [ebp-10h]
  unsigned int fileattrib; // [esp+30h] [ebp-Ch]
  unsigned int fileaccess; // [esp+34h] [ebp-8h]
  char inputbuf; // [esp+38h] [ebp-4h] BYREF
  char v46; // [esp+39h] [ebp-3h]
  char tmode; // [esp+3Ah] [ebp-2h]
  char fileflags; // [esp+3Bh] [ebp-1h]

  fmode = 0;
  tmode = 0;
  SecurityAttributes.nLength = 12;
  SecurityAttributes.lpSecurityDescriptor = 0;
  if ( (oflag & 0x80u) == 0 )
  {
    SecurityAttributes.bInheritHandle = 1;
    fileflags = 0;
  }
  else
  {
    SecurityAttributes.bInheritHandle = 0;
    fileflags = 16;
  }
  if ( _get_fmode(&fmode) )
    _invoke_watson(0, a2, (unsigned int)pfh);
  if ( (oflag & 0x8000) == 0 && ((oflag & 0x74000) != 0 || fmode != 0x8000) )
    fileflags |= 0x80u;
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
        _invalid_parameter(0, v8, 0x16u);
        return 22;
      }
      goto LABEL_14;
    }
    if ( (oflag & 8) != 0 && (oflag & 0x70000) != 0 )
    {
LABEL_14:
      fileaccess = -1073741824;
      goto LABEL_19;
    }
    fileaccess = 0x40000000;
  }
  else
  {
    fileaccess = 0x80000000;
  }
LABEL_19:
  switch ( shflag )
  {
    case 16:
      fileshare = 0;
      break;
    case 32:
      fileshare = 1;
      break;
    case 48:
      fileshare = 2;
      break;
    case 64:
      fileshare = 3;
      break;
    case 128:
      fileshare = fileaccess == 0x80000000;
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
    bomlen = 1;
    goto LABEL_42;
  }
  if ( (oflag & 0x700) == 0x400 || (oflag & 0x700) == 0 )
  {
    bomlen = 3;
    goto LABEL_42;
  }
  if ( v9 == 256 )
  {
    bomlen = 4;
    goto LABEL_42;
  }
  if ( v9 == 512 )
  {
LABEL_51:
    bomlen = 5;
    goto LABEL_42;
  }
  if ( v9 != 768 )
    goto LABEL_13;
  bomlen = 2;
LABEL_42:
  fileattrib = 128;
  if ( (oflag & 0x100) != 0 && (pmode & ~(_BYTE)_umaskval & 0x80u) == 0 )
    fileattrib = 1;
  if ( (oflag & 0x40) != 0 )
  {
    fileattrib |= (unsigned int)&vostok::memory::s_CRT_arena[55905848];
    fileaccess |= (unsigned int)&_sbh_sizeHeaderList;
    fileshare |= 4u;
  }
  if ( (oflag & 0x1000) != 0 )
    fileattrib |= 0x100u;
  if ( (oflag & 0x20) != 0 )
  {
    fileattrib |= 0x8000000u;
  }
  else if ( (oflag & 0x10) != 0 )
  {
    fileattrib |= 0x10000000u;
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
  v36 = fileattrib;
  *punlock_flag = 1;
  osfh = CreateFileA(path, fileaccess, fileshare, &SecurityAttributes, bomlen, v36, 0);
  if ( osfh == (void *)-1 )
  {
    if ( (fileaccess & 0xC0000000) != 0xC0000000
      || (oflag & 1) == 0
      || (fileaccess &= ~0x80000000,
          osfh = CreateFileA(path, fileaccess, fileshare, &SecurityAttributes, bomlen, fileattrib, 0),
          osfh == (void *)-1) )
    {
      v11 = &__pioinfo[*pfh >> 5]->osfile + 64 * (*pfh & 0x1F);
      *v11 &= ~1u;
      LastError = GetLastError();
      _dosmaperr(LastError);
      return *_errno();
    }
  }
  FileType = GetFileType(osfh);
  switch ( FileType )
  {
    case 0u:
      v15 = &__pioinfo[*pfh >> 5]->osfile + 64 * (*pfh & 0x1F);
      *v15 &= ~1u;
      v16 = GetLastError();
      _dosmaperr(v16);
      CloseHandle(osfh);
      if ( !v16 )
        *_errno() = 13;
      return *_errno();
    case 2u:
      fileflags |= 0x40u;
      break;
    case 3u:
      fileflags |= 8u;
      break;
  }
  _set_osfhnd(*pfh, osfh);
  v17 = fileflags | 1;
  *(&__pioinfo[*pfh >> 5]->osfile + 64 * (*pfh & 0x1F)) = fileflags | 1;
  v18 = (char *)&__pioinfo[*pfh >> 5][1] + 64 * (*pfh & 0x1F);
  *v18 &= 0x80u;
  v46 = v17 & 0x48;
  fileflags = v17;
  if ( (v17 & 0x48) == 0 )
  {
    if ( v17 >= 0 )
      goto LABEL_131;
    if ( (oflag & 2) != 0 )
    {
      bom = _lseek_nolock(*pfh, -1, 2u);
      if ( bom == -1 )
      {
        if ( *__doserrno() != 131 )
        {
LABEL_74:
          _close_nolock(*pfh);
          return *_errno();
        }
      }
      else
      {
        v35 = *pfh;
        inputbuf = 0;
        if ( !_read_nolock(0xFFFFFFFF, v35, &inputbuf, 1u) && inputbuf == 26 && _chsize_nolock(*pfh, bom) == -1
          || _lseek_nolock(*pfh, 0, 0) == -1 )
        {
          goto LABEL_74;
        }
      }
    }
  }
  if ( fileflags >= 0 )
    goto LABEL_131;
  if ( (oflag & 0x74000) == 0 )
  {
    if ( (fmode & 0x74000) != 0 )
      oflag |= fmode & 0x74000;
    else
      oflag |= 0x4000u;
  }
  v19 = (HINSTANCE__ *)(oflag & 0x74000);
  if ( (oflag & 0x74000) == 0x4000 )
  {
    tmode = 0;
    goto LABEL_95;
  }
  if ( v19 == &_sbh_sizeHeaderList || v19 == (HINSTANCE__ *)&loc_14000 )
  {
    if ( (oflag & 0x301) != 0x301 )
      goto LABEL_95;
LABEL_93:
    tmode = 2;
    goto LABEL_95;
  }
  if ( v19 == (HINSTANCE__ *)&loc_20000 || v19 == (HINSTANCE__ *)((char *)&loc_23FFF + 1) )
    goto LABEL_93;
  if ( v19 == (HINSTANCE__ *)((char *)&loc_3FFFF + 1) || v19 == (HINSTANCE__ *)&loc_43FFC + 1 )
    tmode = 1;
LABEL_95:
  if ( (oflag & 0x70000) == 0 )
    goto LABEL_131;
  bom = 0;
  if ( (fileflags & 0x40) != 0 )
    goto LABEL_131;
  v20 = fileaccess & 0xC0000000;
  if ( (fileaccess & 0xC0000000) == 0x40000000 )
  {
    v21 = bomlen;
    if ( !bomlen )
      goto LABEL_131;
    if ( (unsigned int)bomlen > 2 )
    {
      if ( (unsigned int)bomlen > 4 )
      {
LABEL_103:
        if ( v21 != 5 )
          goto LABEL_131;
        goto LABEL_104;
      }
      if ( _lseeki64_nolock(*pfh, 0, 2u).bigint )
      {
        v25.bigint = _lseeki64_nolock(*pfh, 0, 0).bigint;
        v26 = v25.twoints.upperhalf & v25.twoints.lowerhalf;
        goto LABEL_119;
      }
    }
    goto LABEL_104;
  }
  if ( v20 == 0x80000000 )
    goto LABEL_109;
  if ( v20 != -1073741824 )
    goto LABEL_131;
  v21 = bomlen;
  if ( !bomlen )
    goto LABEL_131;
  if ( (unsigned int)bomlen <= 2 )
    goto LABEL_104;
  if ( (unsigned int)bomlen > 4 )
    goto LABEL_103;
  if ( !_lseeki64_nolock(*pfh, 0, 2u).bigint )
  {
LABEL_104:
    v22 = 0;
    if ( tmode == 1 )
    {
      bom = (int)&vostok::memory::s_CRT_arena[1362471];
      bomlen = 3;
LABEL_129:
      while ( 1 )
      {
        v27 = _write(0, (unsigned int)pfh, *pfh, (char *)&bom + v22, bomlen - v22);
        if ( v27 == -1 )
          goto LABEL_74;
        v22 += v27;
        if ( bomlen <= v22 )
          goto LABEL_131;
      }
    }
    if ( tmode == 2 )
    {
      bom = 65279;
      bomlen = 2;
      goto LABEL_129;
    }
    goto LABEL_131;
  }
  v23.bigint = _lseeki64_nolock(*pfh, 0, 0).bigint;
  if ( (v23.twoints.upperhalf & v23.twoints.lowerhalf) == -1 )
    goto LABEL_74;
LABEL_109:
  v24 = _read_nolock(0x74000u, *pfh, &bom, 3u);
  if ( v24 == -1 )
    goto LABEL_74;
  if ( v24 != 2 )
  {
    if ( v24 != 3 )
    {
LABEL_127:
      v26 = _lseek_nolock(*pfh, 0, 0);
LABEL_119:
      if ( v26 == -1 )
        goto LABEL_74;
      goto LABEL_131;
    }
    if ( (unsigned __int8 *)bom == &vostok::memory::s_CRT_arena[1362471] )
    {
      tmode = 1;
      goto LABEL_131;
    }
  }
  if ( (unsigned __int16)bom == 65534 )
  {
    _close_nolock(*pfh);
    *_errno() = 22;
    return 22;
  }
  if ( (unsigned __int16)bom != 65279 )
    goto LABEL_127;
  if ( _lseek_nolock(*pfh, 2, 0) == -1 )
    goto LABEL_74;
  tmode = 2;
LABEL_131:
  v28 = (char *)&__pioinfo[*pfh >> 5][1] + 64 * (*pfh & 0x1F);
  *v28 ^= (tmode ^ *v28) & 0x7F;
  v29 = (char *)&__pioinfo[*pfh >> 5][1] + 64 * (*pfh & 0x1F);
  *v29 = *v29 & 0x7F | (BYTE2(oflag) << 7);
  if ( !v46 && (oflag & 8) != 0 )
  {
    v30 = &__pioinfo[*pfh >> 5]->osfile + 64 * (*pfh & 0x1F);
    *v30 |= 0x20u;
  }
  v31 = fileaccess;
  if ( (fileaccess & 0xC0000000) == 0xC0000000 && (oflag & 1) != 0 )
  {
    CloseHandle(osfh);
    v32 = CreateFileA(path, v31 & 0x7FFFFFFF, fileshare, &SecurityAttributes, 3u, fileattrib, 0);
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
