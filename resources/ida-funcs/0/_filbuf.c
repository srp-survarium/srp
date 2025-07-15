int __usercall _filbuf@<eax>(int a1@<ebx>, _iobuf *str)
{
  int flag; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  stlp_std::ioinfo **v6; // edi
  ioinfo *v7; // eax
  int v8; // eax
  char *ptr; // ecx
  int result; // eax
  char *base; // [esp-8h] [ebp-10h]
  unsigned int bufsiz; // [esp-4h] [ebp-Ch]

  if ( !str )
  {
    *_errno() = 22;
    _invalid_parameter(a1, 0, 0);
    return -1;
  }
  flag = str->_flag;
  if ( (flag & 0x83) == 0 || (flag & 0x40) != 0 )
    return -1;
  if ( (flag & 2) != 0 )
  {
    str->_flag = flag | 0x20;
    return -1;
  }
  v3 = flag | 1;
  str->_flag = v3;
  if ( (v3 & 0x10C) != 0 )
    str->_ptr = str->_base;
  else
    _getbuf(str);
  bufsiz = str->_bufsiz;
  base = str->_base;
  v4 = _fileno(a1, 0, str);
  v5 = _read(v4, base, bufsiz);
  str->_cnt = v5;
  if ( !v5 || v5 == -1 )
  {
    str->_flag |= v5 != 0 ? 32 : 16;
    str->_cnt = 0;
    return -1;
  }
  if ( (str->_flag & 0x82) == 0 )
  {
    if ( _fileno(a1, 0, str) == -1 || _fileno(a1, 0, str) == -2 )
    {
      v7 = &__badioinfo;
    }
    else
    {
      v6 = &__pioinfo[_fileno(a1, 0, str) >> 5];
      v7 = (ioinfo *)((char *)*v6 + 64 * (_fileno(a1, (int)v6, str) & 0x1F));
    }
    if ( (v7->osfile & 0x82) == 0x82 )
      str->_flag |= 0x2000u;
  }
  if ( str->_bufsiz == 512 )
  {
    v8 = str->_flag;
    if ( (v8 & 8) != 0 && (v8 & 0x400) == 0 )
      str->_bufsiz = 4096;
  }
  ptr = str->_ptr;
  --str->_cnt;
  result = (unsigned __int8)*ptr;
  str->_ptr = ptr + 1;
  return result;
}
