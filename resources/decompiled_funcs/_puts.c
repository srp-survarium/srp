int __cdecl puts(char *string)
{
  _iobuf *v2; // eax
  int v3; // eax
  ioinfo *v4; // ecx
  ioinfo *v5; // eax
  _iobuf *v6; // eax
  _iobuf *v7; // eax
  int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // esi
  _iobuf *v11; // eax
  int *p_cnt; // eax
  _iobuf *v14; // eax
  _iobuf *v15; // eax
  _iobuf *v16; // eax
  _iobuf *v17; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  retval = -1;
  if ( string
    && ((v2 = __iob_func() + 1, (v2->_flag & 0x40) != 0)
     || ((v3 = _fileno(v2), v3 == -1) || v3 == -2
       ? (v4 = &__badioinfo)
       : (v4 = (ioinfo *)((char *)__pioinfo[v3 >> 5] + 64 * (v3 & 0x1F))),
         (*((_BYTE *)v4 + 36) & 0x7F) == 0
      && (v3 == -1 || v3 == -2 ? (v5 = &__badioinfo) : (v5 = (ioinfo *)((char *)__pioinfo[v3 >> 5] + 64 * (v3 & 0x1F))),
          *((char *)v5 + 36) >= 0))) )
  {
    v6 = __iob_func();
    _lock_file2(1, &v6[1]);
    v7 = __iob_func();
    v8 = _stbuf(v7 + 1);
    strlen((unsigned __int8 *)string);
    v10 = v9;
    v11 = __iob_func();
    if ( _fwrite_nolock(string, 1u, v10, v11 + 1) == v10 )
    {
      p_cnt = &__iob_func()[1]._cnt;
      if ( --*p_cnt < 0 )
      {
        v15 = __iob_func();
        _flsbuf(10, v15 + 1);
      }
      else
      {
        v14 = __iob_func() + 1;
        *v14->_ptr++ = 10;
      }
      retval = 0;
    }
    v16 = __iob_func();
    _ftbuf(v8, v16 + 1);
    v17 = __iob_func();
    _unlock_file2(1, &v17[1]);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return -1;
  }
}
