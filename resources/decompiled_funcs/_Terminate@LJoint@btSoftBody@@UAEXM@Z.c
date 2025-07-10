void __thiscall btSoftBody::LJoint::Terminate(btSoftBody::LJoint *this, float dt)
{
  btRigidBody *m_rigid; // edx
  btVector3 *p_m_sdrift; // ebx
  btRigidBody *v5; // edx
  const btVector3 *v6; // esi
  btSoftBody::Cluster *m_soft; // edi
  btVector3 impulse; // [esp+0h] [ebp-10h] BYREF

  if ( this->m_split > 0.0 )
  {
    m_rigid = this->m_bodies[0].m_rigid;
    p_m_sdrift = &this->m_sdrift;
    impulse.mVec128.m128_f32[0] = -this->m_sdrift.mVec128.m128_f32[0];
    impulse.mVec128.m128_f32[1] = -this->m_sdrift.mVec128.m128_f32[1];
    impulse.mVec128.m128_f32[2] = -this->m_sdrift.mVec128.m128_f32[2];
    impulse.mVec128.m128_i32[3] = 0;
    if ( m_rigid )
      btRigidBody::applyImpulse(m_rigid, &impulse, this->m_rpos);
    if ( this->m_bodies[0].m_soft )
      btSoftBody::clusterDImpulse(&impulse, this->m_rpos, this->m_bodies[0].m_soft);
    v5 = this->m_bodies[1].m_rigid;
    v6 = &this->m_rpos[1];
    if ( v5 )
      btRigidBody::applyImpulse(v5, &this->m_sdrift, v6);
    m_soft = this->m_bodies[1].m_soft;
    if ( m_soft )
      btSoftBody::clusterDImpulse(p_m_sdrift, v6, m_soft);
  }
}
