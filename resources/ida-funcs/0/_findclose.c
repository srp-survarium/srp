int __cdecl _findclose(HANDLE hFile)
{
  if ( FindClose(hFile) )
    return 0;
  *_errno() = 22;
  return -1;
}
