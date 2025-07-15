int __usercall fgetpos@<eax>(unsigned int a1@<ebx>, unsigned int a2@<esi>, _iobuf *stream, __int64 *pos)
{
  int result; // eax
  __int64 v5; // rax
  int v6; // ecx

  if ( stream )
  {
    if ( pos )
    {
      v5 = _ftelli64(stream);
      *pos = v5;
      v6 = HIDWORD(v5) & v5;
      result = -1;
      if ( v6 != -1 )
        return 0;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(a1, 0, 0);
      return -1;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, 0, a2);
    return -1;
  }
  return result;
}
