char *__cdecl fullpath_helper(char *buf, char *path, DWORD sz, char **pBuf)
{
  int v4; // esi
  LPSTR v5; // edi
  int *v6; // eax
  char *result; // eax

  v4 = *_errno();
  *_errno() = 0;
  v5 = _fullpath(buf, path, sz);
  v6 = _errno();
  if ( v5 )
  {
    *v6 = v4;
    return v5;
  }
  else if ( *v6 == 34 )
  {
    *_errno() = v4;
    result = _fullpath(0, path, 0);
    *pBuf = result;
  }
  else
  {
    return 0;
  }
  return result;
}
