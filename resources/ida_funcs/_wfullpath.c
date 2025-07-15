unsigned __int16 *__cdecl _wfullpath(unsigned __int16 *UserBuf, const wchar_t *path, DWORD maxlen)
{
  DWORD FullPathNameW; // eax
  DWORD LastError; // eax
  unsigned int v6; // edi
  DWORD v7; // eax
  unsigned __int16 *pfname; // [esp+Ch] [ebp-8h] BYREF
  unsigned __int16 *buf; // [esp+10h] [ebp-4h]

  if ( !path || !*path )
    return _wgetcwd(UserBuf, maxlen);
  if ( UserBuf )
  {
    v6 = maxlen;
    if ( !maxlen )
    {
      *_errno() = 22;
      _invalid_parameter(0, 0, (unsigned int)GetFullPathNameW);
      return 0;
    }
    buf = UserBuf;
  }
  else
  {
    FullPathNameW = GetFullPathNameW(path, 0, 0, 0);
    if ( !FullPathNameW )
    {
LABEL_5:
      LastError = GetLastError();
      _dosmaperr(LastError);
      return 0;
    }
    v6 = maxlen;
    if ( maxlen <= FullPathNameW )
      v6 = FullPathNameW;
    if ( v6 > 0x7FFFFFFF )
    {
      *_errno() = 22;
      return 0;
    }
    buf = (unsigned __int16 *)calloc(v6, 2u);
    if ( !buf )
    {
      *_errno() = 12;
      return 0;
    }
  }
  v7 = GetFullPathNameW(path, v6, buf, &pfname);
  if ( v7 >= v6 )
  {
    if ( !UserBuf )
      free(buf);
    *_errno() = 34;
    return 0;
  }
  if ( !v7 )
  {
    if ( !UserBuf )
      free(buf);
    goto LABEL_5;
  }
  return buf;
}
