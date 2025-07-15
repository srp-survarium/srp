unsigned int __cdecl fread_s(
        char *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int count,
        _iobuf *stream)
{
  unsigned int retval; // [esp+10h] [ebp-1Ch]

  if ( !elementSize || !count )
    return 0;
  if ( !stream )
  {
    if ( bufferSize != -1 )
      memset((int)buffer, 0, bufferSize);
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return 0;
  }
  _lock_file(stream);
  retval = _fread_nolock_s(buffer, bufferSize, elementSize, count, stream);
  _unlock_file(stream);
  return retval;
}
