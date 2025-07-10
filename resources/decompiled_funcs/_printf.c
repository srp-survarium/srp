int printf(const char *format, ...)
{
  _iobuf *v2; // eax
  _iobuf *v3; // eax
  int v4; // edi
  _iobuf *v5; // eax
  _iobuf *v6; // eax
  _iobuf *v7; // eax
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+38h] [ebp+Ch] BYREF

  va_start(argptr, format);
  if ( format )
  {
    v2 = __iob_func();
    _lock_file2(1, &v2[1]);
    v3 = __iob_func();
    v4 = _stbuf(v3 + 1);
    v5 = __iob_func();
    retval = _output_l(v5 + 1, format, 0, argptr);
    v6 = __iob_func();
    _ftbuf(v4, v6 + 1);
    v7 = __iob_func();
    _unlock_file2(1, &v7[1]);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return -1;
  }
}
