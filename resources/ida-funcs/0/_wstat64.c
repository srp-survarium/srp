int __cdecl _wstat64(const wchar_t *name, _stat64 *buf)
{
  const wchar_t *dwHighDateTime; // esi
  unsigned int v3; // eax
  const wchar_t *v4; // eax
  const wchar_t *v5; // esi
  __int64 v6; // rax
  int v7; // edx
  int v8; // edx
  int v9; // edx
  __int64 v10; // rax
  DWORD LastError; // eax
  __int64 nFileSizeHigh; // [esp-10h] [ebp-498h]
  int drive; // [esp+Ch] [ebp-47Ch]
  _FILETIME LocalFTime; // [esp+10h] [ebp-478h] BYREF
  _SYSTEMTIME SystemTime; // [esp+18h] [ebp-470h] BYREF
  unsigned __int16 *pBuf; // [esp+28h] [ebp-460h] BYREF
  _WIN32_FIND_DATAW findbuf; // [esp+2Ch] [ebp-45Ch] BYREF
  wchar_t pathbuf[260]; // [esp+27Ch] [ebp-20Ch] BYREF

  dwHighDateTime = name;
  LocalFTime.dwHighDateTime = (unsigned int)name;
  if ( name && buf )
  {
    if ( wcspbrk(name, L"?*") )
    {
LABEL_5:
      *_errno() = 2;
      *__doserrno() = 2;
      return -1;
    }
    if ( name[1] == 58 )
    {
      if ( *name && !name[2] )
        goto LABEL_5;
      v3 = towlower(*name) - 96;
    }
    else
    {
      v3 = _getdrive();
    }
    drive = v3;
    pBuf = (unsigned __int16 *)FindFirstFileW(name, &findbuf);
    if ( pBuf == (unsigned __int16 *)-1 )
    {
      pBuf = 0;
      if ( !wcspbrk(name, L"./\\") )
        goto LABEL_5;
      v4 = wfullpath_helper(pathbuf, name, 0x104u, &pBuf);
      v5 = v4;
      if ( !v4 || wcslen(v4) != 3 && !IsRootUNCName_0(v5) || GetDriveTypeW(v5) <= 1 )
      {
        if ( pBuf )
          free(pBuf);
        goto LABEL_5;
      }
      if ( pBuf )
        free(pBuf);
      findbuf.dwFileAttributes = 16;
      findbuf.nFileSizeHigh = 0;
      findbuf.nFileSizeLow = 0;
      findbuf.cFileName[0] = 0;
      LODWORD(v6) = __loctotime64_t(1980, 1, 1, 0, 0, 0, -1);
      dwHighDateTime = (const wchar_t *)LocalFTime.dwHighDateTime;
      buf->st_mtime = v6;
      buf->st_atime = v6;
      buf->st_ctime = v6;
LABEL_41:
      buf->st_mode = __wdtoxmode(findbuf.dwFileAttributes, dwHighDateTime);
      nFileSizeHigh = findbuf.nFileSizeHigh;
      buf->st_nlink = 1;
      v10 = findbuf.nFileSizeLow + (nFileSizeHigh << 32);
      LODWORD(buf->st_size) = findbuf.nFileSizeLow;
      buf->st_ino = 0;
      buf->st_gid = 0;
      buf->st_uid = 0;
      buf->st_dev = drive - 1;
      buf->st_rdev = drive - 1;
      HIDWORD(buf->st_size) = HIDWORD(v10);
      return 0;
    }
    if ( findbuf.ftLastWriteTime.dwLowDateTime || findbuf.ftLastWriteTime.dwHighDateTime )
    {
      if ( !FileTimeToLocalFileTime(&findbuf.ftLastWriteTime, &LocalFTime)
        || !FileTimeToSystemTime(&LocalFTime, &SystemTime) )
      {
        goto LABEL_42;
      }
      LODWORD(buf->st_mtime) = __loctotime64_t(
                                 SystemTime.wYear,
                                 SystemTime.wMonth,
                                 SystemTime.wDay,
                                 SystemTime.wHour,
                                 SystemTime.wMinute,
                                 SystemTime.wSecond,
                                 -1);
      HIDWORD(buf->st_mtime) = v7;
    }
    else
    {
      buf->st_mtime = 0;
    }
    if ( findbuf.ftLastAccessTime.dwLowDateTime || findbuf.ftLastAccessTime.dwHighDateTime )
    {
      if ( !FileTimeToLocalFileTime(&findbuf.ftLastAccessTime, &LocalFTime)
        || !FileTimeToSystemTime(&LocalFTime, &SystemTime) )
      {
        goto LABEL_42;
      }
      LODWORD(buf->st_atime) = __loctotime64_t(
                                 SystemTime.wYear,
                                 SystemTime.wMonth,
                                 SystemTime.wDay,
                                 SystemTime.wHour,
                                 SystemTime.wMinute,
                                 SystemTime.wSecond,
                                 -1);
      HIDWORD(buf->st_atime) = v8;
    }
    else
    {
      buf->st_atime = buf->st_mtime;
    }
    if ( !findbuf.ftCreationTime.dwLowDateTime && !findbuf.ftCreationTime.dwHighDateTime )
    {
      buf->st_ctime = buf->st_mtime;
LABEL_40:
      FindClose(pBuf);
      goto LABEL_41;
    }
    if ( FileTimeToLocalFileTime(&findbuf.ftCreationTime, &LocalFTime) && FileTimeToSystemTime(&LocalFTime, &SystemTime) )
    {
      LODWORD(buf->st_ctime) = __loctotime64_t(
                                 SystemTime.wYear,
                                 SystemTime.wMonth,
                                 SystemTime.wDay,
                                 SystemTime.wHour,
                                 SystemTime.wMinute,
                                 SystemTime.wSecond,
                                 -1);
      HIDWORD(buf->st_ctime) = v9;
      goto LABEL_40;
    }
LABEL_42:
    LastError = GetLastError();
    _dosmaperr(LastError);
    FindClose(pBuf);
    return -1;
  }
  *__doserrno() = 0;
  *_errno() = 22;
  _invalid_parameter(0, (unsigned int)buf, (unsigned int)name);
  return -1;
}
