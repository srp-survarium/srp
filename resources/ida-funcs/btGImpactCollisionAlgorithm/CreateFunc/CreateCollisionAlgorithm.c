btCollisionAlgorithm *__thiscall btGImpactCollisionAlgorithm::CreateFunc::CreateCollisionAlgorithm(
        btGImpactCollisionAlgorithm::CreateFunc *this,
        btCollisionAlgorithmConstructionInfo *ci,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  btCollisionAlgorithm *result; // eax
  btDispatcher *m_dispatcher1; // ecx

  result = (btCollisionAlgorithm *)ci->m_dispatcher1->allocateCollisionAlgorithm(ci->m_dispatcher1, 40);
  if ( !result )
    return 0;
  result->__vftable = (btCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  m_dispatcher1 = ci->m_dispatcher1;
  result[1].m_dispatcher = 0;
  result[1].__vftable = 0;
  result->m_dispatcher = m_dispatcher1;
  result->__vftable = (btCollisionAlgorithm_vtbl *)&btGImpactCollisionAlgorithm::`vftable';
  return result;
}
