DWORD __cdecl _lseek_nolock(int fh, LONG pos, DWORD mthd)
{
  void *osfhandle; // eax
  DWORD v5; // edi
  DWORD LastError; // eax
  char *v7; // eax

  osfhandle = (void *)_get_osfhandle(fh);
  if ( osfhandle == (void *)-1 )
  {
    *_errno() = 9;
    return -1;
  }
  else
  {
    v5 = SetFilePointer(osfhandle, pos, 0, mthd);
    if ( v5 == -1 )
      LastError = GetLastError();
    else
      LastError = 0;
    if ( LastError )
    {
      _dosmaperr(LastError);
      return -1;
    }
    else
    {
      v7 = &__pioinfo[fh >> 5]->osfile + 64 * (fh & 0x1F);
      *v7 &= ~2u;
      return v5;
    }
  }
}
