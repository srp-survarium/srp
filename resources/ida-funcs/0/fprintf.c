int __usercall fprintf@<eax>(int a1@<edi>, _iobuf *str, const char *format, ...)
{
  int v4; // eax
  ioinfo *v5; // ecx
  ioinfo *v6; // eax
  int v7; // edi
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+3Ch] [ebp+10h] BYREF

  va_start(argptr, format);
  retval = 0;
  if ( str && format )
  {
    _lock_file(str);
    if ( (str->_flag & 0x40) == 0 )
    {
      v4 = _fileno((int)str, a1, str);
      if ( v4 == -1 || v4 == -2 )
        v5 = &__badioinfo;
      else
        v5 = (ioinfo *)((char *)__pioinfo[v4 >> 5] + 64 * (v4 & 0x1F));
      if ( (*((_BYTE *)v5 + 36) & 0x7F) != 0
        || (v4 == -1 || v4 == -2
          ? (v6 = &__badioinfo)
          : (v6 = (ioinfo *)((char *)__pioinfo[v4 >> 5] + 64 * (v4 & 0x1F))),
            *((char *)v6 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter((int)str, a1, 0);
        retval = -1;
      }
    }
    if ( !retval )
    {
      v7 = _stbuf(str);
      retval = _output_l(str, format, 0, argptr);
      _ftbuf(v7, str);
    }
    _unlock_file(str);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter((int)str, a1, 0);
    return -1;
  }
}
