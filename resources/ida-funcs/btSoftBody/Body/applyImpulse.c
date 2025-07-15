void __userpurge btSoftBody::Body::applyImpulse(
        const btSoftBody::Impulse *impulse@<ecx>,
        const btVector3 *rpos@<eax>,
        btSoftBody::Body *this)
{
  btRigidBody *m_rigid; // edx
  btRigidBody *v6; // edx
  btVector3 *p_m_drift; // edi

  if ( (*((_BYTE *)impulse + 32) & 1) != 0 )
  {
    m_rigid = this->m_rigid;
    if ( m_rigid )
      btRigidBody::applyImpulse(m_rigid, &impulse->m_velocity, rpos);
    if ( this->m_soft )
      btSoftBody::clusterVImpulse(this->m_soft, rpos, &impulse->m_velocity);
  }
  if ( (*((_BYTE *)impulse + 32) & 2) != 0 )
  {
    v6 = this->m_rigid;
    p_m_drift = &impulse->m_drift;
    if ( v6 )
      btRigidBody::applyImpulse(v6, p_m_drift, rpos);
    if ( this->m_soft )
      btSoftBody::clusterDImpulse(this->m_soft, rpos, p_m_drift);
  }
}
