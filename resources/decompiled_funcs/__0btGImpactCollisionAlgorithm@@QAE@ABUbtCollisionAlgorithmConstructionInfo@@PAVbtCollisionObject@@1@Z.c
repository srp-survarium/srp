btGImpactCollisionAlgorithm *__usercall btGImpactCollisionAlgorithm::btGImpactCollisionAlgorithm@<eax>(
        btGImpactCollisionAlgorithm *this@<ecx>,
        btGImpactCollisionAlgorithm *result@<eax>)
{
  result->__vftable = (btGImpactCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  result->m_dispatcher = (btDispatcher *)this->__vftable;
  result->__vftable = (btGImpactCollisionAlgorithm_vtbl *)&btGImpactCollisionAlgorithm::`vftable';
  result->m_manifoldPtr = 0;
  result->m_convex_algorithm = 0;
  return result;
}
