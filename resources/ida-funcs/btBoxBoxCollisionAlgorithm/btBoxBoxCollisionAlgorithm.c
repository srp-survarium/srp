void __userpurge btBoxBoxCollisionAlgorithm::btBoxBoxCollisionAlgorithm(
        btBoxBoxCollisionAlgorithm *this@<esi>,
        const btCollisionAlgorithmConstructionInfo *ci@<eax>,
        btCollisionObject *mf,
        btCollisionObject *obj0,
        btCollisionObject *obj1)
{
  btDispatcher *m_dispatcher1; // eax

  this->__vftable = (btBoxBoxCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  m_dispatcher1 = ci->m_dispatcher1;
  this->m_manifoldPtr = 0;
  this->m_dispatcher = m_dispatcher1;
  this->__vftable = (btBoxBoxCollisionAlgorithm_vtbl *)&btBoxBoxCollisionAlgorithm::`vftable';
  this->m_ownManifold = 0;
  if ( m_dispatcher1->needsCollision(m_dispatcher1, mf, obj0) )
  {
    this->m_manifoldPtr = this->m_dispatcher->getNewManifold(this->m_dispatcher, mf, obj0);
    this->m_ownManifold = 1;
  }
}
