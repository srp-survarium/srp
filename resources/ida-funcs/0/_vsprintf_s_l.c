int __usercall _vsprintf_s_l@<eax>(
        int a1@<edi>,
        int a2@<esi>,
        char *string,
        unsigned int sizeInBytes,
        char *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax

  if ( !format )
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, a2);
    return -1;
  }
  if ( !string || !sizeInBytes )
  {
    *_errno() = 22;
LABEL_10:
    _invalid_parameter(0, a1, (int)string);
    return -1;
  }
  result = _vsnprintf_helper(a1, (int)string, _output_s_l, string, sizeInBytes, format, plocinfo, ap);
  if ( result < 0 )
    *string = 0;
  if ( result == -2 )
  {
    *_errno() = 34;
    goto LABEL_10;
  }
  return result;
}
