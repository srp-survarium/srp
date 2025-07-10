int __usercall getc@<eax>(unsigned int a1@<ebx>, _iobuf *stream)
{
  int v3; // eax
  ioinfo *v4; // ecx
  ioinfo *v5; // eax
  int v7; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  if ( stream )
  {
    _lock_file(stream);
    if ( (stream->_flag & 0x40) == 0 )
    {
      v3 = _fileno(stream);
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
        _invalid_parameter(a1, 0, (unsigned int)stream);
        retval = -1;
      }
    }
    if ( !retval )
    {
      if ( --stream->_cnt < 0 )
        v7 = _filbuf(stream);
      else
        v7 = *(unsigned __int8 *)stream->_ptr++;
      retval = v7;
    }
    _unlock_file(stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, 0, 0);
    return -1;
  }
}
