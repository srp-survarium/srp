unsigned int __usercall fread_s@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        unsigned __int8 *buffer,
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
    _invalid_parameter(a1, a2, 0);
    return 0;
  }
  _lock_file(stream);
  retval = _fread_nolock_s(0, buffer, bufferSize, elementSize, count, stream);
  _unlock_file(stream);
  return retval;
}
