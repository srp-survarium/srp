int __usercall _write@<eax>(stlp_std::ioinfo **a1@<ebx>, int a2@<esi>, int fh, char *buf, unsigned int cnt)
{
  int r; // [esp+14h] [ebp-1Ch]

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
    _invalid_parameter((int)a1, 0, a2);
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*a1)->osfile + a2) & 1) != 0 )
  {
    r = _write_nolock((char)a1, 0, fh, buf, cnt);
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
