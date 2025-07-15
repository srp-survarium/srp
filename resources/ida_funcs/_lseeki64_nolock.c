doubleint __cdecl _lseeki64_nolock(int fh, __int64 pos, DWORD mthd)
{
  void *osfhandle; // eax
  DWORD LastError; // eax
  char *v6; // eax
  doubleint newpos; // [esp+8h] [ebp-8h] BYREF

  newpos.bigint = pos;
  osfhandle = (void *)_get_osfhandle(fh);
  if ( osfhandle == (void *)-1 )
  {
    *_errno() = 9;
    return (doubleint)-1LL;
  }
  newpos.twoints.lowerhalf = SetFilePointer(osfhandle, newpos.twoints.lowerhalf, &newpos.twoints.upperhalf, mthd);
  if ( newpos.twoints.lowerhalf == -1 )
  {
    LastError = GetLastError();
    if ( LastError )
    {
      _dosmaperr(LastError);
      return (doubleint)-1LL;
    }
  }
  v6 = &__pioinfo[fh >> 5]->osfile + 64 * (fh & 0x1F);
  *v6 &= ~2u;
  return newpos;
}
