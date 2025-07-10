void __fastcall btSoftBody::clusterVImpulse(
        const btVector3 *impulse,
        const btVector3 *rpos,
        btSoftBody::Cluster *cluster)
{
  float m_imass; // xmm0_4
  float v4; // xmm6_4
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm0_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm7_4
  float v15; // xmm6_4
  float v16; // xmm3_4
  float v17; // xmm6_4
  float v18; // xmm4_4
  float v19; // [esp+18h] [ebp-8h]

  m_imass = cluster->m_imass;
  v4 = impulse->mVec128.m128_f32[2];
  v5 = rpos->mVec128.m128_f32[1];
  v6 = m_imass * impulse->mVec128.m128_f32[0];
  v7 = impulse->mVec128.m128_f32[1] * m_imass;
  v19 = v4 * m_imass;
  v8 = (float)(v5 * v4) - (float)(rpos->mVec128.m128_f32[2] * impulse->mVec128.m128_f32[1]);
  v9 = (float)(rpos->mVec128.m128_f32[2] * impulse->mVec128.m128_f32[0]) - (float)(rpos->mVec128.m128_f32[0] * v4);
  v10 = (float)(rpos->mVec128.m128_f32[0] * impulse->mVec128.m128_f32[1]) - (float)(v5 * impulse->mVec128.m128_f32[0]);
  v11 = (float)((float)(cluster->m_invwi.m_el[0].mVec128.m128_f32[2] * v10)
              + (float)(cluster->m_invwi.m_el[0].mVec128.m128_f32[1] * v9))
      + (float)(cluster->m_invwi.m_el[0].mVec128.m128_f32[0] * v8);
  v12 = (float)((float)(cluster->m_invwi.m_el[1].mVec128.m128_f32[2] * v10)
              + (float)(cluster->m_invwi.m_el[1].mVec128.m128_f32[1] * v9))
      + (float)(v8 * cluster->m_invwi.m_el[1].mVec128.m128_f32[0]);
  v13 = cluster->m_invwi.m_el[2].mVec128.m128_f32[2] * v10;
  v14 = cluster->m_invwi.m_el[2].mVec128.m128_f32[1] * v9;
  v15 = cluster->m_invwi.m_el[2].mVec128.m128_f32[0] * v8;
  cluster->m_vimpulses[0].mVec128.m128_f32[0] = cluster->m_vimpulses[0].mVec128.m128_f32[0] + v6;
  cluster->m_vimpulses[0].mVec128.m128_f32[1] = cluster->m_vimpulses[0].mVec128.m128_f32[1] + v7;
  v16 = (float)(v13 + v14) + v15;
  cluster->m_vimpulses[0].mVec128.m128_f32[2] = cluster->m_vimpulses[0].mVec128.m128_f32[2] + v19;
  v17 = cluster->m_lv.mVec128.m128_f32[0] + v6;
  cluster->m_lv.mVec128.m128_f32[1] = cluster->m_lv.mVec128.m128_f32[1] + v7;
  v18 = cluster->m_lv.mVec128.m128_f32[2] + v19;
  cluster->m_lv.mVec128.m128_f32[0] = v17;
  cluster->m_lv.mVec128.m128_f32[2] = v18;
  cluster->m_vimpulses[1].mVec128.m128_f32[0] = cluster->m_vimpulses[1].mVec128.m128_f32[0] + v11;
  cluster->m_vimpulses[1].mVec128.m128_f32[1] = cluster->m_vimpulses[1].mVec128.m128_f32[1] + v12;
  cluster->m_vimpulses[1].mVec128.m128_f32[2] = cluster->m_vimpulses[1].mVec128.m128_f32[2] + v16;
  cluster->m_av.mVec128.m128_f32[0] = cluster->m_av.mVec128.m128_f32[0] + v11;
  cluster->m_av.mVec128.m128_f32[1] = cluster->m_av.mVec128.m128_f32[1] + v12;
  cluster->m_av.mVec128.m128_f32[2] = cluster->m_av.mVec128.m128_f32[2] + v16;
  ++cluster->m_nvimpulses;
}
