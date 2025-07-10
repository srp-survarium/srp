int fprintf(_iobuf *str, const char *format, ...)
{
  int v3; // eax
  ioinfo *v4; // ecx
  ioinfo *v5; // eax
  int v6; // edi
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+3Ch] [ebp+10h] BYREF

  va_start(argptr, format);
  retval = 0;
  if ( str && format )
  {
    _lock_file(str);
    if ( (str->_flag & 0x40) == 0 )
    {
      v3 = _fileno(str);
      if ( v3 == -1 || v3 == -2 )
        v4 = &__badioinfo;
      else
        v4 = (ioinfo *)((char *)__pioinfo[v3 >> 5] + 64 * (v3 & 0x1F));
      if ( (*((_BYTE *)v4 + 36) & 0x7F) != 0
        || (v3 == -1 || v3 == -2
          ? (v5 = &__badioinfo)
          : (v5 = (ioinfo *)((char *)__pioinfo[v3 >> 5] + 64 * (v3 & 0x1F))),
            *((char *)v5 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter(0, 0, 0, 0, 0);
        retval = -1;
      }
    }
    if ( !retval )
    {
      v6 = _stbuf(str);
      retval = _output_l(str, format, 0, argptr);
      _ftbuf(v6, str);
    }
    _unlock_file(str);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return -1;
  }
}
