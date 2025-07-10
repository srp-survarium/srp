void __cdecl fastcopy_I(_OWORD *dst, const __m128i *src, unsigned int len)
{
  unsigned int v5; // ecx
  __m128i si128; // xmm1
  __m128i v7; // xmm2
  __m128i v8; // xmm3
  __m128i v9; // xmm5
  __m128i v10; // xmm6
  __m128i v11; // xmm7

  v5 = len >> 7;
  do
  {
    si128 = _mm_load_si128(src + 1);
    v7 = _mm_load_si128(src + 2);
    v8 = _mm_load_si128(src + 3);
    *dst = _mm_load_si128(src);
    dst[1] = si128;
    dst[2] = v7;
    dst[3] = v8;
    v9 = _mm_load_si128(src + 5);
    v10 = _mm_load_si128(src + 6);
    v11 = _mm_load_si128(src + 7);
    dst[4] = _mm_load_si128(src + 4);
    dst[5] = v9;
    dst[6] = v10;
    dst[7] = v11;
    src += 8;
    dst += 8;
    --v5;
  }
  while ( v5 );
}
