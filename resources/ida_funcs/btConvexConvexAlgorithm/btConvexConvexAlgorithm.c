void __userpurge btConvexConvexAlgorithm::btConvexConvexAlgorithm(
        btConvexConvexAlgorithm *this@<eax>,
        const btCollisionAlgorithmConstructionInfo *ci@<ecx>,
        btPersistentManifold *mf,
        btVoronoiSimplexSolver *body0,
        btConvexPenetrationDepthSolver *body1,
        btVoronoiSimplexSolver *simplexSolver,
        btConvexPenetrationDepthSolver *pdSolver,
        int numPerturbationIterations,
        int minimumPointsPerturbationThreshold)
{
  this->__vftable = (btConvexConvexAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  this->m_dispatcher = ci->m_dispatcher1;
  this->m_simplexSolver = body0;
  this->m_pdSolver = body1;
  this->m_ownManifold = 0;
  this->m_manifoldPtr = mf;
  this->m_lowLevelOfDetail = 0;
  this->__vftable = (btConvexConvexAlgorithm_vtbl *)&btConvexConvexAlgorithm::`vftable';
  this->m_numPerturbationIterations = (int)simplexSolver;
  this->m_minimumPointsPerturbationThreshold = (int)pdSolver;
}
