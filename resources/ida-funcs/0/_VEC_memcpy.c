char *__cdecl _VEC_memcpy(char *dst, const __m128i *src, unsigned int len)
{
  int v3; // ecx
  char *result; // eax
  unsigned int v5; // ecx
  unsigned int v6; // [esp+4h] [ebp-18h]

  v3 = (int)src % 16;
  result = dst;
  if ( ((int)dst % 16) | ((int)src % 16) )
  {
    if ( v3 == (int)dst % 16 )
    {
      qmemcpy(dst, src, 16 - v3);
      _VEC_memcpy((int)&dst[16 - v3], (const __m128i *)((char *)src + 16 - v3), len - (16 - v3));
    }
    else
    {
      qmemcpy(dst, src, len);
    }
    return dst;
  }
  else
  {
    v5 = len & 0x7F;
    v6 = v5;
    if ( len != v5 )
    {
      fastcopy_I(dst, src, len - v5);
      result = dst;
      v5 = v6;
    }
    if ( v5 )
    {
      qmemcpy(&result[len - v5], &src->m128i_i8[len - v5], v6);
      return dst;
    }
  }
  return result;
}
