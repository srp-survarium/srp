int __usercall _ungetc_nolock@<eax>(unsigned int a1@<ebx>, int ch, _iobuf *str)
{
  int v3; // eax
  ioinfo *v4; // ecx
  ioinfo *v5; // eax
  int flag; // eax
  char *v8; // eax
  int v9; // eax

  if ( (str->_flag & 0x40) == 0 )
  {
    v3 = _fileno(str);
    if ( v3 == -1 || v3 == -2 )
      v4 = &__badioinfo;
    else
      v4 = (ioinfo *)((char *)__pioinfo[v3 >> 5] + 64 * (v3 & 0x1F));
    if ( (*((_BYTE *)v4 + 36) & 0x7F) != 0
      || (v3 == -1 || v3 == -2 ? (v5 = &__badioinfo) : (v5 = (ioinfo *)((char *)__pioinfo[v3 >> 5] + 64 * (v3 & 0x1F))),
          *((char *)v5 + 36) < 0) )
    {
      *_errno() = 22;
      _invalid_parameter(a1, 0, (unsigned int)str);
      return -1;
    }
  }
  if ( ch == -1 )
    return -1;
  flag = str->_flag;
  if ( (flag & 1) == 0 && ((flag & 0x80u) == 0 || (flag & 2) != 0) )
    return -1;
  if ( !str->_base )
    _getbuf(str);
  if ( str->_ptr == str->_base )
  {
    if ( str->_cnt )
      return -1;
    ++str->_ptr;
  }
  v8 = --str->_ptr;
  if ( (str->_flag & 0x40) != 0 )
  {
    if ( *v8 != (_BYTE)ch )
    {
      str->_ptr = v8 + 1;
      return -1;
    }
  }
  else
  {
    *v8 = ch;
  }
  v9 = str->_flag;
  ++str->_cnt;
  str->_flag = v9 & 0xFFFFFFEE | 1;
  return (unsigned __int8)ch;
}
