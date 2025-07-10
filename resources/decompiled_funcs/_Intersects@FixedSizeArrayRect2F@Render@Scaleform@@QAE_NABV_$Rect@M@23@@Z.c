bool __thiscall Scaleform::Render::FixedSizeArrayRect2F::Intersects(
        Scaleform::Render::FixedSizeArrayRect2F *this,
        __m128 *bounds)
{
  unsigned int v3; // eax
  __m128 v4; // xmm3
  __m128 v5; // xmm4
  __m128 v6; // xmm5
  __m128 v7; // xmm1
  bool HalfRect; // cl
  unsigned int Size; // esi
  unsigned int v10; // eax
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  Scaleform::Render::Rect2F *pData; // edx
  __m128 v14; // xmm0

  if ( bounds->m128_f32[2] <= (double)bounds->m128_f32[0] || bounds->m128_f32[3] <= (double)bounds->m128_f32[1] )
    return 0;
  v3 = _S2_0;
  if ( (_S2_0 & 1) != 0 )
  {
    v4 = c0000;
  }
  else
  {
    v4 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>'::`2'::v;
    v3 = _S2_0 | 1;
    _S2_0 |= 1u;
    c0000 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>'::`2'::v;
  }
  if ( (v3 & 2) != 0 )
  {
    v5 = c1100;
  }
  else
  {
    v5 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,0>'::`2'::v;
    v3 |= 2u;
    _S2_0 = v3;
    c1100 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,0>'::`2'::v;
  }
  if ( (v3 & 4) != 0 )
  {
    v6 = c0011;
  }
  else
  {
    v6 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>'::`2'::v;
    _S2_0 = v3 | 4;
    c0011 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>'::`2'::v;
  }
  v7 = *bounds;
  HalfRect = this->HalfRect;
  Size = this->Size;
  v10 = 0;
  v11 = _mm_shuffle_ps(v7, v7, 68);
  v12 = _mm_shuffle_ps(v7, v7, 238);
  if ( HalfRect )
    --Size;
  if ( Size )
  {
    pData = this->pData;
    do
    {
      v14 = _mm_or_ps(_mm_cmple_ps(pData->r1, v11), _mm_cmple_ps(v12, pData->r0));
      if ( (_mm_movemask_ps(_mm_cmpeq_ps(_mm_and_ps(v5, v14), v4)) & 0xF) == 0xF
        || (_mm_movemask_ps(_mm_cmpeq_ps(_mm_and_ps(v6, v14), v4)) & 0xF) == 0xF )
      {
        return 1;
      }
      ++v10;
      ++pData;
    }
    while ( v10 < Size );
  }
  return HalfRect
      && (_mm_movemask_ps(
            _mm_cmpeq_ps(
              _mm_and_ps(_mm_or_ps(_mm_cmple_ps(this->pData[v10].r1, v11), _mm_cmple_ps(v12, this->pData[v10].r0)), v5),
              v4))
        & 0xF) == 0xF;
}
