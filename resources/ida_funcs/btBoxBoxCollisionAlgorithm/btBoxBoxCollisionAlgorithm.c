void __userpurge btBoxBoxCollisionAlgorithm::btBoxBoxCollisionAlgorithm(
        btBoxBoxCollisionAlgorithm *this@<esi>,
        const btCollisionAlgorithmConstructionInfo *ci@<eax>,
        btCollisionObject *obj1@<edi>,
        btCollisionObject *mf,
        btCollisionObject *obj0)
{
  btDispatcher *m_dispatcher1; // ecx

  this->__vftable = (btBoxBoxCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  m_dispatcher1 = ci->m_dispatcher1;
  this->m_ownManifold = 0;
  this->m_manifoldPtr = 0;
  this->m_dispatcher = m_dispatcher1;
  this->__vftable = (btBoxBoxCollisionAlgorithm_vtbl *)&btBoxBoxCollisionAlgorithm::`vftable';
  if ( m_dispatcher1->needsCollision(m_dispatcher1, mf, obj1) )
  {
    this->m_manifoldPtr = this->m_dispatcher->getNewManifold(this->m_dispatcher, mf, obj1);
    this->m_ownManifold = 1;
  }
}
