void __stdcall btJacobianEntry::btJacobianEntry(
        btJacobianEntry *this,
        const btVector3 *rel_pos1,
        const btVector3 *rel_pos2,
        const btVector3 *jointAxis,
        float massInvA,
        float massInvB)
{
  const btMatrix3x3 *world2A; // edx
  const btMatrix3x3 *world2B; // ecx
  const btVector3 *inertiaInvA; // edi
  const btVector3 *inertiaInvB; // esi
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm5_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  unsigned __int64 v31; // [esp+10h] [ebp-10h]
  unsigned int v32; // [esp+18h] [ebp-8h]
  unsigned int v33; // [esp+18h] [ebp-8h]

  this->m_linearJointAxis = (btVector3)jointAxis->mVec128;
  v10 = rel_pos1->mVec128.m128_f32[1];
  v11 = rel_pos1->mVec128.m128_f32[2];
  v12 = this->m_linearJointAxis.mVec128.m128_f32[2];
  v13 = this->m_linearJointAxis.mVec128.m128_f32[1];
  v14 = this->m_linearJointAxis.mVec128.m128_f32[0];
  v15 = (float)(v12 * v10) - (float)(v13 * v11);
  v16 = (float)(this->m_linearJointAxis.mVec128.m128_f32[0] * v11) - (float)(rel_pos1->mVec128.m128_f32[0] * v12);
  v17 = (float)(rel_pos1->mVec128.m128_f32[0] * v13) - (float)(this->m_linearJointAxis.mVec128.m128_f32[0] * v10);
  *(float *)&v31 = (float)((float)(world2A->m_el[0].mVec128.m128_f32[1] * v16)
                         + (float)(world2A->m_el[0].mVec128.m128_f32[2] * v17))
                 + (float)(world2A->m_el[0].mVec128.m128_f32[0] * v15);
  *((float *)&v31 + 1) = (float)((float)(world2A->m_el[1].mVec128.m128_f32[1] * v16)
                               + (float)(world2A->m_el[1].mVec128.m128_f32[2] * v17))
                       + (float)(world2A->m_el[1].mVec128.m128_f32[0] * v15);
  v18 = (float)(world2A->m_el[2].mVec128.m128_f32[1] * v16) + (float)(world2A->m_el[2].mVec128.m128_f32[2] * v17);
  v19 = world2A->m_el[2].mVec128.m128_f32[0];
  this->m_aJ.mVec128.m128_u64[0] = v31;
  this->m_aJ.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v18 + (float)(v19 * v15));
  v20 = rel_pos2->mVec128.m128_f32[2];
  v21 = -v13;
  v22 = -v14;
  v23 = -v12;
  v24 = (float)(rel_pos2->mVec128.m128_f32[1] * v23) - (float)(v20 * v21);
  v25 = (float)(v20 * v22) - (float)(rel_pos2->mVec128.m128_f32[0] * v23);
  v26 = (float)(rel_pos2->mVec128.m128_f32[0] * v21) - (float)(rel_pos2->mVec128.m128_f32[1] * v22);
  *(float *)&v31 = (float)((float)(world2B->m_el[0].mVec128.m128_f32[2] * v26)
                         + (float)(world2B->m_el[0].mVec128.m128_f32[1] * v25))
                 + (float)(world2B->m_el[0].mVec128.m128_f32[0] * v24);
  v27 = (float)((float)(world2B->m_el[1].mVec128.m128_f32[2] * v26) + (float)(world2B->m_el[1].mVec128.m128_f32[1] * v25))
      + (float)(world2B->m_el[1].mVec128.m128_f32[0] * v24);
  v28 = world2B->m_el[2].mVec128.m128_f32[1] * v25;
  v29 = world2B->m_el[2].mVec128.m128_f32[0] * v24;
  *((float *)&v31 + 1) = v27;
  v30 = world2B->m_el[2].mVec128.m128_f32[2];
  this->m_bJ.mVec128.m128_u64[0] = v31;
  this->m_bJ.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT((float)((float)(v30 * v26) + v28) + v29);
  *(float *)&v31 = inertiaInvA->mVec128.m128_f32[0] * this->m_aJ.mVec128.m128_f32[0];
  *((float *)&v31 + 1) = this->m_aJ.mVec128.m128_f32[1] * inertiaInvA->mVec128.m128_f32[1];
  *(float *)&v32 = this->m_aJ.mVec128.m128_f32[2] * inertiaInvA->mVec128.m128_f32[2];
  this->m_0MinvJt.mVec128.m128_u64[0] = v31;
  this->m_0MinvJt.mVec128.m128_u64[1] = v32;
  *(float *)&v31 = inertiaInvB->mVec128.m128_f32[0] * this->m_bJ.mVec128.m128_f32[0];
  *((float *)&v31 + 1) = this->m_bJ.mVec128.m128_f32[1] * inertiaInvB->mVec128.m128_f32[1];
  *(float *)&v33 = this->m_bJ.mVec128.m128_f32[2] * inertiaInvB->mVec128.m128_f32[2];
  this->m_1MinvJt.mVec128.m128_u64[0] = v31;
  this->m_1MinvJt.mVec128.m128_u64[1] = v33;
  this->m_Adiag = (float)((float)((float)((float)((float)((float)((float)(this->m_bJ.mVec128.m128_f32[2]
                                                                        * this->m_1MinvJt.mVec128.m128_f32[2])
                                                                + (float)(this->m_bJ.mVec128.m128_f32[1]
                                                                        * this->m_1MinvJt.mVec128.m128_f32[1]))
                                                        + (float)(this->m_aJ.mVec128.m128_f32[2]
                                                                * this->m_0MinvJt.mVec128.m128_f32[2]))
                                                + (float)(this->m_aJ.mVec128.m128_f32[1]
                                                        * this->m_0MinvJt.mVec128.m128_f32[1]))
                                        + (float)(this->m_0MinvJt.mVec128.m128_f32[0] * this->m_aJ.mVec128.m128_f32[0]))
                                + (float)(this->m_bJ.mVec128.m128_f32[0] * this->m_1MinvJt.mVec128.m128_f32[0]))
                        + massInvA)
                + massInvB;
}
