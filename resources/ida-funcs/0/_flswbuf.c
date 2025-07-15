int __usercall _flswbuf@<eax>(int a1@<ebx>, int a2@<edi>, stlp_std::ioinfo **ch, _iobuf *str)
{
  int flag; // eax
  int v7; // eax
  unsigned int v8; // eax
  char *base; // eax
  char *ptr; // edi
  signed int v11; // edi
  ioinfo *v12; // eax
  int v13; // eax
  int v14; // edx
  unsigned __int16 v15; // bx
  int buf; // [esp+4h] [ebp-4h] BYREF
  int stra; // [esp+14h] [ebp+Ch]

  stra = _fileno(a1, a2, str);
  flag = str->_flag;
  if ( (flag & 0x82) == 0 )
  {
    *_errno() = 9;
LABEL_3:
    str->_flag |= 0x20u;
    return 0xFFFF;
  }
  if ( (flag & 0x40) != 0 )
  {
    *_errno() = 34;
    goto LABEL_3;
  }
  if ( (flag & 1) != 0 )
  {
    str->_cnt = 0;
    if ( (flag & 0x10) == 0 )
    {
      str->_flag = flag | 0x20;
      return 0xFFFF;
    }
    str->_ptr = str->_base;
    str->_flag = flag & 0xFFFFFFFE;
  }
  v7 = str->_flag;
  str->_cnt = 0;
  buf = 0;
  v8 = v7 & 0xFFFFFFED | 2;
  str->_flag = v8;
  if ( (v8 & 0x10C) == 0 && (str != &__iob_func()[1] && str != &__iob_func()[2] || !_isatty(2, a2, stra)) )
    _getbuf(str);
  if ( (str->_flag & 0x108) != 0 )
  {
    base = str->_base;
    ptr = str->_ptr;
    str->_ptr = base + 2;
    v11 = ptr - base;
    str->_cnt = str->_bufsiz - 2;
    if ( v11 <= 0 )
    {
      if ( stra == -1 || stra == -2 )
        v12 = &__badioinfo;
      else
        v12 = (ioinfo *)((char *)__pioinfo[stra >> 5] + 64 * (stra & 0x1F));
      if ( (v12->osfile & 0x20) != 0 )
      {
        v13 = _lseeki64(2, stra, 0, 2u);
        if ( (v14 & v13) == 0xFFFFFFFF )
          goto LABEL_28;
      }
    }
    else
    {
      buf = _write((stlp_std::ioinfo **)2, (int)str, stra, base, v11);
    }
    v15 = (unsigned __int16)ch;
    *(_WORD *)str->_base = (_WORD)ch;
  }
  else
  {
    v11 = 2;
    v15 = (unsigned __int16)ch;
    LOWORD(buf) = (_WORD)ch;
    buf = _write(ch, (int)str, stra, (char *)&buf, 2u);
  }
  if ( buf != v11 )
  {
LABEL_28:
    str->_flag |= 0x20u;
    return 0xFFFF;
  }
  return v15;
}
