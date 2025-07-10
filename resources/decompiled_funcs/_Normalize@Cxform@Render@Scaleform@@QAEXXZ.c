void __thiscall Scaleform::Render::Cxform::Normalize(Scaleform::Render::Cxform *this)
{
  *(__m128 *)&this->M[1][0] = _mm_mul_ps(*(__m128 *)&this->M[1][0], tffinv);
}
