int __cdecl _findnext32i64(HANDLE hFile, _finddata32i64_t *pfd)
{
  DWORD LastError; // eax
  int v4; // eax
  unsigned int nFileSizeHigh; // [esp-10h] [ebp-160h]
  _WIN32_FIND_DATAA FindFileData; // [esp+Ch] [ebp-144h] BYREF

  if ( hFile == (HANDLE)-1 || !pfd )
  {
    *_errno() = 22;
    _invalid_parameter(-1, 0, (int)pfd);
    return -1;
  }
  if ( !FindNextFileA(hFile, &FindFileData) )
  {
    LastError = GetLastError();
    if ( LastError >= 2 )
    {
      if ( LastError <= 3 )
        goto LABEL_12;
      if ( LastError == 8 )
      {
        *_errno() = 12;
        return -1;
      }
      if ( LastError == 18 )
      {
LABEL_12:
        *_errno() = 2;
        return -1;
      }
    }
    *_errno() = 22;
    return -1;
  }
  pfd->attrib = FindFileData.dwFileAttributes != 128 ? FindFileData.dwFileAttributes : 0;
  pfd->time_create = __timet_from_ft(&FindFileData.ftCreationTime);
  pfd->time_access = __timet_from_ft(&FindFileData.ftLastAccessTime);
  v4 = __timet_from_ft(&FindFileData.ftLastWriteTime);
  nFileSizeHigh = FindFileData.nFileSizeHigh;
  pfd->time_write = v4;
  LODWORD(pfd->size) = FindFileData.nFileSizeLow;
  HIDWORD(pfd->size) = nFileSizeHigh;
  if ( strcpy_s(0, pfd->name, 260, FindFileData.cFileName) )
    _invoke_watson(0, 0, (int)pfd->name);
  return 0;
}
