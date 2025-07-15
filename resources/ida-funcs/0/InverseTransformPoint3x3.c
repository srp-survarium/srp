void __usercall InverseTransformPoint3x3(const btVector3 *in@<edx>, const btTransform *tr@<eax>, btVector3 *out)
{
  float v3; // xmm4_4
  float v4; // xmm3_4
  float v5; // xmm1_4
  unsigned int v6; // xmm2_4

  v3 = in->mVec128.m128_f32[1];
  v4 = in->mVec128.m128_f32[2];
  v5 = (float)((float)(tr->m_basis.m_el[0].mVec128.m128_f32[1] * in->mVec128.m128_f32[0])
             + (float)(tr->m_basis.m_el[1].mVec128.m128_f32[1] * v3))
     + (float)(tr->m_basis.m_el[2].mVec128.m128_f32[1] * v4);
  *(float *)&v6 = (float)((float)(tr->m_basis.m_el[0].mVec128.m128_f32[2] * in->mVec128.m128_f32[0])
                        + (float)(tr->m_basis.m_el[1].mVec128.m128_f32[2] * v3))
                + (float)(tr->m_basis.m_el[2].mVec128.m128_f32[2] * v4);
  out->mVec128.m128_f32[0] = (float)((float)(in->mVec128.m128_f32[0] * tr->m_basis.m_el[0].mVec128.m128_f32[0])
                                   + (float)(tr->m_basis.m_el[2].mVec128.m128_f32[0] * v4))
                           + (float)(tr->m_basis.m_el[1].mVec128.m128_f32[0] * v3);
  out->mVec128.m128_f32[1] = v5;
  out->mVec128.m128_u64[1] = v6;
}
