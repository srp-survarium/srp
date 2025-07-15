int __cdecl _stat64i32(char *name, _stat64i32 *buf)
{
  const char *dwHighDateTime; // esi
  int v3; // eax
  int v4; // eax
  int v5; // eax
  unsigned __int8 *v6; // eax
  const char *v7; // esi
  int v8; // eax
  __int64 v9; // rax
  int v10; // edx
  int v11; // edx
  int v12; // edx
  DWORD LastError; // eax
  int v15; // [esp+Ch] [ebp-268h]
  _FILETIME LocalFileTime; // [esp+10h] [ebp-264h] BYREF
  _SYSTEMTIME SystemTime; // [esp+18h] [ebp-25Ch] BYREF
  void *pointer; // [esp+28h] [ebp-24Ch] BYREF
  _WIN32_FIND_DATAA FindFileData; // [esp+2Ch] [ebp-248h] BYREF
  char v20[260]; // [esp+16Ch] [ebp-108h] BYREF

  dwHighDateTime = name;
  LocalFileTime.dwHighDateTime = (unsigned int)name;
  if ( name && buf )
  {
    _mbspbrk((int)buf, (unsigned __int8 *)name, "?*");
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
    v15 = v4;
    pointer = FindFirstFileA(name, &FindFileData);
    if ( pointer == (void *)-1 )
    {
      pointer = 0;
      _mbspbrk((int)buf, (unsigned __int8 *)name, "./\\");
      if ( !v5 )
        goto LABEL_5;
      v6 = (unsigned __int8 *)fullpath_helper(v20, name, 0x104u, (char **)&pointer);
      v7 = (const char *)v6;
      if ( !v6 || (strlen(v6), v8 != 3) && !IsRootUNCName(v7) || GetDriveTypeA(v7) <= 1 )
      {
        if ( pointer )
          free(pointer);
        goto LABEL_5;
      }
      if ( pointer )
        free(pointer);
      FindFileData.dwFileAttributes = 16;
      FindFileData.nFileSizeHigh = 0;
      FindFileData.nFileSizeLow = 0;
      FindFileData.cFileName[0] = 0;
      LODWORD(v9) = __loctotime64_t(1980, 1, 1, 0, 0, 0, -1);
      dwHighDateTime = (const char *)LocalFileTime.dwHighDateTime;
      buf->st_mtime = v9;
      buf->st_atime = v9;
      buf->st_ctime = v9;
LABEL_41:
      buf->st_mode = __dtoxmode(0, FindFileData.dwFileAttributes, dwHighDateTime);
      buf->st_nlink = 1;
      buf->st_size = FindFileData.nFileSizeLow;
      buf->st_ino = 0;
      buf->st_gid = 0;
      buf->st_uid = 0;
      buf->st_dev = v15 - 1;
      buf->st_rdev = v15 - 1;
      return 0;
    }
    if ( FindFileData.ftLastWriteTime.dwLowDateTime || FindFileData.ftLastWriteTime.dwHighDateTime )
    {
      if ( !FileTimeToLocalFileTime(&FindFileData.ftLastWriteTime, &LocalFileTime)
        || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
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
      HIDWORD(buf->st_mtime) = v10;
    }
    else
    {
      buf->st_mtime = 0;
    }
    if ( FindFileData.ftLastAccessTime.dwLowDateTime || FindFileData.ftLastAccessTime.dwHighDateTime )
    {
      if ( !FileTimeToLocalFileTime(&FindFileData.ftLastAccessTime, &LocalFileTime)
        || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
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
      HIDWORD(buf->st_atime) = v11;
    }
    else
    {
      buf->st_atime = buf->st_mtime;
    }
    if ( !FindFileData.ftCreationTime.dwLowDateTime && !FindFileData.ftCreationTime.dwHighDateTime )
    {
      buf->st_ctime = buf->st_mtime;
LABEL_40:
      FindClose(pointer);
      goto LABEL_41;
    }
    if ( FileTimeToLocalFileTime(&FindFileData.ftCreationTime, &LocalFileTime)
      && FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
    {
      LODWORD(buf->st_ctime) = __loctotime64_t(
                                 SystemTime.wYear,
                                 SystemTime.wMonth,
                                 SystemTime.wDay,
                                 SystemTime.wHour,
                                 SystemTime.wMinute,
                                 SystemTime.wSecond,
                                 -1);
      HIDWORD(buf->st_ctime) = v12;
      goto LABEL_40;
    }
LABEL_42:
    LastError = GetLastError();
    _dosmaperr(LastError);
    FindClose(pointer);
    return -1;
  }
  *__doserrno() = 0;
  *_errno() = 22;
  _invalid_parameter(0, (int)buf, (int)name);
  return -1;
}
