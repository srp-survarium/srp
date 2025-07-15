int __usercall fsetpos@<eax>(int a1@<ebx>, int a2@<edi>, _iobuf *stream, __int64 *pos)
{
  if ( stream && pos )
    return _fseeki64(a1, stream, *pos, 0);
  *_errno() = 22;
  _invalid_parameter(a1, a2, 0);
  return -1;
}
