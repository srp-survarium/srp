int __usercall fflush@<eax>(int a1@<ebx>, int a2@<edi>, _iobuf *stream)
{
  int rc; // [esp+10h] [ebp-1Ch]

  if ( !stream )
    return flsall(a1, 0);
  _lock_file(stream);
  rc = _fflush_nolock(a1, a2, stream);
  _unlock_file(stream);
  return rc;
}
