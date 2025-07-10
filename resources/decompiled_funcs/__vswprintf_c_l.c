int __usercall _vswprintf_c_l@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        unsigned __int16 *string,
        unsigned int count,
        const wchar_t *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax

  result = _vswprintf_helper(a1, a2, _woutput_l, string, count, format, plocinfo, ap);
  if ( result < 0 )
    return -1;
  return result;
}
