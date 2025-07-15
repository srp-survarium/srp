btMatrix3x3 *__userpurge btMatrix3x3::btMatrix3x3@<eax>(
        btMatrix3x3 *this@<ecx>,
        btMatrix3x3 *result@<eax>,
        const float *xx,
        const float *xy,
        const float *xz,
        const float *yx,
        const float *yy,
        const float *yz,
        const float *zx,
        const float *zy,
        const float *zz)
{
  double v11; // st7

  result->m_el[0].mVec128.m128_f32[0] = this->m_el[0].mVec128.m128_f32[0];
  result->m_el[0].mVec128.m128_f32[1] = *xx;
  result->m_el[0].mVec128.m128_f32[2] = *xy;
  result->m_el[0].mVec128.m128_i32[3] = 0;
  result->m_el[1].mVec128.m128_f32[0] = *xz;
  result->m_el[1].mVec128.m128_f32[1] = *yx;
  result->m_el[1].mVec128.m128_f32[2] = *yy;
  result->m_el[1].mVec128.m128_i32[3] = 0;
  result->m_el[2].mVec128.m128_f32[0] = *yz;
  result->m_el[2].mVec128.m128_f32[1] = *zx;
  v11 = *zy;
  result->m_el[2].mVec128.m128_i32[3] = 0;
  result->m_el[2].mVec128.m128_f32[2] = v11;
  return result;
}
