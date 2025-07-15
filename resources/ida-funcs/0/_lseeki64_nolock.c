__int64 __usercall _lseeki64_nolock@<edx:eax>(int a1@<ebx>, int a2@<edi>, int fh, __int64 pos, DWORD mthd)
{
  void *osfhandle; // eax
  DWORD LastError; // eax
  char *v8; // eax
  __int64 lDistanceToMove; // [esp+8h] [ebp-8h] BYREF

  HIDWORD(lDistanceToMove) = HIDWORD(pos);
  osfhandle = (void *)_get_osfhandle(a1, a2, fh);
  if ( osfhandle == (void *)-1 )
  {
    *_errno() = 9;
    return -1;
  }
  LODWORD(lDistanceToMove) = SetFilePointer(osfhandle, pos, (PLONG)&lDistanceToMove + 1, mthd);
  if ( (_DWORD)lDistanceToMove == -1 )
  {
    LastError = GetLastError();
    if ( LastError )
    {
      _dosmaperr(LastError);
      return -1;
    }
  }
  v8 = &__pioinfo[fh >> 5]->osfile + 64 * (fh & 0x1F);
  *v8 &= ~2u;
  return lDistanceToMove;
}
