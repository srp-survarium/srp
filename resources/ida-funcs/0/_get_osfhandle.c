int __usercall _get_osfhandle@<eax>(int a1@<ebx>, int a2@<edi>, int fh)
{
  char *v4; // eax

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  else if ( fh >= 0 && fh < _nhandle && (v4 = (char *)__pioinfo[fh >> 5] + 64 * (fh & 0x1F), (v4[4] & 1) != 0) )
  {
    return *(_DWORD *)v4;
  }
  else
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1, a2, 0);
    return -1;
  }
}
