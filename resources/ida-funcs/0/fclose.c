int __usercall fclose@<eax>(int a1@<ebx>, _iobuf *stream)
{
  int result; // [esp+10h] [ebp-1Ch]

  result = -1;
  if ( stream )
  {
    if ( (stream->_flag & 0x40) != 0 )
    {
      stream->_flag = 0;
    }
    else
    {
      _lock_file(stream);
      result = _fclose_nolock(stream);
      _unlock_file(stream);
    }
    return result;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, 0, 0);
    return -1;
  }
}
