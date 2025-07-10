void __cdecl _unlock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    LeaveCriticalSection((LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    *((_DWORD *)s + 3) &= ~0x8000u;
    _unlock(i + 16);
  }
}
