void __userpurge btSphereTriangleCollisionAlgorithm::btSphereTriangleCollisionAlgorithm(
        btSphereTriangleCollisionAlgorithm *this@<esi>,
        btPersistentManifold *mf@<eax>,
        const btCollisionAlgorithmConstructionInfo *ci@<ecx>,
        btCollisionObject *col0,
        btCollisionObject *col1,
        bool swapped)
{
  btDispatcher *m_dispatcher1; // edx

  this->__vftable = (btSphereTriangleCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  m_dispatcher1 = ci->m_dispatcher1;
  this->m_dispatcher = ci->m_dispatcher1;
  this->__vftable = (btSphereTriangleCollisionAlgorithm_vtbl *)&btSphereTriangleCollisionAlgorithm::`vftable';
  this->m_ownManifold = 0;
  this->m_manifoldPtr = mf;
  this->m_swapped = swapped;
  if ( !mf )
  {
    this->m_manifoldPtr = m_dispatcher1->getNewManifold(m_dispatcher1, col0, col1);
    this->m_ownManifold = 1;
  }
}
