int __cdecl _vsnprintf_helper(
        int (__cdecl *outfn)(_iobuf *, const char *, localeinfo_struct *, char *),
        char *string,
        unsigned int count,
        const char *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax
  bool v7; // sf
  _iobuf str; // [esp+4h] [ebp-20h] BYREF
  int retval; // [esp+38h] [ebp+14h]

  if ( !format )
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return -1;
  }
  if ( count && !string )
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return -1;
  }
  str._cnt = 0x7FFFFFFF;
  if ( count <= 0x7FFFFFFF )
    str._cnt = count;
  str._flag = 66;
  str._base = string;
  str._ptr = string;
  result = outfn(&str, format, plocinfo, ap);
  retval = result;
  if ( string )
  {
    if ( result >= 0 )
    {
      if ( --str._cnt >= 0 )
      {
        *str._ptr = 0;
        return retval;
      }
      if ( _flsbuf(0, &str) != -1 )
        return retval;
    }
    v7 = str._cnt < 0;
    string[count - 1] = 0;
    return !v7 - 2;
  }
  return result;
}
