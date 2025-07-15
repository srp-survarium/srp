unsigned __int16 *__cdecl wfullpath_helper(
        unsigned __int16 *buf,
        const wchar_t *path,
        unsigned int sz,
        unsigned __int16 **pBuf)
{
  int v4; // esi
  unsigned __int16 *v5; // edi
  int *v6; // eax
  unsigned __int16 *result; // eax

  v4 = *_errno();
  *_errno() = 0;
  v5 = _wfullpath(buf, path, sz);
  v6 = _errno();
  if ( v5 )
  {
    *v6 = v4;
    return v5;
  }
  else if ( *v6 == 34 )
  {
    *_errno() = v4;
    result = _wfullpath(0, path, 0);
    *pBuf = result;
  }
  else
  {
    return 0;
  }
  return result;
}
