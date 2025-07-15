int __usercall _isatty@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, int fh)
{
  if ( fh == -2 )
  {
    *_errno() = 9;
    return 0;
  }
  else if ( fh >= 0 && fh < _nhandle )
  {
    return *(&__pioinfo[fh >> 5]->osfile + 64 * (fh & 0x1F)) & 0x40;
  }
  else
  {
    *_errno() = 9;
    _invalid_parameter(a1, a2, 0);
    return 0;
  }
}
