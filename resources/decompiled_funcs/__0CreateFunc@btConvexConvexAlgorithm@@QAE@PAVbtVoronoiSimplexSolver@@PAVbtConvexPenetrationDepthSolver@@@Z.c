void __userpurge btConvexConvexAlgorithm::CreateFunc::CreateFunc(
        btConvexConvexAlgorithm::CreateFunc *this@<eax>,
        btConvexPenetrationDepthSolver *pdSolver@<edx>,
        btVoronoiSimplexSolver *simplexSolver)
{
  this->m_swapped = 0;
  this->m_numPerturbationIterations = 0;
  this->__vftable = (btConvexConvexAlgorithm::CreateFunc_vtbl *)&btConvexConvexAlgorithm::CreateFunc::`vftable';
  this->m_minimumPointsPerturbationThreshold = 3;
  this->m_simplexSolver = simplexSolver;
  this->m_pdSolver = pdSolver;
}
