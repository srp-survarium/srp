int __cdecl _get_osfhandle(int fh)
{
  char *v2; // eax

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  else if ( fh >= 0 && fh < _nhandle && (v2 = (char *)__pioinfo[fh >> 5] + 64 * (fh & 0x1F), (v2[4] & 1) != 0) )
  {
    return *(_DWORD *)v2;
  }
  else
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(0, 0, 0, 0, 0);
    return -1;
  }
}
