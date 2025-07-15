unsigned int __usercall memcpy_s@<eax>(
        unsigned int a1@<ebx>,
        unsigned __int8 *dst,
        unsigned int sizeInBytes,
        unsigned __int8 *src,
        unsigned int count)
{
  unsigned int v6; // esi

  if ( !count )
    return 0;
  if ( !dst )
    goto LABEL_4;
  if ( src && sizeInBytes >= count )
  {
    memcpy(dst, src, count);
    return 0;
  }
  memset((int)dst, 0, sizeInBytes);
  if ( !src )
  {
LABEL_4:
    v6 = 22;
    *_errno() = 22;
LABEL_5:
    _invalid_parameter(a1, 0, v6);
    return v6;
  }
  if ( sizeInBytes < count )
  {
    *_errno() = 34;
    v6 = 34;
    goto LABEL_5;
  }
  return 22;
}
