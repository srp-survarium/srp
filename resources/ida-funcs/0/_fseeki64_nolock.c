int __usercall _fseeki64_nolock@<eax>(int a1@<ebx>, _iobuf *str, __int64 offset, unsigned int whence)
{
  int flag; // eax
  int v5; // edi
  __int64 v6; // rax
  int v7; // eax
  int v8; // eax
  __int64 v9; // rax

  flag = str->_flag;
  if ( (flag & 0x83) != 0 && (v5 = whence, whence <= 2) )
  {
    str->_flag = flag & 0xFFFFFFEF;
    if ( whence == 1 )
    {
      LODWORD(v6) = _ftelli64_nolock(a1, 1, str);
      offset += v6;
      v5 = 0;
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
    v8 = _fileno(a1, v5, str);
    v9 = _lseeki64(v8, offset, v5);
    if ( (HIDWORD(v9) & (unsigned int)v9) != 0xFFFFFFFF )
      return 0;
  }
  else
  {
    *_errno() = 22;
  }
  return -1;
}
