int __usercall _ungetc_nolock@<eax>(int a1@<ebx>, int a2@<edi>, int ch, _iobuf *str)
{
  int v4; // eax
  ioinfo *v5; // ecx
  ioinfo *v6; // eax
  int flag; // eax
  char *v9; // eax
  int v10; // eax

  if ( (str->_flag & 0x40) == 0 )
  {
    v4 = _fileno(a1, a2, str);
    if ( v4 == -1 || v4 == -2 )
      v5 = &__badioinfo;
    else
      v5 = (ioinfo *)((char *)__pioinfo[v4 >> 5] + 64 * (v4 & 0x1F));
    if ( (*((_BYTE *)v5 + 36) & 0x7F) != 0
      || (v4 == -1 || v4 == -2 ? (v6 = &__badioinfo) : (v6 = (ioinfo *)((char *)__pioinfo[v4 >> 5] + 64 * (v4 & 0x1F))),
          *((char *)v6 + 36) < 0) )
    {
      *_errno() = 22;
      _invalid_parameter(a1, 0, (int)str);
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
  v9 = --str->_ptr;
  if ( (str->_flag & 0x40) != 0 )
  {
    if ( *v9 != (_BYTE)ch )
    {
      str->_ptr = v9 + 1;
      return -1;
    }
  }
  else
  {
    *v9 = ch;
  }
  v10 = str->_flag;
  ++str->_cnt;
  str->_flag = v10 & 0xFFFFFFEE | 1;
  return (unsigned __int8)ch;
}
