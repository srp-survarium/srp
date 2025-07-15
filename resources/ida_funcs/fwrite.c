unsigned int __usercall fwrite@<eax>(
        unsigned int a1@<ebx>,
        unsigned int a2@<edi>,
        unsigned __int8 *buffer,
        unsigned int size,
        unsigned int count,
        _iobuf *stream)
{
  unsigned int retval; // [esp+10h] [ebp-1Ch]

  if ( !size || !count )
    return 0;
  if ( !stream )
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, 0);
    return 0;
  }
  _lock_file(stream);
  retval = _fwrite_nolock(a1, buffer, size, count, stream);
  _unlock_file(stream);
  return retval;
}
