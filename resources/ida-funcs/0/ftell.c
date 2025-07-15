int __cdecl ftell(_iobuf *stream)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream )
  {
    _lock_file(stream);
    retval = _ftell_nolock(stream);
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
