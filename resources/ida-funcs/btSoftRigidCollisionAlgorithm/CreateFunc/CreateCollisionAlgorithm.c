btCollisionAlgorithm *__thiscall btSoftRigidCollisionAlgorithm::CreateFunc::CreateCollisionAlgorithm(
        btSoftRigidCollisionAlgorithm::CreateFunc *this,
        btCollisionAlgorithmConstructionInfo *ci,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  btCollisionAlgorithm *result; // eax

  result = (btCollisionAlgorithm *)ci->m_dispatcher1->allocateCollisionAlgorithm(ci->m_dispatcher1, 20);
  if ( this->m_swapped )
  {
    if ( result )
    {
      result->__vftable = (btCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
      result->m_dispatcher = ci->m_dispatcher1;
      LOBYTE(result[2].__vftable) = 1;
      result->__vftable = (btCollisionAlgorithm_vtbl *)&btSoftRigidCollisionAlgorithm::`vftable';
      return result;
    }
  }
  else if ( result )
  {
    result->__vftable = (btCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
    result->m_dispatcher = ci->m_dispatcher1;
    LOBYTE(result[2].__vftable) = 0;
    result->__vftable = (btCollisionAlgorithm_vtbl *)&btSoftRigidCollisionAlgorithm::`vftable';
    return result;
  }
  return 0;
}
