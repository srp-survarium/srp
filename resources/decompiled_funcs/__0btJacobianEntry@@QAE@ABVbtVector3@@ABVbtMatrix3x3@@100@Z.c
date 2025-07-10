void __stdcall btJacobianEntry::btJacobianEntry(btJacobianEntry *this, const btVector3 *inertiaInvA)
{
  const btMatrix3x3 *world2A; // edx
  const btMatrix3x3 *world2B; // ecx
  const btVector3 *inertiaInvB; // edi
  const btVector3 *jointAxis; // esi
  float v6; // xmm1_4
  float v7; // xmm2_4
  unsigned int v8; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  btVector3 v12; // [esp+Ch] [ebp-10h]

  this->m_linearJointAxis.mVec128.m128_u64[0] = 0;
  this->m_linearJointAxis.mVec128.m128_u64[1] = 0;
  v6 = jointAxis->mVec128.m128_f32[2];
  v7 = jointAxis->mVec128.m128_f32[1];
  v12.mVec128.m128_f32[0] = (float)((float)(world2A->m_el[0].mVec128.m128_f32[1] * v7)
                                  + (float)(world2A->m_el[0].mVec128.m128_f32[2] * v6))
                          + (float)(world2A->m_el[0].mVec128.m128_f32[0] * jointAxis->mVec128.m128_f32[0]);
  v12.mVec128.m128_f32[1] = (float)((float)(world2A->m_el[1].mVec128.m128_f32[1] * v7)
                                  + (float)(world2A->m_el[1].mVec128.m128_f32[2] * v6))
                          + (float)(world2A->m_el[1].mVec128.m128_f32[0] * jointAxis->mVec128.m128_f32[0]);
  *(float *)&v8 = (float)((float)(world2A->m_el[2].mVec128.m128_f32[1] * v7)
                        + (float)(world2A->m_el[2].mVec128.m128_f32[2] * v6))
                + (float)(world2A->m_el[2].mVec128.m128_f32[0] * jointAxis->mVec128.m128_f32[0]);
  this->m_aJ.mVec128.m128_u64[0] = v12.mVec128.m128_u64[0];
  this->m_aJ.mVec128.m128_u64[1] = v8;
  v9 = -jointAxis->mVec128.m128_f32[0];
  v10 = -jointAxis->mVec128.m128_f32[1];
  v11 = -jointAxis->mVec128.m128_f32[2];
  v12.mVec128.m128_f32[0] = (float)((float)(world2B->m_el[0].mVec128.m128_f32[2] * v11)
                                  + (float)(world2B->m_el[0].mVec128.m128_f32[1] * v10))
                          + (float)(world2B->m_el[0].mVec128.m128_f32[0] * v9);
  v12.mVec128.m128_f32[1] = (float)((float)(world2B->m_el[1].mVec128.m128_f32[2] * v11)
                                  + (float)(world2B->m_el[1].mVec128.m128_f32[1] * v10))
                          + (float)(world2B->m_el[1].mVec128.m128_f32[0] * v9);
  v12.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                              (float)((float)(world2B->m_el[2].mVec128.m128_f32[2] * v11)
                                    + (float)(world2B->m_el[2].mVec128.m128_f32[1] * v10))
                            + (float)(world2B->m_el[2].mVec128.m128_f32[0] * v9));
  this->m_bJ = (btVector3)v12.mVec128;
  v12.mVec128.m128_f32[0] = inertiaInvA->mVec128.m128_f32[0] * this->m_aJ.mVec128.m128_f32[0];
  v12.mVec128.m128_f32[1] = this->m_aJ.mVec128.m128_f32[1] * inertiaInvA->mVec128.m128_f32[1];
  v12.mVec128.m128_f32[2] = this->m_aJ.mVec128.m128_f32[2] * inertiaInvA->mVec128.m128_f32[2];
  this->m_0MinvJt.mVec128.m128_u64[0] = v12.mVec128.m128_u64[0];
  this->m_0MinvJt.mVec128.m128_u64[1] = v12.mVec128.m128_u32[2];
  v12.mVec128.m128_f32[0] = inertiaInvB->mVec128.m128_f32[0] * this->m_bJ.mVec128.m128_f32[0];
  v12.mVec128.m128_f32[1] = this->m_bJ.mVec128.m128_f32[1] * inertiaInvB->mVec128.m128_f32[1];
  v12.mVec128.m128_f32[2] = this->m_bJ.mVec128.m128_f32[2] * inertiaInvB->mVec128.m128_f32[2];
  this->m_1MinvJt.mVec128.m128_u64[0] = v12.mVec128.m128_u64[0];
  this->m_1MinvJt.mVec128.m128_u64[1] = v12.mVec128.m128_u32[2];
  this->m_Adiag = (float)((float)((float)((float)((float)(this->m_bJ.mVec128.m128_f32[2]
                                                        * this->m_1MinvJt.mVec128.m128_f32[2])
                                                + (float)(this->m_bJ.mVec128.m128_f32[1]
                                                        * this->m_1MinvJt.mVec128.m128_f32[1]))
                                        + (float)(this->m_aJ.mVec128.m128_f32[2] * this->m_0MinvJt.mVec128.m128_f32[2]))
                                + (float)(this->m_aJ.mVec128.m128_f32[1] * this->m_0MinvJt.mVec128.m128_f32[1]))
                        + (float)(this->m_0MinvJt.mVec128.m128_f32[0] * this->m_aJ.mVec128.m128_f32[0]))
                + (float)(this->m_bJ.mVec128.m128_f32[0] * this->m_1MinvJt.mVec128.m128_f32[0]);
}
