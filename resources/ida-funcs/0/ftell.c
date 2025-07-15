int __usercall ftell@<eax>(int a1@<ebx>, int a2@<edi>, _iobuf *stream)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream )
  {
    _lock_file(stream);
    retval = _ftell_nolock(0, stream);
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
