BOOL __cdecl __lock_fhandle(int fh)
{
  char *v1; // esi
  BOOL retval; // [esp+10h] [ebp-1Ch]

  v1 = (char *)__pioinfo[fh >> 5] + 64 * (fh & 0x1F);
  retval = 1;
  if ( !*((_DWORD *)v1 + 2) )
  {
    _lock(10);
    if ( !*((_DWORD *)v1 + 2) )
    {
      retval = __crtInitCritSecAndSpinCount((_RTL_CRITICAL_SECTION *)(v1 + 12), 0xFA0u) != 0;
      ++*((_DWORD *)v1 + 2);
    }
    _unlock(10);
  }
  if ( retval )
    EnterCriticalSection((LPCRITICAL_SECTION)((char *)&__pioinfo[fh >> 5]->lock + 64 * (fh & 0x1F)));
  return retval;
}
