void __userpurge btConvexPlaneCollisionAlgorithm::btConvexPlaneCollisionAlgorithm(
        btConvexPlaneCollisionAlgorithm *this@<esi>,
        btCollisionObject *col1@<edx>,
        bool isSwapped@<al>,
        const btCollisionAlgorithmConstructionInfo *mf,
        btCollisionObject *ci,
        btCollisionObject *col0,
        int numPerturbationIterations,
        int minimumPointsPerturbationThreshold)
{
  btCollisionObject *v8; // edi
  btCollisionObject *v9; // ebx

  this->__vftable = (btConvexPlaneCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  this->m_dispatcher = mf->m_dispatcher1;
  this->m_numPerturbationIterations = (int)col0;
  v8 = ci;
  this->__vftable = (btConvexPlaneCollisionAlgorithm_vtbl *)&btConvexPlaneCollisionAlgorithm::`vftable';
  this->m_ownManifold = 0;
  this->m_manifoldPtr = 0;
  this->m_isSwapped = isSwapped;
  this->m_minimumPointsPerturbationThreshold = numPerturbationIterations;
  if ( isSwapped )
  {
    v9 = col1;
  }
  else
  {
    v9 = ci;
    v8 = col1;
  }
  if ( this->m_dispatcher->needsCollision(this->m_dispatcher, v9, v8) )
  {
    this->m_manifoldPtr = this->m_dispatcher->getNewManifold(this->m_dispatcher, v9, v8);
    this->m_ownManifold = 1;
  }
}
