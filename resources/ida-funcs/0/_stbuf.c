int __usercall _stbuf@<eax>(int a1@<ebx>, int a2@<edi>, _iobuf *str)
{
  int v3; // eax
  int v4; // eax
  char **v5; // edi
  char *v6; // eax
  char *v7; // edi

  v3 = _fileno(a1, a2, str);
  if ( !_isatty(a1, a2, v3) )
    return 0;
  if ( str == &__iob_func()[1] )
  {
    v4 = 0;
  }
  else
  {
    if ( str != &__iob_func()[2] )
      return 0;
    v4 = 1;
  }
  ++_cflush;
  if ( (str->_flag & 0x10C) != 0 )
    return 0;
  v5 = (char **)&_stdbuf[v4];
  if ( *v5 || (v6 = (char *)_malloc_crt(0x1000u), (*v5 = v6) != 0) )
  {
    v7 = *v5;
    str->_base = v7;
    str->_ptr = v7;
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
