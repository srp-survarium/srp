void __usercall btSoftBody::clusterDAImpulse(btSoftBody::Cluster *cluster@<eax>, const btVector3 *impulse@<ecx>)
{
  float v2; // xmm3_4
  float v3; // xmm4_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4

  v2 = impulse->mVec128.m128_f32[2];
  v3 = impulse->mVec128.m128_f32[1];
  v4 = (float)((float)(cluster->m_invwi.m_el[1].mVec128.m128_f32[1] * v3)
             + (float)(cluster->m_invwi.m_el[1].mVec128.m128_f32[2] * v2))
     + (float)(cluster->m_invwi.m_el[1].mVec128.m128_f32[0] * impulse->mVec128.m128_f32[0]);
  v5 = (float)((float)(cluster->m_invwi.m_el[2].mVec128.m128_f32[1] * v3)
             + (float)(cluster->m_invwi.m_el[2].mVec128.m128_f32[2] * v2))
     + (float)(cluster->m_invwi.m_el[2].mVec128.m128_f32[0] * impulse->mVec128.m128_f32[0]);
  v6 = cluster->m_dimpulses[1].mVec128.m128_f32[0]
     + (float)((float)((float)(cluster->m_invwi.m_el[0].mVec128.m128_f32[1] * v3)
                     + (float)(cluster->m_invwi.m_el[0].mVec128.m128_f32[2] * v2))
             + (float)(cluster->m_invwi.m_el[0].mVec128.m128_f32[0] * impulse->mVec128.m128_f32[0]));
  cluster->m_dimpulses[1].mVec128.m128_f32[1] = cluster->m_dimpulses[1].mVec128.m128_f32[1] + v4;
  v7 = cluster->m_dimpulses[1].mVec128.m128_f32[2] + v5;
  cluster->m_dimpulses[1].mVec128.m128_f32[0] = v6;
  cluster->m_dimpulses[1].mVec128.m128_f32[2] = v7;
  ++cluster->m_ndimpulses;
}
