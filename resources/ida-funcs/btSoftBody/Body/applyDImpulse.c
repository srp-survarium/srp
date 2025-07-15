void __userpurge btSoftBody::Body::applyDImpulse(
        btSoftBody::Body *this@<ecx>,
        const btVector3 *rpos@<eax>,
        const btVector3 *impulse)
{
  btRigidBody *m_rigid; // edx
  btSoftBody::Cluster *m_soft; // edi

  m_rigid = this->m_rigid;
  if ( m_rigid )
    btRigidBody::applyImpulse(m_rigid, impulse, rpos);
  m_soft = this->m_soft;
  if ( m_soft )
    btSoftBody::clusterDImpulse(rpos, impulse, m_soft);
}
