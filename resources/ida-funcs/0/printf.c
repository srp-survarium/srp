int __usercall printf@<eax>(int a1@<ebx>, int a2@<edi>, const char *format, ...)
{
  _iobuf *v4; // eax
  _iobuf *v5; // eax
  int v6; // edi
  _iobuf *v7; // eax
  _iobuf *v8; // eax
  _iobuf *v9; // eax
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+38h] [ebp+Ch] BYREF

  va_start(argptr, format);
  if ( format )
  {
    v4 = __iob_func();
    _lock_file2(1, (char *)&v4[1]);
    v5 = __iob_func();
    v6 = _stbuf(v5 + 1);
    v7 = __iob_func();
    retval = _output_l(v7 + 1, format, 0, argptr);
    v8 = __iob_func();
    _ftbuf(v6, v8 + 1);
    v9 = __iob_func();
    _unlock_file2(1, (char *)&v9[1]);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, 0);
    return -1;
  }
}
