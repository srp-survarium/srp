int __cdecl fflush(_iobuf *stream)
{
  int rc; // [esp+10h] [ebp-1Ch]

  if ( !stream )
    return flsall(0);
  _lock_file(stream);
  rc = _fflush_nolock(stream);
  _unlock_file(stream);
  return rc;
}
