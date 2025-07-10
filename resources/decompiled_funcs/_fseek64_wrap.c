int __cdecl fseek64_wrap(_iobuf *f, __int64 off, int whence)
{
  if ( f )
    return fseek(f, off, whence);
  else
    return -1;
}
