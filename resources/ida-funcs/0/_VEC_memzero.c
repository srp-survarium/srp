char *__cdecl _VEC_memzero(char *dst, int val, int len)
{
  char *result; // eax
  int v4; // edi
  int v5; // edx
  unsigned int v6; // [esp+4h] [ebp-Ch]

  result = dst;
  v4 = (int)dst % 16;
  if ( (int)dst % 16 )
  {
    memset(dst, 0, 16 - v4);
    _VEC_memzero((int)&dst[16 - v4], 0, len - (16 - v4));
    return dst;
  }
  else
  {
    v5 = len & 0x7F;
    v6 = v5;
    if ( len != v5 )
    {
      fastzero_I(dst, len - v5);
      result = dst;
      v5 = v6;
    }
    if ( v5 )
    {
      memset(&result[len - v5], 0, v6);
      return dst;
    }
  }
  return result;
}
