int __usercall _lseeki64@<eax>(int a1@<ebx>, int fh, __int64 pos, DWORD mthd)
{
  stlp_std::ioinfo **v5; // ebx
  int v6; // esi
  int r; // [esp+10h] [ebp-24h]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1, 0, -1);
    return -1;
  }
  v5 = &__pioinfo[fh >> 5];
  v6 = (fh & 0x1F) << 6;
  if ( (*(&(*v5)->osfile + v6) & 1) != 0 )
  {
    __lock_fhandle(fh);
    if ( (*(&(*v5)->osfile + v6) & 1) != 0 )
    {
      r = _lseeki64_nolock((int)v5, 0, fh, pos, mthd);
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
  else
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter((int)v5, 0, v6);
    return -1;
  }
}
