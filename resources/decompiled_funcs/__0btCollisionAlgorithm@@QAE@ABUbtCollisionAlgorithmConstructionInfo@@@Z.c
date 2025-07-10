btCollisionAlgorithm *__usercall btCollisionAlgorithm::btCollisionAlgorithm@<eax>(
        btCollisionAlgorithm *this@<ecx>,
        btCollisionAlgorithm *result@<eax>)
{
  result->__vftable = (btCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  result->m_dispatcher = (btDispatcher *)this->__vftable;
  return result;
}
