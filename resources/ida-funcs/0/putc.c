int __usercall putc@<eax>(int a1@<ebx>, unsigned __int8 ch, _iobuf *str)
{
  int v4; // eax
  ioinfo *v5; // ecx
  ioinfo *v6; // eax
  int v8; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  if ( str )
  {
    _lock_file(str);
    if ( (str->_flag & 0x40) == 0 )
    {
      v4 = _fileno(a1, 0, str);
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
        _invalid_parameter(a1, 0, (int)str);
        retval = -1;
      }
    }
    if ( !retval )
    {
      if ( --str->_cnt < 0 )
      {
        v8 = _flsbuf(ch, str);
      }
      else
      {
        *str->_ptr = ch;
        v8 = ch;
        ++str->_ptr;
      }
      retval = v8;
    }
    _unlock_file(str);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, 0, 0);
    return -1;
  }
}
