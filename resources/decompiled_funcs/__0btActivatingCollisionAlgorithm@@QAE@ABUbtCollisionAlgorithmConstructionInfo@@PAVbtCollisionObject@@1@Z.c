btActivatingCollisionAlgorithm *__usercall btActivatingCollisionAlgorithm::btActivatingCollisionAlgorithm@<eax>(
        btActivatingCollisionAlgorithm *this@<ecx>,
        btActivatingCollisionAlgorithm *result@<eax>)
{
  result->__vftable = (btActivatingCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  result->m_dispatcher = (btDispatcher *)this->__vftable;
  result->__vftable = (btActivatingCollisionAlgorithm_vtbl *)&btActivatingCollisionAlgorithm::`vftable';
  return result;
}
