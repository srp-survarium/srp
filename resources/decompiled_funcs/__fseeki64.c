int __cdecl _fseeki64(_iobuf *stream, __int64 offset, unsigned int whence)
{
  int retval; // [esp+10h] [ebp-1Ch]

  _lock_file(stream);
  retval = _fseeki64_nolock(stream, offset, whence);
  _unlock_file(stream);
  return retval;
}
