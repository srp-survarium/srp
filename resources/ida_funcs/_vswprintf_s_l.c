int __usercall _vswprintf_s_l@<eax>(
        unsigned int a1@<ebx>,
        unsigned int a2@<edi>,
        unsigned __int16 *string,
        unsigned int sizeInWords,
        const wchar_t *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax

  if ( !format )
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, 0);
    return -1;
  }
  if ( !string || !sizeInWords )
  {
    *_errno() = 22;
LABEL_10:
    _invalid_parameter(a1, (unsigned int)string, 0);
    return -1;
  }
  result = _vswprintf_helper((unsigned int)string, 0, _woutput_s_l, string, sizeInWords, format, plocinfo, ap);
  if ( result < 0 )
    *string = 0;
  if ( result == -2 )
  {
    *_errno() = 34;
    goto LABEL_10;
  }
  return result;
}
