void __cdecl _lock(int locknum)
{
  LPCRITICAL_SECTION *v1; // esi

  v1 = &locktable + 2 * locknum;
  if ( !*v1 && !_mtinitlocknum(locknum) )
    _amsg_exit(17);
  EnterCriticalSection(*v1);
}
