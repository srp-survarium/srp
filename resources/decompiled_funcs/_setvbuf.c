int __cdecl setvbuf(_iobuf *str, char *buffer, int type, unsigned int size)
{
  unsigned int v5; // edi
  int v6; // edi
  int flag; // ecx
  int v8; // ecx
  char *p_charbuf; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  if ( !str )
    goto LABEL_2;
  if ( type != 4 )
  {
    if ( !type )
      goto LABEL_7;
    if ( type != 64 )
    {
LABEL_2:
      *_errno() = 22;
      _invalid_parameter(0, 0, 0, 0, 0);
      return -1;
    }
  }
  if ( type != 64 )
  {
    v5 = size;
    goto LABEL_10;
  }
LABEL_7:
  v5 = size;
  if ( size - 2 > 0x7FFFFFFD )
    goto LABEL_2;
LABEL_10:
  v6 = v5 & 0xFFFFFFFE;
  _lock_file(str);
  _flush(str);
  _freebuf(str);
  str->_flag &= 0xFFFFC2F3;
  flag = str->_flag;
  if ( (type & 4) != 0 )
  {
    v8 = flag | 4;
    p_charbuf = (char *)&str->_charbuf;
    v6 = 2;
LABEL_17:
    str->_flag = v8;
    goto LABEL_18;
  }
  p_charbuf = buffer;
  if ( buffer )
  {
    v8 = flag | 0x500;
    goto LABEL_17;
  }
  p_charbuf = (char *)_malloc_crt(v6);
  if ( p_charbuf )
  {
    str->_flag |= 0x408u;
LABEL_18:
    str->_bufsiz = v6;
    str->_base = p_charbuf;
    str->_ptr = p_charbuf;
    str->_cnt = 0;
    goto done;
  }
  ++_cflush;
  retval = -1;
done:
  _unlock_file(str);
  return retval;
}
