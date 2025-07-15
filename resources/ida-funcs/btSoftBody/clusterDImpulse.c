void __usercall btSoftBody::clusterDImpulse(
        const btVector3 *rpos@<edx>,
        const btVector3 *impulse@<eax>,
        btSoftBody::Cluster *cluster)
{
  float v3; // xmm3_4
  float v4; // xmm4_4
  float m_imass; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm7_4
  float v8; // xmm5_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // [esp+8h] [ebp-8h]

  v3 = impulse->mVec128.m128_f32[2];
  v4 = impulse->mVec128.m128_f32[1];
  m_imass = cluster->m_imass;
  v6 = rpos->mVec128.m128_f32[1];
  v14 = v3 * m_imass;
  v7 = v4 * m_imass;
  v8 = (float)(v6 * v3) - (float)(rpos->mVec128.m128_f32[2] * v4);
  v9 = (float)(rpos->mVec128.m128_f32[2] * impulse->mVec128.m128_f32[0]) - (float)(rpos->mVec128.m128_f32[0] * v3);
  v10 = (float)(rpos->mVec128.m128_f32[0] * v4) - (float)(v6 * impulse->mVec128.m128_f32[0]);
  v11 = (float)((float)(cluster->m_invwi.m_el[0].mVec128.m128_f32[2] * v10)
              + (float)(cluster->m_invwi.m_el[0].mVec128.m128_f32[1] * v9))
      + (float)(cluster->m_invwi.m_el[0].mVec128.m128_f32[0] * v8);
  v12 = (float)((float)(cluster->m_invwi.m_el[1].mVec128.m128_f32[2] * v10)
              + (float)(cluster->m_invwi.m_el[1].mVec128.m128_f32[1] * v9))
      + (float)(v8 * cluster->m_invwi.m_el[1].mVec128.m128_f32[0]);
  v13 = (float)((float)(cluster->m_invwi.m_el[2].mVec128.m128_f32[2] * v10)
              + (float)(cluster->m_invwi.m_el[2].mVec128.m128_f32[1] * v9))
      + (float)(cluster->m_invwi.m_el[2].mVec128.m128_f32[0] * v8);
  cluster->m_dimpulses[0].mVec128.m128_f32[0] = cluster->m_dimpulses[0].mVec128.m128_f32[0]
                                              + (float)(cluster->m_imass * impulse->mVec128.m128_f32[0]);
  cluster->m_dimpulses[0].mVec128.m128_f32[1] = cluster->m_dimpulses[0].mVec128.m128_f32[1] + v7;
  cluster->m_dimpulses[0].mVec128.m128_f32[2] = cluster->m_dimpulses[0].mVec128.m128_f32[2] + v14;
  cluster->m_dimpulses[1].mVec128.m128_f32[0] = cluster->m_dimpulses[1].mVec128.m128_f32[0] + v11;
  cluster->m_dimpulses[1].mVec128.m128_f32[1] = cluster->m_dimpulses[1].mVec128.m128_f32[1] + v12;
  cluster->m_dimpulses[1].mVec128.m128_f32[2] = cluster->m_dimpulses[1].mVec128.m128_f32[2] + v13;
  ++cluster->m_ndimpulses;
}
