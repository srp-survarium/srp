int __usercall _close@<eax>(stlp_std::ioinfo **a1@<ebx>, int a2@<esi>, int fh)
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
    r = _close_nolock((int)a1, 0, fh);
  }
  else
  {
    *_errno() = 9;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}
