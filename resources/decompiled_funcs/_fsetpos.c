int __usercall fsetpos@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, _iobuf *stream, __int64 *pos)
{
  if ( stream && pos )
    return _fseeki64(stream, *pos, 0);
  *_errno() = 22;
  _invalid_parameter(a1, a2, 0);
  return -1;
}
