int __usercall _vsnprintf_l@<eax>(
        int a1@<edi>,
        int a2@<esi>,
        char *string,
        unsigned int count,
        char *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax
  int v8; // edi
  _iobuf stream; // [esp+4h] [ebp-20h] BYREF

  if ( format )
  {
    if ( !count || string )
    {
      stream._cnt = 0x7FFFFFFF;
      if ( count <= 0x7FFFFFFF )
        stream._cnt = count;
      stream._flag = 66;
      stream._base = string;
      stream._ptr = string;
      result = _output_l(&stream, format, plocinfo, ap);
      v8 = result;
      if ( string )
      {
        if ( --stream._cnt < 0 )
          _flsbuf(0, result, 0, &stream);
        else
          *stream._ptr = 0;
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
