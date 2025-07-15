DWORD __usercall _lseek_nolock@<eax>(int a1@<ebx>, int a2@<edi>, int fh, LONG pos, DWORD mthd)
{
  void *osfhandle; // eax
  DWORD v7; // edi
  DWORD LastError; // eax
  char *v9; // eax

  osfhandle = (void *)_get_osfhandle(a1, a2, fh);
  if ( osfhandle == (void *)-1 )
  {
    *_errno() = 9;
    return -1;
  }
  else
  {
    v7 = SetFilePointer(osfhandle, pos, 0, mthd);
    if ( v7 == -1 )
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
      v9 = &__pioinfo[fh >> 5]->osfile + 64 * (fh & 0x1F);
      *v9 &= ~2u;
      return v7;
    }
  }
}
