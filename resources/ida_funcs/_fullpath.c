char *__cdecl _fullpath(char *UserBuf, const char *path, DWORD maxlen)
{
  DWORD FullPathNameA; // eax
  DWORD LastError; // eax
  unsigned int v6; // edi
  char *v7; // eax
  DWORD v8; // eax
  char *pfname; // [esp+Ch] [ebp-8h] BYREF
  char *buf; // [esp+10h] [ebp-4h]

  if ( !path || !*path )
    return _getcwd(UserBuf, maxlen);
  if ( UserBuf )
  {
    v6 = maxlen;
    if ( !maxlen )
    {
      *_errno() = 22;
      _invalid_parameter(0, 0, (unsigned int)GetFullPathNameA);
      return 0;
    }
    buf = UserBuf;
  }
  else
  {
    FullPathNameA = GetFullPathNameA(path, 0, 0, 0);
    if ( !FullPathNameA )
    {
LABEL_5:
      LastError = GetLastError();
      _dosmaperr(LastError);
      return 0;
    }
    v6 = maxlen;
    if ( maxlen <= FullPathNameA )
      v6 = FullPathNameA;
    v7 = (char *)calloc(v6, 1u);
    buf = v7;
    if ( !v7 )
    {
      *_errno() = 12;
      return 0;
    }
  }
  v8 = GetFullPathNameA(path, v6, buf, &pfname);
  if ( v8 >= v6 )
  {
    if ( !UserBuf )
      free(buf);
    *_errno() = 34;
    return 0;
  }
  if ( !v8 )
  {
    if ( !UserBuf )
      free(buf);
    goto LABEL_5;
  }
  return buf;
}
