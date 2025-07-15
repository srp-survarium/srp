int __usercall _wfopen_s@<eax>(unsigned int a1@<ebx>, _iobuf **pfile, _iobuf *file, const wchar_t *mode)
{
  _iobuf *v5; // eax

  if ( pfile )
  {
    v5 = _wfsopen((const wchar_t *)pfile, file, mode, 128);
    *pfile = v5;
    if ( v5 )
      return 0;
    else
      return *_errno();
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, 0x16u, 0);
    return 22;
  }
}
