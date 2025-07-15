void __usercall btSoftBody::clusterVImpulse(
        const btVector3 *rpos@<edx>,
        const btVector3 *impulse@<eax>,
        btSoftBody::Cluster *cluster)
{
  float v3; // xmm6_4
  float m_imass; // xmm1_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm3_4
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // [esp+8h] [ebp-8h]

  v3 = impulse->mVec128.m128_f32[2];
  m_imass = cluster->m_imass;
  v5 = m_imass * impulse->mVec128.m128_f32[0];
  v6 = impulse->mVec128.m128_f32[1] * m_imass;
  v18 = v3 * m_imass;
  v7 = (float)(rpos->mVec128.m128_f32[1] * v3) - (float)(rpos->mVec128.m128_f32[2] * impulse->mVec128.m128_f32[1]);
  v8 = (float)(rpos->mVec128.m128_f32[2] * impulse->mVec128.m128_f32[0]) - (float)(rpos->mVec128.m128_f32[0] * v3);
  v9 = (float)(rpos->mVec128.m128_f32[0] * impulse->mVec128.m128_f32[1])
     - (float)(rpos->mVec128.m128_f32[1] * impulse->mVec128.m128_f32[0]);
  v10 = (float)((float)(cluster->m_invwi.m_el[0].mVec128.m128_f32[2] * v9)
              + (float)(cluster->m_invwi.m_el[0].mVec128.m128_f32[1] * v8))
      + (float)(cluster->m_invwi.m_el[0].mVec128.m128_f32[0] * v7);
  v11 = (float)((float)(cluster->m_invwi.m_el[1].mVec128.m128_f32[2] * v9)
              + (float)(cluster->m_invwi.m_el[1].mVec128.m128_f32[1] * v8))
      + (float)(v7 * cluster->m_invwi.m_el[1].mVec128.m128_f32[0]);
  v12 = cluster->m_invwi.m_el[2].mVec128.m128_f32[2] * v9;
  v13 = cluster->m_invwi.m_el[2].mVec128.m128_f32[1] * v8;
  v14 = cluster->m_invwi.m_el[2].mVec128.m128_f32[0] * v7;
  cluster->m_vimpulses[0].mVec128.m128_f32[0] = cluster->m_vimpulses[0].mVec128.m128_f32[0] + v5;
  cluster->m_vimpulses[0].mVec128.m128_f32[1] = cluster->m_vimpulses[0].mVec128.m128_f32[1] + v6;
  cluster->m_vimpulses[0].mVec128.m128_f32[2] = cluster->m_vimpulses[0].mVec128.m128_f32[2] + v18;
  cluster->m_lv.mVec128.m128_f32[0] = cluster->m_lv.mVec128.m128_f32[0] + v5;
  cluster->m_lv.mVec128.m128_f32[1] = cluster->m_lv.mVec128.m128_f32[1] + v6;
  cluster->m_lv.mVec128.m128_f32[2] = cluster->m_lv.mVec128.m128_f32[2] + v18;
  v15 = (float)(v12 + v13) + v14;
  cluster->m_vimpulses[1].mVec128.m128_f32[0] = cluster->m_vimpulses[1].mVec128.m128_f32[0] + v10;
  cluster->m_vimpulses[1].mVec128.m128_f32[1] = cluster->m_vimpulses[1].mVec128.m128_f32[1] + v11;
  cluster->m_vimpulses[1].mVec128.m128_f32[2] = cluster->m_vimpulses[1].mVec128.m128_f32[2] + v15;
  v16 = cluster->m_av.mVec128.m128_f32[0] + v10;
  cluster->m_av.mVec128.m128_f32[1] = cluster->m_av.mVec128.m128_f32[1] + v11;
  v17 = cluster->m_av.mVec128.m128_f32[2] + v15;
  cluster->m_av.mVec128.m128_f32[0] = v16;
  cluster->m_av.mVec128.m128_f32[2] = v17;
  ++cluster->m_nvimpulses;
}
