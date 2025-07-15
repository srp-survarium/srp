void __userpurge btSphereSphereCollisionAlgorithm::btSphereSphereCollisionAlgorithm(
        btSphereSphereCollisionAlgorithm *this@<esi>,
        const btCollisionAlgorithmConstructionInfo *ci@<eax>,
        btCollisionObject *mf,
        btCollisionObject *col0,
        btCollisionObject *col1)
{
  btDispatcher *m_dispatcher1; // ecx

  this->__vftable = (btSphereSphereCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  m_dispatcher1 = ci->m_dispatcher1;
  this->m_ownManifold = 0;
  this->m_manifoldPtr = 0;
  this->m_dispatcher = m_dispatcher1;
  this->__vftable = (btSphereSphereCollisionAlgorithm_vtbl *)&btSphereSphereCollisionAlgorithm::`vftable';
  this->m_manifoldPtr = m_dispatcher1->getNewManifold(m_dispatcher1, mf, col0);
  this->m_ownManifold = 1;
}
