__int64 __usercall _ftelli64@<edx:eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, _iobuf *stream)
{
  __int64 v3; // rax
  __int64 retval; // [esp+10h] [ebp-20h]

  _lock_file(stream);
  LODWORD(v3) = _ftelli64_nolock(a1, a2, stream);
  retval = v3;
  _unlock_file(stream);
  return retval;
}
