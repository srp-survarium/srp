LPSTR __cdecl _fullpath(char *UserBuf, const char *path, DWORD maxlen)
{
  DWORD FullPathNameA; // eax
  DWORD LastError; // eax
  unsigned int v6; // edi
  unsigned __int8 *v7; // eax
  DWORD v8; // eax
  LPSTR FilePart; // [esp+Ch] [ebp-8h] BYREF
  LPSTR lpBuffer; // [esp+10h] [ebp-4h]

  if ( !path || !*path )
    return _getcwd(UserBuf, maxlen);
  if ( UserBuf )
  {
    v6 = maxlen;
    if ( !maxlen )
    {
      *_errno() = 22;
      _invalid_parameter(0, 0, (int)GetFullPathNameA);
      return 0;
    }
    lpBuffer = UserBuf;
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
    v7 = calloc(v6, 1u);
    lpBuffer = (LPSTR)v7;
    if ( !v7 )
    {
      *_errno() = 12;
      return 0;
    }
  }
  v8 = GetFullPathNameA(path, v6, lpBuffer, &FilePart);
  if ( v8 >= v6 )
  {
    if ( !UserBuf )
      free(lpBuffer);
    *_errno() = 34;
    return 0;
  }
  if ( !v8 )
  {
    if ( !UserBuf )
      free(lpBuffer);
    goto LABEL_5;
  }
  return lpBuffer;
}
