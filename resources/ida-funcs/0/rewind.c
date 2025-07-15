void __usercall rewind(int a1@<edi>, _iobuf *str)
{
  int v2; // edi
  ioinfo *v3; // eax
  int flag; // eax

  if ( str )
  {
    v2 = _fileno(0, a1, str);
    _lock_file(str);
    _flush(str);
    str->_flag &= 0xFFFFFFCF;
    if ( v2 == -1 || v2 == -2 )
      v3 = &__badioinfo;
    else
      v3 = (ioinfo *)((char *)__pioinfo[v2 >> 5] + 64 * (v2 & 0x1F));
    v3->osfile &= ~2u;
    flag = str->_flag;
    if ( (flag & 0x80u) != 0 )
      str->_flag = flag & 0xFFFFFFFC;
    if ( _lseek(0, (int)str, v2, 0, 0) == -1 )
      str->_flag |= 0x20u;
    _unlock_file(str);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, 0);
  }
}
