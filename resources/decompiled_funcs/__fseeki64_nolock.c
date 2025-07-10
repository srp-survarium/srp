int __cdecl _fseeki64_nolock(_iobuf *str, __int64 offset, unsigned int whence)
{
  int flag; // eax
  int v4; // edi
  int v5; // eax
  int v6; // eax
  __int64 v7; // rax

  flag = str->_flag;
  if ( (flag & 0x83) != 0 && (v4 = whence, whence <= 2) )
  {
    str->_flag = flag & 0xFFFFFFEF;
    if ( whence == 1 )
    {
      offset += _ftelli64_nolock(str);
      v4 = 0;
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
    v7 = _lseeki64(v6, offset, v4);
    if ( (HIDWORD(v7) & (unsigned int)v7) != 0xFFFFFFFF )
      return 0;
  }
  else
  {
    *_errno() = 22;
  }
  return -1;
}
