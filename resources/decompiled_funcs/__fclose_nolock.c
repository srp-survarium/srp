int __cdecl _fclose_nolock(_iobuf *str)
{
  int v1; // ebx
  int v3; // eax

  v1 = -1;
  if ( str )
  {
    if ( (str->_flag & 0x83) != 0 )
    {
      v1 = _flush(str);
      _freebuf(str);
      v3 = _fileno(str);
      if ( _close(v3) >= 0 )
      {
        if ( str->_tmpfname )
        {
          free(str->_tmpfname);
          str->_tmpfname = 0;
        }
      }
      else
      {
        v1 = -1;
      }
    }
    str->_flag = 0;
    return v1;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return -1;
  }
}
