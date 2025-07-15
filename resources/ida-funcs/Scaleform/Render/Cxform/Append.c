void __thiscall Scaleform::Render::Cxform::Append(Scaleform::Render::Cxform *this, const Scaleform::Render::Cxform *c)
{
  __m128 v2; // xmm0

  v2 = _mm_add_ps(_mm_mul_ps(*(__m128 *)&this->M[1][0], *(__m128 *)&c->M[0][0]), *(__m128 *)&c->M[1][0]);
  *(__m128 *)&this->M[0][0] = _mm_mul_ps(*(__m128 *)&this->M[0][0], *(__m128 *)&c->M[0][0]);
  *(__m128 *)&this->M[1][0] = v2;
}
