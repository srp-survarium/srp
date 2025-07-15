int __cdecl _findfirst32i64(const char *szWild, _finddata32i64_t *pfd)
{
  DWORD LastError; // eax
  int v4; // eax
  unsigned int nFileSizeHigh; // [esp-14h] [ebp-164h]
  HANDLE hFile; // [esp+8h] [ebp-148h]
  _WIN32_FIND_DATAA wfd; // [esp+Ch] [ebp-144h] BYREF

  if ( !pfd || !szWild )
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return -1;
  }
  hFile = FindFirstFileA(szWild, &wfd);
  if ( hFile == (HANDLE)-1 )
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
  pfd->attrib = wfd.dwFileAttributes != 128 ? wfd.dwFileAttributes : 0;
  pfd->time_create = __timet_from_ft(&wfd.ftCreationTime);
  pfd->time_access = __timet_from_ft(&wfd.ftLastAccessTime);
  v4 = __timet_from_ft(&wfd.ftLastWriteTime);
  nFileSizeHigh = wfd.nFileSizeHigh;
  pfd->time_write = v4;
  LODWORD(pfd->size) = wfd.nFileSizeLow;
  HIDWORD(pfd->size) = nFileSizeHigh;
  if ( strcpy_s(pfd->name, 0x104u, wfd.cFileName) )
    _invoke_watson(0, 0, 0, 0, 0);
  return (int)hFile;
}
