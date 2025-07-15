int __usercall _fseek_nolock@<eax>(int a1@<ebx>, int a2@<edi>, _iobuf *str, int offset, int whence)
{
  int flag; // eax
  int v7; // eax
  int v8; // eax

  flag = str->_flag;
  if ( (flag & 0x83) != 0 )
  {
    str->_flag = flag & 0xFFFFFFEF;
    if ( whence == 1 )
    {
      offset += _ftell_nolock((int)str, str);
      whence = 0;
    }
    _flush(str);
    v7 = str->_flag;
    if ( (v7 & 0x80u) == 0 )
    {
      if ( (v7 & 1) != 0 && (v7 & 8) != 0 && (v7 & 0x400) == 0 )
        str->_bufsiz = 512;
    }
    else
    {
      str->_flag = v7 & 0xFFFFFFFC;
    }
    v8 = _fileno(a1, a2, str);
    return (_lseek(v8, offset, whence) != -1) - 1;
  }
  else
  {
    *_errno() = 22;
    return -1;
  }
}
