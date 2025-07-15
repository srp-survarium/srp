void __thiscall Scaleform::Render::Cxform::SetToAppend(
        Scaleform::Render::Cxform *this,
        const Scaleform::Render::Cxform *c0,
        const Scaleform::Render::Cxform *c1)
{
  __m128 v3; // xmm0

  v3 = _mm_add_ps(_mm_mul_ps(*(__m128 *)&c0->M[1][0], *(__m128 *)&c1->M[0][0]), *(__m128 *)&c1->M[1][0]);
  *(__m128 *)&this->M[0][0] = _mm_mul_ps(*(__m128 *)&c0->M[0][0], *(__m128 *)&c1->M[0][0]);
  *(__m128 *)&this->M[1][0] = v3;
}
