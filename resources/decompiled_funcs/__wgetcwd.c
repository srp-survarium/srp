unsigned __int16 *__cdecl _wgetcwd(unsigned __int16 *pnbuf, int maxlen)
{
  unsigned __int16 *retval; // [esp+10h] [ebp-1Ch]

  _lock(7);
  retval = _wgetdcwd_nolock(0, pnbuf, maxlen);
  _unlock(7);
  return retval;
}
