int __cdecl _findclose(void *hFile)
{
  if ( FindClose(hFile) )
    return 0;
  *_errno() = 22;
  return -1;
}
