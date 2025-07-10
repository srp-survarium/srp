int __cdecl _stbuf(_iobuf *str)
{
  int v1; // eax
  int v2; // eax
  char **v3; // edi
  char *v4; // eax
  char *v5; // edi

  v1 = _fileno(str);
  if ( !_isatty(v1) )
    return 0;
  if ( str == &__iob_func()[1] )
  {
    v2 = 0;
  }
  else
  {
    if ( str != &__iob_func()[2] )
      return 0;
    v2 = 1;
  }
  ++_cflush;
  if ( (str->_flag & 0x10C) != 0 )
    return 0;
  v3 = (char **)&_stdbuf[v2];
  if ( *v3 || (v4 = (char *)_malloc_crt(0x1000u), (*v3 = v4) != 0) )
  {
    v5 = *v3;
    str->_base = v5;
    str->_ptr = v5;
    str->_bufsiz = 4096;
    str->_cnt = 4096;
  }
  else
  {
    str->_base = (char *)&str->_charbuf;
    str->_ptr = (char *)&str->_charbuf;
    str->_bufsiz = 2;
    str->_cnt = 2;
  }
  str->_flag |= 0x1102u;
  return 1;
}
