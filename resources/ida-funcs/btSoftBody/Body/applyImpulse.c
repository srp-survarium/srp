void __userpurge btSoftBody::Body::applyImpulse(
        const btSoftBody::Impulse *impulse@<ecx>,
        const btVector3 *rpos@<eax>,
        btSoftBody::Body *this)
{
  btRigidBody *m_rigid; // edx

  if ( (*((_BYTE *)impulse + 32) & 1) != 0 )
  {
    m_rigid = this->m_rigid;
    if ( m_rigid )
      btRigidBody::applyImpulse(m_rigid, &impulse->m_velocity, rpos);
    if ( this->m_soft )
      btSoftBody::clusterVImpulse(rpos, &impulse->m_velocity, this->m_soft);
  }
  if ( (*((_BYTE *)impulse + 32) & 2) != 0 )
    btSoftBody::Body::applyDImpulse(this, rpos, &impulse->m_drift);
}
