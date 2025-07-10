char *__usercall _getdcwd_nolock@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        unsigned int drive,
        char *pnbuf,
        int maxlen)
{
  unsigned int v6; // eax
  char *v7; // edi
  signed int FullPathNameA; // eax
  char *v9; // eax
  signed int v10; // eax
  DWORD LastError; // eax
  char *pname; // [esp+4h] [ebp-8h] BYREF
  char drvstr[4]; // [esp+8h] [ebp-4h] BYREF
  signed int count; // [esp+14h] [ebp+8h]

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
      _invalid_parameter(0, (unsigned int)pnbuf, a2);
      return 0;
    }
    count = maxlen;
    *pnbuf = 0;
  }
  else
  {
    count = 0;
  }
  if ( v6 )
  {
    drvstr[0] = v6 + 64;
    strcpy(&drvstr[1], ":.");
  }
  else
  {
    strcpy(drvstr, ".");
  }
  FullPathNameA = GetFullPathNameA(drvstr, count, pnbuf, &pname);
  if ( !FullPathNameA )
    goto LABEL_25;
  if ( !pnbuf )
  {
    if ( FullPathNameA > maxlen )
      maxlen = FullPathNameA;
    v9 = (char *)calloc(maxlen, 1u);
    v7 = v9;
    if ( !v9 )
    {
      *_errno() = 12;
      *__doserrno() = 8;
      return 0;
    }
    v10 = GetFullPathNameA(drvstr, maxlen, v9, &pname);
    if ( v10 && v10 < maxlen )
      return v7;
LABEL_25:
    LastError = GetLastError();
    _dosmaperr(LastError);
    return 0;
  }
  if ( FullPathNameA < count )
    return v7;
  *_errno() = 34;
  *pnbuf = 0;
  return 0;
}
