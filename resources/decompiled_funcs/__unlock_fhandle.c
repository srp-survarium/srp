void __cdecl _unlock_fhandle(int fh)
{
  LeaveCriticalSection((LPCRITICAL_SECTION)((char *)&__pioinfo[fh >> 5]->lock + 64 * (fh & 0x1F)));
}
