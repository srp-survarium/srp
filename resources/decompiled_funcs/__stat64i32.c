int __cdecl _stat64i32(char *name, _stat64i32 *buf)
{
  const char *dwHighDateTime; // esi
  int v3; // eax
  unsigned int v4; // eax
  int v5; // eax
  unsigned __int8 *v6; // eax
  const char *v7; // esi
  int v8; // eax
  __int64 v9; // rax
  DWORD LastError; // eax
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
    _mbspbrk((unsigned int)buf, (unsigned __int8 *)name, "?*");
    if ( v3 )
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
      v4 = _mbctolower(*name) - 96;
    }
    else
    {
      v4 = _getdrive();
    }
    drive = v4;
    pBuf = (char *)FindFirstFileA(name, &findbuf);
    if ( pBuf == (char *)-1 )
    {
      pBuf = 0;
      _mbspbrk((unsigned int)buf, (unsigned __int8 *)name, "./\\");
      if ( !v5 )
        goto LABEL_5;
      v6 = (unsigned __int8 *)fullpath_helper(pathbuf, name, 0x104u, &pBuf);
      v7 = (const char *)v6;
      if ( !v6 || (strlen(v6), v8 != 3) && !IsRootUNCName(v7) || GetDriveTypeA(v7) <= 1 )
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
      v9 = __loctotime64_t(1980, 1, 1, 0, 0, 0, -1);
      dwHighDateTime = (const char *)LocalFTime.dwHighDateTime;
      buf->st_mtime = v9;
      buf->st_atime = v9;
      buf->st_ctime = v9;
LABEL_41:
      buf->st_mode = __dtoxmode(findbuf.dwFileAttributes, dwHighDateTime);
      buf->st_nlink = 1;
      buf->st_size = findbuf.nFileSizeLow;
      buf->st_ino = 0;
      buf->st_gid = 0;
      buf->st_uid = 0;
      buf->st_dev = drive - 1;
      buf->st_rdev = drive - 1;
      return 0;
    }
    if ( findbuf.ftLastWriteTime.dwLowDateTime || findbuf.ftLastWriteTime.dwHighDateTime )
    {
      if ( !FileTimeToLocalFileTime(&findbuf.ftLastWriteTime, &LocalFTime)
        || !FileTimeToSystemTime(&LocalFTime, &SystemTime) )
      {
        goto LABEL_42;
      }
      buf->st_mtime = __loctotime64_t(
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
      buf->st_atime = __loctotime64_t(
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
      buf->st_ctime = __loctotime64_t(
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
  _invalid_parameter(0, (unsigned int)buf, (unsigned int)name);
  return -1;
}
