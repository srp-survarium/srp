int __cdecl _mkdir(const char *path)
{
  DWORD LastError; // eax

  if ( CreateDirectoryA(path, 0) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( !LastError )
    return 0;
  _dosmaperr(LastError);
  return -1;
}
