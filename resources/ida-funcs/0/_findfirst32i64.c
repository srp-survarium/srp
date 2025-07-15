int __usercall _findfirst32i64@<eax>(int a1@<ebx>, const char *szWild, _finddata32i64_t *pfd)
{
  DWORD LastError; // eax
  int v5; // eax
  unsigned int nFileSizeHigh; // [esp-14h] [ebp-164h]
  HANDLE FirstFileA; // [esp+8h] [ebp-148h]
  _WIN32_FIND_DATAA FindFileData; // [esp+Ch] [ebp-144h] BYREF

  if ( !pfd || !szWild )
  {
    *_errno() = 22;
    _invalid_parameter(a1, 0, (int)pfd);
    return -1;
  }
  FirstFileA = FindFirstFileA(szWild, &FindFileData);
  if ( FirstFileA == (HANDLE)-1 )
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
  v5 = __timet_from_ft(&FindFileData.ftLastWriteTime);
  nFileSizeHigh = FindFileData.nFileSizeHigh;
  pfd->time_write = v5;
  LODWORD(pfd->size) = FindFileData.nFileSizeLow;
  HIDWORD(pfd->size) = nFileSizeHigh;
  if ( strcpy_s(0, pfd->name, 260, FindFileData.cFileName) )
    _invoke_watson(a1, 0, (int)pfd->name);
  return (int)FirstFileA;
}
