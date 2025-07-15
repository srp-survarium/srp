char *__usercall fgets@<eax>(int a1@<edi>, _iobuf *a2@<esi>, char *string, int count, _iobuf *str)
{
  int v6; // eax
  ioinfo *v7; // ecx
  ioinfo *v8; // eax
  char *v9; // edi
  int v11; // eax
  char *retval; // [esp+1Ch] [ebp-1Ch]

  retval = string;
  if ( !string && count || count < 0 || (a2 = str) == 0 )
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, (int)a2);
    return 0;
  }
  if ( !count )
    return 0;
  _lock_file(str);
  if ( (str->_flag & 0x40) == 0 )
  {
    v6 = _fileno(0, a1, str);
    if ( v6 == -1 || v6 == -2 )
      v7 = &__badioinfo;
    else
      v7 = (ioinfo *)((char *)__pioinfo[v6 >> 5] + 64 * (v6 & 0x1F));
    if ( (*((_BYTE *)v7 + 36) & 0x7F) != 0
      || (v6 == -1 || v6 == -2 ? (v8 = &__badioinfo) : (v8 = (ioinfo *)((char *)__pioinfo[v6 >> 5] + 64 * (v6 & 0x1F))),
          *((char *)v8 + 36) < 0) )
    {
      *_errno() = 22;
      _invalid_parameter(0, a1, (int)str);
      retval = 0;
    }
  }
  if ( retval )
  {
    v9 = string;
    do
    {
      if ( !--count )
        break;
      if ( --str->_cnt < 0 )
        v11 = _filbuf(0, str);
      else
        v11 = *(unsigned __int8 *)str->_ptr++;
      if ( v11 == -1 )
      {
        if ( v9 == string )
        {
          retval = 0;
          goto done_5;
        }
        break;
      }
      *v9++ = v11;
    }
    while ( (_BYTE)v11 != 10 );
    *v9 = 0;
  }
done_5:
  _unlock_file(str);
  return retval;
}
