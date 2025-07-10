int __cdecl fseek(_iobuf *stream, int offset, unsigned int whence)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream && whence <= 2 )
  {
    _lock_file(stream);
    retval = _fseek_nolock(stream, offset, whence);
    _unlock_file(stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return -1;
  }
}
