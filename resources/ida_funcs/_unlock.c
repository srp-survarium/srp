void __cdecl _unlock(int locknum)
{
  LeaveCriticalSection(*(&locktable + 2 * locknum));
}
