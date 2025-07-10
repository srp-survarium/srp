void __usercall btSoftBody::clusterVAImpulse(btSoftBody::Cluster *cluster@<eax>, const btVector3 *impulse@<ecx>)
{
  float v2; // xmm3_4
  float v3; // xmm4_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4

  v2 = impulse->mVec128.m128_f32[2];
  v3 = impulse->mVec128.m128_f32[1];
  v4 = (float)((float)(cluster->m_invwi.m_el[0].mVec128.m128_f32[1] * v3)
             + (float)(cluster->m_invwi.m_el[0].mVec128.m128_f32[2] * v2))
     + (float)(cluster->m_invwi.m_el[0].mVec128.m128_f32[0] * impulse->mVec128.m128_f32[0]);
  v5 = (float)((float)(cluster->m_invwi.m_el[1].mVec128.m128_f32[1] * v3)
             + (float)(cluster->m_invwi.m_el[1].mVec128.m128_f32[2] * v2))
     + (float)(cluster->m_invwi.m_el[1].mVec128.m128_f32[0] * impulse->mVec128.m128_f32[0]);
  v6 = (float)((float)(cluster->m_invwi.m_el[2].mVec128.m128_f32[1] * v3)
             + (float)(cluster->m_invwi.m_el[2].mVec128.m128_f32[2] * v2))
     + (float)(cluster->m_invwi.m_el[2].mVec128.m128_f32[0] * impulse->mVec128.m128_f32[0]);
  cluster->m_vimpulses[1].mVec128.m128_f32[0] = cluster->m_vimpulses[1].mVec128.m128_f32[0] + v4;
  cluster->m_vimpulses[1].mVec128.m128_f32[1] = cluster->m_vimpulses[1].mVec128.m128_f32[1] + v5;
  cluster->m_vimpulses[1].mVec128.m128_f32[2] = cluster->m_vimpulses[1].mVec128.m128_f32[2] + v6;
  v7 = cluster->m_av.mVec128.m128_f32[0] + v4;
  cluster->m_av.mVec128.m128_f32[1] = cluster->m_av.mVec128.m128_f32[1] + v5;
  v8 = cluster->m_av.mVec128.m128_f32[2] + v6;
  cluster->m_av.mVec128.m128_f32[0] = v7;
  cluster->m_av.mVec128.m128_f32[2] = v8;
  ++cluster->m_nvimpulses;
}
