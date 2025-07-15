int __usercall _fileno@<eax>(int a1@<ebx>, int a2@<edi>, _iobuf *stream)
{
  if ( stream )
    return stream->_file;
  *_errno() = 22;
  _invalid_parameter(a1, a2, 0);
  return -1;
}
