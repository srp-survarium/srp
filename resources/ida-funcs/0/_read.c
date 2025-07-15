unsigned int __usercall _read@<eax>(stlp_std::ioinfo **a1@<ebx>, int a2@<edi>, int fh, char *buf, unsigned int cnt)
{
  unsigned int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (a1 = &__pioinfo[fh >> 5], a2 = (fh & 0x1F) << 6, (*(&(*a1)->osfile + a2) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
LABEL_7:
    _invalid_parameter((int)a1, a2, 0);
    return -1;
  }
  if ( cnt > 0x7FFFFFFF )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    goto LABEL_7;
  }
  __lock_fhandle(fh);
  if ( (*(&(*a1)->osfile + a2) & 1) != 0 )
  {
    r = _read_nolock(a2, fh, buf, cnt);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}
