int __usercall fseek@<eax>(int a1@<ebx>, int a2@<edi>, _iobuf *stream, int offset, unsigned int whence)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream && (a2 = whence, whence <= 2) )
  {
    _lock_file(stream);
    retval = _fseek_nolock(a1, whence, stream, offset, whence);
    _unlock_file(stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, 0);
    return -1;
  }
}
