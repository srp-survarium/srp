void __thiscall Scaleform::Render::FixedSizeArrayRect2F::PushBack(
        Scaleform::Render::FixedSizeArrayRect2F *this,
        __m128 *r)
{
  unsigned int Size; // eax
  Scaleform::Render::Rect2F *pData; // ecx
  __m128 v5; // xmm0
  int v6; // eax
  __m128 r0; // xmm1
  __m128 *p_r0; // eax
  Scaleform::Render::Rect2F *v9; // eax
  __m128 v10; // xmm0

  Size = this->Size;
  if ( this->HalfRect )
  {
    pData = this->pData;
    v5 = *r;
    v6 = Size;
    r0 = pData[v6 - 1].r0;
    p_r0 = &pData[v6 - 1].r0;
    *p_r0 = _mm_shuffle_ps(r0, *r, 68);
    p_r0[1] = _mm_shuffle_ps(p_r0[1], v5, 228);
    this->HalfRect = 0;
  }
  else
  {
    if ( Size == this->Reserve )
      Scaleform::Render::FixedSizeArray<Scaleform::Render::Rect2F>::grow(this, 2 * Size);
    v9 = &this->pData[this->Size++];
    v10 = *r;
    v9->r0 = _mm_shuffle_ps(*r, v9->r0, 228);
    v9->r1 = _mm_shuffle_ps(v10, v9->r1, 238);
    this->HalfRect = 1;
  }
}
