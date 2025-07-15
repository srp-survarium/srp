char *__cdecl _VEC_memzero(int dst, int val, int len)
{
  char *result; // eax
  int v4; // edi
  int v5; // edx
  unsigned int v6; // [esp+4h] [ebp-Ch]

  result = (char *)dst;
  v4 = dst % 16;
  if ( dst % 16 )
  {
    memset((void *)dst, 0, 16 - v4);
    _VEC_memzero((void *)(16 - v4 + dst), 0, len - (16 - v4));
    return (char *)dst;
  }
  else
  {
    v5 = len & 0x7F;
    v6 = v5;
    if ( len != v5 )
    {
      fastzero_I((_OWORD *)dst, len - v5);
      result = (char *)dst;
      v5 = v6;
    }
    if ( v5 )
    {
      memset(&result[len - v5], 0, v6);
      return (char *)dst;
    }
  }
  return result;
}
