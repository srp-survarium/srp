int __cdecl _close_nolock(int fh)
{
  int osfhandle; // edi
  void *v2; // eax
  DWORD LastError; // edi

  if ( _get_osfhandle(fh) == -1
    || (fh == 1 && ((int)__pioinfo[0][3].lock.OwningThread & 1) != 0
     || fh == 2 && (__pioinfo[0][1].lock.SpinCount & 1) != 0)
    && (osfhandle = _get_osfhandle(2), _get_osfhandle(1) == osfhandle)
    || (v2 = (void *)_get_osfhandle(fh), CloseHandle(v2)) )
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
