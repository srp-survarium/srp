void __userpurge btConvexPlaneCollisionAlgorithm::btConvexPlaneCollisionAlgorithm(
        btConvexPlaneCollisionAlgorithm *this@<esi>,
        const btCollisionAlgorithmConstructionInfo *ci@<ecx>,
        bool isSwapped@<al>,
        btCollisionObject *mf,
        btCollisionObject *col0,
        btCollisionObject *col1,
        int numPerturbationIterations,
        int minimumPointsPerturbationThreshold)
{
  btCollisionObject *v8; // edi
  btDispatcher *m_dispatcher1; // ecx
  btCollisionObject *v10; // ebx
  btDispatcher *m_dispatcher; // ecx

  v8 = col0;
  this->__vftable = (btConvexPlaneCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  m_dispatcher1 = ci->m_dispatcher1;
  this->m_manifoldPtr = 0;
  this->m_dispatcher = m_dispatcher1;
  this->m_numPerturbationIterations = (int)col1;
  v10 = col0;
  if ( isSwapped )
    v8 = mf;
  else
    v10 = mf;
  this->m_minimumPointsPerturbationThreshold = numPerturbationIterations;
  m_dispatcher = this->m_dispatcher;
  this->__vftable = (btConvexPlaneCollisionAlgorithm_vtbl *)&btConvexPlaneCollisionAlgorithm::`vftable';
  this->m_ownManifold = 0;
  this->m_isSwapped = isSwapped;
  if ( m_dispatcher->needsCollision(m_dispatcher, v10, v8) )
  {
    this->m_manifoldPtr = this->m_dispatcher->getNewManifold(this->m_dispatcher, v10, v8);
    this->m_ownManifold = 1;
  }
}
