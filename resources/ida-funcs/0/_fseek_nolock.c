int __cdecl _fseek_nolock(_iobuf *str, int offset, int whence)
{
  int flag; // eax
  int v5; // eax
  int v6; // eax

  flag = str->_flag;
  if ( (flag & 0x83) != 0 )
  {
    str->_flag = flag & 0xFFFFFFEF;
    if ( whence == 1 )
    {
      offset += _ftell_nolock(str);
      whence = 0;
    }
    _flush(str);
    v5 = str->_flag;
    if ( (v5 & 0x80u) == 0 )
    {
      if ( (v5 & 1) != 0 && (v5 & 8) != 0 && (v5 & 0x400) == 0 )
        str->_bufsiz = 512;
    }
    else
    {
      str->_flag = v5 & 0xFFFFFFFC;
    }
    v6 = _fileno(str);
    return (_lseek(v6, offset, whence) != -1) - 1;
  }
  else
  {
    *_errno() = 22;
    return -1;
  }
}
