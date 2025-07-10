void __cdecl Scaleform::Render::ConvertIndices_SIMD(
        __m128i *pdest,
        __m128i *psource,
        unsigned int count,
        unsigned __int16 delta)
{
  __m128i *v4; // eax
  const __m128i *v5; // ecx
  signed __int16 v6; // bx
  unsigned __int16 *v7; // edi
  unsigned int v8; // edx
  unsigned int v9; // esi
  __m128i v10; // xmm0
  __m128i v11; // xmm0

  v4 = pdest;
  v5 = psource;
  if ( (((unsigned __int8)psource ^ (unsigned __int8)pdest) & 0xF) != 0 )
  {
    Scaleform::Render::ConvertIndices_NonOpt((unsigned __int16 *)pdest, (unsigned __int16 *)psource, count, delta);
  }
  else
  {
    v6 = delta;
    v7 = (unsigned __int16 *)psource + count;
    v8 = ((unsigned int)&pdest->m128i_u32[3] + 3) & 0xFFFFFFF0;
    v9 = ((unsigned int)pdest + 2 * count) & 0xFFFFFFF0;
    if ( v8 < v9 )
    {
      if ( (unsigned int)pdest < v8 )
      {
        do
        {
          v4 = (__m128i *)((char *)v4 + 2);
          v4[-1].m128i_i16[7] = delta + v5->m128i_i16[0];
          v5 = (const __m128i *)((char *)v5 + 2);
        }
        while ( (unsigned int)v4 < v8 );
        v6 = delta;
      }
      v10 = _mm_cvtsi32_si128(v6);
      v11 = _mm_shuffle_epi32(_mm_unpacklo_epi16(v10, v10), 0);
      do
        _mm_stream_si128(v4++, _mm_add_epi16(_mm_loadu_si128(v5++), v11));
      while ( (unsigned int)v4 < v9 );
    }
    for ( ; v5 < (const __m128i *)v7; v4 = (__m128i *)((char *)v4 + 2) )
    {
      v4->m128i_i16[0] = v6 + v5->m128i_i16[0];
      v5 = (const __m128i *)((char *)v5 + 2);
    }
  }
}
