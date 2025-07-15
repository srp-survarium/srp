btCollisionAlgorithm *__thiscall btSoftRigidCollisionAlgorithm::CreateFunc::CreateCollisionAlgorithm(
        btSoftRigidCollisionAlgorithm::CreateFunc *this,
        btCollisionAlgorithmConstructionInfo *ci,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  btCollisionAlgorithm *result; // eax
  btDispatcher *m_dispatcher1; // ecx

  result = (btCollisionAlgorithm *)ci->m_dispatcher1->allocateCollisionAlgorithm(ci->m_dispatcher1, 20);
  if ( this->m_swapped )
  {
    if ( result )
    {
      result->__vftable = (btCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
      m_dispatcher1 = ci->m_dispatcher1;
      LOBYTE(result[2].__vftable) = 1;
      goto LABEL_6;
    }
  }
  else if ( result )
  {
    result->__vftable = (btCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
    m_dispatcher1 = ci->m_dispatcher1;
    LOBYTE(result[2].__vftable) = 0;
LABEL_6:
    result->__vftable = (btCollisionAlgorithm_vtbl *)&btSoftRigidCollisionAlgorithm::`vftable';
    result->m_dispatcher = m_dispatcher1;
    return result;
  }
  return 0;
}
