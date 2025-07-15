int __usercall _fseeki64@<eax>(int a1@<ebx>, _iobuf *stream, __int64 offset, unsigned int whence)
{
  int retval; // [esp+10h] [ebp-1Ch]

  _lock_file(stream);
  retval = _fseeki64_nolock(a1, stream, offset, whence);
  _unlock_file(stream);
  return retval;
}
