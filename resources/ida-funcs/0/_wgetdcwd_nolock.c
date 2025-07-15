unsigned __int16 *__cdecl _wgetdcwd_nolock(unsigned int drive, unsigned __int16 *pnbuf, int maxlen)
{
  unsigned int v3; // esi
  unsigned __int16 *v4; // edi
  signed int FullPathNameW; // eax
  unsigned __int8 *v7; // eax
  signed int v8; // eax
  DWORD LastError; // eax
  unsigned __int16 *pname; // [esp+Ch] [ebp-14h] BYREF
  int count; // [esp+10h] [ebp-10h]
  wchar_t drvstr[4]; // [esp+14h] [ebp-Ch] BYREF

  v3 = drive;
  v4 = pnbuf;
  if ( !drive )
  {
    v3 = _getdrive();
LABEL_6:
    if ( pnbuf )
    {
      if ( maxlen <= 0 )
      {
        *_errno() = 22;
        goto LABEL_4;
      }
      count = maxlen;
      *pnbuf = 0;
    }
    else
    {
      count = 0;
    }
    if ( v3 )
    {
      wcscpy(&drvstr[1], L":.");
      drvstr[0] = v3 + 64;
    }
    else
    {
      wcscpy(drvstr, L".");
    }
    FullPathNameW = GetFullPathNameW(drvstr, count, pnbuf, &pname);
    if ( FullPathNameW )
    {
      if ( pnbuf )
      {
        if ( FullPathNameW >= count )
        {
          *_errno() = 34;
          *pnbuf = 0;
          return 0;
        }
        return v4;
      }
      if ( FullPathNameW > maxlen )
        maxlen = FullPathNameW;
      v7 = calloc(maxlen, 2u);
      v4 = (unsigned __int16 *)v7;
      if ( !v7 )
      {
        *_errno() = 12;
        *__doserrno() = 8;
        return 0;
      }
      v8 = GetFullPathNameW(drvstr, maxlen, (LPWSTR)v7, &pname);
      if ( v8 && v8 < maxlen )
        return v4;
    }
    LastError = GetLastError();
    _dosmaperr(LastError);
    return 0;
  }
  if ( _validdrive(drive) )
    goto LABEL_6;
  *__doserrno() = 15;
  *_errno() = 13;
LABEL_4:
  _invalid_parameter(0, (int)pnbuf, v3);
  return 0;
}
