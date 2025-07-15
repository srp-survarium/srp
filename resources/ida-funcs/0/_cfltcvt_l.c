int __usercall _cfltcvt_l@<eax>(
        int a1@<ebx>,
        _CRT_DOUBLE *arg,
        char *buffer,
        unsigned int sizeInBytes,
        int format,
        int precision,
        int caps,
        localeinfo_struct *plocinfo)
{
  switch ( format )
  {
    case 'e':
    case 'E':
      return _cftoe_l(arg, buffer, sizeInBytes, precision, caps, plocinfo);
    case 'f':
      return _cftof_l(arg, buffer, sizeInBytes, precision, plocinfo);
    case 'a':
    case 'A':
      return _cftoa_l(a1, arg, buffer, sizeInBytes, precision, caps, plocinfo);
  }
  return _cftog_l(arg, buffer, sizeInBytes, precision, caps, plocinfo);
}
