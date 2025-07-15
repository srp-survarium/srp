int __usercall _close_nolock@<eax>(int a1@<ebx>, int osfhandle@<edi>, int fh)
{
  void *v3; // eax
  DWORD LastError; // edi

  if ( _get_osfhandle(a1, osfhandle, fh) == -1
    || (fh == 1 && ((int)__pioinfo[0][3].lock.OwningThread & 1) != 0
     || fh == 2 && (__pioinfo[0][1].lock.SpinCount & 1) != 0)
    && (osfhandle = _get_osfhandle(a1, osfhandle, 2), _get_osfhandle(a1, osfhandle, 1) == osfhandle)
    || (v3 = (void *)_get_osfhandle(a1, osfhandle, fh), CloseHandle(v3)) )
  {
    LastError = 0;
  }
  else
  {
    LastError = GetLastError();
  }
  _free_osfhnd(fh);
  *(&__pioinfo[fh >> 5]->osfile + 64 * (fh & 0x1F)) = 0;
  if ( !LastError )
    return 0;
  _dosmaperr(LastError);
  return -1;
}
