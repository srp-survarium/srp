int __usercall _vsnprintf_helper@<eax>(
        int a1@<edi>,
        int a2@<esi>,
        int (__cdecl *outfn)(_iobuf *, const char *, localeinfo_struct *, char *),
        char *string,
        unsigned int count,
        const char *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax
  bool v9; // sf
  _iobuf str; // [esp+4h] [ebp-20h] BYREF
  int v11; // [esp+38h] [ebp+14h]

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
  str._cnt = 0x7FFFFFFF;
  if ( count <= 0x7FFFFFFF )
    str._cnt = count;
  str._flag = 66;
  str._base = string;
  str._ptr = string;
  result = outfn(&str, format, plocinfo, ap);
  v11 = result;
  if ( string )
  {
    if ( result >= 0 )
    {
      if ( --str._cnt >= 0 )
      {
        *str._ptr = 0;
        return v11;
      }
      if ( _flsbuf(0, &str) != -1 )
        return v11;
    }
    v9 = str._cnt < 0;
    string[count - 1] = 0;
    return !v9 - 2;
  }
  return result;
}
