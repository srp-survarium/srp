int sprintf(char *string, const char *format, ...)
{
  int v3; // eax
  bool v4; // sf
  int v5; // esi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF
  va_list argptr; // [esp+34h] [ebp+10h] BYREF

  va_start(argptr, format);
  if ( format && string )
  {
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    str._flag = 66;
    v3 = _output_l(&str, format, 0, argptr);
    v4 = --str._cnt < 0;
    v5 = v3;
    if ( v4 )
      _flsbuf(0, &str);
    else
      *str._ptr = 0;
    return v5;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return -1;
  }
}
