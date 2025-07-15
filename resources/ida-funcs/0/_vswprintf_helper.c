int __usercall _vswprintf_helper@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        int (__cdecl *woutfn)(_iobuf *, const wchar_t *, localeinfo_struct *, char *),
        unsigned __int16 *string,
        unsigned int count,
        const wchar_t *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax
  bool v9; // sf
  _iobuf str; // [esp+4h] [ebp-20h] BYREF
  int retval; // [esp+38h] [ebp+14h]

  if ( !format )
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, a2);
    return -1;
  }
  if ( count && !string )
  {
    *_errno() = 22;
    _invalid_parameter(0, count, 0);
    return -1;
  }
  str._flag = 66;
  str._base = (char *)string;
  str._ptr = (char *)string;
  if ( count <= 0x3FFFFFFF )
    str._cnt = 2 * count;
  else
    str._cnt = 0x7FFFFFFF;
  result = woutfn(&str, format, plocinfo, ap);
  retval = result;
  if ( string )
  {
    if ( result >= 0 )
    {
      if ( --str._cnt >= 0 )
      {
        *str._ptr++ = 0;
LABEL_14:
        if ( --str._cnt >= 0 )
        {
          *str._ptr = 0;
          return retval;
        }
        if ( _flsbuf(0, &str) != -1 )
          return retval;
        goto LABEL_18;
      }
      if ( _flsbuf(0, &str) != -1 )
        goto LABEL_14;
    }
LABEL_18:
    v9 = str._cnt < 0;
    string[count - 1] = 0;
    return !v9 - 2;
  }
  return result;
}
