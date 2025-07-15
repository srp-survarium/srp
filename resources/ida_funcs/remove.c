int __cdecl remove(const char *path)
{
  DWORD LastError; // eax

  if ( DeleteFileA(path) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( !LastError )
    return 0;
  _dosmaperr(LastError);
  return -1;
}
