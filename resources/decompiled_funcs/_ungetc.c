int __usercall ungetc@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, int ch, _iobuf *stream)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream )
  {
    _lock_file(stream);
    retval = _ungetc_nolock(a1, ch, stream);
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
