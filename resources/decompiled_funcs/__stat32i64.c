int __cdecl _stat32i64(const char *name, _stat32i64 *buf)
{
  const char *dwHighDateTime; // esi
  unsigned int v3; // eax
  unsigned __int8 *v4; // eax
  const char *v5; // esi
  int v6; // eax
  int v7; // eax
  int st_mtime; // eax
  int v9; // eax
  __int64 v10; // rax
  DWORD LastError; // eax
  __int64 nFileSizeHigh; // [esp-10h] [ebp-284h]
  char *v14; // [esp-4h] [ebp-278h]
  int drive; // [esp+Ch] [ebp-268h]
  _FILETIME LocalFTime; // [esp+10h] [ebp-264h] BYREF
  _SYSTEMTIME SystemTime; // [esp+18h] [ebp-25Ch] BYREF
  char *pBuf; // [esp+28h] [ebp-24Ch] BYREF
  _WIN32_FIND_DATAA findbuf; // [esp+2Ch] [ebp-248h] BYREF
  char pathbuf[260]; // [esp+16Ch] [ebp-108h] BYREF

  dwHighDateTime = name;
  LocalFTime.dwHighDateTime = (unsigned int)name;
  if ( name && buf )
  {
    if ( _mbspbrk((const unsigned __int8 *)name, "?*") )
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
      v3 = _mbctolower(*name) - 96;
    }
    else
    {
      v3 = _getdrive();
    }
    drive = v3;
    pBuf = (char *)FindFirstFileA(name, &findbuf);
    if ( pBuf == (char *)-1 )
    {
      pBuf = 0;
      if ( !_mbspbrk((const unsigned __int8 *)name, "./\\") )
        goto LABEL_5;
      v4 = (unsigned __int8 *)fullpath_helper(pathbuf, name, 0x104u, &pBuf);
      v5 = (const char *)v4;
      if ( !v4 || (strlen(v4), v6 != 3) && !IsRootUNCName(v5) || GetDriveTypeA(v5) <= 1 )
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
      v7 = __loctotime32_t(1980, 1, 1, 0, 0, 0, -1);
      dwHighDateTime = (const char *)LocalFTime.dwHighDateTime;
      buf->st_mtime = v7;
      buf->st_atime = v7;
      buf->st_ctime = v7;
LABEL_41:
      buf->st_mode = __dtoxmode(findbuf.dwFileAttributes, dwHighDateTime);
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
      buf->st_mtime = __loctotime32_t(
                        SystemTime.wYear,
                        SystemTime.wMonth,
                        SystemTime.wDay,
                        SystemTime.wHour,
                        SystemTime.wMinute,
                        SystemTime.wSecond,
                        -1);
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
      st_mtime = __loctotime32_t(
                   SystemTime.wYear,
                   SystemTime.wMonth,
                   SystemTime.wDay,
                   SystemTime.wHour,
                   SystemTime.wMinute,
                   SystemTime.wSecond,
                   -1);
    }
    else
    {
      st_mtime = buf->st_mtime;
    }
    buf->st_atime = st_mtime;
    if ( !findbuf.ftCreationTime.dwLowDateTime && !findbuf.ftCreationTime.dwHighDateTime )
    {
      v9 = buf->st_mtime;
LABEL_40:
      v14 = pBuf;
      buf->st_ctime = v9;
      FindClose(v14);
      goto LABEL_41;
    }
    if ( FileTimeToLocalFileTime(&findbuf.ftCreationTime, &LocalFTime) && FileTimeToSystemTime(&LocalFTime, &SystemTime) )
    {
      v9 = __loctotime32_t(
             SystemTime.wYear,
             SystemTime.wMonth,
             SystemTime.wDay,
             SystemTime.wHour,
             SystemTime.wMinute,
             SystemTime.wSecond,
             -1);
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
  _invalid_parameter(0, 0, 0, 0, 0);
  return -1;
}
