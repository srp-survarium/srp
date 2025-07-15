int __usercall _flsbuf@<eax>(int a1@<ebx>, int a2@<edi>, unsigned __int8 ch, _iobuf *str)
{
  _iobuf *v4; // esi
  int flag; // eax
  unsigned int v7; // eax
  char *base; // eax
  char *ptr; // edi
  signed int v10; // edi
  ioinfo *v11; // eax
  __int64 v12; // rax
  int v13; // [esp+4h] [ebp-4h]

  v4 = str;
  str = (_iobuf *)_fileno(a1, a2, str);
  flag = v4->_flag;
  if ( (flag & 0x82) == 0 )
  {
    *_errno() = 9;
LABEL_3:
    v4->_flag |= 0x20u;
    return -1;
  }
  if ( (flag & 0x40) != 0 )
  {
    *_errno() = 34;
    goto LABEL_3;
  }
  if ( (flag & 1) != 0 )
  {
    v4->_cnt = 0;
    if ( (flag & 0x10) == 0 )
    {
      v4->_flag = flag | 0x20;
      return -1;
    }
    v4->_ptr = v4->_base;
    v4->_flag = flag & 0xFFFFFFFE;
  }
  v7 = v4->_flag & 0xFFFFFFED | 2;
  v4->_flag = v7;
  v4->_cnt = 0;
  v13 = 0;
  if ( (v7 & 0x10C) == 0 && (v4 != &__iob_func()[1] && v4 != &__iob_func()[2] || !_isatty(0, a2, (int)str)) )
    _getbuf(v4);
  if ( (v4->_flag & 0x108) != 0 )
  {
    base = v4->_base;
    ptr = v4->_ptr;
    v4->_ptr = base + 1;
    v10 = ptr - base;
    v4->_cnt = v4->_bufsiz - 1;
    if ( v10 <= 0 )
    {
      if ( str == (_iobuf *)-1 || str == (_iobuf *)-2 )
        v11 = &__badioinfo;
      else
        v11 = (ioinfo *)((char *)__pioinfo[(int)str >> 5] + 64 * ((unsigned __int8)str & 0x1F));
      if ( (v11->osfile & 0x20) != 0 )
      {
        v12 = _lseeki64((int)str, 0, 2);
        if ( (HIDWORD(v12) & (unsigned int)v12) == 0xFFFFFFFF )
          goto LABEL_27;
      }
    }
    else
    {
      v13 = _write((int)str, base, v10);
    }
    *v4->_base = ch;
  }
  else
  {
    v10 = 1;
    v13 = _write((int)str, &ch, 1u);
  }
  if ( v13 != v10 )
  {
LABEL_27:
    v4->_flag |= 0x20u;
    return -1;
  }
  return ch;
}
