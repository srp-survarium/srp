void __fastcall btSoftBody::clusterDImpulse(
        const btVector3 *impulse,
        const btVector3 *rpos,
        btSoftBody::Cluster *cluster)
{
  float v3; // xmm5_4
  float v4; // xmm3_4
  float m_imass; // xmm6_4
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // [esp+14h] [ebp-Ch]
  float v15; // [esp+18h] [ebp-8h]

  v3 = impulse->mVec128.m128_f32[2];
  v4 = rpos->mVec128.m128_f32[1];
  m_imass = cluster->m_imass;
  v14 = impulse->mVec128.m128_f32[1] * m_imass;
  v15 = v3 * m_imass;
  v6 = (float)(v4 * v3) - (float)(rpos->mVec128.m128_f32[2] * impulse->mVec128.m128_f32[1]);
  v7 = (float)(rpos->mVec128.m128_f32[0] * impulse->mVec128.m128_f32[1]) - (float)(v4 * impulse->mVec128.m128_f32[0]);
  v8 = (float)(rpos->mVec128.m128_f32[2] * impulse->mVec128.m128_f32[0]) - (float)(rpos->mVec128.m128_f32[0] * v3);
  v9 = (float)((float)(cluster->m_invwi.m_el[0].mVec128.m128_f32[2] * v7)
             + (float)(cluster->m_invwi.m_el[0].mVec128.m128_f32[1] * v8))
     + (float)(cluster->m_invwi.m_el[0].mVec128.m128_f32[0] * v6);
  v10 = (float)((float)(cluster->m_invwi.m_el[1].mVec128.m128_f32[2] * v7)
              + (float)(cluster->m_invwi.m_el[1].mVec128.m128_f32[1] * v8))
      + (float)(v6 * cluster->m_invwi.m_el[1].mVec128.m128_f32[0]);
  v11 = cluster->m_invwi.m_el[2].mVec128.m128_f32[2] * v7;
  v12 = cluster->m_invwi.m_el[2].mVec128.m128_f32[1] * v8;
  v13 = cluster->m_invwi.m_el[2].mVec128.m128_f32[0] * v6;
  cluster->m_dimpulses[0].mVec128.m128_f32[0] = cluster->m_dimpulses[0].mVec128.m128_f32[0]
                                              + (float)(m_imass * impulse->mVec128.m128_f32[0]);
  cluster->m_dimpulses[0].mVec128.m128_f32[1] = cluster->m_dimpulses[0].mVec128.m128_f32[1] + v14;
  cluster->m_dimpulses[0].mVec128.m128_f32[2] = cluster->m_dimpulses[0].mVec128.m128_f32[2] + v15;
  cluster->m_dimpulses[1].mVec128.m128_f32[0] = cluster->m_dimpulses[1].mVec128.m128_f32[0] + v9;
  cluster->m_dimpulses[1].mVec128.m128_f32[1] = cluster->m_dimpulses[1].mVec128.m128_f32[1] + v10;
  cluster->m_dimpulses[1].mVec128.m128_f32[2] = cluster->m_dimpulses[1].mVec128.m128_f32[2]
                                              + (float)((float)(v11 + v12) + v13);
  ++cluster->m_ndimpulses;
}
