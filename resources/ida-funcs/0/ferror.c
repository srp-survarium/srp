int __usercall ferror@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, _iobuf *stream)
{
  if ( stream )
    return stream->_flag & 0x20;
  *_errno() = 22;
  _invalid_parameter(a1, a2, 0);
  return 0;
}
