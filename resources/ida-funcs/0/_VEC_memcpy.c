char *__cdecl _VEC_memcpy(int dst, const __m128i *src, unsigned int len)
{
  int v3; // ecx
  char *result; // eax
  int v5; // ecx
  unsigned int v6; // [esp+4h] [ebp-18h]

  v3 = (int)src % 16;
  result = (char *)dst;
  if ( (dst % 16) | ((int)src % 16) )
  {
    if ( v3 == dst % 16 )
    {
      qmemcpy((void *)dst, src, 16 - v3);
      _VEC_memcpy((void *)(16 - v3 + dst), &src->m128i_i8[16 - v3], len - (16 - v3));
    }
    else
    {
      qmemcpy((void *)dst, src, len);
    }
    return (char *)dst;
  }
  else
  {
    v5 = len & 0x7F;
    v6 = v5;
    if ( len != v5 )
    {
      fastcopy_I((_OWORD *)dst, src, len - v5);
      result = (char *)dst;
      v5 = v6;
    }
    if ( v5 )
    {
      qmemcpy(&result[len - v5], &src->m128i_i8[len - v5], v6);
      return (char *)dst;
    }
  }
  return result;
}
