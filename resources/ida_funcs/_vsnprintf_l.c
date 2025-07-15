int __usercall _vsnprintf_l@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        char *string,
        unsigned int count,
        const char *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax
  int v8; // edi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  if ( format )
  {
    if ( !count || string )
    {
      str._cnt = 0x7FFFFFFF;
      if ( count <= 0x7FFFFFFF )
        str._cnt = count;
      str._flag = 66;
      str._base = string;
      str._ptr = string;
      result = _output_l(&str, format, plocinfo, ap);
      v8 = result;
      if ( string )
      {
        if ( --str._cnt < 0 )
          _flsbuf(0, (int)&str);
        else
          *str._ptr = 0;
        return v8;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(0, a1, 0);
      return -1;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, a2);
    return -1;
  }
  return result;
}
