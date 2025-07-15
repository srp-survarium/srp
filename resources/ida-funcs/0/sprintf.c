int __usercall sprintf@<eax>(int a1@<edi>, int a2@<esi>, char *string, char *format, ...)
{
  int v5; // eax
  bool v6; // sf
  int v7; // esi
  _iobuf stream; // [esp+4h] [ebp-20h] BYREF
  va_list argptr; // [esp+34h] [ebp+10h] BYREF

  va_start(argptr, format);
  if ( format && string )
  {
    stream._base = string;
    stream._ptr = string;
    stream._cnt = 0x7FFFFFFF;
    stream._flag = 66;
    v5 = _output_l(&stream, format, 0, argptr);
    v6 = --stream._cnt < 0;
    v7 = v5;
    if ( v6 )
      _flsbuf(0, &stream);
    else
      *stream._ptr = 0;
    return v7;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, a2);
    return -1;
  }
}
