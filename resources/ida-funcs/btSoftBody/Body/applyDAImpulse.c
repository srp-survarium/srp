void __usercall btSoftBody::Body::applyDAImpulse(btSoftBody::Body *this@<edi>, btRigidBody *impulse@<esi>)
{
  float *m_rigid; // eax
  btSoftBody::Cluster *m_soft; // eax
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm0_4

  m_rigid = (float *)this->m_rigid;
  if ( m_rigid )
    btRigidBody::applyTorqueImpulse(impulse, m_rigid);
  m_soft = this->m_soft;
  if ( this->m_soft )
  {
    v4 = *((float *)&impulse->__vftable + 2);
    v5 = *((float *)&impulse->__vftable + 1);
    v6 = (float)((float)(m_soft->m_invwi.m_el[1].mVec128.m128_f32[1] * v5)
               + (float)(m_soft->m_invwi.m_el[1].mVec128.m128_f32[2] * v4))
       + (float)(m_soft->m_invwi.m_el[1].mVec128.m128_f32[0] * *(float *)&impulse->__vftable);
    v7 = (float)((float)(m_soft->m_invwi.m_el[2].mVec128.m128_f32[1] * v5)
               + (float)(m_soft->m_invwi.m_el[2].mVec128.m128_f32[2] * v4))
       + (float)(m_soft->m_invwi.m_el[2].mVec128.m128_f32[0] * *(float *)&impulse->__vftable);
    v8 = m_soft->m_dimpulses[1].mVec128.m128_f32[0]
       + (float)((float)((float)(m_soft->m_invwi.m_el[0].mVec128.m128_f32[1] * v5)
                       + (float)(m_soft->m_invwi.m_el[0].mVec128.m128_f32[2] * v4))
               + (float)(m_soft->m_invwi.m_el[0].mVec128.m128_f32[0] * *(float *)&impulse->__vftable));
    m_soft->m_dimpulses[1].mVec128.m128_f32[1] = m_soft->m_dimpulses[1].mVec128.m128_f32[1] + v6;
    v9 = m_soft->m_dimpulses[1].mVec128.m128_f32[2] + v7;
    m_soft->m_dimpulses[1].mVec128.m128_f32[0] = v8;
    m_soft->m_dimpulses[1].mVec128.m128_f32[2] = v9;
    ++m_soft->m_ndimpulses;
  }
}
