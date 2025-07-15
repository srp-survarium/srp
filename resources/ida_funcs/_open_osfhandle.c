int __cdecl _open_osfhandle(void *osfhandle, __int16 flags)
{
  char v2; // bl
  DWORD FileType; // eax
  DWORD LastError; // eax
  int v6; // eax
  int v7; // esi
  stlp_std::ioinfo **v8; // ecx
  int v9; // eax

  v2 = 0;
  if ( (flags & 8) != 0 )
    v2 = 32;
  if ( (flags & 0x4000) != 0 )
    v2 |= 0x80u;
  if ( (flags & 0x80u) != 0 )
    v2 |= 0x10u;
  FileType = GetFileType(osfhandle);
  switch ( FileType )
  {
    case 0u:
      LastError = GetLastError();
      _dosmaperr(LastError);
      return -1;
    case 2u:
      v2 |= 0x40u;
      break;
    case 3u:
      v2 |= 8u;
      break;
  }
  v6 = _alloc_osfhnd();
  v7 = v6;
  if ( v6 == -1 )
  {
    *_errno() = 24;
    *__doserrno() = 0;
    return -1;
  }
  _set_osfhnd(v6, osfhandle);
  v8 = &__pioinfo[v7 >> 5];
  v9 = (v7 & 0x1F) << 6;
  *(&(*v8)->osfile + v9) = v2 | 1;
  *((_BYTE *)&(*v8)[1].osfhnd + v9) &= 0x80u;
  *((_BYTE *)&(*v8)[1].osfhnd + v9) &= ~0x80u;
  _unlock_fhandle(v7);
  return v7;
}
