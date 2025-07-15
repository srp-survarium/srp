char *__usercall _getdcwd_nolock@<eax>(int a1@<edi>, int a2@<esi>, DWORD drive, char *pnbuf, int maxlen)
{
  int v6; // eax
  char *v7; // edi
  signed int FullPathNameA; // eax
  unsigned __int8 *v9; // eax
  signed int v10; // eax
  DWORD LastError; // eax
  LPSTR FilePart; // [esp+4h] [ebp-8h] BYREF
  char FileName; // [esp+8h] [ebp-4h] BYREF
  char v14[3]; // [esp+9h] [ebp-3h] BYREF
  int nBufferLength; // [esp+14h] [ebp+8h]

  if ( drive )
  {
    if ( !_validdrive(drive) )
    {
      *__doserrno() = 15;
      *_errno() = 13;
      _invalid_parameter(0, a1, a2);
      return 0;
    }
    v6 = drive;
  }
  else
  {
    v6 = _getdrive();
  }
  v7 = pnbuf;
  if ( pnbuf )
  {
    if ( maxlen <= 0 )
    {
      *_errno() = 22;
      _invalid_parameter(0, (int)pnbuf, a2);
      return 0;
    }
    nBufferLength = maxlen;
    *pnbuf = 0;
  }
  else
  {
    nBufferLength = 0;
  }
  if ( v6 )
  {
    FileName = v6 + 64;
    strcpy(v14, ":.");
  }
  else
  {
    FileName = 46;
    v14[0] = 0;
  }
  FullPathNameA = GetFullPathNameA(&FileName, nBufferLength, pnbuf, &FilePart);
  if ( !FullPathNameA )
    goto LABEL_25;
  if ( !pnbuf )
  {
    if ( FullPathNameA > maxlen )
      maxlen = FullPathNameA;
    v9 = calloc(maxlen, 1u);
    v7 = (char *)v9;
    if ( !v9 )
    {
      *_errno() = 12;
      *__doserrno() = 8;
      return 0;
    }
    v10 = GetFullPathNameA(&FileName, maxlen, (LPSTR)v9, &FilePart);
    if ( v10 && v10 < maxlen )
      return v7;
LABEL_25:
    LastError = GetLastError();
    _dosmaperr(LastError);
    return 0;
  }
  if ( FullPathNameA < nBufferLength )
    return v7;
  *_errno() = 34;
  *pnbuf = 0;
  return 0;
}
