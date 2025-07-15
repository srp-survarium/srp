bool __usercall btAngleCompareFunc::operator()@<al>(
        btAngleCompareFunc *this@<esi>,
        const GrahamVector2 *a@<edx>,
        const GrahamVector2 *b@<ecx>)
{
  float m_angle; // xmm0_4
  float v4; // xmm1_4
  float v6; // xmm5_4
  float v7; // xmm4_4

  m_angle = a->m_angle;
  v4 = b->m_angle;
  if ( m_angle == v4
    && (v6 = this->m_anchor.mVec128.m128_f32[2],
        v7 = this->m_anchor.mVec128.m128_f32[1],
        m_angle = (float)((float)((float)(a->mVec128.m128_f32[0] - this->m_anchor.mVec128.m128_f32[0])
                                * (float)(a->mVec128.m128_f32[0] - this->m_anchor.mVec128.m128_f32[0]))
                        + (float)((float)(a->mVec128.m128_f32[2] - v6) * (float)(a->mVec128.m128_f32[2] - v6)))
                + (float)((float)(a->mVec128.m128_f32[1] - v7) * (float)(a->mVec128.m128_f32[1] - v7)),
        v4 = (float)((float)((float)(b->mVec128.m128_f32[0] - this->m_anchor.mVec128.m128_f32[0])
                           * (float)(b->mVec128.m128_f32[0] - this->m_anchor.mVec128.m128_f32[0]))
                   + (float)((float)(b->mVec128.m128_f32[2] - v6) * (float)(b->mVec128.m128_f32[2] - v6)))
           + (float)((float)(b->mVec128.m128_f32[1] - v7) * (float)(b->mVec128.m128_f32[1] - v7)),
        m_angle == v4) )
  {
    return a->m_orgIndex < b->m_orgIndex;
  }
  else
  {
    return v4 > m_angle;
  }
}
