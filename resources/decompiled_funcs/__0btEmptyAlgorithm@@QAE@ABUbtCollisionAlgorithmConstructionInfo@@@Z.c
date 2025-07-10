btEmptyAlgorithm *__usercall btEmptyAlgorithm::btEmptyAlgorithm@<eax>(
        btEmptyAlgorithm *this@<ecx>,
        btEmptyAlgorithm *result@<eax>)
{
  result->__vftable = (btEmptyAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  result->m_dispatcher = (btDispatcher *)this->__vftable;
  result->__vftable = (btEmptyAlgorithm_vtbl *)&btEmptyAlgorithm::`vftable';
  return result;
}
