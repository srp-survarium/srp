int __usercall puts@<eax>(int a1@<edi>, char *string)
{
  _iobuf *v3; // eax
  int v4; // eax
  ioinfo *v5; // ecx
  ioinfo *v6; // eax
  _iobuf *v7; // eax
  _iobuf *v8; // eax
  int v9; // edi
  unsigned int v10; // eax
  unsigned int v11; // esi
  _iobuf *v12; // eax
  int *p_cnt; // eax
  _iobuf *v15; // eax
  _iobuf *v16; // eax
  _iobuf *v17; // eax
  _iobuf *v18; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  retval = -1;
  if ( string
    && ((v3 = __iob_func() + 1, (v3->_flag & 0x40) != 0)
     || ((v4 = _fileno(0, a1, v3), v4 == -1) || v4 == -2
       ? (v5 = &__badioinfo)
       : (v5 = (ioinfo *)((char *)__pioinfo[v4 >> 5] + 64 * (v4 & 0x1F))),
         (*((_BYTE *)v5 + 36) & 0x7F) == 0
      && (v4 == -1 || v4 == -2 ? (v6 = &__badioinfo) : (v6 = (ioinfo *)((char *)__pioinfo[v4 >> 5] + 64 * (v4 & 0x1F))),
          *((char *)v6 + 36) >= 0))) )
  {
    v7 = __iob_func();
    _lock_file2(1, (char *)&v7[1]);
    v8 = __iob_func();
    v9 = _stbuf(v8 + 1);
    strlen((unsigned __int8 *)string);
    v11 = v10;
    v12 = __iob_func();
    if ( _fwrite_nolock(0, (unsigned __int8 *)string, 1u, v11, v12 + 1) == v11 )
    {
      p_cnt = &__iob_func()[1]._cnt;
      if ( --*p_cnt < 0 )
      {
        v16 = __iob_func();
        _flsbuf(0xAu, v16 + 1);
      }
      else
      {
        v15 = __iob_func() + 1;
        *v15->_ptr++ = 10;
      }
      retval = 0;
    }
    v17 = __iob_func();
    _ftbuf(v9, v17 + 1);
    v18 = __iob_func();
    _unlock_file2(1, (char *)&v18[1]);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, -1);
    return -1;
  }
}
