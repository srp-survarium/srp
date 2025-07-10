int __cdecl _rmdir(const char *path)
{
  DWORD LastError; // eax

  if ( RemoveDirectoryA(path) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( !LastError )
    return 0;
  _dosmaperr(LastError);
  return -1;
}
