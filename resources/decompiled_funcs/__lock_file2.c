void __cdecl _lock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    EnterCriticalSection((LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    _lock(i + 16);
    *((_DWORD *)s + 3) |= 0x8000u;
  }
}
